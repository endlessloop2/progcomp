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

void dfs(vvi &adj_list, vector<int> &visited, int node)
{
    if(visited[node]) return; // ver q no esta visitado
    visited[node] = 1; // marcar como visitado

    // visitar vecinos recursivo
    vector<int> vecinos = adj_list[node];
    for (int i = 0; i < vecinos.size(); i++)
    {
        dfs(adj_list, visited, vecinos[i]);
    }
    
}


void solve() 
{
    int n, m, r; // ciudades, road endpoints (creo q nodos)
    // ciudades(separadas), nodos, aristas 
    cin >> n;

    for (int i = 0; i < n; i++) // ciudades separadas
    {
        cin >> m >> r;// nodos, aristas
        vvi adj_list(m, vector<int>()); // lista de adyacencia
        vector<int> visited(m, 0); // vector de visitados
        int c = 0;// conexas

        for (int j = 0; j < r; j++) // leer aristas y push
        {
            int a, b;
            cin >> a >> b;
            adj_list[a].push_back(b);
            adj_list[b].push_back(a);
        }
        // encontrar componentes conexas - 1
        for (int j = 0; j < m; j++)
        {
            if(!visited[j]) c++;

            dfs(adj_list, visited, j);
            //dfs
        }

        cout << c-1 << endl;
        
    }
    
}
