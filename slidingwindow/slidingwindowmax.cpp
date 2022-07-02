vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    vector<int> ans;
    if(B>A.size())
    {
        ans.push_back(*max_element(A.begin(),A.end()));
        return ans;
    }
    int i=0;
    int j=0;
    deque<int>q;
    while(j<A.size()){
        while(!q.empty() && A[j]>q.back()){
            q.pop_back();
        }
        q.push_back(A[j]);
        if(j-i+1<B){
            j++;
        }
        else if(j-i+1==B){
            ans.push_back(q.front());
            if(q.front()==A[i]){
                q.pop_front();
            }
            i++;
            j++;
        }
    }
    return ans;
}
