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
    int n, m=0, s=0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int ml, sl;
        cin >> ml >> sl;
        m += ml * (i+1);
        s += sl * (i+1);
    }

    if(m > s)
    {
        cout << "Mario" << endl;
    }
    else if(m < s)
    {
        cout << "Sonic" << endl;
    }
    else cout << "Empate" << endl;
}
