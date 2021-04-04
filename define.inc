#ifndef HAVE_DEFINE_INC
#define HAVE_DEFINE_INC

#define C_NODIV
#define C_NOMOVE
#define C_OVERLAP
#define C_NOEXTENDREORDER
#define C_NOOPT
#define C_NOARRYXX
#define C_COMPRESS
#define HAVE_CHARACTER_POINTER
#define C_LARGE_NLQ 10000
#define C_LISTVEC
#define C_SMPDEFAULT none
#define C_VEC_NONTEMP

#ifdef  C_SYMBOL
#undef  C_SYMBOL
#endif

#ifdef  ALPHA
#define ADDR64
#define MINDEX integer*8
#endif

#ifdef  IA32
#define MINDEX integer*4
#endif

#ifdef  IA64
#define ADDR64
#undef  HAVE_CHARACTER_POINTER
#define MINDEX integer*8
#endif

#ifdef OPEN64
#undef  HAVE_CHARACTER_POINTER
#endif

#ifdef  HPUX11
#define HPUX
#endif

#ifdef  CRAYT3E
#undef  HAVE_CHARACTER_POINTER
#endif

#ifdef  OSX
#undef  HAVE_CHARACTER_POINTER
#define ADDR64
#define MINDEX integer*8
#endif

#ifdef  CRAYIEEE
#define CRAY
#endif

#ifdef  CRAY
#define C_SYMBOL
#undef  cray
#define A_VECTOR
#define C_IVDEP cdir$ concurrent
#define C_SVDEP cdir$ ivdep
#define C_REPEAT c
#define C_VDOPT c
#define C_SCALAR cdir$ nextscalar
#undef  HAVE_CHARACTER_POINTER
#ifdef  MPP
#define C_TASKCOMMON(x) c
#define C_BEGIN_PARALLEL c
#define C_END_PARALLEL c
#define C_DO_PARALLEL c
#define C_DO_END_NOWAIT c
#define C_ENDDO_PARALLEL c
#define C_DOALL_PARALLEL c
#define C_DYNAMIC c
#define C_GUIDED c
#define C_CHUNKSIZE(x) c
#define C_IF_PARALLEL c
#define C_SHARED1 c
#define C_SHARED2 c
#define C_PRIVATE c
#define C_BEGIN_GUARD c
#define C_END_GUARD c
#define C_ORDERED c
#define C_BEGIN_ORDERED c
#define C_END_ORDERED c
#else
#define C_TASKCOMMON(x) cdir$ taskcommon x
#define C_BEGIN_PARALLEL cmic$ parallel
#define C_END_PARALLEL cmic$ end parallel
#define C_DO_PARALLEL cmic$ do parallel
#define C_DO_END_NOWAIT c
#define C_ENDDO_PARALLEL cmic$ end do
#define C_DOALL_PARALLEL cmic$ do all
#define C_DYNAMIC c
#define C_GUIDED c
#define C_CHUNKSIZE(x) cmic$* chunksize(x)
#define C_IF_PARALLEL cmic$* if 
#define C_SHARED1 cmic$* shared
#define C_SHARED2 cmic$* shared
#define C_PRIVATE cmic$* private 
#define C_BEGIN_GUARD cmic$ guard
#define C_END_GUARD cmic$ end guard
#define C_ORDERED c
#define C_BEGIN_ORDERED cmic$ guard
#define C_END_ORDERED cmic$ end guard
#endif
#define C_DOACROSS c
#define C_SHARE1 c
#define C_SHARE2 c
#define C_LOCAL c
#define C_REDUCTION(x,y) c
#define C_MP_SETLOCK c
#define C_MP_UNSETLOCK c
#endif

#if defined SGI32 || defined SGI64
#ifdef  SGI64
#define ADDR64
#endif
#define SGIONLY
#undef  sgi
#define SGI
#define C_PREFETCH(xx)c*$*prefetch_ref=xx(j+64), stride=32, level=2, kind=wr
#ifdef  SMP
#define C_SYMBOL
#define C_IVDEP c
#define C_REPEAT c
#define C_VDOPT c
#define C_SCALAR cdir$ novector
#define C_TASKCOMMON(x)cdir$ taskcommon x
#define C_BLANK 
#define C_BEGIN_PARALLEL c$doacross 
#define C_END_PARALLEL c
#define C_DO_PARALLEL c
#define C_DO_END_NOWAIT c
#define C_ENDDO_PARALLEL c
#define C_DOALL_PARALLEL c$doacross 
#define C_DYNAMIC c$& ,mp_schedtype=dynamic
#define C_GUIDED c
#define C_STATIC c$& ,mp_schedtype=static
#define C_CHUNKSIZE(x)c$& ,chunk = x
#define C_IF_PARALLEL c$& ,if 
#define C_SHARED1 c$& share
#define C_SHARED2 c$& ,share 
#define C_PRIVATE c$& ,local 
#define C_BEGIN_GUARD c$ C_BLANK C_BLANK C_BLANK call mp_setlock
#define C_END_GUARD c$ C_BLANK C_BLANK C_BLANK call mp_unsetlock
#define C_ORDERED c
#define C_BEGIN_ORDERED c$ C_BLANK C_BLANK C_BLANK call mp_setlock
#define C_END_ORDERED c$ C_BLANK C_BLANK C_BLANK call mp_unsetlock
#define C_DOACROSS c$doacross
#define C_SHARE1 c$& share
#define C_SHARE2 c$& ,share 
#define C_LOCAL c$& ,local
#define C_REDUCTION(x,y)c$& ,reduction(y)
#define C_MP_SETLOCK c$ C_BLANK C_BLANK C_BLANK call mp_setlock
#define C_MP_UNSETLOCK c$ C_BLANK C_BLANK C_BLANK call mp_unsetlock
#else
#ifdef  OPENMP
#define C_SYMBOL
#undef  C_SMPDEFAULT
#define C_SMPDEFAULT shared
#define C_IVDEP c
#define C_REPEAT c
#define C_VDOPT c
#define C_SCALAR c
#define C_TASKCOMMON(x)c$omp threadprivate (/x/)
#define C_BLANK
#define C_BEGIN_PARALLEL c$omp parallel default(C_SMPDEFAULT)
#define C_END_PARALLEL c$omp end parallel
#define C_DO_PARALLEL c$omp do
#define C_DO_END_NOWAIT c$omp end do nowait
#define C_DOALL_PARALLEL c$omp paralleldo default(C_SMPDEFAULT)
#ifdef HYBRID
#define C_ENDDO_NOWAIT c$omp end do nowait
#define C_ENDDO_PARALLEL c$omp end do
#else
#define C_ENDDO_PARALLEL c
#endif
#define C_DYNAMIC c$omp& schedule(dynamic,1)
#define C_STATIC c$omp& schedule(static,1)
#define C_GUIDED(x)c$omp& schedule(guided,x)
#define C_CHUNKSIZE(x)c$omp& chunksize(x)
#define C_IF_PARALLEL c$omp& if
#define C_SHARED1 c$omp& shared
#define C_SHARED2 c$omp& shared
#define C_PRIVATE c$omp& private
#define C_BEGIN_GUARD c$omp critical
#define C_END_GUARD c$omp end critical
#define C_ORDERED c$omp& ordered
#define C_BEGIN_ORDERED c$omp ordered
#define C_END_ORDERED c$omp end ordered
#define C_DOACROSS c$omp paralleldo default(C_SMPDEFAULT)
#define C_SHARE1 c$omp& shared
#define C_SHARE2 c$omp& shared
#define C_LOCAL c$omp& private
#define C_REDUCTION(x,y)c$omp& reduction(x:y)
#define C_MP_SETLOCK c$omp critical
#define C_MP_UNSETLOCK c$omp end critical
#define C_FLUSH c$omp flush
#define C_ATOMIC c$omp atomic
#endif
#endif
#endif

#ifdef  OPENMP
#ifndef C_SYMBOL
#define C_SYMBOL
#define C_IVDEP c
#define C_REPEAT c
#define C_VDOPT c
#define C_SCALAR c
#ifdef  IBMAIX
#define C_TASKCOMMON(x) cibm* threadlocal /x/ ; save /x/
#else
#define C_TASKCOMMON(x) c$omp threadprivate (/x/)
#endif
#define C_BLANK
#define C_BEGIN_PARALLEL c$omp parallel default(C_SMPDEFAULT)
#define C_END_PARALLEL c$omp end parallel
#define C_DO_PARALLEL c$omp do
#define C_DO_END_NOWAIT c$omp end do nowait
#define C_DOALL_PARALLEL c$omp paralleldo default(C_SMPDEFAULT)
#ifdef HYBRID
#define C_ENDDO_NOWAIT c$omp end do nowait
#define C_ENDDO_PARALLEL c$omp end do
#else
#define C_ENDDO_PARALLEL c
#endif
#ifdef FJPP
#define C_DYNAMIC c$omp& schedule(static,1)
#else
#define C_DYNAMIC c$omp& schedule(dynamic,1)
#endif
#define C_STATIC c$omp& schedule(static,1)
#define C_GUIDED(x) c$omp& schedule(guided,x)
#define C_CHUNKSIZE(x) c$omp& chunksize(x)
#define C_IF_PARALLEL c$omp& if
#define C_SHARED1 c$omp& shared
#define C_SHARED2 c$omp& shared
#define C_PRIVATE c$omp& private
#define C_BEGIN_GUARD c$omp critical
#define C_END_GUARD c$omp end critical
#define C_ORDERED c$omp& ordered
#define C_BEGIN_ORDERED c$omp ordered
#define C_END_ORDERED c$omp end ordered
#define C_DOACROSS c$omp paralleldo default(C_SMPDEFAULT)
#define C_SHARE1 c$omp& shared
#define C_SHARE2 c$omp& shared
#define C_LOCAL c$omp& private
#define C_REDUCTION(x,y) c$omp& reduction(x:y)
#define C_MP_SETLOCK c$omp critical
#define C_MP_UNSETLOCK c$omp end critical
#define C_FLUSH c$omp flush
#define C_ATOMIC  c$omp atomic
#endif
#endif

#ifndef C_FLUSH
#define C_FLUSH c
#endif
#ifndef C_ATOMIC
#define C_ATOMIC c
#endif

#ifdef  IA64
#define C_SYMBOL
#if defined A_VECTOR
#undef C_IVDEP
#define C_IVDEP !dir$ivdep
#endif
#endif
#endif

#ifdef  NEC
#define C_SYMBOL
#define ADDR64
#undef  HAVE_CHARACTER_POINTER
#define A_VECTOR
#ifdef  MPP
#define G_VECTOR
#endif
#undef  C_IVDEP
#define C_IVDEP !cdir nodep
#undef  C_SVDEP
#define C_SVDEP !cdir nodep
#undef  C_SCALAR
#define C_SCALAR !cdir novector
#undef  C_NOARRYXX
#define C_NOARRYXX !cdir gthreorder
#undef  C_COMPRESS
#define C_COMPRESS !cdir compress
#undef  C_LISTVEC
#define C_LISTVEC !cdir listvec
#undef  C_ALTCODE
#define C_ALTCODE !cdir altcode=loopcnt
#undef  C_SHORTLOOP
#define C_SHORTLOOP !cdir shortloop
#undef  C_NOMOVEIF
#define C_NOMOVEIF !cdir nomove
#undef  C_NOLOOPCHG
#define C_NOLOOPCHG !cdir noloopchg
#undef  C_UNROLL
#define C_UNROLL(x) !cdir unroll=x
#undef  C_OVERLAP
#define C_OVERLAP *option* -O overlap
#undef  C_NODIV
#define C_NODIV *option* -O nodiv
#undef  C_NOMOVE
#define C_NOMOVE *option* -O nomove
#undef  C_NOEXTENDREORDER
#define C_NOEXTENDREORDER *option* -O noextendreorder
#undef  C_NOOPT
#define C_NOOPT *option* -NO
#undef  C_LOOPCNT
#define C_LOOPCNT *option* -pvctl loopcnt=10000
#endif

#if defined NEC || defined IA64
#ifdef FTRACE
#define C_BLANK
#define C_FTRACE_BEGIN(x) C_BLANK C_BLANK C_BLANK C_BLANK C_BLANK C_BLANK CALL FTRACE_REGION_BEGIN('x')
#define C_FTRACE_END(x) C_BLANK C_BLANK C_BLANK C_BLANK C_BLANK C_BLANK CALL FTRACE_REGION_END('x')
#endif
#endif

#ifdef  FJVPP
#define C_SYMBOL
#define ADDR64
#define A_VECTOR
#ifdef  MPP
#define G_VECTOR
#endif
#define C_IVDEP *VOCL LOOP, NOVREC
#define C_SVDEP *VOCL LOOP, NOVREC
#define C_REPEAT *VOCL LOOP, REPEAT(nlq)
#define C_VDOPT *VOCL LOOP, VDOPT
#define C_SCALAR *VOCL LOOP, SCALAR
#define C_TASKCOMMON(x) c x
#define C_BLANK c
#define C_BEGIN_PARALLEL c
#define C_END_PARALLEL c
#define C_DO_PARALLEL c
#define C_DO_END_NOWAIT c
#define C_ENDDO_PARALLEL c
#define C_DOALL_PARALLEL c
#define C_DYNAMIC c
#define C_GUIDED c
#define C_STATIC c
#define C_CHUNKSIZE(x) c
#define C_IF_PARALLEL c
#define C_SHARED1 c
#define C_SHARED2 c
#define C_PRIVATE c
#define C_BEGIN_GUARD c
#define C_END_GUARD c
#define C_ORDERED c
#define C_BEGIN_ORDERED c
#define C_END_ORDERED c
#define C_DOACROSS c
#define C_SHARE1 c
#define C_SHARE2 c
#define C_LOCAL c
#define C_REDUCTION(x,y) c reduction x,y
#define C_MP_SETLOCK c
#define C_MP_UNSETLOCK c
#endif

#ifdef  HPUX
#if defined SMP && !defined OPENMP
#define C_SYMBOL
#define C_IVDEP c
#define C_REPEAT c
#define C_VDOPT c
#define C_SCALAR c
#define C_BLANK 
#define C_TASKCOMMON(x) c$dir thread_private(/x/)
#define C_BEGIN_PARALLEL c$dir loop_parallel(chunk_size=1)
#define C_ENDDO_PARALLEL c
#define C_DO_PARALLEL c
#define C_DO_END_NOWAIT c
#define C_END_PARALLEL c
#define C_DYNAMIC c
#define C_GUIDED c
#define C_STATIC c
#define C_CHUNKSIZE(x) c
#define C_DOALL_PARALLEL c$dir loop_parallel
#define C_IF_PARALLEL c$dir if 
#define C_SHARED1 c
#define C_SHARED2 c
#define C_PRIVATE c$dir loop_private
#define C_BEGIN_GUARD c$dir critical_section
#define C_END_GUARD c$dir end_critical_section
#define C_ORDERED c
#define C_BEGIN_ORDERED c$dir critical_section
#define C_END_ORDERED c$dir end_critical_section
#define C_DOACROSS c$dir loop_parallel
#define C_SHARE1 c
#define C_SHARE2 c
#define C_LOCAL c$dir loop_private
#define C_REDUCTION(x,y) c$dir reduction(y)
#define C_MP_SETLOCK c$dir critical_section
#define C_MP_UNSETLOCK c$dir end_critical_section
#endif
#endif

#ifdef  HITACHI
#define C_SYMBOL
#define C_IVDEP c
#define C_REPEAT c
#undef  C_SCALAR
#define C_SCALAR c*voption novec
#ifdef SR8000
#define C_PREFETCH(xx) *voption prefetch(xx)
#endif
#define C_VDOPT c
#if defined SMP && !defined OPENMP
#define C_TASKCOMMON(x) *poption tlcommon (x)
#define C_BLANK      
#define C_BEGIN_PARALLEL c
#define C_END_PARALLEL c
#define C_DOALL_PARALLEL *poption parallel
#define C_DO_PARALLEL *poption parallel
#define C_DO_END_NOWAIT c
#ifdef EP8000
#define C_DYNAMIC *poption schedule(dynamic,1)
#define C_STATIC *poption schedule(static,1)
#else
#define C_DYNAMIC *poption cyclic (1)
#define C_STATIC *poption cyclic (1)
#endif
#define C_GUIDED c
#define C_ENDDO_PARALLEL c
#define C_CHUNKSIZE(x) *poption cyclic (x)
#define C_IF_PARALLEL *poption if
#define C_SHARED1 *poption notlocal
#define C_SHARED2 *poption notlocal
#define C_PRIVATE *poption tlocal
#define C_BEGIN_GUARD C_BEGIN_GUARD
#define C_END_GUARD C_END_GUARD
#define C_ORDERED C_ORDERED
#define C_BEGIN_ORDERED C_BEGIN_ORDERED
#define C_END_ORDERED C_END_ORDERED
#define C_DOACROSS *poption parallel
#define C_SHARE1 *poption notlocal
#define C_SHARE2 *poption notlocal
#define C_LOCAL *poption tlocal
#define C_REDUCTION(x,y) C_REDUCTION(x,y)
#define C_MP_SETLOCK C_MP_SETLOCK
#define C_MP_UNSETLOCK C_MP_UNSETLOCK
#endif
#endif

#ifdef  NOVECTOR
#define C_SYMBOL
#define C_IVDEP c
#define C_REPEAT c
#define C_VDOPT c
#define C_SCALAR c
#define C_TASKCOMMON c /x/
#define C_BLANK c
#define C_BEGIN_PARALLEL c
#define C_END_PARALLEL c
#define C_DO_PARALLEL c
#define C_DO_END_NOWAIT c
#define C_ENDDO_PARALLEL c
#define C_DOALL_PARALLEL_DYNAMIC c
#define C_DOALL_PARALLEL c
#define C_CHUNKSIZE(x) c
#define C_IF_PARALLEL c
#define C_SHARED1 c
#define C_SHARED2 c
#define C_PRIVATE c
#define C_BEGIN_GUARD c
#define C_END_GUARD c
#define C_ORDERED c
#define C_BEGIN_ORDERED c
#define C_END_ORDERED c
#define C_DOACROSS c
#define C_SHARE1 c
#define C_SHARE2 c
#define C_LOCAL c
#define C_REDUCTION(x,y) c reduction x,y
#define C_MP_SETLOCK c
#define C_MP_UNSETLOCK c
#endif

#ifndef C_SYMBOL
#define C_IVDEP c
#define C_REPEAT c
#define C_VDOPT c
#define C_SCALAR c
#define C_TASKCOMMON(x) c
#define C_BLANK
#define C_BEGIN_PARALLEL c
#define C_END_PARALLEL c
#define C_DO_PARALLEL c
#define C_DO_END_NOWAIT c
#define C_ENDDO_PARALLEL c
#define C_DOALL_PARALLEL_DYNAMIC c
#define C_DOALL_PARALLEL c
#define C_CHUNKSIZE(x) c
#define C_IF_PARALLEL c
#define C_SHARED1 c
#define C_SHARED2 c
#define C_PRIVATE c
#define C_BEGIN_GUARD c
#define C_END_GUARD c
#define C_ORDERED c
#define C_BEGIN_ORDERED c
#define C_END_ORDERED c
#define C_DOACROSS c
#define C_SHARE1 c
#define C_SHARE2 c
#define C_LOCAL c
#define C_REDUCTION(x,y) c
#define C_MP_SETLOCK c
#define C_MP_UNSETLOCK c
#endif

#ifdef  SUN
#define IEOR xor
#define IAND and
#endif

#ifdef  FJPP
#undef  C_NOOPT
#define C_NOOPT !options -Knofuse
#undef  C_SMPDEFAULT
#define C_SMPDEFAULT none
#define C_PREFETCH(xx) !OCL PREFETCH_READ(xx(j+64))
#define IEOR xor
#define IAND and
#endif

#ifndef MINDEX
#ifdef  ADDR64
#define MINDEX integer*8
#else
#if defined IBMAIX || defined HPUX || defined HITACHI || defined SUN
#define MINDEX integer*4
#else
#define MINDEX integer
#endif
#endif
#endif

#ifdef  CRAY
#define RECLEN 8192
#define RECSTR 4096
#define ZRECSTR 2048
#else
#if defined I4R8 || defined AUTODOUBLE
#if 0
#define RECLEN 65536
#define RECSTR 32768
#define ZRECSTR 512
#else
#define RECLEN 8192
#define RECSTR 4096
#define ZRECSTR 2048
#endif
#else
#define RECLEN 8192
#define RECSTR 1024
#define ZRECSTR 512
#endif
#endif

#if defined AUTODOUBLE || defined CRAY && !defined CRAYSV2_32
#define ZREAL complex*16
#define REALX real*8
#define REAL_SZ 2
#define ZREAL_SZ 4
#define MPI_FLT MPI_DOUBLE_PRECISION
#else
#if defined I4R8
#define ZREAL complex*16
#define REALX real*8
#define REAL_SZ 2
#define ZREAL_SZ 4
#define MPI_FLT MPI_DOUBLE_PRECISION
#else
#define ZREAL complex
#define REALX real
#define REAL_SZ 1
#define ZREAL_SZ 2
#define MPI_FLT MPI_REAL
#endif
#endif

#ifdef BIGID
#define INTEGER8 integer*8
#else
#define INTEGER8 integer
#endif

#if defined CRAY || defined AUTODOUBLE || defined CRAYT3E
#define FLOAT(x) dble(x)
#define DBLE(x) x
#define SNGL(x) x
#define REAL4 real
#define REAL8 real
#define IPRECS 1
#if defined CRAY || defined FJVPP
#define INTEGER4 integer
#else
#define INTEGER4 integer*4
#endif
#else
#define FLOAT(x) float(x)
#define DBLE(x) dble(x)
#define SNGL(x) sngl(x)
#define REAL4 real*4
#define REAL8 real*8
#define IPRECS 2
#define INTEGER4 integer
#endif

#if defined CRAYSV2_32
#undef  FLOAT
#undef  DBLE
#undef  SNGL
#undef  REAL4
#undef  INTEGER4
#undef  MINDEX
#define FLOAT(x) float(x)
#define DBLE(x) dble(x)
#define SNGL(x) sngl(x)
#define REAL4 real
#define INTEGER4 integer*4
#define MINDEX integer*8
#endif

#if defined CRAYSV2_64
#undef  FLOAT
#undef  DBLE
#undef  SNGL
#undef  REAL4
#undef  INTEGER4
#undef  MINDEX
#define FLOAT(x) float(x)
#define DBLE(x) x
#define SNGL(x) x
#define REAL4 real
#define INTEGER4 integer
#define MINDEX integer*8
#define ADDR64
#endif

#include "adios.h"
#define NCPARM 256
