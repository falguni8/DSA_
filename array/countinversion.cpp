#include<iostream>
using namespace std;


int merge(int *arr,int l,int mid,int r){
    int ans=0;
    int n1=mid-l+1;
    int n2=r-mid;
    int a1[n1];
    int a2[n2];
    for(int i=0;i<n1;i++){
        a1[i]=arr[i+l];
    }
    for(int j=0;j<n2;j++){
        a2[j]=arr[mid+1+j];
    }
    int i=0,j=0;
    int k=l;
    while(i<n1 && j<n2){
        if(a1[i]<=a2[j]){
            arr[k]=a1[i];
            i++;
            k++;
        }
        else{
            arr[k]=a2[j];
            j++;
            k++;
            ans+=n1-i;
        }
    }
    while(i<n1){
        arr[k]=a1[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=a2[j];
        j++;
        k++;
    }
    return ans;
}

int mergesort(int *arr,int l,int r){
    int ans=0;
    if(l<r){
        int mid=(l+r)/2;
        ans+=mergesort(arr,l,mid);
        ans+=mergesort(arr,mid+1,r);
        ans+=merge(arr,l,mid,r);
    }
    return ans;
}


int main(){
    int n;
    cin>>n;
    int *arr=new int [n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<mergesort(arr,0,n-1);
    return 0;
}