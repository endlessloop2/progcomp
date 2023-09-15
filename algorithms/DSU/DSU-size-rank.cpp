// DSU implementation with depth-compression

#include <bits/stdc++.h>

using namespace std;

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

    void init_all()
    {
        for(int i = 0; i < parent.size(); ++i)
        {
            make_set(i); // it is a set
        }
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

int main()
{
    //vector<int> V = {5, 9, 8, 2, 2, 3, 1, 42};

    DSU ds(1000); // max size

    // example of nodes from cp-algorithms
    ds.make_set(1);
    ds.make_set(2);
    ds.make_set(3);
    ds.make_set(4);

    cout << ds.find_set(1) << endl;
    cout << ds.find_set(2) << endl;
    cout << ds.find_set(3) << endl;
    cout << ds.find_set(4) << endl;    
    cout << "----------\n";

    ds.union_sets(1, 2); // the parent of 2 will be 1.
    cout << ds.find_set(2) << endl; 
    cout << ds.find_set(1) << endl;
    cout << "----------\n";

    ds.union_sets(3, 4); // the parent of 4 will be 3.
    cout << ds.find_set(4) << endl; 
    cout << ds.find_set(3) << endl;


    cout << "----------\n";
    ds.union_sets(1, 3); // the parent of 3 will be 1.
    cout << ds.find_set(2) << endl; 
    cout << ds.find_set(4) << endl;    


    return 0;
}