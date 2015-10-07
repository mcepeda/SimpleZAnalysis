//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Aug 19 11:39:20 2015 by ROOT version 6.02/04
// from TTree Ntuple/Ntuple
// found on file: roots/RateStage1OnlyMatched.root
//////////////////////////////////////////////////////////

#ifndef tpgs2_h
#define tpgs2_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"

class tpgs2 : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   vector<float>   *rankTP;
   vector<float>   *NSOITP;
   vector<int>     *etaTP;
   vector<int>     *phiTP;
   vector<int>     *ietaTP;
   vector<int>     *iphiTP;
   vector<int>     *spikeTP;
   ULong64_t       evt;
   ULong64_t       noEvt;

   // List of branches
   TBranch        *b_rankTP;   //!
   TBranch        *b_NSOITP;   //!
   TBranch        *b_etaTP;   //!
   TBranch        *b_phiTP;   //!
   TBranch        *b_ietaTP;   //!
   TBranch        *b_iphiTP;   //!
   TBranch        *b_spikeTP;   //!
   TBranch        *b_evt;   //!
   TBranch        *b_noEvt;   //!

   tpgs2(TTree * /*tree*/ =0) : fChain(0) { }
   virtual ~tpgs2() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(tpgs2,0);
};

#endif

#ifdef tpgs2_cxx
void tpgs2::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   rankTP = 0;
   NSOITP = 0;
   etaTP = 0;
   phiTP = 0;
   ietaTP = 0;
   iphiTP = 0;
   spikeTP = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("rankTP", &rankTP, &b_rankTP);
   fChain->SetBranchAddress("NSOITP", &NSOITP, &b_NSOITP);
   fChain->SetBranchAddress("etaTP", &etaTP, &b_etaTP);
   fChain->SetBranchAddress("phiTP", &phiTP, &b_phiTP);
   fChain->SetBranchAddress("ietaTP", &ietaTP, &b_ietaTP);
   fChain->SetBranchAddress("iphiTP", &iphiTP, &b_iphiTP);
   fChain->SetBranchAddress("spikeTP", &spikeTP, &b_spikeTP);
   fChain->SetBranchAddress("evt", &evt, &b_evt);
   fChain->SetBranchAddress("noEvt", &noEvt, &b_noEvt);
}

Bool_t tpgs2::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef tpgs2_cxx
