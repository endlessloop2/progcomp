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
    int n, q; // n of values and n of queries
    cin >> n >> q;

    vector<int> vv;
    //vector<int> prefix_xor(n, 0);
    vector<int> prefix_xor(n+1, 0); // added one index for using rangea-1 safely
    int tmp;
    ll current_value = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        vv.push_back(tmp);
        current_value ^= tmp; // 0 xor something is something, so it works
        prefix_xor[i+1] = current_value;
        //prefix_xor.push_back(current_value);
    }

    int a, b;
    for (int i = 0; i < q; i++)
    {
        // range query
        cin >> a >> b;
        //a--; b--; // 0 indexed
        // int t1 = prefix_xor[b];
        // int t2 = prefix_xor[a];
        // int ttt = t1 ^ t2;
        // int lls = (prefix_xor[b] ^ prefix_xor[a]);
        cout << (prefix_xor[b] ^ prefix_xor[a-1]) << endl;
    }
    
    
}