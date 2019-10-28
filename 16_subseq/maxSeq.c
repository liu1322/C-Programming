#include <stdlib.h>
#include <stdio.h>

size_t maxSeq(int * array, size_t n){
  if (n == 0){
    return 0;
  }
  int max = 1;
  int counter = 1;
  for (int i; i < n-1; i++){
    if (array[i] < array[i+1]){
      counter += 1;
    }
    else{
      if (counter > max){
	max = counter;
      }
      counter = 1;
    }
  }
  return max;
}
