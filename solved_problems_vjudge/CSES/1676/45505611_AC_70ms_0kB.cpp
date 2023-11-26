#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<ll,ll> pll;
typedef vector<pll> vpll;

typedef pair<int,int> ii;
typedef vector<ii> vii;

#define MP make_pair
#define INF INT_MAX-1
#define INF2 10e9

// Se tomaron ideas (texto, no codigo) de solución a problema similar (no encuentro link)
// link general: https://usaco.guide/gold/dsu?lang=cpp
struct DSU
{
    vector<int> parent; // tree
    vector<int> size;

    int comp_count, largest_comp;

    DSU(int N) // pass the required size
    {
        // init vector
        parent = vector<int>(N, -1); // -1 no connection
        size = vector<int>(N, -1);
        comp_count = N; // the amount of cities
        largest_comp = 0; // size of largest_comp
    }

    // O(1)
    void make_set(int v) // element v
    {
        parent[v] = v; // the root of the tree has itself as parent
        size[v] = 1; // the size of the tree for v is 1.
    }

    void init_all()
    {
        for(int i = 0; i < parent.size(); ++i)
        {
            make_set(i);
        }
    }

    // O(log n)
    int find_set(int v) // finds the parent of the element v
    {

        if(parent[v] == v)
        {
            // found root node
            return v;
        }
        
        int returned = find_set(parent[v]);
        parent[v] = returned; // the parent value is propagated back to all the visited nodes
        return returned;
    }

    int size_root(int v)
    {
        return size[v];
    }

    // O(n), O(2n)?
    // attach the tree with lower rank to the one with bigger rank
    void union_sets(int a, int b) // merge set a and b
    {
        // finds the parents
        a = find_set(a);
        b = find_set(b);
        if(a == b) return;

        // merging two components means there is one component less than before
        comp_count--;
        if(size[a] < size[b])
        {
            // now b is the largest component
            largest_comp = max(largest_comp, size[b] + size[a]);
            // now b is the parent of a
            parent[a] = b;
            size[b] += size[a];
            return;
        }


        // now a is the largest component
        largest_comp = max(largest_comp, size[a] + size[b]);
        // now a is the parent of b
        parent[b] = a; // now the parent of set b is the root of set a, effectively merging
        size[a] += size[b]; // now that we merged a into b, we need to add its size into a.
    }

    int get_comp_count()
    {
        return comp_count;
    }
    int get_largest_comp()
    {
        return largest_comp;
    }


};


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
    int n, m; // cities, roads
    cin >> n >> m;
    DSU ds(n);
    ds.init_all();

    int a, b;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        a--; b--;

        int result_a = ds.find_set(a);
        int result_b = ds.find_set(b);

        ds.union_sets(a, b);

        cout << ds.get_comp_count() << " " << ds.get_largest_comp() << "\n";
        
    }
    
    
    
}