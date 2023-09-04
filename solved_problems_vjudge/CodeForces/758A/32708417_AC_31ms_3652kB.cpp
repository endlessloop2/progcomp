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
    int n, numMax = 0, s = 0; // n of citizens
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        numMax = max(numMax, v[i]);
    }
    for (int i = 0; i < n; i++)
    {
        s += (numMax - v[i]);
    }    

    cout << s << endl;
}
