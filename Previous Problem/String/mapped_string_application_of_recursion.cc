#include <bits/stdc++.h>
using namespace std;

static char mapping[] = {'A','B','C','D','E',
				  'F','G','H','I','J',
				  'K','L','M','N','O',
				  'P','Q','R','S','T',
				  'U','V','W','X','Y','Z'
				 };

void change(string str,string osf,int count){
	int s=str.length();
    if(count == s){
        cout<<osf<<endl;
        return;
    }
    if(str[count]!='0'){
        int num=str[count]-'0';
        char ch=mapping[num-1];
        change(str,osf+ch,count+1);
    }
    if(count<s-1){
        int num2=str[count]-'0';
        int num3=str[count+1]-'0';
        int num4=(num2*10)+(num3);
        if(num4<=26){
            char ch1=mapping[num4-1];
            change(str,osf+ch1,count+2);
        }             
    }
}


int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif
	string n,s;
	char res[20];
	cin>>n;
	change(n,s,0);
	//printAll(n,res,0);				 
	return 0;
}