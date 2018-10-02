#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the findShortest function below.

/*
 * For the unweighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] to <name>_to[i].
 *
 */

int find ( queue < int > q , int count , vector<bool> required , vector<vector<int> > connections , vector<bool> &covered ) {
    if ( q.empty() )    return -1;
    vector<int> queue_contents;
    while ( not q.empty() ){
        queue_contents.push_back ( q.front() );
        q.pop();
    }
    
    cout << "The contents of the queue at the start of the function are " << endl; 
    for ( int i : queue_contents )
        cout << i << " ";
    cout << endl;
    
    for ( int i : queue_contents ) {
        covered[i] = true ;
        cout << "Checking connections from " << i << endl;
        for ( int j : connections[i] ) {
            cout << "Connection : " << j << endl;
          if ( not covered[j] ) {
            if ( required[j] ) {
                count+=1;
                cout << "Returning " << count << endl;
                return count;
            }
            else q.push(j);
          }
        }
    }
    
    cout << "PRINTING THE CONTENTS OF THE QUEUE "<<endl;   
    
    
    cout << "Contents of the queue at the END are : " << endl;
    queue<int> temp ;
    temp = q; 
    while ( not temp.empty() ) {
        cout << temp.front() << " " ;
        temp.pop();
    }
    cout<<endl;
    
    return find(q,count+1,required,connections,covered);
}


int findShortest(int graph_nodes, vector<int> graph_from, vector<int> graph_to, vector<long> ids, int val) {
    // solve here
    
    cout << "size of ids is " << ids.size() << endl;
    
    vector<bool> required_nodes ( graph_nodes , false ) ;
    for ( int i=0 ; i<graph_nodes ; i++ )
        if ( ids[i] == val )    required_nodes[i] = true ;
    
    cout << "The contents of the required_nodes vector is " << endl;
    for ( bool i : required_nodes )
        cout << (int)i << " " ;
    cout << endl;
    
    vector<vector<int> > connections ( graph_nodes );
    int edges = graph_from.size();
    for ( int i=0 ; i < edges  ; i++ )
        connections[graph_from[i]-1].push_back (graph_to[i]-1) , connections[graph_to[i]-1].push_back(graph_from[i]-1);
    
    int value = -1 ; 
    for ( int i=0 ; i< graph_nodes ; i++ ) 
        if ( required_nodes [i] ){
            required_nodes[i] = false ;
            cout << "starting from the index : " << i << endl;
            queue<int> q_values; 
            q_values.push ( i ) ;
            vector<bool> temp_covered ( graph_nodes ,false );
            int temp_answer = find ( q_values , 0 , required_nodes , connections , temp_covered ) ;
            cout << "temp_answer : " << temp_answer << endl;
            if ( temp_answer != -1 )
                value == -1 ? value = temp_answer : value = min ( value , temp_answer );
            cout << "value : " << value << endl;
            required_nodes[i] = true ;
        }
    
    return value ;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int graph_nodes;
    int graph_edges;

    cin >> graph_nodes >> graph_edges;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> graph_from(graph_edges);
    vector<int> graph_to(graph_edges);

    for (int i = 0; i < graph_edges; i++) {
        cin >> graph_from[i] >> graph_to[i];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string ids_temp_temp;
    getline(cin, ids_temp_temp);

    vector<string> ids_temp = split_string(ids_temp_temp);

    vector<long> ids(graph_nodes);

    for (int i = 0; i < graph_nodes; i++) {
        long ids_item = stol(ids_temp[i]);

        ids[i] = ids_item;
    }

    int val;
    cin >> val;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int ans = findShortest(graph_nodes, graph_from, graph_to, ids, val);

    fout << ans << "\n";

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
