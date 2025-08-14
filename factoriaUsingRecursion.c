#include <stdio.h>
int factorial(int number);
int main(){
    int num;
    printf("Write the number of which you want the factorial of:");
    scanf("%d",&num);
    printf("the factorial of %d is %d",num,factorial(num));
     return 0;
}
int factorial(int number){
  if(number == 1 || number == 0){
    return 1;
  }
  else{
        return number*factorial(number-1);
  }
}
