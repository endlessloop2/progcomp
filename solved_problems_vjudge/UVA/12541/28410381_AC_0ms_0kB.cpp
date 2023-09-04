#include <bits/stdc++.h>

using namespace std;

int main()
{
    //SOLUCION CON SET Y COMPARADOR CUSTOM
    //se ordena de menor edad a mayor edad
    struct Comparador
    {
        bool operator() (const pair<string, vector<int>> &a, const pair<string, vector<int>> &b) /*const*/
        {
            //retornar true si a va antes que b
            if(a.second[2] == b.second[2])
            {
                //si los años son iguales, ver los meses
                if(a.second[1] == b.second[1])
                {
                    return a.second[0] > b.second[0]; 
                }
                return a.second[1] > b.second[1]; 
            }
            return a.second[2] > b.second[2];//quizas no es necesario definir esto, el multiset ya checkea
        }
    };
    int n;
    set<pair<string, vector<int>>,Comparador> set;
    cin >> n;
    while(1 + --n)
    {
        string n;
        //int d, m, y;
        vector<int> a(3);
        cin >> n >> a[0] >> a[1] >> a[2];
        set.insert( make_pair(n,a) );
        
    }
    cout << set.begin()->first << endl;//maximo, younger
    cout << set.rbegin()->first << endl;//minimo, oldest
}