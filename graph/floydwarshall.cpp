// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
  const int INF = 1e9;
  /*i j k*/
	void shortest_distance(vector<vector<int>>&matrix){
	   for(int j = 0 ; j < matrix.size() ; j++){
	       for(int i = 0 ; i < matrix.size() ; i++){
	           for(int k = 0 ; k < matrix.size();k++){
	               int x = matrix[i][k];    if(x == -1) x = INF;
	               int y = matrix[i][j];    if(y == -1) y = INF;
	               int z = matrix[j][k];    if(z == -1) z = INF;
	               matrix[i][k]  = min(x,y+z);
	               if(matrix[i][k]==INF){
	                   matrix[i][k]=-1;
	               }
	           }
	       }
	   }
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends