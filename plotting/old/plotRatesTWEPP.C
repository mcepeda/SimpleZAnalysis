#include "TH1.h" 
#include "TTree.h"
#include "TFile.h"
#include "TCanvas.h"
#include "tdrstyle.C"

void plotRatesTWEPP(int version=0)
{
        setTDRStyle();

TFile*   file=new TFile("newroots/rate833.root");
//TFile*   file=new TFile("Rate_numEvent10000.root");


Double_t rateTot=328*11245;

TString DIR1="electronRate/Ntuple";
TString DIR2="electronIsoRate/Ntuple";
TString Legend1="Stage1, SingleEG";
TString Legend2="Stage1, SingleIsoEG";

TString DIR3="electronRateGCT/Ntuple";
TString DIR4="electronIsoRateGCT/Ntuple";
TString Legend3="Legacy, SingleEG";
TString Legend4="Legacy, SingleIsoEG";

TTree* tupleUNO=(TTree*)file->Get(DIR1);  tupleUNO->SetName("tupleUNO");
TTree* tupleDOS=(TTree*)file->Get(DIR2); tupleDOS->SetName("tupleDOS");
TTree* tupleTRES=(TTree*)file->Get(DIR3);  tupleTRES->SetName("tupleTRES");
TTree* tupleCUATRO=(TTree*)file->Get(DIR4); tupleCUATRO->SetName("tupleCUATRO");


Double_t getEntries=tupleDOS->GetEntries();

double scale=rateTot/getEntries;

TH1F* histoDOSPtElectrons, *histoUNOPtElectrons,*histoTRESPtElectrons,*histoCUATROPtElectrons,*histoCINCOPtElectrons;
tupleDOS->Draw("pt[0]>>htemp(70,0,70)","pt[0]!=100&&fabs(eta[0])<3.5","pE");
histoDOSPtElectrons=(TH1F*)gPad->GetPrimitive("htemp");
histoDOSPtElectrons->SetName("histoDOSPtElectrons");
histoDOSPtElectrons->SetLineColor(kPink+10);
histoDOSPtElectrons->SetMarkerColor(kPink+10);


tupleUNO->Draw("pt[0]>>htemp(70,0,70)","pt[0]!=100&&fabs(eta[0])<3.5","pE");
histoUNOPtElectrons=(TH1F*)gPad->GetPrimitive("htemp");
histoUNOPtElectrons->SetName("histoUNOPtElectrons");
histoUNOPtElectrons->SetLineColor(kPink+1);
histoUNOPtElectrons->SetMarkerColor(kPink+1);

tupleCUATRO->Draw("pt[0]>>htemp(70,0,70)","pt[0]!=100&&fabs(eta[0])<3.5","pE");
histoCUATROPtElectrons=(TH1F*)gPad->GetPrimitive("htemp");
histoCUATROPtElectrons->SetName("histoCUATROPtElectrons");
histoCUATROPtElectrons->SetLineColor(kAzure+4);
histoCUATROPtElectrons->SetMarkerColor(kAzure+4);

tupleTRES->Draw("pt[0]>>htemp(70,0,70)","pt[0]!=100&&fabs(eta[0])<3.5","pE");
histoTRESPtElectrons=(TH1F*)gPad->GetPrimitive("htemp");
histoTRESPtElectrons->SetName("histoTRESPtElectrons");
histoTRESPtElectrons->SetLineColor(kAzure);
histoTRESPtElectrons->SetMarkerColor(kAzure);

//histoDOSPtElectrons->Sumw2(); histoUNOPtElectrons->Sumw2(); histoTRESPtElectrons->Sumw2(); histoCUATROPtElectrons->Sumw2();

histoCINCOPtElectrons=(TH1F*)histoTRESPtElectrons->Clone(); histoCINCOPtElectrons->SetName("histoCINCOPtElectrons");
for(int i=0; i<histoTRESPtElectrons->GetNbinsX();i++){
	if(i>=63) {histoCINCOPtElectrons->SetBinContent(i,histoTRESPtElectrons->GetBinContent(i));
		  histoCINCOPtElectrons->SetBinError(i,histoTRESPtElectrons->GetBinError(i));}
	else{ histoCINCOPtElectrons->SetBinContent(i,histoCUATROPtElectrons->GetBinContent(i));
		 histoCINCOPtElectrons->SetBinError(i,histoCUATROPtElectrons->GetBinError(i));}
}


TCanvas *CanvasRateElectrons=new TCanvas("CanvasRateElectrons");
   CanvasRateElectrons->Range(-36.0515,-0.5334107,219.7425,4.887184);
   CanvasRateElectrons->SetLeftMargin(0.15);
   CanvasRateElectrons->SetRightMargin(0.08);
   CanvasRateElectrons->SetTopMargin(0.08);
   CanvasRateElectrons->SetBottomMargin(0.14);
TH1F *RateUNOEG=new TH1F("RateUNOEG","",70,0,70);
TH1F *RateDOSEG=new TH1F("RateDOSEG","",70,0,70);
TH1F *RateTRESEG=new TH1F("RateTRESEG","",70,0,70);
TH1F *RateCUATROEG=new TH1F("RateCUATROEG","",70,0,70);
TH1F *RateCINCOEG=new TH1F("RateCINCOEG","",70,0,70);

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
        integral=histoCINCOPtElectrons->IntegralAndError(i,endBin,error);
        RateCINCOEG->SetBinContent(i,integral);
        RateCINCOEG->SetBinError(i,error);
}
RateUNOEG->Scale(scale);
RateDOSEG->Scale(scale);
RateTRESEG->Scale(scale);
RateCUATROEG->Scale(scale);
RateCINCOEG->Scale(scale);

RateUNOEG->SetTitle("");
RateUNOEG->GetXaxis()->SetRangeUser(12,65);
RateUNOEG->SetMinimum(0.7);
RateUNOEG->SetLineWidth(1);
RateDOSEG->SetLineWidth(1);
RateUNOEG->GetYaxis()->SetTitleOffset(1.2);
CanvasRateElectrons->SetLogy();
RateUNOEG->SetXTitle("Electron Threshold [GeV]");
RateUNOEG->SetYTitle("Hz");
RateUNOEG->Draw("E");
RateTRESEG->Draw("E,sames");
RateDOSEG->Draw("E,sames");
RateCUATROEG->Draw("E,sames");
RateCINCOEG->Draw("E,sames");

CanvasRateElectrons->SetGrid();
CanvasRateElectrons->SaveAs("RateElectrons.png");

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
TH1F *CompareLegacy2=(TH1F*)RateCINCOEG->Clone(); CompareLegacy2->SetName("CompareLegacy2");
CompareLegacy2->Divide(RateTRESEG);

CompareLegacy->SetMarkerStyle(20);
CompareStage1->SetMarkerStyle(24);
CompareLegacy2->SetMarkerStyle(20);

CompareStage1->Draw();
CompareLegacy->Draw("sames");
CompareLegacy2->Draw("sames");
CompareStage1->SetYTitle("Relative Rate Reduction");
CompareStage1->SetXTitle("Electron p_{T} threshold");
CompareStage1->GetYaxis()->SetRangeUser(0,1.05);

for(int bin=0; bin<RateUNOEG->GetNbinsX();bin++){
cout<<bin<<endl;
cout<<" Stage1: "<<RateUNOEG->GetBinContent(bin)<<"    "<<RateDOSEG->GetBinContent(bin)<<"  ->"<<CompareStage1->GetBinContent(bin)<<endl;
cout<<" Legacy: "<<RateTRESEG->GetBinContent(bin)<<"   "<<RateCUATROEG->GetBinContent(bin)<<"  ->"<<CompareLegacy->GetBinContent(bin)<<endl;
}


   TLegend *leg = new TLegend(0.2063758,0.2233857,0.5855705,0.434555,NULL,"brNDC");
   leg->SetFillColor(0);
   TLegendEntry *entry=leg->AddEntry("CompareStage1","Stage1","lpf");
   entry=leg->AddEntry("CompareLegacy","Legacy","lpf");
   entry=leg->AddEntry("CompareLegacy2","Legacy, relaxing isolation at 63GeV","lpf");

   leg->Draw();



}
