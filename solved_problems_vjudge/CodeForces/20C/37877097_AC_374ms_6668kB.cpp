#include<bits/stdtr1c++.h>
using namespace std;

#define INF 1000000000000L

vector<vector<pair<int,int>>> adlista;
vector<long long> distancias;
vector<int> padre;

void resolve();
void crearLista(int n);
void agregarVecino(int nodo1,int nodo2,int peso);
long long dijkstra(int nodoOrigen,int nodoFinal);

int main(){
  resolve();

  return 0;
}

void resolve(){
  int n,m,a,b,w;
  cin>>n>>m;
  crearLista(n);
  for(int i=0;i<m;i++){
    cin>>a>>b>>w;
    agregarVecino(a-1,b-1,w);
  }

  long long distanciaCaminoCorto = dijkstra(0, n-1);
  if(distanciaCaminoCorto != INF){
    vector<int>caminoFinal;
    for (int i = n-1; padre[i] != -1; i = padre[i])
    {
        // cout << "padre[" << i << "]" << " = " << padre[i] << endl;
      caminoFinal.push_back(i+1);
    }
    caminoFinal.push_back(1);
    
    for (int i = caminoFinal.size()-1; i >= 0; i--)
    {
      cout<<caminoFinal[i]<<" ";
    }
  }
  else
  {
    cout << -1 << endl;
  }
}

void crearLista(int n){
  for(int i=0;i<n;i++){
    distancias.push_back(INF);
    padre.push_back(-1);
    vector<pair<int,int>> nodo = {};
    adlista.push_back(nodo);
  }
}

void agregarVecino(int nodo1,int nodo2,int peso){
  adlista[nodo1].push_back(pair<int,int>(nodo2,peso));
  adlista[nodo2].push_back(pair<int,int>(nodo1,peso));
}

long long dijkstra(int nodoOrigen,int nodoFinal){
  distancias[nodoOrigen] = 0;
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> siguiente;
  siguiente.push(pair<int,int>(0,nodoOrigen));
  while(!siguiente.empty()){
    int nodo = siguiente.top().second;
    int distancia = siguiente.top().first;
    siguiente.pop();
    if(nodo != nodoFinal && distancia <= distancias[nodo]){
      for(int i=0;i<adlista[nodo].size();i++){
        int vecino = adlista[nodo][i].first;
        int peso = adlista[nodo][i].second;
        if(distancias[vecino] > distancias[nodo] + peso){
          distancias[vecino] = distancias[nodo] + peso;
          siguiente.push(pair<int,int>(distancias[vecino],vecino));
          padre[vecino] = nodo;
        }
      }
    }
  }
  return distancias[nodoFinal];
}