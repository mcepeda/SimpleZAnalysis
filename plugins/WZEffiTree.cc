/*
 * =====================================================================================
 *
 *       Filename:  WZEffiTree.cc
 *        Company:  UW Madison
 *
 * =====================================================================================
 */

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "SimDataFormats/GeneratorProducts/interface/GenEventInfoProduct.h"
#include "DataFormats/HepMCCandidate/interface/GenStatusFlags.h"

#include "FWCore/Common/interface/TriggerNames.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "DataFormats/PatCandidates/interface/TriggerObjectStandAlone.h"
#include "DataFormats/PatCandidates/interface/PackedTriggerPrescales.h"


#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/L1Trigger/interface/L1JetParticle.h"
#include "DataFormats/L1Trigger/interface/L1EmParticle.h"
#include "DataFormats/JetReco/interface/PFJet.h"
#include <DataFormats/PatCandidates/interface/Jet.h>
#include "DataFormats/EgammaCandidates/interface/GsfElectron.h"
#include "DataFormats/PatCandidates/interface/Electron.h"

#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/PatCandidates/interface/PackedGenParticle.h"

#include "DataFormats/Common/interface/ValueMap.h"

#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "DataFormats/VertexReco/interface/Vertex.h"

#include "DataFormats/EgammaCandidates/interface/ConversionFwd.h"
#include "DataFormats/EgammaCandidates/interface/Conversion.h"
#include "RecoEgamma/EgammaTools/interface/ConversionTools.h"

#include "SimDataFormats/PileupSummaryInfo/interface/PileupSummaryInfo.h"

#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

#include "DataFormats/Math/interface/deltaPhi.h"
#include "TLorentzVector.h"
#include "TTree.h"

#include "DataFormats/Scalers/interface/LumiScalers.h"


typedef std::vector<edm::InputTag> VInputTag;

class WZEffiTree : public edm::EDAnalyzer {
        public:
                WZEffiTree(const edm::ParameterSet& pset);
                virtual ~WZEffiTree();
                void analyze(const edm::Event& evt, const edm::EventSetup& es);
        private:
                bool isMC_;

                VInputTag src_;
                VInputTag srcJet_;
                VInputTag recoSrcJet_;
                VInputTag metSrc_;
                VInputTag recoMetSrc_;
                edm::InputTag scalerSrc_;

                TTree* tree;
                std::vector<Float_t>* pts_;
                std::vector<Float_t>* etas_;
                std::vector<Float_t>* phis_;
                std::vector<Int_t>* recomatches_;

                std::vector<Float_t>* recopts_;
                std::vector<Float_t>* recomts_;

                std::vector<Float_t>* recoetas_;
                std::vector<Float_t>* recophis_;
                std::vector<Float_t>* recocharges_;
                std::vector<Float_t>* recodRToJet_;
                std::vector<Float_t>* recoMatchedJet_;

                std::vector<Float_t>* l1matchedpt_;
                std::vector<Float_t>* l1matchedeta_;
                std::vector<Float_t>* l1matchedphi_;
                std::vector<Float_t>* l1matcheddR_;
                std::vector<Float_t>* l1matchedJetpt_;
                std::vector<Float_t>* l1matchedJeteta_;
                std::vector<Float_t>* l1matchedJetphi_;
                std::vector<Float_t>* l1matchedJetdR_;


                std::vector<Float_t>* recolooseids_;
                std::vector<Float_t>* recomediumids_;
                std::vector<Float_t>* recotightids_;
                std::vector<Float_t>* recoconversions_;
                std::vector<Float_t>* recodzs_;
                std::vector<Float_t>* recod0s_;

                std::vector<Float_t>* jetpts_;
                std::vector<Float_t>* jetetas_;
                std::vector<Float_t>* jetphis_;
                std::vector<Int_t>* recoJetmatches_;
                std::vector<Int_t>* recoJetLooseJetID_;
                std::vector<Int_t>* recoJetTightJetID_; 
                std::vector<Int_t>* recoJetTightLepVetoJetID_; 
                std::vector<Float_t>* recoJetpts_;
                std::vector<Float_t>* recoJetetas_;
                std::vector<Float_t>* recoJetphis_;

                Float_t recoMet_Et_;
                Float_t recoMet_Phi_;
                Float_t met_Et_;
                Float_t met_Phi_;

                Float_t genmassZ_;
                Float_t recomassForZ_;
                Int_t leadElectronForZ_;
                Int_t secondElectronForZ_;
                Float_t recomassForZL1_;
                Float_t recomassForZL1V2_;

                Float_t        genmassZFromEle_;
                Float_t        genfirstelept_;
                Float_t        gensecondeleeta_;
                Float_t        genfirsteleeta_;
                Float_t        gensecondelept_;
                Int_t        foundGenZee_;
                Int_t        foundGenZeeFiducial_;

                UInt_t hltEle27Loose_;
                UInt_t hltEle27Tight_;
                UInt_t hltEle23LooseFull_;
                UInt_t hltEle27LooseFull_;

                UInt_t hltEle22Loose_;
                UInt_t hltEle22Tight_;

                UInt_t hltEle2775_;  
                UInt_t hltEle2275Full_;
                UInt_t hltEle2375Full_;

                UInt_t recoNLoose10_, recoNLoose20_, recoNMedium10_, recoNMedium20_, recoNTight10_, recoNTight20_;
                UInt_t recoNJet20_, recoNJet40_, recoNJet30_;


                UInt_t run_;
                UInt_t lumi_;
                ULong64_t event_;
                Int_t nPU_;
                Int_t nvtx_;
                Float_t  instantLumi_;
                Float_t genweight_;
                Float_t instantLumiErr_;
                Float_t pileupScalers_; 
                Float_t pileupScalersRMS_;
                Float_t liveLumiFill_;
                Float_t liveLumiRun_;                      

                Int_t count_;

                edm::EDGetTokenT<reco::BeamSpot> beamSpotToken_;

                // MiniAOD case data members
                edm::EDGetToken electronsMiniAODToken_;
                edm::EDGetTokenT<reco::VertexCollection> vtxMiniAODToken_;
                edm::EDGetTokenT<reco::ConversionCollection> conversionsMiniAODToken_;

                // ID decisions objects
                edm::EDGetTokenT<edm::ValueMap<bool> > eleLooseIdMapToken_;
                edm::EDGetTokenT<edm::ValueMap<bool> > eleMediumIdMapToken_;
                edm::EDGetTokenT<edm::ValueMap<bool> > eleTightIdMapToken_;



                edm::EDGetTokenT<edm::TriggerResults> triggerBits_;
                edm::EDGetTokenT<pat::TriggerObjectStandAloneCollection> triggerObjects_;
                edm::EDGetTokenT<pat::PackedTriggerPrescales> triggerPrescales_;


};

WZEffiTree::WZEffiTree(const edm::ParameterSet& pset):
        isMC_(pset.getUntrackedParameter<bool>("isMC",0)),
        eleLooseIdMapToken_(consumes<edm::ValueMap<bool> >(pset.getParameter<edm::InputTag>("eleLooseIdMap"))),
        eleMediumIdMapToken_(consumes<edm::ValueMap<bool> >(pset.getParameter<edm::InputTag>("eleMediumIdMap"))),
        eleTightIdMapToken_(consumes<edm::ValueMap<bool> >(pset.getParameter<edm::InputTag>("eleTightIdMap"))),
        triggerBits_(consumes<edm::TriggerResults>(pset.getParameter<edm::InputTag>("bits"))),
        triggerObjects_(consumes<pat::TriggerObjectStandAloneCollection>(pset.getParameter<edm::InputTag>("objects"))),
        triggerPrescales_(consumes<pat::PackedTriggerPrescales>(pset.getParameter<edm::InputTag>("prescales")))
{

        beamSpotToken_    = consumes<reco::BeamSpot> 
                (pset.getParameter <edm::InputTag>
                 ("beamSpot"));

        electronsMiniAODToken_    = mayConsume<edm::View<reco::GsfElectron> >
                (pset.getParameter<edm::InputTag>
                 ("electronsMiniAOD"));

        vtxMiniAODToken_          = mayConsume<reco::VertexCollection>
                (pset.getParameter<edm::InputTag>
                 ("verticesMiniAOD"));

        conversionsMiniAODToken_ = mayConsume< reco::ConversionCollection >
                (pset.getParameter<edm::InputTag>
                 ("conversionsMiniAOD"));


        // Initialize the ntuple builder
        edm::Service<TFileService> fs;
        tree = fs->make<TTree>("Ntuple", "Ntuple");
        pts_ = new std::vector<Float_t>();
        etas_ = new std::vector<Float_t>();
        phis_ = new std::vector<Float_t>();
        recomatches_ = new std::vector<Int_t>();

        recopts_ = new std::vector<Float_t>();
        recomts_ = new std::vector<Float_t>();

        l1matchedpt_ = new std::vector<Float_t>();
        l1matchedeta_ = new std::vector<Float_t>();
        l1matchedphi_ = new std::vector<Float_t>();
        l1matcheddR_ = new std::vector<Float_t>();

        l1matchedJetpt_ = new std::vector<Float_t>();
        l1matchedJeteta_ = new std::vector<Float_t>();
        l1matchedJetphi_ = new std::vector<Float_t>();
        l1matchedJetdR_ = new std::vector<Float_t>();

        recoetas_ = new std::vector<Float_t>();
        recophis_ = new std::vector<Float_t>();
        recocharges_ = new std::vector<Float_t>();
        recodRToJet_ = new std::vector<Float_t>();
        recoMatchedJet_  = new std::vector<Float_t>();
        recodzs_ = new std::vector<Float_t>();
        recod0s_ = new std::vector<Float_t>();

        recoconversions_ = new std::vector<Float_t>();
        recotightids_ = new std::vector<Float_t>();
        recomediumids_ = new std::vector<Float_t>();
        recolooseids_ = new std::vector<Float_t>();

        jetpts_ = new std::vector<Float_t>();
        jetetas_ = new std::vector<Float_t>();
        jetphis_ = new std::vector<Float_t>();
        recoJetmatches_ = new std::vector<Int_t>();
        recoJetTightLepVetoJetID_ = new std::vector<Int_t>();
        recoJetLooseJetID_ = new std::vector<Int_t>();
        recoJetTightJetID_ = new std::vector<Int_t>();


        recoJetpts_ = new std::vector<Float_t>();
        recoJetetas_ = new std::vector<Float_t>();
        recoJetphis_ = new std::vector<Float_t>();

        tree->Branch("pt", "std::vector<float>", &pts_);
        tree->Branch("eta", "std::vector<float>", &etas_);
        tree->Branch("phi", "std::vector<float>", &phis_);
        tree->Branch("recomatches", "std::vector<int>", &recomatches_);

        tree->Branch("recopt", "std::vector<float>", &recopts_);
        tree->Branch("recomt", "std::vector<float>", &recomts_);

        tree->Branch("l1matcheddR", "std::vector<float>", &l1matcheddR_);
        tree->Branch("l1matchedpt", "std::vector<float>", &l1matchedpt_);
        tree->Branch("l1matchedeta", "std::vector<float>", &l1matchedeta_);
        tree->Branch("l1matchedphi", "std::vector<float>", &l1matchedphi_);


        tree->Branch("l1matchedJetdR", "std::vector<float>", &l1matchedJetdR_);
        tree->Branch("l1matchedJetpt", "std::vector<float>", &l1matchedJetpt_);
        tree->Branch("l1matchedJeteta", "std::vector<float>", &l1matchedJeteta_);
        tree->Branch("l1matchedJetphi", "std::vector<float>", &l1matchedJetphi_);



        tree->Branch("recoeta", "std::vector<float>", &recoetas_);
        tree->Branch("recophi", "std::vector<float>", &recophis_);
        tree->Branch("recocharge", "std::vector<float>", &recocharges_);
        tree->Branch("recodRToJet", "std::vector<float>", &recodRToJet_);
        tree->Branch("recoMatchedJet", "std::vector<float>", &recoMatchedJet_);

        tree->Branch("recolooseid", "std::vector<float>", &recolooseids_);
        tree->Branch("recomediumid", "std::vector<float>", &recomediumids_);
        tree->Branch("recotightid", "std::vector<float>", &recotightids_);
        tree->Branch("recodz", "std::vector<float>", &recodzs_);
        tree->Branch("recod0", "std::vector<float>", &recod0s_);


        tree->Branch("recoconversion", "std::vector<float>", &recoconversions_);

        tree->Branch("jetpt", "std::vector<float>", &jetpts_);
        tree->Branch("jeteta", "std::vector<float>", &jetetas_);
        tree->Branch("jetphi", "std::vector<float>", &jetphis_);
        tree->Branch("recoJetmatches", "std::vector<int>", &recoJetmatches_);
        tree->Branch("recoJetLooseJetID", "std::vector<int>", &recoJetLooseJetID_);
        tree->Branch("recoJetTightJetID", "std::vector<int>", &recoJetTightJetID_);
        tree->Branch("recoJetTightLepVetoJetID", "std::vector<int>", &recoJetTightLepVetoJetID_);


        tree->Branch("recoJetpt", "std::vector<float>", &recoJetpts_);
        tree->Branch("recoJeteta", "std::vector<float>", &recoJetetas_);
        tree->Branch("recoJetphi", "std::vector<float>", &recoJetphis_);

        tree->Branch("recoMet_Et", &recoMet_Et_, "recoMet_Et/F");
        tree->Branch("recoMet_Phi", &recoMet_Phi_, "recoMet_Phi/F");
        tree->Branch("met_Et", &met_Et_, "met_Et/F");
        tree->Branch("met_Phi", &met_Phi_, "met_Phi/F");

        tree->Branch("recomassForZ", &recomassForZ_, "recomassForZ/F");
        tree->Branch("leadElectronForZ_", &leadElectronForZ_, "leadElectronForZ_/i");
        tree->Branch("secondElectronForZ_", &secondElectronForZ_, "secondElectronForZ_/i");
        tree->Branch("recomassForZL1", &recomassForZL1_, "recomassForZL1/F");
        tree->Branch("recomassForZL1V2", &recomassForZL1V2_, "recomassForZL1V2/F");
        tree->Branch("genmassZ", &genmassZ_, "genmassZ/F");
        tree->Branch("genmassZFromEle", &genmassZFromEle_, "genmassZFromEle/F");
        tree->Branch("genfirstelept", &genfirstelept_, "genfirstelept/F");
        tree->Branch("genfirsteleeta", &genfirsteleeta_, "genfirsteleeta/F");
        tree->Branch("gensecondeleeta", &gensecondeleeta_, "gensecondeleeta/F");
        tree->Branch("gensecondelept", &gensecondelept_, "gensecondelept/F");
        tree->Branch("foundGenZee", &foundGenZee_, "foundGenZee/i");
        tree->Branch("foundGenZeeFiducial", &foundGenZeeFiducial_, "foundGenZeeFiducial/i");

        tree->Branch("run", &run_, "run/i");
        tree->Branch("lumi", &lumi_, "lumi/i");
        tree->Branch("evt", &event_, "evt/l");
        tree->Branch("nPU", &nPU_, "nPU/i");
        tree->Branch("nvtx", &nvtx_, "nvtx/i");
        tree->Branch("genweight", &genweight_, "genweight/F");
        tree->Branch("instantLumi", &instantLumi_, "instantLumi/F");
        tree->Branch("instantLumiErr", &instantLumiErr_, "instantLumiErr/F");
        tree->Branch("pileupScalers", &pileupScalers_, "pileupScalers/F");
        tree->Branch("pileupScalersRMS", &pileupScalersRMS_, "pileupScalersRMS/F");
        tree->Branch("liveLumiFill", &liveLumiFill_, "liveLumiFill/F");
        tree->Branch("liveLumiRun", &liveLumiRun_, "liveLumiRun/F");

        tree->Branch("recoNLoose10", &recoNLoose10_, "recoNLoose10/i");
        tree->Branch("recoNLoose20", &recoNLoose20_, "recoNLoose20/i");
        tree->Branch("recoNMedium20", &recoNMedium20_, "recoNMedium20/i");
        tree->Branch("recoNMedium10", &recoNMedium10_, "recoNMedium10/i");
        tree->Branch("recoNTight20", &recoNTight20_, "recoNTight20/i");
        tree->Branch("recoNTight10", &recoNTight10_, "recoNTight10/i");

        tree->Branch("recoNJet20", &recoNJet20_, "recoNJet20/i");
        tree->Branch("recoNJet30", &recoNJet30_, "recoNJet30/i");
        tree->Branch("recoNJet40", &recoNJet40_, "recoNLoose40/i");

        tree->Branch("hltEle27Loose", &hltEle27Loose_, "hltEle27Loose/i");
        tree->Branch("hltEle27Tight", &hltEle27Tight_, "hltEle27Tight/i");
        tree->Branch("hltEle22Loose", &hltEle22Loose_, "hltEle22Loose/i");
        tree->Branch("hltEle22Tight", &hltEle22Tight_, "hltEle22Tight/i");
        tree->Branch("hltEle2775", &hltEle2775_, "hltEle2775/i");
        tree->Branch("hltEle23LooseFull", &hltEle23LooseFull_, "hltEle23LooseFull/i");
        tree->Branch("hltEle27LooseFull", &hltEle27LooseFull_, "hltEle27LooseFull/i");
        tree->Branch("hltEle2275Full", &hltEle2275Full_, "hltEle2275Full/i");
        tree->Branch("hltEle2375Full", &hltEle2375Full_, "hltEle2375Full/i");

        src_ = pset.getParameter<VInputTag>("src");
        recoSrcJet_ = pset.getParameter<VInputTag>("recoSrcJet");
        metSrc_ = pset.getParameter<VInputTag>("metSrc");
        recoMetSrc_ = pset.getParameter<VInputTag>("recoMetSrc");
        srcJet_ = pset.getParameter<VInputTag>("srcJet");
        scalerSrc_ = pset.getUntrackedParameter<edm::InputTag>("srcScalers",edm::InputTag("scalersRawToDigi"));
        
        count_=0;
}

WZEffiTree::~WZEffiTree() {
        /*
           delete pts_;
           delete etas_;
           delete phis_;
           delete recomatches_;
           delete recopts_;
           delete recophis_;
           delete recoetas_;
           delete recocharges_;
           delete jetpts_;
           delete jetetas_;
           delete jetphis_;
           delete recoJetmatches_;
           delete recoJetpts_;
           delete recoJetphis_;
           delete recoJetetas_;
           delete recoMatchedJet_;
           delete recodRToJet_;
           */
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


        std::vector<const pat::Jet*> getJetCollections(
                        const edm::Event& evt, const VInputTag& collections) {
                std::vector<const pat::Jet*> output;
                for (size_t i = 0; i < collections.size(); ++i) {
                        edm::Handle<edm::View<pat::Jet> > handle;
                        evt.getByLabel(collections[i], handle);
                        for (size_t j = 0; j < handle->size(); ++j) {
                                const pat::Jet& object = handle->at(j);
                                output.push_back(&object);
                        }
                }
                return output;
        }



}

void WZEffiTree::analyze(const edm::Event& evt, const edm::EventSetup& es) {

        count_++;

        using namespace std;
        using namespace edm;
        using namespace reco;



        edm::Handle<edm::TriggerResults> triggerBits;
        edm::Handle<pat::PackedTriggerPrescales> triggerPrescales;
        edm::Handle<pat::TriggerObjectStandAloneCollection> triggerObjects;

        evt.getByToken(triggerObjects_, triggerObjects);
        evt.getByToken(triggerBits_, triggerBits);
        evt.getByToken(triggerPrescales_, triggerPrescales);

        hltEle22Tight_=false; hltEle27Tight_=false; hltEle22Loose_=false; hltEle27Loose_=false; hltEle2775_=false;
        hltEle23LooseFull_=false; hltEle27LooseFull_=false;
        hltEle2275Full_=false; hltEle2375Full_=false;

        const edm::TriggerNames &names = evt.triggerNames(*triggerBits);
        for (unsigned int i = 0, n = triggerBits->size(); i < n; ++i) {
                if(names.triggerName(i).find("HLT_Ele27_eta2p1_WP75_Gsf_v")!=std::string::npos && triggerBits->accept(i) ) hltEle2775_=true;
                if(names.triggerName(i).find("HLT_Ele22_WP75_Gsf_v1")!=std::string::npos && triggerBits->accept(i) ) hltEle2275Full_=true;
                if(names.triggerName(i).find("HLT_Ele23_WP75_Gsf_v1")!=std::string::npos && triggerBits->accept(i) ) hltEle2375Full_=true;
                if(names.triggerName(i).find("HLT_Ele27_eta2p1_WPLoose_Gsf_v")!=std::string::npos && triggerBits->accept(i) ) hltEle27Loose_=true;
                if(names.triggerName(i).find("HLT_Ele22_eta2p1_WPLoose_Gsf_v")!=std::string::npos && triggerBits->accept(i) ) hltEle22Loose_=true;
                if(names.triggerName(i).find("HLT_Ele27_eta2p1_WPTight_Gsf_v")!=std::string::npos && triggerBits->accept(i) ) hltEle27Tight_=true;
                if(names.triggerName(i).find("HLT_Ele22_eta2p1_WPTight_Gsf_v")!=std::string::npos && triggerBits->accept(i) ) hltEle22Tight_=true;
                if(names.triggerName(i).find("HLT_Ele23_WPLoose_Gsf_v")!=std::string::npos && triggerBits->accept(i) ) hltEle23LooseFull_=true;
                if(names.triggerName(i).find("HLT_Ele27_WPLoose_Gsf_v")!=std::string::npos && triggerBits->accept(i) ) hltEle27LooseFull_=true;

                if(count_==1) std::cout << "Trigger " << names.triggerName(i) << 
                        ", prescale " << triggerPrescales->getPrescaleForIndex(i) <<
                                ": " << (triggerBits->accept(i) ? "PASS" : "fail (or not run)") 
                                << std::endl;
        }

        // Get the beam spot
        edm::Handle<reco::BeamSpot> theBeamSpot;
        evt.getByToken(beamSpotToken_,theBeamSpot);  

        // Retrieve the collection of electrons from the event.
        // If we fail to retrieve the collection with the standard AOD
        // name, we next look for the one with the stndard MiniAOD name.
        //   We use exactly the same handle for AOD and MiniAOD formats
        // since pat::Electron objects can be recast as reco::GsfElectron objects.
        edm::Handle<edm::View<reco::GsfElectron> > electrons;
        evt.getByToken(electronsMiniAODToken_,electrons);

        // Get PV
        edm::Handle<reco::VertexCollection> vertices;
        evt.getByToken(vtxMiniAODToken_, vertices);

        if (vertices->empty()) return; // skip the event if no PV found

        genweight_=-777;
        genmassZ_=-1;
        genmassZFromEle_=-1;
        genfirstelept_=-1;
        gensecondeleeta_=-1;
        genfirstelept_=-1;
        gensecondeleeta_=-1;
        foundGenZee_=0;
        foundGenZeeFiducial_=0;

        if(isMC_){
                edm::Handle<GenEventInfoProduct> genInfo;
                if(evt.getByLabel("generator", genInfo)) {
                        genweight_ = genInfo->weight();
                }

        Handle<edm::View<pat::PackedGenParticle> > packed;
        edm::Handle< vector<reco::GenParticle> >pGenPart;
        if(evt.getByLabel("packedGenParticles",packed)&&evt.getByLabel("prunedGenParticles", pGenPart)){

                for( size_t i = 0; i < pGenPart->size(); ++ i ) {
                        const reco::GenParticle& genpart = (*pGenPart)[i];
                        if(genpart.pdgId()!=23)continue;
                        if(genpart.numberOfDaughters()==1) continue;
                        if(!genpart.isLastCopy()) continue;
                        genmassZ_=genpart.mass();
/*                        for(unsigned int j=0; j<genpart.numberOfDaughters()&&!filled; j++){
                                const reco::Candidate* Wdaughter=genpart.daughter(j);
                                if ( fabs(Wdaughter->pdgId())==11) NElectrons++;
                        }
*/
                }

                int uno=-1; int dos=-1; bool demasiados=false;

                for( size_t i = 0; i < packed->size(); ++ i ) { 
                        const pat::PackedGenParticle  packedPart = (*packed)[i] ;
                        if(fabs(packedPart.pdgId())!=11)continue;
                        if(!packedPart.isPromptFinalState()) continue;
                        if(uno==-1) uno=i;
                        else if(uno!=-1 && dos==-1) dos=i;
                        else if (uno!=-1 && dos!=-1) demasiados=true;
                  }
                if(uno!=-1 && dos!=-1 && !demasiados){
                foundGenZee_=1;  
                const pat::PackedGenParticle   primero=(*packed)[uno];
                const pat::PackedGenParticle   segundo=(*packed)[dos];
                genmassZFromEle_=(primero.p4()+segundo.p4()).mass();
                genfirstelept_=primero.pt();
                gensecondelept_=segundo.pt();
                genfirsteleeta_=primero.eta();
                gensecondeleeta_=segundo.eta();

                if(genfirstelept_>25 && gensecondelept_>25 && fabs(genfirsteleeta_)<2.5 && fabs(gensecondeleeta_)<2.5) foundGenZeeFiducial_=1;

                 }

            }

        }

        // Get the objects.
        std::vector<const reco::Candidate*> objects = getCollections(
                        evt, src_);
        std::vector<const reco::Candidate*> jetObjects = getCollections(
                        evt, srcJet_);
        std::vector<const pat::Jet*> recoJetObjects = getJetCollections(
                        evt, recoSrcJet_);
        std::vector<const reco::Candidate*> metObject = getCollections(
                        evt, metSrc_);
        std::vector<const reco::Candidate*> recoMetObject = getCollections(
                        evt, recoMetSrc_);

        std::sort(objects.begin(), objects.end(), CandPtSorter());


        edm::Handle<edm::ValueMap<bool> > loose_id_decisions;
        edm::Handle<edm::ValueMap<bool> > medium_id_decisions;
        edm::Handle<edm::ValueMap<bool> > tight_id_decisions; 
        evt.getByToken(eleLooseIdMapToken_ ,loose_id_decisions);
        evt.getByToken(eleMediumIdMapToken_,medium_id_decisions);
        evt.getByToken(eleTightIdMapToken_,tight_id_decisions);

        // Clear previous event's objects
        pts_->clear();
        etas_->clear();
        phis_->clear();
        recomatches_->clear();
        recopts_->clear();
        recomts_->clear();

        recoetas_->clear();
        recophis_->clear();
        recocharges_->clear();
        jetpts_->clear();
        jetetas_->clear();
        jetphis_->clear();
        recoJetmatches_->clear();
        recoJetLooseJetID_->clear();
        recoJetTightJetID_->clear();
        recoJetTightLepVetoJetID_->clear();
        recoJetpts_->clear();
        recoJetetas_->clear();
        recoJetphis_->clear();
        recodRToJet_->clear();
        recoMatchedJet_->clear();
        recodzs_->clear();
        recod0s_->clear();

        l1matchedpt_->clear();
        l1matchedeta_->clear();
        l1matchedphi_->clear();
        l1matcheddR_->clear();

        l1matchedJetpt_->clear();
        l1matchedJeteta_->clear();
        l1matchedJetphi_->clear();
        l1matchedJetdR_->clear();

        recoconversions_->clear();
        recotightids_->clear();
        recomediumids_->clear();
        recolooseids_->clear();

        recoNLoose20_=0, recoNLoose10_=0;
        recoNMedium20_=0, recoNMedium10_=0;
        recoNTight20_=0, recoNTight10_=0;
        recoNJet20_=0, recoNJet30_=0, recoNJet40_=0;

        leadElectronForZ_=0;
        secondElectronForZ_=0;
        recomassForZ_=0; 
        recomassForZL1_=0;
        recomassForZL1V2_=0;

        // Setup meta info
        run_ = evt.id().run();
        lumi_ = evt.id().luminosityBlock();
        event_ = evt.id().event();


        instantLumi_ = -1; instantLumiErr_=-1; 
        pileupScalers_=-1; pileupScalersRMS_=-1;      
        liveLumiFill_=-1; liveLumiRun_=-1;
        if(!isMC_){
                edm::Handle<LumiScalersCollection> lumiScalers;
                evt.getByLabel(scalerSrc_, lumiScalers);
                instantLumi_ = -1;

                if (lumiScalers->size()){
                        instantLumi_ = lumiScalers->begin()->instantLumi();
                        instantLumiErr_ =lumiScalers->begin()->instantLumiErr() ;
                        pileupScalers_ = lumiScalers->begin()->pileup();
                        pileupScalersRMS_ = lumiScalers->begin()->pileupRMS();
                        liveLumiFill_ = lumiScalers->begin()->liveLumiFill();
                        liveLumiRun_ = lumiScalers->begin()->liveLumiRun();
                }

        }


        if(isMC_){
                edm::Handle<std::vector<PileupSummaryInfo> > PupInfo;
                evt.getByLabel("addPileupInfo", PupInfo);

                nPU_=-1;
                for(std::vector<PileupSummaryInfo>::const_iterator i = PupInfo->begin();
                                i!=PupInfo->end();++i) {
                        int BX = i->getBunchCrossing();
                        if(BX==0) {
                                //   nPU_ =i->getTrueNumInteractions();   // this is always the same number in this case (fixed PU=40 for instance)
                                nPU_=i->getPU_NumInteractions();       // we want this instead, this has the poisson distribution we want
                        }
                }
        } 

        // std::cout<<"----------------------------"<<count_<<std::endl;

        // Get the conversions collection
        edm::Handle<reco::ConversionCollection> conversions;
        evt.getByToken(conversionsMiniAODToken_, conversions);

        // Find the first vertex in the collection that passes
        // good quality criteria
        VertexCollection::const_iterator firstGoodVertex = vertices->end();
        int firstGoodVertexIdx = 0;
        nvtx_=0;
        for (VertexCollection::const_iterator vtx = vertices->begin(); 
                        vtx != vertices->end(); ++vtx, ++firstGoodVertexIdx) {
                // Replace isFake() for MiniAOD because it requires tracks and MiniAOD vertices don't have tracks:
                // Vertex.h: bool isFake() const {return (chi2_==0 && ndof_==0 && tracks_.empty());}
                bool isFake = (vtx->chi2()==0 && vtx->ndof()==0);
                // Check the goodness
                if ( !isFake
                                &&  vtx->ndof()>=4. && vtx->position().Rho()<=2.0
                                && fabs(vtx->position().Z())<=24.0) {
                        if(firstGoodVertexIdx==0) firstGoodVertex = vtx;
                        nvtx_++;
                }
        }

        if ( firstGoodVertex==vertices->end() )
                return; // skip event if there are no good PVs


        //std::cout<<"Trigger Objects!"<<std::endl;
        for (size_t i = 0; i < objects.size(); ++i) {
                if(objects[i]->pt()<10) continue;
          //        std::cout<<objects[i]->pt()<<"   "<<objects[i]->eta()<<"   "<<objects[i]->phi()<<std::endl;
                pts_->push_back(objects[i]->pt());
                etas_->push_back(objects[i]->eta());
                phis_->push_back(objects[i]->phi());
        }

        // std::cout<<"reco Objects!"<<std::endl;

        // std::cout<<"MET ?"<<std::endl;
        met_Et_=-10, met_Phi_=-10,recoMet_Et_=-10, recoMet_Phi_=-10;
        double recoMet_px=0, recoMet_py=0;;

        if(metObject.size()==0) {std::cout<<"?????"<<std::endl;}
        else{ met_Et_=metObject[0]->pt();
                met_Phi_=metObject[0]->phi();
                //     std::cout<<"MET: "<<met_Et_<<"   "<<met_Phi_<<std::endl;
        }
        if(recoMetObject.size()==0) { std::cout<<"?????"<<std::endl; }
        else{ recoMet_Et_=recoMetObject[0]->pt(); recoMet_px=recoMetObject[0]->px(); recoMet_py=recoMetObject[0]->py();
                recoMet_Phi_=recoMetObject[0]->phi();
                //       std::cout<<"recoMET: "<<recoMet_Et_<<"   "<<recoMet_Phi_<<std::endl;
        }


        size_t lead=-1, second=-1;
        double leadPt=0, secondPt=0;     


//            std::cout<<"Reco Electrons"<<electrons->size()<<std::endl;
        for (size_t i = 0; i < electrons->size(); i++){
                const auto el = electrons->ptrAt(i);
                //  if(el->pt()<10) continue;
                recopts_->push_back(el->pt());
                recoetas_->push_back(el->eta());
                recophis_->push_back(el->phi());
                recocharges_->push_back(el->charge());
                bool isPassLoose  = (*loose_id_decisions)[el];
                bool isPassMedium = (*medium_id_decisions)[el];
                bool isPassTight  = (*tight_id_decisions)[el];
                recolooseids_ ->push_back(isPassLoose);
                recomediumids_->push_back(isPassMedium);
                recotightids_ ->push_back(isPassTight);

                double wx=el->px()+recoMet_px;
                double wy=el->py()+recoMet_py;
                double wpt=sqrt(wx*wx+wy*wy);
                double et=el->et() +  recoMet_Et_;
                double massT=et*et-wpt*wpt;
                massT =massT>0?sqrt(massT):0;    

                recomts_->push_back(massT);

                if(isPassLoose && el->pt()>leadPt) {second=lead; secondPt=leadPt; lead=i; leadPt=el->pt();}
                else if(isPassLoose && el->pt()>secondPt) {second=i; secondPt=el->pt();}


                // Impact parameter
                reco::GsfTrackRef theTrack = el->gsfTrack();
                recodzs_->push_back( theTrack->dz( firstGoodVertex->position() ) );
                recod0s_->push_back( theTrack->dxy( firstGoodVertex->position() ) );
                // Conversion rejection
                bool passConvVeto = !ConversionTools::hasMatchedConversion(*el, 
                                conversions,
                                theBeamSpot->position());
                recoconversions_->push_back( (int) passConvVeto );


                if(el->pt()>10) {             
                        if(isPassLoose) recoNLoose10_++; 
                        if(isPassMedium) recoNMedium10_++;
                        if(isPassTight) recoNTight10_++;
                }
                if(el->pt()>20) {
                        if(isPassLoose) recoNLoose20_++;
                        if(isPassMedium) recoNMedium20_++;
                        if(isPassTight) recoNTight20_++;
                }  

                int match=-1;
                double minAngle=0.5;
                for (size_t j = 0; j < objects.size(); ++j) {
                        double deltaEta=(objects[j]->eta() - el->eta() );
                        double deltaPhi=reco::deltaPhi(objects[j]->phi(),el->phi());
                        double dR=sqrt( deltaEta*deltaEta + deltaPhi*deltaPhi)   ;
                        if(dR<minAngle) {minAngle=dR; match=j;} 
                }
                if(match!=-1) {
                        l1matchedpt_->push_back(objects[match]->pt());
                        l1matchedeta_->push_back(objects[match]->eta());
                        l1matchedphi_->push_back(objects[match]->phi());
                        l1matcheddR_->push_back(minAngle);
                } 
                else{
                        l1matchedpt_->push_back(0);
                        l1matchedeta_->push_back(0);
                        l1matchedphi_->push_back(0);
                        l1matcheddR_->push_back(-1);
                } 
                recomatches_->push_back(match);

                int matchJ=-1;
                double minAngleJ=0.5;
                for (size_t j = 0; j < jetObjects.size(); ++j) {
                        double deltaEta=(jetObjects[j]->eta() - el->eta() );
                        double deltaPhi=reco::deltaPhi(jetObjects[j]->phi(),el->phi());
                        double dR=sqrt( deltaEta*deltaEta + deltaPhi*deltaPhi)   ;
                        if(dR<minAngleJ) {minAngleJ=dR; matchJ=j;}
                }
                if(matchJ!=-1) {
                        l1matchedJetpt_->push_back(jetObjects[matchJ]->pt());
                        l1matchedJeteta_->push_back(jetObjects[matchJ]->eta());
                        l1matchedJetphi_->push_back(jetObjects[matchJ]->phi());
                        l1matchedJetdR_->push_back(minAngleJ);
                }
                else{
                        l1matchedJetpt_->push_back(0);
                        l1matchedJeteta_->push_back(0);
                        l1matchedJetphi_->push_back(0);
                        l1matchedJetdR_->push_back(-1);
                }



                double closestDR=10e6;
                double JET=0;
                for (size_t j = 0; j < recoJetObjects.size(); ++j) {
                        double deltaEta=(recoetas_->at(i) - recoJetObjects[j]->eta() );
                        double deltaPhi=reco::deltaPhi(recophis_->at(i),recoJetObjects[j]->phi());
                        double dR=sqrt( deltaEta*deltaEta + deltaPhi*deltaPhi)   ;
                        /*if(dR<0.05) {
                          continue;
                          } */ 
                        if(dR<closestDR) {closestDR=dR;
                                JET=recoJetObjects[j]->pt(); }
                }

                recodRToJet_->push_back(closestDR);
                recoMatchedJet_->push_back(JET);

        }

        if(leadPt>10 && secondPt>10){
                const auto el1 = electrons->ptrAt(lead);
                const auto el2 = electrons->ptrAt(second);
                recomassForZ_=(el1->p4()+el2->p4()).mass();
                leadElectronForZ_=lead;
                secondElectronForZ_=second;

                if(recomatches_->at(lead)!=-1 && recomatches_->at(second)!=-1 && recomatches_->at(second)!= recomatches_->at(lead)){
                        recomassForZL1_=(objects[recomatches_->at(lead)]->p4()+objects[recomatches_->at(second)]->p4()).mass(); 

                        TLorentzVector z1, z2;
                        z1.SetPtEtaPhiE(objects[recomatches_->at(lead)]->pt(),el1->eta(),el1->phi(),objects[recomatches_->at(lead)]->energy());
                        z2.SetPtEtaPhiE(objects[recomatches_->at(second)]->pt(),el2->eta(),el2->phi(),objects[recomatches_->at(second)]->energy());

                        recomassForZL1V2_=(z1+z2).M();

                        //cout<<recomassForZ_<<"   "<<recomassForZL1_<<"  "<<recomassForZL1V2_<<endl;     

                } 



        }



//         std::cout<<"jet Objects!"<<std::endl;
        for (size_t i = 0; i < jetObjects.size(); ++i) {
//                  std::cout<<jetObjects[i]->pt()<<"   "<<jetObjects[i]->eta()<<"   "<<jetObjects[i]->phi()<<std::endl;
                if(jetObjects[i]->pt()<20) continue;
                jetpts_->push_back(jetObjects[i]->pt());
                jetetas_->push_back(jetObjects[i]->eta());
                jetphis_->push_back(jetObjects[i]->phi());
        }

  //       std::cout<<"reco Jet Objects!"<<std::endl;
        for (size_t i = 0; i < recoJetObjects.size(); ++i) {

                double eta= recoJetObjects[i]->eta();

                double NHF = recoJetObjects[i]->neutralHadronEnergyFraction();

                double NEMF = recoJetObjects[i]->neutralEmEnergyFraction();

                double CHF = recoJetObjects[i]->chargedHadronEnergyFraction();

                double MUF = recoJetObjects[i]->muonEnergyFraction();

                double CEMF = recoJetObjects[i]->chargedEmEnergyFraction();

                double NumConst = recoJetObjects[i]->chargedMultiplicity()+recoJetObjects[i]->neutralMultiplicity();

                double NumNeutralParticles =recoJetObjects[i]->neutralMultiplicity();

                double CHM = recoJetObjects[i]->chargedMultiplicity(); 

                bool looseJetID=true, tightJetID=true, tightLepVetoJetID=true;

                if(fabs(recoJetObjects[i]->eta())<3.0){
                        looseJetID = (NHF<0.99 && NEMF<0.99 && NumConst>1) && ((fabs(eta)<=2.4 && CHF>0 && CHM>0 && CEMF<0.99) || fabs(eta)>2.4) ;

                        tightJetID = (NHF<0.90 && NEMF<0.90 && NumConst>1) && ((fabs(eta)<=2.4 && CHF>0 && CHM>0 && CEMF<0.99) || fabs(eta)>2.4) ;

                        tightLepVetoJetID = (NHF<0.90 && NEMF<0.90 && NumConst>1 && MUF<0.8) && ((fabs(eta)<=2.4 && CHF>0 && CHM>0 && CEMF<0.90) || fabs(eta)>2.4);
                }
                else{
                        looseJetID = (NEMF<0.90 && NumNeutralParticles>10 && fabs(eta)>3.0 );
                        tightJetID = (NEMF<0.90 && NumNeutralParticles>10 && fabs(eta)>3.0 ) ;
                }

                bool isEle=false;
                for (size_t j=0; j<recoetas_->size(); j++){
                        double deltaEta=(recoetas_->at(j) - recoJetObjects[i]->eta() );
                        double deltaPhi=reco::deltaPhi(recophis_->at(j),recoJetObjects[i]->phi());
                        double dR=sqrt( deltaEta*deltaEta + deltaPhi*deltaPhi)   ;
                        if(dR<0.5) {isEle=true;}
                }
                if (isEle) continue;

                if(recoJetObjects[i]->pt()<30) continue;
   //               std::cout<<recoJetObjects[i]->pt()<<"   "<<recoJetObjects[i]->eta()<<"   "<<recoJetObjects[i]->phi()<<std::endl;
                recoJetpts_->push_back(recoJetObjects[i]->pt());
                recoJetetas_->push_back(recoJetObjects[i]->eta());
                recoJetphis_->push_back(recoJetObjects[i]->phi());
                int match=-1;
                double minAngle=2;
                for (size_t j=0; j<jetpts_->size(); j++){
                        double deltaEta=(jetetas_->at(j) - recoJetObjects[i]->eta() );
                        double deltaPhi=reco::deltaPhi(jetphis_->at(j),recoJetObjects[i]->phi());
                        double dR=sqrt( deltaEta*deltaEta + deltaPhi*deltaPhi)   ;
                        if(dR<minAngle) {minAngle=dR; match=j;}
                }
                recoJetmatches_->push_back(match);
                recoJetLooseJetID_->push_back(looseJetID);
                recoJetTightJetID_->push_back(tightJetID);
                recoJetTightLepVetoJetID_->push_back(tightLepVetoJetID);


                if(recoJetObjects[i]->pt()>20) recoNJet20_++;
                if(recoJetObjects[i]->pt()>30) recoNJet30_++;
                if(recoJetObjects[i]->pt()>40) recoNJet40_++;



                //  std::cout<<"-----> matched to"<<match<<std::endl;
        }

        tree->Fill();
}

#include "FWCore/Framework/interface/MakerMacros.h"
DEFINE_FWK_MODULE(WZEffiTree);
