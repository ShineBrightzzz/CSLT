#include <iostream>

using namespace std;

struct PHANSO {
    int tu;
    int mau;
};

PHANSO pso1,pso2;   

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

void rutgon(PHANSO &pso) {
    int uoc = gcd(abs(pso.tu), abs(pso.mau));
    pso.tu /= uoc;
    pso.mau /= uoc;
}

void nhap(PHANSO &pso) {
    cin >> pso.tu >> pso.mau;
    while (pso.mau == 0) {
        cin >> pso.mau;
    }
    rutgon(pso);
}

void xuat(const PHANSO &pso) {
    cout << pso.tu << " " << pso.mau << endl;
}


bool toigian(const PHANSO &pso) {
    return gcd(abs(pso.tu), abs(pso.mau)) == 1;
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

void quydong(PHANSO &pso1, PHANSO &pso2) {
    int bcnn = lcm(pso1.mau, pso2.mau);
    pso1.tu = pso1.tu * (bcnn / pso1.mau);
    pso2.tu = pso2.tu * (bcnn / pso2.mau);
    pso1.mau = bcnn;
    pso2.mau = bcnn;
}

int main(){
	nhap(pso1);
	nhap(pso2);
	quydong(pso1,pso2);
	xuat(pso1);
	cout<<endl;
	xuat(pso2);

}