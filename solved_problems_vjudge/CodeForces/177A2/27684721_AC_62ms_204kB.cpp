#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int n; //size of the matrix
    vector<vector<int>> v;
    cin >> n;
    v.resize(n);
    int sum = 0;
    
    if(n == 3)
    {
        for(int i = 0; i < n*n; i++)
        {
            int tmp;
            cin >> tmp;
            sum += tmp;
        }
    }
    else if(n == 1)
    {
        int tmp;
        cin >> tmp;
        sum = tmp;
        //cout << 0 << endl; //seria 0 o el numero?
    }
    else
    {
        //store data
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int tmp;
                cin >> tmp;
                v[i].push_back(tmp);
            }
        }


        //process data
        int diag1 = 1;
        int diag2 = n;//X
        int diag2abajo = 1;//Y
        // I = row, J = col Y, X
        /*int center = 0;
        int middleRow = 0;
        int middleCol = 0;
        int diagonal = 0;
        int diagonal2 = 0;*/

        for(int i = 0; i < n; i++)// row
        {
            for(int j = 0; j < n; j++) // col
            {
                int y = i+1;
                int x = j+1;

                if( y == (n/2 + 1) && x == (n/2 + 1) )//if center
                {// solo se ejecuta cuando en el centro, antes no
                    sum += v[i][j];
                    //center += v[i][j];

                    ++diag1;
                    --diag2;
                    ++diag2abajo; 
                }
                else if( y == (n/2 + 1) )//middle row
                {
                    sum += v[i][j];
                    //middleRow += v[i][j];
                }
                else if( x == (n/2 + 1) )//middle col
                {
                    sum += v[i][j];
                    //middleCol += v[i][j];
                }
                else if(x == diag1 && y == diag1) //diagonal primera
                {
                    sum += v[i][j];
                    //diagonal += v[i][j];
                    ++diag1;
                }
                else if(x == diag2 && y == diag2abajo) //diagonal segunda
                {
                    sum += v[i][j];
                    //diagonal2 += v[i][j];
                    --diag2;
                    ++diag2abajo; 
                }


            }
        }
        /*cout << "centro: " << center << endl;
        cout << "fila del medio: " << middleRow << endl;
        cout << "columna del medio: " << middleCol << endl;
        cout << "diagonal 1: " << diagonal << endl;
        cout << "diagonal 2: " << diagonal2 << endl; */
    }

    cout << sum << endl;


}