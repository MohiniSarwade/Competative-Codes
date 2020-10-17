#include<bits/stdc++.h>
class Solution {
public:
    unordered_map<string, bool>mp;
    bool isScramble(string s1, string s2) {
        if(s1.compare(s2)==0)
            return true;
        int n=s1.size();
        if(n<=1)
            return false;
        string s=s1+" "+s2;
        if(mp.find(s)!=mp.end())
            return mp[s];
        bool flag=false;
        for(int i=1;i<=n-1;i++)
        {
            if((isScramble(s1.substr(0,i),s2.substr(n-i,i))
               &&isScramble(s1.substr(i,n-i),s2.substr(0,n-i)))||
               ((isScramble(s1.substr(0,i),s2.substr(0,i)))&&
                (isScramble(s1.substr(i,n-i),s2.substr(i,n-i)))))
            {
                flag=true;
                break;
            }
          
        }
        return mp[s]=flag;  
    }
};
