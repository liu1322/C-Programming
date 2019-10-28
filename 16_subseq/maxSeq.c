#include <stdlib.h>
#include <stdio.h>

size_t maxSeq(int * array, size_t n){
  if (n == 0){
    return 0;
  }
  int max = 1;
  int counter = 1;
  for (int i = 1; i < n; i++){
    if (array[i] > array[i-1]){
      counter += 1;
    }
    else{
      counter = 1;
    }
    if (counter > max){
      max = counter;
    }
  }
  return max;
}
