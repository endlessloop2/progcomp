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
    int c;
    cin >> c;
    for (int i = 0; i < c; i++)
    {
        cout << "Case #" << i+1 << ": "; 
        solve();
    }
    
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

void dijkstra(vvpi &adj_list, vector<int> &distances, int start, int end)
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
        // if(current_n.first == end) continue;
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
            }

        }
        

    }
}

void solve() 
{
    int n, m, s, t; // n of nodes in the graph, n of edges, start node, end node
    int a, b, w;
    
    cin >> n >> m >> s >> t;
    vvpi adj_list(n, vpi());
    vector<int> distances(n, INF);
    for (int i = 0; i < m; i++) // por cada arista
    {
        cin >> a >> b >> w; 
        adj_list[a].push_back(make_pair(b, w));
        adj_list[b].push_back(make_pair(a, w));
    }


    dijkstra(adj_list, distances, s, t);
    (distances[t] == INF) ? cout << "unreachable" : cout << distances[t];
    cout << endl;

}
