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
#define INF INT_MAX-1

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
    int n;
    string tmp;
    cin >> n;
    set<string> s;
    set<string>::iterator it;
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;

        //(!s.insert(tmp).second) ? cout << "YES" : cout << "NO";
        it = s.find(tmp);
        (it != s.end()) ? cout << "YES" : cout << "NO";
        s.insert(tmp);
        cout << endl;
    }
}