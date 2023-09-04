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

    int cases;
    cin >> cases;

    for (int i = 0; i < cases; i++)
    {
        solve();
    }
    
    return 0;
}

void solve() 
{
    int len;
    cin >> len;
    string l;
    cin >> l;

    set<int> ss;
    int ct = 0;

    for (int i = 0; i < l.size(); i++)
    {
        if(ss.count(l[i]) == 1)
        {
            ct += 1;
            
        }
        else
        {
            ct += 2;
            ss.insert(l[i]);
        }

    }

    // cout << "o: ";
    cout << ct << endl;
    
}
