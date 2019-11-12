#include <iostream>
using namespace std;

int* big_factorial(int n){
    int *a = new int[500]{1,1};
    for(int k=1;k<=n;++k){
        int carry=0;
        for(int i=1;i<=a[0];++i){
            int temp=a[i]*k+carry;
            a[i]=temp%10;
            carry=temp/10;
        }
        while(carry){
            a[++a[0]]=carry%10;
            carry/=10;
        }
    }
    return a;
} 

int main(){
    int n;
    cin>>n;
    int *p = big_factorial(n);
    for(int i=p[0];i>0;--i)
        cout<<p[i];
    cout<<endl;
    return 0;
}

// a better implementation of the big_factorial_problem. 
// void multiply(int a[],int &d,int num){
//     int carry=0;
//     for(int i=1;i<=d;++i){
//         int temp=a[i]*num+carry;
//         a[i]=temp%10;
//         carry=temp/10;
//     }
//     while(carry){
//         a[++d]=carry%10;
//         carry/=10;
//     }
// }
