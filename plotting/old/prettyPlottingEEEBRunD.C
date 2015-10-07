#include "tdrstyle.C"
TFile *file833DEFSingleIsoEG, *file833DEFSingleEG;

double LUMI=25;

void plot(TString plot,TString xlabel, TString ylabel,double xlegmin=0.2, double xlegmax=0.4, double ylegmin=0.75, double ylegmax=0.85);
void cmsPrelim( double intLumi);
void effi(TString plot, TString xlabel, TString ylabel, double xlegmin=0.5, double xlegmax=0.7, double ylegmin=0.3, double ylegmax=0.5);

void prettyPlottingEEEBRunD(){

	setTDRStyle();

	file833DEFSingleEG=new TFile("outputs2/2015DDEFIsoEndcap.root","READONLY");
	file833DEFSingleIsoEG=new TFile("outputs2/2015DDEFIsoBarrel.root","READONLY");

        plot("histonvtx", "NVertices", "Events");
        plot("met_Et", "MET [GeV]", "Events / GeV");

	plot("massZ", "Mass DiElectron [GeV]", "Events / GeV");
        plot("massZL1", "Mass DiElectron [GeV]", "Events / GeV");
        plot("massZL1V2", "Mass DiElectron [GeV]", "Events / GeV");
        plot("recoPtSecond","Sublead Electron p_{t} [GeV]","Events / GeV");
        plot("recoPtLead","Lead Electron p_{t} [GeV]","Events / GeV");

        plot("ResLeadPt","(l1Pt-recoPt)/recoPt - lead Electron","Events");
        plot("ResSecondPtTrig15","(l1Pt-recoPt)/recoPt - sublead electron, 15GeV","Events");
        plot("ResSecondPtTrig20","(l1Pt-recoPt)/recoPt - sublead electron, 20GeV","Events");
        plot("ResSecondPtTrig25","(l1Pt-recoPt)/recoPt - sublead electron, 25GeV","Events");
        plot("ResSecondPtTrig30","(l1Pt-recoPt)/recoPt - sublead electron, 30GeV","Events");
        plot("ResSecondPtTrig35","(l1Pt-recoPt)/recoPt - sublead electron, 35GeV","Events");
        plot("ResSecondPtTrig2540","(l1Pt-recoPt)/recoPt - sublead electron, 20-40GeV","Events");

        plot("ResSecondPtTrig20EB","(l1Pt-recoPt)/recoPt - sublead electron, 20GeV, EB","Events");
        plot("ResSecondPtTrig20EE","(l1Pt-recoPt)/recoPt - sublead electron, 20GeV, EE","Events");

        plot("l1PtSecond","Sublead Electron p_{t} [GeV]","Events / GeV");
        plot("l1PtLead","Lead Electron p_{t} [GeV]","Events / GeV");

        plot("l1PtSecondEB","Sublead Electron p_{t} [GeV] - EB ONLY","Events / GeV");
        plot("l1PtLeadEB","Lead Electron p_{t} [GeV] - EB ONLY","Events / GeV");
        plot("l1PtSecondEE","Sublead Electron p_{t} [GeV] - EE ONLY","Events / GeV");
        plot("l1PtLeadEE","Lead Electron p_{t} [GeV] - EE ONLY","Events / GeV");
        plot("l1EtaSecond","Sublead Electron #eta","Events");
        plot("l1EtaLead","Lead Electron #eta","Events");
        plot("recoEtaSecond","Sublead Electron #eta","Events");
        plot("recoEtaLead","Lead Electron #eta","Events");

        plot("l1DRMatchLead","Lead Electron DR","Events",0.7,0.9);
        plot("l1DRMatchSecond","Sublead Electron DR","Events",0.7,0.9);


        plot("ResEtaSecondPtTrig35","(l1Eta-recoEta)- sublead electron","Events");
        plot("ResPhiSecondPtTrig35","(l1Phi-recoPhi)- sublead electron","Events");


   	    effi("effi15_PtSecond","Trigger Efficiency, SingleIso15","Events"); 
        effi("effi15_EtaSecond","Trigger Efficiency, SingleIso15","Events");

        effi("effi20_PtSecond","Trigger Efficiency, SingleIso20","Events");
        effi("effi20_EtaSecond","Trigger Efficiency, SingleIso20","Events");

        effi("effi25_PtSecond","Trigger Efficiency, SingleIso25","Events");
        effi("effi25_EtaSecond","Trigger Efficiency, SingleIso25","Events");
        effi("effi30_PtSecond","Trigger Efficiency, SingleIso30","Events");
        effi("effi30_EtaSecond","Trigger Efficiency, SingleIso30","Events");
        effi("effi35_PtSecond","Trigger Efficiency, SingleIso35","Events");
        effi("effi35_EtaSecond","Trigger Efficiency, SingleIso35","Events");


      effi("effi15_PtSecondEB","Trigger Efficiency, SingleEG15  (EB)","Events");
        effi("effi20_PtSecondEB","Trigger Efficiency, SingleEG20 (EB)","Events");
        effi("effi25_PtSecondEB","Trigger Efficiency, SingleEG25 (EB)","Events");
        effi("effi30_PtSecondEB","Trigger Efficiency, SingleEG30 (EB)","Events");
        effi("effi35_PtSecondEB","Trigger Efficiency, SingleEG35 (EB)","Events");


      effi("effi15_PtSecondEE","Trigger Efficiency, SingleEG15 (EE)","Events");
        effi("effi20_PtSecondEE","Trigger Efficiency, SingleEG20 (EE)","Events");
        effi("effi25_PtSecondEE","Trigger Efficiency, SingleEG25 (EE)","Events");
        effi("effi30_PtSecondEE","Trigger Efficiency, SingleEG30 (EE)","Events");
        effi("effi35_PtSecondEE","Trigger Efficiency, SingleEG35 (EE)","Events");

        effi("effi20_nvtxSecond","NVtx, SingleIsoEG20","Events");
        effi("effi20_nvtxSecondEB","Trigger Efficiency, SingleEG20 (EB)","Events");
        effi("effi20_nvtxSecondEE","Trigger Efficiency, SingleEG20 (EE)","Events");


}

void plot(TString plot, TString xlabel, TString ylabel, double xlegmin=0.2, double xlegmax=0.4, double ylegmin=0.75, double ylegmax=0.85){	
	TCanvas *c1 = new TCanvas("canvas_"+plot, "canvas_"+plot,0,44,600,600);
	gStyle->SetOptFit(1);
	gStyle->SetOptStat(0);
	c1->SetLeftMargin(0.15);
	c1->SetRightMargin(0.05);
	c1->SetTopMargin(0.10);
	c1->SetBottomMargin(0.11);
	c1->cd();

	TH1F *histo=(TH1F*)file833DEFSingleEG->Get(plot); histo->SetName("833DEFSingleIsoEG_"+plot);
	TH1F *histoIso=(TH1F*)file833DEFSingleIsoEG->Get(plot); histoIso->SetName("Stage1_"+plot);

	histo->Scale(1./histo->Integral());	
        histoIso->Scale(1./histoIso->Integral());

	histo->SetMarkerColor(kOrange);
        histo->SetLineColor(kOrange+4); 
	histo->SetMarkerStyle(21);
	histoIso->SetMarkerStyle(20);

	histo->Draw("hist");
	histoIso->Draw("sames,hist");
	histoIso->SetXTitle(xlabel);
	histoIso->SetYTitle(ylabel);
        histo->SetXTitle(xlabel);
        histo->SetYTitle(ylabel);

	histo->GetYaxis()->SetTitleOffset(1.4);
	histo->GetYaxis()->SetTitleSize(0.05);
	histo->GetXaxis()->SetTitleSize(0.05);

	if(histo->GetMaximum()<histoIso->GetMaximum()) histo->SetMaximum(histoIso->GetMaximum()*1.2);


      cout<<"Plotting "<<plot<<": data "<<histoIso->Integral()<<" vs mc "<<histo->Integral()<<" ("<<histoIso->Integral()/histo->Integral()<<")"<<endl;

	TLegend *leg = new TLegend(xlegmin,ylegmin,xlegmax,ylegmax,NULL,"brNDC");
	TLegendEntry *entry=leg->AddEntry(histo,"Endcap","l");
        entry=leg->AddEntry(histoIso,"Barrel","l");
//	TLegendEntry *entry=leg->AddEntry(histoIso,"SingleIsoEG","p");
//	entry=leg->AddEntry(histo,"SingleEG","lf");
	leg->Draw();
	cmsPrelim(LUMI);

	c1->SaveAs("plots/"+plot+".png");
}


void effi(TString plot, TString xlabel, TString ylabel, double xlegmin=0.5, double xlegmax=0.7, double ylegmin=0.3, double ylegmax=0.5){	
	TCanvas *c1 = new TCanvas("canvas_"+plot, "canvas_"+plot,0,44,600,600);
	gStyle->SetOptFit(1);
	gStyle->SetOptStat(0);
	c1->SetLeftMargin(0.15);
	c1->SetRightMargin(0.05);
	c1->SetTopMargin(0.10);
	c1->SetBottomMargin(0.11);
	c1->cd();

	TH1F *histo=(TH1F*)file833DEFSingleEG->Get(plot); histo->SetName("833DEFSingleIsoEG_"+plot);
	TH1F *histoIso=(TH1F*)file833DEFSingleIsoEG->Get(plot); histoIso->SetName("Stage1_"+plot);

	histo->SetLineColor(kOrange+2);  histoIso->SetMarkerStyle(25); histo->SetMarkerColor(kOrange+2); histo->SetLineWidth(2);
	histoIso->SetMarkerStyle(20); histoIso->SetLineColor(kBlack);  histoIso->SetLineWidth(2);

	histo->Draw("hist,E");
	histoIso->Draw("sames,p,E");
	histo->SetXTitle(xlabel);
	histo->SetYTitle(ylabel);

	histo->GetYaxis()->SetTitleOffset(1.4);
	histo->GetYaxis()->SetTitleSize(0.05);
	histo->GetXaxis()->SetTitleSize(0.05);

	histo->GetYaxis()->SetRangeUser(0,1.1);

	TLegend *leg = new TLegend(xlegmin,ylegmin,xlegmax,ylegmax,NULL,"brNDC");
        TLegendEntry *entry=leg->AddEntry(histo,"Endcap","l");
        entry=leg->AddEntry(histoIso,"Barrel","l");
//	TLegendEntry *entry=leg->AddEntry(histoIso,"SingleIsoEG","p");
//	entry=leg->AddEntry(histo,"SingleEG","lf");
	leg->Draw();
	cmsPrelim(LUMI);

	c1->SaveAs("plots/"+plot+".png");
}





void cmsPrelim( double intLumi ){  TLatex latex;
	latex.SetNDC();
	latex.SetTextSize(0.04);

	latex.SetTextAlign(31); // align right
//	latex.DrawLatex(0.95,0.93,Form("%.1f pb^{-1}, #sqrt{s} = 13 TeV",intLumi));

	latex.SetTextAlign(11); // align left
	latex.DrawLatex(0.15,0.93,"Run2015D");
}

