
# Results

## alpine 3.23

- build succeeded
- returns valid chunk pointer
- wrote to chunk
- malloc useable size: 0

## ubuntu 25.04

- build succeeded
- returns valid chunk pointer
- wrote to chunk
- malloc useable size: 24

## openbsd 7.8

- build failed
- segmentation fault trying to write to chunk
- could not get malloc useable size

## freebsd 15.x

- build succeeded
- returns valid chunk pointer
- wrote to chunk
- could not get malloc useable size

## netbsd 10.x

- build succeeded
- returns valid chunk pointer
- wrote to chunk
- could not get malloc useable size

## windows

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

## macos
