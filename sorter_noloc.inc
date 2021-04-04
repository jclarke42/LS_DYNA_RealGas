c
c NOTE: IF YOU CHANGE THIS FILE PLEASE ALSO CHANGE sorter.inc
c WHICH NEEDS TO BE IDENTICAL EXCEPT FOR znnc->nnc, zlczc->lczc
c
      real znnc,zlczc
      integer
     &    ns11, ns12, ns13, ns14, ns15, ns16,
     &    nh11, nh12, nh13, nh14, nh15, nh16,
     &    nt11, nt12, nt13, nt14, nt15, nt16,
     &    nb11, nb12, nb13, nb14, nb15, nb16,
     &    nu11, nu12, nu13, nu14, nu15, nu16,
     &    nd11, nd12, nd13, nd14, nd15, nd16,
     &    nd17, nd18, nd19, nd20, nd21, nd22,
     &    ncf26, ncf27, ncf28,
     &    n_em_26, n_em_27, n_em_28,
     &    nscf08, nscf09, nscf10, nscf13, nscf14,
     &    nhcf11, nhcf12, nhcf13, nhcf14, nhcf15,
     &    nh_em_11, nh_em_12, nh_em_13, nh_em_14, nh_em_15,
     &    lccf1h, lccf1s, lc_em_1h
      common/sorter/znnc, zlczc,
     &    ns11, ns12, ns13, ns14, ns15, ns16,
     &    nh11, nh12, nh13, nh14, nh15, nh16,
     &    nt11, nt12, nt13, nt14, nt15, nt16,
     &    nb11, nb12, nb13, nb14, nb15, nb16,
     &    nu11, nu12, nu13, nu14, nu15, nu16,
     &    nd11, nd12, nd13, nd14, nd15, nd16,
     &    nd17, nd18, nd19, nd20, nd21, nd22,
     &    ncf26, ncf27, ncf28,
     &    n_em_26, n_em_27, n_em_28,
     &    nscf08, nscf09, nscf10, nscf13, nscf14,
     &    nhcf11, nhcf12, nhcf13, nhcf14, nhcf15,
     &    nh_em_11, nh_em_12, nh_em_13, nh_em_14, nh_em_15,
     &    lccf1h, lccf1s, lc_em_1h
c
      MINDEX dm_hnsubgc,dm_hnfegc
      MINDEX dm_bnsubgc,dm_bnfegc
      MINDEX dm_snsubgc,dm_snfegc
      MINDEX dm_tnsubgc,dm_tnfegc
c
      common/dmsorter/
     1 dm_hnsubgc,dm_hnfegc,
     2 dm_bnsubgc,dm_bnfegc,
     3 dm_snsubgc,dm_snfegc,
     4 dm_tnsubgc,dm_tnfegc
c
c The size of the sorter common block.  Used in the restart and dump
c routines.
c
      integer ISORTERSIZE
      parameter (ISORTERSIZE = 68)
