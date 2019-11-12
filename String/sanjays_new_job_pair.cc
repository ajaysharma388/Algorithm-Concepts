#include <iostream>
#include <utility>
#include <vector>
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
	vector <Emp> emp;
	cin>>min_salary>>n;
	emp.reserve(n);
	int salary;
	string name;
	Emp e;
	for(int i=0;i<n;++i){
		cin>>name>>salary;
		e.first=name;
		e.second=salary;
		emp.push_back(e);
	}
	sort(emp.begin(), emp.end(),compare);
	for(int i=0;i<n;++i)
		if(emp[i].second>min_salary)
			cout<<emp[i].first<<" "<<emp[i].second<<endl;
	return 0;
}