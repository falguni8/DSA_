class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int curr_sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                curr_sum+=nums[i];
            }
            else if(curr_sum+nums[i]>0){
                curr_sum+=nums[i];
            }
            else{
                curr_sum=0;
            }
            sum=max(sum,curr_sum);
        }
        if(sum==0){
            sort(nums.begin(),nums.end());
            sum=nums[nums.size()-1];
        }
        return sum;
    }
};