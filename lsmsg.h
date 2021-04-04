#if 0
  This file is C style since it will be included in both Fortran
  and C routines.  It defines meaningful names for the termination
  codes passed to lsmsg.

#endif

#ifndef MSG_INCLUDED
#define MSG_INCLUDED

#define MSG_KEY 0
#define MSG_STR 2000
#define MSG_INI 4000
#define MSG_SOL 5000
#define MSG_MPP 7000
#define MSG_IMP 8000
#define MSG_OTH 9000
#define MSG_FLU 9500
#define MSG_TOT 11000
#endif

