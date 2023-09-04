#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef vector<vector<int>> vvi;

void solve();
int main() 
{
    // ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(7);
    solve();

    return 0;
}


void dfs(vvi &adj_list, vector<int> &visited, int node, bool f=0)
{

    for (int i = 0; i < adj_list[node].size(); i++)
    {
        if(visited[adj_list[node][i]]) continue;

        visited[adj_list[node][i]] = 1;
        dfs(adj_list, visited, adj_list[node][i], f);
    }
    
}
//el starting vertex no tiene que ser cero.
void solve() 
{
    int n, a, b;

    while (cin >> n && n != 0)
    {
        vvi adj_list(n, vector<int>());
        vector<int> visited(n, 0);

        while(cin >> a && a != 0)
        {// por cada grupo de sets, q termina con 0 cuando no hay mas sets
            while (cin >> b && b != 0) //hasta q el set termine
            {
                // a va con b
                // las conexiones a si mismo importan y se consideran
                adj_list[a-1].push_back(b-1);
            }
        }

        int x, y; // n of ints to check, int to check, not visited count
        cin >> x;
        for (int i = 0; i < x; i++) // for each starting dfs
        {
            vector<int> not_visited;
            cin >> y;
            dfs(adj_list, visited, y-1);

            for (int j = 0; j < visited.size(); j++)
            {
                if(!visited[j])
                {
                    not_visited.push_back(j);
                }
            }

            cout << not_visited.size(); // aaa
            for (int j = 0; j < not_visited.size(); j++)
            {
                cout << " " << not_visited[j] + 1;
            }
            cout << endl; //aaa 

            // visited.clear();
            visited.assign(n, 0);// reset visited
        }

    }
}