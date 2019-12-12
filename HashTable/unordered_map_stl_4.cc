#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

// using unordered_map on the custom objects.

class Student{
	int sem;
	string name,email,phone,roll_no;
public:
	Student(){}
	Student(const string roll_no,const int sem,
		const string name,const string email,const string phone){
		this->roll_no = roll_no;
		this->name = name;
		this->sem = sem;
		this->email = email;
		this->phone = phone;
	}	
	void print(){
		cout << roll_no << " : " << name << " " << sem << " " << email << " " << phone << endl;
	}
};


int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unordered_map<string,Student> Class;
	int n;
	cin >> n;
	while(n--){
		string name,email,phone,roll_no;
		int sem;
		cin >> roll_no >> name >> sem >> email >> phone;
		Student s(roll_no,sem,name,email,phone);
		Class.insert(make_pair(roll_no,s));
	}	
	for(auto st : Class){
		Student student = st.second;
		student.print();
	}
	return 0;
}

// Sample Input : 

// 5
// 1422410001 AjayChaurasia 4 ajau25921@gmail.com 9871805635
// 1422410002 AnkushBhardwaj 4 iamankush0078@gmail.com 8700318113
// 1422410003 AjaySharma 4 ajaysm2201@gmail.com 9758990388
// 1422410004 AnkitSharma 4 iamankit199@gmail.com 9211470726
// 1422410005 DeepakBhardwaj 4 iamdeepak199@gmail.com 9643762201

// Sample Output :

// 1422410004 : AnkitSharma 4 iamankit199@gmail.com 9211470726
// 1422410003 : AjaySharma 4 ajaysm2201@gmail.com 9758990388
// 1422410001 : AjayChaurasia 4 ajau25921@gmail.com 9871805635
// 1422410005 : DeepakBhardwaj 4 iamdeepak199@gmail.com 9643762201
// 1422410002 : AnkushBhardwaj 4 iamankush0078@gmail.com 8700318113