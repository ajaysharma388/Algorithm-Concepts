#include <iostream>
using namespace std;
int main(){
	int t,n;
	int a[]={-11,11,9,7,5,3,1,-1,-3,-5,-7,-9};
	string s[]={"WS","WS","MS","AS","AS","MS",
	"WS","WS","MS","AS","AS","MS"};
	cin>>t;
	while(t--){
		cin>>n;
		int i=n%12;	
		cout<<n+a[i]<<" "<<s[i]<<"\n";
	}
	return 0;
}
