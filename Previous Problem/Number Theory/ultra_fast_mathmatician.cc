#include <iostream>
using namespace std;
#define s string
#define endl "\n"
int main(){
	int n;
	cin>>n;
	while(n--){
		s a,b;
		cin>>a>>b;
		for(int i=0; i<a.length(); i++) 
            (a[i]==b[i])? cout<<"0": cout<<"1";
        cout<<endl;
	}
	return 0;
}