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

void lower(char s[]){
	for (int i = 0; i < strlen(s); ++i)
	{
		if(s[i]<='Z' && s[i]>='A'){
			s[i] = s[i] +32;
		}
	}
}



int main(){
	char s[MAX];
	input(s);
	lower(s);
	print(s);
}