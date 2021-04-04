c
c msc_nodesg: number of coupled nodes global
c msc_nodes:  number of coupled nodes each processor
c msc_comm,msc_npp,msc_lam: communicator, numproc, and iam
c msc_pnlst:  local node list (pointer to a array)
c msc_pnlstg: global couple node list with user ID (pointer to a array)
c msc_cpl:    coupled data array (pointer to a array)
c msc_buffer: message buffer (pointer to a array) - 3*acc or 3*xyz + 3*v
c
c msc_nsegg: number of coupled segments global
c msc_nseg:  number of coupled segments local
c msc_pslst: local segment list
c msc_scpl:  coupled segment array (pointer to array)
c msc_nslstg:global couple segment with match shell user ID
c
      integer msc_nodesg,msc_nodes,msc_comm,msc_npp,msc_lam,
     . msc_pnlst,msc_pnlstg,msc_cpl,msc_buffer,msc_nsegg,msc_nseg,
     . msc_pslst,idummy,idummy2,msc_scpl,msc_nslstg,msc_psseg,msc_pbox,
     . msc_nbox,msc_nodesnd(0:100),msc_nodercv(0:100),
     . msc_pnodesnd,msc_pnodercv,msc_iam0,msc_pinside
      common /msccpl/ msc_nodesg,msc_nodes,msc_comm,msc_npp,msc_lam,
     . msc_pnlst,msc_pnlstg,msc_cpl,msc_buffer,msc_nsegg,msc_nseg,
     . msc_pslst,idummy,idummy2,msc_scpl,msc_nslstg,msc_psseg,msc_pbox,
     . msc_nbox,msc_nodesnd,msc_nodercv,msc_pnodesnd,msc_pnodercv,
     . msc_pinside
