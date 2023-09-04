#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int q; // consultas
    cin >> q;
    //crear map aqui nombre -> puntaje
    map <string, int> puntajes;
    for(int i = 0; i < q; i++)
    {
        //comandos
        int c;
        cin >> c;
        if(c == 1)
        {
            string estudiante;
            int puntaje;
            cin >> estudiante >> puntaje;

            if(puntajes.find(estudiante) != puntajes.end())
            {
               puntajes.find(estudiante)->second = puntajes.find(estudiante) -> second + puntaje;
            } 
            else
            {
                puntajes.insert(pair<string, int>(estudiante, puntaje));
            }
            //pair<string,int> (estudiante,puntaje)
            //AGREGA puntaje
            //leer nombre y puntaje
            //puntajes.insert (pair < >)
            //"nombre mapa".insert()
            //o
            // "nombre mapa"[nombre] = puntaje
        }
        if(c == 2)
        {
            string estudiante;
            cin >> estudiante;
            puntajes.erase(estudiante);
        }
        if(c == 3)
        {
            string estudiante;
            cin >> estudiante;
            if(puntajes.find(estudiante) != puntajes.end())
            {
                map<string, int>::iterator itr;
                itr = puntajes.find(estudiante);
                cout << itr->second << endl;               
            } 
            else
            {
                cout << "0" << endl;
            }
        }
    }
    return 0;
}
