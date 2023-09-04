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
    solve();

    return 0;
}

void solve() 
{
    int n, am;
    string libro;
    cin >> n;
    set<string> s;
    for (int i = 0; i < n; i++)
    {
        cin >> am;// cant libros de persona i.

        for (int j = 0; j < am; j++)
        {
            cin >> libro;
            s.insert(libro);
        }
        
    }

    set<string>::iterator it = s.begin();

    while (it != s.end())
    {
        cout << *it << endl;
        ++it;
    }
    


    
}
