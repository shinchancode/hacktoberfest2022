// Find the Duplicate Number

// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive. There is only one repeated number in nums, return this 
// repeated number. You must solve the problem without modifying the array nums and uses only constant extra space.

// Example 1:
// Input: nums = [1,3,4,2,2]
// Output: 2
  
// Constraints:
// 1 <= n <= 105
// nums.length == n + 1
// 1 <= nums[i] <= n
// All the integers in nums appear only once except for precisely one integer which appears two or more times.

int findDuplicate(vector<int>& nums) {
    int n=nums.size();

    for(int i=0;i<n;i++){
        if(nums[abs(nums[i])]>=0)
            nums[abs(nums[i])]=-nums[abs(nums[i])];
        else{
            n= abs(nums[i]);
            break;
        }
    }
    return n;
}

// TIME COMPLEXITY: O(N)
// AUXILIARY SPACE: O(1)
