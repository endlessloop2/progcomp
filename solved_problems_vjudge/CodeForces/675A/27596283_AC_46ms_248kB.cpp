#include <iostream>

using namespace std;
int main()
{
    int a,b,c; // A: el primer elemento de la secuencia // B: el nro favorito // C: la diferencia entre cada numero de la secuencia es de C
    //suponiendo que el primer elemento es de una secuencia que aumenta
    cin >> a >> b >> c;

    int nextinSequence = a+c;
    //mejor ver si B es multiplo de a+c

    /*while(tmp != b)
    {

    }*/
    if(a == b)
    {
       cout << "YES" << endl; 
    }
    else if (c == 0)
    {
        if(a == b)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    else if(c < 0 && b > a)//si la diferencia es negativa y el nro favorito es superior al primer elemnto 
    {
        cout << "NO" << endl;
    }
    else if(c > 0 && b < a)//si la diferencia es positiva y el nro favorito es inferior al primer elemnto 
    {
        cout << "NO" << endl;
    }
    else if((b-a) % c == 0)// si b es multiplo de a+c
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    
    
}