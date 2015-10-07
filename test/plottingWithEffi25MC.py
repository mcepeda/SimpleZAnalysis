import FWCore.ParameterSet.Config as cms

process = cms.Process('L1TEMULATION')

process.load('Configuration.StandardSequences.Services_cff')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')
process.load('Configuration.EventContent.EventContent_cff')
process.load('Configuration.Geometry.GeometryIdeal_cff')
process.load("Geometry.CMSCommonData.cmsIdealGeometryXML_cfi")

# Select the Message Logger output you would like to see:
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('L1Trigger.L1TCalorimeter.caloConfigStage1PP_cfi')
process.load('L1Trigger.L1TCalorimeter.L1TCaloStage1_PPFromRaw_cff')

process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_condDBv2_cff')
process.GlobalTag.globaltag = 'MCRUN2_74_V9'
#check https://twiki.cern.ch/twiki/bin/view/CMSPublic/SWGuideFrontierConditions?redirectedfrom=CMS.SWGuideFrontierConditions#Global_Tags_for_2015_first_beams
# UNCOMMENT THIS LINE TO RUN ON SETTINGS FROM THE DATABASE
process.es_prefer_GlobalTag = cms.ESPrefer('PoolDBESSource', 'GlobalTag')

import os

# Get command line options
from FWCore.ParameterSet.VarParsing import VarParsing
options = VarParsing ('analysis')
options.outputFile = "test.root"

options.parseArguments()

process.maxEvents = cms.untracked.PSet(
   input = cms.untracked.int32(options.maxEvents)
   )


# Input source
process.source = cms.Source("PoolSource",
    secondaryFileNames = cms.untracked.vstring(),
    fileNames = cms.untracked.vstring(options.inputFiles)
    )


process.output = cms.OutputModule(
    "PoolOutputModule",
    splitLevel = cms.untracked.int32(0),
    eventAutoFlushCompressedSize = cms.untracked.int32(5242880),
    outputCommands = cms.untracked.vstring('keep *'),
    fileName = cms.untracked.string('SimL1Emulator_Stage1_PP.root'),
    dataset = cms.untracked.PSet(
        filterName = cms.untracked.string(''),
        dataTier = cms.untracked.string('')
    )
                                           )
process.options = cms.untracked.PSet()


from L1Trigger.SimpleZAnalysis.patch_metNoHFinMINIAOD_cfi import patch
patch(process)

process.p1 = cms.Path(
    process.rerunMET
    )

process.effitreeWZ = cms.EDAnalyzer("WZEffiTree",
     isMC=cms.untracked.bool(True),
     src = cms.VInputTag(cms.InputTag("l1extraParticles", "Isolated"),cms.InputTag("l1extraParticles", "NonIsolated")),
     recoSrcJet=cms.VInputTag(cms.InputTag("slimmedJets")),
     srcJet = cms.VInputTag(cms.InputTag("l1extraParticles", "Central"),cms.InputTag("l1extraParticles", "Forward")),
     metSrc=cms.VInputTag(cms.InputTag("l1extraParticles", "MET")),
     recoMetSrc=cms.VInputTag(cms.InputTag("slimmedMETsNoHF")),   # genMetTrue
                                 eleLooseIdMap = cms.InputTag("egmGsfElectronIDs:cutBasedElectronID-Spring15-25ns-V1-standalone-loose"),
                                 eleMediumIdMap = cms.InputTag("egmGsfElectronIDs:cutBasedElectronID-Spring15-25ns-V1-standalone-medium"),
                                 eleTightIdMap = cms.InputTag("egmGsfElectronIDs:cutBasedElectronID-Spring15-25ns-V1-standalone-tight"),
electronsMiniAOD = cms.InputTag("slimmedElectrons"),
              verticesMiniAOD     = cms.InputTag("offlineSlimmedPrimaryVertices"),
                                 conversionsMiniAOD  = cms.InputTag('reducedEgamma:reducedConversions'),
       beamSpot = cms.InputTag('offlineBeamSpot'),
    bits = cms.InputTag("TriggerResults","","HLT"),
    prescales = cms.InputTag("patTrigger"),
    objects = cms.InputTag("selectedPatTrigger"),
)

process.effitreeWZIso = cms.EDAnalyzer("WZEffiTree",
     isMC=cms.untracked.bool(True),
     src = cms.VInputTag(cms.InputTag("l1extraParticles", "Isolated")),
     recoSrcJet=cms.VInputTag(cms.InputTag("slimmedJets")),
     srcJet = cms.VInputTag(cms.InputTag("l1extraParticles", "Central"),cms.InputTag("l1extraParticles", "Forward")),
     metSrc=cms.VInputTag(cms.InputTag("l1extraParticles", "MET")),
     recoMetSrc=cms.VInputTag(cms.InputTag("slimmedMETsNoHF")),   # genMetTrue
                                 eleLooseIdMap = cms.InputTag("egmGsfElectronIDs:cutBasedElectronID-Spring15-25ns-V1-standalone-loose"),
                                 eleMediumIdMap = cms.InputTag("egmGsfElectronIDs:cutBasedElectronID-Spring15-25ns-V1-standalone-medium"),
                                 eleTightIdMap = cms.InputTag("egmGsfElectronIDs:cutBasedElectronID-Spring15-25ns-V1-standalone-tight"),
electronsMiniAOD = cms.InputTag("slimmedElectrons"),
              verticesMiniAOD     = cms.InputTag("offlineSlimmedPrimaryVertices"),
                                 conversionsMiniAOD  = cms.InputTag('reducedEgamma:reducedConversions'),
       beamSpot = cms.InputTag('offlineBeamSpot'),
    bits = cms.InputTag("TriggerResults","","HLT"),
    prescales = cms.InputTag("patTrigger"),
    objects = cms.InputTag("selectedPatTrigger"),
)

from PhysicsTools.SelectorUtils.tools.vid_id_tools import *
dataFormat = DataFormat.MiniAOD

switchOnVIDElectronIdProducer(process, dataFormat)

# define which IDs we want to produce
my_id_modules = ['RecoEgamma.ElectronIdentification.Identification.cutBasedElectronID_Spring15_25ns_V1_cff']

#add them to the VID producer
for idmod in my_id_modules:
    setupAllVIDIdsInModule(process,idmod,setupVIDElectronSelection)


process.dummy = cms.EDAnalyzer("Dummy")

process.p5=cms.Path(process.egmGsfElectronIDSequence*process.effitreeWZ*process.effitreeWZIso)

process.output_step = cms.EndPath(process.output)

process.l1RCTParametersTest = cms.EDAnalyzer("L1RCTParametersTester")

process.p7=cms.Path(process.l1RCTParametersTest)

process.schedule = cms.Schedule(
    process.p1, process.p5#, process.output_step
    )

process.TFileService = cms.Service(
  "TFileService",
  fileName = cms.string(options.outputFile)
  )

# Spit out filter efficiency at the end.
process.options = cms.untracked.PSet(wantSummary = cms.untracked.bool(False))
