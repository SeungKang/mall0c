#include <stdlib.h>
#include <stdio.h>

int main()
{
  setbuf(stdout, 0);
  void *ptr = malloc(0);
  printf("ptr is %p\n", ptr);

  size_t size = 0; 

#ifdef __APPLE__
  #include <malloc/malloc.h>
  size =  malloc_size(ptr);
#elif __FreeBSD__
  #include <malloc_np.h>
  size = malloc_usable_size(ptr);
#elif __OpenBSD__
  #include <malloc_np.h>
  size = malloc_usable_size(ptr);
#elif __NetBSD__
  #include <malloc_np.h>
  size = malloc_usable_size(ptr);
#elif __linux__
  #include <malloc.h>
  printf("malloc usable size for linux\n");
  size = malloc_usable_size(ptr);
#endif

  if (size != 0) {
    printf("allocated size is %zu\n", size);
  }

  printf("writing to chunk\n");
  ((char *)ptr)[0] = 'A';
  printf("wrote to chunk\n");

  return 0;
}
