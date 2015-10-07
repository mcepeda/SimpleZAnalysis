#include "tdrstyle.C"
TFile *fileIso, *fileAll;

double LUMI=24;

void cmsPrelim( double intLumi);
void cmsPrelimMC();

void prettyPlottingForTWEPP(){

	setTDRStyle();

        fileAll=new TFile("outputs/DataStage1833.root","READONLY");
        fileIso=new TFile("outputs/DataStage1833Iso.root","READONLY");




	TCanvas *c1 = new TCanvas("canvas", "canvas",0,44,600,600);
	gStyle->SetOptFit(1);
	gStyle->SetOptStat(0);
	c1->SetLeftMargin(0.15);
	c1->SetRightMargin(0.05);
	c1->SetTopMargin(0.10);
	c1->SetBottomMargin(0.11);
	c1->cd();


        TH1F *histo10=(TH1F*)fileAll->Get("effi10_PtSecond"); histo10->SetName("effi10");
	TH1F *histo15=(TH1F*)fileAll->Get("effi15_PtSecond"); histo15->SetName("effi15");
        TH1F *histo20=(TH1F*)fileAll->Get("effi20_PtSecond"); histo20->SetName("effi20");
        TH1F *histo25=(TH1F*)fileAll->Get("effi25_PtSecond"); histo25->SetName("effi25");
        TH1F *histo30=(TH1F*)fileAll->Get("effi30_PtSecond"); histo30->SetName("effi30");
        TH1F *histo35=(TH1F*)fileAll->Get("effi35_PtSecond"); histo35->SetName("effi35");

        TH1F *histonvtx20=(TH1F*)fileAll->Get("effi20_nvtxSecond"); histonvtx20->SetName("effinvtx20");


        TH1F *histoIso10=(TH1F*)fileIso->Get("effi10_PtSecond"); histoIso10->SetName("effi10");
        TH1F *histoIso15=(TH1F*)fileIso->Get("effi15_PtSecond"); histoIso15->SetName("effi15");
        TH1F *histoIso20=(TH1F*)fileIso->Get("effi20_PtSecond"); histoIso20->SetName("effi20");
        TH1F *histoIso25=(TH1F*)fileIso->Get("effi25_PtSecond"); histoIso25->SetName("effi25");
        TH1F *histoIso30=(TH1F*)fileIso->Get("effi30_PtSecond"); histoIso30->SetName("effi30");
        TH1F *histoIso35=(TH1F*)fileIso->Get("effi35_PtSecond"); histoIso35->SetName("effi35");

        TH1F *histoIsonvtx20=(TH1F*)fileIso->Get("effi20_nvtxSecond"); histoIsonvtx20->SetName("effiIsonvtx20");



	histo15->Draw("hist,E");
        histoIso15->Draw("hist,E,sames");
        histoIso20->Draw("hist,E,sames");
        histoIso25->Draw("hist,E,sames");
        histoIso30->Draw("hist,E,sames");
        histoIso35->Draw("hist,E,sames");


        histo10->SetLineWidth(2);
        histo15->SetLineWidth(2);
        histo20->SetLineWidth(2);
        histo25->SetLineWidth(2);
        histo30->SetLineWidth(2);
        histo35->SetLineWidth(2);
        histonvtx20->SetLineWidth(2);

        histo10->SetMarkerStyle(24);
        histo15->SetMarkerStyle(24);
        histo20->SetMarkerStyle(24);
        histo25->SetMarkerStyle(24);
        histo30->SetMarkerStyle(24);
        histo35->SetMarkerStyle(24);
        histonvtx20->SetMarkerStyle(24);

        histo10->SetLineColor(kViolet);histo10->SetMarkerColor(kViolet);
        histo15->SetLineColor(kViolet+4);histo15->SetMarkerColor(kViolet+4);
        histo20->SetLineColor(kBlack);histo20->SetMarkerColor(kBlack);
        histo25->SetLineColor(kMagenta);histo25->SetMarkerColor(kMagenta);
        histo30->SetLineColor(kCyan+1);histo30->SetMarkerColor(kCyan+1);
        histo35->SetLineColor(kGreen+1);histo35->SetMarkerColor(kGreen+1);
        histonvtx20->SetLineColor(kBlack);histonvtx20->SetMarkerColor(kBlack);



        histo10->SetLineStyle(kDashed);
        histo15->SetLineStyle(kDashed);
        histo20->SetLineStyle(kDashed);
        histo25->SetLineStyle(kDashed);
        histo30->SetLineStyle(kDashed);
        histo35->SetLineStyle(kDashed);
        histonvtx20->SetLineStyle(kDashed);



        histoIso10->SetLineWidth(2);
        histoIso15->SetLineWidth(2);
        histoIso20->SetLineWidth(2);
        histoIso25->SetLineWidth(2);
        histoIso30->SetLineWidth(2);
        histoIso35->SetLineWidth(2);
        histoIsonvtx20->SetLineWidth(2);

        histoIso10->SetMarkerStyle(20);
        histoIso15->SetMarkerStyle(20);
        histoIso20->SetMarkerStyle(20);
        histoIso25->SetMarkerStyle(20);
        histoIso30->SetMarkerStyle(20);
        histoIso35->SetMarkerStyle(20);
        histoIsonvtx20->SetMarkerStyle(20);

        histoIso10->SetLineColor(kViolet);histoIso10->SetMarkerColor(kViolet);
        histoIso15->SetLineColor(kViolet+4);histoIso15->SetMarkerColor(kViolet+4);
        histoIso20->SetLineColor(kBlack);histoIso20->SetMarkerColor(kBlack);
        histoIso25->SetLineColor(kMagenta);histoIso25->SetMarkerColor(kMagenta);
        histoIso30->SetLineColor(kCyan+1);histoIso30->SetMarkerColor(kCyan+1);
        histoIso35->SetLineColor(kGreen+1);histoIso35->SetMarkerColor(kGreen+1);
        histoIsonvtx20->SetLineColor(kBlack);histoIsonvtx20->SetMarkerColor(kBlack);



	histo15->SetXTitle("Electron p_{T} [GeV]");
	histo15->SetYTitle("Efficiency");

	histo15->GetYaxis()->SetTitleOffset(1.4);
	histo15->GetYaxis()->SetTitleSize(0.05);
	histo15->GetXaxis()->SetTitleSize(0.05);

	histo15->GetYaxis()->SetRangeUser(0,1.1);

        TLegend *leg2 = new TLegend(0.5,0.2,0.7,0.7,NULL,"brNDC");
	leg2->SetFillColor(0);
	leg2->SetBorderSize(0);
        entry=leg2->AddEntry(histo15,"SingleEG15","pl");
        entry=leg2->AddEntry(histoIso15,"SingleIsoEG15","pl");
        entry=leg2->AddEntry(histoIso20,"SingleIsoEG20","pl");
        entry=leg2->AddEntry(histoIso25,"SingleIsoEG25","pl");
        entry=leg2->AddEntry(histoIso30,"SingleIsoEG30","pl");
        entry=leg2->AddEntry(histoIso35,"SingleIsoEG35","pl");
        leg2->Draw();


//	cmsPrelimMC();
	cmsPrelim(LUMI);

	c1->SaveAs("SingleEG.png");

	TCanvas *C2=new TCanvas("C2");
        gStyle->SetOptFit(1);
        gStyle->SetOptStat(0);
        C2->SetLeftMargin(0.15);
        C2->SetRightMargin(0.05);
        C2->SetTopMargin(0.10);
        C2->SetBottomMargin(0.11);
	 histonvtx20->GetYaxis()->SetRangeUser(0,1.05);
         histonvtx20->GetXaxis()->SetRangeUser(0,40);
        histonvtx20->SetXTitle("#PVs");
        histonvtx20->SetYTitle("Efficiency");
	histonvtx20->Draw("E");
	histoIsonvtx20->Draw("sames,E");
	cmsPrelim(LUMI);

}


void cmsPrelimMC(){ 
	 TLatex latex;
        latex.SetNDC();
        latex.SetTextSize(0.04);

        latex.SetTextAlign(31); // align right
        latex.DrawLatex(0.95,0.93,"#sqrt{s} = 13 TeV");

        latex.SetTextAlign(11); // align left
        latex.DrawLatex(0.15,0.93,"CMS simulation");
}


void cmsPrelim( double intLumi ){  TLatex latex;
	latex.SetNDC();
	latex.SetTextSize(0.04);

	latex.SetTextAlign(31); // align right
	latex.DrawLatex(0.95,0.93,Form("%.1f pb^{-1}, #sqrt{s} = 13 TeV",intLumi));

	latex.SetTextAlign(11); // align left
	latex.DrawLatex(0.15,0.93,"CMS preliminary");
}

