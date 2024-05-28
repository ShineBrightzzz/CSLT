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

int substring(char s[]){
	int firstIndex = 0;
	int secondIndex = 1;
	int count = 0;
	int length = strlen(s);

	while(secondIndex<length){
		if(s[firstIndex] == 'e' && s[secondIndex]=='m'){
			++count;
		}

		++firstIndex;
		++secondIndex;
	}
	return count;
}


int main(){
	char s[MAX];
	input(s);
	cout<<substring(s);
}