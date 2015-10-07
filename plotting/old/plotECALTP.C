#include "TH1.h" 
#include "TTree.h"
#include "TFile.h"
#include "TCanvas.h"
#include "tdrstyle.C"

void plotECALTP()
{
        setTDRStyle();

TFile* fileTRANSP=new TFile("roots/RateStage1WITHTP-onlyrateV3.root");
TFile* fileNOTRANSP=new TFile("roots/RateStage1WITHTPNOTRANS-onlyrateV3_NOTRANSP.root");



TTree* tupleCorrected=(TTree*)fileTRANSP->Get("matchedECAL/Ntuple");  tupleCorrected->SetName("tupleCorrected");
TTree* tupleReemulated=(TTree*)fileNOTRANSP->Get("notmatchedECAL/Ntuple"); tupleReemulated->SetName("tupleReemulated");
//TTree* tupleCorrected=(TTree*)fileTRANSP->Get("reemulatedECAL/Ntuple");  tupleCorrected->SetName("tupleCorrected");
//TTree* tupleReemulated=(TTree*)fileNOTRANSP->Get("reemulatedECAL/Ntuple"); tupleReemulated->SetName("tupleReemulated");
TTree* tupleDefault=(TTree*)fileTRANSP->Get("defaultECAL/Ntuple");  tupleDefault->SetName("tupleDefault");


TCanvas *Spike=new TCanvas("Spike","",0,44,600,600);
Spike->SetLogy();
TH1F* histoReemulSpike, *histoCorrectedSpike, *histoDefaultSpike;
tupleReemulated->Draw("spikeTP>>htemp(2,-0.5,1.5)","rankTP==255","pE");
histoReemulSpike=(TH1F*)gPad->GetPrimitive("htemp");
histoReemulSpike->SetName("histoReemulSpike");
histoReemulSpike->SetMarkerColor(kGreen+1);
histoReemulSpike->SetMarkerStyle(23);
histoReemulSpike->SetLineColor(kGreen+1);
histoReemulSpike->SetXTitle("ECAL TP Rank");
histoReemulSpike->SetTitle("");
tupleCorrected->Draw("spikeTP>>htemp(2,-0.5,1.5)","rankTP==255","sames,pE");
histoCorrectedSpike=(TH1F*)gPad->GetPrimitive("htemp");
histoCorrectedSpike->SetName("histoCorrectedSpike");
histoCorrectedSpike->SetLineColor(kRed);
histoCorrectedSpike->SetMarkerColor(kRed);
histoCorrectedSpike->SetMarkerStyle(22);
tupleDefault->Draw("spikeTP>>htemp(2,-0.5,1.5)","rankTP==255","sames,pE");
histoDefaultSpike=(TH1F*)gPad->GetPrimitive("htemp");
histoDefaultSpike->SetName("histoDefaultSpike");
histoDefaultSpike->SetLineColor(kBlue);
histoDefaultSpike->SetMarkerColor(kBlue);
histoDefaultSpike->SetMarkerStyle(20);

Spike->SaveAs("spike.png");


TCanvas *Ecal=new TCanvas("Ecal","",0,44,600,600);
Ecal->SetLogy();
TH1F* histoReemulEcal, *histoCorrectedEcal, *histoDefaultEcal;
tupleReemulated->Draw("rankTP>>htemp(300,0,300)","rankTP!=500","pE");
histoReemulEcal=(TH1F*)gPad->GetPrimitive("htemp");
histoReemulEcal->SetName("histoReemulEcal");
histoReemulEcal->SetMarkerColor(kGreen+1);
histoReemulEcal->SetMarkerStyle(23);
histoReemulEcal->SetLineColor(kGreen+1);
histoReemulEcal->SetXTitle("ECAL TP Rank");
histoReemulEcal->SetTitle("");
tupleCorrected->Draw("rankTP>>htemp(300,0,300)","rankTP!=500","sames,pE");
histoCorrectedEcal=(TH1F*)gPad->GetPrimitive("htemp");
histoCorrectedEcal->SetName("histoCorrectedEcal");
histoCorrectedEcal->SetLineColor(kRed);
histoCorrectedEcal->SetMarkerColor(kRed);
histoCorrectedEcal->SetMarkerStyle(22);
tupleDefault->Draw("rankTP>>htemp(300,0,300)","rankTP!=500","sames,pE");
histoDefaultEcal=(TH1F*)gPad->GetPrimitive("htemp");
histoDefaultEcal->SetName("histoDefaultEcal");
histoDefaultEcal->SetLineColor(kBlue);
histoDefaultEcal->SetMarkerColor(kBlue);
histoDefaultEcal->SetMarkerStyle(20);

   TLegend *legele = new TLegend(0.5,0.7,0.95,0.9,NULL,"brNDC");
   legele->SetFillColor(0);
   legele->SetTextFont(62);
   TLegendEntry *entry0;
   entry0=legele->AddEntry(histoCorrectedEcal,"Reemulated, Transparency Corrected","lpf");
   entry0=legele->AddEntry(histoReemulEcal,"Reemulated, Not Transparency Corrected","lpf");
   entry0=legele->AddEntry(histoDefaultEcal,"Default","lpf");
   legele->Draw();

Ecal->SaveAs("plotECALTP.png");
   
TCanvas *EcalEta=new TCanvas("EcalEta","",0,44,600,600);
TH1F* histoEtaReemulEcal, *histoEtaCorrectedEcal, *histoEtaDefaultEcal;
tupleReemulated->Draw("ietaTP>>htemp(81,-40,40)","rankTP>20","pE");
histoEtaReemulEcal=(TH1F*)gPad->GetPrimitive("htemp");
histoEtaReemulEcal->SetName("histoEtaReemulEcal");
histoEtaReemulEcal->SetMarkerColor(kGreen+1);
histoEtaReemulEcal->SetMarkerStyle(23);
histoEtaReemulEcal->SetLineColor(kGreen+1);
histoEtaReemulEcal->SetXTitle("ECAL TP iEta");
histoEtaReemulEcal->SetTitle("");
tupleCorrected->Draw("ietaTP>>htemp(81,-40,40)","rankTP>20","sames,pE");
histoEtaCorrectedEcal=(TH1F*)gPad->GetPrimitive("htemp");
histoEtaCorrectedEcal->SetName("histoEtaCorrectedEcal");
histoEtaCorrectedEcal->SetLineColor(kRed);
histoEtaCorrectedEcal->SetMarkerColor(kRed);
histoEtaCorrectedEcal->SetMarkerStyle(22);
tupleDefault->Draw("ietaTP>>htemp(81,-40,40)","rankTP>20","sames,pE");
histoEtaDefaultEcal=(TH1F*)gPad->GetPrimitive("htemp");
histoEtaDefaultEcal->SetName("histoEtaDefaultEcal");
histoEtaDefaultEcal->SetLineColor(kBlue);
histoEtaDefaultEcal->SetMarkerColor(kBlue);
histoEtaDefaultEcal->SetMarkerStyle(20);
   
if(histoEtaCorrectedEcal->GetMaximum()>histoEtaReemulEcal->GetMaximum())histoEtaReemulEcal->SetMaximum(histoEtaCorrectedEcal->GetMaximum()*1.2);

EcalEta->SaveAs("plotECALTPEta.png");

   
TCanvas *EcalPhi=new TCanvas("EcalPhi","",0,44,600,600);
TH1F* histoPhiReemulEcal, *histoPhiCorrectedEcal, *histoPhiDefaultEcal;
tupleReemulated->Draw("iphiTP>>htemp(72,0,71)","rankTP>20","pE");
histoPhiReemulEcal=(TH1F*)gPad->GetPrimitive("htemp");
histoPhiReemulEcal->SetName("histoPhiReemulEcal");
histoPhiReemulEcal->SetMarkerColor(kGreen+1);
histoPhiReemulEcal->SetMarkerStyle(23);
histoPhiReemulEcal->SetLineColor(kGreen+1);
histoPhiReemulEcal->SetXTitle("ECAL TP iPhi");
histoPhiReemulEcal->SetTitle("");
tupleCorrected->Draw("iphiTP>>htemp(72,0,71)","rankTP>20","sames,pE");
histoPhiCorrectedEcal=(TH1F*)gPad->GetPrimitive("htemp");
histoPhiCorrectedEcal->SetName("histoPhiCorrectedEcal");
histoPhiCorrectedEcal->SetLineColor(kRed);
histoPhiCorrectedEcal->SetMarkerColor(kRed);
histoPhiCorrectedEcal->SetMarkerStyle(22);
tupleDefault->Draw("iphiTP>>htemp(72,0,71)","rankTP>20","sames,pE");
histoPhiDefaultEcal=(TH1F*)gPad->GetPrimitive("htemp");
histoPhiDefaultEcal->SetName("histoPhiDefaultEcal");
histoPhiDefaultEcal->SetLineColor(kBlue);
histoPhiDefaultEcal->SetMarkerColor(kBlue);
histoPhiDefaultEcal->SetMarkerStyle(20);
   
if(histoPhiCorrectedEcal->GetMaximum()>histoPhiReemulEcal->GetMaximum())histoPhiReemulEcal->SetMaximum(histoPhiCorrectedEcal->GetMaximum()*1.2);

EcalPhi->SaveAs("plotECALTPPhi.png");


TCanvas *CanvasRateReemulTPs=new TCanvas("CanvasRateReemulTPs");
   CanvasRateReemulTPs->Range(-36.0515,-0.5334107,219.7425,4.887184);
   CanvasRateReemulTPs->SetLeftMargin(0.15);
   CanvasRateReemulTPs->SetRightMargin(0.08);
   CanvasRateReemulTPs->SetTopMargin(0.08);
   CanvasRateReemulTPs->SetBottomMargin(0.14);
TH1F *RateReemulTP=(TH1F*)histoReemulEcal->Clone(); RateReemulTP->SetName("RateReemulTP");
TH1F *RateCorrectedTP=(TH1F*)histoCorrectedEcal->Clone(); RateCorrectedTP->SetName("RateCorrectedTP");
TH1F *RateDefaultTP=(TH1F*)histoDefaultEcal->Clone(); RateDefaultTP->SetName("RateDefaultTP");

for(int i=0; i<RateReemulTP->GetNbinsX();i++){
        double integral=0, error=0;
        integral=RateReemulTP->IntegralAndError(i,-1,error);
        RateReemulTP->SetBinContent(i,integral);
        RateReemulTP->SetBinError(i,error);
        integral=RateCorrectedTP->IntegralAndError(i,-1,error);
        RateCorrectedTP->SetBinContent(i,integral);
        RateCorrectedTP->SetBinError(i,error);
        integral=RateDefaultTP->IntegralAndError(i,-1,error);
        RateDefaultTP->SetBinContent(i,integral);
        RateDefaultTP->SetBinError(i,error);
}
RateReemulTP->SetTitle("");
RateReemulTP->GetXaxis()->SetRangeUser(12,270);
RateReemulTP->SetLineWidth(1);
//RateReemulTP->SetMinimum(0.7);
RateCorrectedTP->SetLineWidth(1);
RateReemulTP->GetYaxis()->SetTitleOffset(1.2);
CanvasRateReemulTPs->SetLogy();
RateReemulTP->SetXTitle("Ecal TP Threshold [RANK]");
RateReemulTP->SetYTitle("Events (this is not a rate!)");
RateReemulTP->Draw("E,");
RateCorrectedTP->Draw("E,sames");
RateDefaultTP->Draw("E,sames");
legele->Draw();
CanvasRateReemulTPs->SetGrid();
CanvasRateReemulTPs->SaveAs("RateEcalTP.png");


TCanvas *TESTCorrected = new TCanvas ("TESTCorrected");
   TESTCorrected->Range(-36.0515,-0.5334107,219.7425,4.887184);
   TESTCorrected->SetLeftMargin(0.15);
   TESTCorrected->SetRightMargin(0.15);
   TESTCorrected->SetTopMargin(0.15);
   TESTCorrected->SetBottomMargin(0.15);
tupleCorrected->Draw("rankTP:spikeTP","rankTP>=200","colz");
histo2DCor=(TH1F*)gPad->GetPrimitive("htemp"); histo2DCor->SetName("histo2DCor");
histo2DCor->GetYaxis()->SetTitleOffset(1.2);
TESTCorrected->SaveAs("2DPlot_Corrected.png");

TCanvas *TESTDefault = new TCanvas ("TESTDefault");
   TESTDefault->Range(-36.0515,-0.5334107,219.7425,4.887184);
   TESTDefault->SetLeftMargin(0.15);
   TESTDefault->SetRightMargin(0.15);
   TESTDefault->SetTopMargin(0.15);
   TESTDefault->SetBottomMargin(0.15);
tupleDefault->Draw("rankTP:spikeTP","rankTP>=200","colz");
histo2DDef=(TH1F*)gPad->GetPrimitive("htemp"); histo2DDef->SetName("histo2DDef");
histo2DDef->GetYaxis()->SetTitleOffset(1.2);
TESTDefault->SaveAs("2DPlot_Default.png");


TCanvas *TESTReemulated = new TCanvas ("TESTDefault");
   TESTReemulated->Range(-36.0515,-0.5334107,219.7425,4.887184);
   TESTReemulated->SetLeftMargin(0.15);
   TESTReemulated->SetRightMargin(0.15);
   TESTReemulated->SetTopMargin(0.15);
   TESTReemulated->SetBottomMargin(0.15);
tupleReemulated->Draw("rankTP:spikeTP","rankTP>=200","colz");
histo2DReem=(TH1F*)gPad->GetPrimitive("htemp"); histo2DReem->SetName("histo2DReem");
histo2DReem->GetYaxis()->SetTitleOffset(1.2);
TESTReemulated->SaveAs("2DPlot_Reemulated.png");


}
