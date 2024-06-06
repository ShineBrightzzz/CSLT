#include <iostream>
#include <cstring>
#define MAX 100

using namespace std;

void input(char s[]) {
    cin.getline(s, MAX);
}


void print(char s[]){
	for (int i = 0; i < strlen(s); ++i)
	{
		cout<<s[i];
		if(s[i]==' '){
			cout<<endl;
		}
	}
}

void upper(char s[]){
	for (int i = 0; i < strlen(s); ++i)
	{
		if(s[i]<='z' && s[i]>='a'){
			s[i] = s[i] - 32;
		}
	}
}


int main(){
	char s[MAX];
	input(s);
	upper(s);
	print(s);
}