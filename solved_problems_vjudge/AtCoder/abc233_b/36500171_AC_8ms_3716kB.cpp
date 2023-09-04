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

    solve();
    return 0;
}

void solve() 
{
    int l,r;
    cin >> l >> r;

    string s;
    cin >> s;
    reverse(s.begin()+(l-1), s.begin()+(r));
    cout << s;
}
