c   ... implicit common ...
C_TASKCOMMON (bki03iloc)
C_TASKCOMMON (bki03rloc)
C_TASKCOMMON (bki04iloc)
      integer lnodim,ndofpn,nnpke,melemt,imlft,imllt,is17loc,is18loc,
     &        imp_mxe
      common/bki03iloc/lnodim(nlq,48),ndofpn,nnpke,melemt,imlft,imllt,
     &                 is17loc,is18loc,imp_mxe
c
      real ske,sme,ske_unsym(nlq,100,100)
      equivalence ( ske, ske_unsym )
      common/bki03rloc/ske(nlq,10440),sme(nlq,10440)
c
      integer lmke
      common/bki04iloc/lmke(nlq,144)
