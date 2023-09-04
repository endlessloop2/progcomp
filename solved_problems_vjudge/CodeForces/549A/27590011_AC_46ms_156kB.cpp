#include <iostream>
#include <vector>

using namespace std;

int findFaces(vector <vector <char>>);
int getLetter(char l);

int main()
{
    int n, m; //altura y largo imagen respectivamente
    cin >> n >> m;
    
    vector <vector<char>> v; //x,y. En este caso la x seria la altura e y la 
    v.resize(n);
    for(int i = 0; i < n; i++)// por cada linea (altura), x
    {
        for(int j = 0; j < m; j++)
        {
            char tmp;
            cin >> tmp;
            v[i].push_back(tmp);
        }
    }

    cout << findFaces(v);

}

int findFaces(vector <vector <char>> v)
{
    int foundFaces = 0;
    for(int i = 0; i < v.size(); i++)// por cada linea (altura), x
    {
        for(int j = 0; j < v[i].size(); j++)
        {
            //SISTEMA Y X
            //por cada letra, escanear 4 (muy ineficiente)
            char current = v[i][j];
            char next = NULL;//siguiente hacia la derecha
            char below = NULL;
            char belowNext = NULL;

            // CUIDADO
            if(j + 1 < v[i].size())
            {
                next = v[i][j+1];//siguiente hacia la derecha
            }
            if(i + 1 < v.size())
            {
                below = v[i+1][j];
            }
            if(j + 1 < v[i].size() && i + 1 < v.size())
            {
                belowNext = v[i+1][j+1];
            }
            bool found [4] {false, false, false, false}; // 0 = f, 1 = a, 2 = c, 3 = e
            /*if(current != 'f' || current != 'a' || current != 'c' || current != 'e')
            {
                
            }*/
            if(current == 'f' || current == 'a' || current == 'c' || current == 'e')
            {
                found[getLetter(current)] = true;
            }
            if(next != NULL && (next == 'f' || next == 'a' || next == 'c' || next == 'e'))
            {
                found[getLetter(next)] = true;
            }
            if(below != NULL && (below == 'f' || below == 'a' || below == 'c' || below == 'e'))
            {
                found[getLetter(below)] = true;
            }
            if(belowNext != NULL && (belowNext == 'f' || belowNext == 'a' || belowNext == 'c' || belowNext == 'e'))
            {
                found[getLetter(belowNext)] = true;
            }

            bool foundStatus = true;
            for(int p = 0; p < 4; p++)
            {
                if(!found[p])
                {
                    foundStatus = false;
                    break;
                }
            }
            if(foundStatus)
            {
                ++foundFaces;
            }
        }
    }
    return foundFaces;
}

int getLetter(char l)
{
    switch (l) 
    { 
        case 'f':  
            return 0; 
            break; 
        case 'a':  
            return 1;  
            break; 
        case 'c':  
            return 2; 
            break;
        case 'e':  
            return 3; 
            break;  
        default:  
            return -1; 
            break;   
    } 
}