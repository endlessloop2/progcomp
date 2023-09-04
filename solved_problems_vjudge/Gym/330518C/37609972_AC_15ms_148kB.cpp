#include <bits/stdc++.h>
using namespace std; 
int main() 
{
    int n1, e1, n2, e2;
    // nodos y aristas ciudad 1
    cin >> n1 >> e1;
    //matriz de adyacencia ciudad 1, tamaño [n1][n1], llena de 0
    vector<vector<bool>> adj_matrix(n1, vector<bool>(n1, 0));
    for(int i = 0; i < e1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_matrix[a][b] = 1;
    }

    cin >> n2 >> e2;
    //matriz de adyacencia ciudad 2, tamaño [n2][n2], llena de 0
    vector<vector<bool>> adj_matrix2(n2, vector<bool>(n2, 0));    
    for(int i = 0; i < e2; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_matrix2[a][b] = 1;
    }

    // pendiente, verificar si son iguales, comparar matrices.
    if(n1 != n2)
    {
        cout << "No son iguales" << endl;
        return 0;
    }
    
    for(int i = 0; i < n1; i++)
    {
        for(int j = 0; j < n1; j++)
        {
            //comparar matriz 1 y matriz 2
            if(adj_matrix[i][j] != adj_matrix2[i][j])
            {
                cout << "No son iguales" << endl;
                return 0;
            }
        }
    }
    
    cout << "Son iguales" << endl;

    // cout << endl;
    // for(int i = 0; i < n1; i++)
    // {
    //     for(int j = 0; j < n1; j++)
    //     {
    //         cout << adj_matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // cout << endl;
    // for(int i = 0; i < n1; i++)
    // {
    //     for(int j = 0; j < n1; j++)
    //     {
    //         cout << adj_matrix2[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}