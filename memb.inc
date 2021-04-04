      common /mem/ mp
      real b(1)
c     dimension b(1)
      pointer(mp,b)
c     common /   / b(1)                                                 npointr
c     include (dyncom)                                                  ibmvs
c     common /dyncom/ b(ndcoml)                                         ibmvs
