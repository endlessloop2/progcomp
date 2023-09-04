#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;//number to be checked
    cin >> n;
    int digits = to_string(n).length();
    //lucky number, formed by 4 and or 7.
    //if number only contains 4s and 7s, inmeditaly yes
    //else, check manually. if n has 3 digits, start at 777, then 774, etc..
    int n2 = n;
    bool completeLucky = true;
    while(n2 != 0)
    {
        if(! (n2 % 10 == 4 || n2 % 10 == 7) )
        //invertida condicion, si uno de los dos es true, lo contrario
        //si no es 4 ni 7
        {
            completeLucky = false;
            break;
        }
        n2 /= 10;
    }

    if(completeLucky)
    {
        cout << "YES" << endl;
        return 0;
    }

    //PURO HARDCODE :(
    //if else nomas, se deberia usar switch
    int divisor1 = 777;
    int divisor2 = 444;
    bool isLucky = false;
    if(3-digits != 0)
    {
        divisor1 /= 10*(3-digits);
        divisor2 /= 10*(3-digits);
    }

    // FALTAN LAS COMBINACIONES 774, 747, 774, 744, 447, 474, 477,
    if(digits != 1)
    {
        //opcion alternativa, partir de 777 irlo disminuyendo. y lo mismo con 444
        for(int i = 0; i < digits; ++i)
        {
            //por cada digito de divisor
            if(n % divisor1 == 0 || n % divisor2 == 0)
            {
                isLucky = true;
                break;
            }

            divisor1 /= 10;
            divisor2 /= 10;
        }

        //literalmente hardcodeado, no se que me pasa
        if(n % 774 == 0 || n % 747 == 0 || n % 744 == 0 || n % 447 == 0 || n % 474 == 0 || n % 477 == 0 || n % 47 == 0 || n % 74 == 0)
        {
            isLucky = true;
        }
    }
    else
    {
        if(n % 7 == 0 || n % 4 == 0) isLucky = true;
    }
    
    /*if(isLucky)
    {
        cout << "YES" << endl;
    }
    else*/
    string printa = isLucky ? "YES" : "NO";
    cout << printa << endl;
}