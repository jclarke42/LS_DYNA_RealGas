c     integer       isuper,nsupr
c     common/superp/isuper,nsupr(44)
c
      integer        imxelm,ietype,nmxnbs,inbelms
      real                                             ratmxs     ,rmax
      common/superp1/imxelm,ietype,nmxnbs,inbelms(100),ratmxs(100),rmax
      integer        nelmrt,melmrt,ldspftmp
      common/superp2/nelmrt,melmrt,ldspftmp
c
      integer nsupr2
      integer isuper,nsupr,lclod1,infnm1,lclod2,infnm2
      integer ntarget,level,nspup,ibox
      real    spout,sptim
      real    target,pctstop1,pctstop2,sclmin,sclmax,ncycsp,spfat
      real    spsrch,sptsch,scales,timoffs,ldcurs,pcnt,
     . timpeak,timnegrt,timoscrt,pctosc,pctdrop,sprcnt1,sprcnt2,
     . rtthres,rtlower,rtupper,rilim,rdlim,strike,tfct,tfact
c
      common/superp/isuper,nsupr(3),spout,sptim,nsupr2(5),
     . lclod1,infnm1,lclod2,infnm2,
     . target,pctstop1,pctstop2,sclmin,sclmax,ncycsp,spfat,
     . ntarget,level,spsrch,sptsch,scales(2),timoffs(2),ldcurs(2),pcnt,
     . timpeak,timnegrt,timoscrt,pctosc,pctdrop,sprcnt1,sprcnt2,
     . rtthres,rtlower,rtupper,rilim,rdlim,strike,tfct,tfact,nspup,ibox
c
