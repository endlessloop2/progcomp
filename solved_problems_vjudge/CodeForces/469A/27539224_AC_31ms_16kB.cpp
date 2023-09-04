#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int lvl_count;
    cin >> lvl_count;
    vector<int> passedLvls;
    bool passed = true;
    
    
    for(int i = 0; i < 2; i++)
    {
        int p;
        cin >> p;
        
        for(int j = 0; j < p; j++)
        {
            int a;
            cin >> a;
            passedLvls.push_back(a);
        } 
    }
    // LOOP THROUGH FIRST ARRAY AND
    int passedLvlsCount;
    for(int i = 0; i < lvl_count; i++) //for each level
    {
        bool lvlPassed = false;
        for(int j = 0; j < passedLvls.size(); j++)// loop through passedLvls
        {
            if((i+1) == passedLvls[j])
            {
                lvlPassed = true;
                break;
            }
        }
        if(!lvlPassed)
        {
            passed = false;
            break;
        }
    }

    if(passed)
    {
        cout << "I become the guy.";
    }
    else
    {
        cout << "Oh, my keyboard!";
    }
}