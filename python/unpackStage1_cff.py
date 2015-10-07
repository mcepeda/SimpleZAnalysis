import FWCore.ParameterSet.Config as cms

from EventFilter.L1TRawToDigi.caloStage1Digis_cfi import caloStage1Digis

caloStage1LegacyFormatDigis = cms.EDProducer(
    "L1TCaloUpgradeToGCTConverter",
    InputCollection = cms.InputTag("caloStage1Digis"),
    InputRlxTauCollection = cms.InputTag("caloStage1Digis:rlxTaus"),
    InputIsoTauCollection = cms.InputTag("caloStage1Digis:isoTaus"),
    InputHFSumsCollection = cms.InputTag("caloStage1Digis:HFRingSums"),
    InputHFCountsCollection = cms.InputTag("caloStage1Digis:HFBitCounts")
)


stage1l1extraParticlesUnpacked = cms.EDProducer("L1ExtraParticlesProd",
    muonSource = cms.InputTag("gtDigis"),
    etTotalSource = cms.InputTag("caloStage1LegacyFormatDigis"),
    nonIsolatedEmSource = cms.InputTag("caloStage1LegacyFormatDigis","nonIsoEm"),
    etMissSource = cms.InputTag("caloStage1LegacyFormatDigis"),
    htMissSource = cms.InputTag("caloStage1LegacyFormatDigis"),
    produceMuonParticles = cms.bool(True),
    forwardJetSource = cms.InputTag("caloStage1LegacyFormatDigis","forJets"),
    centralJetSource = cms.InputTag("caloStage1LegacyFormatDigis","cenJets"),
    produceCaloParticles = cms.bool(True),
    tauJetSource = cms.InputTag("caloStage1LegacyFormatDigis","tauJets"),
    isoTauJetSource = cms.InputTag("caloStage1LegacyFormatDigis","isoTauJets"),
    isolatedEmSource = cms.InputTag("caloStage1LegacyFormatDigis","isoEm"),
    etHadSource = cms.InputTag("caloStage1LegacyFormatDigis"),
    hfRingEtSumsSource = cms.InputTag("caloStage1LegacyFormatDigis"),
    hfRingBitCountsSource = cms.InputTag("caloStage1LegacyFormatDigis"),
    centralBxOnly = cms.bool(True),
    ignoreHtMiss = cms.bool(False)
)

getStage1Digis = cms.Sequence(
      caloStage1Digis
      +caloStage1LegacyFormatDigis
      +stage1l1extraParticlesUnpacked
)


