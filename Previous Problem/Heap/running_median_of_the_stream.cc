#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"
#define maxHeap priority_queue<int>
#define minHeap	priority_queue<int,vector<int>,greater<int>>


// Here we are trying to keep boo the heaps balanced
// so that we can maintain the size diference between 
// them less than or equal to 1.
void balanceHeap(maxHeap &mx,minHeap &mn){
	if(mx.size() > mn.size()){
		int tp = mx.top();
		mx.pop();
		mn.push(tp);
	}else{
		int tp = mn.top();
		mn.pop();
		mx.push(tp);
	}
}

int getMedian(maxHeap &lr,minHeap &rr){
	int lsize = lr.size();
	int rsize = rr.size();
	int md = 0; 
	// rebalancing the heap.
	if(abs(lsize-rsize) > 1){
		balanceHeap(lr,rr);
	}
	// if both the heaps has equal number of 
	// element the median would be average of 
	// their top elements.
	if(lr.size()==rr.size()){
		int f = lr.top();
		int s = rr.top();
		md = (f+s)/2;
	}else if(lr.size()>rr.size()){
		// uneven case when size of left is greater.
		md = lr.top();
	}else{
		// uneven case when size of right is greater.
		md = rr.top();
	}
	return md;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	maxHeap lr;
	minHeap rr;
	int cur;
	int median;
	// reading till the end of file.
	while(scanf("%d",&cur)!=EOF){
		// if both of them has no element special case.
		if(lr.size()==0 and rr.size()==0){
			lr.push(cur);
		}else if(cur>=median){
			rr.push(cur);
		}else{
			lr.push(cur);
		}
		median = getMedian(lr,rr);
		cout << median << " ";
	}
	return 0;
}

// Sample Input :

// 1 2 3 8 9
// 5 15 1 3 10 2 7 8

// Sample Output :

// 1 1 2 2 3 
// 5 10 5 4 5 4 5 6 