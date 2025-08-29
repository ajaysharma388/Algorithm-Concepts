#include <iostream>
#include <string>
using namespace std;

int main(){
    int alphabet[26]={0};
    string str;
    cin>>str;
    for(int i=0;i<str.length();++i)
        alphabet[(int)str[i]-97]++;
    int max = 0,index = 0;
    for(int i=0;i<26;i++){
        if(alphabet[i]>max){
            max = alphabet[i];
            index = i;
        }
     }
    cout<<(char)(index+97)<<endl;
    return 0;
}