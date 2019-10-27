#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n);

int main(void){
  int array1[] = {};
  int array2[] = {1, 2, 5, -6, 8};
  int array3[] = {9};
  int array4[] = {6, 10, 5, 9, -11, 3, 6, 12};
  int array5[] = {-2};
  int array6[] = {1,1,1,3};

  if (maxSeq(array1, 0)) {
    printf("failed on empty\n");
    return EXIT_FAILURE;
  }
  if (maxSeq(array2, 5) != 3) {
    printf("failed on 1 2 5 -6 8, negative case\n");
    return EXIT_FAILURE;
  }
  if (maxSeq(array3, 1) != 1) {
    printf("failed on 9, single case\n");
    return EXIT_FAILURE;
  }
  if (maxSeq(array4, 8) != 4) {
    printf("failed on 6, 10, 5, 9, -11, 3, 6, 12, negative case\n");
    return EXIT_FAILURE;
  }
  if (maxSeq(array5, 1) != 1) {
    printf("failed on -2, negative case\n");
    return EXIT_FAILURE;
  }
  if (maxSeq(array6, 4) != 2) {
    printf("failed on 1,1,1,3, level case\n");
    return EXIT_FAILURE;
  }
  
  return EXIT_SUCCESS;
}
