#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "fading_filter_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "fading_filter.h"
#include "fading_filter_capi.h"
#include "fading_filter_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"fading_filter/fading filter 2 order/Sum1" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 0 } , { 1 , 0 , TARGET_STRING (
"fading_filter/fading filter 2 order/Sum3" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 0 } , { 2 , 0 , TARGET_STRING (
"fading_filter/fading filter 3 order/Plus" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 0 } , { 3 , 0 , TARGET_STRING (
"fading_filter/fading filter 3 order/Sum1" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 0 } , { 4 , 0 , TARGET_STRING (
"fading_filter/fading filter 3 order/Sum3" ) , TARGET_STRING ( "x_dot hat" )
, 0 , 0 , 0 , 0 , 0 } , { 5 , 0 , TARGET_STRING (
"fading_filter/signal generator /Constant" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 1 } , { 6 , 0 , TARGET_STRING (
"fading_filter/signal generator /Gain" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 2 } , { 7 , 0 , TARGET_STRING ( "fading_filter/signal generator /Gain1" )
, TARGET_STRING ( "real sign dot" ) , 0 , 0 , 0 , 0 , 2 } , { 8 , 0 ,
TARGET_STRING ( "fading_filter/signal generator /Gain2" ) , TARGET_STRING (
"real sign dot dot" ) , 0 , 0 , 0 , 0 , 2 } , { 9 , 0 , TARGET_STRING (
"fading_filter/signal generator /Add" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 3 } , { 10 , 0 , TARGET_STRING ( "fading_filter/signal generator /Sum2" )
, TARGET_STRING ( "sin(ramp) + noise" ) , 0 , 0 , 0 , 0 , 2 } , { 11 , 0 ,
TARGET_STRING (
"fading_filter/signal generator /Band-Limited White Noise/Output" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 12 , 0 , TARGET_STRING (
"fading_filter/signal generator /Ramp1/Step" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 4 } , { 13 , 0 , TARGET_STRING (
"fading_filter/signal generator /Ramp2/Step" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 4 } , { 14 , 0 , TARGET_STRING (
"fading_filter/signal generator /Ramp3/Step" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 4 } , { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ;
static const rtwCAPI_BlockParameters rtBlockParameters [ ] = { { 15 ,
TARGET_STRING ( "fading_filter/fading filter 2 order/beta second order" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 16 , TARGET_STRING (
"fading_filter/fading filter 2 order/Delay" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 17 , TARGET_STRING (
"fading_filter/fading filter 2 order/Delay1" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 18 , TARGET_STRING (
"fading_filter/fading filter 3 order/beta third order" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 19 , TARGET_STRING (
"fading_filter/fading filter 3 order/Gain1" ) , TARGET_STRING ( "Gain" ) , 0
, 0 , 0 } , { 20 , TARGET_STRING (
"fading_filter/fading filter 3 order/Delay" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 21 , TARGET_STRING (
"fading_filter/fading filter 3 order/Delay1" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 22 , TARGET_STRING (
"fading_filter/fading filter 3 order/Delay2" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 23 , TARGET_STRING (
"fading_filter/signal generator /Ramp1" ) , TARGET_STRING ( "slope" ) , 0 , 0
, 0 } , { 24 , TARGET_STRING ( "fading_filter/signal generator /Ramp1" ) ,
TARGET_STRING ( "start" ) , 0 , 0 , 0 } , { 25 , TARGET_STRING (
"fading_filter/signal generator /Ramp1" ) , TARGET_STRING ( "InitialOutput" )
, 0 , 0 , 0 } , { 26 , TARGET_STRING (
"fading_filter/signal generator /Ramp2" ) , TARGET_STRING ( "slope" ) , 0 , 0
, 0 } , { 27 , TARGET_STRING ( "fading_filter/signal generator /Ramp2" ) ,
TARGET_STRING ( "start" ) , 0 , 0 , 0 } , { 28 , TARGET_STRING (
"fading_filter/signal generator /Ramp2" ) , TARGET_STRING ( "InitialOutput" )
, 0 , 0 , 0 } , { 29 , TARGET_STRING (
"fading_filter/signal generator /Ramp3" ) , TARGET_STRING ( "slope" ) , 0 , 0
, 0 } , { 30 , TARGET_STRING ( "fading_filter/signal generator /Ramp3" ) ,
TARGET_STRING ( "start" ) , 0 , 0 , 0 } , { 31 , TARGET_STRING (
"fading_filter/signal generator /Ramp3" ) , TARGET_STRING ( "InitialOutput" )
, 0 , 0 , 0 } , { 32 , TARGET_STRING (
"fading_filter/signal generator /Constant" ) , TARGET_STRING ( "Value" ) , 0
, 0 , 0 } , { 33 , TARGET_STRING ( "fading_filter/signal generator /Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 34 , TARGET_STRING (
"fading_filter/signal generator /Gain1" ) , TARGET_STRING ( "Gain" ) , 0 , 0
, 0 } , { 35 , TARGET_STRING ( "fading_filter/signal generator /Gain2" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 36 , TARGET_STRING (
"fading_filter/signal generator /Band-Limited White Noise/Output" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 37 , TARGET_STRING (
"fading_filter/signal generator /Band-Limited White Noise/White Noise" ) ,
TARGET_STRING ( "Mean" ) , 0 , 0 , 0 } , { 38 , TARGET_STRING (
"fading_filter/signal generator /Band-Limited White Noise/White Noise" ) ,
TARGET_STRING ( "StdDev" ) , 0 , 0 , 0 } , { 39 , TARGET_STRING (
"fading_filter/signal generator /Ramp1/Step" ) , TARGET_STRING ( "Before" ) ,
0 , 0 , 0 } , { 40 , TARGET_STRING (
"fading_filter/signal generator /Ramp2/Step" ) , TARGET_STRING ( "Before" ) ,
0 , 0 , 0 } , { 41 , TARGET_STRING (
"fading_filter/signal generator /Ramp3/Step" ) , TARGET_STRING ( "Before" ) ,
0 , 0 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 } } ; static const
rtwCAPI_Signals rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 ,
0 , 0 , 0 } } ; static const rtwCAPI_Signals rtRootOutputs [ ] = { { 0 , 0 ,
( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const
rtwCAPI_ModelParameters rtModelParameters [ ] = { { 42 , TARGET_STRING ( "Ts"
) , 0 , 0 , 0 } , { 43 , TARGET_STRING ( "seedGyro1" ) , 0 , 0 , 0 } , { 0 ,
( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . dy3pns2zay , & rtB . fvjzdey4zx ,
& rtB . deh3sa1izr , & rtB . nrrhf3zrwg , & rtB . fcsmvnhlhf , & rtB .
b2bpqzpkan , & rtB . hce0j3xn40 , & rtB . nk2j0vox1p , & rtB . ap2zumddy4 , &
rtB . pd0fa1hjwp , & rtB . hmthhj5kju , & rtB . fbqgur4h21 , & rtB .
lnutfrwd2c , & rtB . m4qr10sxhr , & rtB . oomnw0kr1c , & rtP .
betasecondorder_Value , & rtP . Delay_InitialCondition , & rtP .
Delay1_InitialCondition , & rtP . betathirdorder_Value , & rtP .
Gain1_Gain_h0au2tela2 , & rtP . Delay_InitialCondition_nyirudh0e4 , & rtP .
Delay1_InitialCondition_kcif3gltgy , & rtP . Delay2_InitialCondition , & rtP
. Ramp1_slope , & rtP . Ramp1_start , & rtP . Ramp1_InitialOutput , & rtP .
Ramp2_slope , & rtP . Ramp2_start , & rtP . Ramp2_InitialOutput , & rtP .
Ramp3_slope , & rtP . Ramp3_start , & rtP . Ramp3_InitialOutput , & rtP .
Constant_Value , & rtP . Gain_Gain , & rtP . Gain1_Gain , & rtP . Gain2_Gain
, & rtP . Output_Gain , & rtP . WhiteNoise_Mean , & rtP . WhiteNoise_StdDev ,
& rtP . Step_Y0 , & rtP . Step_Y0_bdajcq0r4x , & rtP . Step_Y0_o11t1or1fs , &
rtP . Ts , & rtP . seedGyro1 , } ; static int32_T * rtVarDimsAddrMap [ ] = {
( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } } ; static const uint_T rtDimensionArray [ ] = {
1 , 1 } ; static const real_T rtcapiStoredFloats [ ] = { 0.01 , 0.0 , 0.1 ,
1.0 } ; static const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL
) , rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const
rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , 2 ,
0 } , { ( NULL ) , ( NULL ) , 4 , 0 } , { ( const void * ) &
rtcapiStoredFloats [ 1 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , 0 ,
0 } , { ( const void * ) & rtcapiStoredFloats [ 2 ] , ( const void * ) &
rtcapiStoredFloats [ 1 ] , 3 , 0 } , { ( const void * ) & rtcapiStoredFloats
[ 1 ] , ( const void * ) & rtcapiStoredFloats [ 3 ] , 1 , 0 } } ; static
rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 15 ,
rtRootInputs , 0 , rtRootOutputs , 0 } , { rtBlockParameters , 27 ,
rtModelParameters , 2 } , { ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap
, rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float"
, { 2258351275U , 816693164U , 294807161U , 3266394777U } , ( NULL ) , 0 , 0
} ; const rtwCAPI_ModelMappingStaticInfo * fading_filter_GetCAPIStaticMap (
void ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void fading_filter_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void fading_filter_host_InitializeDataMapInfo (
fading_filter_host_DataMapInfo_T * dataMap , const char * path ) {
rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap ->
mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
