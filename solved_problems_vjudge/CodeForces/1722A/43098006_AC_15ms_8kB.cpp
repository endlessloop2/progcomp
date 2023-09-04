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
    
    int cases;
    cin >> cases;
    for(int i = 0; i < cases; i++)
    {
        solve();
    }
    return 0;
}

void solve()
{
    int n; // len of string s
    string s;
    cin >> n >> s;
    // set<char> st;
    // st.insert('T');
    // st.insert('i');
    // st.insert('m');
    // st.insert('u');
    // st.insert('r');
    
    string tt = "Timur";
    if(n != tt.size())
    {
        cout << "NO" << endl;
        return;
    }
    sort(tt.begin(), tt.end());
    sort(s.begin(), s.end());
    if(tt == s)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    // for(int i = 0; i < s.size(); i++)
    // {

    // }

}