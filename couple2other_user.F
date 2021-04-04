c
c $Id: couple2other_user.F 106721 2016-03-25 23:08:32Z sheng $
c
#include "define.inc"
#ifdef MPP
      subroutine couple2other_reader(icpl2thr_i,icpl2thr_code,
     .                               nameothercode)
      character*60 nameothercode
c
c icpl2thr_i: rank of the line in the reading order of *COUPLE_TO_OTHER_CODES 
c icpl2thr_code: code id (2nd parameter in *COUPLE_TO_OTHER_CODES) 
c nameothercode: name of the input deck to be read by the other code
c          
c 1st code 
      if (icpl2thr_code.eq.1) then
c
c     read data from the file nameothercode 
c
c 2nd code 
      elseif (icpl2thr_code.eq.2) then
c
c     read data from the file nameothercode
c
c 3rd code 
      elseif (icpl2thr_code.eq.3) then
c
c     read data from the file nameothercode
c
c 4th code 
      elseif (icpl2thr_code.eq.4) then
c
c     read data from the file nameothercode
c
      endif
c        
      return
      end
c
      subroutine couple2other_extra(icpl2thr_i,icpl2thr_code,
     .                              icpl2thr_flgextra)
c
c icpl2thr_i: rank of the line in the reading order of *COUPLE_TO_OTHER_CODES
c icpl2thr_code: code id (2nd parameter in *COUPLE_TO_OTHER_CODES) 
c icpl2thr_flgextra: flag to increase the memory in order to communicate 
c between processes:
c              - the velocities (icpl2thr_flgextra=1)
c              - the accelerations (icpl2thr_flgextra=2)
c              - the velocities and accelerations (icpl2thr_flgextra=3)
c
      icpl2thr_flgextra=1
      return
      end
c
      subroutine couple2other_dt(icpl2thr_i,icpl2thr_code,cpl2thr_dt,
     .                           icpl2thr_flag)
c
c icpl2thr_i: rank of the line in the reading order of *COUPLE_TO_OTHER_CODES 
c icpl2thr_code: code id (2nd parameter in *COUPLE_TO_OTHER_CODES) 
c cpl2thr_dt: time step to be computed here by the other codes
c             cpl2thr_dt is initialized by the time step computed by ls-dyna
c             for the next cycle. A minimum over the processes will be taken 
c             after this routine
c icpl2thr_flag: flag = 1 before the minimum over the processes 
c                flag = 2 after  the minimum over the processes and cpl2thr_dt 
c                is this minimum 
c
      return
      end
c
      subroutine couple2other_comm(icpl2thr_i,icpl2thr_code,
     .                             icpl2thr_comm,icpl2thr_nproc,
     .                             icpl2thr_iam)
c
c icpl2thr_i: rank of the line in the reading order of *COUPLE_TO_OTHER_CODES 
c icpl2thr_code: code id (2nd parameter in *COUPLE_TO_OTHER_CODES) 
c icpl2thr_comm: communicator of processes involved in the coupling
c icpl2thr_nproc: number of processes involved in the coupling
c icpl2thr_iam: rank of the current process involved in the coupling
c moreproc: number of processes to be added to icpl2thr_comm
c
c          
c 1st code 
      if (icpl2thr_code.eq.1) then
        moreproc=0
        if (moreproc.gt.0)
     .  call couple2other_comm1(icpl2thr_comm,icpl2thr_nproc,
     .                          icpl2thr_iam,moreproc)
c          
c 2nd code 
      elseif (icpl2thr_code.eq.2) then
        moreproc=0
        if (moreproc.gt.0)
     .  call couple2other_comm1(icpl2thr_comm,icpl2thr_nproc,
     .                          icpl2thr_iam,moreproc)
c          
c 3rd code 
      elseif (icpl2thr_code.eq.3) then
        moreproc=0
        if (moreproc.gt.0)
     .  call couple2other_comm1(icpl2thr_comm,icpl2thr_nproc,
     .                          icpl2thr_iam,moreproc)
c          
c 4th code 
      elseif (icpl2thr_code.eq.4) then
        moreproc=0
        if (moreproc.gt.0) 
     .  call couple2other_comm1(icpl2thr_comm,icpl2thr_nproc,
     .                          icpl2thr_iam,moreproc)
c
      endif
      return
      end
c
      subroutine couple2other_boxminmax(icpl2thr_i,icpl2thr_code,
     .                                  icpl2thr_iam,icpl2thr_nproc,
     .                                  cpl2thr_box,icpl2thr_cntcycle, 
     .                                  icpl2thr_ncycle,x,numberofnode)
c
c icpl2thr_i: rank of the line in the reading order of *COUPLE_TO_OTHER_CODES 
c icpl2thr_code: code id (2nd parameter in *COUPLE_TO_OTHER_CODES) 
c icpl2thr_iam: rank of the current process involved in the coupling
c icpl2thr_nproc: number of processes involved in the coupling
c
c cpl2thr_box(1,icpl2thr_iam)=xmin
c cpl2thr_box(2,icpl2thr_iam)=ymin
c cpl2thr_box(3,icpl2thr_iam)=zmin
c xmin,ymin,zmin: lowest nodal coordinates of the mesh created by the 
c other code for the process icpl2thr_iam   
c
c cpl2thr_box(4,icpl2thr_iam)=xmax
c cpl2thr_box(5,icpl2thr_iam)=ymax
c cpl2thr_box(6,icpl2thr_iam)=zmax
c xmax,ymax,zmax: highest nodal coordinates of the mesh created by the 
c other code for the process icpl2thr_iam
c
c xmin,ymin,zmin and xmax,ymax,zmax forms a box. The structure nodes
c are checked to be in this box or not. If they are, they take part 
c to the coupling and their positions are sent to the other code 
c
c icpl2thr_ncycle : number of cycles between each updates of xmin,ymin,zmin 
c and xmax,ymax,zmax
c If icpl2thr_ncycle=0, compute xmin,ymin,zmin and xmax,ymax,zmax only the 
c first time the code gets in this routine
c icpl2thr_cntcycle: count down before updating xmin,ymin,zmin 
c and xmax,ymax,zmax
c
      real*8 x
      dimension cpl2thr_box(6,0:*),x(3,*)
      logical testloadseg
      testloadseg=.true.
c
c 1st code 
      if (icpl2thr_code.eq.1) then
c
        icpl2thr_ncycle=0
        icpl2thr_cntcycle=icpl2thr_cntcycle-1
        if (icpl2thr_cntcycle.eq.0) then
          icpl2thr_cntcycle=icpl2thr_ncycle 
c
c xmin,ymin,zmin and xmax,ymax,zmax from the 1st code and for icpl2thr_iam
c The program below is just an example based on ls-dyna nodes to compute 
c xmin,ymin,zmin and xmax,ymax,zmax for the *LOAD_SEGMENT application
c The user is invited to modify it to get the minimum and maximum positions 
c of the other code mesh
c
          xmin=1e+30
          ymin=1e+30
          zmin=1e+30
          xmax=-xmin
          ymax=-ymin
          zmax=-zmin
          do i=1,numberofnode
            x1=SNGL(x(1,i))
            x2=SNGL(x(2,i))
            x3=SNGL(x(3,i))
            xmin=min(xmin,x1)
            ymin=min(ymin,x2)
            zmin=min(zmin,x3)
            xmax=max(xmax,x1)
            ymax=max(ymax,x2)
            zmax=max(zmax,x3)
          enddo
          if (xmin.eq.xmax) then
            xmin=-1e+30
            xmax=-xmin
          endif
          if (ymin.eq.ymax) then
            ymin=-1e+30
            ymax=-ymin
          endif
          if (zmin.eq.zmax) then
            zmin=-1e+30
            zmax=-zmin
          endif
          if (testloadseg) then
            xmax=1e30
            zmax=1e30
            xmin=-xmax
            zmin=-zmax
            ylength=1.1/icpl2thr_nproc
            ymin=icpl2thr_iam*ylength-0.55
            ymax=(icpl2thr_iam+1)*ylength-0.55
          endif
          cpl2thr_box(1,icpl2thr_iam)=xmin
          cpl2thr_box(2,icpl2thr_iam)=ymin
          cpl2thr_box(3,icpl2thr_iam)=zmin
          cpl2thr_box(4,icpl2thr_iam)=xmax
          cpl2thr_box(5,icpl2thr_iam)=ymax
          cpl2thr_box(6,icpl2thr_iam)=zmax
        endif
c          
c 2nd code 
      elseif (icpl2thr_code.eq.2) then
c
c xmin,ymin,zmin and xmax,ymax,zmax from the 1st code and for icpl2thr_iam
c The program below is just an example based on ls-dyna nodes to compute 
c xmin,ymin,zmin and xmax,ymax,zmax for the motor application
c The user is invited to modify it to get the minimum and maximum positions 
c of the other code mesh
c
        icpl2thr_ncycle=0
        icpl2thr_cntcycle=icpl2thr_cntcycle-1
        if (icpl2thr_cntcycle.eq.0) then
          icpl2thr_cntcycle=icpl2thr_ncycle
          xmax=0.0770445
          xlength=2*xmax
          xmin=-xmax
          ymin=xmin
          ymax=xmax
          zmin=0.0
          zmax=0.18018
          cpl2thr_box(1,icpl2thr_iam)=xmin+icpl2thr_iam*xlength
          cpl2thr_box(2,icpl2thr_iam)=ymin
          cpl2thr_box(3,icpl2thr_iam)=zmin
          cpl2thr_box(4,icpl2thr_iam)=xmax+icpl2thr_iam*xlength
          cpl2thr_box(5,icpl2thr_iam)=ymax
          cpl2thr_box(6,icpl2thr_iam)=zmax
        endif
c
c 3rd code 
      elseif (icpl2thr_code.eq.3) then
c
        icpl2thr_ncycle=0
        icpl2thr_cntcycle=icpl2thr_cntcycle-1
        if (icpl2thr_cntcycle.eq.0) then
          icpl2thr_cntcycle=icpl2thr_ncycle 
        endif
c
c 4th code 
      elseif (icpl2thr_code.eq.4) then
c
        icpl2thr_ncycle=0
        icpl2thr_cntcycle=icpl2thr_cntcycle-1
        if (icpl2thr_cntcycle.eq.0) then
          icpl2thr_cntcycle=icpl2thr_ncycle 
        endif
c
      endif
c
      return
      end
c
      subroutine couple2other_givex(icpl2thr_i,icpl2thr_code,
     .                              cpl2thr_t,cpl2thr_dt,cpl2thr_tend,
     .                              x,v,f,temp,ncycle_init,ncycle,
     .                              icpl2thr_jr2id,icpl2thr_njr,
     .                              icpl2thr_sg2jr,icpl2thr_jr2sg,
     .                              icpl2thr_csg,icpl2thr_ncsg,
     .                              cpl2thr_box,icpl2thr_iam,
     .                              cpl2thr_nproc,icpl2thr_comm,
     .                              icpl2thr_nvar,icpl2thr_flgextra,
     .                              cpl2thr_rcv,icpl2thr_rcv,
     .                              cpl2thr_snd,icpl2thr_snd,
     .                              icpl2thr_nrcv,share)
c
       include 'mpif.h'
c
c icpl2thr_i: rank of the line in the reading order of *COUPLE_TO_OTHER_CODES 
c icpl2thr_code: code id (2nd parameter in *COUPLE_TO_OTHER_CODES) 
c icpl2thr_t: time 
c icpl2thr_dt: time step
c x: nodal positions available on the current process
c v: nodal velocities available on the current process
c f: accelerations (for the call of couple2other_givex) of forces
c    (for the call of couple2other_getf)  available on the current process
c temp: nodal temperature
c ncycle: number of cycles
c ncycle_init: initial value of ncycle
c
c Nomenclature:
c - jr : rank of a node in the nodal list used for the coupling
c - id : user id of a node
c - sg : segment (a segment is a face of 4 nodes)
c - rcv: data received by the current process
c - snd: data to be sent by the current process
c 
c Example:
c jr |  id        Mesh of the faces:
c ---|----           
c  1 |  18            18 -------4578 ------179 ------ 676          
c  2 | 359             |          |          |          |
c  3 |  24             |          |          |          |
c  4 |4578             |          |          |          |
c  5 |  71           359 ------- 24 ------- 71 ------- 55  
c  6 | 179
c  7 |  55        Segments in the input deck:
c  8 | 676
c ...| ...        *SET_SEGMENT
c                 18,359,24,4578
c                 4578,24,71,179
c                 179,71,55,676
c                 ... 
c
c icpl2thr_jr2id : maps the rank of a node jr to its user id
c Example from above:
c icpl2thr_jr2id(1)=18
c icpl2thr_jr2id(2)=359
c icpl2thr_jr2id(3)=24
c icpl2thr_jr2id(4)=4578
c icpl2thr_jr2id(5)=71
c icpl2thr_jr2id(6)=179
c icpl2thr_jr2id(7)=55
c icpl2thr_jr2id(8)=676
c ....
c icpl2thr_jr2id(icpl2thr_njr)=...
c 
c icpl2thr_njr : total number of nodes forming the segments (max of jr)
c
c icpl2thr_sg2jr : list of ranks jr of 4 nodes forming the segment sg  
c Example from above:
c For the 1st segment isg=1, icpl2thr_sg2jr(1,1)=1
c                            icpl2thr_sg2jr(2,1)=2 
c                            icpl2thr_sg2jr(3,1)=3 
c                            icpl2thr_sg2jr(4,1)=4 
c                            icpl2thr_sg2jr(5,1)=element_id 
c For the 2nd segment isg=2, icpl2thr_sg2jr(1,2)=4
c                            icpl2thr_sg2jr(2,2)=3 
c                            icpl2thr_sg2jr(3,2)=5 
c                            icpl2thr_sg2jr(4,2)=6 
c                            icpl2thr_sg2jr(5,2)=element_id
c For the 3rd segment isg=3, icpl2thr_sg2jr(1,3)=6
c                            icpl2thr_sg2jr(2,3)=5 
c                            icpl2thr_sg2jr(3,3)=7 
c                            icpl2thr_sg2jr(4,3)=8 
c                            icpl2thr_sg2jr(5,3)=element_id 
c ....
c element_id is the internal id of the element on which the segment is attached: 
c - If it's positive, the element is a solid
c - If it's negative, the element is a shell
c
c icpl2thr_jr2sg : list of 4 segments connected to nodes with ranks jr
c Example from above:
c For the 1st node (jr=1)  , icpl2thr_jr2sg(1,1)=1
c                            icpl2thr_jr2sg(2,1)=0 
c                            icpl2thr_jr2sg(3,1)=0 
c                            icpl2thr_jr2sg(4,1)=0 
c For the 2nd node (jr=2)  , icpl2thr_jr2sg(1,2)=1
c                            icpl2thr_jr2sg(2,2)=0 
c                            icpl2thr_jr2sg(3,2)=0 
c                            icpl2thr_jr2sg(4,2)=0 
c For the 3rd node (jr=3)  , icpl2thr_jr2sg(1,3)=1
c                            icpl2thr_jr2sg(2,3)=2 
c                            icpl2thr_jr2sg(3,3)=0 
c                            icpl2thr_jr2sg(4,3)=0 
c ....
c
c icpl2thr_jr2sg : list of 4 segments connected to nodes with ranks jr
c 
c
c
c icpl2thr_csg: list of the segment ranks isg found to be inside the box
c               defined by the routine couple2other_boxminmax.
c               If at least one of the 4 nodes of a segment is inside the box,
c               the segment is listed in icpl2thr_csg.
c               The segments of this list are involved in the coupling with
c               the mesh created by the other code for the current process 
c               icpl2thr_iam
c               
c icpl2thr_ncsg: number of segments in icpl2thr_csg
c 
c cpl2thr_rcv: nodal positions (+ other data depending on icpl2thr_flgextra) 
c              received by other processes
c icpl2thr_rcv(1,*): nodal rank jr for each positions (+data) in  cpl2thr_rcv  
c                    this integer array uses the same memory than cpl2thr_rcv
c
c icpl2thr_nvar: number of variables in cpl2thr_rcv ( jr + number of data) 
c
c icpl2thr_flgextra: flag defined by couple2other_extra to increase the number
c                    of data
c    if icpl2thr_flgextra=0, icpl2thr_nvar=4 and onlyi the rank jr and nodal 
c                            positions are received in cpl2thr_rcv by the 
c                            current process
c    if icpl2thr_flgextra=1, icpl2thr_nvar=7 and the rank jr, positions and 
c                            velocities are received in cpl2thr_rcv by the 
c                            current process
c    if icpl2thr_flgextra=2, icpl2thr_nvar=7 and the rank jr, positions and 
c                            accelerations are received in cpl2thr_rcv by 
c                            the current process
c    if icpl2thr_flgextra=3, icpl2thr_nvar=7 and the rank jr, positions, 
c                            velocities and accelerations are
c                            received in cpl2thr_rcv by the current process
c
c icpl2thr_nrcv : number of nodes received by the current process
c                 icpl2thr_nrcv*icpl2thr_nvar is the size of cpl2thr_rcv
c
c cpl2thr_snd: array to send forces back to the other process
c icpl2thr_snd(1,*): nodal rank jr for each forces (+data) in cpl2thr_snd  
c                    cpl2thr_snd and icpl2thr_snd uses the same memory than 
c                    cpl2thr_rcv
c
c share: array of 0 and 1 used for the shared nodes
c        For example, if the processes 3, 5 and 10 share the same node nd, 
c        share(nd)=1 for the highest process 10 and share(nd)=0 for the 2 
c        other share(nd) is always 1 for an internal node (a node not 
c        shared by several processes)             
c
c see couple2other_getf for an example applying a constant and uniform 
c pressure like *LOAD_SEGMENT_SET
c
      dimension icpl2thr_jr2id(*),icpl2thr_sg2jr(5,*),icpl2thr_csg(*),
     .          cpl2thr_box(6,0:*),icpl2thr_jr2sg(4,*)
      real*8 x
      dimension x(3,*),v(3,*),f(3,*),share(*),temp(*)
      dimension cpl2thr_rcv(icpl2thr_nvar,*),
     .         icpl2thr_rcv(icpl2thr_nvar,*)
      dimension cpl2thr_snd(4,*),icpl2thr_snd(4,*)
c          
      MINDEX malloc
      common/cpl2thr_comuser/ptr_rcv,ptr_jr2rcv
      common/cpl2thr_comuser1/isze_rcv
      pointer(ptr_rcv,rcv)
      pointer(ptr_jr2rcv,jr2rcv)
      dimension rcv(icpl2thr_nvar-1,*),jr2rcv(*)
c          
c 1st code 
      if (icpl2thr_code.eq.1) then
c Since cpl2thr_rcv and cpl2thr_snd have the same memory, the data (positions,
c  ...) received from the other processes are saved in a temporary memory
c
        if (ncycle.eq.ncycle_init) then
          ptr_rcv=0
          isze_rcv=0
#ifdef AUTODOUBLE
          ptr_jr2rcv=malloc(icpl2thr_njr*8)
#else
          ptr_jr2rcv=malloc(icpl2thr_njr*4)
#endif
        elseif (cpl2thr_t.ge.cpl2thr_tend) then
          if (ptr_rcv.ne.0) call free(ptr_rcv)
          if (ptr_jr2rcv.ne.0) call free(ptr_jr2rcv)
          return
        endif
        isze_rcvnew=(icpl2thr_nvar-1)*icpl2thr_nrcv
        if (isze_rcv.lt.isze_rcvnew) then
          isze_rcv=isze_rcvnew
#ifdef AUTODOUBLE
          ptr_rcv=malloc(isze_rcv*8)
#else
          ptr_rcv=malloc(isze_rcv*4)
#endif
        endif
c
        do jrcv=1,icpl2thr_nrcv
          do j=2,icpl2thr_nvar
            rcv(j-1,jrcv)=cpl2thr_rcv(j,jrcv)
            cpl2thr_rcv(j,jrcv)=0.0
          enddo
        enddo
c
c jr2rcv maps the rank jr to the rank of each node received in cpl2thr_rcv
c
        do jr=1,icpl2thr_njr
          jr2rcv(jr)=0
        enddo
        do jrcv=1,icpl2thr_nrcv
          jr=icpl2thr_rcv(1,jrcv)
          if (jr2rcv(jr).eq.0) jr2rcv(jr)=jrcv
          icpl2thr_rcv(1,jrcv)=0
        enddo
c          
c 2nd code 
      elseif (icpl2thr_code.eq.2) then
c
c 3rd code 
      elseif (icpl2thr_code.eq.3) then
c
c 4th code 
      elseif (icpl2thr_code.eq.4) then
c
      endif
c        
      return
      end
c
      subroutine couple2other_getf(icpl2thr_i,icpl2thr_code,
     .                             cpl2thr_t,cpl2thr_dt,cpl2thr_tend,
     .                             x,v,f,temp,ncycle_init,ncycle,
     .                             icpl2thr_jr2id,icpl2thr_njr,
     .                             icpl2thr_sg2jr,icpl2thr_jr2sg,
     .                             icpl2thr_csg,icpl2thr_ncsg,
     .                             cpl2thr_box,icpl2thr_iam,
     .                             cpl2thr_nproc,icpl2thr_comm,
     .                             icpl2thr_nvar,icpl2thr_flgextra,
     .                             cpl2thr_rcv,icpl2thr_rcv,
     .                             cpl2thr_snd,icpl2thr_snd,
     .                             icpl2thr_nrcv,share)
       include 'mpif.h'
c       include 'alecom.inc'
c
c icpl2thr_i: rank of the line in the reading order of *COUPLE_TO_OTHER_CODES 
c icpl2thr_code: code id (2nd parameter in *COUPLE_TO_OTHER_CODES) 
c cpl2thr_x4f: nodal coupling forces on the segments listed in icpl2thr_csg 
c icpl2thr_t: time 
c icpl2thr_dt: time step
c cpl2thr_tend: termination time
c x: nodal positions available on the current process
c v: nodal velocities available on the current process
c f: accelerations (for the call of couple2other_givex) or forces
c    (for the call of couple2other_getf)  available on the current process
c temp: nodal temperature
c
c see couple2other_givex for the definition of all the variables
c
      dimension icpl2thr_jr2id(*),icpl2thr_sg2jr(5,*),icpl2thr_csg(*),
     .          cpl2thr_box(6,0:*),icpl2thr_jr2sg(4,*)
      real*8 x
      dimension x(3,*),v(3,*),f(3,*),share(*),temp(*)
      dimension cpl2thr_rcv(icpl2thr_nvar,*),
     .         icpl2thr_rcv(icpl2thr_nvar,*)
      dimension cpl2thr_snd(4,*),icpl2thr_snd(4,*)
c          
      MINDEX malloc
      common/cpl2thr_comuser/ptr_rcv,ptr_jr2rcv
      common/cpl2thr_comuser2/ipstonflag,iswtch
      pointer(ptr_rcv,rcv)
      pointer(ptr_jr2rcv,jr2rcv)
      dimension rcv(icpl2thr_nvar-1,*),jr2rcv(*)
      dimension xs(3,4)
c
c 1st code 
      if (icpl2thr_code.eq.1) then
c
c This code is an example applying an uniform and constant pressure over a 
c segment set like *LOAD_SEGMENT_SET
c 
c The nodal positions received by the other processes are the 3 first 
c in cpl2thr_rcv
c The forces should be stored in cpl2thr_snd to be sent to the other processes
c
c loop over the coupling segments to integrate the constant pressure pres over
c the segment area and distribute the resulting forces to the nodes. 
c The forces are cumulated in cpl2thr_snd to send back or f() if the node 
c belongs to the processor
c
        do i=1,icpl2thr_ncsg
          isg=icpl2thr_csg(i)
          do j=1,4
            jr=icpl2thr_sg2jr(j,isg)
c jr2rcv(jr)=0 means the current process has this node
            if (jr2rcv(jr).eq.0) then
c icpl2thr_jr2id maps the rank jr to the user id 
c (see comments in couple2other_givex) 
c lqf8 maps the user id to the internal id
              id=lqf8(icpl2thr_jr2id(jr),1)
              do k=1,3
                xs(k,j)=SNGL(x(k,id)) 
              enddo
            else
c jr2rcv(jr)=jrcv means the current process does not have this node and it 
c received the positions from another process  
              jrcv=jr2rcv(jr)
              do k=1,3
                xs(k,j)=rcv(k,jrcv)
              enddo
            endif
          enddo
c If the center of the segment is in the box defined by couple2other_boxminmax,
c a pressure is applied on this segment 
          xc=0.0
          yc=0.0
          zc=0.0
          do j=1,4
            xc=xc+xs(1,j) 
            yc=yc+xs(2,j) 
            zc=zc+xs(3,j) 
          enddo
          xc=0.25*xc
          yc=0.25*yc
          zc=0.25*zc
          xmin=cpl2thr_box(1,icpl2thr_iam)
          ymin=cpl2thr_box(2,icpl2thr_iam)
          zmin=cpl2thr_box(3,icpl2thr_iam)
          xmax=cpl2thr_box(4,icpl2thr_iam)
          ymax=cpl2thr_box(5,icpl2thr_iam)
          zmax=cpl2thr_box(6,icpl2thr_iam)
          if (xc.ge.xmin.and.yc.ge.ymin.and.zc.ge.zmin.and.
     .        xc.le.xmax.and.yc.le.ymax.and.zc.le.zmax) then
            x13=xs(1,3)-xs(1,1)
            x24=xs(1,4)-xs(1,2)
            y13=xs(2,3)-xs(2,1)
            y24=xs(2,4)-xs(2,2)
            z13=xs(3,3)-xs(3,1)
            z24=xs(3,4)-xs(3,2)
            fs1=x13-x24
            ft1=x13+x24
            fs2=y13-y24
            ft2=y13+y24
            fs3=z13-z24
            ft3=z13+z24
            fnx=0.25*(fs2*ft3-ft2*fs3)
            fny=0.25*(fs3*ft1-ft3*fs1)
            fnz=0.25*(fs1*ft2-ft1*fs2)
            pres=1e3
            do j=1,4
              jr=icpl2thr_sg2jr(j,isg)
              id=lqfe8(icpl2thr_jr2id(jr),1)
              if (id.gt.0) then
c The forces are directly stored in f(3,*) if the current process has this node
c (and it didn't receive it from another process) 
                f(1,id)=f(1,id)+0.25*pres*fnx*share(id)
                f(2,id)=f(2,id)+0.25*pres*fny*share(id)
                f(3,id)=f(3,id)+0.25*pres*fnz*share(id)
              endif
              if (jr2rcv(jr).ne.0) then
c The forces are stored in cpl2thr_snd to be sent back to the process that 
c gives the nodal position for this node 
                jrcv=jr2rcv(jr)
               icpl2thr_snd(1,jrcv)=jr
                cpl2thr_snd(2,jrcv)=cpl2thr_snd(2,jrcv)
     .                             +0.25*pres*fnx
                cpl2thr_snd(3,jrcv)=cpl2thr_snd(3,jrcv)
     .                             +0.25*pres*fny
                cpl2thr_snd(4,jrcv)=cpl2thr_snd(4,jrcv)
     .                             +0.25*pres*fnz
              endif
            enddo
          endif
        enddo
c          
c 2nd code 
      elseif (icpl2thr_code.eq.2) then
c
c This code is an example of 4 cylinders with pistons from an engine.
c 4 processors should be used as each proc. has its own cylinder for simplicity:
c rcv() and jr2rcv() are not necessary.
c The thermodynamical pressure applied on each piston and cylinder is computed.
c LS-DYNA gives the new positions of the pistons.
c 
        radius=0.0385222
        pi=3.14159265
        surf=pi*radius**2
        volmin=40e-6
        volmax=440e-6
        zpistonmin=8.58e-3
        zpistonmax=9.438e-2
        xmastot=0.2555168409e-3
        xmascarb=0.0134807161e-3
        r=287
        gamma=1.4
        cp=r*gamma/(gamma-1)
        cv=r/(gamma-1)
        volratio=(volmax/volmin)**gamma
        ro1=xmastot/volmax
        p5=1e5
        p1=0.5*p5
        p2=p1*volratio 
        t2=p2*volmin/(xmastot*r)
        rendementcombustion=0.95
        pci=44000e3
        q3=pci*xmascarb*rendementcombustion
        t3=q3/(xmastot*cv)+t2
        p3=xmastot*r*t3/volmin
        p4=p3/volratio 
        isg=icpl2thr_csg(1)
        jr=icpl2thr_sg2jr(1,isg)
        zmax=cpl2thr_box(6,icpl2thr_iam)
        id=lqf8(icpl2thr_jr2id(jr),1)
        zpiston=zmax-SNGL(x(3,id))
        vol=zpiston*surf
        if (cpl2thr_t.eq.0) then
          if (icpl2thr_iam.eq.1) then
            ipstonflag=3
          elseif (icpl2thr_iam.eq.0) then
            ipstonflag=2
          elseif (icpl2thr_iam.eq.2) then
            ipstonflag=1
          elseif (icpl2thr_iam.eq.3) then
            ipstonflag=4
          endif
          iswtch=1
        endif
        tol=1e-3
        if (zpiston.ge.zpistonmax-tol.or.zpiston.le.zpistonmin+tol) then
          if (iswtch.eq.0) then
            iswtch=1
            ipstonflag=ipstonflag+1
          endif
        else
          iswtch=0
        endif
        if (ipstonflag.eq.5) ipstonflag=1
c
c loop over the coupling segments to integrate the constant pressure pres over the segment
c area and distribute the resulting forces to the nodes. The forces are cumulated in f
c
        if (ipstonflag.eq.1) then
          pres=(p1-p5)/(volmax-volmin)*(vol-volmin)+p5
        elseif (ipstonflag.eq.2) then
          volratio=(volmax/vol)**gamma
          pres=p1*volratio
        elseif (ipstonflag.eq.3) then
          volratio=(volmin/vol)**gamma
          pres=p3*volratio
        elseif (ipstonflag.eq.4) then
          pres=p5
        endif
c        alerefp=pres
c
        fz=0.0
        do i=1,icpl2thr_ncsg
          isg=icpl2thr_csg(i)
          do j=1,4
            jr=icpl2thr_sg2jr(j,isg)
            id=lqf8(icpl2thr_jr2id(jr),1)
            do k=1,3
              xs(k,j)=SNGL(x(k,id)) 
            enddo
          enddo
c If the center of the segment is in the box defined by couple2other_boxminmax, a
c pressure is applied on this segment 
          xc=0.0
          yc=0.0
          zc=0.0
          do j=1,4
            xc=xc+xs(1,j) 
            yc=yc+xs(2,j) 
            zc=zc+xs(3,j) 
          enddo
          xc=0.25*xc
          yc=0.25*yc
          zc=0.25*zc
          xmin=cpl2thr_box(1,icpl2thr_iam)
          ymin=cpl2thr_box(2,icpl2thr_iam)
          zmin=cpl2thr_box(3,icpl2thr_iam)
          xmax=cpl2thr_box(4,icpl2thr_iam)
          ymax=cpl2thr_box(5,icpl2thr_iam)
          zmax=cpl2thr_box(6,icpl2thr_iam)
          if (xc.ge.xmin.and.yc.ge.ymin.and.zc.ge.zmin.and.
     .        xc.le.xmax.and.yc.le.ymax.and.zc.le.zmax) then
            x13=xs(1,3)-xs(1,1)
            x24=xs(1,4)-xs(1,2)
            y13=xs(2,3)-xs(2,1)
            y24=xs(2,4)-xs(2,2)
            z13=xs(3,3)-xs(3,1)
            z24=xs(3,4)-xs(3,2)
            fs1=x13-x24
            ft1=x13+x24
            fs2=y13-y24
            ft2=y13+y24
            fs3=z13-z24
            ft3=z13+z24
            fnx=0.25*(fs2*ft3-ft2*fs3)
            fny=0.25*(fs3*ft1-ft3*fs1)
            fnz=0.25*(fs1*ft2-ft1*fs2)
            fz=fz+fnz*pres
            do j=1,4
              jr=icpl2thr_sg2jr(j,isg)
              id=lqfe8(icpl2thr_jr2id(jr),1)
              if (id.gt.0) then
                f(1,id)=f(1,id)+0.25*pres*fnx*share(id)
                f(2,id)=f(2,id)+0.25*pres*fny*share(id)
                f(3,id)=f(3,id)+0.25*pres*fnz*share(id)
              endif
            enddo
          endif
        enddo
        if (icpl2thr_iam.eq.0) then
          fz1=0.0
        elseif (icpl2thr_iam.eq.1) then
          fz1=fz
        elseif (icpl2thr_iam.eq.2) then
          fz1=fz
        elseif (icpl2thr_iam.eq.3) then
          fz1=0.0
        endif
        call MPI_ALLREDUCE(fz1,fz2,1,MPI_REAL,MPI_SUM,
     .    icpl2thr_comm,ierr)
        if (icpl2thr_iam.eq.0.or.icpl2thr_iam.eq.3) then
          f(3,id)=f(3,id)-0.5*fz2
        endif
        if (icpl2thr_iam.eq.0) then
          fz1=fz
        elseif (icpl2thr_iam.eq.1) then
          fz1=0.0
        elseif (icpl2thr_iam.eq.2) then
          fz1=0.0
        elseif (icpl2thr_iam.eq.3) then
          fz1=fz
        endif
        call MPI_ALLREDUCE(fz1,fz2,1,MPI_REAL,MPI_SUM,
     .    icpl2thr_comm,ierr)
        if (icpl2thr_iam.eq.1.or.icpl2thr_iam.eq.2) then
          f(3,id)=f(3,id)-0.5*fz2
        endif
c 
c 3rd code 
      elseif (icpl2thr_code.eq.3) then
c
c 4th code 
      elseif (icpl2thr_code.eq.4) then
c
      endif
c        
      return
      end
#else
      subroutine couple2other_user_dummy
      return
      end
#endif
