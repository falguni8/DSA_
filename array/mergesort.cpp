#include<iostream>
using namespace std;

void merge(int *arr,int l,int mid,int r){
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
        if(a1[i]<a2[j]){
            arr[k]=a1[i];
            i++;
            k++;
        }
        else{
            arr[k]=a2[j];
            j++;
            k++;
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
}

void mergesort(int *arr,int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}


int main(){
    int n;
    cin>>n;
    int *arr=new int [n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergesort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}