#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the roadsAndLibraries function below.
long roadsAndLibraries(long n, long c_lib, long c_road, vector<vector<long>> cities) 
{
    vector <long> adj[n];
    for(long i=0;i<cities.size();i++)
    {
        adj[cities[i][0]-1].push_back(cities[i][1]-1);
        adj[cities[i][1]-1].push_back(cities[i][0]-1);
    }
    long cc = 0;
    stack <long> s;
    vector <long> visited(n);
    vector <long> comp;
    for(long i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
           s.push(i);
           visited[i]=1;
           long count = 1;
           while(!s.empty())
           {
                 long x = s.top();
                 visited[x]=1;
                 s.pop();
                 for(long i=0;i<adj[x].size();i++)
                 {
                    long ver = adj[x][i];
                    if(visited[ver]==0)
                    {
                    s.push(ver);
                    visited[ver] = 1;
                    count++;
                    }
                 }
           }
           comp.push_back(count);
           cc++;
        } 
    }
    if(c_lib < c_road)
        return c_lib*n;
    else
    {
        long roads = 0;
        for(long i=0;i<comp.size();i++)
        {
            roads += (comp[i]-1);
        }
        long cost = roads*c_road + cc*c_lib;
        return cost;
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    long q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (long q_itr = 0; q_itr < q; q_itr++) {
        string nmC_libC_road_temp;
        getline(cin, nmC_libC_road_temp);

        vector<string> nmC_libC_road = split_string(nmC_libC_road_temp);

        long n = stoi(nmC_libC_road[0]);

        long m = stoi(nmC_libC_road[1]);

        long c_lib = stoi(nmC_libC_road[2]);

        long c_road = stoi(nmC_libC_road[3]);

        vector<vector<long>> cities(m);
        for (long i = 0; i < m; i++) {
            cities[i].resize(2);

            for (long j = 0; j < 2; j++) {
                cin >> cities[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);

        fout << result << "\n";
    }

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
