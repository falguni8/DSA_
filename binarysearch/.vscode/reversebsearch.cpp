#include<bits/stdc++.h>
#include<iostream>
#include<vector>

int binarysearch(int arr[],int key,int n){
    int start=0;
    int end=n-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==key){
            return mid;
        }
        if(arr[mid]<key){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return -1;
}
using namespace std;
int main(){
    int arr[5]={9,5,3,1,0};
    int key=5;
    cout<<binarysearch(arr,key,5);
    return 0;

}