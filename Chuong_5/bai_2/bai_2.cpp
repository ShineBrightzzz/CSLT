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

void checkOddEven(int a[],int n){
	bool isOdd = true;
	bool isEven = true;
	for(int i=0;i<n;i++){
		if(a[i]%2!=0){
			isEven = false;
			break;
		}
	}

	for(int i=0;i<n;i++){
		if(a[i]%2==0){
			isOdd = false;
			break;
		}
	}

	if(isOdd == true){
		cout<<"Odd"<<endl;
	}
	else if(isEven ==true){
		cout<<"Even"<<endl;
	}else{
		cout<<"Neither Odd nor Even"<<endl;
	}
	
}
	
 void checkPrime(int a[],int n){
 	bool isPrime = true;
 	for(int i=0;i<n;i++){
 		for(int j=2;j<a[i];j++){
 			if(a[i]%j==0){
 				isPrime = false;
 				break;
 			}
 		}
 	}

 	if(isPrime){
 		cout<<"Prime"<<endl;
 	}else{
 		cout<<"notPrime"<<endl;
 	}
 }

 void checkSquare(int a[],int n){
 	bool isSquare = false;
 	int SquareCount =0;
 	for(int i=0;i<n;i++){
 		isSquare = false;
 		for(int j=1;j<=a[i];j++){
 			if(a[i]==j*j){
 				isSquare = true;
 				SquareCount++;

 			}
 		}
 	}

 	if(SquareCount == n){
 		cout<<"Square"<<endl;
 	}else{
 		cout<<"notSquare"<<endl;
 	}
}

void checkAsc(int a[],int n){
	bool isAsc = true;
	for(int i=0;i<n-1;i++){
		if(a[i]>a[i+1]){
			isAsc = false;
			break;
		}
	}

	if(isAsc){
		cout<<"Day tang";
	}
}

void checkDesc(int a[],int n){
	bool isDesc = true;
	for(int i=0;i<n-1;i++){
		if(a[i]<a[i+1]){
			isDesc = false;
			break;
		}
	}

	if(isDesc){
		cout<<"Day giam";
	}
}


int main(){
	int n;
	int a[MAX];
	nhapMang(a,n);
	checkOddEven(a,n);
	checkPrime(a,n);
	checkSquare(a,n);
	checkAsc(a,n);
	checkDesc(a,n);
}