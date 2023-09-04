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
    int n, m;
    string tmp1, tmp2; // n of sv, n of config files
    cin >> n >> m;
    map<string, string> mp;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp1 >> tmp2;
        mp[tmp2] = tmp1;
    }
    for(int i = 0; i < m; ++i)
    {
        cin >> tmp1 >> tmp2;
        cout << tmp1 << " " << tmp2 << " #" << mp[tmp2.substr(0, tmp2.size()-1)] << "\n";
    }
}
