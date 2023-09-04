#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

void solve();
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
        //cout << "input: ";
        cout << i+1 << " ";
        solve();
    }

    return 0;
}


int bubblesort(vector<int> &v)
{
    int steps = 0;
    for (int i = 0; i < v.size()-1; i++)
    {
        for (int j = 0; j < v.size()-1-i; j++)
        {
            if(v[j] > v[j+1])
            {
                swap(v[j], v[j+1]);
                ++steps;
            }
                
        }
        
    }
    return steps;
    
}

void solve() 
{
    vector<int> v(20);
    int tmp;
    cin >> tmp;
    for (int i = 0; i < 20; i++)
    {
        cin >> v[i];
    }
    cout << bubblesort(v) << endl;
}
