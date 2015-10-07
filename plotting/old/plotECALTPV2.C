#include "TH1.h" 
#include "TTree.h"
#include "TFile.h"
#include "TCanvas.h"
#include "tdrstyle.C"

void plotECALTPV2()
{
        setTDRStyle();

TFile* fileTRANSP=new TFile("test_numEvent500000.root");

TTree* tupleMatched=(TTree*)fileTRANSP->Get("matchedECAL/Ntuple");  tupleMatched->SetName("tupleMatched");
TTree* tuplenotmatched=(TTree*)fileTRANSP->Get("notmatchedECAL/Ntuple"); tuplenotmatched->SetName("tuplenotmatched");
TTree* tupleDefault=(TTree*)fileTRANSP->Get("defaultECAL/Ntuple");  tupleDefault->SetName("tupleDefault");
TTree* tuplereemulated=(TTree*)fileTRANSP->Get("reemulatedECAL/Ntuple");  tuplereemulated->SetName("tuplereemulated");


TCanvas *Ecal=new TCanvas("Ecal","",0,44,600,600);
Ecal->SetLogy();
TH1F* histoReemulEcal, *histoMatchedEcal, *histoDefaultEcal;
tuplenotmatched->Draw("rankTP>>htemp(300,0,300)","rankTP<200","pE");
histoReemulEcal=(TH1F*)gPad->GetPrimitive("htemp");
histoReemulEcal->SetName("histoReemulEcal");
histoReemulEcal->SetMarkerColor(kBlack);
histoReemulEcal->SetMarkerStyle(23);
histoReemulEcal->SetLineColor(kBlack);
histoReemulEcal->SetXTitle("ECAL TP Rank");
histoReemulEcal->SetTitle("");
tupleMatched->Draw("rankTP>>htemp(300,0,300)","rankTP<200","sames,pE");
histoMatchedEcal=(TH1F*)gPad->GetPrimitive("htemp");
histoMatchedEcal->SetName("histoMatchedEcal");
histoMatchedEcal->SetLineColor(kMagenta);
histoMatchedEcal->SetMarkerColor(kMagenta);
histoMatchedEcal->SetMarkerStyle(22);
tupleDefault->Draw("rankTP>>htemp(300,0,300)","rankTP<200","sames,pE");
histoDefaultEcal=(TH1F*)gPad->GetPrimitive("htemp");
histoDefaultEcal->SetName("histoDefaultEcal");
histoDefaultEcal->SetLineColor(kBlue);
histoDefaultEcal->SetMarkerColor(kBlue);
histoDefaultEcal->SetMarkerStyle(20);
histoReemulEcal->Draw("sames");
histoReemulEcal->GetYaxis()->SetRangeUser(0.7,histoMatchedEcal->GetMaximum()*1.5);
tuplereemulated->Draw("rankTP>>htemp(300,0,300)","rankTP<200","sames,pE");
historeemulatedEcal=(TH1F*)gPad->GetPrimitive("htemp");
historeemulatedEcal->SetName("historeemulatedEcal");
historeemulatedEcal->SetLineColor(kGreen);
historeemulatedEcal->SetMarkerColor(kGreen);
historeemulatedEcal->SetMarkerStyle(21);


   TLegend *legele = new TLegend(0.3,0.7,0.95,0.9,NULL,"brNDC");
   legele->SetFillColor(0);
   legele->SetTextFont(62);
   TLegendEntry *entry0;
   entry0=legele->AddEntry(histoMatchedEcal,"Reemulated, MATCHED","lpf");
   entry0=legele->AddEntry(histoReemulEcal,"Reemulated, NOT MATCHED","lpf");
   entry0=legele->AddEntry(historeemulatedEcal,"Reemulated","lpf");
   entry0=legele->AddEntry(histoDefaultEcal,"Unpacked","lpf");
   legele->Draw();

Ecal->SaveAs("plotECALTP.png");
   
TCanvas *EcalEta=new TCanvas("EcalEta","",0,44,600,600);
TH1F* histoEtaReemulEcal, *histoEtaMatchedEcal, *histoEtaDefaultEcal;
tuplenotmatched->Draw("ietaTP>>htemp(81,-40,40)","rankTP>100&&rankTP<200","pE");
histoEtaReemulEcal=(TH1F*)gPad->GetPrimitive("htemp");
histoEtaReemulEcal->SetName("histoEtaReemulEcal");
histoEtaReemulEcal->SetMarkerColor(kBlack);
histoEtaReemulEcal->SetMarkerStyle(23);
histoEtaReemulEcal->SetLineColor(kBlack);
histoEtaReemulEcal->SetXTitle("ECAL TP iEta");
histoEtaReemulEcal->SetTitle("");
tupleMatched->Draw("ietaTP>>htemp(81,-40,40)","rankTP>100&&rankTP<200","sames,pE");
histoEtaMatchedEcal=(TH1F*)gPad->GetPrimitive("htemp");
histoEtaMatchedEcal->SetName("histoEtaMatchedEcal");
histoEtaMatchedEcal->SetLineColor(kMagenta);
histoEtaMatchedEcal->SetMarkerColor(kMagenta);
histoEtaMatchedEcal->SetMarkerStyle(22);
tupleDefault->Draw("ietaTP>>htemp(81,-40,40)","rankTP>100&&rankTP<200","sames,pE");
histoEtaDefaultEcal=(TH1F*)gPad->GetPrimitive("htemp");
histoEtaDefaultEcal->SetName("histoEtaDefaultEcal");
histoEtaDefaultEcal->SetLineColor(kBlue);
histoEtaDefaultEcal->SetMarkerColor(kBlue);
histoEtaDefaultEcal->SetMarkerStyle(20);
histoEtaReemulEcal->Draw("sames");
   
if(histoEtaMatchedEcal->GetMaximum()>histoEtaReemulEcal->GetMaximum())histoEtaReemulEcal->SetMaximum(histoEtaMatchedEcal->GetMaximum()*1.2);

EcalEta->SaveAs("plotECALTPEta.png");

   
TCanvas *EcalPhi=new TCanvas("EcalPhi","",0,44,600,600);
TH1F* histoPhiReemulEcal, *histoPhiMatchedEcal, *histoPhiDefaultEcal;
tuplenotmatched->Draw("iphiTP>>htemp(72,0,71)","rankTP>100&&rankTP<200","pE");
histoPhiReemulEcal=(TH1F*)gPad->GetPrimitive("htemp");
histoPhiReemulEcal->SetName("histoPhiReemulEcal");
histoPhiReemulEcal->SetMarkerColor(kBlack);
histoPhiReemulEcal->SetMarkerStyle(23);
histoPhiReemulEcal->SetLineColor(kBlack);
histoPhiReemulEcal->SetXTitle("ECAL TP iPhi");
histoPhiReemulEcal->SetTitle("");
tupleMatched->Draw("iphiTP>>htemp(72,0,71)","rankTP>100&&rankTP<200","sames,pE");
histoPhiMatchedEcal=(TH1F*)gPad->GetPrimitive("htemp");
histoPhiMatchedEcal->SetName("histoPhiMatchedEcal");
histoPhiMatchedEcal->SetLineColor(kMagenta);
histoPhiMatchedEcal->SetMarkerColor(kMagenta);
histoPhiMatchedEcal->SetMarkerStyle(22);
tupleDefault->Draw("iphiTP>>htemp(72,0,71)","rankTP>100&&rankTP<200","sames,pE");
histoPhiDefaultEcal=(TH1F*)gPad->GetPrimitive("htemp");
histoPhiDefaultEcal->SetName("histoPhiDefaultEcal");
histoPhiDefaultEcal->SetLineColor(kBlue);
histoPhiDefaultEcal->SetMarkerColor(kBlue);
histoPhiDefaultEcal->SetMarkerStyle(20);
   
if(histoPhiMatchedEcal->GetMaximum()>histoPhiReemulEcal->GetMaximum())histoPhiReemulEcal->SetMaximum(histoPhiMatchedEcal->GetMaximum()*1.2);

EcalPhi->SaveAs("plotECALTPPhi.png");


TCanvas *CanvasRateReemulTPs=new TCanvas("CanvasRateReemulTPs");
   CanvasRateReemulTPs->Range(-36.0515,-0.5334107,219.7425,4.887184);
   CanvasRateReemulTPs->SetLeftMargin(0.15);
   CanvasRateReemulTPs->SetRightMargin(0.08);
   CanvasRateReemulTPs->SetTopMargin(0.08);
   CanvasRateReemulTPs->SetBottomMargin(0.14);
TH1F *RateReemulTP=(TH1F*)histoReemulEcal->Clone(); RateReemulTP->SetName("RateReemulTP");
TH1F *RateMatchedTP=(TH1F*)histoMatchedEcal->Clone(); RateMatchedTP->SetName("RateMatchedTP");
TH1F *RateDefaultTP=(TH1F*)histoDefaultEcal->Clone(); RateDefaultTP->SetName("RateDefaultTP");
TH1F *RatereemulatedTP=(TH1F*)historeemulatedEcal->Clone(); RatereemulatedTP->SetName("RatereemulatedTP");

for(int i=0; i<RateReemulTP->GetNbinsX();i++){
        double integral=0, error=0;
        integral=RateReemulTP->IntegralAndError(i,-1,error);
        RateReemulTP->SetBinContent(i,integral);
        RateReemulTP->SetBinError(i,error);
        integral=RateMatchedTP->IntegralAndError(i,-1,error);
        RateMatchedTP->SetBinContent(i,integral);
        RateMatchedTP->SetBinError(i,error);
        integral=RateDefaultTP->IntegralAndError(i,-1,error);
        RateDefaultTP->SetBinContent(i,integral);
        RateDefaultTP->SetBinError(i,error);
        integral=RatereemulatedTP->IntegralAndError(i,-1,error);
        RatereemulatedTP->SetBinContent(i,integral);
        RatereemulatedTP->SetBinError(i,error);
}
RateReemulTP->SetTitle("");
RateReemulTP->GetXaxis()->SetRangeUser(12,270);
RateReemulTP->GetXaxis()->SetRangeUser(0.7,1e5);
RateReemulTP->SetLineWidth(1);
//RateReemulTP->SetMinimum(0.7);
RateMatchedTP->SetLineWidth(1);
RateReemulTP->GetYaxis()->SetTitleOffset(1.2);
CanvasRateReemulTPs->SetLogy();
RateReemulTP->SetXTitle("Ecal TP Threshold [RANK]");
RateReemulTP->SetYTitle("Events (this is not a rate!)");
RateReemulTP->Draw("E,");
RateMatchedTP->Draw("E,sames");
RateDefaultTP->Draw("E,sames");
RatereemulatedTP->Draw("E,sames");
legele->Draw();
CanvasRateReemulTPs->SetGrid();
CanvasRateReemulTPs->SaveAs("RateEcalTP.png");

TCanvas *TESTMatched = new TCanvas ("TESTMatched");
   TESTMatched->Range(-36.0515,-0.5334107,219.7425,4.887184);
   TESTMatched->SetLeftMargin(0.15);
   TESTMatched->SetRightMargin(0.15);
   TESTMatched->SetTopMargin(0.15);
   TESTMatched->SetBottomMargin(0.15);
tupleMatched->Draw("iphiTP:ietaTP","rankTP>50","colz");
histo2DCor=(TH1F*)gPad->GetPrimitive("htemp"); histo2DCor->SetName("histo2DCor");
histo2DCor->GetYaxis()->SetTitleOffset(1.2);
TESTMatched->SaveAs("2DPlot_Matched.png");

TCanvas *TESTDefault = new TCanvas ("TESTDefault");
   TESTDefault->Range(-36.0515,-0.5334107,219.7425,4.887184);
   TESTDefault->SetLeftMargin(0.15);
   TESTDefault->SetRightMargin(0.15);
   TESTDefault->SetTopMargin(0.15);
   TESTDefault->SetBottomMargin(0.15);
tupleDefault->Draw("iphiTP:ietaTP","rankTP>50","colz");
histo2DDef=(TH1F*)gPad->GetPrimitive("htemp"); histo2DDef->SetName("histo2DDef");
histo2DDef->GetYaxis()->SetTitleOffset(1.2);
TESTDefault->SaveAs("2DPlot_Default.png");


TCanvas *TESTnotmatched = new TCanvas ("TESTNotMatched");
   TESTnotmatched->Range(-36.0515,-0.5334107,219.7425,4.887184);
   TESTnotmatched->SetLeftMargin(0.15);
   TESTnotmatched->SetRightMargin(0.15);
   TESTnotmatched->SetTopMargin(0.15);
   TESTnotmatched->SetBottomMargin(0.15);
tuplenotmatched->Draw("iphiTP:ietaTP","rankTP>50","colz");
histo2DReem=(TH1F*)gPad->GetPrimitive("htemp"); histo2DReem->SetName("histo2DReem");
histo2DReem->GetYaxis()->SetTitleOffset(1.2);
TESTnotmatched->SaveAs("2DPlot_notmatched.png");


}
