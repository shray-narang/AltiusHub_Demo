#include <array>
using namespace std;

int max(vector<int> &arr) {
  // solved using kadane's algorithm
  // intializing two variables inorder to store current maximums and over all
  // maximum
  int currentSum = 0;
  int maxSum = INT_MIN;

  // add the current iterated value to the current sum and see if it the current
  // sum increases with the new addition of the new value itself is bigger than
  // the current sum. Update the maximum sum accordingly to see if the newly
  // built current sum is greater than the previously found maximum sum follows
  // through in O(n) time completxity.

  for (int i = 0; i < arr.size(); i++) {
    currentSum = max(arr[i], arr[i] + currentSum);
    maxSum = max(currentSum, maxSum);
  }

  return maxSum;
}

// helper function to reverse array of integer without rewriting code
void reverse(vector<int> &arr, int start, int end) {
  while (start < end) {
    swap(arr[start], arr[end]);
    start++;
    end--;
  }
}
// return type is void since the function uses the inplace method
void rotate(vector<int> &arr, int k) {
  int s = arr.size();
  k = k % s;
  // rotating by the updated value of k positions which accounts for value of
  // k's larger than size of array 1,2,3,4,5,6,7,8: 3 steps needed: reverse
  // array completely - 8,7,6,5,4,3,2,1 reverse first k elements -
  // 6,7,8,5,4,3,2,1 reverse remaning elements - 6,7,8,1,2,3,4,5
  reverse(arr, 0, s - 1);
  reverse(arr, 0, k - 1);
  reverse(arr, k, s - 1);
}