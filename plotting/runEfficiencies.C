#define effis_cxx
#include "effis.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TH1F.h>

void runEfficiencies(){

        double LUMI=23.7;

        TFile *fileDataStage1= new TFile("roots/test.root");

        TTree* tupleDataStage1DEF=  (TTree*)fileDataStage1->Get("effitreeWZDEFAULT/Ntuple");
        effis treeStage1DEF;
        treeStage1DEF.Init(tupleDataStage1DEF);
        treeStage1DEF.Loop("outputs/DataStage1DEF.root", 1,false);


/*  
        //For MC     

        double LUMI=23.7;
        double xsec=2008.4*3;
        double normalization=1.56649e+09;

        TTree* tupleMCStage125nsDEF=  (TTree*)fileMCStage125ns->Get("effitreeminiDEFAULT/Ntuple");
        effis treeMCStage125nsDEF;
        treeMCStage125nsDEF.Init(tupleMCStage125nsDEF);
        treeMCStage125nsDEF.Loop("outputs/MCStage125nsDEF.root", xsec*LUMI/normalization,false);
*/

}



void effis::Loop(TString outputFile="outputs/Data.root", double scale=1, bool forQCD=false)
{
        if (fChain == 0) return;

        Long64_t nentries = fChain->GetEntriesFast();


        const int binsPt=13;
        double ptbins[21]={0,5,10,15,20,25,30,35,40,45,50,60,70,100};

        //        const int binsPt=16;
        //        double ptbins[21]={0,5,10,15,20,22.5,25,27.5,30,32.5,35,37.5,40,45,50,60,70,100};


        TH1F *histonvtx = new TH1F("histonvtx","",40,0,40);  histonvtx->Sumw2();
        TH1F *massZ = new TH1F("massZ","",30,60,120);  massZ->Sumw2();
        TH1F *massZL1 = new TH1F("massZL1","",30,60,120);  massZL1->Sumw2();
        TH1F *massZL1V2 = new TH1F("massZL1V2","",30,60,120);  massZL1V2->Sumw2();

        TH1F *massZRes = new TH1F("massZRes","",50,-1,1);  massZRes->Sumw2();



        TH1F *reconvtx = new TH1F("reconvtx","",8,0,40);  reconvtx->Sumw2();
        TH1F *reconvtxEB = new TH1F("reconvtxEB","",8,0,40);  reconvtxEB->Sumw2();
        TH1F *reconvtxEE = new TH1F("reconvtxEE","",8,0,40);  reconvtxEE->Sumw2();
        TH1F *reconvtxSecondTrig20 = new TH1F("reconvtxSecondTrig20","",8,0,40);  reconvtxSecondTrig20->Sumw2();
        TH1F *reconvtxSecondEBTrig20 = new TH1F("reconvtxSecondEBTrig20","",8,0,40);  reconvtxSecondEBTrig20->Sumw2();
        TH1F *reconvtxSecondEETrig20 = new TH1F("reconvtxSecondEETrig20","",8,0,40);  reconvtxSecondEETrig20->Sumw2();



        TH1F *met = new TH1F("met_Et","",50,0,100);  met->Sumw2();

        TH1F *recoPtLead = new TH1F("recoPtLead","",50,0,100); recoPtLead->Sumw2();
        TH1F *recoPtSecond = new TH1F("recoPtSecond","",50,0,100); recoPtSecond->Sumw2();

        TH1F *recoBinPtLead = new TH1F("recoBinPtLead","",binsPt,ptbins); recoBinPtLead->Sumw2();
        TH1F *recoBinPtSecond = new TH1F("recoBinPtSecond","",binsPt,ptbins); recoBinPtSecond->Sumw2();
        TH1F *recoBinPtLeadTrig = new TH1F("recoBinPtLeadTrig","",binsPt,ptbins); recoBinPtLeadTrig->Sumw2();
        TH1F *recoBeforeBinPtLead = new TH1F("recoBeforeBinPtLead","",binsPt,ptbins); recoBeforeBinPtLead->Sumw2();
        TH1F *recoBeforeBinPtSecond = new TH1F("recoBeforeBinPtSecond","",binsPt,ptbins); recoBeforeBinPtSecond->Sumw2();


        TH1F *recoBinPtSecondTrig10 = new TH1F("recoBinPtSecondTrig10","",binsPt,ptbins); recoBinPtSecondTrig10->Sumw2();
        TH1F *recoBinPtSecondTrig15 = new TH1F("recoBinPtSecondTrig15","",binsPt,ptbins); recoBinPtSecondTrig15->Sumw2();
        TH1F *recoBinPtSecondTrig20 = new TH1F("recoBinPtSecondTrig20","",binsPt,ptbins); recoBinPtSecondTrig20->Sumw2();
        TH1F *recoBinPtSecondTrig25 = new TH1F("recoBinPtSecondTrig25","",binsPt,ptbins); recoBinPtSecondTrig25->Sumw2();
        TH1F *recoBinPtSecondTrig30 = new TH1F("recoBinPtSecondTrig30","",binsPt,ptbins); recoBinPtSecondTrig30->Sumw2();
        TH1F *recoBinPtSecondTrig35 = new TH1F("recoBinPtSecondTrig35","",binsPt,ptbins); recoBinPtSecondTrig35->Sumw2();

        TH1F *recoBinPtSecondEBTrig15 = new TH1F("recoBinPtSecondEBTrig15","",binsPt,ptbins); recoBinPtSecondEBTrig15->Sumw2();
        TH1F *recoBinPtSecondEBTrig20 = new TH1F("recoBinPtSecondEBTrig20","",binsPt,ptbins); recoBinPtSecondEBTrig20->Sumw2();
        TH1F *recoBinPtSecondEBTrig25 = new TH1F("recoBinPtSecondEBTrig25","",binsPt,ptbins); recoBinPtSecondEBTrig25->Sumw2();
        TH1F *recoBinPtSecondEBTrig30 = new TH1F("recoBinPtSecondEBTrig30","",binsPt,ptbins); recoBinPtSecondEBTrig30->Sumw2();
        TH1F *recoBinPtSecondEBTrig35 = new TH1F("recoBinPtSecondEBTrig35","",binsPt,ptbins); recoBinPtSecondEBTrig35->Sumw2();
        TH1F *recoBinPtSecondEB = new TH1F("recoBinPtSecondEB","",binsPt,ptbins); recoBinPtSecondEB->Sumw2();

        TH1F *recoBinPtSecondEETrig15 = new TH1F("recoBinPtSecondEETrig15","",binsPt,ptbins); recoBinPtSecondEETrig15->Sumw2();
        TH1F *recoBinPtSecondEETrig20 = new TH1F("recoBinPtSecondEETrig20","",binsPt,ptbins); recoBinPtSecondEETrig20->Sumw2();
        TH1F *recoBinPtSecondEETrig25 = new TH1F("recoBinPtSecondEETrig25","",binsPt,ptbins); recoBinPtSecondEETrig25->Sumw2();
        TH1F *recoBinPtSecondEETrig30 = new TH1F("recoBinPtSecondEETrig30","",binsPt,ptbins); recoBinPtSecondEETrig30->Sumw2();
        TH1F *recoBinPtSecondEETrig35 = new TH1F("recoBinPtSecondEETrig35","",binsPt,ptbins); recoBinPtSecondEETrig35->Sumw2();
        TH1F *recoBinPtSecondEE = new TH1F("recoBinPtSecondEE","",binsPt,ptbins); recoBinPtSecondEE->Sumw2();

        TH1F *l1PtLead = new TH1F("l1PtLead","",50,0,100); l1PtLead->Sumw2();
        TH1F *l1PtSecond = new TH1F("l1PtSecond","",50,0,100);l1PtSecond->Sumw2();

        TH1F *l1PtLeadEB = new TH1F("l1PtLeadEB","",50,0,100); l1PtLeadEB->Sumw2();
        TH1F *l1PtSecondEB = new TH1F("l1PtSecondEB","",50,0,100);l1PtSecondEB->Sumw2();

        TH1F *l1PtLeadEE = new TH1F("l1PtLeadEE","",50,0,100); l1PtLeadEE->Sumw2();
        TH1F *l1PtSecondEE = new TH1F("l1PtSecondEE","",50,0,100);l1PtSecondEE->Sumw2();

        TH1F *l1DRMatchLead = new TH1F("l1DRMatchLead","",100,0,1); l1DRMatchLead->Sumw2();
        TH1F *l1DRMatchSecond = new TH1F("l1DRMatchSecond","",100,0,1);l1DRMatchSecond->Sumw2();

        TH1F *ResLeadPt = new TH1F("ResLeadPt","",100,-1,1);  ResLeadPt->Sumw2();
        TH1F *ResSecondPtTrig15 = new TH1F("ResSecondPtTrig15","",100,-1,1);  ResSecondPtTrig15->Sumw2();
        TH1F *ResSecondPtTrig20 = new TH1F("ResSecondPtTrig20","",100,-1,1);  ResSecondPtTrig20->Sumw2();
        TH1F *ResSecondPtTrig25 = new TH1F("ResSecondPtTrig25","",100,-1,1);  ResSecondPtTrig25->Sumw2();
        TH1F *ResSecondPtTrig2540 = new TH1F("ResSecondPtTrig2540","",100,-1,1);  ResSecondPtTrig2540->Sumw2();
        TH1F *ResSecondPtTrig30 = new TH1F("ResSecondPtTrig30","",100,-1,1);  ResSecondPtTrig30->Sumw2();
        TH1F *ResSecondPtTrig35 = new TH1F("ResSecondPtTrig35","",100,-1,1);  ResSecondPtTrig35->Sumw2();

        TH1F *ResSecondPtTrig20EB = new TH1F("ResSecondPtTrig20EB","",100,-1,1);  ResSecondPtTrig20EB->Sumw2();
        TH1F *ResSecondPtTrig20EE = new TH1F("ResSecondPtTrig20EE","",100,-1,1);  ResSecondPtTrig20EE->Sumw2();

        TH2F *ResSecondPtTrig2D = new TH2F("ResSecondPtTrig2D","",50,0,100,100,-1,1);  ResSecondPtTrig2D->Sumw2();
        TH2F *ResSecondPtTrig2DL1 = new TH2F("ResSecondPtTrig2DL1","",50,0,100,100,-1,1);  ResSecondPtTrig2DL1->Sumw2();
        TH2F *ResSecondPtTrig2DEta = new TH2F("ResSecondPtTrig2DEta","",20,-2.5,2.5,100,-1,1);  ResSecondPtTrig2DEta->Sumw2();


        TH1F *ResEtaLeadPt = new TH1F("ResEtaLeadPt","",100,-1,1);  ResEtaLeadPt->Sumw2();
        TH1F *ResEtaSecondPtTrig15 = new TH1F("ResEtaSecondPtTrig15","",100,-1,1);  ResEtaSecondPtTrig15->Sumw2();
        TH1F *ResEtaSecondPtTrig25 = new TH1F("ResEtaSecondPtTrig25","",100,-1,1);  ResEtaSecondPtTrig25->Sumw2();
        TH1F *ResEtaSecondPtTrig20 = new TH1F("ResEtaSecondPtTrig20","",100,-1,1);  ResEtaSecondPtTrig20->Sumw2();
        TH1F *ResEtaSecondPtTrig30 = new TH1F("ResEtaSecondPtTrig30","",100,-1,1);  ResEtaSecondPtTrig30->Sumw2();
        TH1F *ResEtaSecondPtTrig35 = new TH1F("ResEtaSecondPtTrig35","",100,-1,1);  ResEtaSecondPtTrig35->Sumw2();

        TH1F *ResPhiLeadPt = new TH1F("ResPhiLeadPt","",100,-1,1);  ResPhiLeadPt->Sumw2();
        TH1F *ResPhiSecondPtTrig15 = new TH1F("ResPhiSecondPtTrig15","",100,-1,1);  ResPhiSecondPtTrig15->Sumw2();
        TH1F *ResPhiSecondPtTrig25 = new TH1F("ResPhiSecondPtTrig25","",100,-1,1);  ResPhiSecondPtTrig25->Sumw2();
        TH1F *ResPhiSecondPtTrig20 = new TH1F("ResPhiSecondPtTrig20","",100,-1,1);  ResPhiSecondPtTrig20->Sumw2();
        TH1F *ResPhiSecondPtTrig30 = new TH1F("ResPhiSecondPtTrig30","",100,-1,1);  ResPhiSecondPtTrig30->Sumw2();
        TH1F *ResPhiSecondPtTrig35 = new TH1F("ResPhiSecondPtTrig35","",100,-1,1);  ResPhiSecondPtTrig35->Sumw2();



        TH1F *recoEtaLead = new TH1F("recoEtaLead","",20,-2.5,2.5); recoEtaLead->Sumw2();
        TH1F *recoEtaSecond = new TH1F("recoEtaSecond","",20,-2.5,2.5); recoEtaSecond->Sumw2();
        TH1F *recoEtaSecondr20 = new TH1F("recoEtaSecondr20","",20,-2.5,2.5); recoEtaSecondr20->Sumw2();
        TH1F *recoEtaSecondr25 = new TH1F("recoEtaSecondr25","",20,-2.5,2.5); recoEtaSecondr25->Sumw2();
        TH1F *recoEtaSecondr30 = new TH1F("recoEtaSecondr30","",20,-2.5,2.5); recoEtaSecondr30->Sumw2();
        TH1F *recoEtaSecondr35 = new TH1F("recoEtaSecondr35","",20,-2.5,2.5); recoEtaSecondr35->Sumw2();
        TH1F *recoEtaSecondr40 = new TH1F("recoEtaSecondr40","",20,-2.5,2.5); recoEtaSecondr40->Sumw2();
        TH1F *recoEtaSecondr45 = new TH1F("recoEtaSecondr45","",20,-2.5,2.5); recoEtaSecondr45->Sumw2();

        TH1F *recoEtaLeadTrig = new TH1F("recoEtaLeadTrig","",20,-2.5,2.5); recoEtaLeadTrig->Sumw2();

        TH1F *recoEtaSecondTrig15 = new TH1F("recoEtaSecondTrig15","",20,-2.5,2.5); recoEtaSecondTrig15->Sumw2();
        TH1F *recoEtaSecondTrig20 = new TH1F("recoEtaSecondTrig20","",20,-2.5,2.5); recoEtaSecondTrig20->Sumw2();
        TH1F *recoEtaSecondTrig25 = new TH1F("recoEtaSecondTrig25","",20,-2.5,2.5); recoEtaSecondTrig25->Sumw2();
        TH1F *recoEtaSecondTrig30 = new TH1F("recoEtaSecondTrig30","",20,-2.5,2.5); recoEtaSecondTrig30->Sumw2();
        TH1F *recoEtaSecondTrig35 = new TH1F("recoEtaSecondTrig35","",20,-2.5,2.5); recoEtaSecondTrig35->Sumw2();

        TH1F *l1EtaLead = new TH1F("l1EtaLead","",20,-2.5,2.5); l1EtaLead->Sumw2();
        TH1F *l1EtaSecond = new TH1F("l1EtaSecond","",20,-2.5,2.5);l1EtaSecond->Sumw2();


        TH1F *nJets = new TH1F("nJets","",10,0,10); nJets->Sumw2();
        TH1F *nJetsClean = new TH1F("nJetsClean","",10,0,10); nJetsClean->Sumw2();
        TH1F *hLeadPtJet = new TH1F("hLeadPtJet","",25,0,200);  hLeadPtJet->Sumw2();
        TH1F *hLeadEtaJet = new TH1F("hLeadEtaJet","",100,-5,5);  hLeadEtaJet->Sumw2();

        TH1F *hL1LeadPtJet = new TH1F("hL1LeadPtJet","",25,0,200);  hL1LeadPtJet->Sumw2();
        TH1F *hL1LeadEtaJet = new TH1F("hL1LeadEtaJet","",100,-5,5);  hL1LeadEtaJet->Sumw2();

        TH1F *hL1LeadMatchedPtJet = new TH1F("hL1LeadMatchedPtJet","",25,0,200);  hL1LeadMatchedPtJet->Sumw2();
        TH1F *hL1LeadMatchedEtaJet = new TH1F("hL1LeadMatchedEtaJet","",100,-5,5);  hL1LeadMatchedEtaJet->Sumw2();

        TH1F *hLeadPtJetTrig50 = new TH1F("hLeadPtJetTrig50","",25,0,200);  hLeadPtJetTrig50->Sumw2();
        TH1F *hResLeadPtJet = new TH1F("hResLeadPtJet","",100,-1,1);  hResLeadPtJet->Sumw2();


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
                        sumall+=genweight;//puweight;
                        //cout<<genweight<<endl;
                        weightPlots=genweight*scale;//*puweight;
                        if(genweight>0) countw++; else countw--;		
                }	



                if(recoNLoose10<2||recoNTight20<1) continue;
                double leadPtreco=recopt->at(leadElectronForZ_);
                double secondPtreco=recopt->at(secondElectronForZ_);

                /*
                   if(scale!=1) {
                   leadPtreco=leadPtreco*0.99;
                   secondPtreco=secondPtreco*0.99;
                   }
                   */

                if(leadPtreco<32)continue;


                //      if(fabs(recoeta->at(leadElectronForZ_))>2.1 || fabs(recoeta->at(leadElectronForZ_))<1.5) continue;	
                //      if(fabs(recoeta->at(secondElectronForZ_))>2.5 || fabs(recoeta->at(secondElectronForZ_))<1.5) continue;

                if(fabs(recoeta->at(leadElectronForZ_))>2.1   ) continue;
                if(fabs(recoeta->at(secondElectronForZ_))>2.5 ) continue;

                if(fabs(recoeta->at(secondElectronForZ_))>1.44&&fabs(recoeta->at(secondElectronForZ_))<1.55) continue;
                if(fabs(recoeta->at(leadElectronForZ_))>1.44&&fabs(recoeta->at(leadElectronForZ_))<1.55) continue;
                if(!recotightid->at(leadElectronForZ_))continue;
                if(!recolooseid->at(secondElectronForZ_))continue;
                if(recomassForZ<60 || recomassForZ> 120) continue;    

                double leadL1Pt=l1matchedpt->at(leadElectronForZ_);//leadMatch<pt->size()?pt->at(leadMatch):0;
                double leadL1Eta=l1matchedeta->at(leadElectronForZ_); //leadMatch<eta->size()?eta->at(leadMatch):0;
                double leadL1Phi=l1matchedphi->at(leadElectronForZ_); //leadMatch<phi->size()?phi->at(leadMatch):0;

                double secondL1Pt=l1matchedpt->at(secondElectronForZ_);//secondMatch<pt->size()?pt->at(secondMatch):0;
                double secondL1Eta=l1matchedeta->at(secondElectronForZ_); //secondMatch<eta->size()?eta->at(secondMatch):0;
                double secondL1Phi=l1matchedphi->at(secondElectronForZ_); //secondMatch<phi->size()?phi->at(secondMatch):0;
                double secondEtareco=recoeta->at(secondElectronForZ_);

                recoBeforeBinPtLead->Fill(leadPtreco,weightPlots);
                recoBeforeBinPtSecond->Fill(secondPtreco,weightPlots);

                if(leadL1Pt==secondL1Pt && leadL1Eta==secondL1Eta && leadL1Phi==secondL1Phi) continue;
                //if(l1matcheddR->at(leadElectronForZ_)>0.25 || l1matcheddR->at(secondElectronForZ_)>0.25) continue;
                if(leadL1Pt<25 || fabs(leadL1Eta)>2.1) continue;
                if(!hltEle27Tight && !hltEle2775) continue;

                met->Fill(recoMet_Et,weightPlots);
                massZ->Fill(recomassForZ,weightPlots);
                recoPtLead->Fill(leadPtreco,weightPlots);
                recoPtSecond->Fill(secondPtreco,weightPlots);
                massZL1->Fill(recomassForZL1,weightPlots);
                massZL1V2->Fill(recomassForZL1V2,weightPlots);

                massZRes->Fill((-recomassForZL1+recomassForZ)/recomassForZ,weightPlots);


                histonvtx->Fill(nvtx,weightPlots);	
                if(secondPtreco>30) reconvtx->Fill(nvtx,weightPlots);

                recoBinPtLead->Fill(leadPtreco,weightPlots);
                recoBinPtSecond->Fill(secondPtreco,weightPlots);
                if(fabs(secondEtareco)<1.5) {		
                        if(secondPtreco>30) reconvtxEB->Fill(nvtx,weightPlots); 
                        recoBinPtSecondEB->Fill(secondPtreco,weightPlots);}
                if(fabs(secondEtareco)>1.5) {
                        if(secondPtreco>30) reconvtxEE->Fill(nvtx,weightPlots); 
                        recoBinPtSecondEE->Fill(secondPtreco,weightPlots);}



                if(leadPtreco>40) recoEtaLead->Fill(recoeta->at(leadElectronForZ_),weightPlots);
                recoEtaSecond->Fill(recoeta->at(secondElectronForZ_),weightPlots);
                if(secondPtreco>25) recoEtaSecondr25->Fill(recoeta->at(secondElectronForZ_),weightPlots);
                if(secondPtreco>30) recoEtaSecondr30->Fill(recoeta->at(secondElectronForZ_),weightPlots);
                if(secondPtreco>35) recoEtaSecondr35->Fill(recoeta->at(secondElectronForZ_),weightPlots);
                if(secondPtreco>40) recoEtaSecondr40->Fill(recoeta->at(secondElectronForZ_),weightPlots);
                if(secondPtreco>45) recoEtaSecondr45->Fill(recoeta->at(secondElectronForZ_),weightPlots);



                l1PtLead->Fill(leadL1Pt,weightPlots);
                l1PtSecond->Fill(secondL1Pt,weightPlots);

                if(fabs(leadL1Eta)<1.5) l1PtLeadEB->Fill(leadL1Pt,weightPlots);
                if(fabs(secondEtareco)<1.5) l1PtSecondEB->Fill(secondL1Pt,weightPlots);

                if(fabs(leadL1Eta)>1.5) l1PtLeadEE->Fill(leadL1Pt,weightPlots);
                if(fabs(secondEtareco)>1.5) l1PtSecondEE->Fill(secondL1Pt,weightPlots);

                l1EtaLead->Fill(leadL1Eta,weightPlots);
                l1EtaSecond->Fill(secondL1Eta,weightPlots);

                l1DRMatchLead->Fill(l1matcheddR->at(leadElectronForZ_),weightPlots);
                l1DRMatchSecond->Fill(l1matcheddR->at(secondElectronForZ_),weightPlots);


                double resLead=(leadL1Pt-leadPtreco) / leadPtreco ;
                double resSecond=(secondL1Pt-secondPtreco) / secondPtreco ;
                double resetaLead=leadL1Eta-recoeta->at(leadElectronForZ_);
                double resetaSecond=secondL1Eta-recoeta->at(secondElectronForZ_);
                double resphiLead=leadL1Phi-recophi->at(leadElectronForZ_);
                double resphiSecond=secondL1Phi-recophi->at(secondElectronForZ_);


                if(leadL1Pt>40) {
                        recoBinPtLeadTrig->Fill(leadPtreco,weightPlots); ResLeadPt->Fill(resLead,weightPlots); 
                        ResEtaLeadPt->Fill(resetaLead,weightPlots);  ResPhiLeadPt->Fill(resphiLead,weightPlots); 
                        recoEtaLeadTrig->Fill(recoeta->at(leadElectronForZ_),weightPlots);
                }
                if(secondL1Pt>10) {
                        recoBinPtSecondTrig10->Fill(secondPtreco,weightPlots);
                }
                if(secondL1Pt>15) {
                        recoBinPtSecondTrig15->Fill(secondPtreco,weightPlots);  
                        if(fabs(secondEtareco)<1.5) recoBinPtSecondEBTrig15->Fill(secondPtreco,weightPlots);
                        if(fabs(secondEtareco)>1.5) recoBinPtSecondEETrig15->Fill(secondPtreco,weightPlots);
                        ResSecondPtTrig15->Fill(resSecond,weightPlots);
                        ResEtaSecondPtTrig15->Fill(resetaSecond,weightPlots);  ResPhiSecondPtTrig15->Fill(resphiSecond,weightPlots);
                        if(secondPtreco>25) recoEtaSecondTrig15->Fill(recoeta->at(secondElectronForZ_),weightPlots);
                }
                if(secondL1Pt>20) {
                        recoBinPtSecondTrig20->Fill(secondPtreco,weightPlots);  
                        if(secondPtreco>30) reconvtxSecondTrig20->Fill(nvtx,weightPlots);
                        if(fabs(secondEtareco)<1.5) {recoBinPtSecondEBTrig20->Fill(secondPtreco,weightPlots); ResSecondPtTrig20EB->Fill(resSecond,weightPlots);
                                if(secondPtreco>30) reconvtxSecondEBTrig20->Fill(nvtx,weightPlots);}
                        if(fabs(secondEtareco)>1.5) {recoBinPtSecondEETrig20->Fill(secondPtreco,weightPlots); ResSecondPtTrig20EE->Fill(resSecond,weightPlots);
                                if(secondPtreco>30) reconvtxSecondEETrig20->Fill(nvtx,weightPlots);}
                        ResSecondPtTrig20->Fill(resSecond,weightPlots); 
                        ResEtaSecondPtTrig20->Fill(resetaSecond,weightPlots);  ResPhiSecondPtTrig20->Fill(resphiSecond,weightPlots);
                        if(secondPtreco>30) recoEtaSecondTrig20->Fill(recoeta->at(secondElectronForZ_),weightPlots);
                        ResSecondPtTrig2D->Fill(secondPtreco,resSecond,weightPlots);
                        ResSecondPtTrig2DL1->Fill(secondL1Pt,resSecond,weightPlots);
                        ResSecondPtTrig2DEta->Fill(recoeta->at(secondElectronForZ_),resSecond,weightPlots);
                }
                if(secondL1Pt>25) {
                        recoBinPtSecondTrig25->Fill(secondPtreco,weightPlots);  ResSecondPtTrig25->Fill(resSecond,weightPlots);
                        if(secondPtreco<40 && fabs(secondEtareco)<1.5)  ResSecondPtTrig2540->Fill(resSecond,weightPlots);
                        if(fabs(secondEtareco)<1.5) recoBinPtSecondEBTrig25->Fill(secondPtreco,weightPlots);
                        if(fabs(secondEtareco)>1.5) recoBinPtSecondEETrig25->Fill(secondPtreco,weightPlots);
                        ResEtaSecondPtTrig25->Fill(resetaSecond,weightPlots);  ResPhiSecondPtTrig25->Fill(resphiSecond,weightPlots);
                        if(secondPtreco>35) recoEtaSecondTrig25->Fill(recoeta->at(secondElectronForZ_),weightPlots);
                }
                if(secondL1Pt>30) {
                        recoBinPtSecondTrig30->Fill(secondPtreco,weightPlots);  ResSecondPtTrig30->Fill(resSecond,weightPlots);
                        if(fabs(secondEtareco)<1.5) recoBinPtSecondEBTrig30->Fill(secondPtreco,weightPlots);
                        if(fabs(secondEtareco)>1.5) recoBinPtSecondEETrig30->Fill(secondPtreco,weightPlots);
                        ResEtaSecondPtTrig30->Fill(resetaSecond,weightPlots);  ResPhiSecondPtTrig30->Fill(resphiSecond,weightPlots);
                        if(secondPtreco>40) recoEtaSecondTrig30->Fill(recoeta->at(secondElectronForZ_),weightPlots);
                }
                if(secondL1Pt>35) {
                        recoBinPtSecondTrig35->Fill(secondPtreco,weightPlots);  ResSecondPtTrig35->Fill(resSecond,weightPlots);
                        if(fabs(secondEtareco)<1.5) recoBinPtSecondEBTrig35->Fill(secondPtreco,weightPlots);
                        if(fabs(secondEtareco)>1.5) recoBinPtSecondEETrig35->Fill(secondPtreco,weightPlots);
                        ResEtaSecondPtTrig35->Fill(resetaSecond,weightPlots);  ResPhiSecondPtTrig35->Fill(resphiSecond,weightPlots);
                        if(secondPtreco>45) recoEtaSecondTrig35->Fill(recoeta->at(secondElectronForZ_),weightPlots);
                }

                int countJets=0, countJetsClean=0, leadPtJetCount=-1;
                double leadPtJet=0;
                for (size_t m=0; m<recoJetpt->size(); m++){
                        if (recoJetpt->at(m)<30) continue;
                        countJets++;
                        double dEtaJet=recoJeteta->at(m)-recoeta->at(secondElectronForZ_);
                        double dphiJet=recoJetphi->at(m)-recophi->at(secondElectronForZ_);
                        if (dphiJet > 3.141516) dphiJet -= 2*3.141516;
                        if (dphiJet <= 3.141516) dphiJet += 2*3.141516;
                        double dRJet= sqrt(dEtaJet*dEtaJet+dphiJet*dphiJet);
                        if (dRJet<0.5) continue;

                        dEtaJet=recoJeteta->at(m)-recoeta->at(leadElectronForZ_);
                        dphiJet=recoJetphi->at(m)-recophi->at(leadElectronForZ_);
                        if (dphiJet > 3.141516) dphiJet -= 2*3.141516;
                        if (dphiJet <= 3.141516) dphiJet += 2*3.141516;
                        dRJet= sqrt(dEtaJet*dEtaJet+dphiJet*dphiJet);
                        if (dRJet<0.5) continue;
                        countJetsClean++;
                        if(recoJetpt->at(m)>leadPtJet) leadPtJetCount=m; 

                }


                if(leadPtJetCount!=-1) {
                        hLeadPtJet->Fill(recoJetpt->at(leadPtJetCount),weightPlots);
                        hLeadEtaJet->Fill(recoJeteta->at(leadPtJetCount),weightPlots);
                        int matchJet=recoJetmatches->at(leadPtJetCount);
                        if(matchJet!=-1){
                                hL1LeadMatchedPtJet->Fill(jetpt->at(matchJet),weightPlots);
                                hL1LeadMatchedEtaJet->Fill(jeteta->at(matchJet),weightPlots);	
                                if(jetpt->at(matchJet)>50) {hLeadPtJetTrig50->Fill(recoJetpt->at(leadPtJetCount),weightPlots);}	
                                hResLeadPtJet->Fill(-1+jetpt->at(matchJet)/recoJetpt->at(leadPtJetCount),weightPlots);
                        }
                }
                nJets->Fill(countJets,weightPlots); nJetsClean->Fill(countJetsClean,weightPlots);

                int countJetsL1=0, countJetsCleanL1=0, leadPtJetCountL1=-1;
                double leadPtJetL1=0;
                for (size_t m=0; m<jetpt->size(); m++){
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

        TH1F *effi_PtLead=(TH1F*)recoBinPtLeadTrig->Clone(); 
        effi_PtLead->SetName("effi_PtLead");
        effi_PtLead->Divide(recoBinPtLeadTrig,recoBinPtLead,1,1,"B");

        TH1F *effiHLT_PtLead=(TH1F*)recoBinPtLead->Clone();
        effiHLT_PtLead->SetName("effiHLT_PtLead");
        effiHLT_PtLead->Divide(recoBinPtLead,recoBeforeBinPtLead,1,1,"B");

        TH1F *effi_EtaLead=(TH1F*)recoEtaLeadTrig->Clone();
        effi_EtaLead->SetName("effi_EtaLead");
        effi_EtaLead->Divide(recoEtaLeadTrig,recoEtaLead,1,1,"B");


        TH1F *effi10_PtSecond=(TH1F*)recoBinPtSecondTrig10->Clone();
        effi10_PtSecond->SetName("effi10_PtSecond");
        effi10_PtSecond->Divide(recoBinPtSecondTrig10,recoBinPtSecond,1,1,"B");


        TH1F *effi15_PtSecond=(TH1F*)recoBinPtSecondTrig15->Clone();    
        effi15_PtSecond->SetName("effi15_PtSecond");
        effi15_PtSecond->Divide(recoBinPtSecondTrig15,recoBinPtSecond,1,1,"B");

        TH1F *effi15_PtSecondEB=(TH1F*)recoBinPtSecondEBTrig15->Clone();
        effi15_PtSecondEB->SetName("effi15_PtSecondEB");
        effi15_PtSecondEB->Divide(recoBinPtSecondEBTrig15,recoBinPtSecondEB,1,1,"B");

        TH1F *effi15_PtSecondEE=(TH1F*)recoBinPtSecondEETrig15->Clone();
        effi15_PtSecondEE->SetName("effi15_PtSecondEE");
        effi15_PtSecondEE->Divide(recoBinPtSecondEE);

        TH1F *effi15_EtaSecond=(TH1F*)recoEtaSecondTrig15->Clone();
        effi15_EtaSecond->SetName("effi15_EtaSecond");
        effi15_EtaSecond->Divide(recoEtaSecondr25);

        TH1F *effi20_PtSecond=(TH1F*)recoBinPtSecondTrig20->Clone();
        effi20_PtSecond->SetName("effi20_PtSecond");
        effi20_PtSecond->Divide(recoBinPtSecond);

        TH1F *effi20_PtSecondEB=(TH1F*)recoBinPtSecondEBTrig20->Clone();
        effi20_PtSecondEB->SetName("effi20_PtSecondEB");
        effi20_PtSecondEB->Divide(recoBinPtSecondEB);

        TH1F *effi20_PtSecondEE=(TH1F*)recoBinPtSecondEETrig20->Clone();
        effi20_PtSecondEE->SetName("effi20_PtSecondEE");
        effi20_PtSecondEE->Divide(recoBinPtSecondEE);

        TH1F *effi20_nvtxSecond=(TH1F*)reconvtxSecondTrig20->Clone();
        effi20_nvtxSecond->SetName("effi20_nvtxSecond");
        effi20_nvtxSecond->Divide(reconvtx);

        TH1F *effi20_nvtxSecondEB=(TH1F*)reconvtxSecondEBTrig20->Clone();
        effi20_nvtxSecondEB->SetName("effi20_nvtxSecondEB");
        effi20_nvtxSecondEB->Divide(reconvtxEB);

        TH1F *effi20_nvtxSecondEE=(TH1F*)reconvtxSecondEETrig20->Clone();
        effi20_nvtxSecondEE->SetName("effi20_nvtxSecondEE");
        effi20_nvtxSecondEE->Divide(reconvtxEE);




        TH1F *effi20_EtaSecond=(TH1F*)recoEtaSecondTrig20->Clone();
        effi20_EtaSecond->SetName("effi20_EtaSecond");
        effi20_EtaSecond->Divide(recoEtaSecondr30);

        TH1F *effi25_PtSecond=(TH1F*)recoBinPtSecondTrig25->Clone();
        effi25_PtSecond->SetName("effi25_PtSecond");
        effi25_PtSecond->Divide(recoBinPtSecond);

        TH1F *effi25_PtSecondEB=(TH1F*)recoBinPtSecondEBTrig25->Clone();
        effi25_PtSecondEB->SetName("effi25_PtSecondEB");
        effi25_PtSecondEB->Divide(recoBinPtSecondEB);

        TH1F *effi25_PtSecondEE=(TH1F*)recoBinPtSecondEETrig25->Clone();
        effi25_PtSecondEE->SetName("effi25_PtSecondEE");
        effi25_PtSecondEE->Divide(recoBinPtSecondEE);



        TH1F *effi25_EtaSecond=(TH1F*)recoEtaSecondTrig25->Clone();
        effi25_EtaSecond->SetName("effi25_EtaSecond");
        effi25_EtaSecond->Divide(recoEtaSecondr35);

        TH1F *effi30_PtSecond=(TH1F*)recoBinPtSecondTrig30->Clone();
        effi30_PtSecond->SetName("effi30_PtSecond");
        effi30_PtSecond->Divide(recoBinPtSecond);

        TH1F *effi30_PtSecondEB=(TH1F*)recoBinPtSecondEBTrig30->Clone();
        effi30_PtSecondEB->SetName("effi30_PtSecondEB");
        effi30_PtSecondEB->Divide(recoBinPtSecondEB);

        TH1F *effi30_PtSecondEE=(TH1F*)recoBinPtSecondEETrig30->Clone();
        effi30_PtSecondEE->SetName("effi30_PtSecondEE");
        effi30_PtSecondEE->Divide(recoBinPtSecondEE);


        TH1F *effi30_EtaSecond=(TH1F*)recoEtaSecondTrig30->Clone();
        effi30_EtaSecond->SetName("effi30_EtaSecond");
        effi30_EtaSecond->Divide(recoEtaSecondr40);

        TH1F *effi35_PtSecond=(TH1F*)recoBinPtSecondTrig35->Clone();
        effi35_PtSecond->SetName("effi35_PtSecond");
        effi35_PtSecond->Divide(recoBinPtSecond);

        TH1F *effi35_PtSecondEB=(TH1F*)recoBinPtSecondEBTrig35->Clone();
        effi35_PtSecondEB->SetName("effi35_PtSecondEB");
        effi35_PtSecondEB->Divide(recoBinPtSecondEB);

        TH1F *effi35_PtSecondEE=(TH1F*)recoBinPtSecondEETrig35->Clone();
        effi35_PtSecondEE->SetName("effi35_PtSecondEE");
        effi35_PtSecondEE->Divide(recoBinPtSecondEE);

        TH1F *effi35_EtaSecond=(TH1F*)recoEtaSecondTrig35->Clone();
        effi35_EtaSecond->SetName("effi35_EtaSecond");
        effi35_EtaSecond->Divide(recoEtaSecondr45);


        TH1F *effiHLT_PtSecond=(TH1F*)recoBinPtSecond->Clone();
        effiHLT_PtSecond->SetName("effiHLT_PtSecond");
        effiHLT_PtSecond->Divide(recoBeforeBinPtSecond);

        //cout<<count<<"   ->"<<countw<<"  ->"<<sumall<<endl;

        TFile *output = new TFile(outputFile,"RECREATE");
        output->cd();
        massZ->Write();
        massZL1->Write();
        massZL1V2->Write();

        recoPtSecond->Write();
        recoPtLead->Write();
        l1PtLead->Write();
        l1PtSecond->Write();
        l1PtLeadEB->Write();
        l1PtSecondEB->Write();
        l1PtLeadEE->Write();
        l1PtSecondEE->Write();
        recoBinPtLeadTrig->Write();
        recoBinPtSecond->Write();
        recoBinPtLead->Write();
        effi_PtLead->Write();
        ResLeadPt->Write();
        histonvtx->Write();
        recoEtaLeadTrig->Write();
        recoEtaSecond->Write();
        recoEtaLead->Write();
        effi_EtaLead->Write();
        l1EtaLead->Write();
        l1EtaSecond->Write();
        recoBeforeBinPtSecond->Write();
        recoBeforeBinPtLead->Write();
        effiHLT_PtLead->Write();
        effiHLT_PtSecond->Write();
        recoBinPtSecondTrig15->Write();
        recoBinPtSecondTrig20->Write();
        recoBinPtSecondTrig25->Write();
        recoBinPtSecondTrig30->Write();
        recoBinPtSecondTrig35->Write();
        ResSecondPtTrig15->Write();
        ResSecondPtTrig20->Write();
        ResSecondPtTrig25->Write();
        ResSecondPtTrig30->Write();
        ResSecondPtTrig35->Write();
        effi15_EtaSecond->Write();
        effi20_EtaSecond->Write();
        effi25_EtaSecond->Write();
        effi30_EtaSecond->Write();
        effi35_EtaSecond->Write();
        effi15_PtSecond->Write();
        effi20_PtSecond->Write();
        effi25_PtSecond->Write();
        effi30_PtSecond->Write();
        effi35_PtSecond->Write();

        ResEtaLeadPt->Write();
        ResPhiLeadPt->Write();

        ResPhiSecondPtTrig15->Write();
        ResPhiSecondPtTrig20->Write();
        ResPhiSecondPtTrig25->Write();
        ResPhiSecondPtTrig30->Write();
        ResPhiSecondPtTrig35->Write();

        ResEtaSecondPtTrig15->Write();
        ResEtaSecondPtTrig20->Write();
        ResEtaSecondPtTrig25->Write();
        ResEtaSecondPtTrig30->Write();
        ResEtaSecondPtTrig35->Write();

        l1DRMatchLead->Write();
        l1DRMatchSecond->Write();

        met->Write();
        ResSecondPtTrig2D->Write();
        ResSecondPtTrig2DL1->Write();
        ResSecondPtTrig2DEta->Write();

        effi15_PtSecondEE->Write();
        effi20_PtSecondEE->Write();
        effi25_PtSecondEE->Write();
        effi30_PtSecondEE->Write();
        effi35_PtSecondEE->Write();

        effi15_PtSecondEB->Write();
        effi20_PtSecondEB->Write();
        effi25_PtSecondEB->Write();
        effi30_PtSecondEB->Write();
        effi35_PtSecondEB->Write();

        ResSecondPtTrig2540->Write();

        recoBinPtSecondEB->Write();
        recoBinPtSecondEE->Write();

        recoBinPtSecondTrig15->Write();
        recoBinPtSecondTrig20->Write();
        recoBinPtSecondTrig25->Write();
        recoBinPtSecondTrig30->Write();
        recoBinPtSecondTrig35->Write();

        recoBinPtSecondEBTrig15->Write();
        recoBinPtSecondEBTrig20->Write();
        recoBinPtSecondEBTrig25->Write();
        recoBinPtSecondEBTrig30->Write();
        recoBinPtSecondEBTrig35->Write();

        recoBinPtSecondEETrig15->Write();
        recoBinPtSecondEETrig20->Write();
        recoBinPtSecondEETrig25->Write();
        recoBinPtSecondEETrig30->Write();
        recoBinPtSecondEETrig35->Write();

        ResSecondPtTrig20EB->Write();
        ResSecondPtTrig20EE->Write();


        effi20_nvtxSecondEE->Write();
        effi20_nvtxSecondEB->Write();
        effi20_nvtxSecond->Write();

        massZRes->Write();

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

        effi10_PtSecond->Write();

}
