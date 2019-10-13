#include <stdio.h>
#include <stdlib.h>

struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

double balance(double balance, retire_info workStage){
  balance = balance + workStage.rate_of_return * balance + workStage.contribution;
  return balance;
}

void retirement(int startAge, double initial, retire_info working, retire_info retired){
  int month = startAge % 12;
  int age = startAge / 12;
  for (int i = 1; i <= working.months; i++){
    printf( "Age %3d month %2d you have $%.2lf\n", age, month, initial);   
    initial = balance(initial, working);
    month += 1;
    if (month % 12 == 0){
      age += 1;
      month = 0;
    }
  }                                                                        

  for (int i = 1; i <= retired.months; i++){                               
    printf( "Age %3d month %2d you have $%.2lf\n", age, month, initial);   
    initial = balance(initial, retired);                                   
    month += 1;                                                            
    if (month % 12 == 0){                                                  
      age += 1;                                                            
      month = 0;                                                          
    }                                                                      
  }
  
}

int main(void){
  retire_info working;
  retire_info retired;

  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045/12.0;

  retired.months = 384;         
  retired.contribution = -4000;  
  retired.rate_of_return = 0.01/12.0;
  
  retirement(327, 21345, working, retired);
  return EXIT_SUCCESS;
}
