int isvalid(vector<int>&A,int n,int B,int mid){
    int cnt = 0;
    int sumAllocated = 0;
    for (int i = 0; i < n; i++) {
        if (sumAllocated + A[i] > mid) {
            cnt++;
            sumAllocated = A[i];
            if (sumAllocated > mid) return false;
        }
        else {
            sumAllocated += A[i];
        }
    }
  if (cnt <B) return true;
  return false;
}
int Solution::books(vector<int> &A, int B) {
    if(B>A.size()){
        return -1;
    }
    int sum=0;
    for(int i=0;i<A.size();i++){
        sum+=A[i];
    }
    int low=0;
    int high=sum;
    int res=INT_MAX;;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(isvalid(A,A.size(),B,mid)){
            res=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return res;
}
