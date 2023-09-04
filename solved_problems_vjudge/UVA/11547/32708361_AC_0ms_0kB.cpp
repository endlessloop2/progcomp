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
    int n;
    cin >> n;
    n = ( ( ( ( ( n * 567 ) / 9) + 7492 ) * 235) / 47) - 498;
    //637
    // decima
    n = (n/10) % 10; 
    n = abs(n);
    cout << n << endl;
}
