#include "tdrstyle.C"
TFile *fileIso, *fileAll;

double LUMI=24;

void cmsPrelim( double intLumi);
void cmsPrelimMC();

void prettyPlottingForTWEPP(){

	setTDRStyle();

//        fileAll=new TFile("outputs/DataGCT833DEF.root","READONLY");
//        fileIso=new TFile("outputs/DataGCT833DEFIso.root","READONLY");

        fileAll=new TFile("outputs/DataStage1833.root","READONLY");
        fileIso=new TFile("outputs/DataStage1833Iso.root","READONLY");

//        fileAll=new TFile("outputs/MCStage125nsDEF.root","READONLY");
//        fileIso=new TFile("outputs/MCStage125nsDEFIso.root","READONLY");


	TCanvas *c1 = new TCanvas("canvas", "canvas",0,44,600,600);
	gStyle->SetOptFit(1);
	gStyle->SetOptStat(0);
	c1->SetLeftMargin(0.15);
	c1->SetRightMargin(0.05);
	c1->SetTopMargin(0.10);
	c1->SetBottomMargin(0.11);
	c1->cd();

        TGraphAsymmErrors *o10=(TGraphAsymmErrors*)fileAll->Get("effi10_PtSecond"); o10->SetName("effi10");
	TGraphAsymmErrors *o15=(TGraphAsymmErrors*)fileAll->Get("effi15_PtSecond"); o15->SetName("effi15");
        TGraphAsymmErrors *o20=(TGraphAsymmErrors*)fileAll->Get("effi20_PtSecond"); o20->SetName("effi20");
        TGraphAsymmErrors *o25=(TGraphAsymmErrors*)fileAll->Get("effi25_PtSecond"); o25->SetName("effi25");
        TGraphAsymmErrors *o30=(TGraphAsymmErrors*)fileAll->Get("effi30_PtSecond"); o30->SetName("effi30");
        TGraphAsymmErrors *o35=(TGraphAsymmErrors*)fileAll->Get("effi35_PtSecond"); o35->SetName("effi35");

        TGraphAsymmErrors *onvtx20=(TGraphAsymmErrors*)fileAll->Get("effi20_nvtxSecond"); onvtx20->SetName("effi20PV");


        TGraphAsymmErrors *oIso10=(TGraphAsymmErrors*)fileIso->Get("effi10_PtSecond"); oIso10->SetName("effiIso10");
        TGraphAsymmErrors *oIso15=(TGraphAsymmErrors*)fileIso->Get("effi15_PtSecond"); oIso15->SetName("effiIso15");
        TGraphAsymmErrors *oIso20=(TGraphAsymmErrors*)fileIso->Get("effi20_PtSecond"); oIso20->SetName("effiIso20");
        TGraphAsymmErrors *oIso25=(TGraphAsymmErrors*)fileIso->Get("effi25_PtSecond"); oIso25->SetName("effiIso25");
        TGraphAsymmErrors *oIso30=(TGraphAsymmErrors*)fileIso->Get("effi30_PtSecond"); oIso30->SetName("effiIso30");
        TGraphAsymmErrors *oIso35=(TGraphAsymmErrors*)fileIso->Get("effi35_PtSecond"); oIso35->SetName("effiIso35");

        TGraphAsymmErrors *onvtxIso20=(TGraphAsymmErrors*)fileIso->Get("effi20_nvtxSecond"); onvtxIso20->SetName("effi20PVIso");

	TH1F* oAxis=(TH1F*)o15->GetHistogram(); oAxis->SetName("oAxis");

/*
        TH1F *hIso10=(TH1F*)fileIso->Get("effiH10_PtSecond"); hIso10->SetName("effiHIso10");
        TH1F *hIso15=(TH1F*)fileIso->Get("effiH15_PtSecond"); hIso15->SetName("effiHIso15");
        TH1F *hIso20=(TH1F*)fileIso->Get("effiH20_PtSecond"); hIso20->SetName("effiHIso20");
        TH1F *hIso25=(TH1F*)fileIso->Get("effiH25_PtSecond"); hIso25->SetName("effiHIso25");
        TH1F *hIso30=(TH1F*)fileIso->Get("effiH30_PtSecond"); hIso30->SetName("effiHIso30");
        TH1F *hIso35=(TH1F*)fileIso->Get("effiH35_PtSecond"); hIso35->SetName("effiHIso35");

	cout<<"AY"<<endl;


	oAxis->Draw();
	o15->Draw("Ep,sames");


        oIso15->Draw("Ep,sames");
        oIso20->Draw("Ep,sames");
        oIso25->Draw("Ep,sames");
        oIso30->Draw("Ep,sames");
        oIso35->Draw("Ep,sames");

        o10->SetLineWidth(2);
        o15->SetLineWidth(2);
        o20->SetLineWidth(2);
        o25->SetLineWidth(2);
        o30->SetLineWidth(2);
        o35->SetLineWidth(2);
        onvtx20->SetLineWidth(2);

        o10->SetMarkerStyle(24);
        o15->SetMarkerStyle(24);
        o20->SetMarkerStyle(24);
        o25->SetMarkerStyle(24);
        o30->SetMarkerStyle(24);
        o35->SetMarkerStyle(24);
        onvtx20->SetMarkerStyle(24);

        o10->SetLineColor(kViolet);o10->SetMarkerColor(kViolet);
        o15->SetLineColor(kViolet+4);o15->SetMarkerColor(kViolet+4);
        o20->SetLineColor(kBlack);o20->SetMarkerColor(kBlack);
        o25->SetLineColor(kMagenta);o25->SetMarkerColor(kMagenta);
        o30->SetLineColor(kCyan+1);o30->SetMarkerColor(kCyan+1);
        o35->SetLineColor(kGreen+1);o35->SetMarkerColor(kGreen+1);
        onvtx20->SetLineColor(kBlack);onvtx20->SetMarkerColor(kBlack);



        o10->SetLineStyle(kDashed);
        o15->SetLineStyle(kDashed);
        o20->SetLineStyle(kDashed);
        o25->SetLineStyle(kDashed);
        o30->SetLineStyle(kDashed);
        o35->SetLineStyle(kDashed);
        onvtx20->SetLineStyle(kDashed);



        oIso10->SetLineWidth(2);
        oIso15->SetLineWidth(2);
        oIso20->SetLineWidth(2);
        oIso25->SetLineWidth(2);
        oIso30->SetLineWidth(2);
        oIso35->SetLineWidth(2);
        onvtxIso20->SetLineWidth(2);

        oIso10->SetMarkerStyle(20);
        oIso15->SetMarkerStyle(20);
        oIso20->SetMarkerStyle(20);
        oIso25->SetMarkerStyle(20);
        oIso30->SetMarkerStyle(20);
        oIso35->SetMarkerStyle(20);
        onvtxIso20->SetMarkerStyle(20);

        oIso10->SetLineColor(kViolet);oIso10->SetMarkerColor(kViolet);
        oIso15->SetLineColor(kViolet+4);oIso15->SetMarkerColor(kViolet+4);
        oIso20->SetLineColor(kBlack);oIso20->SetMarkerColor(kBlack);
        oIso25->SetLineColor(kMagenta);oIso25->SetMarkerColor(kMagenta);
        oIso30->SetLineColor(kCyan+1);oIso30->SetMarkerColor(kCyan+1);
        oIso35->SetLineColor(kGreen+1);oIso35->SetMarkerColor(kGreen+1);
        onvtxIso20->SetLineColor(kBlack);onvtxIso20->SetMarkerColor(kBlack);



	oAxis->SetXTitle("Electron p_{T} [GeV]");
	oAxis->SetYTitle("Efficiency");

	oAxis->GetYaxis()->SetTitleOffset(1.4);
	oAxis->GetYaxis()->SetTitleSize(0.05);
	oAxis->GetXaxis()->SetTitleSize(0.05);

	oAxis->GetYaxis()->SetRangeUser(0,1.1);

	TLegend *leg = new TLegend(0.7,0.2,0.9,0.7,NULL,"brNDC");
	TLegendEntry *entry; 
        entry=leg->AddEntry(o15,"SingleEG15","pl");
        entry=leg->AddEntry(o20,"SingleEG20","pl");
        entry=leg->AddEntry(o25,"SingleEG25","pl");
        entry=leg->AddEntry(o30,"SingleEG30","pl");
        entry=leg->AddEntry(o35,"SingleEG35","pl");
//	leg->Draw();


        TLegend *leg2 = new TLegend(0.5,0.2,0.7,0.7,NULL,"brNDC");
	leg2->SetFillColor(0);
	leg2->SetBorderSize(0);
        entry=leg2->AddEntry(o15,"SingleEG15","pl");
        entry=leg2->AddEntry(oIso15,"SingleIsoEG15","pl");
        entry=leg2->AddEntry(oIso20,"SingleIsoEG20","pl");
        entry=leg2->AddEntry(oIso25,"SingleIsoEG25","pl");
        entry=leg2->AddEntry(oIso30,"SingleIsoEG30","pl");
        entry=leg2->AddEntry(oIso35,"SingleIsoEG35","pl");
        leg2->Draw();


//	cmsPrelimMC();
	cmsPrelim(LUMI);

*/

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

