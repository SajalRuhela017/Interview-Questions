// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

// Example 1:
// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]

// Example 2:
// Input: nums = [-1,-100,3,99], k = 2
// Output: [3,99,-1,-100]
// Explanation: 
// rotate 1 steps to the right: [99,-1,-100,3]
// rotate 2 steps to the right: [3,99,-1,-100]
 
// Constraints:
// 1 <= nums.length <= 10^5
// -2^31 <= nums[i] <= 2^31 - 1
// 0 <= k <= 10^5


//Approach 1:
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> result;
        if(nums.size()<k){
            k = k%nums.size();
        }
        for(int i=nums.size()-k;i<nums.size();i++){
            result.push_back(nums[i]);
        }
        for(int i=0;i<nums.size()-k;i++){
            result.push_back(nums[i]);
        }
        nums = result;
    }
};

//Approach 2:
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size()<k){
            k = k%nums.size();
        }
        reverse(nums.begin(),nums.end()-k);
        reverse(nums.end()-k,nums.end());
        reverse(nums.begin(),nums.end());
    }
};