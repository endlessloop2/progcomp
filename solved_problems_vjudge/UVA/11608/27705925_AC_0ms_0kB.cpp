#include <bits/stdc++.h>

using namespace std;

int main()
{
    int s; // S: num of problems that is ready at the beginning of the year
    cin >> s;

    int n = 1;//cantidad de casos para Case X
    vector <vector <int>> v;// [mes][ 0: problems created in that month, 1: problems required in that month] 
    while(s >= 0) // for each case  s != 1
    {
        v.resize(12);
        //reimplementar con otra struct
        //vector <vector <int>> v(12);// [mes][ 0: problems created in that month, 1: problems required in that month] 
        for(int i = 0; i < 12; i++)//read 2nd line
        {
            int tmp;
            cin >> tmp;
            v[i].push_back(tmp);
        }

        for(int i = 0; i < 12; i++)//read 3rd line
        {
            int tmp;
            cin >> tmp;
            v[i].push_back(tmp);
        }

        cout << "Case " << n << ":" << endl;
        int created = s;// (los creados son los de los meses anteriores + el del principio ) - los que se usaron 
        for(int i = 0; i < 12; i++)//process
        {
            int required = v[i][1]; //required
            if(i == 0)
            {
                if(s >= required) //si hay suficientes creados
                {
                    cout << "No problem! :D" << endl;
                    created -= required;// elimina los usados
                }
                else
                {
                    cout << "No problem. :(" << endl;
                }
            }
            else
            {
                if(created >= required) //si hay suficientes creados
                {
                    cout << "No problem! :D" << endl;
                    created -= required;// elimina los usados
                }
                else
                {
                    cout << "No problem. :(" << endl;
                }
            }
            //ELIMINAR SOLO SI SE USARON
            //created -= required;// elimina los usados
            created += v[i][0];//añadir los creados en este mes        
        }

    cin >> s;
    ++n;
    v.clear();//deletes everything
    }//end case 

    //when s == 0, next case
}