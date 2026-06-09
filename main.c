#include <stdlib.h>
#include <stdio.h>

#ifdef __APPLE__
#include <malloc/malloc.h>
#endif

int main()
{
  void *ptr = malloc(0);
  printf("ptr is %p\n", ptr);

#ifdef __APPLE__
  size_t size =  malloc_size(ptr);
  printf("allocated size is %zu\n", size);
#endif

  return 0;
}
