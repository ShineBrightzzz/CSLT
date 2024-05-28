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

bool isPalindrome(char s[]){
	char ords[MAX];
	for (int i = 0; i < strlen(s); ++i)
	{
		ords[i] = s[i];
	}
	for (int i = 0; i < strlen(s)/2; ++i)
	{
		swap(s[i],s[strlen(s)-i-1]);
	}
	for (int i = 0; i < strlen(s); ++i)
	{
		if (ords[i]!=s[i]){
			return false;
		}
	}
	return true;
}


int main(){
	char s[MAX];
	input(s);
	cout<<isPalindrome(s);
}