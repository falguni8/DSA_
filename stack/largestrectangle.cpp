class Solution {
public:
    int largestRectangleArea(vector<int>& heights){
        vector<int>right;
        vector<int>left;
        vector<int>width(heights.size());
        stack<pair<int,int>>s;
        heights.push_back(0);
        int n=heights.size();
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && heights[i]<=s.top().first){
                s.pop();
            }
            if(s.empty()){
                right.push_back(0);
            }
            else{
                right.push_back(s.top().second);
            }
            s.push({heights[i],i});
        }
        reverse(right.begin(),right.end());
        while(!s.empty()){
            s.pop();
        }
        for(int i=0;i<n-1;i++){
            while(!s.empty() && heights[i]<=s.top().first){
                s.pop();
            }
            if(s.empty()){
                left.push_back(-1);
            }
            else{
                left.push_back(s.top().second);
            }
            s.push({heights[i],i});
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            width[i]=right[i]-left[i]-1; 
        }
        for(int i=0;i<n-1;i++){
            //cout<<width[i]<<" "<<right[i]<<" "<<left[i]<<"\n";
            ans=max(ans,width[i]*heights[i]);
        }
        return ans;
        }
};