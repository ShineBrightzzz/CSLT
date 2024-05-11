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
}	

