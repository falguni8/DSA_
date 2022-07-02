#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    int ans=0;
	    int count[26];
	    int q[26];
	    for(int i=0;i<26;i++){
	        count[i]=0;
	        q[i]=0;
	    }
        int i=0;
        int j=0;
        int K=pat.length();
        int N=txt.length();
        for(int m=0;m<K;m++){
            q[pat[m]-'a']++;
        }
        while(j<N){
            count[txt[j]-'a']++;
            if(j-i+1<K){
                j++;
            }
            else if((j-i+1)==K){
                int flag=0;
                for(int p=0;p<K;p++){
                    if(count[pat[p]-'a']==q[pat[p]-'a']){
                        flag=1;
                    }
                    else{
                        flag=0;
                        break;
                    }
                }
                if(flag==1){
                    //cout<<i<<" "<<j<<"\n";
                    ans+=1;
                }
                if(count[txt[i]-'a']>0){
                    count[txt[i]-'a']--;
                }
                i++;
                j++;
            }
        }
        return ans;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends