class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }
        if(nums.size()==0){
            return 0;
        }
	   int longest = 1;
	   for(int num : s) {
            if(s.count(num - 1)) continue;
            int j = 1;
            while(s.count(num + j)){ 
                j++; 
                longest = max(longest, j);
            }
        }
	return longest;
    }
};