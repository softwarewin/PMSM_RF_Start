###########################################################################
## Makefile generated for Simulink model 'vdp'. 
## 
## Makefile     : vdp.mk
## Generated on : Mon May 28 00:16:59 2018
## MATLAB Coder version: 3.0 (R2015b)
## 
## Build Info:
## 
## Final product: ./vdp.exe
## Product type : executable
## Build type   : Top-Level Standalone Executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPUTER                Computer type. See the MATLAB "computer" command.
# MODELREF_LINK_RSPFILE   Include paths for the model reference build
# PERL                    PERL Tool
# GEN_LNK_SCRIPT          Perl script to generate the command file
# CMD_FILE                Command file
# MEX_OPTS_FLAG           MEX options

PRODUCT_NAME              = vdp
MAKEFILE                  = vdp.mk
COMPUTER                  = PCWIN64
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2015b
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2015b/bin
MATLAB_ARCH_BIN           = C:/PROGRA~1/MATLAB/R2015b/bin/win64
MASTER_ANCHOR_DIR         = 
START_DIR                 = C:/Users/jxlllx/Documents/GitHub/RF_Ctr/InductionMotor_RF_ControllerCom_Start
ARCH                      = win64
SOLVER                    = ode45.c
SOLVER_OBJ                = ode45.obj
CLASSIC_INTERFACE         = 1
TGT_FCN_LIB               = None
MODELREF_LINK_RSPFILE_NAME = vdp_ref.rsp
RELATIVE_PATH_TO_ANCHOR   = ../../..
MODELREF_LINK_RSPFILE     = vdp_ref.rsp
PERL                      = $(MATLAB_ROOT)/sys/perl/win32/bin/perl.exe
GEN_LNK_SCRIPT            = $(MATLAB_ROOT)/rtw/c/tools/mkvc_lnk.pl
CMD_FILE                  = $(PRODUCT_NAME).lnk
ANSI_OPTS                 = -ansi -pedantic -Wno-long-long -fwrapv
CPP_ANSI_OPTS             = -std=c++98 -pedantic -Wno-long-long -fwrapv
MEX_OPTS_FLAG             = -f "$(MATLAB_ROOT)/bin/win64/mexopts/mingw64.xml"

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          MinGW64 v4.x | gmake (64-bit Windows)
# Supported Version(s):    4.x
# ToolchainInfo Version:   R2015b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# ANSI_OPTS
# CPP_ANSI_OPTS
# MINGW_ROOT

#-----------
# MACROS
#-----------

WARN_FLAGS         = -Wall -W -Wwrite-strings -Winline -Wstrict-prototypes -Wnested-externs -Wpointer-arith -Wcast-align
WARN_FLAGS_MAX     = $(WARN_FLAGS) -Wcast-qual -Wshadow
CPP_WARN_FLAGS     = -Wall -W -Wwrite-strings -Winline -Wpointer-arith -Wcast-align
CPP_WARN_FLAGS_MAX = $(CPP_WARN_FLAGS) -Wcast-qual -Wshadow
MEX_OPTS_FILE      = $(MATLAB_ROOT)/bin/win64/mexopts/mingw64.xml
MW_EXTERNLIB_DIR   = $(MATLAB_ROOT)/extern/lib/win64/mingw64
SHELL              = %SystemRoot%/system32/cmd.exe

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -lws2_32

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: GNU C Compiler
CC_PATH = $(MINGW_ROOT)
CC = $(CC_PATH)/gcc

# Linker: GNU Linker
LD_PATH = $(MINGW_ROOT)
LD = $(LD_PATH)/gcc

# C++ Compiler: GNU C++ Compiler
CPP_PATH = $(MINGW_ROOT)
CPP = $(CPP_PATH)/g++

# C++ Linker: GNU C++ Linker
CPP_LD_PATH = $(MINGW_ROOT)
CPP_LD = $(CPP_LD_PATH)/g++

# Archiver: GNU Archiver
AR_PATH = $(MINGW_ROOT)
AR = $(AR_PATH)/ar

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_BIN)
MEX = $(MEX_PATH)/mex

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%/bin/win64
MAKE = $(MAKE_PATH)/gmake


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @del
ECHO                = @echo
MV                  = @move
RUN                 =

#----------------------------------------
# "Faster Builds" Build Configuration
#----------------------------------------

ARFLAGS              = ruvs
CFLAGS               = -c $(ANSI_OPTS) \
                       -O0
CPPFLAGS             = -c $(CPP_ANSI_OPTS) \
                       -O0
CPP_LDFLAGS          = -Wl,-rpath,"$(MATLAB_ARCH_BIN)",-L"$(MATLAB_ARCH_BIN)"
CPP_SHAREDLIB_LDFLAGS  = -shared -Wl,-rpath,"$(MATLAB_ARCH_BIN)",-L"$(MATLAB_ARCH_BIN)" -Wl,--no-undefined \
                         -Wl,--out-implib,$(basename $(PRODUCT))$(STATICLIB_EXT)
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              = -Wl,-rpath,"$(MATLAB_ARCH_BIN)",-L"$(MATLAB_ARCH_BIN)"
MEX_CFLAGS           = -MATLAB_ARCH=$(ARCH) $(INCLUDES) \
                         \
                       COPTIMFLAGS="$(ANSI_OPTS)  \
                       -O0 \
                        $(DEFINES)" \
                         \
                       -silent
MEX_LDFLAGS          = LDFLAGS=='$$LDFLAGS'
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -shared -Wl,-rpath,"$(MATLAB_ARCH_BIN)",-L"$(MATLAB_ARCH_BIN)" -Wl,--no-undefined \
                       -Wl,--out-implib,$(basename $(PRODUCT))$(STATICLIB_EXT)

#--------------------
# File extensions
#--------------------

H_EXT               = .h
OBJ_EXT             = .obj
C_EXT               = .c
EXE_EXT             = .exe
SHAREDLIB_EXT       = .dll
HPP_EXT             = .hpp
OBJ_EXT             = .obj
CPP_EXT             = .cpp
EXE_EXT             = .exe
SHAREDLIB_EXT       = .dll
STATICLIB_EXT       = .lib
MEX_EXT             = .mexw64
MAKE_EXT            = .mk


###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = ./vdp.exe
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR)/slprj/raccel/vdp -I$(START_DIR) -I$(MATLAB_ROOT)/toolbox/simulink/simdemos/simgeneral -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include -I$(MATLAB_ROOT)/rtw/c/src -I$(MATLAB_ROOT)/rtw/c/src/rapid -I$(MATLAB_ROOT)/rtw/c/raccel -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common -I$(MATLAB_ROOT)/rtw/c/src/rtiostream/rtiostreamtcpip -I$(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_BUILD_ARGS = -DEXT_MODE=1 -DINTEGER_CODE=0 -DCLASSIC_INTERFACE=1 -DALLOCATIONFCN=0 -DONESTEPFCN=0 -DTERMFCN=1 -DMULTI_INSTANCE_CODE=0
DEFINES_IMPLIED = -DTID01EQ=0
DEFINES_OPTS = -DSLMSG_ALLOW_SYSTEM_ALLOC -DTGTCONN -DON_TARGET_WAIT_FOR_START=0
DEFINES_STANDARD = -DNDEBUG -DMODEL=vdp -DNUMST=1 -DNCSTATES=2 -DHAVESTDIO -DNRT -DRSIM_PARAMETER_LOADING -DRSIM_WITH_SL_SOLVER

DEFINES = $(DEFINES_BUILD_ARGS) $(DEFINES_IMPLIED) $(DEFINES_OPTS) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/slprj/raccel/vdp/rtGetInf.c $(START_DIR)/slprj/raccel/vdp/rtGetNaN.c $(START_DIR)/slprj/raccel/vdp/rt_nonfinite.c $(START_DIR)/slprj/raccel/vdp/vdp.c $(START_DIR)/slprj/raccel/vdp/vdp_capi.c $(START_DIR)/slprj/raccel/vdp/vdp_data.c $(START_DIR)/slprj/raccel/vdp/vdp_tgtconn.c rt_logging_mmi.c rtw_modelmap_utils.c rt_logging.c $(MATLAB_ROOT)/rtw/c/raccel/raccel_main.c $(MATLAB_ROOT)/rtw/c/raccel/raccel_sup.c $(MATLAB_ROOT)/rtw/c/raccel/raccel_mat.c $(MATLAB_ROOT)/simulink/include/simulink_solver_api.c $(MATLAB_ROOT)/rtw/c/src/rapid/raccel_utils.c $(MATLAB_ROOT)/rtw/c/src/rapid/common_utils.c $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/rtiostream_interface.c $(MATLAB_ROOT)/rtw/c/src/rtiostream/rtiostreamtcpip/rtiostream_tcpip.c $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/ext_svr.c $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/updown.c $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/ext_work.c $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/rtiostream_utils.c

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = rtGetInf.obj rtGetNaN.obj rt_nonfinite.obj vdp.obj vdp_capi.obj vdp_data.obj vdp_tgtconn.obj rt_logging_mmi.obj rtw_modelmap_utils.obj rt_logging.obj raccel_main.obj raccel_sup.obj raccel_mat.obj simulink_solver_api.obj raccel_utils.obj common_utils.obj rtiostream_interface.obj rtiostream_tcpip.obj ext_svr.obj updown.obj ext_work.obj rtiostream_utils.obj

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = $(MATLAB_ROOT)/extern/lib/win64/mingw64/libmwcoder_target_services.lib $(MATLAB_ROOT)/extern/lib/win64/mingw64/libmwcoder_ToAsyncQueueTgtAppSvc.lib $(MATLAB_ROOT)/extern/lib/win64/mingw64/libmwcoder_ParamTuningTgtAppSvc.lib

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS =  -L$(MATLAB_ROOT)/bin/win64 -L$(MATLAB_ROOT)/extern/lib/win64/mingw64 -llibmwipp -llibut -llibmx -llibmat -llibmwmathutil -llibmwsl_solver_rtw -llibmwsl_fileio -llibmwsigstream -llibmwsl_AsyncioQueue -llibmwsl_log_load_blocks -llibfixedpoint

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_BASIC)

###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS) $(LIBS)
	@echo "### Successfully generated all binary outputs."


prebuild : 


download : build


execute : download
	@echo "### Invoking postbuild tool "Execute" ..."
	$(EXECUTE) $(EXECUTE_FLAGS)
	@echo "### Done invoking postbuild tool."


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(LIBS)
	$(PERL) $(GEN_LNK_SCRIPT) $(CMD_FILE) $(OBJS)
	@echo "### Creating standalone executable "$(PRODUCT)" ..."
	$(LD) $(LDFLAGS) -o $(PRODUCT) @$(CMD_FILE) $(LIBS) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	@echo "### Created: $(PRODUCT)"
	$(RM) $(CMD_FILE)


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.obj : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/slprj/raccel/vdp/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/slprj/raccel/vdp/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/rtiostream/rtiostreamtcpip/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/rtiostream/rtiostreamtcpip/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


raccel_main.obj : $(MATLAB_ROOT)/rtw/c/raccel/raccel_main.c
	$(CC) $(CFLAGS) -o "$@" "$<"


raccel_sup.obj : $(MATLAB_ROOT)/rtw/c/raccel/raccel_sup.c
	$(CC) $(CFLAGS) -o "$@" "$<"


raccel_mat.obj : $(MATLAB_ROOT)/rtw/c/raccel/raccel_mat.c
	$(CC) $(CFLAGS) -o "$@" "$<"


simulink_solver_api.obj : $(MATLAB_ROOT)/simulink/include/simulink_solver_api.c
	$(CC) $(CFLAGS) -o "$@" "$<"


raccel_utils.obj : $(MATLAB_ROOT)/rtw/c/src/rapid/raccel_utils.c
	$(CC) $(CFLAGS) -o "$@" "$<"


common_utils.obj : $(MATLAB_ROOT)/rtw/c/src/rapid/common_utils.c
	$(CC) $(CFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : $(MAKEFILE) rtw_proj.tmw


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(ECHO) "### Deleted all derived files."


