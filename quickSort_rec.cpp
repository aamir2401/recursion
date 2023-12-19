#include <iostream>
#include <string>
#include <vector>
using namespace std;
int partitionLogic(vector<int> &nums, int s, int e)
{
    // choose a pivot index ;
    int pivotIndex = s;
    // choose a pivot elemnet;
    int pivotElement = nums[s];
    // count number of elements persent in nums which are smaller than pivot element;
    int count = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (nums[i] <= nums[pivotIndex])
        {
            count++;
        }
    }
    // we have got the right index for pivot element as count+s;
    int rightIndexForPivotElemnet = s + count;
    swap(nums[pivotIndex], nums[rightIndexForPivotElemnet]);
    pivotIndex = rightIndexForPivotElemnet;
    // now check whether all element in the left of pivotElement is smaller then pivot element or not or vice versa for right of the pivotElemnet;
    int i = s;
    int j = e;
    while (i <= pivotIndex and j >= pivotIndex)
    {
        while (nums[i] < nums[pivotIndex])
        {
            i++;
        }
        while (nums[j] > nums[pivotIndex])
        {
            j--;
        }
        // here two cases can be happen like loop for i/j will break if if nums[i]> nums[pivotindex] || nums[pivotIndex] > nums[j];
        // if above mentioned condition is triggered then below swap function will be invoked;
        swap(nums[i], nums[j]);
    }

    return pivotIndex;
}
void quickSort(vector<int> &nums, int s, int e)
{
    if (s >= e)
    {
        return;
    }

    // partition logic;
    int a = partitionLogic(nums, s, e);

    // recursive calls for left and right part of array;
    // call for left part ;
    quickSort(nums, s, a - 1);

    // call for right part;
    quickSort(nums, a + 1, e);
}
int main()
{
    vector<int> nums = {6, 1, 20, 30, 8, 5, 60, 5};
    int n = 8;
    int s = 0;
    int end = n - 1;
    cout<<"Printing before quick sort called :" <<endl;
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    quickSort(nums, s, end);
    cout<<" wwww"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}