#include "TH1.h" 
#include "TTree.h"
#include "TFile.h"
#include "TCanvas.h"
#include "tdrstyle.C"

void plotRatesJetsPU(int version=0)
{
        setTDRStyle();


TFile*   file1=new TFile("newroots/RATEALLNEW-run254790.root");
TFile*   file2=new TFile("newroots/RATEALLNEWNEWPU.root");
TFile*   file3=new TFile("newroots/RATEALLNEWNOPU.root");


TString DIR1="allJetRate/Ntuple"; 
TString DIR2="allJetRate/Ntuple";
TString DIR3="allJetRate/Ntuple";

TString Legend1="Stage1, allJet (RCT+V1), MC PU";
TString Legend2="Stage1, allJet (RCT+V1), DataDriven PU";
TString Legend3="Stage1, allJet (RCT+V1), NO PU CORRECTION";

TTree* tupleUNO=(TTree*)file1->Get(DIR1);  tupleUNO->SetName("tupleUNO");
TTree* tupleDOS=(TTree*)file2->Get(DIR2); tupleDOS->SetName("tupleDOS");
TTree* tupleTRES=(TTree*)file3->Get(DIR3); tupleTRES->SetName("tupleTRES");

TCanvas *Jets=new TCanvas("Jets","",0,44,1253,600);
TH1F* histoTRESPtJets, *histoTRESEtaJets,*histoPtJets,*histoEtaJets, * histoDOSPtJets, *histoDOSEtaJets;
Jets->Divide(2,1);
Jets->cd(1);
Jets->cd(1)->SetLogy();
tupleDOS->Draw("pt[0]>>htemp(255,0,255)","pt[0]!=100&&fabs(eta[0])>0","pE");
histoDOSPtJets=(TH1F*)gPad->GetPrimitive("htemp");
histoDOSPtJets->SetName("histoDOSPtJets");
histoDOSPtJets->SetMarkerColor(kGreen+1);
histoDOSPtJets->SetMarkerStyle(23);
histoDOSPtJets->SetLineColor(kGreen+1);
histoDOSPtJets->SetXTitle("Jet p_{T}");
histoDOSPtJets->SetTitle("");
Jets->cd(2);
//Jets->cd(2)->SetLogy();
tupleDOS->Draw("eta[0]>>htemp","pt[0]>36","pE");
histoDOSEtaJets=(TH1F*)gPad->GetPrimitive("htemp");
histoDOSEtaJets->SetName("histoDOSEtaJets");
histoDOSEtaJets->SetMarkerColor(kGreen+1);
histoDOSEtaJets->SetMarkerStyle(23);
histoDOSEtaJets->SetLineColor(kGreen+1);
histoDOSEtaJets->SetXTitle("Jet #eta");
histoDOSEtaJets->SetTitle("");
   TPaveText *pt = new TPaveText(-3.,1400,3.,1600,"br");
   TText *AText = pt->AddText("Jet pt>36GeV");
   pt->SetFillColor(0);
   pt->SetBorderSize(0);
   pt->Draw();

Jets->cd(1);
tupleUNO->Draw("pt[0]>>htemp(255,0,255)","pt[0]!=100&&fabs(eta[0])>0","sames,pE");
histoPtJets=(TH1F*)gPad->GetPrimitive("htemp");
histoPtJets->SetName("histoPtJets");
histoPtJets->SetLineColor(kRed);
histoPtJets->SetMarkerColor(kRed);
histoPtJets->SetMarkerStyle(22);
Jets->cd(2);
tupleUNO->Draw("eta[0]>>htemp(200,-5.36,5.36)","pt[0]>36","sames,pE");
histoEtaJets=(TH1F*)gPad->GetPrimitive("htemp");
histoEtaJets->SetName("histoEtaJets");
histoEtaJets->SetMarkerColor(kRed);
histoEtaJets->SetMarkerStyle(22);
histoEtaJets->SetLineColor(kRed);
Jets->cd(1);
tupleTRES->Draw("pt[0]>>htemp(255,0,255)","pt[0]!=100&&fabs(eta[0])>0","sames,pE");
histoTRESPtJets=(TH1F*)gPad->GetPrimitive("htemp");
histoTRESPtJets->SetName("histoTRESPtJets");
histoTRESPtJets->SetLineColor(kBlue);
histoTRESPtJets->SetMarkerColor(kBlue);
histoTRESPtJets->SetMarkerStyle(20);
   TLegend *legele = new TLegend(0.3,0.65,0.95,0.9,NULL,"brNDC");
   legele->SetFillColor(0);
   legele->SetTextFont(62);
   TLegendEntry *entry0;
   entry0=legele->AddEntry(histoPtJets,Legend1,"lpf");
   entry0=legele->AddEntry(histoDOSPtJets,Legend2,"lpf");
   entry0=legele->AddEntry(histoTRESPtJets,Legend3,"lpf");
   legele->Draw();
Jets->cd(2);
tupleTRES->Draw("eta[0]>>htemp(200,-5.36,5.36)","pt[0]>36","sames,pE");
histoTRESEtaJets=(TH1F*)gPad->GetPrimitive("htemp");
histoTRESEtaJets->SetName("histoTRESEtaJets");
histoTRESEtaJets->SetMarkerColor(kBlue);
histoTRESEtaJets->SetMarkerStyle(20);
histoTRESEtaJets->SetLineColor(kRed);

histoDOSEtaJets->GetYaxis()->SetRangeUser(0,2000);
histoDOSPtJets->GetYaxis()->SetRangeUser(1,20000);


Jets->SaveAs("pt_Jets.png");




TCanvas *CanvasRateJets=new TCanvas("CanvasRateJets");
   CanvasRateJets->Range(-36.0515,-0.5334107,219.7425,4.887184);
   CanvasRateJets->SetLeftMargin(0.15);
   CanvasRateJets->SetRightMargin(0.08);
   CanvasRateJets->SetTopMargin(0.08);
   CanvasRateJets->SetBottomMargin(0.14);
TH1F *RateEG=(TH1F*)histoPtJets->Clone(); RateEG->SetName("RateEG");
TH1F *RateDOS=(TH1F*)histoDOSPtJets->Clone(); RateDOS->SetName("RateDOS");
TH1F *RateTRES=(TH1F*)histoTRESPtJets->Clone(); RateTRES->SetName("RateTRES");

for(int i=0; i<RateEG->GetNbinsX();i++){
	double integral=0, error=0;
	integral=RateEG->IntegralAndError(i,-1,error);
	RateEG->SetBinContent(i,integral);
        RateEG->SetBinError(i,error);
        integral=RateDOS->IntegralAndError(i,-1,error);
        RateDOS->SetBinContent(i,integral);
        RateDOS->SetBinError(i,error);
        integral=RateTRES->IntegralAndError(i,-1,error);
        RateTRES->SetBinContent(i,integral);
        RateTRES->SetBinError(i,error);

}
RateEG->SetTitle("");
RateEG->GetXaxis()->SetRangeUser(12,255);
RateEG->SetMinimum(0.7);
RateEG->SetLineWidth(1);
RateDOS->SetLineWidth(1);
RateEG->GetYaxis()->SetTitleOffset(1.2);
CanvasRateJets->SetLogy();
RateEG->SetXTitle("Jet Threshold [GeV]");
RateEG->SetYTitle("Events (this is not a rate!)");
RateEG->Draw("E,");
RateDOS->Draw("E,sames");
RateTRES->Draw("E,sames");

legele->Draw();
CanvasRateJets->SetGrid();
CanvasRateJets->SaveAs("RateJets.png");

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
