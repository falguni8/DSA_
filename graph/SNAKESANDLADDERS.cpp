class Solution {
    public:
        int snakesAndLadders(vector<vector<int>>& board) {
                int r=board.size();
                queue<int> q;
                q.push(1);
                int step=0;
                bool vis[r][r];
                for(int i=0;i<r;i++){
                    for(int j=0;j<r;j++){
                        vis[i][j]=false;
                    }
                }
                vis[r-1][0]=true;
                while(!q.empty()){
                    int n=q.size();
                    for(int i=0;i<n;i++)
                    {
                        int t=q.front();
                        q.pop();
                        //cout<<t<<" ";
                        if(t==r*r)return step;
                        for(int i=1;i<=6;i++)
                        {
                            int next_step=t+i;
                            if(next_step>r*r)break;
                            auto v=cordinate(r,next_step); 
                            int row=v[0],col=v[1];
                            if(vis[row][col]==true){
                                continue;
                            }
                            vis[row][col]=true;
                            if(board[row][col]==-1)
                            {
                                q.push(next_step);
                            }
                            else{
                                q.push(board[row][col]);
                            }
                        }
                    }
                    step++;
                }
           // cout<<step<<" ";
             return -1;
        }
    private:
    vector<int> cordinate(int n,int curr){
        int r = n - (curr - 1) / n  -1;
        int c = (curr - 1) % n;
        if (r % 2 == n % 2) {
            return {r, n - 1 - c};
        } else {
            return {r, c};
        }
    }
};