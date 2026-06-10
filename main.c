#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#ifdef _WIN32
  #include <process.h>
#else
  #include <unistd.h>
#endif

#ifdef __APPLE__
  #include <malloc/malloc.h>
#endif

#ifdef __FreeBSD__
  #include <malloc_np.h>
#endif

#ifdef __linux__
  #include <malloc.h>
#endif

void read_16_bytes(void *ptr) {
    // Cast to an 8-bit unsigned integer pointer
    uint8_t *byte_ptr = (uint8_t *)ptr;

    // Read and print each byte
    for (int i = 0; i < 16; i++) {
        fprintf(stderr,"Byte %d: 0x%02X\n", i, byte_ptr[i]);
    }
}

int main()
{
  setbuf(stdout, 0);

  void *ptr;
  ptr = malloc(10);
  fprintf(stderr,"malloc(10) ptr is %p\n", ptr);

  ptr = malloc(0);
  fprintf(stderr,"malloc(0) ptr is %p\n", ptr);

  ptr = malloc(10);
  fprintf(stderr,"malloc(10) ptr is %p\n", ptr);

  ptr = malloc(0);
  fprintf(stderr,"malloc(0) ptr is %p\n", ptr);

  //fprintf(stderr,"after malloc...");
  //getchar();

  size_t size = 0; 

#ifdef __APPLE__
  size =  malloc_size(ptr);
#endif

#ifdef __FreeBSD__
  size = malloc_usable_size(ptr);
#endif

#ifdef __linux__
  size = malloc_usable_size(ptr);
#endif

  fprintf(stderr,"allocated size is %zu\n", size);

  fprintf(stderr,"writing to chunk\n");
  ((char *)ptr)[0] = 'A';
  fprintf(stderr,"wrote to chunk\n");

  //read_16_bytes(ptr);

#ifdef _WIN32
  print("%d\n", _getpid());
#else
  printf("%d\n", getpid());
#endif

  fprintf(stderr,"pausing...");

#ifdef _WIN32
  getchar();
#else
  pause();
#endif

  return 0;
}
