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
   int n; // n of words for each person, there are 3
   cin >> n;

   string tmp;
   vector<int> points (3, 0);
   map<string, set<int>> mp;
   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < n; j++)
      {
         //for each word of every person
         cin >> tmp;
         //map<string, set<int>>::iterator it1 = mp.find("tmp");
         if(mp.find(tmp) == mp.end())
         {
            mp[tmp] = set<int>();
         }
         mp[tmp].insert(i);
      }
      
   }
   map<string, set<int>>::iterator it = mp.begin();
   
   while(it != mp.end())
   {
      //it->second is the array
      if(it->second.size() == 3)
      {
      }
      else if(it->second.size() == 2)
      {
         set<int>::iterator it2 = it->second.begin();
         points[*it2]++;
         //next(it2);
         it2++;
         points[*it2]++;
      }      
      else if(it->second.size() == 1)
      {
         set<int>::iterator it2 = it->second.begin();
         points[*it2] += 3;
      }
      // for(int i = 0; i < it->second.size(); ++i)
      // {

      // }
      it++;
   }

   for (int i = 0; i < 3; i++)
   {
      cout << points[i] << " ";
      
   }
   cout << endl;
}