#include<bits/stdc++.h>
using namespace std;
vector<int>tree;
void build(vector<int>v,int n)
{
  for(int i=n,j=0;i<2*n;i++,j++)
  tree[i]=v[j];
  for(int i=n-1;i>=0;i--)
  tree[i]=tree[i*2]&tree[i*2+1];
}
int query(int l,int r,int n)
{
  l+=n;
  r+=n;
  int a=-1;
  while(l<=r)
  {
    if(l%2)
    a=a&tree[l],l++;
    if(!r%2)
    a=a&tree[r],r--;
    l/=2;
    r/=2;
  }return a;
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    vector<int>v(n,0);
    for(int i=0;i<n;i++)
    cin>>v[i];
    int size=2*n+1;
    tree.resize(size,-1);
    build(v,n);
    int q;
    cin>>q;
    while(q--)
    {
      int l,r;
      cin>>l>>r;
      cout<<query(l,r,n)<<endl;
    }
  }
}
