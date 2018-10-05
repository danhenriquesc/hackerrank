#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the journeyToMoon function below.
long journeyToMoon(long n, vector<vector<long>> astronaut) 
{
      vector <long> adj[n];
      for(long i=0;i<astronaut.size();i++)
      {
          adj[astronaut[i][0]].push_back(astronaut[i][1]);
          adj[astronaut[i][1]].push_back(astronaut[i][0]);
      }
      vector <long> visited(n);
      stack <long> st;
      vector <long> comp;
      long c = 0;
      for(long i=0;i<n;i++)
      {
          if(visited[i]==0)
          {
              long s = i;
              st.push(s);
              long count = 1;
              while(!st.empty())
              {
                  long v = st.top();
                  visited[v] = 1;
                  st.pop();
                  for(long j=0;j<adj[v].size();j++)
                  {
                      if(visited[adj[v][j]]==0)
                      {
                          st.push(adj[v][j]);
                          visited[adj[v][j]] = 1;
                          count++;
                      }                      
                  }                  
              }
              if(count>1)
                 comp.push_back(count);
              else
              if(count==1)
                 c++;
          }
      }
    long res = 0, nn = comp.size(), sum =0;
    for(long i=0;i<nn-1;i++)
    {       
        for(long j=i+1;j<nn;j++)
        {
            res += comp[i]*comp[j];
        }
    }
    for(int k=0;k<nn;k++)
    sum += comp[k];
    return res + sum*c + (c*(c-1))/2;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string np_temp;
    getline(cin, np_temp);

    vector<string> np = split_string(np_temp);

    long n = stoi(np[0]);

    long p = stoi(np[1]);

    vector<vector<long>> astronaut(p);
    for (long i = 0; i < p; i++) {
        astronaut[i].resize(2);

        for (long j = 0; j < 2; j++) {
            cin >> astronaut[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long result = journeyToMoon(n, astronaut);

    fout << result << "\n";

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
