#include "TH1.h" 
#include "TTree.h"
#include "TFile.h"
#include "TCanvas.h"
#include "tdrstyle.C"

void plotRates(int version=2)
{
        setTDRStyle();

//TFile* fileStage1=new TFile("roots/stage1notransrate.root","READONLY");
//TFile* fileStage1=new TFile("roots/rateStage1LauraV2.root","READONLY");
//TFile* fileStage1=new TFile("roots/stage1rate.root","READONLY");
//TFile* fileStage1=new TFile("roots/cleanecal_notransp_numEvent30000.root");

//TFile* fileStage1=new TFile("roots/rateStage1NOREEMUL.root");
//TFile* fileStage1=new TFile("roots/RateStage1WITHTP-onlyrateV3.root");
//TFile* fileStage1=new TFile("roots/RateStage1WITHTPNOTRANS-onlyrateV3_NOTRANSP.root");
//TFile*   fileStage1=new TFile("roots/RateStage1OnlyMatched.root");

TFile*   fileStage1=new TFile("rate833.root");

TString DIR1="electronRateUnpacked/Ntuple"; 
TString DIR2="electronRateGCTUnpacked/Ntuple";
TString Legend1="Stage1, SingleEG";
TString Legend2="Legacy, SingleEG";

if(version==1){
DIR1="electronIsoRateUnpacked/Ntuple";
DIR2="electronIsoRateGCTUnpacked/Ntuple";
Legend1="Stage1, SingleIsoEG";
Legend2="Legacy, SingleIsoEG";
}

if(version==2){
DIR1="electronRate/Ntuple";
DIR2="electronRateUnpacked/Ntuple";
Legend2="Stage1 UNPACKED, SingleEG";
Legend1="Stage1 EMULATED, SingleEG";
}


if(version==3){
DIR1="electronIsoRate/Ntuple";
DIR2="electronIsoRateUnpacked/Ntuple";
Legend1="Stage1 UNPACKED, SingleIsoEG";
Legend2="Stage1 EMULATED, SingleIsoEG";
}

if(version==4){
DIR1="electronRateUnpacked/Ntuple";
DIR2="electronIsoRateUnpacked/Ntuple";
Legend1="Stage1, SingleEG";
Legend2="Stage1, SingleIsoEG";
}



TTree* tupleUNO=(TTree*)fileStage1->Get(DIR1);  tupleUNO->SetName("tupleUNO");
TTree* tupleDOS=(TTree*)fileStage1->Get(DIR2); tupleDOS->SetName("tupleDOS");

TCanvas *Electrons=new TCanvas("Electrons","",0,44,1253,600);
TH1F* histoDOSPtElectrons, *histoDOSEtaElectrons,*histoPtElectrons,*histoEtaElectrons;
Electrons->Divide(2,1);
Electrons->cd(1);
Electrons->cd(1)->SetLogy();
tupleDOS->Draw("pt[0]>>htemp(100,0,100)","pt[0]!=100&&fabs(eta[0])>0","pE");
histoDOSPtElectrons=(TH1F*)gPad->GetPrimitive("htemp");
histoDOSPtElectrons->SetName("histoDOSPtElectrons");
histoDOSPtElectrons->SetMarkerColor(kGreen+1);
histoDOSPtElectrons->SetMarkerStyle(23);
histoDOSPtElectrons->SetLineColor(kGreen+1);
histoDOSPtElectrons->SetXTitle("Electron p_{T}");
histoDOSPtElectrons->SetTitle("");
Electrons->cd(2);
//Electrons->cd(2)->SetLogy();
tupleDOS->Draw("eta[0]>>htemp","pt[0]>20","pE");
histoDOSEtaElectrons=(TH1F*)gPad->GetPrimitive("htemp");
histoDOSEtaElectrons->SetName("histoDOSEtaElectrons");
histoDOSEtaElectrons->SetMarkerColor(kGreen+1);
histoDOSEtaElectrons->SetMarkerStyle(23);
histoDOSEtaElectrons->SetLineColor(kGreen+1);
histoDOSEtaElectrons->SetXTitle("Electron #eta");
histoDOSEtaElectrons->SetTitle("");
Electrons->cd(1);
tupleUNO->Draw("pt[0]>>htemp(100,0,100)","pt[0]!=100&&fabs(eta[0])>0","sames,pE");
histoPtElectrons=(TH1F*)gPad->GetPrimitive("htemp");
histoPtElectrons->SetName("histoPtElectrons");
histoPtElectrons->SetLineColor(kRed);
histoPtElectrons->SetMarkerColor(kRed);
histoPtElectrons->SetMarkerStyle(22);
   TLegend *legele = new TLegend(0.5,0.7,0.95,0.9,NULL,"brNDC");
   legele->SetFillColor(0);
   legele->SetTextFont(62);
   TLegendEntry *entry0=legele->AddEntry(histoDOSPtElectrons,Legend2,"lpf");
   entry0=legele->AddEntry(histoPtElectrons,Legend1,"lpf");
   legele->Draw();
Electrons->cd(2);
tupleUNO->Draw("eta[0]>>htemp(200,-5.36,5.36)","pt[0]>20","sames,pE");
histoEtaElectrons=(TH1F*)gPad->GetPrimitive("htemp");
histoEtaElectrons->SetName("histoEtaElectrons");
histoEtaElectrons->SetMarkerColor(kRed);
histoEtaElectrons->SetMarkerStyle(22);
histoEtaElectrons->SetLineColor(kRed);
histoDOSEtaElectrons->SetMaximum(histoEtaElectrons->GetMaximum()*1.2);
Electrons->SaveAs("pt_Electrons.png");

TCanvas *CanvasRateElectrons=new TCanvas("CanvasRateElectrons");
   CanvasRateElectrons->Range(-36.0515,-0.5334107,219.7425,4.887184);
   CanvasRateElectrons->SetLeftMargin(0.15);
   CanvasRateElectrons->SetRightMargin(0.08);
   CanvasRateElectrons->SetTopMargin(0.08);
   CanvasRateElectrons->SetBottomMargin(0.14);
TH1F *RateEG=(TH1F*)histoPtElectrons->Clone(); RateEG->SetName("RateEG");
TH1F *RateDOSEG=(TH1F*)histoDOSPtElectrons->Clone(); RateDOSEG->SetName("RateDOSEG");

for(int i=0; i<RateEG->GetNbinsX();i++){
	double integral=0, error=0;
	integral=RateEG->IntegralAndError(i,-1,error);
	RateEG->SetBinContent(i,integral);
        RateEG->SetBinError(i,error);
        integral=RateDOSEG->IntegralAndError(i,-1,error);
        RateDOSEG->SetBinContent(i,integral);
        RateDOSEG->SetBinError(i,error);
}
RateEG->SetTitle("");
RateEG->GetXaxis()->SetRangeUser(12,65);
RateEG->SetMinimum(0.7);
RateEG->SetLineWidth(1);
RateDOSEG->SetLineWidth(1);
RateEG->GetYaxis()->SetTitleOffset(1.2);
CanvasRateElectrons->SetLogy();
RateEG->SetXTitle("Electron Threshold [GeV]");
RateEG->SetYTitle("Events (this is not a rate!)");
RateEG->Draw("E,");
RateDOSEG->Draw("E,sames");
legele->Draw();
CanvasRateElectrons->SetGrid();
CanvasRateElectrons->SaveAs("RateElectrons.png");

/*
TCanvas *TEST = new TCanvas ("TEST");
   TEST->Range(-36.0515,-0.5334107,219.7425,4.887184);
   TEST->SetLeftMargin(0.15);
   TEST->SetRightMargin(0.15);
   TEST->SetTopMargin(0.15);
   TEST->SetBottomMargin(0.15);
tupleUNO->Draw("phi[0]:eta[0]","pt[0]>=63","colz");
histo2D=(TH1F*)gPad->GetPrimitive("htemp"); histo2D->SetName("histo2D");
histo2D->GetYaxis()->SetTitleOffset(1.2);
TEST->SaveAs("2DPlot.png");
*/
}
