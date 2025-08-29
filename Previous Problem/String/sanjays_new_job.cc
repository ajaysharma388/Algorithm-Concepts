#include <iostream>
#include <utility>
#include <cstring>
#include <algorithm>

#define Emp pair<string,int>
using namespace std;

bool compare(Emp p1,Emp p2){
	if(p1.second==p2.second)
		return p1.second < p2.second;
	return p1.second > p2.second;
}

int main(){
	int n,min_salary;
	Emp emp[10005];
	cin>>min_salary>>n;
	int salary;
	string name;
	for(int i=0;i<n;++i){
		cin>>name>>salary;
		emp[i].first=name;
		emp[i].second=salary;
	}
	sort(emp,emp+n,compare);
	for(int i=0;i<n;++i) if(emp[i].second>min_salary) 
		cout<<emp[i].first<<" "<<emp[i].second<<endl;
	return 0;
}
