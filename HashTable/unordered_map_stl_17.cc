#include <bits/stdc++.h>
using namespace std;

class Student {
    private:
        int rollNo;
        string fName, lName;
    public:
        // Default Constructor.
        Student() {}
        // Parameterised Constructor
        Student(string fName, string lName, int rollNo ) {
            this->fName = fName;
            this->lName = lName;
            this->rollNo = rollNo;
        }
        string getFirstName() const { 
            return this->fName; 
        }
        string getLastName() const { 
            return this->lName; 
        }
        bool operator==(const Student &s) const {
            return this->rollNo == s.rollNo ? true : false;
        }
};

class hasFn {
    public:
        size_t operator() (const Student &s) const {
            return s.getFirstName().length() + s.getLastName().length();
        }
};


int main() {
    int n; cin >> n;
    unordered_map<Student, int, hasFn> st_mp;
    for(int i = 0; i < n; ++i ) {
        string fName, lName;
        int rollNo, mark;
        cin >> fName >> lName >> rollNo >> mark;
        Student s(fName, lName, rollNo);
        st_mp[s] = mark;    
    }
    // Printing the data inside unordered_map.
    for(auto mp : st_mp) {
        cout << mp.first.getFirstName() << " " << mp.first.getLastName() << " -> " << mp.second << endl;
    }
    return 0;
}

// Sample Input :

// 5
// Ajay Sharma 26 79
// Vijay Sharma 24 98
// Ajay Sharma 25 90
// Kanika Bhardwaj 22 99
// Deepak Bhardwaj 23 67

// Sample Output :

// Deepak Bhardwaj -> 67
// Kanika Bhardwaj -> 99
// Ajay Sharma -> 90
// Ajay Sharma -> 79
// Vijay Sharma -> 98