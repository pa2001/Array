#include<bits/stdc++.h>
using namespace std;
bool cmpx(pair<int,int>a,pair<int,int>b)
{
  return a.first<b.first;
}
bool cmpy(pair<int,int>a,pair<int,int>b)
{
  return a.second<b.second;
}
float min(float x,float y)
{
  if(x<y)
  return x;
  else
  return y;
}
float dis(pair<int,int>&p1,pair<int,int>&p2)
{
  float dist=sqrt((p1.first-p2.first)*(p1.first-p2.first)+(p1.second - p2.second)*(p1.second-p2.second));
  return dist;
}
float brute(vector<pair<int,int>>&v,int s,int n)
{
  float mn=FLT_MAX;
  for(int i=s;i<=n;i++)
  {
    for(int j=i+1;j<=n;j++)
    {
      if(dis(v[i],v[j])<mn)
      mn=dis(v[i],v[j]);
    }
  }
  return mn;
}
float strip(vector<pair<int,int>>&strips,float d)
{
  float mn=d;
  sort(strips.begin(),strips.end(),cmpy);
  for(int i=0;i<strips.size();i++)
  {
    for(int j=i+1;j<strips.size()&&strips[j].second-strips[i].second<mn;j++)
    if(dis(strips[i],strips[j])<mn)
    mn=dis(strips[i],strips[j]);
  }return mn;
}
float closest(vector<pair<int,int>>&v,int s,int n)
{
  if(n-s<=2)
  return brute(v,s,n);
  int mid=s+(n-s)/2;
  pair<int,int>p=v[mid];
  float dl=closest(v,s,mid-1);
  float dr=closest(v,mid+1,n);
  float d=min(dl,dr);
  vector<pair<int,int>>strips;
  int j=0;
  for(int i=s;i<=n;i++)
  {
    if(abs(v[i].first-p.first)<d&&i!=mid)
    {
      strips.push_back(p);
    }
  }
  return min(d,strip(strips,d));
}
float find(vector<pair<int,int>>&v,int n)
{
  sort(v.begin(),v.end(),cmpx);
  return closest(v,0,n);
}
int main()
{
  int n;
  cin>>n;
  vector<pair<int,int>>v;
  int x,y;
  for(int i=0;i<n;i++)
  {
    cin>>x>>y;
    v.push_back({x,y});
  }
  cout<<float(find(v,n-1));
}
