#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;

    while(cin >> n)
    {
        //mt
        //leer n ints
        vector<int> v;
        while(n--)//precio de cada libro
        {
            int tmp;
            cin >> tmp;
            v.push_back(tmp);
        }
        sort(v.begin(), v.end());

        cin >> m;//dinero que tiene peter
        //restarle cada uno al dinero, despues buscar el otro
        //cada uno que sea menor
        int mindif = -1;//minima diferencia
        pair<int,int> minp;
        for(int i = 0; i < v.size(); ++i)
        {
            int busca = m-v[i];
            if(binary_search(v.begin(), v.end(), busca))
            {
                if(mindif == -1) 
                {
                    mindif = busca;
                    minp = make_pair(v[i], busca);
                }
                else
                {
                    if(abs(v[i]-busca) < mindif)
                    { 
                        mindif = abs(v[i]-busca);
                        minp = make_pair(v[i], busca);
                    }
                }
                if(mindif == 0) break;
            }
        }
        cout << "Peter should buy books whose prices are " << min(minp.first, minp.second) << " and " << max(minp.first, minp.second) << "." << endl << endl;
        
    }
}