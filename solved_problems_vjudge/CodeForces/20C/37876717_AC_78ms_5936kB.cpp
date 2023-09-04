#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpi;
typedef vector<vpi> vvpi;
typedef pair<int,int> ii;

#define INF 1000000000000L

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

//greater por el second
class Compare
{
public:
    bool operator() (ii &a, ii &b)
    {
        return a.second > b.second;
    }
};

void dijkstra(vvpi &adj_list, vector<ll> &distances, vector<int> &parent, int start, int end)
{
    distances[start] = 0;
    priority_queue<ii, vpi, Compare> pq;

    pq.push(make_pair(start, 0));

    while(!pq.empty())
    {
        ii current_n = pq.top();// nodo actual
        pq.pop();

        // actualizar distancias a vecinos

        // si es el nodo final, no hay pq visitar
        if(current_n.second > distances[current_n.first]) continue;// trampa
        if(current_n.first == end) continue;
        for (int i = 0; i < adj_list[current_n.first].size(); i++)
        {
            // solo actualizar si la distancia es mayor
            ii neighbor_n = adj_list[current_n.first][i];
            if(distances[current_n.first] + neighbor_n.second < distances[neighbor_n.first])
            {
                distances[neighbor_n.first] = distances[current_n.first] + neighbor_n.second;

                //modificado
                neighbor_n.second = distances[neighbor_n.first];
                pq.push(neighbor_n);

                //xd
                parent[neighbor_n.first] = current_n.first;

            }

        }
        

    }
}

void solve() 
{
    int n, m; // n of nodes in the graph, n of edges
    cin >> n >> m;

    int a, b, w;
    vvpi adj_list(n, vpi());
    vector<ll> distances;
    vector<int> parent(n, -1);
    for (int i = 0; i < m; i++) // por cada arista
    {
        cin >> a >> b >> w;
        adj_list[a-1].push_back(make_pair(b-1, w));
        adj_list[b-1].push_back(make_pair(a-1, w));
    }

    distances.assign(n, INF);
    dijkstra(adj_list, distances, parent, 0, n-1);
    // cout << "llega aqui";
    if (distances[n-1] == INF) cout << -1;
    else
    {
        vector<int> path;
        for(int i = n-1; i != -1; i = parent[i])// probar despues
        {
            path.push_back(i+1);
        }
        // path.push_back(1);
        // reverse(path.begin(), path.end());

        for (int i = path.size()-1; i >= 0; i--)
        {
            cout << path[i] << " ";
        }
        
    }
    cout << endl;


    
}
