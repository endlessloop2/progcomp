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

    solve();

    return 0;
}

void solve()
{
    int d, sumTime;
    cin >> d >> sumTime;

    int a, b, t = 0;

    vector<pair<int, int>> vp;
    map<int, int> hoursAdded; // day, hours studied that day
    for (int i = 0; i < d; i++)
    {
        cin >> a >> b;
        vp.push_back(make_pair(a,b));
        t += a;
        hoursAdded[i] = a;
        if(t > sumTime)
        {
            cout << "NO" << endl;
            return;
        }
    }
    
    bool flag = 0;
    for (int i = 0; i < d; i++)
    {
        //descontar lo que ya añadimos
        //t += vp[i].second - hoursAdded[i];
        if(t + (vp[i].second - hoursAdded[i]) > sumTime)
        {
            //t += abs(sumTime - t);
            hoursAdded[i] += (sumTime - t);
            flag = 1;
            break;
        }
        else
        {
            t += (vp[i].second - hoursAdded[i]);
            hoursAdded[i] += (vp[i].second - hoursAdded[i]);
        }
        if(t == sumTime)
        {
            flag = 1;
            break;
        }
    }
    
    if(flag)
    {
        cout << "YES" << endl;
        //cout << hoursAdded.size() << " ";
        for (map<int, int>::iterator it = hoursAdded.begin(); it != hoursAdded.end() ; it++)
        {
            cout << it->second << " ";
        }
        cout << endl;
        
        return;
    }
    cout << "NO" << endl;

}