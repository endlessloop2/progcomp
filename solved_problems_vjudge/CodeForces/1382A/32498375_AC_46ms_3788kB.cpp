#include <bits/stdc++.h>

using namespace std;

void solve();
int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i)
    {
        solve();
    }
}

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int tmp, result;
    bool found = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        //linear search
        for(int j = 0; j < n && !found; ++j)
        {
            if(v[j] == tmp)
            {
                //esta malo, hay q seguir leyendo
                /*found = 1;
                cout << "YES" << endl;
                cout << "1 " << tmp << endl; 
                return;*/
                found = 1;
                result = tmp;
            }
        }
    }
    //cout << "OUTPUT: " << endl;
    if(found)
    {
        cout << "YES" << endl;
        cout << "1 " << result << endl;
    }
    else
    {
        cout << "NO" << endl;
   }
   //cout << "END" << endl;
}