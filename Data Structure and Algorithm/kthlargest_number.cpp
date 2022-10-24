//Kth Largest Element in an Array

//Given an integer array nums and an integer k, return the kth largest element in the array. Note that it is the kth largest element in the sorted order, not the kth 
//distinct element. You must solve it in O(n) time complexity.

//Example 1:

//Input: nums = [3,2,1,5,6,4], k = 2
//Output: 5

int findKthLargest(vector<int>& nums, int k) {
	priority_queue<int> pq(nums.begin(),nums.end());
	for(int i=1;i<k;++i) pq.pop();
	return pq.top();
}

//TIME COMPLEXITY: O(NlogN)
//AUXILIARY SPACE: O(N)
