#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
#define MP make_pair

vector<int> bfs(vector<vii> &adj_list, int a, int b);

/*BFS iterativo*/
//traversal de todo el grafo desde a, no hace nada con b por ahora.

vector<int> bfs(vector<vii> &adj_list, int a, int b)
{
    queue<int> q;
    vector<bool> visited(adj_list.size(), 0);
    visited[a] = 1;
    q.push(a);
    while(!q.empty())
    {
        int currentNode = q.front();
        q.pop();
        cout << "En " << currentNode << endl;

        for(int i = 0; i < adj_list[currentNode].size(); ++i)
        {
            int neighbor = adj_list[currentNode][i].first;

            //visited quiere decir que el nodo ya fue visitado (vecinos ya visitados)
            //o se esta visitando y esta en la cola (vecinos no visitados)
            if(!visited[neighbor])
            {
                q.push(neighbor);
                cout << "Marcando " << neighbor << " como visitado" << endl;
                visited[neighbor] = true;
            }
        }
    }
    return vector<int>(0,0);
}