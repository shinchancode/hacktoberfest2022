#include <bits/stdc++.h>
using namespace std;
#define v vector<int>
#define p pair<int, int>
#define vi vector<p>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
#define setBits(x) built_in_popcount(x)


signed main(){
  int n;
  cin>>n;
  v a(n);
  for(int i=0;i<n;i++){
      cin>>a[i];
  }
  map<int,int> freq;
   for(int i=0;i<n;i++){
      freq[a[i]]++;
  }
  map<int,int>::iterator it;
  for(it=freq.begin();it!=freq.end();it++){
cout<<it->ff<<" "<<it->ss<<endl;
  }


    return 0;
}
