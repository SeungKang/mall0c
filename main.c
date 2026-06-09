#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

void read_16_bytes(void *ptr) {
    // Cast to an 8-bit unsigned integer pointer
    uint8_t *byte_ptr = (uint8_t *)ptr;

    // Read and print each byte
    for (int i = 0; i < 16; i++) {
        printf("Byte %d: 0x%02X\n", i, byte_ptr[i]);
    }
}

int main()
{
  setbuf(stdout, 0);
  void *ptr = malloc(0);
  printf("ptr is %p\n", ptr);

  size_t size = 0; 

#ifdef __APPLE__
  #include <malloc/malloc.h>
  size =  malloc_size(ptr);
//#elif __FreeBSD__
//  #include <malloc_np.h>
//  size = malloc_usable_size(ptr);
//#elif __NetBSD__
//  #include <malloc_np.h>
//  size = malloc_usable_size(ptr);
#elif __linux__
  #include <malloc.h>
  printf("malloc usable size for linux\n");
  size = malloc_usable_size(ptr);
#endif

  printf("allocated size is %zu\n", size);

  printf("writing to chunk\n");
  ((char *)ptr)[0] = 'A';
  printf("wrote to chunk\n");

  read_16_bytes(ptr);

  return 0;
}
