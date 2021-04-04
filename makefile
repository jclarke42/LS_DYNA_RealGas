#
# Makefile for building lsdyna.exe
# on 'Windows X64
# SMPD
FC=ifort
FLAGS = -c -traceback  -4Yportlib -fp:precise -assume:byterecl,buffered_io -QxW -w -WB \
-fpp -DPCWIN -DINTEL -DIA64 -DAMD64 -DWINX64 -DNET_SECURITY -DXEON64 -DLSTCODE -DLONGFORMAT 
 
SMPS = -DOPENMP -Qopenmp -DDOUBLEXR 
SMPD = -DOPENMP -Qopenmp -DAUTODOUBLE -4R8 -4I8 

FFLAGS = $(FLAGS) $(SMPD)
LFLAGS = -F:180000000 -link -force -nodefaultlib:msvcrt.lib -nodefaultlib:vcomp.lib 
OBJS= dyn21.obj dyn21b.obj couple2other_user.obj
LIBS= libdyna.lib libansys.lib shell32.lib user32.lib comctl32.lib comdlg32.lib Iphlpapi.lib gdi32.lib mkl_intel_ilp64.lib mkl_sequential.lib mkl_core.lib

lsdyna.exe: $(OBJS)
	$(FC) -w -q -o lsdyna.exe $(OBJS) $(LIBS) $(LFLAGS)

dyn21.obj: dyn21.F
	$(FC) $(FFLAGS) dyn21.F 
dyn21b.obj: dyn21b.F
	$(FC) $(FFLAGS) dyn21b.F
couple2other_user.obj: couple2other_user.F
	$(FC) $(FFLAGS) couple2other_user.F

clean:
	-if exist *.obj erase *.obj
#	-if exist del $(OBJS)
	-if exist lsdyna.exe erase lsdyna.exe

