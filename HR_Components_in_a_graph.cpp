//https://www.hackerrank.com/challenges/components-in-graph/problem
#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the componentsInGraph function below.
 */
void makeset(int *s,int n)
{
    for(int i=1;i<=n;i++)
        s[i]=-1;
}
int find(int *s,int n,int x)
{
    if(x<=0 || x>n)
        return INT_MIN;
    if(s[x]<0)
        return x;
    else return(s[x]=find(s,n,s[x]));
}

void union_s(int *s,int n,int p, int q)
{
    int t1=find(s,n,p);
    int t2=find(s,n,q);
    if(t1==t2 && t1!=-1)
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
vector<int> componentsInGraph(vector<vector<int>> gb) {
    /*
     * Write your code here.
     */
    vector<int>v;
    int n=gb.size()*2;
    int s[n];
    makeset(s,n);
    for(long unsigned int i=0;i<gb.size();i++)
        union_s(s,n,gb[i][0],gb[i][1]);

    int min=INT_MAX,max=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(s[i]<0)
        {
            if(min>s[i])
                min=s[i];
        }
    } 
    int c_max=abs(min);
//cout<<"c"<<c_max<<endl;
    for(int i=0;i<n;i++)
    {
        if(s[i]<-1)
        {
            if(max<s[i])
                max=s[i];
        }
    }  
    int c_min=abs(max);
    if(c_min==INT_MIN)
        v.push_back(1);
    else
    {
        v.push_back(c_min);
        v.push_back(c_max);
    }
    
    return v;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> gb(n);
    for (int gb_row_itr = 0; gb_row_itr < n; gb_row_itr++) {
        gb[gb_row_itr].resize(2);

        for (int gb_column_itr = 0; gb_column_itr < 2; gb_column_itr++) {
            cin >> gb[gb_row_itr][gb_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> SPACE = componentsInGraph(gb);

    
    for (int SPACE_itr = 0; SPACE_itr < SPACE.size(); SPACE_itr++) {
        fout << SPACE[SPACE_itr];

        if (SPACE_itr != SPACE.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
/////////////////////////////////////////////////////////////////////


#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the componentsInGraph function below.
 */
 void DFS(list<int>*l,int n, int i, int &count, bool vist[])
 {
     vist[i]=true;
     count++;
     for(auto it=l[i].begin();it!=l[i].end();it++)
        if(vist[*it]==false)
            DFS(l,n,*it,count,vist);
 }
 void find(list<int>*l,int& min, int& max, int n)
 {
     bool vist[n];
     memset(vist,0,sizeof(vist));
     for(int i=0;i<n;i++)
     {
         int count=0;
         if(vist[i]==false)
            DFS(l,n,i,count,vist);
         if(count<min && count>1)
            min=count;
         if(count>max)
            max=count;
     }
 }
vector<int> componentsInGraph(vector<vector<int>> gb) {
    /*
     * Write your code here.
     */
     list<int>*l=new list<int>[gb.size()*2];
     for(int i=0;i<gb.size();i++)
    {
        l[gb[i][0]-1].push_back(gb[i][1]-1);
        l[gb[i][1]-1].push_back(gb[i][0]-1);
    }  
    int min=INT_MAX,max=INT_MIN;
    int n=gb.size()*2;
    find(l,min,max,n);
    vector<int>v(2);
    v[0]=min;
    v[1]=max;
    return v;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> gb(n);
    for (int gb_row_itr = 0; gb_row_itr < n; gb_row_itr++) {
        gb[gb_row_itr].resize(2);

        for (int gb_column_itr = 0; gb_column_itr < 2; gb_column_itr++) {
            cin >> gb[gb_row_itr][gb_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> SPACE = componentsInGraph(gb);

    for (int SPACE_itr = 0; SPACE_itr < SPACE.size(); SPACE_itr++) {
        fout << SPACE[SPACE_itr];

        if (SPACE_itr != SPACE.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
