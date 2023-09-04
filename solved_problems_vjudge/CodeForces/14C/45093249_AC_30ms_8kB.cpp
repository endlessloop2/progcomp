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
    set<ii> st, st_duplicated;
    int x1, y1, x2, y2;

    vector<vector<int>> parallel_x, parallel_y;
    //vector<vector<int>> parallel_y;
    for (int i = 0; i < 4; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;

        // it is a point
        if(x1 == x2 && y1 == y2)
        {
            cout << "NO" << endl;
            return;
        }


        if(st.find(MP(x1, y1)) == st.end())
        {
            st.insert(MP(x1, y1));
        }
        else
        {
            if(!st_duplicated.empty() && st_duplicated.find(MP(x1, y1)) != st_duplicated.end())
            {
                cout << "NO" << endl;
                return;
            }
            else
            {
                st_duplicated.insert(MP(x1,y1));
            }
        }

        if(st.find(MP(x2, y2)) == st.end())
        {
            st.insert(MP(x2, y2));
        }
        else
        {
            if(!st_duplicated.empty() && st_duplicated.find(MP(x2, y2)) != st_duplicated.end())
            {
                cout << "NO" << endl;
                return;
            }
            else
            {
                st_duplicated.insert(MP(x2,y2));

            }
        }

        // st.insert(MP(x1, y1));
        // st.insert(MP(x2, y2));

        //parallel to the Y axis
        if(x1 == x2 && y1 != y2)
        {
            parallel_y.push_back({x1, y1, x2, y2});
        }
        else if(y1 == y2 && x1 != x2) // parallel to the X axis
        {
            parallel_x.push_back({x1, y1, x2, y2});
        }//quizas añadir else para sacar una no paralela altiro
    }
    
    // valid closed geometry figure with positive area
    // all of this guarantees that we have 4/8 different points (there are 4 pairs of points that are equal)
    // there are also 2 parallel lines to the X axis and 2 parallel lines to the Y axis
    if(st_duplicated.size() != 4 || parallel_x.size() != 2 || parallel_y.size() != 2)
    {
        cout << "NO" << endl;
        return;
    }
    


    // i believe at this point we don't need to check that the parallel lines have the same length, just compare?
    // EDIT: will check.
    if(abs(parallel_y[0][1] - parallel_y[0][3]) != abs(parallel_y[1][1] - parallel_y[1][3]) ||
    abs(parallel_x[0][0] - parallel_x[0][2]) != abs(parallel_x[1][0] - parallel_x[1][2])
    )
    {
        // some parallel lines dont have the same length
        cout << "NO" << endl;
        return;
    }
    
    // calc length
    // check that the length of the x line and the y line is different
    // just checking one of the lines, assuming they are the same length.
    // y1 - y2                                         // x1 - x2
    // now checking that the y parallels and x parallels dont have the same length
    // if(abs(parallel_y[0][1] - parallel_y[0][3]) == abs(parallel_x[0][0] - parallel_x[0][2]) ||    
    // abs(parallel_y[1][1] - parallel_y[1][3]) == abs(parallel_x[1][0] - parallel_x[1][2])
    // )
    // {
    //     // not a rectangle, maybe other figure like a square
    //     cout << "NO" << endl;
    //     return;
    // }
    // THIS DOES NOT APPLY TO THE TEST CASES???

    cout << "YES" << endl;


    
    
}