https://www.hackerrank.com/challenges/special-palindrome-again/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the substrCount function below.
long substrCount(int n, string s) {
    int i=0;
    int ans=0;
    int a[n]={0};
    while(i<n)
    {
        int j=i+1,c=1;
        while(j<n && s[i]==s[j])
        {
            j++;c++;
        }
        ans+=c*(c+1)>>1;
        a[i]=c;
        i=j;
    }
    for(int j=1;j<n-1;j++)
    {
        if(s[j]==s[j-1])
            a[j]=a[j-1];
        if(s[j-1]==s[j+1]&&s[j]!=s[j-1])
            ans+=min(a[j-1],a[j+1]);
    }
    return ans;
}

int main()
{

    int n;
    cin >> n;
   
    string s;
     cin>>s;
    cout<<substrCount(n, s)<<endl;

    return 0;
}
