#include <bits/stdc++.h>
using namespace std;
// SI 
int main() {
  
    int n, m; // N: CDs de jack, M: cds de Jill
    cin >> n >> m;
    
    while(n != 0 && m != 0)//loop casos
    {
        int counter = 0;
        set<unsigned int> ja; //cds de jack
        set<unsigned int> repetidos;
        //set<int> ji; //cds de jill
        //insertar
    
    for(int i = 0; i < n; ++i) //insertar los de jack
    {
        int tmp;
        cin >> tmp;
        ja.insert(tmp);
    }

    for(int i = 0; i < m; ++i) //insertar los de jill
    {
        int tmp;
        cin >> tmp;
        //ji.insert(tmp);
        if(!ja.insert(tmp).second)
        {
            // Se repite con jack
            if(repetidos.insert(tmp).second)
            {
            // No lo hemos contado
            counter++;
            }
	    }

    }
    
    //ciclo del 1 al n, encontrar repetidos, aumentar contador
        cout << counter << endl;
        cin >> n >> m;
    }
  
    return 0;
}
