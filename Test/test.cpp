#include <bits/stdc++.h>

using namespace std;

void nhapMang(int a[], int &n){
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
}

void xuatMang(int a[],int n){
    for (int i = 0; i < n; ++i)
    {
        cout<<a[i]<<" ";
    }
}

int binarySearch(int a[],int n,int x){
    int low=1;
    int high = n-1;
    while (low<=high){
        int mid = low+ (high-low)/2; 
        if(a[mid]==x){
            return mid;
        }
        else if(a[mid]<x){
            low = mid+1;
        }else{
            high = mid-1;
        }       
    }

    return -1;


}



int main(){
    int n,m,k;
    int a[100];
    nhapMang(a,n);
    cout<<binarySearch(a,n,3);
}