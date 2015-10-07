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
process.GlobalTag.globaltag = 'GR_P_V56'
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

# GT
from L1Trigger.Configuration.SimL1Emulator_cff import simGtDigis
process.simGtDigis = simGtDigis.clone()
process.simGtDigis.GmtInputTag = 'simGmtDigis'
process.simGtDigis.GctInputTag = 'simCaloStage1LegacyFormatDigis'
process.simGtDigis.TechnicalTriggersInputTags = cms.VInputTag( )

process.load("L1Trigger.SimpleZAnalysis.rerunCALO_cff")
process.load("L1Trigger.SimpleZAnalysis.unpackStage1_cff")
process.load("L1Trigger.SimpleZAnalysis.rerunStage1_cff")

process.caloStage1Params.jetCalibrationLUTFile = cms.FileInPath("L1Trigger/L1TCalorimeter/data/jetCalibrationLUT_stage1_symmetric_Spring15_newRCTv2.txt")
process.caloStage1Params.jetSeedThreshold = cms.double(5.)

process.caloStage1Params.regionPUSParams  = cms.vdouble([0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.500000, 0.500000, 0.500000, 0.500000, 1.000000, 1.000000, 1.500000, 1.500000, 2.000000, 2.500000, 2.500000, 2.500000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.500000, 0.500000, 0.500000, 0.500000, 1.000000, 1.000000, 1.500000, 1.500000, 2.000000, 2.000000, 3.500000, 3.500000, 3.500000, 0.000000, 0.000000, 0.000000, 0.000000, 0.500000, 0.500000, 0.500000, 1.000000, 1.000000, 1.000000, 1.500000, 1.500000, 2.000000, 2.500000, 2.500000, 3.000000, 3.000000, 3.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.500000, 0.500000, 0.500000, 0.500000, 0.500000, 1.000000, 1.000000, 1.000000, 1.500000, 2.000000, 2.000000, 2.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.500000, 0.500000, 0.500000, 0.500000, 1.000000, 1.000000, 1.500000, 2.500000, 5.000000, 5.000000, 5.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.500000, 0.500000, 0.500000, 0.500000, 0.500000, 2.000000, 2.000000, 2.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.500000, 0.500000, 0.500000, 0.500000, 0.500000, 0.500000, 0.500000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.500000, 0.500000, 0.500000, 0.500000, 0.500000, 0.500000, 0.500000, 0.500000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.500000, 0.500000, 0.500000, 0.500000, 0.500000, 0.500000, 1.000000, 1.000000, 2.000000, 2.000000, 2.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.500000, 0.500000, 0.500000, 0.500000, 0.500000, 0.500000, 0.500000, 1.000000, 1.000000, 1.000000, 2.000000, 2.000000, 2.000000, 0.000000, 0.500000, 0.500000, 0.500000, 0.500000, 0.500000, 0.500000, 0.500000, 0.500000, 0.500000, 1.000000, 1.000000, 1.000000, 1.500000, 1.500000, 1.500000, 1.500000, 1.500000, 0.000000, 0.500000, 0.500000, 0.500000, 0.500000, 0.500000, 0.500000, 0.500000, 0.500000, 0.500000, 1.000000, 1.000000, 1.000000, 1.000000, 1.500000, 1.000000, 1.000000, 1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.500000, 0.500000, 0.500000, 0.500000, 0.500000, 0.500000, 0.500000, 1.000000, 1.000000, 1.000000, 2.000000, 2.000000, 2.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.500000, 0.500000, 0.500000, 0.500000, 0.500000, 0.500000, 1.000000, 1.000000, 1.500000, 1.500000, 1.500000, 0.000000, 0.000000, 0.000000, 0.000000, 0.500000, 0.500000, 0.500000, 0.500000, 0.500000, 0.500000, 0.500000, 0.500000, 1.000000, 1.000000, 1.000000, 2.000000, 2.000000, 2.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.500000, 0.500000, 0.500000, 0.500000, 0.500000, 0.500000, 0.500000, 0.500000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.500000, 0.500000, 0.500000, 0.500000, 0.500000, 1.500000, 1.500000, 1.500000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.500000, 0.500000, 0.500000, 0.500000, 1.000000, 1.000000, 2.000000, 2.500000, 3.500000, 3.500000, 3.500000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.500000, 0.500000, 0.500000, 0.500000, 0.500000, 1.000000, 1.000000, 1.000000, 1.500000, 1.500000, 1.500000, 1.500000, 1.500000, 0.000000, 0.000000, 0.000000, 0.000000, 0.500000, 0.500000, 0.500000, 1.000000, 1.000000, 1.000000, 1.500000, 1.500000, 2.000000, 2.500000, 3.000000, 3.000000, 3.000000, 3.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.500000, 0.500000, 0.500000, 0.500000, 1.000000, 1.000000, 1.000000, 1.500000, 1.500000, 2.000000, 2.500000, 2.000000, 2.000000, 2.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.500000, 0.500000, 0.500000, 0.500000, 1.000000, 1.000000, 1.000000, 1.500000, 2.000000, 2.000000, 2.000000, 2.000000, 2.000000])





from L1Trigger.SimpleZAnalysis.patch_metNoHFinMINIAOD_cfi import patch
patch(process)

process.p1 = cms.Path(
    process.reRunL1CALO
    +process.getStage1Digis
    +process.rerunStage1
    +process.rerunMET
    )

process.electronRate = cms.EDAnalyzer(
  "RateTree",
  src = cms.VInputTag(cms.InputTag("l1ExtraLayer2", "Isolated"),cms.InputTag("l1ExtraLayer2", "NonIsolated")),
  srcJet = cms.VInputTag(cms.InputTag("l1ExtraLayer2", "Central"),cms.InputTag("l1ExtraLayer2", "Tau")),
  isUCT = cms.bool(False),
  )

process.electronIsoRate = cms.EDAnalyzer(
  "RateTree",
  src = cms.VInputTag(cms.InputTag("l1ExtraLayer2", "Isolated")),
  srcJet = cms.VInputTag(cms.InputTag("l1ExtraLayer2", "Central"),cms.InputTag("l1ExtraLayer2", "Tau")),
  isUCT = cms.bool(False),
  )

process.electronRateDEFAULT = cms.EDAnalyzer(
  "RateTree",
  src = cms.VInputTag(cms.InputTag("l1extraParticles", "Isolated"),cms.InputTag("l1extraParticles", "NonIsolated")),
  srcJet = cms.VInputTag(cms.InputTag("l1extraParticles", "Central"),cms.InputTag("l1extraParticles", "Tau")),
  isUCT = cms.bool(False),
  )

process.electronIsoRateDEFAULT = cms.EDAnalyzer(
  "RateTree",
  src = cms.VInputTag(cms.InputTag("l1extraParticles", "Isolated")),
  srcJet = cms.VInputTag(cms.InputTag("l1extraParticles", "Central"),cms.InputTag("l1extraParticles", "Tau")),
  isUCT = cms.bool(False),
  )

process.effitreeWZ = cms.EDAnalyzer("WZEffiTree",
     src = cms.VInputTag(cms.InputTag("l1ExtraLayer2", "Isolated"),cms.InputTag("l1ExtraLayer2", "NonIsolated")),
     recoSrcJet=cms.VInputTag(cms.InputTag("slimmedJets")),
     srcJet = cms.VInputTag(cms.InputTag("l1ExtraLayer2", "Central"),cms.InputTag("l1ExtraLayer2", "Forward")),
     metSrc=cms.VInputTag(cms.InputTag("l1ExtraLayer2", "MET")),
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
     src = cms.VInputTag(cms.InputTag("l1ExtraLayer2", "Isolated")),
     recoSrcJet=cms.VInputTag(cms.InputTag("slimmedJets")),
     srcJet = cms.VInputTag(cms.InputTag("l1ExtraLayer2", "Central"),cms.InputTag("l1ExtraLayer2", "Forward")),
     metSrc=cms.VInputTag(cms.InputTag("l1ExtraLayer2", "MET")),
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

process.effitreeWZGCTDEFAULT = cms.EDAnalyzer("WZEffiTree",
     src = cms.VInputTag(cms.InputTag("gctl1extraParticles", "Isolated"),cms.InputTag("gctl1extraParticles", "NonIsolated")),
     recoSrcJet=cms.VInputTag(cms.InputTag("slimmedJets")),
     srcJet = cms.VInputTag(cms.InputTag("gctl1extraParticles", "Central"),cms.InputTag("gctl1extraParticles", "Tau"),cms.InputTag("gctl1extraParticles", "Forward")),
     metSrc=cms.VInputTag(cms.InputTag("gctl1extraParticles", "MET")),
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

process.effitreeWZGCTDEFAULTIso = cms.EDAnalyzer("WZEffiTree",
     src = cms.VInputTag(cms.InputTag("gctl1extraParticles", "Isolated")),
     recoSrcJet=cms.VInputTag(cms.InputTag("slimmedJets")),
     srcJet = cms.VInputTag(cms.InputTag("gctl1extraParticles", "Central"),cms.InputTag("gctl1extraParticles", "Tau"),cms.InputTag("gctl1extraParticles", "Forward")),
     metSrc=cms.VInputTag(cms.InputTag("gctl1extraParticles", "MET")),
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



process.effitreeWZDEFAULT = cms.EDAnalyzer("WZEffiTree",
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

process.effitreeWZIsoDEFAULT = cms.EDAnalyzer("WZEffiTree",
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



process.p4=cms.Path(process.electronRate*process.electronIsoRate*process.electronRateDEFAULT*process.electronIsoRateDEFAULT)

from PhysicsTools.SelectorUtils.tools.vid_id_tools import *
dataFormat = DataFormat.MiniAOD

switchOnVIDElectronIdProducer(process, dataFormat)

# define which IDs we want to produce
my_id_modules = ['RecoEgamma.ElectronIdentification.Identification.cutBasedElectronID_Spring15_25ns_V1_cff']

#add them to the VID producer
for idmod in my_id_modules:
    setupAllVIDIdsInModule(process,idmod,setupVIDElectronSelection)


process.dummy = cms.EDAnalyzer("Dummy")

process.p5=cms.Path(process.egmGsfElectronIDSequence*process.effitreeWZ*process.effitreeWZIso*process.effitreeWZDEFAULT*process.effitreeWZIsoDEFAULT)

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


def dasQuery(queryString, entryTitle) :
    import das_client
    dasinfo = das_client.get_data('https://cmsweb.cern.ch', queryString, 0, 0, False)
    if dasinfo['status'] != 'ok' :
        raise Exception('DAS query failed.\nQuery: %s\nDAS Status returned: %s' % (queryString, dasinfo['status']))

    for entry in dasinfo['data'] :
        if len(entry[entryTitle]) > 0 :
            yield entry[entryTitle][0]

def getSecondaryFiles(primaryFileList) :
    import re
    secondaryFiles = []
    for primaryFile in primaryFileList :
        lfn = re.search('/store/.*', primaryFile).group()
        query = 'parent file=%s' % lfn
        for entry in dasQuery(query, 'parent') :
            secondaryFiles.append(entry['name'].encode('ascii','ignore'))
    print secondaryFiles  
    return secondaryFiles

process.source.secondaryFileNames = cms.untracked.vstring(getSecondaryFiles(process.source.fileNames))

import FWCore.PythonUtilities.LumiList as LumiList
#process.source.lumisToProcess = LumiList.LumiList(filename = '/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/Cert_246908-256869_13TeV_PromptReco_Collisions15_25ns_JSON.txt').getVLuminosityBlockRange()
process.source.lumisToProcess = LumiList.LumiList(filename = '/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/Cert_246908-257599_13TeV_PromptReco_Collisions15_25ns_JSON.txt').getVLuminosityBlockRange()


# Spit out filter efficiency at the end.
process.options = cms.untracked.PSet(wantSummary = cms.untracked.bool(False))
