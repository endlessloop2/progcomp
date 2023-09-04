#include <bits/stdc++.h>

using namespace std;

int main()
{
    //POSIBLE PROBLEMA TRAMPA (SIMPLE)
    int n; //
    cin >> n;

    string out;
    if(n == 1) out = "Alice";
    else
    {
        if(n % 2 == 0)//even
        {
            out = "Bob";//queda 0, even
        }
        else
        {
            out = "Alice"; // queda 1, odd
        }
        
    }
    

    cout << out << endl;
}