#include "tdrstyle.C"
TFile *fileIso, *fileAll;

double LUMI=24;

void cmsPrelim( double intLumi);
void cmsPrelimMC();

void prettyPlottingForTWEPPV3(){

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

        TGraphAsymmErrors *o15=(TGraphAsymmErrors*)fileAll->Get("effi15_PtSecond"); o15->SetName("effi15");
        TGraphAsymmErrors *o20=(TGraphAsymmErrors*)fileAll->Get("effi20_PtSecond"); o20->SetName("effi20");
        TGraphAsymmErrors *o25=(TGraphAsymmErrors*)fileAll->Get("effi25_PtSecond"); o25->SetName("effi25");
        TGraphAsymmErrors *o30=(TGraphAsymmErrors*)fileAll->Get("effi30_PtSecond"); o30->SetName("effi30");
        TGraphAsymmErrors *o35=(TGraphAsymmErrors*)fileAll->Get("effi35_PtSecond"); o35->SetName("effi35");

        TGraphAsymmErrors *oIso15=(TGraphAsymmErrors*)fileIso->Get("effi15_PtSecond"); oIso15->SetName("effiIso15");
        TGraphAsymmErrors *oIso20=(TGraphAsymmErrors*)fileIso->Get("effi20_PtSecond"); oIso20->SetName("effiIso20");
        TGraphAsymmErrors *oIso25=(TGraphAsymmErrors*)fileIso->Get("effi25_PtSecond"); oIso25->SetName("effiIso25");
        TGraphAsymmErrors *oIso30=(TGraphAsymmErrors*)fileIso->Get("effi30_PtSecond"); oIso30->SetName("effiIso30");
        TGraphAsymmErrors *oIso35=(TGraphAsymmErrors*)fileIso->Get("effi35_PtSecond"); oIso35->SetName("effiIso35");

	TH1F *histo15=(TH1F*)fileAll->Get("effiH15_PtSecond"); histo15->SetName("effiH15");
        TH1F *histo20=(TH1F*)fileAll->Get("effiH20_PtSecond"); histo20->SetName("effiH20");
        TH1F *histo25=(TH1F*)fileAll->Get("effiH25_PtSecond"); histo25->SetName("effiH25");
        TH1F *histo30=(TH1F*)fileAll->Get("effiH30_PtSecond"); histo30->SetName("effiH30");
        TH1F *histo35=(TH1F*)fileAll->Get("effiH35_PtSecond"); histo35->SetName("effiH35");

        TH1F *histoIso15=(TH1F*)fileIso->Get("effiH15_PtSecond"); histoIso15->SetName("effiH15");
        TH1F *histoIso20=(TH1F*)fileIso->Get("effiH20_PtSecond"); histoIso20->SetName("effiH20");
        TH1F *histoIso25=(TH1F*)fileIso->Get("effiH25_PtSecond"); histoIso25->SetName("effiH25");
        TH1F *histoIso30=(TH1F*)fileIso->Get("effiH30_PtSecond"); histoIso30->SetName("effiH30");
        TH1F *histoIso35=(TH1F*)fileIso->Get("effiH35_PtSecond"); histoIso35->SetName("effiH35");

	histo15->Draw("hist");
        histoIso15->Draw("hist,sames");
        histoIso20->Draw("hist,sames");
        histoIso25->Draw("hist,sames");
        histoIso30->Draw("hist,sames");
        histoIso35->Draw("hist,sames");

	o15->Draw("P,sames");
        oIso15->Draw("P,sames");
        oIso20->Draw("P,sames");
        oIso25->Draw("P,sames");
        oIso30->Draw("P,sames");
        oIso35->Draw("P,sames");


        histo15->SetLineWidth(2);
        histo20->SetLineWidth(2);
        histo25->SetLineWidth(2);
        histo30->SetLineWidth(2);
        histo35->SetLineWidth(2);

        histo15->SetMarkerStyle(1);
        histo20->SetMarkerStyle(1);
        histo25->SetMarkerStyle(1);
        histo30->SetMarkerStyle(1);
        histo35->SetMarkerStyle(1);





        histo15->SetLineColor(kViolet-4);histo15->SetMarkerColor(kViolet-4);
        histo20->SetLineColor(kBlack);histo20->SetMarkerColor(kBlack);
        histo25->SetLineColor(kMagenta);histo25->SetMarkerColor(kMagenta);
        histo30->SetLineColor(kCyan+1);histo30->SetMarkerColor(kCyan+1);
        histo35->SetLineColor(kGreen+1);histo35->SetMarkerColor(kGreen+1);

        o15->SetLineColor(kViolet-4);o15->SetMarkerColor(kViolet-4);
        o20->SetLineColor(kBlack);o20->SetMarkerColor(kBlack);
        o25->SetLineColor(kMagenta);o25->SetMarkerColor(kMagenta);
        o30->SetLineColor(kCyan+1);o30->SetMarkerColor(kCyan+1);
        o35->SetLineColor(kGreen+1);o35->SetMarkerColor(kGreen+1);

        o15->SetLineWidth(2);
        o20->SetLineWidth(2);
        o25->SetLineWidth(2);
        o30->SetLineWidth(2);
        o35->SetLineWidth(2);

        o15->SetMarkerStyle(1);
        o20->SetMarkerStyle(1);
        o25->SetMarkerStyle(1);
        o30->SetMarkerStyle(1);
        o35->SetMarkerStyle(1);

        histo15->SetLineStyle(kSolid);
        histo20->SetLineStyle(kSolid);
        histo25->SetLineStyle(kSolid);
        histo30->SetLineStyle(kSolid);
        histo35->SetLineStyle(kSolid);

        histoIso15->SetLineWidth(2);
        histoIso20->SetLineWidth(2);
        histoIso25->SetLineWidth(2);
        histoIso30->SetLineWidth(2);
        histoIso35->SetLineWidth(2);

        histoIso15->SetMarkerStyle(1);
        histoIso20->SetMarkerStyle(1);
        histoIso25->SetMarkerStyle(1);
        histoIso30->SetMarkerStyle(1);
        histoIso35->SetMarkerStyle(1);

        histoIso15->SetLineColor(kViolet+4);histoIso15->SetMarkerColor(kViolet+4);
        histoIso20->SetLineColor(kBlack);histoIso20->SetMarkerColor(kBlack);
        histoIso25->SetLineColor(kMagenta);histoIso25->SetMarkerColor(kMagenta);
        histoIso30->SetLineColor(kCyan+1);histoIso30->SetMarkerColor(kCyan+1);
        histoIso35->SetLineColor(kGreen+1);histoIso35->SetMarkerColor(kGreen+1);

        oIso15->SetLineColor(kViolet+4);oIso15->SetMarkerColor(kViolet+4);
        oIso20->SetLineColor(kBlack);oIso20->SetMarkerColor(kBlack);
        oIso25->SetLineColor(kMagenta);oIso25->SetMarkerColor(kMagenta);
        oIso30->SetLineColor(kCyan+1);oIso30->SetMarkerColor(kCyan+1);
        oIso35->SetLineColor(kGreen+1);oIso35->SetMarkerColor(kGreen+1);

        oIso15->SetMarkerStyle(1);
        oIso20->SetMarkerStyle(1);
        oIso25->SetMarkerStyle(1);
        oIso30->SetMarkerStyle(1);
        oIso35->SetMarkerStyle(1);

        oIso15->SetLineWidth(2);
        oIso20->SetLineWidth(2);
        oIso25->SetLineWidth(2);
        oIso30->SetLineWidth(2);
        oIso35->SetLineWidth(2);

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

