#include <iostream>
<<<<<<< HEAD
#include <climits>
=======
>>>>>>> 0066dad836f719347708659766ead4b8b01e1c1d
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
<<<<<<< HEAD
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
=======
	cout<<endl;
}

void seperate(int a[], int b[], int c[], int n, int &nb, int &nc) {
    int lb = 0, lc = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > 0) {
            b[lb] = a[i];
            ++lb;
        } else {
            c[lc] = a[i];
            ++lc;
        }
    }
    nb = lb;
    nc = lc;
}

void sort(int a[],int d[],int n,int &nd){
	int l =0;
	for(int i=0;i<n;i++){
		if(a[i]>0) d[l] =  a[i];++l;
		if(a[i]<0) d[l] = a[i];++l;
		if(a[i]=0) d[l] = a[i];++l;
	}
	nd =l;
}

int main(){
	int n;
	int nb=1,nc=1,nd=1;
	int a[MAX];
	int b[nb];
	int c[nc];
	int d[nd];
	inputArray(a,n);
	seperate(a,b,c,n,nb,nc);
	printArray(b,nb);
	printArray(c,nc);
	sort(a,d,n,nd);
	printArray(d,n);
>>>>>>> 0066dad836f719347708659766ead4b8b01e1c1d
}	

