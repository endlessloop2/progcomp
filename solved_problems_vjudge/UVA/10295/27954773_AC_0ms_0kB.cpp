#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m, n; //M: palabras en el diccionario; N: nro de descripciones de trabajo terminadas con .
    cin >> m >> n;

    map<string, int> skills;
    for(int i = 0; i < m; ++i)
    {
        string sk;
        int points;
        cin >> sk >> points;
        skills[sk] = points;
    }

    cin.clear();
    for(int i = 0; i < n; ++i)
    {
        //for each job
        int pointsRequired = 0;
        //if it matches any of the words. pr
        string word;
        cin >> word;
        while(word[0] != '.')
        {
            //loop through, if it matches, pointsRequired + word.second
            map<string, int>::iterator it;
            for(it = skills.begin(); it != skills.end(); ++it)
            {
                if(word == it->first)
                {
                    pointsRequired += it->second;
                }
            }
            cin >> word;
        }
        cout << pointsRequired << endl;
    }
    //round 4 decimal
}