#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> vvi;


void solve();

int main() 
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.setf(ios::fixed);
    //cout.precision(7);
    solve();
    return 0;
}

void DFS(int n, vvi &adj_list, vector<bool> &visitados)
{
    visitados[n] = 1;

    for(int i = 0; i < adj_list[n].size(); ++i)
    {
        int vecino = adj_list[n][i];
        if(!visitados[vecino])
        {
            DFS(vecino, adj_list, visitados);
        }
    }
}

void solve() 
{
    int n,m; // nodos, aristas
    cin >> n >> m;
    vvi adj_list(n, vector<int>());
    vector<bool> visitados(n,false);
    for(int i = 0; i < m; ++i)
    {
        int a,b;
        cin >> a >> b;
        adj_list[a-1].push_back(b-1);
        adj_list[b-1].push_back(a-1);
    }
    DFS(0, adj_list, visitados);

    bool flag = 0;
    for(int i = 0; i < n; ++i)
    {
        if(!visitados[i])
        {
            cout << i+1 << endl;
            flag = 1;
        }
    }
    if(flag == 0) cout << "Connected" << endl;
}
