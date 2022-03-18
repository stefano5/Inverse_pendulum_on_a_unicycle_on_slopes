#ifndef RTW_HEADER_fading_filter_h_
#define RTW_HEADER_fading_filter_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef fading_filter_COMMON_INCLUDES_
#define fading_filter_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "fading_filter_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME fading_filter
#define NSAMPLE_TIMES (5) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (15) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (0)   
#elif NCSTATES != 0
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T lnutfrwd2c ; real_T hce0j3xn40 ; real_T fbqgur4h21 ;
real_T hmthhj5kju ; real_T dy3pns2zay ; real_T fvjzdey4zx ; real_T m4qr10sxhr
; real_T nk2j0vox1p ; real_T nrrhf3zrwg ; real_T fcsmvnhlhf ; real_T
deh3sa1izr ; real_T oomnw0kr1c ; real_T ap2zumddy4 ; real_T pd0fa1hjwp ;
real_T b2bpqzpkan ; } B ; typedef struct { real_T al02fiyu1j ; real_T
fzuyoelf04 ; real_T fslkmxjwkc ; real_T cautctv11j ; real_T khzdyn41ul ;
real_T fp141r5usk ; struct { void * LoggedData [ 2 ] ; } a0gvl2cpky ; struct
{ void * LoggedData [ 2 ] ; } fkozlf4msq ; struct { void * LoggedData [ 2 ] ;
} ocfuwqdzu3 ; struct { void * LoggedData [ 2 ] ; } dsxhngkofn ; struct {
void * LoggedData [ 3 ] ; } h5bp2iqm50 ; struct { void * LoggedData [ 2 ] ; }
bli2vuxmkz ; struct { void * LoggedData [ 2 ] ; } hkjsbkpuv5 ; uint32_T
hi1k4va2l2 ; int_T jwe0xvglkc ; int_T ixlpix4lbf ; int_T lvt5uednpr ; } DW ;
typedef struct { real_T ptfnbnif2i ; real_T awleqewny4 ; real_T lh4tr51xxc ;
} ZCV ; typedef struct { rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ;
struct P_ { real_T Ts ; real_T seedGyro1 ; real_T Ramp1_InitialOutput ;
real_T Ramp2_InitialOutput ; real_T Ramp3_InitialOutput ; real_T Ramp1_slope
; real_T Ramp2_slope ; real_T Ramp3_slope ; real_T Ramp1_start ; real_T
Ramp2_start ; real_T Ramp3_start ; real_T Step_Y0 ; real_T Gain_Gain ; real_T
Delay1_InitialCondition ; real_T Delay_InitialCondition ; real_T
WhiteNoise_Mean ; real_T WhiteNoise_StdDev ; real_T Output_Gain ; real_T
Step_Y0_bdajcq0r4x ; real_T Gain1_Gain ; real_T
Delay1_InitialCondition_kcif3gltgy ; real_T Delay2_InitialCondition ; real_T
Gain1_Gain_h0au2tela2 ; real_T Delay_InitialCondition_nyirudh0e4 ; real_T
Step_Y0_o11t1or1fs ; real_T Gain2_Gain ; real_T betasecondorder_Value ;
real_T betathirdorder_Value ; real_T Constant_Value ; } ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern DW rtDW ; extern P rtP ;
extern const rtwCAPI_ModelMappingStaticInfo * fading_filter_GetCAPIStaticMap
( void ) ; extern SimStruct * const rtS ; extern const int_T gblNumToFiles ;
extern const int_T gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ;
extern rtInportTUtable * gblInportTUtables ; extern const char *
gblInportFileName ; extern const int_T gblNumRootInportBlks ; extern const
int_T gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ;
extern const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [
] ; extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ; extern const int_T gblParameterTuningTid ; extern
DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void
MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ;
void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model (
ssExecutionInfo * executionInfo ) ;
#endif
