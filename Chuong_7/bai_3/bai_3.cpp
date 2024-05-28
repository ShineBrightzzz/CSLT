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

char lower(char ch){
	if(ch<='Z' && ch>='A'){
		ch = ch + 32;
	}
	return ch;
}

char upper(char ch){
	if(ch<='z' && ch>='a'){
		ch = ch - 32;
	}
	return ch;
}

void proper(char s[]){
	bool isfirstLetter = true;
	for (int i = 0; i < strlen(s); ++i)
	{
		if(s[i]==' '){
			isfirstLetter = true;
			continue;
		}
		if(isfirstLetter == true){
			s[i] = upper(s[i]);
			isfirstLetter = false;
		}else{
			s[i] = lower(s[i]);
		}

	}
}






int main(){
	char s[MAX];
	input(s);
	proper(s);
	print(s);
}