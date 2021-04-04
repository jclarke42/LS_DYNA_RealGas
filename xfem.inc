c     Include file for fracture analysis with xfem
c     ictrxfem     0 not an xfem analysis
c                  2 2d/shell only
c                  3 3d only
c                  5 shell and 3d
      integer        ictrxfem,ictrxfem2,iformxfem
      common/xfemctr/ictrxfem,ictrxfem2,iformxfem
c
c     cohesive material constants
c     a(ndtype)    mctype(*)
c     a(ndcohm)    cmcoh(48,*)
c     nmtcox       number of internal variables in each xfem
c     nmtcoh       number of internal variables in each cohesive zone
      integer       ndtype,ndcohm,nmtcox,nmtcoh
      common/cohmat/ndtype,ndcohm,nmtcox,nmtcoh
c       
c     element status
c     ngxfem       number of xfem parts
c     ntxfem       number of elements in xfem parts
c     a(ndinxfem)  inxfems(*) global eid to local (xfem parts) eid
c     a(ndxfems)   ixfems(*) for 2d/shell elements
c     a(ndxfemh)   ixfemh(*) for 3d elements
c     a(ndbfems)   isbfem(*) =1 boundary elements
c     a(ndckopens) ckopen(33,*) crack opening angle, location & nodal forces
      integer        ngxfem,ntxfem,ndinxfem
      integer        ndxfems,ndbfems,ndckopens,ndneighbors,
     &               ndxfemh,ndbfemh,ndckopenh
      common/xfemind/ndxfems,ndbfems,ndckopens,ndneighbors,
     &               ndxfemh,ndbfemh,ndckopenh,
     &               ngxfem,ntxfem,ndinxfem
c
c     non-local strain 
c     xf_xeps(2*ntxfem) non-local strain:local strain
c     xf_nipxfem        ipp
c     xf_nelxfem        ippn
c     xf_dcjp           support
c     xf_nelgxfem       group of eid
c     xf_xyzc           coordinates of element centers 
c     xf_ntipfem        if tip front element, pointed to xytipfem       
c     xf_xytipfem       local tip coordinate to reg. strain
      MINDEX xf_xeps,xf_nipxfem,xf_nelxfem,xf_dcjp,xf_nelgxfem,
     &       xf_xyzc,xf_ntipfem,xf_xytipfem
      common/xfemsmth/xf_xeps,xf_nipxfem,xf_nelxfem,xf_dcjp,xf_nelgxfem,
     &                xf_xyzc,xf_ntipfem,xf_xytipfem
c
c     crack description
c     ncracks      number of cracks
c     mcracks      allocated number of cracks
c     nxfems       number of xfem elements
c     mxfems       allocated number of xfem elements
c     npnods       number of phantom nodes
c     mpnods       allocated number of phantom nodes
c     nxact        number of active xfems
c     nactcks      number of active cracks (after merging)
      integer      ncracks,nxfems,npnods,mcracks,mxfems,mpnods,
     &             nxact,nprexfem,iphstat,nactcks,iformjump,icontip,
     &             icohesive,ixfemmass,ixfemndfc,ixfemsmorder
      real         crklength
      common/cracks/ncracks,nxfems,npnods,mcracks,mxfems,mpnods,
     &              nxact,nprexfem,iphstat,nactcks,crklength,iformjump,
     &              icontip,icohesive,ixfemmass,ixfemndfc,ixfemsmorder
c     ck_nxfems    number of xfems for each crack
c     ck_pairs     element pairs (orig & phantom) for cracks
c     ck_x         crack position in reference coordinates
c     ck_ixesta    crack start element (xfem id)
c     ck_ixeend    crack end element (xfem id)
c     ck_cracks    crack id for active cracks
      MINDEX ck_nxfems,ck_pairs,ck_x,ck_ixesta,ck_ixeend,ck_cracks
      common/ckindex/ck_nxfems,ck_pairs,ck_x,ck_ixesta,ck_ixeend,
     &               ck_cracks
c
c     xfem database
c     xf_phnods    phantom nodes ids
c     xf_m         phantom node mass
c     xf_mr        phantom node mass (rotation)
c     xf_disp      phantom node displacements
c     xf_v         phantom node velocities
c     xf_a         phantom node acceleration/rhs
c     xf_nbc       boundary conditions on phantom nodes
c     xf_nphsta    phamtom node status
c     xf_npcxfm    nodal constraint at crack tip
c     xf_cpcxfm    nodal constraint parameter at crack tip
      MINDEX xf_phnods,xf_m,xf_disp,xf_v,xf_a,xf_nbc,xf_mr
      MINDEX xf_nphsta,xf_npcxfm,xf_cpcxfm
      common/xfnods/xf_phnods,xf_m,xf_disp,xf_v,xf_a,xf_nbc,xf_mr,
     &  xf_nphsta,xf_npcxfm,xf_cpcxfm
c     xf_phelms    phantom element connectivity
c     xf_auxvec    memory for internal variables in phantom elements
c     xf_lavn      start location for internal variables in ph-elements
c     xf_auxcoh    memory for internal variables in cohesive interface
c     xf_lavcoh    start location for int. variables in cohesive zone
c     xf_aratio    area ratios of the two sub-region to whole element
c     xf_ipxfem    number of integration points for xfem (subdomain)
c     xf_npxfem    nodal numbers in subdomains 
      MINDEX xf_phelms,xf_auxvec,xf_lavn,xf_auxcoh,xf_lavcoh,
     &       xf_aratio,xf_ipxfem,xf_npxfem
      common/xfelms/xf_phelms,xf_auxvec,xf_lavn,xf_auxcoh,xf_lavcoh,
     &              xf_aratio,xf_ipxfem,xf_npxfem
c
      integer        ntncog,ncoir
      common/coeleir/ntncog,ncoir(20)
      integer nxfemco,nxfem2
      common/xfemtype2/nxfemco,nxfem2(20)
