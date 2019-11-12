#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

string searchIn [] = {"prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"};
string keys[] = {" ",".+@$","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

int* computePattern(char pattern[],int n){
    int *lps = new int[n];
    int index =0;
    for(int i=0;i<n;++i){
      	lps[i]=0;
    }
    for(int i=1; i < n;){
        if(pattern[i] == pattern[index]){
            lps[i] = index + 1;
            index++;
            i++;
        }else{
            if(index != 0){
                index = lps[index-1];
            }else{
                lps[i] =0;
                i++;
            }
        }
    }
    return lps;
}

bool KMP(string text, char pattern[],int m,int n){
    int *lps = computePattern(pattern,n);
    int i=0;
    int j=0;
    while(i < m && j < n){
        if(text[i] == pattern[j]){
            i++;
            j++;
        }else{
            if(j!=0){
                j = lps[j-1];
            }else{
                i++;
            }
        }
    }
    if(j == n){
        return true;
    }
    return false;
}

  
void advanceKey(char n[],char res[],int i,int j){
	if(n[i]=='\0'){
		res[j]='\0';
		for(int k=0;k<11;++k){
			if(KMP(searchIn[k],res,j,searchIn[k].length()))
				cout<<searchIn[k]<<endl;
		}		
		return;
	}
	string currStr = keys[n[j]-'0'];
	for(int k=0;k<currStr.length();++k){
		res[j]=currStr[k];
		advanceKey(n,res,i+1,j+1);
	}
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	char res[10],num[10];
	cin >> num;
	advanceKey(num,res,0,0);
	return 0;
}

