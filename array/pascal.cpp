
vector<vector<int> > Solution::solve(int A) {
    if(!A) return {};
    if(A==1) return {{1}};
    if(A==2) return {{1},{1,1}};
    vector<vector<int>> res(A);
    res[0].push_back(1);
    {res[1].push_back(1); res[1].push_back(1);}
    for(int i=3;i<=A;i++){
            res[i-1].push_back(1);
        for(int j=1;j<res[i-2].size();j++){
                 res[i-1].push_back(res[i-2][j]+res[i-2][j-1]);
        }
             res[i-1].push_back(1);
    }
    return res;
}
