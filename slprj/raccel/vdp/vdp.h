#include "__cf_vdp.h"
#ifndef RTW_HEADER_vdp_h_
#define RTW_HEADER_vdp_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef vdp_COMMON_INCLUDES_
#define vdp_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "vdp_types.h"
#include "multiword_types.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME vdp
#define NSAMPLE_TIMES (1) 
#define NINPUTS (0)       
#define NOUTPUTS (2)     
#define NBLOCKIO (3) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (2)   
#elif NCSTATES != 2
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
typedef struct { real_T dd2tkjygng ; real_T hlljur0dk4 ; real_T jre4cphv4k ;
} B ; typedef struct { struct { void * LoggedData ; } abh5bjzoxu ; } DW ;
typedef struct { real_T gq0u3r51ae ; real_T bxm4duvtnu ; } X ; typedef struct
{ real_T gq0u3r51ae ; real_T bxm4duvtnu ; } XDot ; typedef struct { boolean_T
gq0u3r51ae ; boolean_T bxm4duvtnu ; } XDis ; typedef struct { real_T
gq0u3r51ae ; real_T bxm4duvtnu ; } CStateAbsTol ; typedef struct { real_T
knrqyxbhzu ; real_T moq0w12ulw ; } ExtY ; typedef struct {
rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ { real_T x1_IC ;
real_T x2_IC ; real_T Mu_Gain ; } ; extern P rtP ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW rtDW ;
extern ExtY rtY ; extern const rtwCAPI_ModelMappingStaticInfo *
vdp_GetCAPIStaticMap ( void ) ; extern SimStruct * const rtS ; extern const
int_T gblNumToFiles ; extern const int_T gblNumFrFiles ; extern const int_T
gblNumFrWksBlocks ; extern rtInportTUtable * gblInportTUtables ; extern const
char * gblInportFileName ; extern const int_T gblNumRootInportBlks ; extern
const int_T gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ;
extern const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [
] ; extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ; extern const int_T gblParameterTuningTid ; extern
DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void
MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ;
void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model ( void
) ;
#endif
