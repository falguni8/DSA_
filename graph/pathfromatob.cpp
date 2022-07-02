// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        string str;
        vector<string>ans;
        dfs(0,0,m,n-1,n-1,ans,str);
        if(ans.size()>0){
            sort(ans.begin(),ans.end());
            return ans;
        }
    }
    private:
    void dfs(int sx,int sy,vector<vector<int>>&m,int ex,int ey,vector<string>&ans,string &str){
        if(sx<0 || sx>ex||sy<0 ||sy>ex || m[sx][sy]==0){
            return ;
        }
        if(sx==ex && sy==ey){
            if(m[sx][sy]==1){
                ans.push_back(str);
                return;
            }
        }
        m[sx][sy]=0;
        str.push_back('U');
        dfs(sx-1,sy,m,ex,ey,ans,str);
        str.pop_back();
        str.push_back('D');
        dfs(sx+1,sy,m,ex,ey,ans,str);
        str.pop_back();
        str.push_back('R');
        dfs(sx,sy+1,m,ex,ey,ans,str);
        str.pop_back();
        str.push_back('L');
        dfs(sx,sy-1,m,ex,ey,ans,str);
        str.pop_back();
        m[sx][sy]=1;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends