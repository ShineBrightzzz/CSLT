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


bool checkSquare(int n){
	bool isSquare = false;
	for(int i=1;i<=n;i++){
		if(i*i==n){
			return true;
		}
	}
	return false;
}


void FixArray(int a[],int n){
	for(int i=0;i<n;i++){ 
		if(checkPrime(a[i])){
			a[i]=0;
		}else if(checkSquare(a[i])){
			a[i]=-1;
		}
	}
}

void insert(int a[],int &n,int pos,int x){

	for(int i = n; i > pos; i--) {
        a[i] = a[i - 1];
    }
	a[pos] = x;
	n++;
}

void insert2(int a[],int &n){
	for(int i=0;i<n;i++){ 
		if(checkPrime(a[i])){
			insert(a,n,i+1,0);
			i++;
		}else if(checkSquare(a[i])){
			insert(a,n,i,-1);
			i++;
		}
	}
}

void Delete(int a[],int &n,int pos){
	for(int i=pos; i<n-1;i++){
		a[i]=a[i+1];
	}
	n--;
}

void delete2(int a[],int &n){
	for(int i=0;i<n;i++){
		if(checkPrime(a[i])){
			Delete(a,n,i);
			i--;
		}
	}
}

int reversed(int n,int res = 0){

	if(n==0){
		return res;
	}else{
		int digit = n%10;
		res = res * 10 + digit;
		return reversed(n/10,res ); 
	}

}

int main(){
	int n,x;
	int a[MAX];
	// inputArray(a,n);
	// insert2(a,n);
	cin>>n;
	// printArray(a,n);
	cout<<reversed(n);
}	

