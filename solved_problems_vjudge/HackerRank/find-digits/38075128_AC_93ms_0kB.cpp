#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpi;
typedef vector<vpi> vvpi;
typedef pair<int,int> ii;

#define INF INT_MAX-1

void solve();
int main() 
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(7);
    int c;
    cin >> c;

    for(int i = 0; i < c; i++)
    {
        solve();
    }

    return 0;
}


void solve() 
{
    string n;
    cin >> n;
    int n_int = stoi(n), c = 0;
    
    for (int i = 0; i < n.size(); i++)
    {
        // cout << n[i] - '0' << endl;
        if((n[i] - '0') != 0 && n_int % (n[i] - '0') == 0)
        {
            c++;
        }
    }
    cout << c << endl;
}
