#include <iostream>
#include <string>
using namespace std;

bool checkPalindrome(string str,char *left,
    char *right,int length){
    if(length==0 || length==1 || left==right)
        return true;
    if(left[0]==*right)
        checkPalindrome(str,++left,--right,length);
    else
        return false;
}

int main(){
    string str;
    cin>>str;
    int length = str.length();
    char *left = &str[0];
    char *right = &str[length-1];
    if(checkPalindrome(str,left,right,length))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
}