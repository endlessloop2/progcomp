#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef vector<vector<int>> vvi;

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

void dfs(vvi &adj_list, vector<bool> &visited, int current)
{
    visited[current] = 1;
    for (int i = 0; i < adj_list[current].size(); i++) // por todos los vecinos del nodo current
    {
        if(!visited[adj_list[current][i]])
        {
            dfs(adj_list, visited, adj_list[current][i]);
        }
    }
    
}

void solve() 
{
    int N, M; // nro de casas, nro de cables
    cin >> N >> M;

    int a, b;
    vvi adj_list(N, vector<int>());
    vector<bool> visited(N, 0); //vector de viistados
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        adj_list[a-1].push_back(b-1);
        adj_list[b-1].push_back(a-1);
    }
    dfs(adj_list, visited, 0);
    
    bool flag = 0;
    for (int i = 0; i < N; i++)
    {
        if(!visited[i])
        {
            cout << i+1 << endl;
            flag = 1;
        }
    }
    if(!flag) cout << "Connected" << endl;
}
