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

malloc(10) ptr is 0x7f9e17dd8ca0
malloc(0) ptr is 0x7f9e17dd8cb0
malloc(10) ptr is 0x7f9e17dd8cc0
malloc(0) ptr is 0x7f9e17dd8cd0
allocated size is 0

### ubuntu 25.04

- build succeeded
- returns valid chunk pointer
- wrote to chunk

malloc(10) ptr is 0x570aff0052a0
malloc(0) ptr is 0x570aff0052c0
malloc(10) ptr is 0x570aff0052e0
malloc(0) ptr is 0x570aff005300
allocated size is 24

### openbsd 7.8

- build failed
- segmentation fault trying to write to chunk
- could not get malloc useable size

malloc(10) ptr is 0x7c3d6e9b720
malloc(0) ptr is 0x7c3d6e7c750
malloc(10) ptr is 0x7c3d6e817a0
malloc(0) ptr is 0x7c3d6e7cd70
allocated size is 0

### freebsd 15.x

- build succeeded
- returns valid chunk pointer
- wrote to chunk
- could not get malloc useable size
- needed to separate the def import to use malloc_useable_size

malloc(10) ptr is 0x1037c9e08000
malloc(0) ptr is 0x1037c9e09000
malloc(10) ptr is 0x1037c9e08010
malloc(0) ptr is 0x1037c9e09008
allocated size is 8

### netbsd 10.x

- build succeeded
- returns valid chunk pointer
- wrote to chunk
- could not get malloc useable size

malloc(10) ptr is 0x7d62ece54000
malloc(0) ptr is 0x7d62ece55008
malloc(10) ptr is 0x7d62ece54010
malloc(0) ptr is 0x7d62ece55010
allocated size is 0

### windows

- build from developer command prompt for VS
- cl main.c
- returns valid chunk pointer
- could not get malloc useable size
- malloc(0) and malloc(10) pointers returned were in the same region
- malloc(0) ended up being near the end address of the region with 0x28 bytes from the end

0x000001070000-0x000001087000 (allocb: 0x000001070000) rw- -- 0x000000017000 (private, commit)
malloc(10) ptr is 0107E7B8
malloc(0) ptr is 01086FD8
malloc(10) ptr is 0107E7D0
malloc(0) ptr is 01080F98
allocated size is 0

### macos

- build succeeded
- return valid chunk pointer
- wrote to chunk

malloc(10) ptr is 0x6000019bc030
malloc(0) ptr is 0x6000019bc040
malloc(10) ptr is 0x6000019bc050
malloc(0) ptr is 0x6000019bc060
allocated size is 16
