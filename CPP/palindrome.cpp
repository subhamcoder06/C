#include <iostream>
using namespace std;
int main(){
    int num,x,y,z,a,pal;
    cout<<"Give a number to find wheather its palindrome or not"<<endl;
    cin>>num;
    x = num%10;//last digit
    y = num/10;//first 2 digits
    z = y%10;//2nd digit
    a = y/10;//1st digit
    pal = x*100+z*10+a*1;
    
    if(pal == num){
        cout<<"The number is a Palindrome"<<endl;
    }else{
        cout<<"The number is not a Palindrome"<<endl;
    }

    return 0;
}