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
    cout.precision(7);
    solve();

    return 0;
}

void solve() 
{
    int n, m, tmp, c; // jack cds, jill cds
    //while(cin >> n >> m && (n != 0 || m != 0))
    
    //while(cin >> n >> m, n||m) 
    while(cin >> n >> m && (n != 0 || m != 0))
    {
        c = 0;// ESTO FALTABA XD
        set<int> ja;
        for(int i = 0; i < n; ++i)
        {
            cin >> tmp;
            ja.insert(tmp);
        }
        for (int i = 0; i < m; i++)
        {
            cin >> tmp;
            if(ja.find(tmp) != ja.end())
            {
                c++;
            }
        }
        cout << c << "\n";
    }
}
