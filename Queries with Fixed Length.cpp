/*Consider an -integer sequence,A={a0,a1,a2,...an-1}. We perform a query on A by using an integer,d, to calculate the result of the following expression:
                                                    min    (max   aj)
                                                   0<=i<=n-d    i<=j<i+d 
in other words, if we let mi=max(ai,ai+1,....ai+d-1) , then you need to calculate min(m0,m1,...mn-d).Given A and q queries (each query consists of an integer, d), print the result of each query on a new line.
*/
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the solve function below.
void slideSolve(vector<int>arr,int k,vector<int>&v)
{
    deque<int>q;
    int c=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
    for(long unsigned int i=0;i<k;i++)
    {
        while(!q.empty() && arr[i]>arr[q.back()])
            q.pop_back();
        q.push_back(i);
    }
    for(long unsigned int i=k;i<arr.size();i++)
    {
        
        p.push(make_pair(arr[q.front()],c++));
        while(!q.empty() && arr[i]>arr[q.back()])
            q.pop_back();
        while(!q.empty() && q.front()<=i-k)
            q.pop_front();
        q.push_back(i);
    }
    p.push(make_pair(arr[q.front()],c++));
    v.push_back(p.top().first);
}
vector<int> solve(vector<int> arr, vector<int> queries) {
    vector<int>v;
    for(int i=0;i<queries.size();i++)
    {
        slideSolve(arr,queries[i],v);
    }
    return v;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nq_temp;
    getline(cin, nq_temp);

    vector<string> nq = split_string(nq_temp);

    int n = stoi(nq[0]);

    int q = stoi(nq[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int arr_itr = 0; arr_itr < n; arr_itr++) {
        int arr_item = stoi(arr_temp[arr_itr]);

        arr[arr_itr] = arr_item;
    }

    vector<int> queries(q);

    for (int queries_itr = 0; queries_itr < q; queries_itr++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[queries_itr] = queries_item;
    }

    vector<int> result = solve(arr, queries);

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

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
