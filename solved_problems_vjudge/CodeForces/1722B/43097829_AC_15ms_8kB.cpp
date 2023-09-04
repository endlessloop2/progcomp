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

    int cases;
    cin >> cases;
    for(int i = 0; i < cases; i++)
    {
        solve();
    }
    return 0;
}

void solve()
{
   int n; // n of columns of grid
   string s1, s2;// the rows
   cin >> n >> s1 >> s2;
   bool a = true;
   for(int i = 0; i < s1.size(); i++){
      if((s1[i] == 'R' && s2[i] != 'R') || (s2[i] == 'R' && s1[i] != 'R'))
      {
         a = false;
         break;
      }
   }

   (a) ? cout << "YES" : cout << "NO";
   cout << endl;
}