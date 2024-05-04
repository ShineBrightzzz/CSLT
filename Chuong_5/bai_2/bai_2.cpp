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
	bool odd = true;
	bool even = true;
	for(int i=0;i<n;i++){
		if(a[i]%2!=0){
			even = false;
			break;
		}
	}

	for(int i=0;i<n;i++){
		if(a[i]%2==0){
			odd = false;
			break;
		}
	}

	if(odd == true){
		cout<<"Odd";
	}
	else if(even ==true){
		cout<<"Even";
	}else{
		cout<<"Not odd either even";
	}
	
}

// void checkPrime(){

// }

// void checkSquare(){

// }

// void checkAsc(){

// }

// void checkDesc(){

// }


int main(){
	int n;
	int a[MAX];
	nhapMang(a,n);
	checkOddEven(a,n);
}