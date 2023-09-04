#include <iostream>
#include <math.h>
#include <vector>
//#include <set>
#include <algorithm>

using namespace std;

int main()
{
    int n;
//SET??
    //vector<bool> isJolly;
    while(cin >> n)
    {
        vector<int> v;//vector de cada caso
        //set<int> s; // set para ordenar diferencias
        vector<int> dif;//vector de diferencias
        bool isJollyl = true;
        for(int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            v.push_back(tmp);
        }

        int prevValue;
        //int prevValue = 0;
        for(int i = 0; i < n; i++)
        {
            int currentValue;
            currentValue = v[i];
            if(i > 0)
            {
                dif.push_back( abs(prevValue - currentValue) );
            }
            prevValue = currentValue;
        }

        sort(dif.begin(), dif.end());
        prevValue = 0;
        for(int i = 0; i < dif.size(); ++i)
        {
            int currentValue = dif[i];
            if(i != 0)
            {
                if(prevValue+1 != currentValue)
                {
                    isJollyl = false;
                    break;
                }
            }
            else
            {
                if(currentValue != 1)
                {
                    isJollyl = false;
                    break;                    
                }
            }
            
            prevValue = currentValue;
        }




        //int test = sum(n-1);
        //cout << test << endl;
        if(/*n == 1 ||*/ isJollyl)
        {
            //isJolly.push_back(true);
            cout << "Jolly" << endl;
        }
        else
        {
            //isJolly.push_back(false);
            cout << "Not jolly" << endl;
        }



    }

    /*for(int i = 0; i < isJolly.size(); ++i)
    {
        if(isJolly[i])
        {
            cout << "Jolly" << endl;
        }
        else
        {
            cout << "Not Jolly" << endl;
        }
        
    }*/
}