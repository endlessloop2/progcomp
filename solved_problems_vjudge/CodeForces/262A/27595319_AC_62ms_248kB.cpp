#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//int countLuckyNums(int i);
int main()
{
    int n,k; // hay n numeros, los numeros no deben tener mas de k digitos de suerte (4 y 7)
    cin >> n >> k;
    vector <int> v; //store data 
    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    int howMany = 0;// how many integers NOT have more than k lucky digits
    for(int i = 0; i < v.size(); i++)//for each number
    {
        int luckyDigitCount = 0;//contador de numeros de suerte de cada numero
        while(v[i] != 0)// for each digit
        {
            if( (v[i] % 10) == 4 || (v[i] % 10) == 7)
            {
                luckyDigitCount++;
            }
            if(luckyDigitCount > k)
            {
                break;
            }
            v[i] /= 10;
        }
        if(luckyDigitCount <= k)
        {
            howMany++;
        }
    }    
    cout << howMany;
}