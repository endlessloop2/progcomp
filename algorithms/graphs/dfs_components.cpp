#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define INF INT_MAX
#define MP make_pair

typedef pair<int,int> ii;
typedef vector<ii> vii;

void dfs(int node, vector<vii> &adj_list, vector<bool> &visited, int comp = 0);
int countComponents(int vertices, vector<vii> &adj_list, vector<int> &visited);


void dfs(int node, vector<vector<ii>> &adj_list, vector<int> &visited, int comp)
{
    if(visited[node] > -1) return;
    visited[node] = comp;
    for(int i = 0; i < adj_list[node].size(); ++i)
    {
        dfs(adj_list[node][i].first, adj_list, visited, comp);
    }
}

int countComponents(int vertices, vector<vii> &adj_list, vector<int> &visited)
{
    int type = 0;
    for(int i = 0; i < vertices; ++i)
    {
        //si ya esta visitado, saltarse
        if(visited[i] > -1) continue;
        //si no esta visitado, aumentar el tipo y hacer dfs
        dfs(i, adj_list, visited, type);
        ++type;
    }
    return type-1;
}