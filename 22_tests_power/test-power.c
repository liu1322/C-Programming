#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned power(unsigned x, unsigned y);

int main(void){
  if (power(0, 0) != 1) {
    printf("failed on 0-0");
    exit(EXIT_FAILURE);
  }
  if (power(-3, 2) != 9) {
    printf("failed on negative base\n");
    exit(EXIT_FAILURE);
  }
  if (power(4294967295, 1) != 4294967295) {
    printf("failed on double\n");
    exit(EXIT_FAILURE);
  }
  if (power(9, 0) != 1) {
    printf("failed on power 0\n");
    exit(EXIT_FAILURE);
  }
  if (power(2.0, 2.0) != pow(2.0, 2.0)){
    printf("failed on double\n");
    exit(EXIT_FAILURE);
  }
  return EXIT_SUCCESS;
}
