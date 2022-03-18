#include "rt_logging_mmi.h"
#include "fading_filter_capi.h"
#include <math.h>
#include "fading_filter.h"
#include "fading_filter_private.h"
#include "fading_filter_dt.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; void
raccelForceExtModeShutdown ( boolean_T extModeStartPktReceived ) { if ( !
extModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 4 , & stopRequested ) ; }
rtExtModeShutdown ( 4 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 5 ; const char_T
* gbl_raccel_Version = "10.2 (R2020b) 29-Jul-2020" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const int_T gblNumRootInportBlks = 0 ; const int_T
gblNumModelInputs = 0 ; extern const char * gblInportFileName ; extern
rtInportTUtable * gblInportTUtables ; const int_T gblInportDataTypeIdx [ ] =
{ - 1 } ; const int_T gblInportDims [ ] = { - 1 } ; const int_T
gblInportComplex [ ] = { - 1 } ; const int_T gblInportInterpoFlag [ ] = { - 1
} ; const int_T gblInportContinuous [ ] = { - 1 } ; int_T enableFcnCallFlag [
] = { 1 , 1 , 1 , 1 , 1 } ; const char * raccelLoadInputsAndAperiodicHitTimes
( SimStruct * S , const char * inportFileName , int * matFileFormat ) {
return rt_RAccelReadInportsMatFile ( S , inportFileName , matFileFormat ) ; }
B rtB ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS = &
model_S ; real_T rt_urand_Upu32_Yd_f_pw_snf ( uint32_T * u ) { uint32_T hi ;
uint32_T lo ; lo = * u % 127773U * 16807U ; hi = * u / 127773U * 2836U ; if (
lo < hi ) { * u = 2147483647U - ( hi - lo ) ; } else { * u = lo - hi ; }
return ( real_T ) * u * 4.6566128752457969E-10 ; } real_T
rt_nrand_Upu32_Yd_f_pw_snf ( uint32_T * u ) { real_T si ; real_T sr ; real_T
y ; do { sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf ( u ) - 1.0 ; si = 2.0 *
rt_urand_Upu32_Yd_f_pw_snf ( u ) - 1.0 ; si = sr * sr + si * si ; } while (
si > 1.0 ) ; y = muDoubleScalarSqrt ( - 2.0 * muDoubleScalarLog ( si ) / si )
* sr ; return y ; } void MdlInitialize ( void ) { real_T tmp ; int32_T r ;
int32_T t ; uint32_T tseed ; rtDW . al02fiyu1j = rtP .
Delay1_InitialCondition ; rtDW . fzuyoelf04 = rtP . Delay_InitialCondition ;
tmp = muDoubleScalarFloor ( rtP . seedGyro1 ) ; if ( muDoubleScalarIsNaN (
tmp ) || muDoubleScalarIsInf ( tmp ) ) { tmp = 0.0 ; } else { tmp =
muDoubleScalarRem ( tmp , 4.294967296E+9 ) ; } tseed = tmp < 0.0 ? ( uint32_T
) - ( int32_T ) ( uint32_T ) - tmp : ( uint32_T ) tmp ; r = ( int32_T ) (
tseed >> 16U ) ; t = ( int32_T ) ( tseed & 32768U ) ; tseed = ( ( ( ( tseed -
( ( uint32_T ) r << 16U ) ) + t ) << 16U ) + t ) + r ; if ( tseed < 1U ) {
tseed = 1144108930U ; } else { if ( tseed > 2147483646U ) { tseed =
2147483646U ; } } rtDW . hi1k4va2l2 = tseed ; rtDW . fp141r5usk =
rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . hi1k4va2l2 ) * rtP . WhiteNoise_StdDev
+ rtP . WhiteNoise_Mean ; rtDW . fslkmxjwkc = rtP .
Delay1_InitialCondition_kcif3gltgy ; rtDW . cautctv11j = rtP .
Delay2_InitialCondition ; rtDW . khzdyn41ul = rtP .
Delay_InitialCondition_nyirudh0e4 ; } void MdlStart ( void ) { { bool
externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} MdlInitialize ( ) ; } void MdlOutputs ( int_T tid ) { real_T chhv1xbifb ;
real_T d2muinjxvo ; real_T hm4khg3ups ; real_T khwr0vyieu ; real_T lyooeoho54
; real_T muztmmkpth ; real_T nutnlxfum4 ; if ( ssIsSampleHit ( rtS , 1 , 0 )
) { rtDW . jwe0xvglkc = ( ssGetTaskTime ( rtS , 1 ) >= rtP . Ramp1_start ) ;
if ( rtDW . jwe0xvglkc == 1 ) { rtB . lnutfrwd2c = rtP . Ramp1_slope ; } else
{ rtB . lnutfrwd2c = rtP . Step_Y0 ; } } rtB . hce0j3xn40 = muDoubleScalarSin
( ( ssGetT ( rtS ) - rtP . Ramp1_start ) * rtB . lnutfrwd2c + rtP .
Ramp1_InitialOutput ) * rtP . Gain_Gain ; if ( ssIsSampleHit ( rtS , 2 , 0 )
) { chhv1xbifb = rtDW . al02fiyu1j ; khwr0vyieu = rtP . Ts * rtDW .
al02fiyu1j + rtDW . fzuyoelf04 ; } if ( ssIsSampleHit ( rtS , 3 , 0 ) ) { rtB
. fbqgur4h21 = rtP . Output_Gain * rtDW . fp141r5usk ; } rtB . hmthhj5kju =
rtB . fbqgur4h21 + rtB . hce0j3xn40 ; if ( ssIsSampleHit ( rtS , 2 , 0 ) ) {
hm4khg3ups = rtB . hmthhj5kju ; nutnlxfum4 = rtB . hmthhj5kju - khwr0vyieu ;
rtB . dy3pns2zay = ( 1.0 - rtP . betasecondorder_Value * rtP .
betasecondorder_Value ) * nutnlxfum4 + khwr0vyieu ; } if ( ssIsSampleHit (
rtS , 2 , 0 ) ) { rtB . fvjzdey4zx = ( 1.0 - rtP . betasecondorder_Value ) *
( 1.0 - rtP . betasecondorder_Value ) * nutnlxfum4 / rtP . Ts + chhv1xbifb ;
} if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtDW . ixlpix4lbf = ( ssGetTaskTime
( rtS , 1 ) >= rtP . Ramp2_start ) ; if ( rtDW . ixlpix4lbf == 1 ) { rtB .
m4qr10sxhr = rtP . Ramp2_slope ; } else { rtB . m4qr10sxhr = rtP .
Step_Y0_bdajcq0r4x ; } } rtB . nk2j0vox1p = muDoubleScalarCos ( ( ssGetT (
rtS ) - rtP . Ramp2_start ) * rtB . m4qr10sxhr + rtP . Ramp2_InitialOutput )
* rtP . Gain1_Gain ; if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { lyooeoho54 = rtDW
. fslkmxjwkc ; d2muinjxvo = rtDW . cautctv11j ; chhv1xbifb = ( rtP . Ts *
rtDW . fslkmxjwkc + rtP . Gain1_Gain_h0au2tela2 * rtDW . cautctv11j ) + rtDW
. khzdyn41ul ; muztmmkpth = hm4khg3ups - chhv1xbifb ; rtB . nrrhf3zrwg = (
1.0 - rtP . betathirdorder_Value * rtP . betathirdorder_Value ) * muztmmkpth
+ chhv1xbifb ; } if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { rtB . fcsmvnhlhf = (
( rtP . betathirdorder_Value + 1.0 ) * 1.5 * ( ( 1.0 - rtP .
betathirdorder_Value ) * ( 1.0 - rtP . betathirdorder_Value ) ) * muztmmkpth
/ rtP . Ts + rtP . Ts * d2muinjxvo ) + lyooeoho54 ; } if ( ssIsSampleHit (
rtS , 2 , 0 ) ) { rtB . deh3sa1izr = muDoubleScalarPower ( 1.0 - rtP .
betathirdorder_Value , 3.0 ) * 0.5 * ( muztmmkpth * 2.0 ) / ( rtP . Ts * rtP
. Ts ) + d2muinjxvo ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtDW .
lvt5uednpr = ( ssGetTaskTime ( rtS , 1 ) >= rtP . Ramp3_start ) ; if ( rtDW .
lvt5uednpr == 1 ) { rtB . oomnw0kr1c = rtP . Ramp3_slope ; } else { rtB .
oomnw0kr1c = rtP . Step_Y0_o11t1or1fs ; } } rtB . ap2zumddy4 =
muDoubleScalarSin ( ( ssGetT ( rtS ) - rtP . Ramp3_start ) * rtB . oomnw0kr1c
+ rtP . Ramp3_InitialOutput ) * rtP . Gain2_Gain ; if ( ssIsSampleHit ( rtS ,
3 , 0 ) ) { rtB . pd0fa1hjwp = rtB . b2bpqzpkan + rtB . fbqgur4h21 ; }
UNUSED_PARAMETER ( tid ) ; } void MdlOutputsTID4 ( int_T tid ) { rtB .
b2bpqzpkan = rtP . Constant_Value ; UNUSED_PARAMETER ( tid ) ; } void
MdlUpdate ( int_T tid ) { if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { rtDW .
al02fiyu1j = rtB . fvjzdey4zx ; rtDW . fzuyoelf04 = rtB . dy3pns2zay ; rtDW .
fslkmxjwkc = rtB . fcsmvnhlhf ; rtDW . cautctv11j = rtB . deh3sa1izr ; rtDW .
khzdyn41ul = rtB . nrrhf3zrwg ; } if ( ssIsSampleHit ( rtS , 3 , 0 ) ) { rtDW
. fp141r5usk = rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . hi1k4va2l2 ) * rtP .
WhiteNoise_StdDev + rtP . WhiteNoise_Mean ; } UNUSED_PARAMETER ( tid ) ; }
void MdlUpdateTID4 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void
MdlZeroCrossings ( void ) { ZCV * _rtZCSV ; _rtZCSV = ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) ; _rtZCSV -> ptfnbnif2i = ssGetT ( rtS )
- rtP . Ramp1_start ; _rtZCSV -> awleqewny4 = ssGetT ( rtS ) - rtP .
Ramp2_start ; _rtZCSV -> lh4tr51xxc = ssGetT ( rtS ) - rtP . Ramp3_start ; }
void MdlTerminate ( void ) { } void MdlInitializeSizes ( void ) {
ssSetNumContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU ( rtS , 0
) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS , 4 ) ;
ssSetNumBlocks ( rtS , 70 ) ; ssSetNumBlockIO ( rtS , 15 ) ;
ssSetNumBlockParams ( rtS , 29 ) ; } void MdlInitializeSampleTimes ( void ) {
ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 0.0 ) ;
ssSetSampleTime ( rtS , 2 , 0.01 ) ; ssSetSampleTime ( rtS , 3 , 0.1 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1 , 1.0 ) ;
ssSetOffsetTime ( rtS , 2 , 0.0 ) ; ssSetOffsetTime ( rtS , 3 , 0.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 2258351275U ) ;
ssSetChecksumVal ( rtS , 1 , 816693164U ) ; ssSetChecksumVal ( rtS , 2 ,
294807161U ) ; ssSetChecksumVal ( rtS , 3 , 3266394777U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; ( void ) memset ( ( char * ) rtS , 0 ,
sizeof ( SimStruct ) ) ; ( void ) memset ( ( char * ) & mdlInfo , 0 , sizeof
( struct _ssMdlInfo ) ) ; ssSetMdlInfoPtr ( rtS , & mdlInfo ) ;
ssSetExecutionInfo ( rtS , executionInfo ) ; { static time_T mdlPeriod [
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
( ( void * ) & rtB ) ) ; ssSetWorkSizeInBytes ( rtS , sizeof ( rtB ) ,
"BlockIO" ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof ( B ) ) ; }
{ void * dwork = ( void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ;
ssSetWorkSizeInBytes ( rtS , sizeof ( rtDW ) , "DWork" ) ; ( void ) memset (
dwork , 0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void )
memset ( ( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ;
ssSetModelMappingInfo ( rtS , & dtInfo ) ; dtInfo . numDataTypes = 14 ;
dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = &
rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = & rtBTransTable ; dtInfo .
PTransTable = & rtPTransTable ; dtInfo . dataTypeInfoTable =
rtDataTypeInfoTable ; } fading_filter_InitializeDataMapInfo ( ) ;
ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ;
ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"fading_filter" ) ; ssSetPath ( rtS , "fading_filter" ) ; ssSetTStart ( rtS ,
0.0 ) ; ssSetTFinal ( rtS , 10.0 ) ; { static RTWLogInfo rt_DataLoggingInfo ;
rt_DataLoggingInfo . loggingInterval = NULL ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { { static int_T rt_LoggedStateWidths [ ] = { 1 , 1
, 1 , 1 , 1 } ; static int_T rt_LoggedStateNumDimensions [ ] = { 1 , 1 , 1 ,
1 , 1 } ; static int_T rt_LoggedStateDimensions [ ] = { 1 , 1 , 1 , 1 , 1 } ;
static boolean_T rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 , 0 , 0 } ; static
BuiltInDTypeId rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ; static int_T
rt_LoggedStateComplexSignals [ ] = { 0 , 0 , 0 , 0 , 0 } ; static
RTWPreprocessingFcnPtr rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) } ; static const char_T *
rt_LoggedStateLabels [ ] = { "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" ,
"DSTATE" } ; static const char_T * rt_LoggedStateBlockNames [ ] = {
"fading_filter/fading filter 2 order/Delay1" ,
"fading_filter/fading filter 2 order/Delay" ,
"fading_filter/fading filter 3 order/Delay1" ,
"fading_filter/fading filter 3 order/Delay2" ,
"fading_filter/fading filter 3 order/Delay" } ; static const char_T *
rt_LoggedStateNames [ ] = { "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" ,
"DSTATE" } ; static boolean_T rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 , 0
, 0 } ; static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static
RTWLogSignalInfo rt_LoggedStateSignalInfo = { 5 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert } ; static void *
rt_LoggedStateSignalPtrs [ 5 ] ; rtliSetLogXSignalPtrs ( ssGetRTWLogInfo (
rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtDW . al02fiyu1j ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtDW . fzuyoelf04 ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtDW . fslkmxjwkc ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtDW . cautctv11j ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) & rtDW . khzdyn41ul ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) ,
"" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
ssSolverInfo slvrInfo ; static uint8_T zcAttributes [ 3 ] = { (
ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_UP ) } ;
ssSetStepSize ( rtS , 0.01 ) ; ssSetMinStepSize ( rtS , 0.0 ) ;
ssSetMaxNumMinSteps ( rtS , - 1 ) ; ssSetMinStepViolatedError ( rtS , 0 ) ;
ssSetMaxStepSize ( rtS , 0.01 ) ; ssSetSolverMaxOrder ( rtS , - 1 ) ;
ssSetSolverRefineFactor ( rtS , 1 ) ; ssSetOutputTimes ( rtS , ( NULL ) ) ;
ssSetNumOutputTimes ( rtS , 0 ) ; ssSetOutputTimesOnly ( rtS , 0 ) ;
ssSetOutputTimesIndex ( rtS , 0 ) ; ssSetZCCacheNeedsReset ( rtS , 0 ) ;
ssSetDerivCacheNeedsReset ( rtS , 0 ) ; ssSetNumNonContDerivSigInfos ( rtS ,
0 ) ; ssSetNonContDerivSigInfos ( rtS , ( NULL ) ) ; ssSetSolverInfo ( rtS ,
& slvrInfo ) ; ssSetSolverName ( rtS , "VariableStepDiscrete" ) ;
ssSetVariableStepSolver ( rtS , 1 ) ; ssSetSolverConsistencyChecking ( rtS ,
0 ) ; ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ;
ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetSolverStateProjection ( rtS ,
0 ) ; ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelLogData ( rtS , rt_UpdateTXYLogVars ) ;
ssSetModelLogDataIfInInterval ( rtS , rt_UpdateTXXFYLogVars ) ;
ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetSolverZcSignalAttrib ( rtS ,
zcAttributes ) ; ssSetSolverNumZcSignals ( rtS , 3 ) ;
ssSetModelZeroCrossings ( rtS , MdlZeroCrossings ) ;
ssSetSolverConsecutiveZCsStepRelTol ( rtS , 2.8421709430404007E-13 ) ;
ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ; ssSetSolverConsecutiveZCsError
( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic ( rtS , 1 ) ;
ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ; ssSetTNextTid ( rtS , INT_MIN )
; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 3 ) ; } ssSetChecksumVal ( rtS , 0 ,
2258351275U ) ; ssSetChecksumVal ( rtS , 1 , 816693164U ) ; ssSetChecksumVal
( rtS , 2 , 294807161U ) ; ssSetChecksumVal ( rtS , 3 , 3266394777U ) ; {
static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static
RTWExtModeInfo rt_ExtModeInfo ; static const sysRanDType * systemRan [ 6 ] ;
gblRTWExtModeInfo = & rt_ExtModeInfo ; ssSetRTWExtModeInfo ( rtS , &
rt_ExtModeInfo ) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo ,
systemRan ) ; systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = &
rtAlwaysEnabled ; systemRan [ 2 ] = & rtAlwaysEnabled ; systemRan [ 3 ] = &
rtAlwaysEnabled ; systemRan [ 4 ] = & rtAlwaysEnabled ; systemRan [ 5 ] = &
rtAlwaysEnabled ; rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) ,
& ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo
( rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS
) , ssGetTPtr ( rtS ) ) ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 4 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID4 ( tid ) ; }
