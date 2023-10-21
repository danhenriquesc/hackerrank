#include <bits/stdc++.h>
using namespace std;
int find(vector <int> &parent, int i)
{
    if(parent[i]==-1)
    return i;
    return find(parent,parent[i]);
}
void add_edge(vector <int> &parent, int x, int y)
{
    int xset = find(parent,x);
    int yset = find(parent,y);
    parent[xset] = yset;
}
int main()
{
    int g_nodes;
    int g_edges;

    cin >> g_nodes >> g_edges;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> g_from(g_edges);
    vector<int> g_to(g_edges);
    vector<int> g_weight(g_edges);

    for (int i = 0; i < g_edges; i++) {
        cin >> g_from[i] >> g_to[i] >> g_weight[i];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
   int cost = 0;
    pair <int,pair<int,int> > p[g_edges];
    for(int i=0;i<g_edges;i++)
    p[i]=make_pair(g_weight[i],make_pair(g_from[i],g_to[i]));
    sort(p,p + g_edges);
    vector <int> parent(g_nodes+1,-1);
    for(int i=0;i<g_edges;i++)
    {
    int x = p[i].second.first, y = p[i].second.second;
    if(find(parent,x) != find(parent,y))
    {
        add_edge(parent,x,y);
        cost += p[i].first;
    }
    }
    cout<<cost;
    return 0;
}
