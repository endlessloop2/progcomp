#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int main()
{
    int n;
    cin >> n;

    queue<int> q;
    vector<int> output;
    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        q.push(tmp);
    }

    bool firstNum = true;
    int currentlyChecking; //cual se esta checkeando ahora
    while(!q.empty())
    {
        if(firstNum)
        {
            currentlyChecking = q.front();
            output.push_back(currentlyChecking);
            q.pop();
            firstNum = false;
        } 
        else
        {
            if(q.front() > currentlyChecking)
            {
                currentlyChecking = q.front();
                output.push_back(currentlyChecking);
            }
            q.pop();    
        }
        
        //++i;
    }

    cout << output.size() << endl;
    for(int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }
    cout << endl;

}