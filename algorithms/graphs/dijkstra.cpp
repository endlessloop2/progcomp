#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
#define MP make_pair
#define INF 10e8

vector<int> dijkstra(vector<vii> &adj_list, vector<int> &distances, int startnode);
//vector<int> rebuildPath(vector<int> &prev, int a, int b);


//greater por el second
class Compare
{
public:
    bool operator() (ii &a, ii &b)
    {
        return a.second > b.second;
    }
};

/*Algoritmo de Dijkstra sin op. de relajación, solo entrega todas las distancias */
vector<int> dijkstra(vector<vii> &adj_list, vector<int> &distances, int start_n)
{
    //los nodos parten de 1, hay que restarle
    start_n--;

    //par nodo, costo total (desde start_n)
    priority_queue<ii, vector<ii>, Compare> pq;
    distances[start_n] = 0;

    pq.push( make_pair(start_n, 0) );

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
    return vector<int>();
}
