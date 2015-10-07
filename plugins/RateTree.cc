/*
 * =====================================================================================
 *
 *       Filename:  RateTree.cc
 *
 *    Description:  Produce a tree for computing rates.
 *
 *         Author:  Evan Friis, evan.friis@cern.ch
 *        Company:  UW Madison
 *
 * =====================================================================================
 */

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/L1Trigger/interface/L1JetParticle.h"
#include "DataFormats/L1Trigger/interface/L1EmParticle.h"

#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "DataFormats/Math/interface/deltaPhi.h"
#include "DataFormats/Scalers/interface/LumiScalers.h"

#include "TTree.h"

typedef std::vector<edm::InputTag> VInputTag;

class RateTree : public edm::EDAnalyzer {
        public:
                RateTree(const edm::ParameterSet& pset);
                virtual ~RateTree();
                void analyze(const edm::Event& evt, const edm::EventSetup& es);
        private:
                VInputTag src_;
                VInputTag srcJet_;

                TTree* tree;
                std::vector<Float_t>* pts_;
                std::vector<Float_t>* etas_;
                std::vector<Float_t>* phis_;
//                std::vector<Float_t>* BXs_;

                std::vector<Float_t>* jetpts_;
                std::vector<Float_t>* jetetas_;
                std::vector<Float_t>* jetphis_;
                std::vector<Float_t>* jetdRs_;




                UInt_t run_;
                UInt_t lumi_;
                ULong64_t event_;
                edm::InputTag scalerSrc_;
                Float_t instLumi_;
                // Add UCT-only variables
};

RateTree::RateTree(const edm::ParameterSet& pset) {
        // Initialize the ntuple builder
        edm::Service<TFileService> fs;
        tree = fs->make<TTree>("Ntuple", "Ntuple");
        pts_ = new std::vector<Float_t>();
        etas_ = new std::vector<Float_t>();
        phis_ = new std::vector<Float_t>();
//        BXs_ = new std::vector<Float_t>();

        jetpts_ = new std::vector<Float_t>();
        jetetas_ = new std::vector<Float_t>();
        jetphis_ = new std::vector<Float_t>();
        jetdRs_ = new std::vector<Float_t>();

        tree->Branch("pt", "std::vector<float>", &pts_);
        tree->Branch("eta", "std::vector<float>", &etas_);
        tree->Branch("phi", "std::vector<float>", &phis_);
//        tree->Branch("BX", "std::vector<float>", &BXs_);

        tree->Branch("jetpt", "std::vector<float>", &jetpts_);
        tree->Branch("jeteta", "std::vector<float>", &jetetas_);
        tree->Branch("jetphi", "std::vector<float>", &jetphis_);
        tree->Branch("jetdR", "std::vector<float>", &jetdRs_);


        tree->Branch("run", &run_, "run/i");
        tree->Branch("lumi", &lumi_, "lumi/i");
        tree->Branch("evt", &event_, "evt/l");
        tree->Branch("instlumi", &instLumi_, "instlumi/F");

        src_ = pset.getParameter<VInputTag>("src");
        srcJet_ = pset.getParameter<VInputTag>("srcJet");

}

RateTree::~RateTree() {
}


namespace {

        // Predicate to sort candidates by descending pt
        class CandPtSorter {
                public:
                        bool operator()(const reco::Candidate* candA, const reco::Candidate* candB)
                                const {
                                        return candA->pt() > candB->pt();
                                }
        };

        // Turn a set of InputTags into a colleciton of candidate pointers.
        std::vector<const reco::Candidate*> getCollections(
                        const edm::Event& evt, const VInputTag& collections) {
                std::vector<const reco::Candidate*> output;
                // Loop over collections
                for (size_t i = 0; i < collections.size(); ++i) {
                        edm::Handle<edm::View<reco::Candidate> > handle;
                        evt.getByLabel(collections[i], handle);
                        // Loop over objects in current collection
                        for (size_t j = 0; j < handle->size(); ++j) {
                                const reco::Candidate& object = handle->at(j);
                                output.push_back(&object);
                        }
                }
                return output;
        }

}

void RateTree::analyze(const edm::Event& evt, const edm::EventSetup& es) {



        // Get the objects.
        std::vector<const reco::Candidate*> objects = getCollections(
                        evt, src_);

        std::sort(objects.begin(), objects.end(), CandPtSorter());


        std::vector<const reco::Candidate*> objectsJets = getCollections(
                        evt, srcJet_);



        // Clear previous event's objects
        pts_->clear();
        etas_->clear();
        phis_->clear();
//        BXs_->clear();
        jetpts_->clear();
        jetetas_->clear();
        jetphis_->clear();
        jetdRs_->clear();

        // Setup meta info
        run_ = evt.id().run();
        lumi_ = evt.id().luminosityBlock();
        event_ = evt.id().event();


        // Get instantaneous lumi from the scalers
        // thx to Carlo Battilana
        /*
           edm::Handle<LumiScalersCollection> lumiScalers;
           evt.getByLabel(scalerSrc_, lumiScalers);
           instLumi_ = -1;
           if (lumiScalers->size())
           instLumi_ = lumiScalers->begin()->instantLumi();
           */
        for (size_t i = 0; i < objects.size(); ++i) {
                pts_->push_back(objects[i]->pt());
                etas_->push_back(objects[i]->eta());
                phis_->push_back(objects[i]->phi());

                int find=-1; double DRMIN=10;
                for (size_t j = 0; j < objectsJets.size(); ++j) {
                        double deltaEta=objectsJets[j]->eta() - objects[i]->eta();
                        double deltaPhi=reco::deltaPhi(objectsJets[j]->phi(),objects[i]->phi());
                        double dR=sqrt( deltaEta*deltaEta + deltaPhi*deltaPhi)   ;
                        if(dR<DRMIN) {find=j; DRMIN=dR;}
                }
                if(find!=-1){
                jetpts_->push_back(objectsJets[find]->pt());
                jetetas_->push_back(objectsJets[find]->eta());
                jetphis_->push_back(objectsJets[find]->phi());
                jetdRs_->push_back(DRMIN);
                }
                else{
                jetpts_->push_back(-1);
                jetetas_->push_back(-1);
                jetphis_->push_back(-1);
                jetdRs_->push_back(-1);
                }
        }

        // pad everything, to work around the MaxIf bug.
        tree->Fill();
}

#include "FWCore/Framework/interface/MakerMacros.h"
DEFINE_FWK_MODULE(RateTree);
