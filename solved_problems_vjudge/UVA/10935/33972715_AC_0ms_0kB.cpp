#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<ll,ll> pii;
typedef vector<pii> vpii;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef set<int> si;

#define MP make_pair
#define INFI INT_MAX
#define INF2 1e9
#define INF INT_MAX-1

void solve();
int main() 
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.setf(ios::fixed);
    solve();
    return 0;
}

void solve() 
{
    int n;
    while(cin >> n && n != 0)
    {
        queue<int> q;
        int top = 1; // 1 for edge case // :/
        for(int i = 0; i < n; ++i)
        {
            q.push(i+1);       
        }
        cout << "Discarded cards:";
        if(q.size() >= 2) cout << " "; //only add space if there are discarded
        while(q.size() >= 2)
        {
            top = q.front();
            q.pop();
            cout << top;
            if(q.size() > 1) cout << ", ";
            top = q.front();
            q.pop();
            q.push(top);
        }
        cout << endl;
        //cout
        cout << "Remaining card: " << top << endl;
    }
}