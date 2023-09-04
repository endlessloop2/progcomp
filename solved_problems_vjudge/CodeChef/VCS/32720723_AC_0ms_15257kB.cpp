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
    int n, m, k, f1 = 0, f2 = 0, tmp; // n of files, n of ignored files, n of tracked files. // out: tracked && ignored, !(tracked && ignored)
    cin >> n >> m >> k;
    
    set<int> ig;
    set<int> tr;
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        ig.insert(tmp);

    }
    for (int i = 0; i < k; i++)
    {
        cin >> tmp;
        tr.insert(tmp);
        if(ig.find(tmp) != ig.end()) ++f1;
    }    

    for (int i = 0; i < n; i++)
    {
        if(ig.find(i+1) == ig.end() && tr.find(i+1) == tr.end()) ++f2;
    }
    
    cout << f1 << " " << f2 << "\n";
}
