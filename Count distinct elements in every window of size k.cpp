vector <int> countDistinct (int A[], int n, int k)
{
    //code here.
    unordered_map<int,int>mp;
    vector<int>v;
    int count=0;
    for(int i=0;i<k;i++)
    {
        if(mp[A[i]]==0)
        {
            count++;
        }
        mp[A[i]]++;
    }
    v.push_back(count);
    for(int i=k;i<n;i++)
    {
        if(mp[A[i-k]]==1)
        {
            count--;
        }
        mp[A[i-k]]--;
        if(mp[A[i]]==0)
            count++;
        mp[A[i]]++;
        v.push_back(count);
    }
    return v;
}

/////////////////////////////////////////////////////////////////////////////////
vector <int> countDistinct (int A[], int n, int k)
{
    //code here.
    vector<int>v;
    unordered_map<int,int>mp;
    int i;
    for(i=0;i<k;i++)
        mp[A[i]]++;
    for(i=k;i<n;i++)
    {
        v.push_back(mp.size());
        mp[A[i-k]]--;
        if(mp[A[i-k]]<=0)
            mp.erase(A[i-k]);
        mp[A[i]]++;
    }
    v.push_back(mp.size());
    return v;
}
