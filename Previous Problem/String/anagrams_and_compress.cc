#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define s string

bool isAnagram(s s1,s s2){
    int l1=s1.length(),l2=s2.length(); 
    if(l1!=l2) return false;
    transform(s1.begin(), s1.end(),s1.begin(),::tolower);
    transform(s2.begin(), s2.end(),s2.begin(),::tolower);
    int arr[1<<8]={0};
    for(int i=0;i<l1;++i){
        arr[s1[i]-1]++;
    }
    for(int i=0;i<l2;++i){
        arr[s1[i]-1]--;
    }
    for(int i=0;i<(1<<8);++i)
        if(arr[i]!=0) return false;
    return true;
}

void compress(s str){
    transform(str.begin(), str.end(),str.begin(),::tolower);
    int arr[1<<8]={0};
    int l=str.length();
    for(int i=0;i<l;++i){
        arr[str[i]-1]++;
    }
    char st[100];
    int j=0;
    for(int i=0;i<(1<<8);++i)
        if(arr[i]>0){ 
            st[j]=(char)(i+1);
            j++;
            st[j]=(char)arr[i];
            j++;
        }
    if(j==2){
        cout<< str <<endl;
    }else{
        for(int i=0;i<j;++i)
            (i&1)?
                cout<< (int)st[i]:
                cout<< (char)st[i];
    }
    return;   
}


int main(){
	s s1,s2;
    cin>>s1>>s2;
    (isAnagram(s1,s2))?
        cout<<"Anagram"<<endl:cout<<"Not Anagram"<<endl;
    compress(s1);
    return 0;
}