#include <iostream>
using namespace std;

int factorial(int n){
    if(n==1)
        return 1;
    return n*factorial(n-1);
}
void printInc(int n){
    if(n == 1){
        cout<<n<<" ";
        return;
    }
    printInc(n-1);
    cout<<n<<" ";
    return;
}
void printDec(int n){
    if(n == 1){
        cout<<n<<" ";
        return;
    }
    cout<<n<<" ";
    printDec(n-1);
}
int main()
{
    printInc(8);
    return 0;
}
