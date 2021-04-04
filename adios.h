#if 0
  This file is C style since it will be included in both Fortran
  and C routines.  It defines meaningful names for the termination
  codes passed to adios, because the numbers were getting out of hand.

  Currently, these names replicate the existing numbers, so nothing
  should break as they are phased in.  Once they are in complete
  consistent use, they should be able to be renumbered to anything.
#endif

#ifndef ADIOS_INCLUDED
#define ADIOS_INCLUDED

#define TC_NORMAL 1
#define TC_ERROR 2
#define TC_ERROR_NO_OUTPUT -2
#define TC_ERROR_SYNC 20
#define TC_LICENSE 3
#define TC_TRIM	4
#define TC_MADYRET 5
#define TC_RETURN 6
#define TC_ILLEGAL 99
#define TC_MADYMO -9898
#define TC_NEGVOL -9899
#define TC_RTNKILL -9999

#endif
