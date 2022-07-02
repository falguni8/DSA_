bool isvalid(vector<int>&C,long int k,long int s){
    long int fsum=0;
    long int c=1;
    for(int i=0;i<C.size();i++){
        fsum+=C[i];
        if(fsum>s){
            c++;
            fsum=C[i];
        }
    }
    if(c<=k){
            return true;
        }
    return false;
}
int Solution::paint(int A, int B, vector<int> &C) {
    int mx=0;
    long int sum=0;
    int mod=10000003;
    for(int i=0;i<C.size();i++){
        sum+=C[i];
        mx=max(mx,C[i]);
    }
    long int low=mx;
    long int high=sum;
    long int res=-1;
    while(low<=high){
        long int mid=low+(high-low)/2;
        if(isvalid(C,A,mid)){
            res=mid%mod;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return (res*B)%mod;
}

