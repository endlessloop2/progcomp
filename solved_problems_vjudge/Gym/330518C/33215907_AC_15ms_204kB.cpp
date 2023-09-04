#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

void solve();

int main() 
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.setf(ios::fixed);
    //cout.precision(7);
    solve();
    return 0;
}

void solve() 
{
    int n1,a1,n2,a2,a,b;
    cin >> n1 >> a1;

    vector<vector<int>> c1(n1, vector<int>(n1, 0));
    for(int i = 0; i < a1; ++i)
    {
        cin >> a >> b;
        c1[a][b] = 1;
        c1[b][a] = 1;
    }
    cin >> n2 >> a2;
    vector<vector<int>> c2(n2, vector<int>(n2, 0));
    for(int i = 0; i < a2; ++i)
    {
        cin >> a >> b;
        c2[a][b] = 1;
        c2[b][a] = 1;
    }

    if(n1 != n2 || a1 != a2)
    {
        cout << "No son iguales" << endl;
        return;
    }

    for(int i = 0; i < n1; ++i)
    {
        for(int j = 0; j < n1; ++j)
        {
            if(c1[i][j] != c2[i][j])
            {
                cout << "No son iguales" << endl;
                return;
            }
        }
    }
    cout << "Son iguales" << endl;
}