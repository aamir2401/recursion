#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void addUsingRecursion(string &num1, string &num2, int i, int j, string &ans, int carry)
{
    if (i < 0 && j < 0)
    {
        if (carry != 0)
        {
            ans.push_back(carry + '0');
        }
        return;
    }
    int n1 = (i >= 0 ? num1[i] - '0' : 0);
    int n2 = (j >= 0 ? num2[j] - '0' : 0);
    int cSum = n1 + n2 + carry;
    int digit = cSum % 10;
    carry = cSum / 10;
    ans.push_back(digit + '0');
    addUsingRecursion(num1, num2, i - 1, j - 1, ans, carry);
}
int main()
{
    string num1 = "6887";
    string num2 = "3";
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    string ans = "";
    int carry = 0;
    cout << "Before addding the ans string is: " << ans << endl;
    addUsingRecursion(num1, num2, i, j, ans, carry);
    reverse(ans.begin(), ans.end());
    cout << "After addding the ans string is: " << ans << endl;

    return 0;
}

// #include <iostream>
// #include <string>
// #include<algorithm>
// using namespace std;

// void addUsingRecursion(string &num1, string &num2, int i, int j, string &ans, int carry) {
//     if (i < 0 && j < 0) {
//         if (carry != 0) {
//             ans.push_back(carry + '0');
//         }
//         return;
//     }
//     int n1 = (i >= 0 ? num1[i] - '0' : 0);
//     int n2 = (j >= 0 ? num2[j] - '0' : 0);
//     int cSum = n1 + n2 + carry; // Fix the calculation here
//     int digit = cSum % 10;
//     carry = cSum / 10;
//     ans.push_back(digit + '0');
//     addUsingRecursion(num1, num2, i - 1, j - 1, ans, carry);
// }

// int main() {
//     string num1 = "123";
//     string num2 = "3";
//     int i = num1.size() - 1;
//     int j = num2.size() - 1;
//     string ans = "";
//     int carry = 0;
//     cout << "Before adding, the ans string is: " << ans << endl;
//     addUsingRecursion(num1, num2, i, j, ans, carry);
//     reverse(ans.begin(), ans.end());
//     cout << "After adding, the ans string is: " << ans << endl;

//     return 0;
// }
