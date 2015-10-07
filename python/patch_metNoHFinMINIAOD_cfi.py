#
# This is a patch that allows to reconstruct the MET without the HF.
#
# Written by Oscar Gonzalez (2015_08_10) from the official example

import FWCore.ParameterSet.Config as cms

from PhysicsTools.PatAlgos.tools.jetTools import *


def patch (process):
    '''Method to patch the MET and use the one without HF'''

    # Candidates excluding HF
    process.noHFCands = cms.EDFilter("CandPtrSelector",
                                     src=cms.InputTag("packedPFCandidates"),
                                     cut=cms.string("abs(pdgId)!=1 && abs(pdgId)!=2 && abs(eta)<3.0")
                                     #cut=cms.string("abs(eta)<1000.0")
                                     )

    # Computing the MET
    from PhysicsTools.PatUtils.tools.runMETCorrectionsAndUncertainties import runMetCorAndUncFromMiniAOD

    runMetCorAndUncFromMiniAOD(process,
                               isData=True,  # NOTE!!!
                               pfCandColl=cms.InputTag("noHFCands"),
                               postfix="NoHF"
                               )
    process.patJetCorrFactorsNoHF.levels = cms.vstring('L1FastJet', 'L2Relative', 'L3Absolute')

    # Remove for data the residual corrections:

    process.patPFMetT1T2CorrNoHF.jetCorrLabelRes = cms.InputTag("L3Absolute")
    process.patPFMetT1T2SmearCorrNoHF.jetCorrLabelRes = cms.InputTag("L3Absolute")
    process.patPFMetT2CorrNoHF.jetCorrLabelRes = cms.InputTag("L3Absolute")
    process.patPFMetT2SmearCorrNoHF.jetCorrLabelRes = cms.InputTag("L3Absolute")
    process.shiftedPatJetEnDownNoHF.jetCorrLabelUpToL3Res = cms.InputTag("ak4PFCHSL1FastL2L3Corrector")
    process.shiftedPatJetEnUpNoHF.jetCorrLabelUpToL3Res = cms.InputTag("ak4PFCHSL1FastL2L3Corrector")
    print "WARNING!!!!! Using MC corrections also for MET in MINIAOD data"

    # Adding the relevant modules to the path

    process.rerunMET = cms.Sequence(process.noHFCands
                                   *process.pfCHSNoHF
                                   *process.ak4PFJetsCHSNoHF
                                   *process.patJetCorrFactorsNoHF
                                   *process.patJetsNoHF
                                   *process.selectedPatJetsNoHF
                                   *process.pfMetNoHF
                                   *process.patPFMetNoHF
                                   *process.ak4PFCHSL1FastjetCorrector
                                   *process.ak4PFCHSL2RelativeCorrector
                                   *process.ak4PFCHSL3AbsoluteCorrector
                                   *process.ak4PFCHSL1FastL2L3Corrector
                                   *process.patPFMetT1T2CorrNoHF
                                   *process.patPFMetT1NoHF

                                   *process.shiftedPatJetEnUpNoHF
                                   *process.shiftedPatJetEnDownNoHF
                                   *process.shiftedPatMETCorrJetEnUpNoHF
                                   *process.shiftedPatMETCorrJetEnDownNoHF
                                   *process.patPFMetT1JetEnUpNoHF
                                   *process.patPFMetT1JetEnDownNoHF

                                   *process.shiftedPatMuonEnUpNoHF
                                   *process.shiftedPatMETCorrMuonEnUpNoHF
                                   *process.patPFMetT1MuonEnUpNoHF

                                   *process.shiftedPatMuonEnDownNoHF
                                   *process.shiftedPatMETCorrMuonEnDownNoHF
                                   *process.patPFMetT1MuonEnDownNoHF

                                   *process.shiftedPatElectronEnUpNoHF
                                   *process.shiftedPatMETCorrElectronEnUpNoHF
                                   *process.patPFMetT1ElectronEnUpNoHF

                                   *process.shiftedPatElectronEnDownNoHF
                                   *process.shiftedPatMETCorrElectronEnDownNoHF
                                   *process.patPFMetT1ElectronEnDownNoHF

                                   *process.shiftedPatTauEnUpNoHF
                                   *process.shiftedPatMETCorrTauEnUpNoHF
                                   *process.patPFMetT1TauEnUpNoHF

                                   *process.shiftedPatTauEnDownNoHF
                                   *process.shiftedPatMETCorrTauEnDownNoHF
                                   *process.patPFMetT1TauEnDownNoHF

                                   *process.patPFMetT2CorrNoHF

                                   *process.patPFMetT2CorrUnclusteredEnUpNoHF
                                   *process.patPFMetT1UnclusteredEnUpNoHF

                                   *process.patPFMetT2CorrUnclusteredEnDownNoHF
                                   *process.patPFMetT1UnclusteredEnDownNoHF

                                   *getattr(process,"slimmedMETsNoHF")
                                   )

#    process.CMSTREE.MetTag = cms.untracked.InputTag("slimmedMETsNoHF")

#########################################################################
