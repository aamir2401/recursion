#include <iostream>
#include <vector>
using namespace std;

// Function to count ways to get the sum
int countWays(vector<int>& arr, int target_sum) {
    // Base case: if target_sum becomes 0, there's 1 way (no elements used)
    if (target_sum == 0) return 1;
    
    // If target_sum becomes negative, there's no way to achieve it
    if (target_sum < 0) return 0;
    
    // Initialize the number of ways to 0
    int total_ways = 0;
    
    // Try using each element in the array
    for (int i = 0; i < arr.size(); i++) {
        // Recur by reducing the target_sum by arr[i]
        total_ways += countWays(arr, target_sum - arr[i]);
    }
    
    return total_ways;
}

int main() {
    vector<int> arr = {1, 2, 3}; // The given vector of elements
    int target_sum = 4; // The target sum we want to achieve
    
    // Call the recursive function and print the result
    cout << "Number of ways to get sum " << target_sum << " is: "
         << countWays(arr, target_sum) << endl;

    return 0;
}
