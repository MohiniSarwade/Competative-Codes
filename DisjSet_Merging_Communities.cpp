//https://www.hackerrank.com/challenges/merging-communities/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include<bits/stdc++.h>
void makeset(int *s,int n)
{
    for(int i=1;i<=n;i++)
        s[i]=-1;
}
int find(int *s, int n,int x)
{
    if(x<=0 ||x>n)
        return INT_MIN;
    if(s[x]<0)
        return x;
    else return (s[x]=find(s,n,s[x]));
}
void union_s(int *s,int n, int p,int q)
{ 
    int t1=find(s,n,p);
    int t2=find(s,n,q);
    if((t1==t2) && t1!=-1)
        return;
    if(s[t2]<s[t1])
    {
        s[t2]+=s[t1];
        s[t1]=t2;
    }
    else
    {
        s[t1]+=s[t2];
        s[t2]=t1;
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,q;
    int count=0;
    
    cin>>n;
    cin>>q;
    int s[n+1];
        makeset(s,n);
    while(q--)
    {
        char c;
        cin>>c;
        if(c=='Q')
        {
            int x;
            cin>>x;
            int r=find(s,n,x);
            cout<<abs(s[r])<<endl;
         
        }
        else
        {
            int p,q;
            cin>>p>>q;
            union_s(s,n,p,q);
        }
    }
    return 0;
}
