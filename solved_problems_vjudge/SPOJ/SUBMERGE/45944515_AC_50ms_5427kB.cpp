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


void solve();

// sources that helped solve this problem:
// https://soi.ch/wiki/bridges-articulationpoints/
// https://cp-algorithms.com/graph/cutpoints.html
// https://codeforces.com/blog/entry/71146
// https://www.cs.kent.edu/%20/slides/04ArtPointsBridges.pdf

int TIME_CT;

// int ART_CT_2; // bad implementation

set<int> art_points;

int dfs_art(int n, vector<vector<int>> &adj_list, vector<int> &found_time, vector<int> &low, int parent)
{
    TIME_CT++;
    found_time[n] = TIME_CT; // found at this time
    low[n] = TIME_CT; // the lowest it can reach is this.
    int child_count = 0;

    // for all neighbors
    for (int i = 0; i < adj_list[n].size(); i++)
    {
        if(adj_list[n][i] == parent) continue; // we dont want to visit the path that we come from.
        
        // if the neighbors has not been visited
        // weird
        if(!found_time[adj_list[n][i]])
        {
            child_count++;
            dfs_art(adj_list[n][i], adj_list, found_time, low, n); // idk why this is called here. probably to find low before checking it.
            // C1: there is no way to get (BACK) to a node V with strictly smaller disc.time than node U. it is articulation point
            if(found_time[n] <= low[adj_list[n][i]] && !(n == 0 && parent == 0)) // revisar // el ser el primer nodo solo se considerara en el if de la otra funcion
            {
                // ART_CT_2++;
                art_points.insert(n);
            }
            // do the other things so low is updated
            // not an ancestor though
            // TREE EDGE
            low[n] = min(low[n], low[adj_list[n][i]]); // now the lowest that can be reached is the min between the low of this node and the neighbor.
        }
        else
        {
            // FORWARD OR BACK EDGE
            // if the neighbor has already been visited, then it is an ancestor, update low?
            // !! find ancestor with min discovery time
            // checks discovery of current neighbor (ancestor) NOTE: THIS IS BEING CALLED FOR THE NODE ITSELF, IT CAN BE A BUG
            low[n] = min(low[n], found_time[adj_list[n][i]]);
        }

    }
    
    return child_count; // used to check if root node has more than one subgraph

}

int find_art_points(vector<vector<int>> &adj_list)
{
    TIME_CT = 0;// reset
    // ART_CT_2 = 0;
    art_points.clear();

    //int art_ct = 0;
    vector<int> found_time(adj_list.size()); // first time that a node was discovered.
    vector<int> low(adj_list.size()); // stores the node with least disc time that can be reached without going back through same path.
    // for all nodes

    for (int i = 0; i < adj_list.size(); i++)
    {
        // if the node has not been found
        if(!found_time[i])
        {
            // C2: if the node has more than one child (subgraph, it is also an art.point)
            if (dfs_art(i, adj_list, found_time, low, i) > 1)
            {
                //art_ct++;
                art_points.insert(i);
            }
        }
    }
    return art_points.size();
    // return art_ct + ART_CT_2;
}

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
    int N, M; // n of islands, n of bridges // NODES, VORTEX
    
    while(cin >> N >> M && (N != 0 || M != 0)) // for each testcase, end when N=M=0
    {
        vector<vector<int>> adj_list;
        adj_list.assign(N, vector<int>()); // creates N vectors inside vector of vectors
        int a, b;
        for (int i = 0; i < M; i++) // for each vertex
        {
            cin >> a >> b;
            a--; b--; // index 0
            // bidirectional graph
            adj_list[a].push_back(b);
            adj_list[b].push_back(a);
        }

        // run dfs and find art points.
        //vector<bool> visited(N, 0);
        //vector<int> found_time(N, -1); // first time that a node was discovered. // used to see if a node is ancestor of another.
        // given nodes U,V. if there is no way to get (BACK) to a node V with strictly smaller disc.time than node U. it is articulation point
        // or if U is a root and has 2 subgraphs.

        // to see if there is a node with strictly smaller disc.time than u,
        // we need to find a node V with the least disc.time that can be reached from u without passing through viisted nodes.
        // this is represented for each node in the array low[v]
        cout << find_art_points(adj_list) << endl;
    }
    
}