# mall0c research

## observations

- watched billy's video
- setup sourcehut account
- tried matrix builds for multiple os - no way to do this
- created build manifest for each os
- create c program that runs malloc(0) and prints pointer
- collected for each os and it passed on each os
- change c program to also write a byte at the returned ptr
- all os passed except for openbsd
- tried to get malloc useable size - only got for macos, alpine, ubuntu, and freebsd
- got notes on windows and macos
- potential github actions automation for windows and macos
- looking at the location of allocated memory for 10 and 0 using memshonk or ld program
- looking at realloc method of finding useable space


## Results

### alpine 3.23

- build succeeded
- returns valid chunk pointer
- wrote to chunk
- allocated regions are adjacent in memory
- procfs

malloc(10) ptr is 0x7fb9ac8d0ca0
malloc(0) ptr is 0x7fb9ac8d0cb0
malloc(10) ptr is 0x7fb9ac8d0cc0
malloc(0) ptr is 0x7fb9ac8d0cd0
allocated size is 0
7fb9ac8ce000-7fb9ac8d1000 rw-p 00000000 00:00 0 

### ubuntu 25.04

- build succeeded
- returns valid chunk pointer
- wrote to chunk
- allocated regions are adjacent in memory
- procfs

malloc(10) ptr is 0x55f44d9512a0
malloc(0) ptr is 0x55f44d9512c0
malloc(10) ptr is 0x55f44d9512e0
malloc(0) ptr is 0x55f44d951300
allocated size is 24
55f44d951000-55f44d972000 rw-p 00000000 00:00 0                          [heap]

### openbsd 7.8

- build failed
- segmentation fault trying to write to chunk
- could not get malloc useable size

malloc(10) ptr is 0x7c3d6e9b720
malloc(0) ptr is 0x7c3d6e7c750
malloc(10) ptr is 0x7c3d6e817a0
malloc(0) ptr is 0x7c3d6e7cd70
allocated size is 0

- the malloc(0)s seem adjacent in memory but not the malloc(10)s

### freebsd 15.x

- build succeeded
- returns valid chunk pointer
- wrote to chunk
- could not get malloc useable size
- needed to separate the def import to use malloc_useable_size
- allocated regions seem grouped based on requested size
- procstat vm PID

malloc(10) ptr is 0x3fb796408000
malloc(0) ptr is 0x3fb796409000
malloc(10) ptr is 0x3fb796408010
malloc(0) ptr is 0x3fb796409008
allocated size is 8

  PID              START                END PRT  RES PRES REF SHD FLAG  TP PATH
 1412     0x3fb796200000     0x3fb796c00000 rw-   29   29   1   0 ----- sw 

### netbsd 10.x

- build succeeded
- returns valid chunk pointer
- wrote to chunk
- could not get malloc useable size
- allocated regions seem grouped based on requested size
- pmap 

malloc(10) ptr is 0x79f8d9363000
malloc(0) ptr is 0x79f8d9364008
malloc(10) ptr is 0x79f8d9363010
malloc(0) ptr is 0x79f8d9364010
allocated size is 0

000079F8D9363000      4K read/write          [ anon ]
000079F8D9364000     68K read/write          [ anon ]

### windows

- build from developer command prompt for VS
- cl main.c
- returns valid chunk pointer
- could not get malloc useable size
- malloc(0) and malloc(10) pointers returned were in the same region
- malloc(0) ended up being near the end address of the region with 0x28 bytes from the end

malloc(10) ptr is 0107E7B8
malloc(0) ptr is 01086FD8
malloc(10) ptr is 0107E7D0
malloc(0) ptr is 01080F98
allocated size is 0

0x000001070000-0x000001087000 (allocb: 0x000001070000) rw- -- 0x000000017000 (private, commit)

- allocated regions seem grouped based on requested size
- malloc(0) ptr seems closer to the end of the memory region
- memshonk

### macos

- build succeeded
- return valid chunk pointer
- wrote to chunk

malloc(10) ptr is 0x6000019bc030
malloc(0) ptr is 0x6000019bc040
malloc(10) ptr is 0x6000019bc050
malloc(0) ptr is 0x6000019bc060
allocated size is 16

- allocated regions are adjacent in memory
- vmmap

malloc(10) ptr is 0x600003164030
malloc(0) ptr is 0x600003164040
malloc(10) ptr is 0x600003164050
malloc(0) ptr is 0x600003164060

MALLOC_NANO  600000000000-600020000000 [512.0M  128K  128K  0K] rw-/rwx SM=PRV  DefaultMallocZone_0x100188000
