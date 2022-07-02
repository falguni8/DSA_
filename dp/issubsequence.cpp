class Solution {
public:
    string f(string X, string Y, int m, int n)
    {
        //code here
        int dp[m+1][n+1];
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0||j==0){
                    dp[i][j]=0;
                }
            }
        }
        int l=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(X[i-1]==Y[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    //l=max(l,dp[i][j]);
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int i=m;
        int j=n;
        string s;
        while(i>0 && j>0){
            if(X[i-1]==Y[j-1]){
                s.push_back(X[i-1]);
                i--;
                j--;
            }
            else{
                if(dp[i][j-1]>dp[i-1][j]){
                    s.push_back(Y[j-1]);
                    j--;
                }
                else{
                    s.push_back(X[i-1]);
                    i--;
                }
            }
        }
        while(i>0){
            s.push_back(X[i-1]);
            i--;
        }
        while(j>0){
            s.push_back(Y[j-1]);
            j--;
        }
        reverse(s.begin(),s.end());
        return s;
    }
    bool isSubsequence(string s, string t) {
        string k=f(s,t,s.size(),t.size());
        return k==t;
    }
};