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

int TIME_CT;

void dfs_art(int n, vector<vector<int>> &adj_list, vector<int> &found_time, vector<int> &low, int parent, set<int> &art_points)
{
    TIME_CT++;
    low[n] = TIME_CT; // found at this time
    found_time[n] = TIME_CT; // found at this time
    int child_count = 0;

    // for all neighbors
    for (int i = 0; i < adj_list[n].size(); i++)
    {
        if(adj_list[n][i] == parent) continue; // we dont want to visit the path that we come from.
        
        // if the neighbors has not been visited
        if(found_time[adj_list[n][i]] == 0)
        {
            child_count++;
            dfs_art(adj_list[n][i], adj_list, found_time, low, n, art_points); // find low
            // C1: there is no way to get (BACK) to a node V with strictly smaller disc.time than node U. it is articulation point
            if(found_time[n] <= low[adj_list[n][i]] && parent != -1) // revisar
                art_points.insert(n);
            
            // do the other things so low is updated
            // not an ancestor though
            low[n] = min(low[n], low[adj_list[n][i]]); // now the lowest that can be reached is the min between the low of this node and the neighbor.
        }
        else
        {
            // if the neighbor has already been visited, then it is an ancestor, update low?
            // !! find ancestor with min discovery time
            // checks discovery of current neighbor (ancestor)
            low[n] = min(low[n], found_time[adj_list[n][i]]);
        }

    }
    
    // C2: it is root node and it has more than 1 child subgraph
    if (parent == -1 && child_count > 1)
    {
        art_points.insert(n);
    }

}

set<int> find_art_points(vector<vector<int>> &adj_list)
{
    TIME_CT = 0;// reset

    vector<int> found_time(adj_list.size(), 0); // first time that a node was discovered.
    vector<int> low(adj_list.size(), 0); // stores the node with least disc time that can be reached without going back through same path.
    set<int> art_points;


    for (int i = 0; i < adj_list.size(); i++)
    {
        // if the node has not been found
        if(found_time[i] == 0)
        {
            dfs_art(i, adj_list, found_time, low, -1, art_points);
        }
    }
    //return ap;
    return art_points;
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
    int N, ctt = 0;
    

    bool flag = false;
    while(cin >> N && N != 0)
    {
        if(!flag)
        {
            flag = 1;
        }
        else cout << endl;
        map<string, int> mp1;
        map<int, string> mp2;
        // N number of locations in the city.
        string loc_name;
        for (int i = 0; i < N; i++)
        {
            cin >> loc_name; // location names
            mp1[loc_name] = i;
            mp2[i] = loc_name;
        }
        
        int r; // n of routes
        cin >> r;
        string a_s, b_s;
        vector<vector<int>> adj_list(N, vector<int>());
        for (int i = 0; i < r; i++)
        {
            cin >> a_s >> b_s;
            adj_list[mp1[a_s]].push_back(mp1[b_s]);
            adj_list[mp1[b_s]].push_back(mp1[a_s]);
        }
        
        ctt++;
        set<int> art_points = find_art_points(adj_list);

        cout << "City map #" << ctt << ": " << art_points.size() << " camera(s) found"  << endl; 
        

        vector<string> aps;
        set<int>::iterator it = art_points.begin();
        
        set<string> art_points_names;

        while (it != art_points.end())
        {
            //cout << mp2[(*it)] << endl;
            art_points_names.insert(mp2[(*it)]);
            ++it;
        }

        set<string>::iterator it2 = art_points_names.begin();

        while (it2 != art_points_names.end())
        {
            cout << *it2 << endl;
            ++it2;
        }



        // cout << endl;
        
    }

}