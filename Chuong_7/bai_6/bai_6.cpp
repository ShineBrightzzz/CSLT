#include <iostream>
#include <cstring>
#define MAX 100

using namespace std;

void input(char s[]) {
    cin.getline(s, MAX);
}

string maxLengthWord(char s[]) {
    int i = 0;
    int j = 0;
    int imax = 0;
    int jmax = 0;
    std::string res;

    int len = strlen(s);
    
    while (j <= len) {
        i = j;
        while (j < len && s[j] != ' ') {
            ++j;
        }
        if (j - i > jmax - imax) {
            imax = i;
            jmax = j;
        }
        ++j;
    }

    for (int a = imax; a < jmax; ++a) {
        res += s[a];
    }
    
    return res;
}

int main() {
	char s[MAX];
	input(s);
	cout<<maxLengthWord(s);
}
