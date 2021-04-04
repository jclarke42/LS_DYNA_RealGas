c
c     includes all fixed dimension material model arrays 
c     EXCEPT mtfailx in matflr.inc
c     if the length is changed here, please also change mtfailx in matflr.inc
c
      integer    LMATFIXD
      parameter (LMATFIXD=2000)
      integer nusrmt,ncma
      integer ibulkp,nusrcn,iorien,ishrmp,ivectr,ihyper,ifipts
      integer ivumat,ihsv_epsp,icmadd,iswumat,ievts
      integer ishrub,icompf,mhyper,mrotate
      common/umatss/nusrmt,ncma,
     .              ibulkp(LMATFIXD),nusrcn(LMATFIXD),
     .              iorien(LMATFIXD),ishrmp(LMATFIXD),
     .              ivectr(LMATFIXD),ihyper(LMATFIXD),
     .              ifipts(LMATFIXD),ivumat(LMATFIXD),
     .              ihsv_epsp(LMATFIXD),icmadd(LMATFIXD),
     .              iswumat(LMATFIXD),ievts(LMATFIXD)
      common/comrbbr/ishrub(LMATFIXD),icompf(LMATFIXD),
     .               mhyper(LMATFIXD),mrotate(LMATFIXD)
