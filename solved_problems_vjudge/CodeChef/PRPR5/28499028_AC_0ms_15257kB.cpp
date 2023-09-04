#include <bits/stdc++.h>

using namespace std;

//declarar aqui para tener acceso
int N,S; //cantidad de compartimentos vacios, nro de shards

int F(int x, vector<int> &vec)
{
    int prev = vec[0];
    int shardplaced = 0;

    for(int i = 1; i < N; ++i)
    {
        if(vec[i]-prev >= x)
        {
            ++shardplaced;
            prev = vec[i];
            if(shardplaced == (S-1)) return 1;
        }
    }
    return 0;
}
int binary_s(vector<int> &v, int l, int r, int max = -1)
{
    int mid = (l+r)/2;
    
    if(l == r)//arreglando asinoms
    {
        if(F(mid, v))//se pudo colocar a mid distancia
        {
             if(mid > max) max = mid;
        }
        return max;  
    }
    if(l < r)//ya se reviso todo??//añadido = para arreglar bugs // eliminado despues
    {
        if(F(mid, v))//se pudo colocar a mid distancia
        {
            if(mid > max) max = mid;
            return binary_s(v, mid+1, r, max);
        }
        else return binary_s(v, l, mid-1, max);//ARREGLAR

    }

    return max;
}
int main()
{
    vector<int> vec;
    cin >> N >> S;
    int n2 = N;

    while(1+--n2)
    {
        //coordenadas de los compartimentos vacios
        int tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end());
    cout << binary_s(vec, 1, vec[vec.size()-1]-vec[0]) << endl;//vec[0] +1  o no?
}