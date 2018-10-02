#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Graph {    
    public:
        
        vector<vector<int> > connections ;
        vector<bool> covered ;
        vector<int> values ;
    
        Graph(int n) {
            connections.resize(n);
            covered.resize(n,false);
            values.resize(n);
        }
    
        void add_edge(int u, int v) {
          /*  cout << " input edge : " << u << " " << v << endl;
            u-=1 , v-=1 ;
            cout << "inserting  connection : " << u << " " << v << endl; */
            connections[u].push_back(v);
            connections[v].push_back(u);
          //  cout << "connection inserted "<<endl;
        }
        
        void dfs ( int vertex , int value ) {
            this->values[vertex] = value ;
            this->covered[vertex] = true ;
            for ( int i : this->connections[vertex] )
                if ( not covered[i] or this->values[i] > value + 6 )
                    dfs ( i , value + 6 );
            return;
        }
    
        vector<int> shortest_reach(int start) {
        //    start -=1 ;
            dfs ( start , 0 );
            this->values[start] = -1 ;
            for ( int i=0 ; i<this->values.size() ; i++ )
                if ( this->values[i] == 0 )
                    this->values[i] = -1 ;
            return this->values;
        }
    
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
		int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
		int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}