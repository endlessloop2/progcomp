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

void bubble(vector<int> &v)
{
    for (int i = v.size(); i > 0; i--)
    {
        for (int j = 0; j < i - 1; j++)
        {
            if(v[j] > v[j+1])
            {
                swap(v[j], v[j+1]);
                // uwuswap(v[j], v[j+1]);
            }
        }
        
    }
    
}

void solve() 
{
    string s, s2;
    cin >> s;
    vector<int> v;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] != '+')
        {
            v.push_back(s[i] - 48);
        }
    }
    // sort(v.begin(), v.end());
    bubble(v);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
        if(v.size() != 1 && i < v.size()-1) 
        {
            cout << "+";
        }
    }
    cout << endl;
}
