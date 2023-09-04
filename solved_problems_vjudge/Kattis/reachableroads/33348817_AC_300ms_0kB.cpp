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

void dfs(vvi adj_list, vector<bool> &visited, int node)
{
    visited[node] = 1;

    for (int i = 0; i < adj_list[node].size(); i++)
    {
        if(!visited[adj_list[node][i]])
        {
            dfs(adj_list, visited, adj_list[node][i]);
        }
    }
     
}

void solve() 
{
    int n, m, r, a, b, c; //cities, road endpoints (nodes), pairs of endpoints (aristas)
    cin >> n;
    for (int i = 0; i < n; i++) //for each city.
    {
        c = 0;
        cin >> m >> r;// nodes, edges
        vvi adj_list(m, vector<int>());
        vector<bool> visited(m, 0);
        for (int j = 0; j < r; j++) //for each edge
        {
            cin >> a >> b;
            adj_list[a].push_back(b);
            adj_list[b].push_back(a);
        }
        //sera contar los componentes conexos??, intentemos con dfs
        // hay q hacer un dfs desde todos los nodos, y ver si es uno nuevo.
        for (int j = 0; j < m; j++)
        {
            if(!visited[j])
            {
                //dfs here
                dfs(adj_list, visited, j);
                c++;
            }
        }
        //cout << "a";
        cout << c-1 << endl;
    }
}
