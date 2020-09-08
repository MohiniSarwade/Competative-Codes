#include<bits/stdc++.h>
using namespace std;

bool check(string n)
{
    if(n==" "||n.size()==0)
        return true;
    map<char, char>mp;
    mp.insert({ '0', '0' }); 
    mp.insert({ '1', '1' }); 
    mp.insert({ '8', '8' }); 
    mp.insert({ '6', '9' }); 
    mp.insert({ '9', '6' }); 
    
 
    int i=0,j=n.length()-1;
    while(i<=j)
    {
        
        if(mp.find(n[j])==mp.end()||(n[i]!=mp[n[j]]))
            return false;
        i++;
        j--;
    }    
    return true;
}

int main()
{
    string n="16791";
    if(check(n)==true)
        cout<<"Number is strobogrammatic"<<endl;
    else
        cout<<"Number is not strobogrammatic"<<endl;
    return 0;
}
