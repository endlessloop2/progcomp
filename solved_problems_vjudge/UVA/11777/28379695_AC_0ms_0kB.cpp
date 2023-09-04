#include <bits/stdc++.h>

using namespace std;

char gradeCalc(int a)
{
    //ESTO NO VA A FUNCIONAR PARA NROS PEQUEÑOS
    //fix
    /*if(a >= 10) a /= 10;
    else a = -1;*/
    if(a == 100) return 'A';
    (a >= 10) ? a /= 10 : a = -1;
    switch(a)
    {
        case 9:
        return 'A';
        break;

        case 8:
        return 'B';
        break;

        case 7:
        return 'C';
        break;

        case 6:
        return 'D';
        break;

        default:
        return 'F';
        break;
    }
}

int main()
{
    int T = 0;
    cin >> T;

    for(int i = 0; i < T; ++i)
    {
        int grade = 0;
        int ct[3];
        int avgct = 0;
        //T1 T2 F At CT1 CT2 CT3
        for(int j = 0; j < 4; ++j)
        {
            int tmp;
            cin >> tmp;
            grade += tmp;
        }

        for(int j = 0; j < 3; ++j)
        {
            //ESTA WEA NO FUNCA
            int tmp;
            cin >> tmp;
            ct[j] = tmp;            
            avgct += ct[j];
            //innecesario tanto
            /*if(j > 0)
            {
                avgct += max(ct[j-1], ct[j]);
            }*/
        }
        avgct -= min(ct[0], min(ct[1], ct[2]));
        avgct /= 2;
        grade += avgct;
        cout << "Case " << i+1 << ": " << gradeCalc(grade) << endl;
    }
}