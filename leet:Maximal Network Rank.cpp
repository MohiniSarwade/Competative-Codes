class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        list<int> *l=new list<int>[n];
        int tmp[n];
        memset(tmp,0,sizeof(tmp));
        for(int i=0;i<roads.size();i++)
        {
            l[roads[i][0]].push_back(roads[i][1]);
            tmp[roads[i][0]]++;
            l[roads[i][1]].push_back(roads[i][0]);
            tmp[roads[i][1]]++;
        }
       
        int m=INT_MIN;
        bool flag=false;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(auto it=l[i].begin();it!=l[i].end();it++)
                   if(*it==j)
                     flag=true;
                if(flag==true)
                    m=max(m,(tmp[i]+tmp[j]-1));
                else
                    m=max(m,tmp[i]+tmp[j]);
                flag=false;
            }
            
        }
        return m;
        
    }
};
