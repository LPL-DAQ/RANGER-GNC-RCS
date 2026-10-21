###########################################################################
## Makefile generated for component 'solenoid_valve_curtain_v1_109'. 
## 
## Makefile     : solenoid_valve_curtain_v1_109.mk
## Generated on : Tue Oct 20 20:09:56 2026
## Final product: $(RELATIVE_PATH_TO_ANCHOR)/solenoid_valve_curtain_v1_109.exe
## Product type : executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPILER_COMMAND_FILE   Compiler command listing model reference header paths
# CMD_FILE                Command file

PRODUCT_NAME              = solenoid_valve_curtain_v1_109
MAKEFILE                  = solenoid_valve_curtain_v1_109.mk
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2026a
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2026a/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = C:/Users/11and/USC/LPL/RANGER-GNC-RCS
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = ISO_C
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0
RELATIVE_PATH_TO_ANCHOR   = ..
COMPILER_COMMAND_FILE     = solenoid_valve_curtain_v1_109_comp.rsp
CMD_FILE                  = solenoid_valve_curtain_v1_109.rsp
C_STANDARD_OPTS           = -fwrapv
CPP_STANDARD_OPTS         = -fwrapv
LIBSSC_SLI_ERT_MINGW64_OBJS = 
LIBSSC_CORE_ERT_MINGW64_OBJS = 
LIBPM_ST_ERT_MINGW64_OBJS = 
LIBMC_ERT_MINGW64_OBJS    = 
LIBEX_ERT_MINGW64_OBJS    = 
LIBPM_ERT_MINGW64_OBJS    = 

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          MinGW64 | gmake (64-bit Windows)
# Supported Version(s):    14.x
# ToolchainInfo Version:   2026a
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# C_STANDARD_OPTS
# CPP_STANDARD_OPTS
# MINGW_ROOT
# MINGW_C_STANDARD_OPTS

#-----------
# MACROS
#-----------

WARN_FLAGS            = -Wall -W -Wwrite-strings -Winline -Wstrict-prototypes -Wnested-externs -Wpointer-arith -Wcast-align -Wno-stringop-overflow
WARN_FLAGS_MAX        = $(WARN_FLAGS) -Wcast-qual -Wshadow
CPP_WARN_FLAGS        = -Wall -W -Wwrite-strings -Winline -Wpointer-arith -Wcast-align -Wno-stringop-overflow
CPP_WARN_FLAGS_MAX    = $(CPP_WARN_FLAGS) -Wcast-qual -Wshadow
MW_EXTERNLIB_DIR      = $(MATLAB_ROOT)/extern/lib/win64/mingw64
SHELL                 = %SystemRoot%/system32/cmd.exe

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -lws2_32

FORMAT_FOR_ECHO_CMD              = $(strip $(subst >,^>,\
	$(subst <,^<,\
	$(subst |,^|,\
	$(subst &,^&,\
	$(subst ",^",\
	$(subst ^,^^,\
	$1)))))))
FORMAT_FOR_ECHO                  = $(FORMAT_FOR_ECHO_CMD)
HASH                             = \#
SEMICOLON                        = ;
UNESCAPE_SEMICOLONS              = $(subst \;,;,$1)
ADD_QUOTES                       = $(foreach aPath,$1,"$(aPath)")

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: GNU C Compiler
CC_PATH = $(MINGW_ROOT)
CC = "$(CC_PATH)/gcc"

# Linker: GNU Linker
LD_PATH = $(MINGW_ROOT)
LD = "$(LD_PATH)/g++"

# C++ Compiler: GNU C++ Compiler
CPP_PATH = $(MINGW_ROOT)
CPP = "$(CPP_PATH)/g++"

# C++ Linker: GNU C++ Linker
CPP_LD_PATH = $(MINGW_ROOT)
CPP_LD = "$(CPP_LD_PATH)/g++"

# Archiver: GNU Archiver
AR_PATH = $(MINGW_ROOT)
AR = "$(AR_PATH)/ar"

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = $(MINGW_ROOT)
MAKE = "$(MAKE_PATH)/mingw32-make.exe"


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
CFLAGS               = -c $(MINGW_C_STANDARD_OPTS) -m64 -Wno-error=incompatible-pointer-types -Wno-error=stringop-overflow \
                       -O0
CPPFLAGS             = -c $(CPP_STANDARD_OPTS) -m64 -Wno-error=incompatible-pointer-types -Wno-error=stringop-overflow \
                       -O0
CPP_LDFLAGS          =  -static -m64
CPP_SHAREDLIB_LDFLAGS  = -shared -Wl,--no-undefined \
                         -Wl,--out-implib,$(basename $(PRODUCT)).lib
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              =  -static -m64
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -j $(MAX_MAKE_JOBS) -l $(MAX_MAKE_LOAD_AVG) -Oline -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -shared -Wl,--no-undefined \
                       -Wl,--out-implib,$(basename $(PRODUCT)).lib



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/solenoid_valve_curtain_v1_109.exe
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = 

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_BUILD_ARGS = -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTERMFCN=0 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0
DEFINES_CUSTOM = 
DEFINES_OPTS = -DTID01EQ=1
DEFINES_STANDARD = -DMODEL=solenoid_valve_curtain_v1_109 -DNUMST=2 -DNCSTATES=25 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0

DEFINES = $(DEFINES_BUILD_ARGS) $(DEFINES_CUSTOM) $(DEFINES_OPTS) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_96c7c979_1_ds.c $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_96c7c979_1_ds_log.c $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_96c7c979_1_ds_obs_act.c $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_96c7c979_1_ds_dxf_p.c $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_96c7c979_1_ds_obs_il.c $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_96c7c979_1_ds_tdxf_p.c $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_96c7c979_1_ds_obs_all.c $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_96c7c979_1_ds_dxf.c $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_96c7c979_1_ds_acon_p.c $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_96c7c979_1_ds_obs_exp.c $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_96c7c979_1_ds_f.c $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_96c7c979_1.c $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_96c7c979_1_gateway.c $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_77b42695_1_ds.c $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_77b42695_1_ds_log.c $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_77b42695_1_ds_obs_act.c $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_77b42695_1_ds_dxf_p.c $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_77b42695_1_ds_obs_il.c $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_77b42695_1_ds_tdxf_p.c $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_77b42695_1_ds_obs_all.c $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_77b42695_1_ds_dxf.c $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_77b42695_1_ds_acon_p.c $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_77b42695_1_ds_obs_exp.c $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_77b42695_1_ds_f.c $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_77b42695_1.c $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_77b42695_1_gateway.c $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/rt_backsubrr_dbl.c $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/rt_forwardsubrr_dbl.c $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/rt_lu_real.c $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/rt_matrixlib_dbl.c $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109.c

MAIN_SRC = $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/ert_main.c

ALL_SRCS = $(SRCS) $(MAIN_SRC)

###########################################################################
## OBJECTS
###########################################################################

OBJS = solenoid_valve_curtain_v1_109_96c7c979_1_ds.obj solenoid_valve_curtain_v1_109_96c7c979_1_ds_log.obj solenoid_valve_curtain_v1_109_96c7c979_1_ds_obs_act.obj solenoid_valve_curtain_v1_109_96c7c979_1_ds_dxf_p.obj solenoid_valve_curtain_v1_109_96c7c979_1_ds_obs_il.obj solenoid_valve_curtain_v1_109_96c7c979_1_ds_tdxf_p.obj solenoid_valve_curtain_v1_109_96c7c979_1_ds_obs_all.obj solenoid_valve_curtain_v1_109_96c7c979_1_ds_dxf.obj solenoid_valve_curtain_v1_109_96c7c979_1_ds_acon_p.obj solenoid_valve_curtain_v1_109_96c7c979_1_ds_obs_exp.obj solenoid_valve_curtain_v1_109_96c7c979_1_ds_f.obj solenoid_valve_curtain_v1_109_96c7c979_1.obj solenoid_valve_curtain_v1_109_96c7c979_1_gateway.obj solenoid_valve_curtain_v1_109_77b42695_1_ds.obj solenoid_valve_curtain_v1_109_77b42695_1_ds_log.obj solenoid_valve_curtain_v1_109_77b42695_1_ds_obs_act.obj solenoid_valve_curtain_v1_109_77b42695_1_ds_dxf_p.obj solenoid_valve_curtain_v1_109_77b42695_1_ds_obs_il.obj solenoid_valve_curtain_v1_109_77b42695_1_ds_tdxf_p.obj solenoid_valve_curtain_v1_109_77b42695_1_ds_obs_all.obj solenoid_valve_curtain_v1_109_77b42695_1_ds_dxf.obj solenoid_valve_curtain_v1_109_77b42695_1_ds_acon_p.obj solenoid_valve_curtain_v1_109_77b42695_1_ds_obs_exp.obj solenoid_valve_curtain_v1_109_77b42695_1_ds_f.obj solenoid_valve_curtain_v1_109_77b42695_1.obj solenoid_valve_curtain_v1_109_77b42695_1_gateway.obj rt_backsubrr_dbl.obj rt_forwardsubrr_dbl.obj rt_lu_real.obj rt_matrixlib_dbl.obj solenoid_valve_curtain_v1_109.obj

MAIN_OBJ = ert_main.obj

ALL_OBJS = $(OBJS) $(MAIN_OBJ)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/lib/ssc_sli_ert_mingw64.lib $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/lib/ssc_core_ert_mingw64.lib $(MATLAB_ROOT)/extern/physmod/win64/pm_st/lib/pm_st_ert_mingw64.lib $(MATLAB_ROOT)/extern/physmod/win64/mc/lib/mc_ert_mingw64.lib $(MATLAB_ROOT)/extern/physmod/win64/ex/lib/ex_ert_mingw64.lib $(MATLAB_ROOT)/extern/physmod/win64/pm/lib/pm_ert_mingw64.lib

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_TFL = -msse2 -fno-predictive-commoning
CFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CFLAGS += $(CFLAGS_TFL) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_TFL = -msse2 -fno-predictive-commoning
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CPPFLAGS += $(CPPFLAGS_TFL) $(CPPFLAGS_BASIC)

#---------------------
# MEX C++ Compiler
#---------------------

MEX_CPP_Compiler_BASIC =  @$(COMPILER_COMMAND_FILE)

MEX_CPPFLAGS += $(MEX_CPP_Compiler_BASIC)

#-----------------
# MEX Compiler
#-----------------

MEX_Compiler_BASIC =  @$(COMPILER_COMMAND_FILE)

MEX_CFLAGS += $(MEX_Compiler_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################


MINGW_C_STANDARD_OPTS = $(C_STANDARD_OPTS)


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild download execute


all : build
	@echo $(call FORMAT_FOR_ECHO,### Successfully generated all binary outputs.)


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS) $(LIBS)
	@echo $(call FORMAT_FOR_ECHO,### Successfully generated all binary outputs.)


prebuild : 


download : $(PRODUCT)


execute : download
	@echo $(call FORMAT_FOR_ECHO,### Invoking postbuild tool Execute ...)
	$(EXECUTE) $(EXECUTE_FLAGS)
	@echo $(call FORMAT_FOR_ECHO,### Done invoking postbuild tool.)


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(LIBS) $(MAIN_OBJ)
	@echo $(call FORMAT_FOR_ECHO,### Creating standalone executable "$(PRODUCT)" ...)
	$(LD) $(LDFLAGS) -o $(PRODUCT) @$(CMD_FILE) -Wl,--start-group $(LIBS) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS) -Wl,--end-group
	@echo $(call FORMAT_FOR_ECHO,### Created: "$(PRODUCT)")


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


%.obj : %.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : %.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : %.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : %.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : %.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : %.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ex/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/mc/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/pm/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/pm_st/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/pm_st/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/pm_st/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/pm_st/src/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/pm_st/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/pm_st/src/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/pm_st/src/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/pm_st/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ssc_core/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/simulink/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/simulink/src/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/simulink/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/simulink/src/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/simulink/src/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/simulink/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


solenoid_valve_curtain_v1_109_96c7c979_1_ds.obj : $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_96c7c979_1_ds.c
	$(CC) $(CFLAGS) -o "$@" "$<"


solenoid_valve_curtain_v1_109_96c7c979_1_ds_log.obj : $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_96c7c979_1_ds_log.c
	$(CC) $(CFLAGS) -o "$@" "$<"


solenoid_valve_curtain_v1_109_96c7c979_1_ds_obs_act.obj : $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_96c7c979_1_ds_obs_act.c
	$(CC) $(CFLAGS) -o "$@" "$<"


solenoid_valve_curtain_v1_109_96c7c979_1_ds_dxf_p.obj : $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_96c7c979_1_ds_dxf_p.c
	$(CC) $(CFLAGS) -o "$@" "$<"


solenoid_valve_curtain_v1_109_96c7c979_1_ds_obs_il.obj : $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_96c7c979_1_ds_obs_il.c
	$(CC) $(CFLAGS) -o "$@" "$<"


solenoid_valve_curtain_v1_109_96c7c979_1_ds_tdxf_p.obj : $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_96c7c979_1_ds_tdxf_p.c
	$(CC) $(CFLAGS) -o "$@" "$<"


solenoid_valve_curtain_v1_109_96c7c979_1_ds_obs_all.obj : $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_96c7c979_1_ds_obs_all.c
	$(CC) $(CFLAGS) -o "$@" "$<"


solenoid_valve_curtain_v1_109_96c7c979_1_ds_dxf.obj : $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_96c7c979_1_ds_dxf.c
	$(CC) $(CFLAGS) -o "$@" "$<"


solenoid_valve_curtain_v1_109_96c7c979_1_ds_acon_p.obj : $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_96c7c979_1_ds_acon_p.c
	$(CC) $(CFLAGS) -o "$@" "$<"


solenoid_valve_curtain_v1_109_96c7c979_1_ds_obs_exp.obj : $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_96c7c979_1_ds_obs_exp.c
	$(CC) $(CFLAGS) -o "$@" "$<"


solenoid_valve_curtain_v1_109_96c7c979_1_ds_f.obj : $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_96c7c979_1_ds_f.c
	$(CC) $(CFLAGS) -o "$@" "$<"


solenoid_valve_curtain_v1_109_96c7c979_1.obj : $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_96c7c979_1.c
	$(CC) $(CFLAGS) -o "$@" "$<"


solenoid_valve_curtain_v1_109_96c7c979_1_gateway.obj : $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_96c7c979_1_gateway.c
	$(CC) $(CFLAGS) -o "$@" "$<"


solenoid_valve_curtain_v1_109_77b42695_1_ds.obj : $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_77b42695_1_ds.c
	$(CC) $(CFLAGS) -o "$@" "$<"


solenoid_valve_curtain_v1_109_77b42695_1_ds_log.obj : $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_77b42695_1_ds_log.c
	$(CC) $(CFLAGS) -o "$@" "$<"


solenoid_valve_curtain_v1_109_77b42695_1_ds_obs_act.obj : $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_77b42695_1_ds_obs_act.c
	$(CC) $(CFLAGS) -o "$@" "$<"


solenoid_valve_curtain_v1_109_77b42695_1_ds_dxf_p.obj : $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_77b42695_1_ds_dxf_p.c
	$(CC) $(CFLAGS) -o "$@" "$<"


solenoid_valve_curtain_v1_109_77b42695_1_ds_obs_il.obj : $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_77b42695_1_ds_obs_il.c
	$(CC) $(CFLAGS) -o "$@" "$<"


solenoid_valve_curtain_v1_109_77b42695_1_ds_tdxf_p.obj : $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_77b42695_1_ds_tdxf_p.c
	$(CC) $(CFLAGS) -o "$@" "$<"


solenoid_valve_curtain_v1_109_77b42695_1_ds_obs_all.obj : $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_77b42695_1_ds_obs_all.c
	$(CC) $(CFLAGS) -o "$@" "$<"


solenoid_valve_curtain_v1_109_77b42695_1_ds_dxf.obj : $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_77b42695_1_ds_dxf.c
	$(CC) $(CFLAGS) -o "$@" "$<"


solenoid_valve_curtain_v1_109_77b42695_1_ds_acon_p.obj : $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_77b42695_1_ds_acon_p.c
	$(CC) $(CFLAGS) -o "$@" "$<"


solenoid_valve_curtain_v1_109_77b42695_1_ds_obs_exp.obj : $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_77b42695_1_ds_obs_exp.c
	$(CC) $(CFLAGS) -o "$@" "$<"


solenoid_valve_curtain_v1_109_77b42695_1_ds_f.obj : $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_77b42695_1_ds_f.c
	$(CC) $(CFLAGS) -o "$@" "$<"


solenoid_valve_curtain_v1_109_77b42695_1.obj : $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_77b42695_1.c
	$(CC) $(CFLAGS) -o "$@" "$<"


solenoid_valve_curtain_v1_109_77b42695_1_gateway.obj : $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109_77b42695_1_gateway.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_backsubrr_dbl.obj : $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/rt_backsubrr_dbl.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_forwardsubrr_dbl.obj : $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/rt_forwardsubrr_dbl.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_lu_real.obj : $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/rt_lu_real.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_matrixlib_dbl.obj : $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/rt_matrixlib_dbl.c
	$(CC) $(CFLAGS) -o "$@" "$<"


ert_main.obj : $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/ert_main.c
	$(CC) $(CFLAGS) -o "$@" "$<"


solenoid_valve_curtain_v1_109.obj : $(START_DIR)/solenoid_valve_curtain_v1_109_ert_rtw/solenoid_valve_curtain_v1_109.c
	$(CC) $(CFLAGS) -o "$@" "$<"


#------------------------
# BUILDABLE LIBRARIES
#------------------------

$(MATLAB_ROOT)/extern/physmod/win64/ssc_sli/lib/ssc_sli_ert_mingw64.lib : $(LIBSSC_SLI_ERT_MINGW64_OBJS)
	@echo $(call FORMAT_FOR_ECHO,### Creating static library $@ ...)
	$(AR) $(ARFLAGS)  $@ $(LIBSSC_SLI_ERT_MINGW64_OBJS)


$(MATLAB_ROOT)/extern/physmod/win64/ssc_core/lib/ssc_core_ert_mingw64.lib : $(LIBSSC_CORE_ERT_MINGW64_OBJS)
	@echo $(call FORMAT_FOR_ECHO,### Creating static library $@ ...)
	$(AR) $(ARFLAGS)  $@ $(LIBSSC_CORE_ERT_MINGW64_OBJS)


$(MATLAB_ROOT)/extern/physmod/win64/pm_st/lib/pm_st_ert_mingw64.lib : $(LIBPM_ST_ERT_MINGW64_OBJS)
	@echo $(call FORMAT_FOR_ECHO,### Creating static library $@ ...)
	$(AR) $(ARFLAGS)  $@ $(LIBPM_ST_ERT_MINGW64_OBJS)


$(MATLAB_ROOT)/extern/physmod/win64/mc/lib/mc_ert_mingw64.lib : $(LIBMC_ERT_MINGW64_OBJS)
	@echo $(call FORMAT_FOR_ECHO,### Creating static library $@ ...)
	$(AR) $(ARFLAGS)  $@ $(LIBMC_ERT_MINGW64_OBJS)


$(MATLAB_ROOT)/extern/physmod/win64/ex/lib/ex_ert_mingw64.lib : $(LIBEX_ERT_MINGW64_OBJS)
	@echo $(call FORMAT_FOR_ECHO,### Creating static library $@ ...)
	$(AR) $(ARFLAGS)  $@ $(LIBEX_ERT_MINGW64_OBJS)


$(MATLAB_ROOT)/extern/physmod/win64/pm/lib/pm_ert_mingw64.lib : $(LIBPM_ERT_MINGW64_OBJS)
	@echo $(call FORMAT_FOR_ECHO,### Creating static library $@ ...)
	$(AR) $(ARFLAGS)  $@ $(LIBPM_ERT_MINGW64_OBJS)


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(COMPILER_COMMAND_FILE) $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo $(call FORMAT_FOR_ECHO,### PRODUCT = $(PRODUCT))
	@echo $(call FORMAT_FOR_ECHO,### PRODUCT_TYPE = $(PRODUCT_TYPE))
	@echo $(call FORMAT_FOR_ECHO,### BUILD_TYPE = $(BUILD_TYPE))
	@echo $(call FORMAT_FOR_ECHO,### INCLUDES = $(INCLUDES))
	@echo $(call FORMAT_FOR_ECHO,### DEFINES = $(DEFINES))
	@echo $(call FORMAT_FOR_ECHO,### ALL_SRCS = $(ALL_SRCS))
	@echo $(call FORMAT_FOR_ECHO,### ALL_OBJS = $(ALL_OBJS))
	@echo $(call FORMAT_FOR_ECHO,### LIBS = $(LIBS))
	@echo $(call FORMAT_FOR_ECHO,### MODELREF_LIBS = $(MODELREF_LIBS))
	@echo $(call FORMAT_FOR_ECHO,### SYSTEM_LIBS = $(SYSTEM_LIBS))
	@echo $(call FORMAT_FOR_ECHO,### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS))
	@echo $(call FORMAT_FOR_ECHO,### CFLAGS = $(CFLAGS))
	@echo $(call FORMAT_FOR_ECHO,### LDFLAGS = $(LDFLAGS))
	@echo $(call FORMAT_FOR_ECHO,### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS))
	@echo $(call FORMAT_FOR_ECHO,### CPPFLAGS = $(CPPFLAGS))
	@echo $(call FORMAT_FOR_ECHO,### CPP_LDFLAGS = $(CPP_LDFLAGS))
	@echo $(call FORMAT_FOR_ECHO,### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS))
	@echo $(call FORMAT_FOR_ECHO,### ARFLAGS = $(ARFLAGS))
	@echo $(call FORMAT_FOR_ECHO,### MEX_CFLAGS = $(MEX_CFLAGS))
	@echo $(call FORMAT_FOR_ECHO,### MEX_CPPFLAGS = $(MEX_CPPFLAGS))
	@echo $(call FORMAT_FOR_ECHO,### MEX_LDFLAGS = $(MEX_LDFLAGS))
	@echo $(call FORMAT_FOR_ECHO,### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS))
	@echo $(call FORMAT_FOR_ECHO,### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS))
	@echo $(call FORMAT_FOR_ECHO,### EXECUTE_FLAGS = $(EXECUTE_FLAGS))
	@echo $(call FORMAT_FOR_ECHO,### MAKE_FLAGS = $(MAKE_FLAGS))


clean : 
	$(ECHO) "### Deleting all derived files ..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(ECHO) "### Deleted all derived files."


