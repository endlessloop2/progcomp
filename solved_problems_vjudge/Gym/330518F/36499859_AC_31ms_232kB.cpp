#include <bits/stdc++.h>

using namespace std;

int main() 
{
    queue<int> co;
    stack<int> pi;

    int n;
    cin >> n;
    //leer n datos
    while(n--)
    {
        int num;
        cin >> num;
        co.push(num);
        pi.push(num);      
    }

    cout << "PILA: ";

    while(!pi.empty())
    {
        cout << pi.top() << " ";
        pi.pop();
    }
    cout << endl;

    cout << "COLA: ";
    while(!co.empty())
    {
        cout << co.front() << " ";
        co.pop();
    }
    cout << endl;

    return 0;
}