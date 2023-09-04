#include <bits/stdc++.h>

using namespace std;

void solve();
typedef long long ll;
typedef long double ld;

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
}

void solve()
{
    int n,k;
    string s;
    char l = 'a';
    cin >> n >> k;//largo de la string, max palindrome

    for(int i = 0; i < n; ++i)
    {
        if(l > 'c') l = 'a';
        s += l;
        ++l;
    }
    cout << s << endl;
}