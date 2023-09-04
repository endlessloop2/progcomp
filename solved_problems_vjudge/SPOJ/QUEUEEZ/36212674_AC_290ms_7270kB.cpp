#include <bits/stdc++.h>

using namespace std;

int main(){
   
    ios_base::sync_with_stdio (false);
    cin.tie(NULL);
    cout.setf(ios::fixed);

    int t;
    cin >> t;
    
    queue <int> Num;

    for(int i = 0; i < t; i++)
    {
        int instruccion;
        cin >> instruccion;
        if(instruccion == 1)
        {
            int numero;
            cin >> numero;
            Num.push(numero);
            
        }
        if(instruccion == 2)
        {
            if (!Num.empty()){
                Num.pop();               
            }
        }
        if(instruccion == 3)
        {
            if (Num.empty())
            {
                cout << "Empty!" << "\n"; 
            }
            else
            {
                cout << Num.front() << "\n";   
            }
        }
    }
    //
    return 0;
}