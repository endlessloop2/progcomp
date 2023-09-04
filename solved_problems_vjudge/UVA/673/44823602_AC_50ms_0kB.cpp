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
    
    int n;
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; ++i)
    {
        solve();
    }

    return 0;
}

void solve()
{
    string tmp;
    // cin >> tmp;
    getline(cin, tmp);

    //cout << tmp << " " << tmp.size() << endl;
    if((tmp.size() % 2) != 0)
    {
        cout << "No" << endl;
        return;
    }

    if(tmp[0] == ')' || tmp[0] == ']' || tmp[tmp.size()-1] == '(' || tmp[tmp.size()-1] == '[')
    {
        cout << "No" << endl;
        return;
    }

    for (int i = 0; i < tmp.size(); i++)
    {
        if((tmp[i] == '(' && tmp[i+1] == ']') || (tmp[i] == '[' && tmp[i+1] == ')'))
        {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
    
}