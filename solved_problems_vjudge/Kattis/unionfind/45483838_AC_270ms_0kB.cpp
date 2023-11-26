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

// With help from USACO guide and cp-algorithms
struct DSU
{
    vector<int> parent; // tree
    vector<int> size;

    DSU(int N) // pass the required size
    {
        // init vector
        parent = vector<int>(N, -1); // -1 no connection
        size = vector<int>(N, -1);
    }

    // O(1)
    void make_set(int v) // element v
    {
        parent[v] = v; // the root of the tree has itself as parent
        size[v] = 1; // the size of the tree for v is 1.
    }

    // O(log n) // probably for future calls?
    int find_set(int v) // finds the parent of the element v
    {
        if(parent[v] == -1)
        {
            return -1;
        }

        if(parent[v] == v)
        {
            // found root node
            return v;
        }
        
        int returned = find_set(parent[v]);
        parent[v] = returned; // the parent value is propagated back to all the visited nodes
        return returned;
    }

    // O(n), O(2n)?
    // attach the tree with lower rank to the one with bigger rank
    void union_sets(int a, int b) // merge set a and b
    {
        // finds the parents
        a = find_set(a);
        b = find_set(b);
        if(a == b) return;

        if(size[a] < size[b])
        {
            // now b is the parent of a
            parent[a] = b;
            size[b] += size[a];
            return;
        }

        // now a is the parent of b
        parent[b] = a; // now the parent of set b is the root of set a, effectively merging
        size[a] += size[b]; // now that we merged a into b, we need to add its size into a.
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
    int n, q; // base set elements, operations
    cin >> n >> q;
    DSU ds(n);

    cin.ignore();
    char cmd;
    int a, b, c;
    for (int i = 0; i < q; ++i)
    {
        cin >> cmd >> a >> b;
        // a--; b--;
        if(cmd == '?')
        {
            int result_a = ds.find_set(a);
            int result_b = ds.find_set(b);
            if(result_a == -1)
            {
                ds.make_set(a);
                result_a = a;
            }
            if(result_b == -1)
            {
                ds.make_set(b);
                result_b = b;
            }
            result_a == result_b ? cout << "yes" : cout << "no";
            cout << "\n";
        }
        else
        {
            int result_a = ds.find_set(a);
            int result_b = ds.find_set(b);
            if(result_a == -1)
            {
                ds.make_set(a);
            }
            if(result_b == -1)
            {
                ds.make_set(b);
            }
            ds.union_sets(a, b);
        }
        
    }
    
    
    
}