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

void Delete(char s[],int pos){
	int len = strlen(s);
	for (int i = pos; i < len; ++i)
	{
		s[i]=s[i+1];
	}
}

void deleteSpace(char s[]){
	for (int i = 0; i < strlen(s); ++i)
	{
		if(s[i]==' '){
			Delete(s,i);
			--i;
		}
	}
}


int main(){
	char s[MAX];
	input(s);
	deleteSpace(s);
	print(s);
}