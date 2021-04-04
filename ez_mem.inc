c
c***  EASY dynamic memory management
c
c***  C STYLE INCLUDE because of the use of MINDEX
c
c***  ALLOCATE MEMORY:
c         call ez_mem_allocm(i,len,literal_string) 
c         call ez_mem_allocmchk(i,len,literal_string)
c
c       ez_mem_allocm puts a value of 0 in iezp(i) and mezp(i) to indicate
c                  that the memory allocation failed just as mem_allocm
c                  returns a 0 for the memory pointer
c
c       ez_mem_allocmchk terminates the code on failure.
c
c       where 
c         i is the equivalent of the integer used with addlen
c         len is the number of words of memory
c         literal_string is a 'description'
c
c         iezp(i) is the handle you are using
c         mezp(i) is the corresponding MINDEX pointer to i_mem and r_mem 
c
c       therefore iezp points to mezp through memh_ptr, i.e.,
c         mezp(i)=memh_ptr(iezp(i))
c
c***  REALLOCATE MEMORY:
c         call ez_mem_realloc(i,len,literal_string)
c
c***  FREE MEMORY:
c         automatic at end of run
c       or
c         call ez_mem_free(i)
c
c***  RESTARTS:
c         iezp is written to the restart file and
c         mezp is automatically updated during the restart
c
c         memory allocated using this method will automatically 
c         be handled during restart writes and reads
c
c***  IEZP AND MEZP DOCUMENTATION:
c         the equivalent of the ioshl comments in dynai
c         are located in routine ez_mem_allocmchk in atemp.F
c
c***  INITIALIZATION:
c         all arrays initialized to zero in ez_mem_init
c
      integer LENEZMEM  
      parameter (LENEZMEM=1000)
      integer iezp
      MINDEX  mezp
      common/iezpcom/iezp(LENEZMEM)
      common/mezpcom/mezp(LENEZMEM)
