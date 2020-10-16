#include <iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> NearestSmallerRight(int a[], int n)
{
    stack<pair<int,int>>s;
    vector<int>v(n);
    
    for(int i=n-1;i>=0;i--)
    {
        if(s.size()==0)
            v[i]=n;
        if(s.size()>0 && s.top().first<a[i])
            v[i]=s.top().second;
        if(s.size()>0 && s.top().first>=a[i])
        {
            while(s.size()!=0 && s.top().first>=a[i])
                s.pop();
            if(s.size()==0)
                v[i]=n;
            else
                v[i]=s.top().second;
        }
        
        s.push({a[i],i});
    }
    return v;
}

vector<int> NearestSmallerLeft(int a[], int n)
{
    stack<pair<int,int>>s;
    vector<int>v(n);
    
    for(int i=0;i<n;i++)
    {
        if(s.size()==0)
            v[i]=-1;
        if(s.size()>0 && s.top().first<a[i])
            v[i]=s.top().second;
        if(s.size()>0 && s.top().first>=a[i])
        {
            while(s.size()!=0 && s.top().first>=a[i])
                s.pop();
            if(s.size()==0)
                v[i]=-1;
            else
                v[i]=s.top().second;
        }
        
        s.push({a[i],i});
    }
    return v;
}

int MaxRect(int a[], int n)
{
    vector<int>NGL;
    vector<int>NGR;
    int width[n];
    int Max=INT_MIN;
    NGL=NearestSmallerLeft(a,n);
    NGR=NearestSmallerRight(a,n);
    for(int i=0;i<n;i++)
    {
        
        width[i]=NGR[i]-NGL[i]-1;
        Max=max(Max,width[i]*a[i]);
    }
    return Max;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    cout<<MaxRect(a,n)<<endl;
	}
	return 0;
}
