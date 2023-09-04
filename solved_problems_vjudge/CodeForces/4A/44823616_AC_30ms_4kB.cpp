#include <bits/stdc++.h>

using namespace std;

void solve();

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int cases;
    //cin >> cases;
    cases = 1;
    for(int i = 0; i < cases; ++i)
    {
        solve();
    }
    return 0;
}

void solve()
{
    int w;
    cin >> w;

    if(w % 2 != 0 || w == 2)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
}