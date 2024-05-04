#include <iostream>
#define MAX 100

using namespace std;

void nhapMang(int a[],int &n){
	cin>>n;
	while(n<=0){
		cin>>n;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

}


void xuatMang(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}

int main(){
	int n;
	int a[MAX];
	nhapMang(a,n);
	xuatMang(a,n);
}