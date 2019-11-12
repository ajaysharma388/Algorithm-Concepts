#include <iostream>

using namespace std;

void multiply(int *a, int &n , int num){
    int carry = 0;
    for(int i = 0 ; i < n ; ++i){
        int product = a[i]* num +carry;
        a[i] = product%10;
        carry = product/10;
    }
    while(carry){
        a[n] = carry%10;
        carry = carry/10;
        n++;
    }
}

void big_Factorial(int number){
    int *a = new int[1000]{0};
    a[0] = 1;
    int n = 1;
    for(int i = 2 ; i <= number ; ++i)
        multiply(a,n ,i);
    for(int i = n-1 ; i > -1 ; i--)
        cout <<a[i];
    cout<<endl;
}
int main()
{
    int n;
    //cout<<"Enter Any Number to find Factorial : ";
    cin>>n;
    //cout<<"The Factorial of "<< n << " is ";
    big_Factorial(n);
    return 0;
}
