class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
       int ans = 0;
       for(int i=0; i<nums.size(); i++){
        int first = i+1<nums.size()?nums[i+1]:-1;
        int second = i+2<nums.size()?nums[i+2]:-1;
        int third = i+3<nums.size()?nums[i+3]:-1;


        if(nums[i]==first || nums[i]==second || nums[i]==third) return nums[i];
       } 
       return -1;
    }
};