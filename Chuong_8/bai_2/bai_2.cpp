// Nhập/Xuất n phân số
// Rút gọn mọi phân số
// Đếm số lượng phân số âm/dương trong mảng
// Tìm phân số dương đầu tiên trong mảng
// Tìm phân số nhỏ nhất/lớn nhất trong mảng
// Sắp xếp mảng tăng dần/giảm dần


#include <iostream>
#define MAX 100

using namespace std;

struct PHANSO {
    int tu;
    int mau;
};

PHANSO ps[MAX];
int n;

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

void nhapMang(PHANSO ps[],int &n) {
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin >> ps[i].tu >> ps[i].mau;
        while (ps[i].mau == 0) {
            cin >> ps[i].mau;
        }
    }
    
}

void Dem(PHANSO ps[],int n){
    int psDuong=0;
    int psAm=0;
    for (int i = 0; i < n; ++i)
    {
        if(ps[i].tu>0){
            ++psDuong;
        }else if(ps[i].tu<0){
            ++psAm;
        }
    }

    cout<<"Trong mang co "<<psDuong<<" phan so duong"<<endl;
    cout<<"Trong mang co "<<psAm<<" phan so am"<<endl;
}

void soDuongDauTien(PHANSO ps[],int n){
    for (int i = 0; i < n; ++i)
    {
        if(ps[i].tu>0){
            cout<<"Phan so duong dau tien trong mang la: "<<ps[i].tu<<" "<<ps[i].mau<<endl;
            return;
        }
    }
}

void sapXep(PHANSO ps[], int n){
    PHANSO temp;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (ps[j].tu > ps[j+1].tu){
                    temp = ps[j];
                    ps[j] = ps[j+1];
                    ps[j+1] = temp;
            }
        }
    }
}




void xuat(PHANSO ps[],int n) {
    for (int i = 0; i < n; ++i)
    {
        cout << ps[i].tu << " " << ps[i].mau << endl;
    }
    
}





// int lcm(int a, int b) {
//     return (a / gcd(a, b)) * b;
// }

// void quydong(PHANSO &pso1, PHANSO &pso2) {
//     int bcnn = lcm(pso1.mau, pso2.mau);
//     pso1.tu = pso1.tu * (bcnn / pso1.mau);
//     pso2.tu = pso2.tu * (bcnn / pso2.mau);
//     pso1.mau = bcnn;
//     pso2.mau = bcnn;
// }

int main(){
	nhapMang(ps,n);
    Dem(ps,n);
    soDuongDauTien(ps,n);
    sapXep(ps,n);
    xuat(ps,n);
}