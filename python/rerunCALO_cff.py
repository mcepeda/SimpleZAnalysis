import FWCore.ParameterSet.Config as cms

from Configuration.StandardSequences.RawToDigi_cff import hcalDigis
from Configuration.StandardSequences.RawToDigi_cff import ecalDigis
from Configuration.StandardSequences.RawToDigi_cff import gctDigis
from Configuration.StandardSequences.RawToDigi_cff import scalersRawToDigi
from L1Trigger.Configuration.SimL1Emulator_cff import simRctDigis
from L1Trigger.Configuration.SimL1Emulator_cff import simGctDigis
from L1Trigger.L1ExtraFromDigis.l1extraParticles_cfi import l1extraParticles
from SimCalorimetry.HcalTrigPrimProducers.hcaltpdigi_cff import *

HcalTPGCoderULUT.LUTGenerationMode = cms.bool(True)

simRctDigis.ecalDigis = cms.VInputTag( cms.InputTag( 'ecalDigis:EcalTriggerPrimitives' ) )
simRctDigis.hcalDigis = cms.VInputTag( cms.InputTag( 'hcalDigis' ) )
simGctDigis.inputLabel = 'simRctDigis'

simgctl1extraParticles = cms.EDProducer("L1ExtraParticlesProd",
    muonSource = cms.InputTag("gtDigis"),
    etTotalSource = cms.InputTag("simGctDigis"),
    nonIsolatedEmSource = cms.InputTag("simGctDigis","nonIsoEm"),
    etMissSource = cms.InputTag("simGctDigis"),
    htMissSource = cms.InputTag("simGctDigis"),
    produceMuonParticles = cms.bool(True),
    forwardJetSource = cms.InputTag("simGctDigis","forJets"),
    centralJetSource = cms.InputTag("simGctDigis","cenJets"),
    produceCaloParticles = cms.bool(True),
    tauJetSource = cms.InputTag("simGctDigis","tauJets"),
    isoTauJetSource = cms.InputTag("simGctDigis","isoTauJets"),
    isolatedEmSource = cms.InputTag("simGctDigis","isoEm"),
    etHadSource = cms.InputTag("simGctDigis"),
    hfRingEtSumsSource = cms.InputTag("simGctDigis"),
    hfRingBitCountsSource = cms.InputTag("simGctDigis"),
    centralBxOnly = cms.bool(True),
    ignoreHtMiss = cms.bool(False)
)

gctl1extraParticles = cms.EDProducer("L1ExtraParticlesProd",
    muonSource = cms.InputTag("gtDigis"),
    etTotalSource = cms.InputTag("gctDigis"),
    nonIsolatedEmSource = cms.InputTag("gctDigis","nonIsoEm"),
    etMissSource = cms.InputTag("gctDigis"),
    htMissSource = cms.InputTag("gctDigis"),
    produceMuonParticles = cms.bool(True),
    forwardJetSource = cms.InputTag("gctDigis","forJets"),
    centralJetSource = cms.InputTag("gctDigis","cenJets"),
    produceCaloParticles = cms.bool(True),
    tauJetSource = cms.InputTag("gctDigis","tauJets"),
    isoTauJetSource = cms.InputTag("gctDigis","isoTauJets"),
    isolatedEmSource = cms.InputTag("gctDigis","isoEm"),
    etHadSource = cms.InputTag("gctDigis"),
    hfRingEtSumsSource = cms.InputTag("gctDigis"),
    hfRingBitCountsSource = cms.InputTag("gctDigis"),
    centralBxOnly = cms.bool(True),
    ignoreHtMiss = cms.bool(False)
)

reRunL1CALO = cms.Sequence(
    ecalDigis
    +hcalDigis
    +simRctDigis
    +simGctDigis
    +simgctl1extraParticles
    +gctDigis  
    +gctl1extraParticles
    +scalersRawToDigi
)


