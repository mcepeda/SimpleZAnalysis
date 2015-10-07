/*
 * =====================================================================================
 *
 *       Filename:  SumsRateTree.cc
 *
 *    Description:  Produces a tree of UCT event-level sums objects -
 *                  like MET, MT, MHT, etc.
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

#include "DataFormats/L1Trigger/interface/L1EtMissParticle.h"
#include "DataFormats/L1Trigger/interface/L1EtMissParticleFwd.h"

#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/Scalers/interface/LumiScalers.h"

#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

#include "TTree.h"

typedef std::vector<edm::InputTag> VInputTag;

class SumsRateTree : public edm::EDAnalyzer {
  public:
    SumsRateTree(const edm::ParameterSet& pset);
    virtual ~SumsRateTree();
    void analyze(const edm::Event& evt, const edm::EventSetup& es);
  private:
    edm::InputTag l1MHTSrc_;
    edm::InputTag l1METSrc_;
    edm::InputTag l1SHTSrc_;
    edm::InputTag l1SETSrc_;

    TTree* tree;

    Float_t l1MHT_;
    Float_t l1MET_;
    Float_t l1SHT_;
    Float_t l1SET_;


    Int_t pu_;
    UInt_t run_;
    ULong64_t event_;

};

SumsRateTree::SumsRateTree(const edm::ParameterSet& pset) {
  // Initialize the ntuple builder
  edm::Service<TFileService> fs;
  tree = fs->make<TTree>("Ntuple", "Ntuple");

  tree->Branch("l1MHT", &l1MHT_, "l1MHT/F");
  tree->Branch("l1MET", &l1MET_, "l1MET/F");
  tree->Branch("l1SHT", &l1SHT_, "l1SHT/F");
  tree->Branch("l1SET", &l1SET_, "l1SET/F");

  tree->Branch("run", &run_, "run/i");
  tree->Branch("evt", &event_, "evt/l");

  l1MHTSrc_ = pset.getParameter<edm::InputTag>("l1MHTSrc");
  l1METSrc_ = pset.getParameter<edm::InputTag>("l1METSrc");
  l1SHTSrc_ = pset.getParameter<edm::InputTag>("l1SHTSrc");
  l1SETSrc_ = pset.getParameter<edm::InputTag>("l1SETSrc");

}

SumsRateTree::~SumsRateTree() {}

namespace {

double getValue(const edm::Event& evt, const edm::InputTag& tag, bool et=false) {
  edm::Handle<l1extra::L1EtMissParticleCollection> handle;
  evt.getByLabel(tag, handle);
  double ET=handle->at(0).etMiss();
  if(et)  ET=handle->at(0).etTotal();
  return ET;

}

}

void SumsRateTree::analyze(const edm::Event& evt, const edm::EventSetup& es) {

  // Setup meta info
  run_ = evt.id().run();
  event_ = evt.id().event();

  l1MHT_ = getValue(evt, l1MHTSrc_,false);
  l1MET_ = getValue(evt, l1METSrc_,false);
  l1SHT_ = getValue(evt, l1SHTSrc_,true);
  l1SET_ = getValue(evt, l1SETSrc_,true);

  tree->Fill();
}

#include "FWCore/Framework/interface/MakerMacros.h"
DEFINE_FWK_MODULE(SumsRateTree);
