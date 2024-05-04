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

void FindX(int a[],int n,int x){
	for(int i=n-1;i>=0;i++){
		if(a[i]==x){
			cout<<i;
			break;
		}
	}
}

void firstPrime(int a[],int n){
	bool isPrime = true;
	for(int i=0;i<n;i++){
		isPrime = true;
		for(int j=2;j<a[i];j++){
			if(a[i]%j==0){
				isPrime = false;
				break;
			}
		}
		if(a[i]==1||a[i]==0){
			isPrime = false;
		}
		if(isPrime){
			cout<<a[i]<<endl;
			break;
		}
	}
}

void Min(int a[],int n){
	int min=a[0];
	for(int i=0;i<n;i++){
		if(a[i]<min){
			min=a[i];
		}
	}

	cout<<min;
}

int main(){
	int n,x;
	int a[MAX];
	inputArray(a,n);
	Input(x);
	firstPrime(a,n);
	Min(a,n);

}	