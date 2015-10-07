import FWCore.ParameterSet.Config as cms

from L1Trigger.L1TCalorimeter.caloConfigStage1PP_cfi import *
from L1Trigger.L1TCalorimeter.L1TCaloStage1_PPFromRaw_cff import *
from L1Trigger.Configuration.SimL1Emulator_cff import simGtDigis

simGtDigis = simGtDigis.clone()
simGtDigis.GmtInputTag = 'simGmtDigis'
simGtDigis.GctInputTag = 'simCaloStage1LegacyFormatDigis'
simGtDigis.TechnicalTriggersInputTags = cms.VInputTag( )

from L1Trigger.Configuration.SimL1Emulator_cff import simRctDigis
simRctDigis.ecalDigis = cms.VInputTag( cms.InputTag( 'ecalDigis:EcalTriggerPrimitives' ) )
simRctDigis.hcalDigis = cms.VInputTag( cms.InputTag( 'hcalDigis' ) )
# This is to overwrite the configuration of L1Trigger.L1TCalorimeter.L1TCaloStage1_PPFromRaw_cff 

rerunStage1 = cms.Sequence(
    L1TCaloStage1
    +simGtDigis
    +l1ExtraLayer2
    )
