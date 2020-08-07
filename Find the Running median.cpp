#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the runningMedian function below.
 */
vector<double> runningMedian(vector<int> a) {
    
    vector<double>v;

    priority_queue<pair<int,int>>LMax;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>RMin;

    double m=0;
    int c=0;
    for(int i=0;i<a.size();i++)
    {
        int ch=LMax.size()-RMin.size();
        switch(ch)
        {
            case 0:
                if(a[i]<m)
                {
                    LMax.push(make_pair(a[i],c++));
                    m=LMax.top().first;
                }
                else
                {
                    RMin.push(make_pair(a[i],c++));
                    m=RMin.top().first;
                }
                break;
            case 1:
                if(a[i]<m)
                {
                    RMin.push(make_pair(LMax.top().first,c++));
                    LMax.pop();
                    c--;
                    LMax.push(make_pair(a[i],c++));
                }
                else
                    RMin.push(make_pair(a[i],c++));
                m=(LMax.top().first + RMin.top().first)/2.0;
                break;

            case -1:
                if(a[i]<m)
                {
                    LMax.push(make_pair(a[i],c++));
                }
                else
                {
                    LMax.push(make_pair(RMin.top().first,c++));
                    RMin.pop();
                    c--;
                    RMin.push(make_pair(a[i],c++));
                }
                m=(LMax.top().first + RMin.top().first)/2.0;
                break;
        } 
        v.push_back(m);  
    }
    return v;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int a_count;
    cin >> a_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> a(a_count);

    for (int a_itr = 0; a_itr < a_count; a_itr++) {
        int a_item;
        cin >> a_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        a[a_itr] = a_item;
    }

    vector<double> result = runningMedian(a);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
