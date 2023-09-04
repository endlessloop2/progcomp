#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b; //numerador, denominador
    cin >> a >> b;

    int mixta, numerador;
    while(a != 0 && b != 0)
    {
        //pasar fracciones inexactas a mixtas >> 5/4 >> 1 1/4
        // x y/z 
        //ver cuantas veces cabe el den en el num, aumentar asi el x
        // lo que no quepa, ponerlo en y e mantener el z
        //mantener el den
        mixta = (int)a/b;
        numerador = a-(mixta*b);

        cout << mixta << " " << numerador << " / " << b << endl;
        cin >> a >> b; 
    }


}