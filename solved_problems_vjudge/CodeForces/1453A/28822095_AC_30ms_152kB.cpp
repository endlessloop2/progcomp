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
    int n,m,c=0;
    //vector<int> bTrains;
    //vector<int> lTrains;
    set<int> trains;
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;
        //bTrains.push_back(tmp);
        trains.insert(tmp);
    }
    for(int i = 0; i < m; ++i)
    {
        int tmp;
        cin >> tmp;
        //lTrains.push_back(tmp);
        if(trains.find(tmp) != trains.end()) ++c;
    }

    cout << c << endl;
}