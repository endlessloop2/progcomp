#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpi;
typedef vector<vpi> vvpi;
typedef pair<int,int> ii;

#define INF INT_MAX-1

void solve();
int main() 
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(7);
    solve();

    return 0;
}

void dfs(vvi &adj_list, vector<bool> &visited, int node)
{
    if(visited[node]) return;
    visited[node] = 1;
    // cout << "visitando nodo: " << node << endl;

    for (int i = 0; i < adj_list[node].size(); i++)
    {
        dfs(adj_list, visited, adj_list[node][i]);
    }
    
}


void solve() 
{
    int n, m, a, b; // casas, cables // amount of nodes, vertices
    cin >> n >> m;
    vvi adj_list(n, vector<int>());
    vector<bool> visited(n, 0);

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adj_list[a-1].push_back(b-1);
        adj_list[b-1].push_back(a-1);
    }

    dfs(adj_list, visited, 0);

    bool f = 0;
    for (int i = 0; i < n; i++)
    {
        if(!visited[i]) 
        {
            f = 1;
            cout << i+1 << endl;
        } 
    }

    if(!f)
    {
        cout << "Connected" << endl;
    }
    
    

}
