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

void bfs(vvi &adj_list, vector<bool> &visited, int start)
{
    int level = 0;
    queue<int> q;
    //visited[start] = 1;
    // no es necesario marcar como visitado, pq en el fondo termina y se limita porq es unidireccional y maximo level 2.// todo eso mal xd
    // sino si habria que marcar como visitado y crear condicion especial...
    // a si mismo maximo se puede visitar 1 vez, no habra loop. pq despues si se marca como visited.
    q.push(start);
    //nodo de inicio

    while(!q.empty())
    {
        int curr = q.front(); //se visita el nodo actual? // mas bien se visitan los vecinos de este.
        q.pop();

        //if(level == 2) return;// ya estamos en un nodo a 2 de distancia, los siguientes ya se pasan. // no era asi al final :[
        for (int i = 0; i < adj_list[curr].size(); i++)
        {
            //ahora si se visita el nodo.. si no esta visitado
            if(!visited[adj_list[curr][i]])
            {
                visited[adj_list[curr][i]] = 1;// a si mismo maximo se puede visitar 1 vez, no habra loop.
                q.push(adj_list[curr][i]); // se pushea como uno que se visitan sus vecinos despues

            }
        }
        //aumenta el nivel aqui???
        ++level;
    }
}
//el starting vertex no tiene que ser cero.
// NOTA: posiblemente haya una forma mucho mas eficiente, calculando todas las distancias desde todos los nodos, pero depende de q
// starting nodes pidan... algo asi.
void solve() 
{
    int n, a, b;

    while (cin >> n && n != 0)
    {
        vvi adj_list(n, vector<int>());
        vector<bool> visited(n, 0);

        while(cin >> a && a != 0)
        {// por cada grupo de sets, q termina con 0 cuando no hay mas sets
            while (cin >> b && b != 0) //hasta q el set termine
            {
                //a va con b
                //ignorar conexiones a si mismo, no se consideran ?
                //al final no se ignoran, pero pq en la definicion no especifica??
                /*if(a != b)*/ adj_list[a-1].push_back(b-1);
            }
            // dfs(adj_list, visited, x);
        }
        //hasta aca no hay bugs XD
        int x, y; //, c = 0; // n of ints to check, int to check, not visited count
        cin >> x;
        for (int i = 0; i < x; i++) // for each starting bfs
        {
            vector<int> not_visited;
            cin >> y;
            //aca estaba el otro bug, hay q restar siempre, recordar
            bfs(adj_list, visited, y-1);
            for (int j = 0; j < visited.size(); j++)
            {
                if(!visited[j])
                {
                    //++c;
                    not_visited.push_back(j);
                }
            }

            //cout << "o;";
            cout << not_visited.size();
            for (int j = 0; j < not_visited.size(); j++)
            {
                cout << " " << not_visited[j] + 1;//era un j no i.
            }
            cout << endl;

            visited.assign(n, 0);// reset visited
        }

    }
    //hay que revisar con BFS, solo hasta 2 niveles.
}
