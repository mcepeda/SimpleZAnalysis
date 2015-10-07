#define tpgs_cxx
#include "tpgs.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TH1F.h>

void compare(tpgs treeMatched);

void compareTPGs(){

TFile *fileMatched= new TFile("test_numEvent100000.root");
TTree* tupleMatched=  (TTree*)fileMatched->Get("comparetpsforres/Ntuple");

tpgs treeMatched;
treeMatched.Init(tupleMatched);
treeMatched.Loop();

}

void compare(tpgs treeMatched){

   Long64_t nentries = 10000;//treeMatched->GetEntries();

   Long64_t total=0;

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = treeMatched.LoadTree(jentry);
      if (ientry < 0) break;
	total++;
      nb = treeMatched.GetEntry(jentry);   nbytes += nb;

      for (int i=0; i<treeMatched.ietaTP->size(); i++)
		cout<<treeMatched.ietaTP->at(i)<<endl;
   }
	
	cout<<total;


}

void tpgs::Loop()
{
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   TH1F *etaTP = new TH1F("etaTP","",81,-40,40); etaTP->Sumw2();
   TH1F *resTP = new TH1F ("resTP","",1000,-1,1); resTP->Sumw2();
   TH2D *resTP2D = new TH2D ("resTP2D","",81,-40,40,1000,-1,1); resTP2D->Sumw2();
   TH1F *resTPEE = new TH1F ("resTPEE","",1000,-1,1); resTPEE->Sumw2();
   TH1F *resTPEB = new TH1F ("resTPEB","",1000,-1,1); resTPEB->Sumw2();
   TH2D *plotrankTP = new TH2D("plotrankTP","",255,0,255,255,0,255); plotrankTP->Sumw2();
   TH2D *plotrankTPEB = new TH2D("plotrankTPEB","",255,0,255,255,0,255); plotrankTPEB->Sumw2();
   TH2D *plotrankTPEE = new TH2D("plotrankTPEE","",255,0,255,255,0,255); plotrankTPEE->Sumw2();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

      for (int i=0; i<ietaTP->size(); i++)	{
	if( rankTPORIGINAL->at(i)==0) continue;
        if( rankTP->at(i)<20) continue;

		      etaTP->Fill(ietaTP->at(i));
		resTP->Fill(1-rankTP->at(i)/rankTPORIGINAL->at(i)) ;	
		if(abs(ietaTP->at(i))<=16) {
			resTPEB->Fill(1-rankTP->at(i)*1.00/rankTPORIGINAL->at(i)) ; 
			 plotrankTPEB->Fill(rankTP->at(i),rankTPORIGINAL->at(i));
		}
		else {
			resTPEE->Fill(1-rankTP->at(i)*1.000/rankTPORIGINAL->at(i)) ; 
                         plotrankTPEE->Fill(rankTP->at(i),rankTPORIGINAL->at(i));
                }
		resTP2D->Fill(ietaTP->at(i),1-rankTP->at(i)*1.000/rankTPORIGINAL->at(i)) ;
		plotrankTP->Fill(rankTP->at(i),rankTPORIGINAL->at(i));	
		
	}
   }

	TCanvas *C1=new TCanvas("C1");
   etaTP->Draw();
        C1->SaveAs("eta.png");


        TCanvas *C2=new TCanvas("C2");
	plotrankTPEE->Draw("box");
        plotrankTPEB->Draw("box,sames"); plotrankTPEB->SetLineColor(kRed);
        C2->SaveAs("res.png");

        C2->SaveAs("res.C");


        TCanvas *C3=new TCanvas("C3");
  	resTP2D->Draw("colz");
	C3->SaveAs("res2D.png");
        C3->SaveAs("res2D.root");


	TFile *out=new TFile("output.root","RECREATE");
	out->cd();
	plotrankTP->Write();
        plotrankTPEB->Write();
        plotrankTPEE->Write();
	resTP->Write();
	resTPEB->Write();
        resTPEE->Write();
	resTP2D->Write();

}
	


