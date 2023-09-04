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
    int n, x, tmp;
    cin >> n >> x;

    set<int> s1;
    set<int> s2;
    map<int, set<int>> mp;
    
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if(s1.find(tmp) != s1.end())
        {
            s2.insert(tmp);
        }
        else
        {
            mp[tmp] = set<int>();
        }
        mp[tmp].insert(i+1);
        s1.insert(tmp);
    }
    
    set<int>::iterator it1 = s1.begin();
    while(it1 != s1.end())
    {
        if(x-(*it1) == x/2 && s2.find(x-(*it1)) != s2.end()) // caso de repetido
        {
            //cout << x/2 << " " << x/2 << endl;
            set<int>::iterator it3 = mp.find(x/2)->second.begin();
            ++it3;
            cout << *(mp.find(x/2)->second.begin()) << " " << *(it3) << endl; 
            return;
        }
        if(!(x-(*it1) == x/2) && s1.find(x-(*it1)) != s1.end()) // caso de no repetido
        {
            //cout << *it1 << " " << *( s1.find(x-(*it1)) ) << endl;
            // set<int>::iterator it4 = mp.find(x-(*it1))->second.begin();
            // ++it4;

            cout << *(mp.find(*it1)->second.begin()) << " " << *(mp.find(x-(*it1))->second.begin()) << endl; 
            return;
        }
        ++it1;
    }
    
    cout << "-1" << endl;
}
