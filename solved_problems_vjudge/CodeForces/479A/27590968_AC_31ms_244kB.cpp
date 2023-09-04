#include <iostream>
#include <algorithm>
using namespace std;

//int findMax(int n[]); 
int main()
{
    //*max_element(array , array + n)
    int nums[3];
    int tmp[5];
    cin >> nums[0] >> nums[1] >> nums[2];

    tmp[0] = nums[0] + nums[1] * nums[2];
    tmp[1] = nums[0] * (nums[1] + nums[2]);
    tmp[2] = nums[0] * nums[1] * nums[2];
    tmp[3] = (nums[0] + nums[1]) * nums[2];
    tmp[4] = nums[0] + nums[1] + nums[2];
    int * t;
    t = max_element(tmp, tmp + 5);
    cout << int(*t);
}