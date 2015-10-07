//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Oct  7 14:43:18 2015 by ROOT version 6.02/05
// from TTree Ntuple/Ntuple
// found on file: roots/test.root
//////////////////////////////////////////////////////////

#ifndef effis_h
#define effis_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"

class effis {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
   const Int_t kMaxleadElectronForZ = 1;
   const Int_t kMaxsecondElectronForZ = 1;

   // Declaration of leaf types
   vector<float>   *pt;
   vector<float>   *eta;
   vector<float>   *phi;
   vector<int>     *recomatches;
   vector<float>   *recopt;
   vector<float>   *recomt;
   vector<float>   *l1matcheddR;
   vector<float>   *l1matchedpt;
   vector<float>   *l1matchedeta;
   vector<float>   *l1matchedphi;
   vector<float>   *l1matchedJetdR;
   vector<float>   *l1matchedJetpt;
   vector<float>   *l1matchedJeteta;
   vector<float>   *l1matchedJetphi;
   vector<float>   *recoeta;
   vector<float>   *recophi;
   vector<float>   *recocharge;
   vector<float>   *recodRToJet;
   vector<float>   *recoMatchedJet;
   vector<float>   *recolooseid;
   vector<float>   *recomediumid;
   vector<float>   *recotightid;
   vector<float>   *recodz;
   vector<float>   *recod0;
   vector<float>   *recoconversion;
   vector<float>   *jetpt;
   vector<float>   *jeteta;
   vector<float>   *jetphi;
   vector<int>     *recoJetmatches;
   vector<int>     *recoJetLooseJetID;
   vector<int>     *recoJetTightJetID;
   vector<int>     *recoJetTightLepVetoJetID;
   vector<float>   *recoJetpt;
   vector<float>   *recoJeteta;
   vector<float>   *recoJetphi;
   Float_t         recoMet_Et;
   Float_t         recoMet_Phi;
   Float_t         met_Et;
   Float_t         met_Phi;
   Float_t         recomassForZ;
   UInt_t          leadElectronForZ_;
   UInt_t          secondElectronForZ_;
   Float_t         recomassForZL1;
   Float_t         recomassForZL1V2;
   Float_t         genmassZ;
   Float_t         genmassZFromEle;
   Float_t         genfirstelept;
   Float_t         genfirsteleeta;
   Float_t         gensecondeleeta;
   Float_t         gensecondelept;
   UInt_t          foundGenZee;
   UInt_t          foundGenZeeFiducial;
   UInt_t          run;
   UInt_t          lumi;
   ULong64_t       evt;
   UInt_t          nPU;
   UInt_t          nvtx;
   Float_t         genweight;
   Float_t         instantLumi;
   Float_t         instantLumiErr;
   Float_t         pileupScalers;
   Float_t         pileupScalersRMS;
   Float_t         liveLumiFill;
   Float_t         liveLumiRun;
   UInt_t          recoNLoose10;
   UInt_t          recoNLoose20;
   UInt_t          recoNMedium20;
   UInt_t          recoNMedium10;
   UInt_t          recoNTight20;
   UInt_t          recoNTight10;
   UInt_t          recoNJet20;
   UInt_t          recoNJet30;
   UInt_t          recoNJet40;
   UInt_t          hltEle27Loose;
   UInt_t          hltEle27Tight;
   UInt_t          hltEle22Loose;
   UInt_t          hltEle22Tight;
   UInt_t          hltEle2775;
   UInt_t          hltEle23LooseFull;
   UInt_t          hltEle27LooseFull;
   UInt_t          hltEle2275Full;
   UInt_t          hltEle2375Full;

   // List of branches
   TBranch        *b_pt;   //!
   TBranch        *b_eta;   //!
   TBranch        *b_phi;   //!
   TBranch        *b_recomatches;   //!
   TBranch        *b_recopt;   //!
   TBranch        *b_recomt;   //!
   TBranch        *b_l1matcheddR;   //!
   TBranch        *b_l1matchedpt;   //!
   TBranch        *b_l1matchedeta;   //!
   TBranch        *b_l1matchedphi;   //!
   TBranch        *b_l1matchedJetdR;   //!
   TBranch        *b_l1matchedJetpt;   //!
   TBranch        *b_l1matchedJeteta;   //!
   TBranch        *b_l1matchedJetphi;   //!
   TBranch        *b_recoeta;   //!
   TBranch        *b_recophi;   //!
   TBranch        *b_recocharge;   //!
   TBranch        *b_recodRToJet;   //!
   TBranch        *b_recoMatchedJet;   //!
   TBranch        *b_recolooseid;   //!
   TBranch        *b_recomediumid;   //!
   TBranch        *b_recotightid;   //!
   TBranch        *b_recodz;   //!
   TBranch        *b_recod0;   //!
   TBranch        *b_recoconversion;   //!
   TBranch        *b_jetpt;   //!
   TBranch        *b_jeteta;   //!
   TBranch        *b_jetphi;   //!
   TBranch        *b_recoJetmatches;   //!
   TBranch        *b_recoJetLooseJetID;   //!
   TBranch        *b_recoJetTightJetID;   //!
   TBranch        *b_recoJetTightLepVetoJetID;   //!
   TBranch        *b_recoJetpt;   //!
   TBranch        *b_recoJeteta;   //!
   TBranch        *b_recoJetphi;   //!
   TBranch        *b_recoMet_Et;   //!
   TBranch        *b_recoMet_Phi;   //!
   TBranch        *b_met_Et;   //!
   TBranch        *b_met_Phi;   //!
   TBranch        *b_recomassForZ;   //!
   TBranch        *b_leadElectronForZ_;   //!
   TBranch        *b_secondElectronForZ_;   //!
   TBranch        *b_recomassForZL1;   //!
   TBranch        *b_recomassForZL1V2;   //!
   TBranch        *b_genmassZ;   //!
   TBranch        *b_genmassZFromEle;   //!
   TBranch        *b_genfirstelept;   //!
   TBranch        *b_genfirsteleeta;   //!
   TBranch        *b_gensecondeleeta;   //!
   TBranch        *b_gensecondelept;   //!
   TBranch        *b_foundGenZee;   //!
   TBranch        *b_foundGenZeeFiducial;   //!
   TBranch        *b_run;   //!
   TBranch        *b_lumi;   //!
   TBranch        *b_evt;   //!
   TBranch        *b_nPU;   //!
   TBranch        *b_nvtx;   //!
   TBranch        *b_genweight;   //!
   TBranch        *b_instantLumi;   //!
   TBranch        *b_instantLumiErr;   //!
   TBranch        *b_pileupScalers;   //!
   TBranch        *b_pileupScalersRMS;   //!
   TBranch        *b_liveLumiFill;   //!
   TBranch        *b_liveLumiRun;   //!
   TBranch        *b_recoNLoose10;   //!
   TBranch        *b_recoNLoose20;   //!
   TBranch        *b_recoNMedium20;   //!
   TBranch        *b_recoNMedium10;   //!
   TBranch        *b_recoNTight20;   //!
   TBranch        *b_recoNTight10;   //!
   TBranch        *b_recoNJet20;   //!
   TBranch        *b_recoNJet30;   //!
   TBranch        *b_recoNLoose40;   //!
   TBranch        *b_hltEle27Loose;   //!
   TBranch        *b_hltEle27Tight;   //!
   TBranch        *b_hltEle22Loose;   //!
   TBranch        *b_hltEle22Tight;   //!
   TBranch        *b_hltEle2775;   //!
   TBranch        *b_hltEle23LooseFull;   //!
   TBranch        *b_hltEle27LooseFull;   //!
   TBranch        *b_hltEle2275Full;   //!
   TBranch        *b_hltEle2375Full;   //!

   effis(TTree *tree=0);
   virtual ~effis();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(TString outputFile, double scale, bool forQCD);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef effis_cxx
effis::effis(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("roots/test.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("roots/test.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("roots/test.root:/effitreeWZ");
      dir->GetObject("Ntuple",tree);

   }
   Init(tree);
}

effis::~effis()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t effis::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t effis::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void effis::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   pt = 0;
   eta = 0;
   phi = 0;
   recomatches = 0;
   recopt = 0;
   recomt = 0;
   l1matcheddR = 0;
   l1matchedpt = 0;
   l1matchedeta = 0;
   l1matchedphi = 0;
   l1matchedJetdR = 0;
   l1matchedJetpt = 0;
   l1matchedJeteta = 0;
   l1matchedJetphi = 0;
   recoeta = 0;
   recophi = 0;
   recocharge = 0;
   recodRToJet = 0;
   recoMatchedJet = 0;
   recolooseid = 0;
   recomediumid = 0;
   recotightid = 0;
   recodz = 0;
   recod0 = 0;
   recoconversion = 0;
   jetpt = 0;
   jeteta = 0;
   jetphi = 0;
   recoJetmatches = 0;
   recoJetLooseJetID = 0;
   recoJetTightJetID = 0;
   recoJetTightLepVetoJetID = 0;
   recoJetpt = 0;
   recoJeteta = 0;
   recoJetphi = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("pt", &pt, &b_pt);
   fChain->SetBranchAddress("eta", &eta, &b_eta);
   fChain->SetBranchAddress("phi", &phi, &b_phi);
   fChain->SetBranchAddress("recomatches", &recomatches, &b_recomatches);
   fChain->SetBranchAddress("recopt", &recopt, &b_recopt);
   fChain->SetBranchAddress("recomt", &recomt, &b_recomt);
   fChain->SetBranchAddress("l1matcheddR", &l1matcheddR, &b_l1matcheddR);
   fChain->SetBranchAddress("l1matchedpt", &l1matchedpt, &b_l1matchedpt);
   fChain->SetBranchAddress("l1matchedeta", &l1matchedeta, &b_l1matchedeta);
   fChain->SetBranchAddress("l1matchedphi", &l1matchedphi, &b_l1matchedphi);
   fChain->SetBranchAddress("l1matchedJetdR", &l1matchedJetdR, &b_l1matchedJetdR);
   fChain->SetBranchAddress("l1matchedJetpt", &l1matchedJetpt, &b_l1matchedJetpt);
   fChain->SetBranchAddress("l1matchedJeteta", &l1matchedJeteta, &b_l1matchedJeteta);
   fChain->SetBranchAddress("l1matchedJetphi", &l1matchedJetphi, &b_l1matchedJetphi);
   fChain->SetBranchAddress("recoeta", &recoeta, &b_recoeta);
   fChain->SetBranchAddress("recophi", &recophi, &b_recophi);
   fChain->SetBranchAddress("recocharge", &recocharge, &b_recocharge);
   fChain->SetBranchAddress("recodRToJet", &recodRToJet, &b_recodRToJet);
   fChain->SetBranchAddress("recoMatchedJet", &recoMatchedJet, &b_recoMatchedJet);
   fChain->SetBranchAddress("recolooseid", &recolooseid, &b_recolooseid);
   fChain->SetBranchAddress("recomediumid", &recomediumid, &b_recomediumid);
   fChain->SetBranchAddress("recotightid", &recotightid, &b_recotightid);
   fChain->SetBranchAddress("recodz", &recodz, &b_recodz);
   fChain->SetBranchAddress("recod0", &recod0, &b_recod0);
   fChain->SetBranchAddress("recoconversion", &recoconversion, &b_recoconversion);
   fChain->SetBranchAddress("jetpt", &jetpt, &b_jetpt);
   fChain->SetBranchAddress("jeteta", &jeteta, &b_jeteta);
   fChain->SetBranchAddress("jetphi", &jetphi, &b_jetphi);
   fChain->SetBranchAddress("recoJetmatches", &recoJetmatches, &b_recoJetmatches);
   fChain->SetBranchAddress("recoJetLooseJetID", &recoJetLooseJetID, &b_recoJetLooseJetID);
   fChain->SetBranchAddress("recoJetTightJetID", &recoJetTightJetID, &b_recoJetTightJetID);
   fChain->SetBranchAddress("recoJetTightLepVetoJetID", &recoJetTightLepVetoJetID, &b_recoJetTightLepVetoJetID);
   fChain->SetBranchAddress("recoJetpt", &recoJetpt, &b_recoJetpt);
   fChain->SetBranchAddress("recoJeteta", &recoJeteta, &b_recoJeteta);
   fChain->SetBranchAddress("recoJetphi", &recoJetphi, &b_recoJetphi);
   fChain->SetBranchAddress("recoMet_Et", &recoMet_Et, &b_recoMet_Et);
   fChain->SetBranchAddress("recoMet_Phi", &recoMet_Phi, &b_recoMet_Phi);
   fChain->SetBranchAddress("met_Et", &met_Et, &b_met_Et);
   fChain->SetBranchAddress("met_Phi", &met_Phi, &b_met_Phi);
   fChain->SetBranchAddress("recomassForZ", &recomassForZ, &b_recomassForZ);
   fChain->SetBranchAddress("leadElectronForZ_", &leadElectronForZ_, &b_leadElectronForZ_);
   fChain->SetBranchAddress("secondElectronForZ_", &secondElectronForZ_, &b_secondElectronForZ_);
   fChain->SetBranchAddress("recomassForZL1", &recomassForZL1, &b_recomassForZL1);
   fChain->SetBranchAddress("recomassForZL1V2", &recomassForZL1V2, &b_recomassForZL1V2);
   fChain->SetBranchAddress("genmassZ", &genmassZ, &b_genmassZ);
   fChain->SetBranchAddress("genmassZFromEle", &genmassZFromEle, &b_genmassZFromEle);
   fChain->SetBranchAddress("genfirstelept", &genfirstelept, &b_genfirstelept);
   fChain->SetBranchAddress("genfirsteleeta", &genfirsteleeta, &b_genfirsteleeta);
   fChain->SetBranchAddress("gensecondeleeta", &gensecondeleeta, &b_gensecondeleeta);
   fChain->SetBranchAddress("gensecondelept", &gensecondelept, &b_gensecondelept);
   fChain->SetBranchAddress("foundGenZee", &foundGenZee, &b_foundGenZee);
   fChain->SetBranchAddress("foundGenZeeFiducial", &foundGenZeeFiducial, &b_foundGenZeeFiducial);
   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("lumi", &lumi, &b_lumi);
   fChain->SetBranchAddress("evt", &evt, &b_evt);
   fChain->SetBranchAddress("nPU", &nPU, &b_nPU);
   fChain->SetBranchAddress("nvtx", &nvtx, &b_nvtx);
   fChain->SetBranchAddress("genweight", &genweight, &b_genweight);
   fChain->SetBranchAddress("instantLumi", &instantLumi, &b_instantLumi);
   fChain->SetBranchAddress("instantLumiErr", &instantLumiErr, &b_instantLumiErr);
   fChain->SetBranchAddress("pileupScalers", &pileupScalers, &b_pileupScalers);
   fChain->SetBranchAddress("pileupScalersRMS", &pileupScalersRMS, &b_pileupScalersRMS);
   fChain->SetBranchAddress("liveLumiFill", &liveLumiFill, &b_liveLumiFill);
   fChain->SetBranchAddress("liveLumiRun", &liveLumiRun, &b_liveLumiRun);
   fChain->SetBranchAddress("recoNLoose10", &recoNLoose10, &b_recoNLoose10);
   fChain->SetBranchAddress("recoNLoose20", &recoNLoose20, &b_recoNLoose20);
   fChain->SetBranchAddress("recoNMedium20", &recoNMedium20, &b_recoNMedium20);
   fChain->SetBranchAddress("recoNMedium10", &recoNMedium10, &b_recoNMedium10);
   fChain->SetBranchAddress("recoNTight20", &recoNTight20, &b_recoNTight20);
   fChain->SetBranchAddress("recoNTight10", &recoNTight10, &b_recoNTight10);
   fChain->SetBranchAddress("recoNJet20", &recoNJet20, &b_recoNJet20);
   fChain->SetBranchAddress("recoNJet30", &recoNJet30, &b_recoNJet30);
   fChain->SetBranchAddress("recoNJet40", &recoNJet40, &b_recoNLoose40);
   fChain->SetBranchAddress("hltEle27Loose", &hltEle27Loose, &b_hltEle27Loose);
   fChain->SetBranchAddress("hltEle27Tight", &hltEle27Tight, &b_hltEle27Tight);
   fChain->SetBranchAddress("hltEle22Loose", &hltEle22Loose, &b_hltEle22Loose);
   fChain->SetBranchAddress("hltEle22Tight", &hltEle22Tight, &b_hltEle22Tight);
   fChain->SetBranchAddress("hltEle2775", &hltEle2775, &b_hltEle2775);
   fChain->SetBranchAddress("hltEle23LooseFull", &hltEle23LooseFull, &b_hltEle23LooseFull);
   fChain->SetBranchAddress("hltEle27LooseFull", &hltEle27LooseFull, &b_hltEle27LooseFull);
   fChain->SetBranchAddress("hltEle2275Full", &hltEle2275Full, &b_hltEle2275Full);
   fChain->SetBranchAddress("hltEle2375Full", &hltEle2375Full, &b_hltEle2375Full);
   Notify();
}

Bool_t effis::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void effis::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t effis::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef effis_cxx
