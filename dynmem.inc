c
c     dynamic memory allocation stuff.  This has to be a C style 
c     include because of the use of MINDEX
c
      integer i_mem(0:1)
      real r_mem(0:1)
      integer*8 i8_mem(0:1)
      real*8 r8_mem(0:1)
      real*8 real8_mem
      MINDEX m_mem(0:1)
      common/dynmem/real8_mem(0:1)
      equivalence (i_mem,r_mem,i8_mem,r8_mem,real8_mem,m_mem)
      MINDEX mem_alloc, mems_alloc,mem_realloc, memh_ptr
      integer mem_length,memh_alloc,memh_realloc,memh_length
      integer memh_enum,memh_enums,memh_attach
c      integer mem_newmark,mem_getmark,memh_getmark
      MINDEX memh_detach,memh_ralloc
      MINDEX m_to_m8
      MINDEX m_to_mm
      MINDEX m8_to_m
#ifndef PCWIN
      external mem_alloc, mems_alloc, mem_realloc, mem_length
      external memh_alloc, memh_realloc, memh_length, memh_ptr
      external memh_enum,memh_attach,memh_detach,memh_ralloc
      external memh_enums
      external m_to_m8
      external m_to_mm
      external m8_to_m
#endif
      MINDEX dm_x,dm_xr,dm_v,dm_vr,dm_a,dm_ar,dm_rots,dm_rotr
      MINDEX dm_xms,dm_xmr,dm_xm2,dm_xmz,dm_xma
      MINDEX dm_xtpz,dm_disp
      MINDEX dm_me1,dm_me2,dm_me3
      MINDEX dm_masp,dm_masr
      MINDEX dm_xrb,dm_yrb,dm_zrb
      MINDEX dm_axrb,dm_ayrb,dm_azrb
      MINDEX dm_rbfx,dm_rbfy,dm_rbfz
      MINDEX dm_n45
      MINDEX dm_rwsx
      integer len_n45,len_n46
      common/dynmem1/ 
     . dm_x,dm_xr,dm_v,dm_vr,dm_a,dm_ar,dm_rots,dm_rotr,
     . dm_xms,dm_xmr,dm_xm2,dm_xmz,dm_xma,
     . dm_xtpz,dm_disp,
     . dm_me1,dm_me2,dm_me3,
     . dm_masp,dm_masr,
     . dm_xrb,dm_yrb,dm_zrb,
     . dm_axrb,dm_ayrb,dm_azrb,
     . dm_rbfx,dm_rbfy,dm_rbfz,
     . dm_n45,dm_rwsx
      common/dynmem1l/len_n45,len_n46
c
      MINDEX mem_allocm,mems_allocm,mem_reallocm,mem_loc
      integer memh_allocm,memh_reallocm
#ifndef PCWIN
      external mem_allocm,mems_allocm,mem_reallocm,mem_loc
      external memh_allocm,memh_reallocm
#endif
      MINDEX mem_allocmchk,mem_allocchk,mems_allocmchk,mems_allocchk
      MINDEX mem_reallocmchk,mem_reallocchk
      integer memh_allocmchk,memh_allocchk
#ifndef PCWIN
      external mem_allocmchk,mem_allocchk,mems_allocmchk,mems_allocchk
      external mem_reallocmchk,mem_reallocchk
      external memh_allocmchk,memh_allocchk
#endif
