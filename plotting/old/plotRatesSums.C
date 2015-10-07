#include "TH1.h" 
#include "TTree.h"
#include "TFile.h"
#include "TCanvas.h"
#include "tdrstyle.C"

void plotRatesSums(int version=0)
{
        setTDRStyle();

TFile*   file=new TFile("newroots/rate833.root");
TFile*   file2=new TFile("newroots/rate833NEWSFNOPU.root");

//TFile*   file=new TFile("newroots/rate833.root");
//TFile*   file2=new TFile("newroots/rate833OLDSFNOPU.root");
//TFile*   file2=new TFile("newroots/rate833NEWSFNOPU.root");
//TFile*   file2=new TFile("newroots/rate833.root");


Double_t rateTot=328*11245;

/*
 l1MET           = 254
 l1MET           = 9
 l1SHT           = 9.5
 l1SET           = 41.5
*/

/*
TString DIR1="sumsL1Rates/Ntuple";
TString DIR2="sumsL1RatesGCT/Ntuple";
TString Legend1="Stage1, MET, New SF, NO PU";
TString Legend2="GCT, MET, New SF";

TString DIR3="sumsL1Rates/Ntuple";
TString DIR4="sumsL1RatesGCT/Ntuple";
TString Legend3="Stage1, SHT, New SF, NO PU";
TString Legend4="GCT, SHT, New SF";


TString DIR1="sumsL1RatesUnpacked/Ntuple";
TString DIR2="sumsL1Rates/Ntuple";
TString Legend1="Stage1, MET";
TString Legend2="Stage1, MET, NO RCT CALIB";

TString DIR3="sumsL1RatesUnpacked/Ntuple";
TString DIR4="sumsL1Rates/Ntuple";
TString Legend3="Stage1, SHT";
TString Legend4="Stage1, SHT, NO RCT CALIB";
*/

TString DIR1="sumsL1Rates/Ntuple";
TString DIR2="sumsL1Rates/Ntuple";
TString Legend1="Stage1, SET, New SF, PU";
TString Legend2="Stage1, SET, New SF, NO PU";

TString DIR3="sumsL1Rates/Ntuple";
TString DIR4="sumsL1RatesGCT/Ntuple";
TString Legend3="Stage1, SET, New SF, PU";
TString Legend4="GCT, SET, New SF";

/*
TString DIR1="sumsL1RatesGCT/Ntuple";
TString DIR2="sumsL1RatesGCT/Ntuple";
TString Legend1="GCT, MET, New SF";
TString Legend2="GCT, MET, Old SF";

TString DIR3="sumsL1RatesGCT/Ntuple";
TString DIR4="sumsL1RatesGCT/Ntuple";
TString Legend3="GCT, SHT, New SF";
TString Legend4="GCT, SHT, Old SF";


TString DIR1="sumsL1Rates/Ntuple";
TString DIR2="sumsL1Rates/Ntuple";
TString Legend1="Stage1, MET, New SF, PU";
TString Legend2="Stage1, MET, New SF, NO PU";

TString DIR3="sumsL1Rates/Ntuple";
TString DIR4="sumsL1Rates/Ntuple";
TString Legend3="Stage1, SHT, New SF, PU";
TString Legend4="Stage1, SHT, New SF, NO PU";


TString DIR1="sumsL1RatesGCTUnpacked/Ntuple";
TString DIR2="sumsL1RatesGCT/Ntuple";
TString Legend1="GCT, MET, Unpacked";
TString Legend2="GCT, MET, Reemulated";

TString DIR3="sumsL1RatesGCTUnpacked/Ntuple";
TString DIR4="sumsL1RatesGCT/Ntuple";
TString Legend3="GCT, SHT, Unpacked";
TString Legend4="GCT, SHT, Reemulated";

TString DIR1="sumsL1RatesUnpacked/Ntuple";
TString DIR2="sumsL1Rates/Ntuple";
TString Legend1="Stage1, MET, Unpacked";
TString Legend2="Stage1, MET, Reemulated";

TString DIR3="sumsL1RatesUnpacked/Ntuple";
TString DIR4="sumsL1Rates/Ntuple";
TString Legend3="Stage1, SHT, Unpacked";
TString Legend4="Stage1, SHT, Reemulated";
*/


TTree* tupleUNO=(TTree*)file->Get(DIR1);  tupleUNO->SetName("tupleUNO");
TTree* tupleDOS=(TTree*)file2->Get(DIR2); tupleDOS->SetName("tupleDOS");
TTree* tupleTRES=(TTree*)file->Get(DIR3);  tupleTRES->SetName("tupleTRES");
TTree* tupleCUATRO=(TTree*)file2->Get(DIR4); tupleCUATRO->SetName("tupleCUATRO");

Double_t getEntries=tupleDOS->GetEntries();

double scale=rateTot/getEntries;

TH1F* histoDOSPtElectrons, *histoUNOPtElectrons,*histoTRESPtElectrons,*histoCUATROPtElectrons,*histoCINCOPtElectrons;
tupleDOS->Draw("l1SET>>htemp(500,0,500)","","pE");
histoDOSPtElectrons=(TH1F*)gPad->GetPrimitive("htemp");
histoDOSPtElectrons->SetName("histoDOSPtElectrons");
histoDOSPtElectrons->SetLineColor(kPink+10);
histoDOSPtElectrons->SetMarkerColor(kPink+10);


tupleUNO->Draw("l1SET>>htemp(500,0,500)","","pE");
histoUNOPtElectrons=(TH1F*)gPad->GetPrimitive("htemp");
histoUNOPtElectrons->SetName("histoUNOPtElectrons");
histoUNOPtElectrons->SetLineColor(kPink+1);
histoUNOPtElectrons->SetMarkerColor(kPink+1);

tupleCUATRO->Draw("l1SET>>htemp(500,0,500)","","pE");
histoCUATROPtElectrons=(TH1F*)gPad->GetPrimitive("htemp");
histoCUATROPtElectrons->SetName("histoCUATROPtElectrons");
histoCUATROPtElectrons->SetLineColor(kAzure+4);
histoCUATROPtElectrons->SetMarkerColor(kAzure+4);

tupleTRES->Draw("l1SET>>htemp(500,0,500)","","pE");
histoTRESPtElectrons=(TH1F*)gPad->GetPrimitive("htemp");
histoTRESPtElectrons->SetName("histoTRESPtElectrons");
histoTRESPtElectrons->SetLineColor(kAzure);
histoTRESPtElectrons->SetMarkerColor(kAzure);

//histoDOSPtElectrons->Sumw2(); histoUNOPtElectrons->Sumw2(); histoTRESPtElectrons->Sumw2(); histoCUATROPtElectrons->Sumw2();



TCanvas *Canvas=new TCanvas("Canvas");
   Canvas->Range(-36.0515,-0.5334107,219.7425,4.887184);
   Canvas->SetLeftMargin(0.15);
   Canvas->SetRightMargin(0.08);
   Canvas->SetTopMargin(0.08);
   Canvas->SetBottomMargin(0.14);

TH1F *RateUNOEG=new TH1F("RateUNOEG","",500,0,500);
TH1F *RateDOSEG=new TH1F("RateDOSEG","",500,0,500);
TH1F *RateTRESEG=new TH1F("RateTRESEG","",500,0,500);
TH1F *RateCUATROEG=new TH1F("RateCUATROEG","",500,0,500);

RateTRESEG->SetLineColor(kAzure);
RateTRESEG->SetMarkerColor(kAzure);
RateCUATROEG->SetLineColor(kAzure+4);
RateCUATROEG->SetMarkerColor(kAzure+4);
RateUNOEG->SetLineColor(kPink+1);
RateUNOEG->SetMarkerColor(kPink+1);
RateDOSEG->SetLineColor(kPink+10);
RateDOSEG->SetMarkerColor(kPink+10);

int endBin=RateUNOEG->GetNbinsX();


for(int i=0; i<RateUNOEG->GetNbinsX();i++){
	double integral=0, error=0;
	integral=histoUNOPtElectrons->IntegralAndError(i,endBin,error);
	RateUNOEG->SetBinContent(i,integral);
        RateUNOEG->SetBinError(i,error);
        integral=histoDOSPtElectrons->IntegralAndError(i,endBin,error);
        RateDOSEG->SetBinContent(i,integral);
        RateDOSEG->SetBinError(i,error);
        integral=histoTRESPtElectrons->IntegralAndError(i,endBin,error);
        RateTRESEG->SetBinContent(i,integral);
        RateTRESEG->SetBinError(i,error);
        integral=histoCUATROPtElectrons->IntegralAndError(i,endBin,error);
        RateCUATROEG->SetBinContent(i,integral);
        RateCUATROEG->SetBinError(i,error);
}
RateUNOEG->Scale(scale);
RateDOSEG->Scale(scale);
RateTRESEG->Scale(scale);
RateCUATROEG->Scale(scale);

RateUNOEG->SetTitle("");
RateUNOEG->GetXaxis()->SetRangeUser(12,65);
RateUNOEG->SetMinimum(0.7);
RateUNOEG->SetLineWidth(1);
RateDOSEG->SetLineWidth(1);
RateUNOEG->GetYaxis()->SetTitleOffset(1.2);
Canvas->SetLogy();
RateUNOEG->SetXTitle("Sums Threshold [GeV]");
RateUNOEG->SetYTitle("Hz");
RateUNOEG->Draw("E");
RateTRESEG->Draw("E,sames");
RateDOSEG->Draw("E,sames");
RateCUATROEG->Draw("E,sames");

Canvas->SetGrid();

   TLegend *leg = new TLegend(0.2063758,0.2233857,0.58555005,0.434555,NULL,"brNDC");
   leg->SetFillColor(0);
   TLegendEntry *entry;
   entry=leg->AddEntry("RateUNOEG",Legend1,"lpf");
   entry=leg->AddEntry("RateDOSEG",Legend2,"lpf");
   //entry=leg->AddEntry("RateTRESEG",Legend3,"lpf");
   entry=leg->AddEntry("RateCUATROEG",Legend4,"lpf");
   leg->Draw();


TCanvas *Canvas2=new TCanvas("Canvas2");
   Canvas2->Range(-36.0515,-0.5334107,219.7425,4.887184);
   Canvas2->SetLeftMargin(0.15);
   Canvas2->SetRightMargin(0.08);
   Canvas2->SetTopMargin(0.08);
   Canvas2->SetBottomMargin(0.14);

   Canvas2->cd();

TH1F *CompareStage1=(TH1F*)RateDOSEG->Clone(); CompareStage1->SetName("CompareStage1");
CompareStage1->Divide(RateDOSEG,RateUNOEG,1,1,"B");
TH1F *CompareLegacy=(TH1F*)RateCUATROEG->Clone(); CompareLegacy->SetName("CompareLegacy");
CompareLegacy->Divide(RateCUATROEG,RateTRESEG,1,1,"B");

CompareLegacy->SetMarkerStyle(20);
CompareStage1->SetMarkerStyle(24);

CompareStage1->Draw();
CompareLegacy->Draw("sames");

Canvas2->SetGrid();

CompareStage1->SetYTitle("Ratio");
CompareStage1->SetXTitle("Sums threshold");
CompareStage1->GetYaxis()->SetRangeUser(0,5);



/*
TCanvas *CanvasElectrons=new TCanvas("CanvasElectrons");
   CanvasElectrons->Range(-36.0515,-0.5334107,219.7425,4.887184);
   CanvasElectrons->SetLeftMargin(0.15);
   CanvasElectrons->SetRightMargin(0.08);
   CanvasElectrons->SetTopMargin(0.08);
   CanvasElectrons->SetBottomMargin(0.14);
histoDOSPtElectrons->Divide(histoUNOPtElectrons);
histoDOSPtElectrons->Draw("");
histoCUATROPtElectrons->Divide(histoUNOPtElectrons);
histoCUATROPtElectrons->Draw("sames");
histoDOSPtElectrons->SetMarkerStyle(24);
histoCUATROPtElectrons->SetMarkerStyle(20);


TCanvas *CanvasCompareElectrons=new TCanvas("CanvasCompareElectrons");
   CanvasCompareElectrons->Range(-36.0515,-0.5334107,219.7425,4.887184);
   CanvasCompareElectrons->SetLeftMargin(0.15);
   CanvasCompareElectrons->SetRightMargin(0.08);
   CanvasCompareElectrons->SetTopMargin(0.08);
   CanvasCompareElectrons->SetBottomMargin(0.14);

TH1F *CompareStage1=(TH1F*)RateDOSEG->Clone(); CompareStage1->SetName("CompareStage1");
CompareStage1->Divide(RateUNOEG);
TH1F *CompareLegacy=(TH1F*)RateCUATROEG->Clone(); CompareLegacy->SetName("CompareLegacy");
CompareLegacy->Divide(RateTRESEG);

CompareLegacy->SetMarkerStyle(20);
CompareStage1->SetMarkerStyle(24);

CompareStage1->Draw();
CompareLegacy->Draw("sames");

CompareStage1->SetYTitle("Relative Rate Reduction");
CompareStage1->SetXTitle("Sums threshold");
CompareStage1->GetYaxis()->SetRangeUser(0,1.05);

for(int bin=0; bin<RateUNOEG->GetNbinsX();bin++){
cout<<bin<<endl;
cout<<" Stage1: "<<RateUNOEG->GetBinContent(bin)<<"    "<<RateDOSEG->GetBinContent(bin)<<"  ->"<<CompareStage1->GetBinContent(bin)<<endl;
cout<<" Legacy: "<<RateTRESEG->GetBinContent(bin)<<"   "<<RateCUATROEG->GetBinContent(bin)<<"  ->"<<CompareLegacy->GetBinContent(bin)<<endl;
}


   TLegend *leg = new TLegend(0.2063758,0.2233857,0.58555005,0.434555,NULL,"brNDC");
   leg->SetFillColor(0);
   TLegendEntry *entry=leg->AddEntry("CompareStage1","Stage1","lpf");
   entry=leg->AddEntry("CompareLegacy","Legacy","lpf");
   leg->Draw();

*/

}
