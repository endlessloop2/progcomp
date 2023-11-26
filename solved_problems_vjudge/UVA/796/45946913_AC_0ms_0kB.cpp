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


void dfs_br(int n, vector<vector<int>> &adj_list, vector<int> &found_time, vector<int> &low, int parent, set<pair<int,int>> &bridges)
{
    TIME_CT++;
    found_time[n] = TIME_CT; // found at this time
    low[n] = TIME_CT; // the lowest it can reach is this.

    // for all neighbors
    for (int i = 0; i < adj_list[n].size(); i++)
    {
        if(adj_list[n][i] == parent) continue; // we dont want to visit the path that we come from.
        
        // if the neighbors has not been visited
        if(!found_time[adj_list[n][i]])
        {
            dfs_br(adj_list[n][i], adj_list, found_time, low, n, bridges); // idk why this is called here. probably to find low before checking it.
            // C1: there is no way to get (BACK) to a node V with NOT STRICTLY smaller disc.time than node U. it is bridge // if there is a way to same discover time then it is the root of a cycle
            //if(found_time[n] < low[adj_list[n][i]] && !(n == 0 && parent == 0)) //
            if(found_time[n] < low[adj_list[n][i]])
            {
                            // The links are listed in ascending order according to their first element. // check before ordering
                bridges.insert(MP(min(n, adj_list[n][i]), max(n, adj_list[n][i])));
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
    
    // return child_count; // used to check if root node has more than one subgraph

}

set<pair<int,int>> find_bridges(vector<vector<int>> &adj_list)
{
    TIME_CT = 0;// reset

    vector<int> found_time(adj_list.size()); // first time that a node was discovered.
    vector<int> low(adj_list.size()); // stores the node with least disc time that can be reached without going back through same path.
    // for all nodes
    set<pair<int,int>> bridges;

    for (int i = 0; i < adj_list.size(); i++)
    {
        // if the node has not been found
        if(!found_time[i])
        {
            dfs_br(i, adj_list, found_time, low, -1, bridges);
        }
    }
    return bridges;
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

    int V; // n of nodes
    // bool flag = 0;
    while(cin >> V)
    {
        // cout << V << "\n";
        int a, b;
        string neighbor_ct_str;
        vector<vector<int>> adj_list;
        adj_list.assign(V, vector<int>()); // creates N vectors inside vector of vectors
        
        
        for (int i = 0; i < V; i++)
        {
            cin >> a;   
            cin >> neighbor_ct_str;
            //
            int p1 = neighbor_ct_str.find_first_of('('), p2 = neighbor_ct_str.find_first_of(')');
            string neighbor_ct_str_new;
            for (int k = p1+1; k < p2; k++)
            {
                neighbor_ct_str_new += neighbor_ct_str[k];
            }
            int neighbor_ct = stoi(neighbor_ct_str_new);            
            //
            //cout << a << " " << neighbor_ct << "\n";
            for (int j = 0; j < neighbor_ct; j++)
            {
                cin >> b;
                // bidirectional graph
                adj_list[a].push_back(b);
                adj_list[b].push_back(a); // revisar
                // cout << b << "\n";
            }
            
        }
        set<pair<int,int>> bridges_return = find_bridges(adj_list);

        // if(flag)
        // { 
        //     cout << "\n";
        // }
        // else flag = 1;
        cout << bridges_return.size() << " critical links" << "\n";

        auto it = bridges_return.begin();
        while(it != bridges_return.end())
        {
            // The links are listed in ascending order according to their first element. // check before ordering
            cout << it->first << " - " << it->second << "\n";
            //cout << min(it->first, it->second) << " - " << max(it->first, it->second) << "\n";
            it++;
        }
        cout << "\n";
    }

}