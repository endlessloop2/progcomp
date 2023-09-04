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
    int n, uwu=0, tmp;
    cin >> n;

    map<int, int> mp;

    // vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        mp[tmp]++;
        if(mp[tmp] > tmp) uwu++;
    }

    map<int,int>::iterator it = mp.begin();
    
    while(it != mp.end())
    {
        if(it->second < it->first) uwu += it->second;
        ++it;
    }
    


    cout << uwu << endl;    
}
