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
	}
}


int wordCount(char s[]){
	int count=(s[0] != ' ');
	for(int i=0;i<strlen(s)-1;i++){
		if(s[i]==' '|| s[i]=='\t' || s[i]=='\n'){
			if(s[i+1]!=' '&& s[i+1]!='\t' && s[i+1]!='\n')
				++count;
		}
	}
	return count;
}


int main(){
	char s[MAX];
	input(s);
	cout<<wordCount(s);
}