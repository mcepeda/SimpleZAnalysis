#include "TH1.h" 
#include "TTree.h"
#include "TFile.h"
#include "TCanvas.h"
#include "tdrstyle.C"

void reemulECALTP()
{
        setTDRStyle();

TFile* file=new TFile("test.root");

//TTree* tupleDefault=(TTree*)file->Get("defaultECAL/Ntuple");  tupleDefault->SetName("tupleDefault");
//TTree* tupleReemulated=(TTree*)file->Get("reemulatedECAL/Ntuple"); tupleReemulated->SetName("tupleReemulated");


TTree* tupleDefault=(TTree*)file->Get("matchedECAL/Ntuple");  tupleDefault->SetName("tupleDefault");
TTree* tupleReemulated=(TTree*)file->Get("notmatchedECAL/Ntuple"); tupleReemulated->SetName("tupleReemulated");



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
   entry0=legele->AddEntry(histoReemulEcal,"Reemulated","lpf");
   entry0=legele->AddEntry(histoDefaultEcal,"Default","lpf");
   legele->Draw();

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
tupleDefault->Draw("ietaTP>>htemp(81,-40,40)","rankTP>20","sames,pE");
histoEtaDefaultEcal=(TH1F*)gPad->GetPrimitive("htemp");
histoEtaDefaultEcal->SetName("histoEtaDefaultEcal");
histoEtaDefaultEcal->SetLineColor(kBlue);
histoEtaDefaultEcal->SetMarkerColor(kBlue);
histoEtaDefaultEcal->SetMarkerStyle(20);


}
