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
