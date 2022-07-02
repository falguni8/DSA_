class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>>mp;
        for(int i=0;i<arr.size();i++){
            mp.push({abs(arr[i]-x),arr[i]});
            if(mp.size()>k){
                mp.pop();
            }
        }
        vector<int>ans;
        while(mp.size()>0){
            ans.push_back(mp.top().second);
            mp.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};