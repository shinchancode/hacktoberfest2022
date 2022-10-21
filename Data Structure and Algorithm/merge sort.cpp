#include <iostream>
using namespace std;
void merge( int start, int mid,int end, int ar){
    int arr1[end-start+1];
    int left=start,ptr=0,right=mid+1;
    
    while(left<=mid || right<=end){
        if(ar[left] < ar[right]){ arr1[ptr]=ar[left]; left++;}
        else {
            arr1[ptr]=ar[right];
            right++;
        }
        ptr++; 
        }
        
    while(left<=mid)arr1[ptr++]=ar[left++];
    while(right<=end)arr1[ptr++]=ar[right++];
    
    for(int i=0; i<=end-start ; i++) ar[start++]=arr1[i];
}


int mergesort(int start, int end, int ar){
    if(start>=end) return;
    int mid=start + (end-start)/2;
    mergesort(start, mid, ar);
    mergesort(mid+1,end,ar);
    merge(start, mid, end, ar);
}

int main() {
	int n;
	cin>>n;
	int ar[n];
	for(int i=0;i<n;i++)cin>>ar[i];
	mergesort(0,n-1,ar);
	return 0;
}