/*Viết hàm standard(char s[]) loại bỏ toàn bộ khoảng trắng đầu xâu, 
cuối xâu và giữa 2 từ trong s chỉ còn 1 khoảng trắng.*/


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

string left(char s[],int pos){
	string str;
	for(int i=0;i<pos;++i){
		str+=s[i];
	}
	return str;
}

string right(char s[],int pos){
	string str;
	int n = strlen(s);
	for(int i=n-1;i>=n-pos;--i){
		str+=s[i];
	}
	return str;
}



int main(){
	char s[MAX];
	input(s);
	cout<<left(s,3);
	cout<<endl;
	cout<<right(s,3);
}