/*TEMPLATE */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<ll,ll> pii;
typedef vector<pii> vpii;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef set<int> si;

#define MP make_pair
#define INFI INT_MAX
#define INF2 1e9
#define INF INT_MAX-1

void solve();
int main() 
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.setf(ios::fixed);
    //cout.precision(7);
    int cases;
    cin >> cases;
    for(int i = 0; i < cases; ++i)
    {
        solve();
    }

    return 0;
}

void solve() 
{
    string a,b;
    cin >> a;
    b=a;
    reverse(a.begin(), a.end());
    (a==b) ? cout << "wins" : cout << "loses";
    cout << endl;
}