#include <iostream>
#include <string>
using namespace std;

int main(){
    string cammelCase;
    cin>>cammelCase;
    cout<<cammelCase[0];
    for(int i=1;i<cammelCase.length();++i){
        if((int)cammelCase[i]>=65 &&
         (int)cammelCase[i]<=90)
            cout<<endl;
        cout<<cammelCase[i];
    }
    return 0;
}