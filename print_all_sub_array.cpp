// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;
// void printSubArray(vector<int> &nums, int start, int end)
// {
//     // base case;
//     if (end == nums.size())
//     {
//         return;
//     }

//     for (int i = start; i <= end; i++)
//     {
//         cout << nums[i] << " ";
//     }
//     cout << endl;
//     printSubArray(nums, start, end + 1);
// }
// void printerUtil(vector<int> &nums)
// {
//     for (int start = 0; start < nums.size(); start++)
//     {
//         int end = start;
//         printSubArray(nums, start, end);
//     }
//     cout << endl;
// }
// int main()
// {
//     vector<int> nums{1, 2, 3, 4, 5};
//     printerUtil(nums);

//     return 0;
// }

#include <iostream>
#include <string>
#include <vector>
using namespace std;
void printingArray_util(vector<int> &nums, int start, int end)
{
    // base case;
    if (end == nums.size())
    {
        return;
    }

    for (int i = start; i <= end; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    printingArray_util(nums, start, end + 1);
}
void print_sub(vector<int> &nums)
{
    for (int start = 0; start < nums.size(); start++)
    {
        int end = start;
        printingArray_util(nums, start, end);
    }
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    print_sub(nums);

    return 0;
}