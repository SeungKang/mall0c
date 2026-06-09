|  build          |  malloc(0) result                                               | 
|  -------------  |  -------------------------------------------------------------  |
|  alpine 3.23    |  build succeeded - returns valid chunk pointer - wrote to chunk - malloc useable size: 0  |
|  ubuntu 25.04   |  build succeeded - returns valid chunk pointer - wrote to chunk - malloc useable size: 24 |
|  openbsd 7.8    |  build failed - segmentation fault trying to write to chunk - could not get malloc useable size  |
|  freebsd 15.x   |  build succeeded - returns valid chunk pointer - wrote to chunk - could not get malloc useable size |
|  netbsd 10.x    |  build succeeded - returns valid chunk pointer - wrote to chunk - could not get malloc useable size |
