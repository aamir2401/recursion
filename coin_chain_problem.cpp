#include <iostream>
#include<limits.h>
#include<vector>
using namespace std;
int getCoinChain(vector<int>& arr, int target)
{
    int n=arr.size();
    if(target == 0)
    {
       return 0;
    }
    if(target < 0)
    {
      return INT_MAX;   
    }
    int minimum = INT_MAX;
    for(int i=0; i<n; i++)
    {
        int ans = getCoinChain(arr, target-arr[i]);
        
        if(ans != INT_MAX)
        {
            minimum = min(minimum,ans+1);
           
        }
    }
    return minimum;
}
int main()
{
    int i=0;
    int target = 5;
    vector<int> v{1,2,3};
    int ans = getCoinChain(v, target);
    cout<<"we have some ans: "<<ans;
    return 0;
}