#include <iostream>
#define MAX 100

using namespace std;

void inputArray(int a[],int &n){
	cin>>n;
	while(n<=0||n>MAX){
		cin>>n;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

}

void Input(int &n){
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
	cout<<DivCount<<endl;
}

void sumPrime(int a[],int n){
	bool isPrime = true;
	int sum =0;
	for(int i=0;i<n;i++){
		isPrime = true;
 		for(int j=2;j<a[i];j++){
 			if(a[i]%j==0){
 				isPrime = false;
 				break;
 			}
 		}
 		if(a[i]==0||a[i]==1){
 			isPrime = false;
 		}

 		if(isPrime==true){
 			sum+=a[i];
 		}
 	}
 	cout<<sum<<endl;
}

int main(){
	int n,m,k;
	int a[MAX];
	inputArray(a,n);
	Input(m);
	Input(k);
	Div(a,n,m,k);
	sumPrime(a,n);	
}	