#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define INF INT_MAX

typedef pair<int,int> ii;

void solve();
void dfs(int node, vector<vector<ii>> &adj_list, vector<bool> &visited);

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.setf(ios::fixed);
    solve();
    return 0;
}

void solve() 
{
    int V,E; //vertices, edges
    cin >> V >> E;

    vector<vector<ii>> adj_list(V);
    vector<bool> visited(V, false);
    for(int i = 0; i < E; ++i)
    {
        int a,b,w;
        cin >> a >> b >> w;
        adj_list[a-1].push_back(make_pair(b-1,w));
        adj_list[b-1].push_back(make_pair(a-1,w));

    }
    dfs(0, adj_list, visited);
    cout << "a" << endl;
}

void dfs(int node, vector<vector<ii>> &adj_list, vector<bool> &visited)
{
    if(visited[node]) return; //backtrack, ya visitado
    visited[node] = 1;
    cout << "Visitando el nodo " << node+1 << endl;

    for(int i = 0; i < adj_list[node].size(); ++i)
    {
        dfs(adj_list[node][i].first, adj_list, visited);
    }
}
