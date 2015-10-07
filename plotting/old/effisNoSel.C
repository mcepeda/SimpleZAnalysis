#define effis_cxx
#include "effis.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TH1F.h>

void effisNoSel(){

	double LUMI=40;

        TFile *fileQCDMC= new TFile("QCD_numEvent500000.root");
        TTree* tupleQCDMCDEF=  (TTree*)fileQCDMC->Get("effitreeminiDEFAULT/Ntuple");
        effis treeQCDMCDEF;
        treeQCDMCDEF.Init(tupleQCDMCDEF);
        treeQCDMCDEF.Loop("outputs/QCDMCDEF.root", 1,false);

	TFile *fileMC= new TFile("Ws_test_numEvent500000.root");
	TTree* tupleWsMCDEF=  (TTree*)fileMC->Get("effitreeminiDEFAULT/Ntuple");
        effis treeMCDEF;
        treeMCDEF.Init(tupleWsMCDEF);
        treeMCDEF.Loop("outputs/WsMCDEF.root", 1,false);

	TFile *filePILEUP25ns= new TFile("dataRunC25ns_numEvent30000.root");
        TTree* tupleDataStage125nsDEF=  (TTree*)filePILEUP25ns->Get("effitreeminiDEFAULT/Ntuple");
        effis treeStage125nsDEF;
        treeStage125nsDEF.Init(tupleDataStage125nsDEF);
        treeStage125nsDEF.Loop("outputs/DataStage125nsDEF.root", 1,false);

	TFile *filePILEUP833= new TFile("newroots/effiNEWPURECOMETNOHF.root");
	TFile *fileNOPU833= new TFile("newroots/effiNOPURECOMETNOHF.root");
	TFile *fileOLDPU833= new TFile("newroots/effiOLDPURECOMETNOHF.root");

	TTree* tupleDataStage1833DEF=  (TTree*)filePILEUP833->Get("effitreeminiDEFAULT/Ntuple");
	effis treeStage1833DEF;
	treeStage1833DEF.Init(tupleDataStage1833DEF);
	treeStage1833DEF.Loop("outputs/DataStage1833DEF.root", 1,false);

	TTree* tupleDataGCT833GCTDEF=  (TTree*)filePILEUP833->Get("effitreeminiGCTDEFAULT/Ntuple");
	effis treeGCT833GCTDEF;
	treeGCT833GCTDEF.Init(tupleDataGCT833GCTDEF);
	treeGCT833GCTDEF.Loop("outputs/DataGCT833GCTDEF.root", 1,false);

	TTree* tupleDataStage1833=  (TTree*)filePILEUP833->Get("effitreemini/Ntuple");
	effis treeStage1833;
	treeStage1833.Init(tupleDataStage1833);
	treeStage1833.Loop("outputs/DataStage1833.root", 1,false);

	TTree* tupleDataStage1833NOPU=  (TTree*)fileNOPU833->Get("effitreemini/Ntuple");
	effis treeStage1833NOPU;
	treeStage1833NOPU.Init(tupleDataStage1833NOPU);
	treeStage1833NOPU.Loop("outputs/DataStage1833NOPU.root", 1,false);

	TTree* tupleDataStage1833OLDPU=  (TTree*)fileOLDPU833->Get("effitreemini/Ntuple");
	effis treeStage1833OLDPU;
	treeStage1833OLDPU.Init(tupleDataStage1833OLDPU);
	treeStage1833OLDPU.Loop("outputs/DataStage1833OLDPU.root", 1,false);

	
	//   TTree* tupleDataGCT833OLDPU=  (TTree*)fileOLDPU833->Get("effitreeminiGCT/Ntuple");
	//   effis treeGCT833OLDPU;
	//   treeGCT833OLDPU.Init(tupleDataGCT833OLDPU);
	//   treeGCT833OLDPU.Loop("outputs/DataGCT833OLDPU.root", 1,false);
	
	//   TTree* tupleDataGCT833GCT=  (TTree*)fileNOPU833->Get("effitreeminiGCT/Ntuple");
	//   effis treeGCT833GCT;
	//   treeGCT833GCT.Init(tupleDataGCT833GCT);
	//   treeGCT833GCT.Loop("outputs/DataGCT833GCT.root", 1,false);

}



void effis::Loop(TString outputFile="outputs/Data.root", double scale=1, bool forQCD=false)
{
	if (fChain == 0) return;

	Long64_t nentries = fChain->GetEntriesFast();

	TH1F *histomet = new TH1F("histomet","",50,0,100);  histomet->Sumw2();
	TH1F *histomt = new TH1F("histomt","",100,0,200);  histomt->Sumw2();
	TH1F *recoPtLead = new TH1F("recoPtLead","",50,0,100); recoPtLead->Sumw2();
	TH1F *histonvtx = new TH1F("histonvtx","",40,0,40);  histonvtx->Sumw2();
        TH1F *recoEtaLead = new TH1F("recoEtaLead","",100,-5,5); recoEtaLead->Sumw2();


	TH2F *hLeadPtEtaJet = new TH2F("hLeadPtEtaJet","",40,0,200,100,-5,5);  hLeadPtEtaJet->Sumw2();

	TH1F *nJets = new TH1F("nJets","",10,0,10); nJets->Sumw2();
	TH1F *nJetsClean = new TH1F("nJetsClean","",10,0,10); nJetsClean->Sumw2();
	TH1F *hLeadPtJet = new TH1F("hLeadPtJet","",50,0,500);  hLeadPtJet->Sumw2();
	TH1F *hLeadEtaJet = new TH1F("hLeadEtaJet","",100,-5,5);  hLeadEtaJet->Sumw2();
	TH1F *hAllPtJet = new TH1F("hAllPtJet","",50,0,500);  hAllPtJet->Sumw2();
        TH1F *hLeadPhiJet = new TH1F("hLeadPhiJet","",100,-5,5);  hLeadPhiJet->Sumw2();
        TH1F *hDeltaREleJet = new TH1F("hDeltaREleJet","",100,0,10);  hDeltaREleJet->Sumw2();
        TH1F *hDeltaPhiEleJet = new TH1F("hDeltaPhiEleJet","",100,0,10);  hDeltaPhiEleJet->Sumw2();
        TH1F *hDeltaEtaEleJet = new TH1F("hDeltaEtaEleJet","",100,0,10);  hDeltaEtaEleJet->Sumw2();

	TH1F *hL1LeadPtJet = new TH1F("hL1LeadPtJet","",50,0,500);  hL1LeadPtJet->Sumw2();
	TH1F *hL1LeadEtaJet = new TH1F("hL1LeadEtaJet","",100,-5,5);  hL1LeadEtaJet->Sumw2();

	TH1F *hL1LeadMatchedPtJet = new TH1F("hL1LeadMatchedPtJet","",50,0,500);  hL1LeadMatchedPtJet->Sumw2();
	TH1F *hL1LeadMatchedEtaJet = new TH1F("hL1LeadMatchedEtaJet","",100,-5,5);  hL1LeadMatchedEtaJet->Sumw2();

	TH1F* hL1LeadMatchedDR = new TH1F("hL1LeadMatchedDR","",100,0,2); hL1LeadMatchedDR->Sumw2();

	TH1F *hLeadPtJetTrig50 = new TH1F("hLeadPtJetTrig50","",50,0,500);  hLeadPtJetTrig50->Sumw2();
	TH1F *hLeadPtJetTrig70 = new TH1F("hLeadPtJetTrig70","",50,0,500);  hLeadPtJetTrig70->Sumw2();
	TH1F *hLeadPtJetTrig100 = new TH1F("hLeadPtJetTrig100","",50,0,500);  hLeadPtJetTrig100->Sumw2();
	TH1F *hLeadPtJetTrig150 = new TH1F("hLeadPtJetTrig150","",50,0,500);  hLeadPtJetTrig150->Sumw2();
	TH1F *hAllPtJetTrig70 = new TH1F("hAllPtJetTrig70","",50,0,500);  hAllPtJetTrig70->Sumw2();

	TH1F *hResLeadPtJet = new TH1F("hResLeadPtJet","",100,-1,1);  hResLeadPtJet->Sumw2();
	TH2F *hResLeadPtJet2D = new TH2F("hResLeadPtJet2D","",50,0,500,100,-0.5,0.5);  hResLeadPtJet2D->Sumw2();
	TH2F *hResLeadPtJet2DL1 = new TH2F("hResLeadPtJet2DL1","",50,0,500,100,-0.5,0.5);  hResLeadPtJet2DL1->Sumw2();
	TH2F *hResLeadPtJet2DEta = new TH2F("hResLeadPtJet2DEta","",100,-5,5,100,-0.5,0.5);  hResLeadPtJet2DEta->Sumw2();
	TH2F *hResLeadPtJet2DNVTX = new TH2F("hResLeadPtJet2DNVTX","",10,0,40,100,-0.5,0.5);  hResLeadPtJet2DNVTX->Sumw2();


	TH1F *reconvtx = new TH1F("reconvtx","",10,0,40);  reconvtx->Sumw2();
	TH1F *reconvtxLeadPtJetTrig50 = new TH1F("reconvtxLeadPtJetTrig50","",10,0,40);  reconvtxLeadPtJetTrig50->Sumw2();
        TH1F *reconvtxForDivide = new TH1F("reconvtxForDivide","",10,0,40);  reconvtxForDivide->Sumw2();



	double sumall=0;
	double count=0;
	double countw=0;

	Long64_t nbytes = 0, nb = 0;
	for (Long64_t jentry=0; jentry<nentries;jentry++) {
		Long64_t ientry = LoadTree(jentry);
		if (ientry < 0) break;
		nb = fChain->GetEntry(jentry);   nbytes += nb;
		// if (Cut(ientry) < 0) continue;
		double weightPlots=scale;
		count++;

		if(scale!=1) {
			double puweight=1;//weightsPU[nvtx];
			if(nvtx>40) puweight=0;
			//cout<<puweight<<endl;
			sumall+=genweight;//*puweight;
			weightPlots=genweight*scale;//*puweight;
			if(genweight>0) countw++; else countw--;		
		}	


		if(recoNTight20<1) continue;
		if(recoNLoose20>=2) continue;
		double leadPtreco=recopt->at(0);
		if(fabs(recoeta->at(0))>2.5   ) continue;
		if(fabs(recoeta->at(0))>1.44&&fabs(recoeta->at(0))<1.55) continue;
		double leadL1Pt=l1matchedpt->at(0);//leadMatch<pt->size()?pt->at(leadMatch):0;
		double leadL1Eta=l1matchedeta->at(0); //leadMatch<eta->size()?eta->at(leadMatch):0;
		double leadL1Phi=l1matchedphi->at(0); //leadMatch<phi->size()?phi->at(leadMatch):0;

		if(recomt->at(0)<50) continue;
		if(recotightid->at(0)!=1) continue;
		if(leadPtreco<25) continue;
                if(recoconversion->at(0)!=1) continue;

		histomet->Fill(recoMet_Et,weightPlots);
		histomt->Fill(recomt->at(0),weightPlots);
		recoPtLead->Fill(leadPtreco,weightPlots);
		histonvtx->Fill(nvtx,weightPlots);
                recoEtaLead->Fill(recoeta->at(0),weightPlots);

		int countJets=0, countJetsClean=0, leadPtJetCount=-1;
		double leadPtJet=0;
		bool filter=false;
		for (int m=0; m<recoJetpt->size(); m++){
			if (recoJetpt->at(m)<25) continue;
				
			if (fabs(recoJeteta->at(m))<2.5||fabs(recoJeteta->at(m))>3) filter=true;
//			if (fabs(recoJeteta->at(m))>=2.5) continue;
			if (fabs(recoJeteta->at(m))<3.5) continue;
			//if(recoJetTightJetID->at(m)!=1) continue;	


			countJets++;
			bool thisisaelectron=false;
			double dEtaJet=0, dphiJet=0, dRJet=0;
			for (int k=0; k<recoeta->size(); k++){
				dEtaJet=recoJeteta->at(m)-recoeta->at(k);
				dphiJet=recoJetphi->at(m)-recophi->at(k);
				if (dphiJet > 3.141516) dphiJet -= 2*3.141516;
				if (dphiJet <= -3.141516) dphiJet += 2*3.141516;
				dRJet= sqrt(dEtaJet*dEtaJet+dphiJet*dphiJet);
				if (dRJet<0.5) thisisaelectron=true;
			}
			if(thisisaelectron==true) continue;

			countJetsClean++;
			if(recoJetpt->at(m)>leadPtJet) leadPtJetCount=m; 

			hAllPtJet->Fill(recoJetpt->at(m),weightPlots);
			int matchJetM=recoJetmatches->at(m);

			if(matchJetM==-1) continue;
			dEtaJet=recoJeteta->at(m)-jeteta->at(matchJetM);
			dphiJet=recoJetphi->at(m)-jetphi->at(matchJetM);
			if (dphiJet > 3.141516) dphiJet -= 2*3.141516;
			if (dphiJet <= -3.141516) dphiJet += 2*3.141516;
			dRJet= sqrt(dEtaJet*dEtaJet+dphiJet*dphiJet);
			if (dRJet>0.5) continue;
			if(matchJetM!=-1&&jetpt->at(matchJetM)>70) {hAllPtJetTrig70->Fill(recoJetpt->at(m),weightPlots);}

		}


		if(leadPtJetCount!=-1) {

                                double dEtaJet=recoJeteta->at(leadPtJetCount)-recoeta->at(0);
                                double dphiJet=recoJetphi->at(leadPtJetCount)-recophi->at(0);
                                if (dphiJet > 3.141516) dphiJet -= 2*3.141516;
                                if (dphiJet <= -3.141516) dphiJet += 2*3.141516;
                                double dRJetEle= sqrt(dEtaJet*dEtaJet+dphiJet*dphiJet);

			//if(filter==false && dRJetEle>4) continue;

			hDeltaREleJet->Fill(dRJetEle,weightPlots);
                        hDeltaEtaEleJet->Fill(dEtaJet,weightPlots);
                        hDeltaPhiEleJet->Fill(dphiJet,weightPlots);

			hLeadPtJet->Fill(recoJetpt->at(leadPtJetCount),weightPlots);
			hLeadEtaJet->Fill(recoJeteta->at(leadPtJetCount),weightPlots);
                        hLeadPhiJet->Fill(recoJetphi->at(leadPtJetCount),weightPlots);
                        hLeadPtEtaJet->Fill(recoJetpt->at(leadPtJetCount),recoJeteta->at(leadPtJetCount),weightPlots);

			reconvtx->Fill(nvtx,weightPlots);
			if(recoJetpt->at(leadPtJetCount)>70 )reconvtxForDivide->Fill(nvtx,weightPlots);


			int matchJet=recoJetmatches->at(leadPtJetCount);

			if(matchJet!=-1){

				double dEtaJet=recoJeteta->at(leadPtJetCount)-jeteta->at(matchJet);
				double dphiJet=recoJetphi->at(leadPtJetCount)-jetphi->at(matchJet);
				if (dphiJet > 3.141516) dphiJet -= 2*3.141516;
				if (dphiJet <= -3.141516) dphiJet += 2*3.141516;
				double dRJet= sqrt(dEtaJet*dEtaJet+dphiJet*dphiJet);

				hL1LeadMatchedDR->Fill(dRJet,weightPlots);
				if(dRJet<=0.5) {
					hL1LeadMatchedPtJet->Fill(jetpt->at(matchJet),weightPlots);
					hL1LeadMatchedEtaJet->Fill(jeteta->at(matchJet),weightPlots);	
					if(jetpt->at(matchJet)>50) {hLeadPtJetTrig50->Fill(recoJetpt->at(leadPtJetCount),weightPlots);}	
					if(jetpt->at(matchJet)>70) {hLeadPtJetTrig70->Fill(recoJetpt->at(leadPtJetCount),weightPlots);}
					if(jetpt->at(matchJet)>100) {hLeadPtJetTrig100->Fill(recoJetpt->at(leadPtJetCount),weightPlots);}
					if(jetpt->at(matchJet)>150) {hLeadPtJetTrig150->Fill(recoJetpt->at(leadPtJetCount),weightPlots);}

					if(jetpt->at(matchJet)>50&&recoJetpt->at(leadPtJetCount)>70) {reconvtxLeadPtJetTrig50->Fill(nvtx,weightPlots);}

					if(jetpt->at(matchJet)<=250){ // skipping the saturated jets
						if(recoJetpt->at(leadPtJetCount)>70) hResLeadPtJet->Fill(-1+jetpt->at(matchJet)/recoJetpt->at(leadPtJetCount),weightPlots);
						hResLeadPtJet2D->Fill(recoJetpt->at(leadPtJetCount),-1+jetpt->at(matchJet)/recoJetpt->at(leadPtJetCount),weightPlots);
						hResLeadPtJet2DL1->Fill(jetpt->at(matchJet),-1+jetpt->at(matchJet)/recoJetpt->at(leadPtJetCount),weightPlots);
						if(recoJetpt->at(leadPtJetCount)>70) {hResLeadPtJet2DEta->Fill(recoJeteta->at(leadPtJetCount),-1+jetpt->at(matchJet)/recoJetpt->at(leadPtJetCount),weightPlots);}
						if(recoJetpt->at(leadPtJetCount)>70 && jetpt->at(matchJet)>50) {hResLeadPtJet2DNVTX->Fill(nvtx,-1+jetpt->at(matchJet)/recoJetpt->at(leadPtJetCount),weightPlots);}
					}
				}}
		}

		nJets->Fill(countJets,weightPlots); nJetsClean->Fill(countJetsClean,weightPlots);

		int countJetsL1=0, countJetsCleanL1=0, leadPtJetCountL1=-1;
		double leadPtJetL1=0;
		for (int m=0; m<jetpt->size(); m++){
			if (jetpt->at(m)<30) continue;
			countJetsL1++;
			if(jetpt->at(m)>leadPtJetL1) leadPtJetCountL1=m;
		}


		if(leadPtJetCountL1!=-1) {
			hL1LeadPtJet->Fill(jetpt->at(leadPtJetCountL1),weightPlots);
			hL1LeadEtaJet->Fill(jeteta->at(leadPtJetCountL1),weightPlots);
		}

	}


	TH1F *effi_PtLead_Jet50=(TH1F*)hLeadPtJetTrig50->Clone();
	effi_PtLead_Jet50->SetName("effi_PtLead_Jet50");
	effi_PtLead_Jet50->Divide(hLeadPtJetTrig50,hLeadPtJet,1,1,"B");

	TGraphAsymmErrors *effiG_PtLead_Jet50=new TGraphAsymmErrors(hLeadPtJetTrig50,hLeadPtJet);
	effiG_PtLead_Jet50->SetName("effiG_PtLead_Jet50");

	TH1F *effi_PtLead_Jet70=(TH1F*)hLeadPtJetTrig70->Clone();
	effi_PtLead_Jet70->SetName("effi_PtLead_Jet70");
	effi_PtLead_Jet70->Divide(hLeadPtJetTrig70,hLeadPtJet,1,1,"B");

        TGraphAsymmErrors *effiG_PtLead_Jet70=new TGraphAsymmErrors(hLeadPtJetTrig70,hLeadPtJet);
        effiG_PtLead_Jet70->SetName("effiG_PtLead_Jet70");

	TH1F *effi_PtLead_Jet100=(TH1F*)hLeadPtJetTrig100->Clone();
	effi_PtLead_Jet100->SetName("effi_PtLead_Jet100");
	effi_PtLead_Jet100->Divide(hLeadPtJetTrig100,hLeadPtJet,1,1,"B");

        TGraphAsymmErrors *effiG_PtLead_Jet100=new TGraphAsymmErrors(hLeadPtJetTrig100,hLeadPtJet);
        effiG_PtLead_Jet100->SetName("effiG_PtLead_Jet100");

	TH1F *effi_PtLead_Jet150=(TH1F*)hLeadPtJetTrig150->Clone();
	effi_PtLead_Jet150->SetName("effi_PtLead_Jet150");
	effi_PtLead_Jet150->Divide(hLeadPtJetTrig150,hLeadPtJet,1,1,"B");

        TGraphAsymmErrors *effiG_PtLead_Jet150=new TGraphAsymmErrors(hLeadPtJetTrig150,hLeadPtJet);
        effiG_PtLead_Jet150->SetName("effiG_PtLead_Jet150");

	TH1F *effi_PtAll_Jet70=(TH1F*)hAllPtJetTrig70->Clone();
	effi_PtAll_Jet70->SetName("effi_PtAll_Jet70");
	effi_PtAll_Jet70->Divide(hAllPtJetTrig70,hAllPtJet,1,1,"B");

        TGraphAsymmErrors *effiG_PtAll_Jet70=new TGraphAsymmErrors(hAllPtJetTrig70,hAllPtJet);
        effiG_PtAll_Jet70->SetName("effiG_PtAll_Jet70");

	TH1F *effi_nvtx_Jet70=(TH1F*)reconvtxLeadPtJetTrig50->Clone();
	effi_nvtx_Jet70->SetName("effi_nvtx_Jet70");
	effi_nvtx_Jet70->Divide(reconvtxLeadPtJetTrig50,reconvtxForDivide,1,1,"B");

        TGraphAsymmErrors *effiG_nvtx_Jet70=new TGraphAsymmErrors(reconvtxLeadPtJetTrig50,reconvtx);
        effiG_nvtx_Jet70->SetName("effiG_nvtx_Jet70");


	cout<<count<<"   ->"<<countw<<"  ->"<<sumall<<endl;

	TFile *output = new TFile(outputFile,"RECREATE");
	output->cd();
	nJets->Write();
	nJetsClean->Write();
	hLeadPtJet->Write();
	hLeadEtaJet->Write();
	hL1LeadPtJet->Write();
	hL1LeadEtaJet->Write();
	hL1LeadMatchedPtJet->Write();
	hL1LeadMatchedEtaJet->Write();
	hLeadPtJetTrig50->Write();
	hResLeadPtJet->Write();

	effi_PtLead_Jet50->Write();
	effi_PtLead_Jet70->Write();
	effi_PtLead_Jet100->Write();
	effi_PtLead_Jet150->Write();

        effiG_PtLead_Jet50->Write();
        effiG_PtLead_Jet70->Write();
        effiG_PtLead_Jet100->Write();
        effiG_PtLead_Jet150->Write();

	effi_PtAll_Jet70->Write();
	hAllPtJet->Write();

        effiG_PtAll_Jet70->Write();

	histomet->Write();
	histomt->Write();
	recoPtLead->Write();

	hL1LeadMatchedDR->Write();

	hResLeadPtJet2D->Write();
	hResLeadPtJet2DEta->Write();
	hResLeadPtJet2DL1->Write();

	reconvtxLeadPtJetTrig50->Write();
	reconvtx->Write();
	histonvtx->Write();
	effi_nvtx_Jet70->Write();
	hResLeadPtJet2DNVTX->Write();

        effiG_nvtx_Jet70->Write();

	hLeadPhiJet->Write();
	hDeltaREleJet->Write();
        hDeltaEtaEleJet->Write();
        hDeltaPhiEleJet->Write();
	
	recoEtaLead->Write();
	hLeadPtEtaJet->Write();

}
