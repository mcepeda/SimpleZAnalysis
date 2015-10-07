#include "tdrstyle.C"
TFile *file25ns, *file50ns;

double LUMI=10;

void plot(TString plot,TString xlabel, TString ylabel,double xlegmin=0.2, double xlegmax=0.4, double ylegmin=0.75, double ylegmax=0.85);
void cmsPrelim( double intLumi);
void effi(TString plot, TString xlabel, TString ylabel, double xlegmin=0.5, double xlegmax=0.7, double ylegmin=0.3, double ylegmax=0.5);
void res(TString plot, TString xlabel, TString ylabel, double xlegmin=0.5, double xlegmax=0.7, double ylegmin=0.3, double ylegmax=0.5);

void prettyPlotting2550(){

	setTDRStyle();

	file50ns=new TFile("outputs/DataStage1833DEFIso.root","READONLY");
	file25ns=new TFile("outputs/DataStage125nsDEFIso.root","READONLY");

//	res("ResSecondPtTrig2DEta","Reco #eta","(l1pt-recopt)/recopt",0.3,0.7,0.2,0.4);
//        res("ResSecondPtTrig2DL1","L1 #pt","(l1pt-recopt)/recopt",0.3,0.7,0.2,0.4);

	plot("nJets","nJets","Events");
        plot("nJetsClean","nJetsClean","Events");
        plot("hLeadPtJet","Lead Jet Pt","Events");
        plot("hLeadEtaJet","Lead Jet #eta","Events");

/*
        plot("histonvtx", "NVertices", "Events");

        plot("met_Et", "MET [GeV]", "Events / GeV");

	plot("massZ", "Mass DiElectron [GeV]", "Events / GeV");

        plot("massZL1", "Mass DiElectron [GeV]", "Events / GeV");
	
        plot("massZRes", "1 - MassL1 / MassReco ", "Events");
	

//      plot("massZL1V2", "Mass DiElectron [GeV]", "Events / GeV");

        plot("recoPtSecond","Sublead Electron p_{t} [GeV]","Events / GeV");
        plot("recoPtLead","Lead Electron p_{t} [GeV]","Events / GeV");

        plot("ResLeadPt","(l1Pt-recoPt)/recoPt - lead Electron","Events");
        plot("ResSecondPtTrig20","(l1Pt-recoPt)/recoPt - sublead electron","Events");
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


        effi("effi20_nvtxSecond","Trigger Efficiency, SingleEG20","Events");
        effi("effi20_nvtxSecondEB","Trigger Efficiency, SingleEG20 (EB)","Events");
        effi("effi20_nvtxSecondEE","Trigger Efficiency, SingleEG20 (EE)","Events");
*/
}

void plot(TString plot, TString xlabel, TString ylabel, double xlegmin=0.2, double xlegmax=0.4, double ylegmin=0.75, double ylegmax=0.85){	
	TCanvas *c1 = new TCanvas("canvas_"+plot, "canvas_"+plot,0,66,600,600);
	gStyle->SetOptFit(1);
	gStyle->SetOptStat(0);
        c1->Range(0,0,1,1);
	c1->SetLeftMargin(0.15);
	c1->SetRightMargin(0.05);
	c1->SetTopMargin(0.10);
	c1->SetBottomMargin(0.11);
	c1->cd();

	TPad *pad_1 = new TPad("Pad1_"+plot, "",0.008,0.22,0.99,0.99);
   pad_1->Draw();
   pad_1->cd();
   pad_1->Range(-1.266667,-0.01421653,1.4,0.09514138);
   pad_1->SetRightMargin(0.15);
   pad_1->SetTopMargin(0.13);
   pad_1->SetBottomMargin(0.13);


	TH1F *histo=(TH1F*)file25ns->Get(plot); histo->SetName("25ns_"+plot);
	TH1F *histo50ns=(TH1F*)file50ns->Get(plot); histo50ns->SetName("50ns_"+plot);

	histo->SetMarkerColor(kPink+10);
        histo->SetLineColor(kPink+10); 
	histo->SetMarkerStyle(21);
	histo50ns->SetMarkerStyle(20);
//	histo50ns->Scale(1./4);
	 histo50ns->Scale(1./histo50ns->Integral());
         histo->Scale(1./histo->Integral());


	histo50ns->Draw("hist,E");
	histo->Draw("sames,hist,E");
	histo50ns->SetXTitle(xlabel);
	histo50ns->SetYTitle(ylabel);

	histo50ns->GetYaxis()->SetTitleOffset(1.4);
	histo50ns->GetYaxis()->SetTitleSize(0.05);
	histo50ns->GetXaxis()->SetTitleSize(0.05);

	if(histo50ns->GetMaximum()<histo->GetMaximum()) histo50ns->SetMaximum(histo->GetMaximum()*1.2);


      cout<<"Plotting "<<plot<<": data "<<histo50ns->Integral()<<" vs mc "<<histo->Integral()<<" ("<<histo50ns->Integral()/histo->Integral()<<")"<<endl;

	TLegend *leg = new TLegend(xlegmin,ylegmin,xlegmax,ylegmax,NULL,"brNDC");
        TLegendEntry *entry=leg->AddEntry(histo50ns,"50ns, run 254833","pl");
        entry=leg->AddEntry(histo,"25ns","lp");
	leg->Draw();
	cmsPrelim(LUMI);

   c1->cd();
   TPad *pad_2 = new TPad("pad_2_"+plot, "pad_2",0.008,0.010,0.99,0.19);
   pad_2->Draw();
   pad_2->cd();
   pad_2->Range(-1.26484,0.3372093,1.406393,1.523256);
   pad_2->SetGridx();
   pad_2->SetGridy();
   pad_2->SetRightMargin(0.1521368);
   pad_2->SetTopMargin(0.01960784);
   pad_2->SetBottomMargin(0.1372549);
   pad_2->SetFrameFillStyle(0);
   pad_2->SetFrameBorderMode(0);
   pad_2->SetFrameFillStyle(0);
   pad_2->SetFrameBorderMode(0);

	TH1F * ratio=(TH1F*)histo->Clone();  ratio->SetName("ratio_"+plot);
	ratio->Divide(histo50ns);

	c1->cd(2);
	ratio->Draw("p");
   ratio->GetXaxis()->SetLabelSize(0.035);
   ratio->GetYaxis()->SetNdivisions(505);
   ratio->GetYaxis()->SetLabelSize(0.17);
   ratio->GetZaxis()->SetLabelSize(0.035);
   ratio->GetYaxis()->SetRangeUser(0,2);
   ratio->SetYTitle("Ratio");
	c1->SaveAs("plots/"+plot+".png");
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

        TH2F *histo2D=(TH2F*)file25ns->Get(plot); histo2D->SetName("25ns_2D_"+plot);
        TH2F *histo50ns2D=(TH2F*)file50ns->Get(plot); histo50ns2D->SetName("50ns_2D_"+plot);

	TH1F*histo=(TH1F*)histo2D->ProfileX(); histo->SetName("25ns_"+plot);
        TH1F*histo50ns=(TH1F*)histo50ns2D->ProfileX(); histo50ns->SetName("25ns_"+plot);

        histo->SetLineColor(kPink+10);  histo->SetMarkerStyle(21); histo->SetMarkerColor(kPink+10); histo->SetLineWidth(2);
        histo50ns->SetMarkerStyle(20); histo50ns->SetLineColor(kBlack);  histo50ns->SetLineWidth(2);

	histo50ns->Draw("hist,p,E");
        histo->Draw("sames,p,hist,E");

	histo50ns->GetYaxis()->SetRangeUser(-0.2,0.2);

        histo50ns->SetXTitle(xlabel);
        histo50ns->SetYTitle(ylabel);

        histo50ns->GetYaxis()->SetTitleOffset(1.4);
        histo50ns->GetYaxis()->SetTitleSize(0.05);
        histo50ns->GetXaxis()->SetTitleSize(0.05);

        TLegend *leg = new TLegend(xlegmin,ylegmin,xlegmax,ylegmax,NULL,"brNDC");
        TLegendEntry *entry=leg->AddEntry(histo50ns,"50ns, run 254833","pl");
        entry=leg->AddEntry(histo,"25ns","lp");
        leg->Draw();

	c1->SaveAs("resolution_"+plot+".png");

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

	TH1F *histo=(TH1F*)file25ns->Get(plot); histo->SetName("25ns_"+plot);
	TH1F *histo50ns=(TH1F*)file50ns->Get(plot); histo50ns->SetName("50ns_"+plot);

	histo->SetLineColor(kPink+10);  histo->SetMarkerStyle(21); histo->SetMarkerColor(kPink+10); histo->SetLineWidth(2);
	histo50ns->SetMarkerStyle(20); histo50ns->SetLineColor(kBlack);  histo50ns->SetLineWidth(2);

	histo50ns->Draw("hist,p,E");
	histo->Draw("sames,p,hist,E");
	histo50ns->SetXTitle(xlabel);
	histo50ns->SetYTitle(ylabel);

	histo50ns->GetYaxis()->SetTitleOffset(1.4);
	histo50ns->GetYaxis()->SetTitleSize(0.05);
	histo50ns->GetXaxis()->SetTitleSize(0.05);

	histo50ns->GetYaxis()->SetRangeUser(0,1.1);

	TLegend *leg = new TLegend(xlegmin,ylegmin,xlegmax,ylegmax,NULL,"brNDC");
	TLegendEntry *entry=leg->AddEntry(histo50ns,"50ns, run 254833","lp");
	entry=leg->AddEntry(histo,"25ns","lf");
	leg->Draw();
	cmsPrelim(LUMI);

	c1->SaveAs("plots/"+plot+".png");
}





void cmsPrelim( double intLumi ){  TLatex latex;
	latex.SetNDC();
	latex.SetTextSize(0.04);

//	latex.SetTextAlign(31); // align right
//	latex.DrawLatex(0.95,0.93,Form("%.0f pb^{-1} + %.0f pb^{-1}, #sqrt{s} = 13 TeV",intLumi,40.000));

	latex.SetTextAlign(11); // align left
	latex.DrawLatex(0.15,0.93,"CMS preliminary");
}

