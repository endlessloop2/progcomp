#include<bits/stdtr1c++.h>
using namespace std;

vector<vector<pair<int,int>>> adlista;
vector<int> distancias;
vector<int> padre;

void resolve();
void crearLista(int n);
void agregarVecino(int nodo1,int nodo2,int peso);
int dijkstra(int nodoOrigen,int nodoFinal);

int main(){
  ios_base :: sync_with_stdio (false);
  cin.tie(NULL);
  cout.setf(ios :: fixed);
  
  resolve();

  system("pause");
  return 0;
}

void resolve(){
  int n,m,q,s,u,v,w;
  cin>>n>>m>>q>>s;
  do{
    crearLista(n);
    for(int i=0;i<m;i++){
      cin>>u>>v>>w;
      agregarVecino(u,v,w);
    }
    for(int i=0;i<q;i++){
      int destino,resultado;
      cin>>destino;
      resultado = dijkstra(s,destino);
      if(resultado == 2147483647) cout<<"Impossible" <<'\n';
      else cout<< resultado <<'\n';
      distancias.clear();
      distancias.assign(n,2147483647);
    }
    adlista.clear();
    cin>>n>>m>>q>>s;
    cout<<'\n';
  }while(n+m+q+s != 0);
}

void crearLista(int n){
  for(int i=0;i<n;i++){
    padre.push_back(-1);
    distancias.push_back(2147483647);
    vector<pair<int,int>> nodo = {};
    adlista.push_back(nodo);
  }
}

void agregarVecino(int nodo1,int nodo2,int peso){
  adlista[nodo1].push_back(pair<int,int>(nodo2,peso));
}

int dijkstra(int nodoOrigen,int nodoFinal){
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
        }
      }
    }
  }
  return distancias[nodoFinal];
}