unordered_map<string,int>mp;

int Solution::isScramble(const string A, const string B) {
    string key = A + " " + B;
    if (mp.find(key) != mp.end())
		return mp[key];

    if(A.length()!=B.length()){
        return 0;
    }
    if(A.compare(B)==0){
        return 1;
    }
    if(A.length()<=1){
        return 0;
    }
    int n=A.length();
    int flag=0;
    for(int i=1;i<=n-1;i++){
        if(isScramble(A.substr(0,i),B.substr(n-i,i)) && isScramble(A.substr(i),B.substr(0,n-i))
        ||isScramble(A.substr(0,i),B.substr(0,i)) && isScramble(A.substr(i),B.substr(i))){
            flag=1;
            break;
        }
    }
    mp[key] = flag;
    return flag;
}