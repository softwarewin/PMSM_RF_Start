#include "__cf_vdp.h"
#include "rt_logging_mmi.h"
#include "vdp_capi.h"
#include <math.h>
#include "vdp.h"
#include "vdp_private.h"
#include "vdp_dt.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 1 ; const char_T
* gbl_raccel_Version = "8.9 (R2015b) 13-Aug-2015" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const char * gblSlvrJacPatternFileName =
"slprj\\raccel\\vdp\\vdp_Jpattern.mat" ; const int_T gblNumRootInportBlks = 0
; const int_T gblNumModelInputs = 0 ; extern rtInportTUtable *
gblInportTUtables ; extern const char * gblInportFileName ; const int_T
gblInportDataTypeIdx [ ] = { - 1 } ; const int_T gblInportDims [ ] = { - 1 }
; const int_T gblInportComplex [ ] = { - 1 } ; const int_T
gblInportInterpoFlag [ ] = { - 1 } ; const int_T gblInportContinuous [ ] = {
- 1 } ;
#include "simstruc.h"
#include "fixedpoint.h"
const int_T gblParameterTuningTid = - 1 ; void MdlOutputsParameterSampleTime
( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } B rtB ; X rtX ; DW rtDW ; ExtY
rtY ; static SimStruct model_S ; SimStruct * const rtS = & model_S ; void
MdlInitialize ( void ) { rtX . gq0u3r51ae = rtP . x1_IC ; rtX . bxm4duvtnu =
rtP . x2_IC ; } void MdlStart ( void ) { MdlInitialize ( ) ; { bool
externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( ) ; rtwISigstreamManagerGetInputIsInDatasetFormat (
pISigstreamManager , & externalInputIsInDatasetFormat ) ; if (
externalInputIsInDatasetFormat ) { } } } void MdlOutputs ( int_T tid ) { rtB
. dd2tkjygng = rtX . gq0u3r51ae ; rtY . knrqyxbhzu = rtB . dd2tkjygng ; rtB .
hlljur0dk4 = rtX . bxm4duvtnu ; rtY . moq0w12ulw = rtB . hlljur0dk4 ; rtB .
jre4cphv4k = ( 1.0 - rtB . dd2tkjygng * rtB . dd2tkjygng ) * rtB . hlljur0dk4
* rtP . Mu_Gain - rtB . dd2tkjygng ; UNUSED_PARAMETER ( tid ) ; } void
MdlUpdate ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives (
void ) { XDot * _rtXdot ; _rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ; _rtXdot
-> gq0u3r51ae = rtB . hlljur0dk4 ; _rtXdot -> bxm4duvtnu = rtB . jre4cphv4k ;
} void MdlProjection ( void ) { } void MdlTerminate ( void ) { } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 2 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 2 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
1 ) ; ssSetNumBlocks ( rtS , 9 ) ; ssSetNumBlockIO ( rtS , 3 ) ;
ssSetNumBlockParams ( rtS , 3 ) ; } void MdlInitializeSampleTimes ( void ) {
ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ; }
void raccel_set_checksum ( SimStruct * rtS ) { ssSetChecksumVal ( rtS , 0 ,
4108554392U ) ; ssSetChecksumVal ( rtS , 1 , 3577912045U ) ; ssSetChecksumVal
( rtS , 2 , 3622395637U ) ; ssSetChecksumVal ( rtS , 3 , 2542311506U ) ; }
SimStruct * raccel_register_model ( void ) { static struct _ssMdlInfo mdlInfo
; ( void ) memset ( ( char * ) rtS , 0 , sizeof ( SimStruct ) ) ; ( void )
memset ( ( char * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; { rtB . dd2tkjygng = 0.0 ; rtB . hlljur0dk4 = 0.0 ;
rtB . jre4cphv4k = 0.0 ; } } { ssSetY ( rtS , & rtY ) ; rtY . knrqyxbhzu =
0.0 ; rtY . moq0w12ulw = 0.0 ; } ssSetDefaultParam ( rtS , ( real_T * ) & rtP
) ; { real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ; ( void
) memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = ( void * )
& rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork , 0 ,
sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset ( (
char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS ,
& dtInfo ) ; dtInfo . numDataTypes = 14 ; dtInfo . dataTypeSizes = &
rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ;
dtInfo . B = & rtBTransTable ; dtInfo . P = & rtPTransTable ; }
vdp_InitializeDataMapInfo ( rtS ) ; ssSetIsRapidAcceleratorActive ( rtS ,
true ) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS ,
SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "vdp" ) ; ssSetPath ( rtS
, "vdp" ) ; ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal ( rtS , 30.0 ) ; { static
RTWLogInfo rt_DataLoggingInfo ; rt_DataLoggingInfo . loggingInterval = NULL ;
ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ; } { { static int_T
rt_LoggedStateWidths [ ] = { 1 , 1 } ; static int_T
rt_LoggedStateNumDimensions [ ] = { 1 , 1 } ; static int_T
rt_LoggedStateDimensions [ ] = { 1 , 1 } ; static boolean_T
rt_LoggedStateIsVarDims [ ] = { 0 , 0 } ; static BuiltInDTypeId
rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE } ; static int_T
rt_LoggedStateComplexSignals [ ] = { 0 , 0 } ; static const char_T *
rt_LoggedStateLabels [ ] = { "CSTATE" , "CSTATE" } ; static const char_T *
rt_LoggedStateBlockNames [ ] = { "vdp/x1" , "vdp/x2" } ; static const char_T
* rt_LoggedStateNames [ ] = { "" , "" } ; static boolean_T
rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 } ; static RTWLogDataTypeConvert
rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 ,
1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } }
; static RTWLogSignalInfo rt_LoggedStateSignalInfo = { 2 ,
rt_LoggedStateWidths , rt_LoggedStateNumDimensions , rt_LoggedStateDimensions
, rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , { rt_LoggedStateLabels } , ( NULL )
, ( NULL ) , ( NULL ) , { rt_LoggedStateBlockNames } , { rt_LoggedStateNames
} , rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert } ; static void *
rt_LoggedStateSignalPtrs [ 2 ] ; rtliSetLogXSignalPtrs ( ssGetRTWLogInfo (
rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . gq0u3r51ae ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . bxm4duvtnu ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "tmp_raccel_xout" ) ; rtliSetLogXFinal (
ssGetRTWLogInfo ( rtS ) , "xFinal" ) ; rtliSetLogVarNameModifier (
ssGetRTWLogInfo ( rtS ) , "none" ) ; rtliSetLogFormat ( ssGetRTWLogInfo ( rtS
) , 2 ) ; rtliSetLogMaxRows ( ssGetRTWLogInfo ( rtS ) , 0 ) ;
rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS ) , 1 ) ; { static void *
rt_LoggedOutputSignalPtrs [ ] = { & rtY . knrqyxbhzu , & rtY . moq0w12ulw } ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( ( LogSignalPtrsType )
rt_LoggedOutputSignalPtrs ) ) ; } { static int_T rt_LoggedOutputWidths [ ] =
{ 1 , 1 } ; static int_T rt_LoggedOutputNumDimensions [ ] = { 1 , 1 } ;
static int_T rt_LoggedOutputDimensions [ ] = { 1 , 1 } ; static boolean_T
rt_LoggedOutputIsVarDims [ ] = { 0 , 0 } ; static void *
rt_LoggedCurrentSignalDimensions [ ] = { ( NULL ) , ( NULL ) } ; static int_T
rt_LoggedCurrentSignalDimensionsSize [ ] = { 4 , 4 } ; static BuiltInDTypeId
rt_LoggedOutputDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE } ; static int_T
rt_LoggedOutputComplexSignals [ ] = { 0 , 0 } ; static const char_T *
rt_LoggedOutputLabels_0 [ ] = { "x1" } ; static const char_T *
rt_LoggedOutputBlockNames_0 [ ] = { "vdp/Out1" } ; static const char_T *
rt_LoggedOutputLabels_1 [ ] = { "x2" } ; static const char_T *
rt_LoggedOutputBlockNames_1 [ ] = { "vdp/Out2" } ; static
RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } } ; static RTWLogSignalInfo rt_LoggedOutputSignalInfo [
] = { { 1 , rt_LoggedOutputWidths , rt_LoggedOutputNumDimensions ,
rt_LoggedOutputDimensions , rt_LoggedOutputIsVarDims ,
rt_LoggedCurrentSignalDimensions , rt_LoggedCurrentSignalDimensionsSize ,
rt_LoggedOutputDataTypeIds , rt_LoggedOutputComplexSignals , ( NULL ) , {
rt_LoggedOutputLabels_0 } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedOutputBlockNames_0 } , { ( NULL ) } , ( NULL ) ,
rt_RTWLogDataTypeConvert } , { 1 , rt_LoggedOutputWidths + 1 ,
rt_LoggedOutputNumDimensions + 1 , rt_LoggedOutputDimensions + 1 ,
rt_LoggedOutputIsVarDims + 1 , rt_LoggedCurrentSignalDimensions + 1 ,
rt_LoggedCurrentSignalDimensionsSize + 1 , rt_LoggedOutputDataTypeIds + 1 ,
rt_LoggedOutputComplexSignals + 1 , ( NULL ) , { rt_LoggedOutputLabels_1 } ,
( NULL ) , ( NULL ) , ( NULL ) , { rt_LoggedOutputBlockNames_1 } , { ( NULL )
} , ( NULL ) , rt_RTWLogDataTypeConvert + 1 } } ; rtliSetLogYSignalInfo (
ssGetRTWLogInfo ( rtS ) , rt_LoggedOutputSignalInfo ) ;
rt_LoggedCurrentSignalDimensions [ 0 ] = & rt_LoggedOutputWidths [ 0 ] ;
rt_LoggedCurrentSignalDimensions [ 1 ] = & rt_LoggedOutputWidths [ 1 ] ; }
rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "tmp_raccel_yout1,tmp_raccel_yout2" )
; } { static struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , &
statesInfo2 ) ; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 2 ] ; static
real_T absTol [ 2 ] = { 1.0E-5 , 1.0E-5 } ; static uint8_T absTolControl [ 2
] = { 2U , 2U } ; ssSetSolverRelTol ( rtS , 0.001 ) ; ssSetStepSize ( rtS ,
0.0 ) ; ssSetMinStepSize ( rtS , 0.0 ) ; ssSetMaxNumMinSteps ( rtS , - 1 ) ;
ssSetMinStepViolatedError ( rtS , 0 ) ; ssSetMaxStepSize ( rtS , 0.6 ) ;
ssSetSolverMaxOrder ( rtS , - 1 ) ; ssSetSolverRefineFactor ( rtS , 1 ) ;
ssSetOutputTimes ( rtS , ( NULL ) ) ; ssSetNumOutputTimes ( rtS , 0 ) ;
ssSetOutputTimesOnly ( rtS , 0 ) ; ssSetOutputTimesIndex ( rtS , 0 ) ;
ssSetZCCacheNeedsReset ( rtS , 0 ) ; ssSetDerivCacheNeedsReset ( rtS , 0 ) ;
ssSetNumNonContDerivSigInfos ( rtS , 0 ) ; ssSetNonContDerivSigInfos ( rtS ,
( NULL ) ) ; ssSetSolverInfo ( rtS , & slvrInfo ) ; ssSetSolverName ( rtS ,
"ode45" ) ; ssSetVariableStepSolver ( rtS , 1 ) ;
ssSetSolverConsistencyChecking ( rtS , 0 ) ; ssSetSolverAdaptiveZcDetection (
rtS , 0 ) ; ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetAbsTolVector (
rtS , absTol ) ; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetSolverStateProjection ( rtS , 0 ) ; ssSetSolverMassMatrixType ( rtS , (
ssMatrixType ) 0 ) ; ssSetSolverMassMatrixNzMax ( rtS , 0 ) ;
ssSetModelOutputs ( rtS , MdlOutputs ) ; ssSetModelLogData ( rtS ,
rt_UpdateTXYLogVars ) ; ssSetModelLogDataIfInInterval ( rtS ,
rt_UpdateTXXFYLogVars ) ; ssSetModelUpdate ( rtS , MdlUpdate ) ;
ssSetModelDerivatives ( rtS , MdlDerivatives ) ;
ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ;
ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid ( rtS , INT_MIN )
; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 0 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; }
ssSetChecksumVal ( rtS , 0 , 4108554392U ) ; ssSetChecksumVal ( rtS , 1 ,
3577912045U ) ; ssSetChecksumVal ( rtS , 2 , 3622395637U ) ; ssSetChecksumVal
( rtS , 3 , 2542311506U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 1 ] ; ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo
) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; rteiSetModelMappingInfoPtr (
ssGetRTWExtModeInfo ( rtS ) , & ssGetModelMappingInfo ( rtS ) ) ;
rteiSetChecksumsPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) )
; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; } return
rtS ; }
