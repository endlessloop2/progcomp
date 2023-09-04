#include <iostream>

using namespace std;
int main()
{
    bool isEasy = true;
    int n; //number of people
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int tmp;//each person
        cin >> tmp;
        if(tmp == 1)
        {
            isEasy = false;
            break;    
        }
    }
    if(isEasy)
    {
        cout << "EASY";
    }
    else
    {
        cout << "HARD";
    }
}