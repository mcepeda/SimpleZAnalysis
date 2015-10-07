#include "tdrstyle.C"
TFile *fileStage1DEF, *fileGCTDEF,*fileStage1ReRun;

double LUMI=25;

void plot(TString plot,TString xlabel, TString ylabel,double xlegmin=0.2, double xlegmax=0.4, double ylegmin=0.75, double ylegmax=0.85);
void cmsPrelim( double intLumi);
void effi(TString plot, double threshold, TString xlabel, TString ylabel, double xlegmin=0.5, double xlegmax=0.7, double ylegmin=0.3, double ylegmax=0.5);
void res(TString plot, TString xlabel, TString ylabel, double xlegmin=0.5, double xlegmax=0.7, double ylegmin=0.3, double ylegmax=0.5);

void prettyPlottingJets(){

	setTDRStyle();

	fileGCTDEF=new TFile("outputs/DataGCT833GCTDEF.root","READONLY");
	fileStage1DEF=new TFile("outputs/DataStage1833DEF.root","READONLY");
        fileStage1ReRun=new TFile("outputs/DataStage1833.root","READONLY");

        plot("histomet","histomet","Events");
        plot("histomt","histomt","Events");

        plot("nJets","nJets","Events");
        plot("nJetsClean","nJetsClean","Events");
        plot("hLeadPtJet","Lead Jet Pt","Events");
        plot("hLeadEtaJet","Lead Jet #eta","Events");
        plot("hL1LeadMatchedPtJet","L1LeadMatched Jet Pt","Events");
        plot("hL1LeadMatchedEtaJet","L1LeadMatched Jet #eta","Events");
        plot("hL1LeadPtJet","L1Lead Jet Pt","Events");
        plot("hL1LeadEtaJet","L1Lead Jet #eta","Events");
        plot("hL1LeadMatchedDR","L1LeadMatched DR","Events");

        plot("hResLeadPtJet","Lead Jet Pt","Events");
	res("hResLeadPtJet2DEta","Reco #eta","(l1pt-recopt)/recopt",0.3,0.7,0.2,0.4);
        res("hResLeadPtJet2D","Reco jet Pt","(l1pt-recopt)/recopt",0.3,0.7,0.2,0.4);
        res("hResLeadPtJet2DL1","L1 jet Pt","(l1pt-recopt)/recopt",0.3,0.7,0.2,0.4);

        effi("effi_PtLead_Jet50",50,"Trigger Efficiency, SingleJet50","Events",0.5,0.95,0.2,0.5);
        effi("effi_PtLead_Jet150",150,"Trigger Efficiency, SingleJet150","Events",0.2,0.4,0.95,0.7);
        effi("effi_PtLead_Jet70",70,"Trigger Efficiency, SingleJet70","Events",0.5,0.95,0.2,0.5);
        effi("effi_PtLead_Jet100",100,"Trigger Efficiency, SingleJet100","Events",0.6,0.99,0.2,0.5);

        effi("effi_PtAll_Jet70",70,"Trigger Efficiency, SingleJet70","Events",0.5,0.95,0.2,0.5);


/*
        plot("histonvtx", "NVertices", "Events");
        plot("met_Et", "MET [GeV]", "Events / GeV");

	plot("massZ", "Mass DiElectron [GeV]", "Events / GeV");
//      plot("massZL1", "Mass DiElectron [GeV]", "Events / GeV");
//      plot("massZL1V2", "Mass DiElectron [GeV]", "Events / GeV");
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

        plot("l1DRMatchLead","Lead Electron DR","Events");
        plot("l1DRMatchSecond","Sublead Electron DR","Events");


        plot("ResEtaSecondPtTrig35","(l1Eta-recoEta)- sublead electron","Events");
        plot("ResPhiSecondPtTrig35","(l1Phi-recoPhi)- sublead electron","Events");


   	    effi("effi15_PtSecond","Trigger Efficiency, SingleEG15","Events"); 
        effi("effi15_EtaSecond","Trigger Efficiency, SingleEG15","Events");

        effi("effi20_PtSecond","Trigger Efficiency, SingleEG20","Events");
        effi("effi20_EtaSecond","Trigger Efficiency, SingleEG20","Events");

        effi("effi25_PtSecond","Trigger Efficiency, SingleEG25","Events");
        effi("effi25_EtaSecond","Trigger Efficiency, SingleEG25","Events");
        effi("effi30_PtSecond","Trigger Efficiency, SingleEG30","Events");
        effi("effi30_EtaSecond","Trigger Efficiency, SingleEG30","Events");
        effi("effi35_PtSecond","Trigger Efficiency, SingleEG35","Events");
        effi("effi35_EtaSecond","Trigger Efficiency, SingleEG35","Events");


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


*/

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

	TH1F *histo=(TH1F*)fileGCTDEF->Get(plot); histo->SetName("Stage1DEF_"+plot);
	TH1F *histoDefault=(TH1F*)fileStage1DEF->Get(plot); histoDefault->SetName("Stage1_"+plot);
        TH1F *histoReRun=(TH1F*)fileStage1ReRun->Get(plot); histoReRun->SetName("Stage1_"+plot);

	histoDefault->SetMarkerColor(kOrange+4);
        histoDefault->SetLineColor(kOrange+4); 
	histoDefault->SetMarkerStyle(21);
	histo->SetMarkerStyle(20);
        histoReRun->SetMarkerColor(kPink+10);
        histoReRun->SetLineColor(kPink+10);
        histoReRun->SetMarkerStyle(22);


	histo->Draw("E");
	histoDefault->Draw("sames,E");
        histoReRun->Draw("sames,E");

	histoDefault->SetXTitle(xlabel);
	histoDefault->SetYTitle(ylabel);
        histo->SetXTitle(xlabel);
        histo->SetYTitle(ylabel);

	histo->GetYaxis()->SetTitleOffset(1.4);
	histo->GetYaxis()->SetTitleSize(0.05);
	histo->GetXaxis()->SetTitleSize(0.05);

	if(histo->GetMaximum()<histoDefault->GetMaximum()) histo->SetMaximum(histoDefault->GetMaximum()*1.2);
        if(histo->GetMaximum()<histoReRun->GetMaximum()) histo->SetMaximum(histoReRun->GetMaximum()*1.2);


      cout<<"Plotting "<<plot<<": data "<<histoDefault->Integral()<<" vs mc "<<histo->Integral()<<" ("<<histoDefault->Integral()/histo->Integral()<<")"<<endl;

	TLegend *leg = new TLegend(xlegmin,ylegmin,xlegmax,ylegmax,NULL,"brNDC");
	TLegendEntry *entry=leg->AddEntry(histoDefault,"Stage1, Unpacked","p");
        entry=leg->AddEntry(histoReRun,"Stage1, Reprocessed","lf");
	entry=leg->AddEntry(histo,"GCT, Unpacked","lf");
	leg->Draw();
	cmsPrelim(LUMI);

	c1->SaveAs("plots/"+plot+".png");
}


void effi(TString plot, double threshold,TString xlabel, TString ylabel, double xlegmin=0.5, double xlegmax=0.9, double ylegmin=0.2, double ylegmax=0.5){	
	TCanvas *c1 = new TCanvas("canvas_"+plot, "canvas_"+plot,0,44,600,600);
	gStyle->SetOptFit(1);
	gStyle->SetOptStat(0);
	c1->SetLeftMargin(0.15);
	c1->SetRightMargin(0.05);
	c1->SetTopMargin(0.10);
	c1->SetBottomMargin(0.11);
	c1->cd();

	TH1F *histo=(TH1F*)fileGCTDEF->Get(plot); histo->SetName("GCT_"+plot);
	TH1F *histoDefault=(TH1F*)fileStage1DEF->Get(plot); histoDefault->SetName("Stage1_"+plot);
        TH1F *histoReRun=(TH1F*)fileStage1ReRun->Get(plot); histoReRun->SetName("Stage1_RERUN_"+plot);

	histoDefault->SetLineColor(kOrange+4);  histoDefault->SetMarkerStyle(21); histoDefault->SetMarkerColor(kOrange+4); histoDefault->SetLineWidth(2);
	histo->SetMarkerStyle(20); histo->SetLineColor(kBlack);  histo->SetLineWidth(2);
        histoReRun->SetLineColor(kPink+10);  histoReRun->SetMarkerStyle(22); histoReRun->SetMarkerColor(kPink+10); histoReRun->SetLineWidth(2);

	histo->Draw("E");
	histoDefault->Draw("sames,p,E");
        histoReRun->Draw("sames,p,E");

	histo->SetXTitle(xlabel);
	histo->SetYTitle(ylabel);

	histo->GetYaxis()->SetTitleOffset(1.4);
	histo->GetYaxis()->SetTitleSize(0.05);
	histo->GetXaxis()->SetTitleSize(0.05);
	histo->GetYaxis()->SetNdivisions(520);

	histo->GetYaxis()->SetRangeUser(0,1.1);

	cmsPrelim(LUMI);

        TLegend *leg = new TLegend(xlegmin,ylegmin,xlegmax,ylegmax,NULL,"brNDC");
        TLegendEntry *entry=leg->AddEntry(histoDefault,"Stage1, Unpacked","pl");
        entry=leg->AddEntry(histoReRun,"Stage1, Reprocessed (JES, PU)","pl");
        entry=leg->AddEntry(histo,"GCT, Unpacked","pl");
        leg->Draw();

	c1->SetGrid();

	   TLine *line = new TLine(threshold,0,threshold,0.5);
	   line->Draw();
	   line = new TLine(0,0.5,threshold,0.5);
	   line->Draw();
	   

	c1->SaveAs("plots/"+plot+".png");
}





void cmsPrelim( double intLumi ){  TLatex latex;
	latex.SetNDC();
	latex.SetTextSize(0.04);

	latex.SetTextAlign(31); // align right
	latex.DrawLatex(0.95,0.93,Form("%.1f pb^{-1}, #sqrt{s} = 13 TeV",intLumi));

	latex.SetTextAlign(11); // align left
	latex.DrawLatex(0.15,0.93,"CMS preliminary");
}

void res(TString plot, TString xlabel, TString ylabel, double xlegmin=0.4, double xlegmax=0.7, double ylegmin=0.4, double ylegmax=0.5){
        TCanvas *c1 = new TCanvas("canvas_"+plot, "canvas_"+plot,0,44,600,600);
        gStyle->SetOptFit(1);
        gStyle->SetOptStat(0);
        c1->SetLeftMargin(0.15);
        c1->SetRightMargin(0.05);
        c1->SetTopMargin(0.10);
        c1->SetBottomMargin(0.11);
        c1->cd();


        TH2F *histo2D=(TH2F*)fileGCTDEF->Get(plot); histo2D->SetName("GCT_2D_"+plot);
        TH2F *histoReRun2D=(TH2F*)fileStage1ReRun->Get(plot); histoReRun2D->SetName("ReRun_2D_"+plot);
        TH2F *histoDefault2D=(TH2F*)fileStage1DEF->Get(plot); histoDefault2D->SetName("Default_2D_"+plot);

	TH1F* histo=(TH1F*)histo2D->ProfileX(); histo->SetName("GCT_"+plot);
        TH1F* histoReRun=(TH1F*)histoReRun2D->ProfileX(); histoReRun->SetName("ReRun_"+plot);
        TH1F* histoDefault=(TH1F*)histoDefault2D->ProfileX(); histoDefault->SetName("Default_"+plot);

        histoDefault->SetLineColor(kOrange+4);  histoDefault->SetMarkerStyle(21); histoDefault->SetMarkerColor(kOrange+4); histoDefault->SetLineWidth(2);
        histo->SetMarkerStyle(20); histo->SetLineColor(kBlack);  histo->SetLineWidth(2);
        histoReRun->SetLineColor(kPink+10);  histoReRun->SetMarkerStyle(22); histoReRun->SetMarkerColor(kPink+10); histoReRun->SetLineWidth(2);

	histoReRun->Draw("hist,p,E");
        histo->Draw("sames,p,hist,E");
        histoDefault->Draw("sames,p,hist,E");

	histoReRun->GetYaxis()->SetRangeUser(-1,1);

        histoReRun->SetXTitle(xlabel);
        histoReRun->SetYTitle(ylabel);

        histoReRun->GetYaxis()->SetTitleOffset(1.4);
        histoReRun->GetYaxis()->SetTitleSize(0.05);
        histoReRun->GetXaxis()->SetTitleSize(0.05);

        TLegend *leg = new TLegend(xlegmin,ylegmin,xlegmax,ylegmax,NULL,"brNDC");
        TLegendEntry * entry=leg->AddEntry("NULL","Profile","");
	entry=leg->AddEntry(histoDefault,"Stage1, Unpacked","p");
        entry=leg->AddEntry(histoReRun,"Stage1, Reprocessed","lf");
        entry=leg->AddEntry(histo,"GCT, Unpacked","lf");
        leg->Draw();

	c1->SaveAs("resolution_"+plot+".png");

}


