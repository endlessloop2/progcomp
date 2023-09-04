#include <iostream>

using namespace std;
int main()
{
    int s[4];//4 shoes
    cin >> s[0] >> s[1] >> s[2] >> s[3];

    int howMany = 0;// how many need to be replaced?
    int equalShoes = 0;//how many shoes have the same color?
    int colors = 0; //how many different colors have been found?
    
    for(int i = 0; i < 4; i++)
    {
        bool found = false;
        for(int j = 0; j < 4; j++)// empezar a leer desde i
        {
            if(i == j)//no comparar la misma shoe con si misma
            {
                //equalShoes++; && S[i] = 0
                continue;
            }
            if( (s[i] == s[j]) && s[j] != 0)
            {
                //s[i] = 0;
                s[j] = 0;
                if(!found)
                {
                    ++colors;
                    ++equalShoes;
                    found = true;
                }
                ++equalShoes;
            }
        }

    }

    if(equalShoes == 2)
    {
        howMany = 1;
    }
    else if(equalShoes == 3)
    {
        howMany = 2;
    }
    else if(equalShoes == 4)
    {
        if(colors == 1)
        {
            howMany = 3;
        }
        else
        {
            howMany = 2;
        }
        
    }

    cout << howMany << endl;
}