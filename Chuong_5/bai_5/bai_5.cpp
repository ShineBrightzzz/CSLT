#include <iostream>
#include <climits>
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

void printArray(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}

bool checkPrime(int n){
	bool isPrime = true;
	if(n<=1){
		return false;
	}
	for(int i=2;i<n;i++){
		if(n%i==0){
			return false;
		}
	}

	return true;
}

void insertLast(int a[],int &n,int x){
	for(int i=0;i<MAX;i++){
		if(a[i]==NULL){
			a[i]=x;
			break;
		}
	}
}

void buildArrayB(int a[],int b[],int n){
	for(int i=0;i<n;i++){
		if(checkPrime(a[i])){
			insertLast(b,n,a[i]);
		}
	}
}


int main(){
	int n,x;
	int a[MAX];
	int b[MAX];
	int c[MAX];	
	inputArray(a,n);

	printArray(a,n);
}	

