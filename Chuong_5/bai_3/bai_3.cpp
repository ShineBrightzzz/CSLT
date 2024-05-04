#include <iostream>
#define MAX 100

using namespace std;

void nhapMang(int a[],int &n){
	cin>>n;
	while(n<=0||n>MAX){
		cin>>n;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

}

void Nhap(int &n){
	cin>>n;
	while(n<=0){
		cin>>n;
	}
}

void Div(int a[],int n,int m,int k){
	int DivCount = 0;
	for(int i=0;i<n;i++){
		if(a[i]%m==0 and a[i]%k!=0){
			DivCount++;
		}
	}
	cout<<DivCount;
}

int main(){
	int n,m,k;
	int a[MAX];
	nhapMang(a,n);
	Nhap(m);
	Nhap(k);
	Div(a,n,m,k);	
}	