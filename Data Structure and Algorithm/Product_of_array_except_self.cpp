// Product of Array Except Self

// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i]. The product of any prefix 
// or suffix of nums is guaranteed to fit in a 32-bit integer. You must write an algorithm that runs in O(n) time and without using the division operation.
  
// Example 1:
// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]

// Constraints:
// 2 <= nums.length <= 105
// -30 <= nums[i] <= 30
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

vector<int> productExceptSelf(vector<int>& nums) {
      int x=1,y=1,c=0;
      vector<int>v;
      for(int i = 0; i < nums.size(); i ++){
          if(nums[i] != 0)
          x *= nums[i];
          if(nums[i] == 0) c++;
      }
      for(int i = 0; i < nums.size(); i ++){
          if(c > 1){
              v.push_back(0);
              continue;
          }
          if(nums[i] == 0) v.push_back(x);
          else{
              if(c > 0) v.push_back(0);
              else v.push_back(x / nums[i]);
          }
      }
      return v;
}

// TIME COMPLEXITY: O(N)
// AUXILIARY SPACE: O(1)
