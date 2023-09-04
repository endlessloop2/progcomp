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
    string head, text;
    getline(cin, head);
    getline(cin, text);

    //no, se pueden usar mas de una vez segun cuantos hay.

    map<char, int> mp;

    for (int i = 0; i < head.size(); i++)
    {
        mp[head[i]]++;
    }
    
    
    for (int i = 0; i < text.size(); i++)
    {
        if(text[i] == ' ') continue;
        //cout << text[i] << endl;
        if(mp.find(text[i]) != mp.end())
        {
            if(mp.find(text[i])->second > 0)
            {
                mp.find(text[i])->second--;
            }
            else
            {
                cout << "NO" << endl;
                return;                
            }
        }
        else
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
    
}
