#include <bits/stdc++.h>

using namespace std;

typedef long long int li;
typedef long double ld;

typedef pair<int,int> ii;
typedef vector<ii> vii;

#define INF INT_MAX;
void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(7);
    solve();
}

void solve()
{
    int st, av; //calles y avenidas
    cin >> st >> av;
    
    //map<int,int> restaurants1;// calle, costo
    //map<int,int> restaurants2;// avenida, costo
    //vector<int> minCost;//minimo costo en linea
    int maxCost = -1, maxCostPos = -1;
    for(int i = 0; i < st; ++i)
    {
        int currentMinCost = -1;
        for(int j = 0; j < av; ++j)
        {
            //actualmente en el restaurante calle i, avenida, j
            int cost;
            cin >> cost;
            if(currentMinCost == -1) currentMinCost = cost;
            else currentMinCost = min(currentMinCost, cost);
        }
        //minCost.push_back(currentMinCost);

        if(currentMinCost > maxCost)
        {
            maxCost = currentMinCost;
        }
    }
    cout << maxCost << endl;
}