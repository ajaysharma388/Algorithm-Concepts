#include <iostream>

using namespace std;

int main(){
	char s[100];
	cin>>s;
	for(int i=0;s[i]!='\0';++i){
		int temp;
		if(s[i]>=97){
			temp=s[i]-97;
			s[i]=65+temp;
		}else{
			temp=s[i]-65;
			s[i]=97+temp;
		}
		cout<<s[i];
	}
	cout<<"\n";
	return 0;
}