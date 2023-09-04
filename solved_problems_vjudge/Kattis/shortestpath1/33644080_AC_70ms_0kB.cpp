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


/*void dijkstra(vvpi &adj_list, vector<bool> &distances, int start)
{

}*/

class Compare
{
public:
    bool operator() (ii &a, ii &b)
    {
        return a.second > b.second;
    }
};


/*Algoritmo de Dijkstra sin op. de relajación, solo entrega todas las distancias */
void dijkstra(vvpi &adj_list, vector<int> &distances, int start)
{

    //start--;
    //par nodo, costo total (desde start_n)
    priority_queue<ii, vector<ii>, Compare> pq;
    distances[start] = 0;

    pq.push( make_pair(start, 0) );

    //se elige el nodo con menor costo
    while(!pq.empty())
    {
        //nodo, costo total nodo
        int current_n = pq.top().first;
        int current_tc = pq.top().second;
        pq.pop();

        //si el nodo ya se visito con distancia inferior, no hay q visitarlo de nuevo
        if(current_tc > distances[current_n]) continue;

        for(int i = 0; i < adj_list[current_n].size(); ++i)
        {
            //nodo, costo local nodo
            int neighbor = adj_list[current_n][i].first;
            int neighbor_c = adj_list[current_n][i].second;

            //si la distancia hasta el nodo actual + el costo del vecino es menor a la prev. calculada para el vecino, añadir a cola
            //el vecino y su dist. total actualizada
            if(distances[current_n] + neighbor_c < distances[neighbor])
            {
                distances[neighbor] = distances[current_n] + neighbor_c;
                pq.push(make_pair(neighbor, distances[neighbor] ) );
            }
        }
    }
}


void solve() 
{
    int n, m, q, s, a, b, w; // nodes, edges, queries, starting node
        
        
    while (cin >> n >> m >> q >> s && (n != 0 || m != 0 || q != 0 || s != 0))
    {
        //cout << "out: " << n << " " << m << " " << q << " " << s << endl;
        //vvi adj_list(n, vector<int>());
        vvpi adj_list(n, vpi());
        vector<int> distances(n, INF);
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b >> w;
            adj_list[a].push_back(make_pair(b, w));
            // add nodes.
            //adj_list[a].push_back(b)
        }

        dijkstra(adj_list, distances, s);
        for (int i = 0; i < q; i++)
        {
            //hacer dijkstra con solo calculo de distancias, imprimir el distances para ese.
            cin >> a;
            //cout << "out: ";
            (distances[a] != INF) ? cout << distances[a] << endl : cout << "Impossible" << endl;
        }
    }
}
