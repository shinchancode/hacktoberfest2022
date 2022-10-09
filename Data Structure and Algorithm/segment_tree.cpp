#include<bits/stdc++.h>
using namespace std;
 
void build(int i, int low, int high, int a[], int b[])
{
    if(low==high)
    {
        b[i]=a[low];
        return;
    }
 
    int mid=(low+high)/2;
    build(2*i+1,low,mid,a,b);
    build(2*i+2,mid+1,high,a,b);
    b[i]=max(b[2*i+1],b[2*i+2]);
}
 
int query(int i, int low, int high, int l, int r, int a[],int b[])
{
    if(low>=l && high<=r)
    {
        return b[i];
    }
    if(high <l || low > r)
    {
        return INT_MIN;
    }
    int mid = (low+high)/2;
    int left=query(2*i+1,low, mid, l,r,a, b);
    int right=query(2*i+2,mid+1, high, l,r,a, b);
    return max(left,right);
}
 
void call()
{
    int n,m;
    cin>>n>>m;
    int a[m];
 
    for(int i=0;i<m;i++)
    {
        cin>>a[i];
    }
 
    int q;
    cin>>q;
    int x1,y1,x2,y2,k;
    int b[4*m];
    build(0,0,m-1,a,b);
    for(int i=0;i<q;i++)
    {
        cin>>x1>>y1>>x2>>y2>>k;
        if(abs(y1-y2)%k!=0 || abs(x1-x2)%k!=0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        if(y1>y2)
        {
            swap(x1,x2);
            swap(y1,y2);
        }
 
        int x=0;
        if(x1==n || x2 == n)
            x=n;
        else
            x=n-(n-x1)%k;
 
        int ans = query(0,0,m-1,y1-1,y2-1,a,b);
 
        // cout<<x<<" "<<ans<<endl;
        if(ans>=x)
        {
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
    }
}
// -.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.
 
int main()
{
    fast;       //makes cin fast
            
    ll t=1;
    // cin>>t;
    // ignore;
    // while(t--)
    // {
        call();
    // }
 
    return 0;
}
