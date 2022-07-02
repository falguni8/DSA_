class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>a=nums;
        vector<pair<int,int>>m;
        for(int i=0;i<nums.size();i++){
            m.push_back({nums[i],i});
        }
        sort(m.begin(),m.end());
        int i=0;
        int j=nums.size()-1;
        while(i<j){
            //cout<<m[i].first<<m[j].first<<i<<j<<" ";
            if(m[i].first+m[j].first==target){
                return {m[i].second,m[j].second};
            }
            else if(m[i].first+m[j].first<target){
                i++;
            }
            else if(m[i].first+m[j].first>target){
                j--;
            }
        }
        return {};
    }
};