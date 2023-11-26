#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<ll,ll> pll;
typedef vector<pll> vpll;

typedef pair<int,int> ii;
typedef vector<ii> vii;

#define MP make_pair
#define INF2 10e9

typedef pair<ll, ll> pll;
const long long INF = LONG_LONG_MAX-1;
const pll NETR = {INF, INF};

struct SegmentTree {
  vector<pll> ST;
  int N;

  // La raíz sea el nodo 1.
  // Los hijos de un nodo con id n
  // son 2*n y 2*n+1

  // Cada nodo tiene id n,
  // y tiene rango [l, r]
  SegmentTree(vector<ll> &A) {
    N = A.size();
    ST.resize(4*N);

    build(1, 0, N-1, A);
  }

  // Construye correctamente la información
  // para el nodo n
  void build(int n, int l, int r, vector<ll> &A) {
    if(l == r) {
      ST[n] = {A[r], r};
      return;
    }

    int mid = (l+r)/2;

    // Hijo izquierdo
    build(2*n, l, mid, A);

    // Hijo derecho
    build(2*n+1, mid+1, r, A);

    // Construir info del padre
    ST[n] = min(ST[2*n], ST[2*n+1]);
  }

  // Para el nodo n con info sobre [l, r], responde
  // la consulta para el rango [i, j]
  pll query(int n, int l, int r, int i, int j) {
    // Caso 1
    if(i <= l && r <= j) {
      return ST[n];
    }

    // Caso 2
    if(j < l || r < i) {
      return NETR;
    }

    int mid = (l+r)/2;
    pll left_response = query(2*n, l, mid, i, j);
    pll right_response = query(2*n+1, mid+1, r, i, j);

    return min(left_response, right_response);
  }

  // Calcula el minimo del rango [i, j]
  pll query(int i, int j) {
    return query(1, 0, N-1, i, j);
  }

  void update(int n, int l, int r, int i, int x) {
    // [l, r] no contiene al i
    if(i < l || r < i) return;

    // Cuando llego a la hoja
    if(l == i && i == r) {
      ST[n] = {x, i};
      return;
    }

    int mid = (l+r)/2;

    // Hijo izquierdo
    update(2*n, l, mid, i, x);

    // Hijo derecho
    update(2*n+1, mid+1, r, i, x);

    // Construir info del padre
    ST[n] = min(ST[2*n], ST[2*n+1]);
  }

  void update(int i, int x) {
    return update(1, 0, N-1, i, x);
  }
};

// WIP: redo with my own implementation

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

void solve()
{
    int n, q; // n of values and n of queries
    cin >> n >> q;

    vector<ll> vv;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        vv.push_back(tmp);
    }
    SegmentTree tree(vv); 

    int a, b;
    for (int i = 0; i < q; i++)
    {
        cin >> a >> b;
        a--; b--;
        cout << tree.query(a, b).first << endl;
        
    }
    
}