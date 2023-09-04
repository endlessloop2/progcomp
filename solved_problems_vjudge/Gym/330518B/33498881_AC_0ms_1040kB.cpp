#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef vector<vector<int>> vvi;

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
    int n, e, q; // students, connections, queries.
    cin >> n >> e >> q;
    vector<int> notas(n);  
    //vvi adj_matrix(n, vector<int>(n, 0));
    vector<vector<bool>> adj_matrix(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
    {
        cin >> notas[i];
    }
    int a, b, c;
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b;
        adj_matrix[a][b] = 1;
        adj_matrix[b][a] = 1;    
    }
    
    for (int i = 0; i < q; i++)
    {
        cin >> c >> a;
        if(c == 1)
        {
            cin >> b;
            adj_matrix[a][b] = 0;
            adj_matrix[b][a] = 0;
        }
        else
        {
            bool f = 0;
            for (int j = 0; j < adj_matrix[a].size(); j++)
            {
                if((adj_matrix[a][j]) && (abs(notas[a] - notas[j]) <= 5))
                {
                    if(f) cout << " ";
                    cout << j;
                    f=1;
                }
            }
            if(!f) cout << "No copio, honesto el cabro";
            cout << endl;
            
        }

    }
    
    
}
