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

process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_condDBv2_cff')
process.GlobalTag.globaltag = 'GR_P_V56'
#check https://twiki.cern.ch/twiki/bin/view/CMSPublic/SWGuideFrontierConditions?redirectedfrom=CMS.SWGuideFrontierConditions#Global_Tags_for_2015_first_beams
# UNCOMMENT THIS LINE TO RUN ON SETTINGS FROM THE DATABASE
process.es_prefer_GlobalTag = cms.ESPrefer('PoolDBESSource', 'GlobalTag')

import os

# Get command line options
from FWCore.ParameterSet.VarParsing import VarParsing
options = VarParsing ('analysis')
options.outputFile = "RATE.root"

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
    outputCommands = cms.untracked.vstring('drop *',
                                           'keep *_*_*_L1TEMULATION'),
    fileName = cms.untracked.string('SimL1Emulator_Stage1_PP.root'),
    dataset = cms.untracked.PSet(
        filterName = cms.untracked.string(''),
        dataTier = cms.untracked.string('')
    )
                                           )
process.options = cms.untracked.PSet()

process.load("L1Trigger.SimpleZAnalysis.rerunCALO_cff")
process.load("L1Trigger.SimpleZAnalysis.unpackStage1_cff")
process.load("L1Trigger.SimpleZAnalysis.rerunStage1_cff")

#process.caloStage1Params.jetCalibrationLUTFile = cms.FileInPath("L1Trigger/L1TCalorimeter/data/jetCalibrationLUT_stage1_symmetric_LAURA.txt")
process.caloStage1Params.jetCalibrationLUTFile = cms.FileInPath("L1Trigger/L1TCalorimeter/data/jetCalibrationLUT_stage1_symmetric_Spring15_newRCTv2.txt")
process.caloStage1Params.jetSeedThreshold = cms.double(5.)

process.caloStage1Params.regionPUSParams  = cms.vdouble(0.000526, 0.017403, 0.068487, 0.130059, 0.210714, 0.305371, 0.414596, 0.541782, 0.688259, 0.850227, 1.029244, 1.231508, 1.466828, 1.704281, 1.993464, 2.145833, 2.472222, 2.472222, 0.001257, 0.031867, 0.113854, 0.195662, 0.292358, 0.401044, 0.523185, 0.663854, 0.824215, 1.002329, 1.204471, 1.432883, 1.688452, 1.953722, 2.295207, 2.743056, 2.833333, 2.833333, 0.001964, 0.055337, 0.182034, 0.299277, 0.424801, 0.558997, 0.706456, 0.875220, 1.063389, 1.279351, 1.524954, 1.796661, 2.105826, 2.430136, 2.858388, 3.138889, 3.333333, 3.333333, 0.002678, 0.037122, 0.104117, 0.160784, 0.223480, 0.290001, 0.364018, 0.450532, 0.550502, 0.669485, 0.805136, 0.960249, 1.133714, 1.320870, 1.540305, 1.798611, 1.972222, 1.972222, 0.003250, 0.023175, 0.058470, 0.089567, 0.124847, 0.165843, 0.216983, 0.284882, 0.376798, 0.509589, 0.702461, 0.995051, 1.404938, 1.994634, 2.949891, 3.611111, 4.500000, 4.500000, 0.003422, 0.017924, 0.036881, 0.052876, 0.069950, 0.088463)+cms.vdouble( 0.109330, 0.135071, 0.166923, 0.209008, 0.262798, 0.336487, 0.446568, 0.566901, 0.754357, 0.777778, 1.555556, 1.555556, 0.034187, 0.069745, 0.108466, 0.139486, 0.166670, 0.199390, 0.233235, 0.272109, 0.318168, 0.375941, 0.446455, 0.532498, 0.640793, 0.744243, 0.910131, 2.020833, 1.055556, 1.055556, 0.056148, 0.105299, 0.150827, 0.188907, 0.223063, 0.258147, 0.299061, 0.345056, 0.400637, 0.466768, 0.545796, 0.637606, 0.762998, 0.887044, 1.044118, 1.118056, 1.277778, 1.277778, 0.021649, 0.057739, 0.098916, 0.127276, 0.160659, 0.193319, 0.230757, 0.273676, 0.327265, 0.391194, 0.466433, 0.562264, 0.672928, 0.808406, 0.989107, 1.375000, 1.444444, 1.444444, 0.032915, 0.074009, 0.115342, 0.148855, 0.183883, 0.222639, 0.262186, 0.308542, 0.366830, 0.435994, 0.523824, 0.630281, 0.739126, 0.908004, 1.179739, 1.291667, 1.111111, 1.111111, 0.115518, 0.190160, 0.223516, 0.264020, 0.304201, 0.347608, 0.396224, 0.448680, 0.514882, 0.592152, 0.691747, 0.804402, 0.946251, 1.110832, 1.391612, 1.597222, 1.277778, 1.277778, 0.119950, 0.196752, 0.227158, 0.267566, 0.306491, 0.350720, 0.396512, 0.447451, 0.511393, 0.594756, 0.691346, 0.811540, 0.937488, 1.103734, 1.366013, 1.750000, 1.666667, 1.666667, 0.032174, 0.073576, 0.113430, 0.148924, 0.179500, 0.216614, 0.257066, 0.300935, 0.358698, 0.424280, 0.507278, 0.614627, 0.746546, 0.880561, 1.022331, 1.618056, 1.027778, 1.027778, 0.017027, 0.050969, 0.092308, 0.122088, 0.154019)+cms.vdouble(0.184328, 0.222451, 0.265130, 0.315396, 0.379205, 0.453752, 0.548108, 0.658502, 0.785547, 0.901961, 1.527778, 2.472222, 2.472222, 0.064580, 0.118812, 0.162619, 0.198511, 0.236371, 0.271764, 0.310944, 0.356325, 0.412592, 0.476385, 0.555414, 0.650181, 0.775264, 0.908562, 1.112200, 1.076389, 2.944444, 2.944444, 0.050222, 0.090291, 0.129639, 0.160353, 0.192120, 0.223122, 0.258358, 0.299527, 0.345118, 0.403947, 0.475473, 0.564182, 0.669108, 0.773307, 0.988017, 1.076389, 1.194444, 1.194444, 0.002741, 0.016214, 0.035791, 0.051948, 0.066302, 0.086004, 0.105546, 0.130378, 0.161912, 0.201268, 0.253497, 0.325936, 0.424600, 0.549184, 0.739107, 0.993056, 1.777778, 1.777778, 0.002810, 0.023346, 0.059369, 0.090986, 0.126045, 0.169191, 0.221306, 0.291665, 0.385077, 0.519508, 0.719403, 1.006666, 1.436780, 2.062765, 2.801198, 3.993056, 3.972222, 3.972222, 0.002557, 0.035010, 0.099437, 0.156342, 0.213238, 0.279638, 0.352482, 0.437963, 0.534227, 0.649994, 0.784861, 0.926393, 1.087385, 1.287838, 1.528867, 1.923611, 1.583333, 1.583333, 0.001964, 0.053240, 0.174141, 0.287589, 0.408102, 0.538587, 0.687458, 0.851668, 1.038660, 1.252526, 1.496511, 1.764371, 2.056983, 2.349765, 2.807190, 3.430556, 3.361111, 3.361111, 0.001106, 0.032508, 0.112457, 0.196008, 0.292320, 0.398626, 0.524290, 0.664652, 0.825759, 1.005843, 1.213059, 1.435589, 1.684693, 1.975352, 2.354575, 2.500000, 2.694444, 2.694444, 0.000553, 0.017785, 0.070969, 0.134381, 0.211074, 0.305795, 0.417541, 0.545416, 0.689293, 0.850767, 1.037602, 1.238156, 1.453073, 1.729600, 1.994553, 2.062500, 2.527778, 2.527778)


#process.caloStage1Params.etSumEtThreshold = cms.vdouble(0., 14.) 

process.p1 = cms.Path(
    process.reRunL1CALO
    +process.getStage1Digis
    +process.rerunStage1
    )

process.electronRateUnpacked = cms.EDAnalyzer(
  "RateTree",
  src = cms.VInputTag(cms.InputTag("stage1l1extraParticlesUnpacked", "Isolated"),cms.InputTag("stage1l1extraParticlesUnpacked", "NonIsolated")),
  srcJet = cms.VInputTag(cms.InputTag("stage1l1extraParticlesUnpacked", "Central")),
  isUCT = cms.bool(False),
  )

process.electronIsoRateUnpacked = cms.EDAnalyzer(
  "RateTree",
  src = cms.VInputTag(cms.InputTag("stage1l1extraParticlesUnpacked", "Isolated")),
  srcJet = cms.VInputTag(cms.InputTag("stage1l1extraParticlesUnpacked", "Central")),
  isUCT = cms.bool(False),
  )

process.electronRate = cms.EDAnalyzer(
  "RateTree",
  src = cms.VInputTag(cms.InputTag("l1ExtraLayer2", "Isolated"),cms.InputTag("l1ExtraLayer2", "NonIsolated")),
  srcJet = cms.VInputTag(cms.InputTag("l1ExtraLayer2", "Central")),
  isUCT = cms.bool(False),
  )

process.electronIsoRate = cms.EDAnalyzer(
  "RateTree",
  src = cms.VInputTag(cms.InputTag("l1ExtraLayer2", "Isolated")),
  srcJet = cms.VInputTag(cms.InputTag("l1ExtraLayer2", "Central")),
  isUCT = cms.bool(False),
  )


process.electronRateGCTUnpacked = cms.EDAnalyzer(
  "RateTree",
  src = cms.VInputTag(cms.InputTag("gctl1extraParticles", "Isolated"),cms.InputTag("gctl1extraParticles", "NonIsolated")),
  srcJet = cms.VInputTag(cms.InputTag("gctl1extraParticles", "Central"),cms.InputTag("gctl1extraParticles", "Tau")),
  isUCT = cms.bool(False),
  )

process.electronIsoRateGCTUnpacked = cms.EDAnalyzer(
  "RateTree",
  src = cms.VInputTag(cms.InputTag("gctl1extraParticles", "Isolated")),
  srcJet = cms.VInputTag(cms.InputTag("gctl1extraParticles", "Central"),cms.InputTag("gctl1extraParticles", "Tau")),
  isUCT = cms.bool(False),
  )



process.electronRateGCT = cms.EDAnalyzer(
  "RateTree",
  src = cms.VInputTag(cms.InputTag("simgctl1extraParticles", "Isolated"),cms.InputTag("simgctl1extraParticles", "NonIsolated")),
  srcJet = cms.VInputTag(cms.InputTag("simgctl1extraParticles", "Central"),cms.InputTag("simgctl1extraParticles", "Tau")),
  isUCT = cms.bool(False),
  )

process.electronIsoRateGCT = cms.EDAnalyzer(
  "RateTree",
  src = cms.VInputTag(cms.InputTag("simgctl1extraParticles", "Isolated")),
  srcJet = cms.VInputTag(cms.InputTag("simgctl1extraParticles", "Central"),cms.InputTag("simgctl1extraParticles", "Tau")),
  isUCT = cms.bool(False),
  )

process.centralJetRateGCT = cms.EDAnalyzer(
  "RateTree",
  src = cms.VInputTag(cms.InputTag("simgctl1extraParticles", "Central"),cms.InputTag("simgctl1extraParticles", "Tau")),
  srcJet = cms.VInputTag(cms.InputTag("simgctl1extraParticles", "Central"),cms.InputTag("simgctl1extraParticles", "Tau")),
  isUCT = cms.bool(False),
  )


process.centralJetRate = cms.EDAnalyzer(
  "RateTree",
  src = cms.VInputTag(cms.InputTag("l1ExtraLayer2", "Central")),
  srcJet = cms.VInputTag(cms.InputTag("l1ExtraLayer2", "Central")),
  isUCT = cms.bool(False),
  )


process.centralJetRateUnpacked = cms.EDAnalyzer(
  "RateTree",
  src = cms.VInputTag(cms.InputTag("stage1l1extraParticlesUnpacked", "Central")),
  srcJet = cms.VInputTag(cms.InputTag("stage1l1extraParticlesUnpacked", "Central")),
  isUCT = cms.bool(False),
  )

process.allJetRateGCT = cms.EDAnalyzer(
  "RateTree",
  src = cms.VInputTag(cms.InputTag("simgctl1extraParticles", "Central"),cms.InputTag("simgctl1extraParticles", "Tau"),cms.InputTag("simgctl1extraParticles", "Forward")),
  srcJet = cms.VInputTag(cms.InputTag("simgctl1extraParticles", "Central"),cms.InputTag("simgctl1extraParticles", "Tau"),cms.InputTag("simgctl1extraParticles", "Forward")),
  isUCT = cms.bool(False),
  )


process.allJetRate = cms.EDAnalyzer(
  "RateTree",
  src = cms.VInputTag(cms.InputTag("l1ExtraLayer2", "Central"),cms.InputTag("l1ExtraLayer2", "Forward")),
  srcJet = cms.VInputTag(cms.InputTag("l1ExtraLayer2", "Central"),cms.InputTag("l1ExtraLayer2", "Forward")),
  isUCT = cms.bool(False),
  )


process.allJetRateUnpacked = cms.EDAnalyzer(
  "RateTree",
  src = cms.VInputTag(cms.InputTag("stage1l1extraParticlesUnpacked", "Central"),cms.InputTag("stage1l1extraParticlesUnpacked", "Forward")),
  srcJet = cms.VInputTag(cms.InputTag("stage1l1extraParticlesUnpacked", "Central"),cms.InputTag("stage1l1extraParticlesUnpacked", "Forward")),
  isUCT = cms.bool(False),
  )


process.p4=cms.Path(process.electronRate*process.electronIsoRate*process.electronRateUnpacked*process.electronIsoRateUnpacked*process.electronRateGCT*process.electronIsoRateGCT*process.electronRateGCTUnpacked*process.electronIsoRateGCTUnpacked*process.centralJetRateGCT*process.centralJetRate*process.centralJetRateUnpacked*process.allJetRateGCT*process.allJetRate*process.allJetRateUnpacked)

process.output_step = cms.EndPath(process.output)

process.l1RCTParametersTest = cms.EDAnalyzer("L1RCTParametersTester")

process.p7=cms.Path(process.l1RCTParametersTest)

process.sumsL1Rates = cms.EDAnalyzer(
    "SumsRateTree",
    l1MHTSrc = cms.InputTag("l1ExtraLayer2", "MHT"),
    l1METSrc = cms.InputTag("l1ExtraLayer2", "MET"),
    l1SHTSrc = cms.InputTag("l1ExtraLayer2", "MHT"),
    l1SETSrc = cms.InputTag("l1ExtraLayer2", "MET"),
)

process.sumsL1RatesUnpacked = cms.EDAnalyzer(
    "SumsRateTree",
    l1MHTSrc = cms.InputTag("stage1l1extraParticlesUnpacked", "MHT"),
    l1METSrc = cms.InputTag("stage1l1extraParticlesUnpacked", "MET"),
    l1SHTSrc = cms.InputTag("stage1l1extraParticlesUnpacked", "MHT"),
    l1SETSrc = cms.InputTag("stage1l1extraParticlesUnpacked", "MET"),
)

process.p8=cms.Path(process.sumsL1Rates*process.sumsL1RatesUnpacked)




process.schedule = cms.Schedule(
    process.p1, process.p4,process.p8 #, process.output_step
    )

process.TFileService = cms.Service(
  "TFileService",
  fileName = cms.string(options.outputFile)
  )

import FWCore.PythonUtilities.LumiList as LumiList
process.source.lumisToProcess = LumiList.LumiList(filename = '/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/DCSOnly/json_DCSONLY.txt').getVLuminosityBlockRange()

# Spit out filter efficiency at the end.
process.options = cms.untracked.PSet(wantSummary = cms.untracked.bool(False))
