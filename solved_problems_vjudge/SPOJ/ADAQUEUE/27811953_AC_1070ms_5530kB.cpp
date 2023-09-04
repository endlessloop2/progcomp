#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool processCommand(string cmd, vector<string> args, deque<int> &queue, bool &reverse);
bool backf(deque<int> &queue, bool reverse);
bool frontf(deque<int> &queue, bool reverse);
bool reversef(deque<int> &queue, bool &reverse);
bool push_backf(deque<int> &queue, bool reverse, int num);
bool toFrontf(deque<int> &queue, bool reverse, int num);

int main()
{
    int q;//num of queries
    deque<int> queue;
    cin >> q;
    cin.ignore(); //clear buffer so getline() works
    bool reverseFlag = false;
    for(int i = 0; i < q; ++i)
    {
        string s;
        getline(cin, s);
        string delim = " ";

        string cmd = s.substr(0, s.find(delim));
        s.erase(0, s.find(delim) + delim.length());
        vector<string> args;

        size_t pos = 0;
        while ((pos = s.find(delim)) != std::string::npos) //stack overflow
        {
            args.push_back( s.substr(0, pos) );
            s.erase(0, pos + delim.length());
        }
        args.push_back(s);
        bool execute = processCommand(cmd, args, queue, reverseFlag);
    }
}

bool processCommand(string cmd, vector<string> args, deque<int> &queue, bool &reverse)
{
    int argslen = args.size(); 

    if(cmd == "back")
    {
        return backf(queue, reverse);
    }
    else if (cmd == "front")
    {
        return frontf(queue, reverse);
    }
    else if (cmd == "reverse")
    {
        return reversef(queue, reverse);
    }
    else if (cmd == "push_back" && argslen == 1)
    {
        return push_backf(queue, reverse, stoi(args[0]));
    }
    else if (cmd == "toFront" && argslen == 1)
    {
        return toFrontf(queue, reverse, stoi(args[0]));
    }
    
    return false;
}

bool backf(deque<int> &queue, bool reverse)
{
    if(!queue.empty())
    {
        if(!reverse)
        {
            cout << queue.back() << endl;
            queue.pop_back();
        }
        else
        {
            cout << queue.front() << endl;
            queue.pop_front();    
        }
        return true;
    }
    cout << "No job for Ada?" << endl;
    return false;
}

bool frontf(deque<int> &queue, bool reverse)
{
    if(!queue.empty())
    {
        if(!reverse)
        {
            cout << queue.front() << endl;
            queue.pop_front();
        }
        else
        {
            cout << queue.back() << endl;
            queue.pop_back();   
        }
        return true;
    }
    cout << "No job for Ada?" << endl;
    return false;
}

bool reversef(deque<int> &queue, bool &reverse)
{
    //checkear si se modifica
    //se puede reversear si la cola esta vacia?
    if(!queue.empty())
    {
        if(!reverse) reverse = true;
        else reverse = false;
    }
    
    return true;
}

bool push_backf(deque<int> &queue, bool reverse, int num)
{
    if(!reverse) queue.push_back(num);
    else queue.push_front(num);
    
    return true;
}

bool toFrontf(deque<int> &queue, bool reverse, int num)
{
    if(!reverse) queue.push_front(num);
    else queue.push_back(num);

    return true;
}