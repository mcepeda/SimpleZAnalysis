//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Aug 19 12:53:07 2015 by ROOT version 6.02/04
// from TTree Ntuple/Ntuple
// found on file: test_numEvent10000.root
//////////////////////////////////////////////////////////

#ifndef tpgs_h
#define tpgs_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"

class tpgs {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   vector<float>   *rankTP;
   vector<float>   *rankTPORIGINAL;
   vector<float>   *NSOITP;
   vector<int>     *ietaTP;
   vector<int>     *iphiTP;
   vector<int>     *spikeTP;
   ULong64_t       evt;
   ULong64_t       noEvt;

   // List of branches
   TBranch        *b_rankTP;   //!
   TBranch        *b_rankTPORIGINAL;   //!
   TBranch        *b_NSOITP;   //!
   TBranch        *b_ietaTP;   //!
   TBranch        *b_iphiTP;   //!
   TBranch        *b_spikeTP;   //!
   TBranch        *b_evt;   //!
   TBranch        *b_noEvt;   //!

   tpgs(TTree *tree=0);
   virtual ~tpgs();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef tpgs_cxx
tpgs::tpgs(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("test_numEvent10000.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("test_numEvent10000.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("test_numEvent10000.root:/comparetpsforres");
      dir->GetObject("Ntuple",tree);

   }
   Init(tree);
}

tpgs::~tpgs()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t tpgs::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t tpgs::LoadTree(Long64_t entry)
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

void tpgs::Init(TTree *tree)
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
   rankTPORIGINAL = 0;
   NSOITP = 0;
   ietaTP = 0;
   iphiTP = 0;
   spikeTP = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("rankTP", &rankTP, &b_rankTP);
   fChain->SetBranchAddress("rankTPORIGINAL", &rankTPORIGINAL, &b_rankTPORIGINAL);
   fChain->SetBranchAddress("NSOITP", &NSOITP, &b_NSOITP);
   fChain->SetBranchAddress("ietaTP", &ietaTP, &b_ietaTP);
   fChain->SetBranchAddress("iphiTP", &iphiTP, &b_iphiTP);
   fChain->SetBranchAddress("spikeTP", &spikeTP, &b_spikeTP);
   fChain->SetBranchAddress("evt", &evt, &b_evt);
   fChain->SetBranchAddress("noEvt", &noEvt, &b_noEvt);
   Notify();
}

Bool_t tpgs::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void tpgs::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t tpgs::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef tpgs_cxx
