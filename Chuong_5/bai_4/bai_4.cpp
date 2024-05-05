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

void Input(int &n){
	cin>>n;
	while(n<=0){
		cin>>n;
	}
}

void FindX(int a[],int n,int x){
	for(int i=n-1;i>=0;i--){
		if(a[i]==x){
			cout<<"LastPositionOfX: "<<i+1<<endl;
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
		if(a[i]<=1){
			isPrime = false;
		}
		if(isPrime){
			cout<<"FirstPrime: "<<a[i]<<endl;
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

	cout<<"Min: "<<min<<endl;
}

void MinPos(int a[],int n){
	int minPos=INT_MAX;
	for(int i=0;i<n;i++){
		if(a[i]>0){
			minPos=a[i];
			break;
		}
	}

	for(int i=0;i<n;i++){
		if(a[i]<minPos and a[i]>0){
			minPos = a[i];
		}
	}
	if(minPos!=INT_MAX)
		cout<<"MinPos: "<<minPos<<endl;
	else
		cout<<"NoMinPos";
}

void MaxNeg(int a[],int n){
	int maxNeg=INT_MIN;
	for(int i=0;i<n;i++){
		if(a[i]<0){
			maxNeg=a[i];
			break;
		}
	}

	for(int i=0;i<n;i++){
		if(a[i]>maxNeg and a[i]<0){
			maxNeg = a[i];
		}
	}

	if(maxNeg!=INT_MIN)
		cout<<"MaxNeg: "<<maxNeg<<endl;
	else
		cout<<"NoMaxNeg";
}

int main(){
	int n,x;
	int a[MAX];
	inputArray(a,n);
	Input(x);
	FindX(a,n,x);
	firstPrime(a,n);
	Min(a,n);
	MinPos(a,n);
	MaxNeg(a,n);
}	

