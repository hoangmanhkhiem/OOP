//Bài 1: Xây dựng lớp DayNguyen (dãy số nguyên). Thuộc tính gồm:
//-	Số nguyên n lưu trữ số phần tử của mảng.
//-	Con trỏ thực lưu trữ các phần tử của dãy số thưc.
//Các phương thức gồm:
//-	Hàm nhập 1 dãy n số thực.
//-	Hàm bạn xuất n số thực.
//-	Hàm toán tử đếm vàliệt kê các phần tử là số nguyên tố
//        Viết chương trình nhập 2 dãy nguyên X, Y. In các dãy đó ra màn hình. Dãy nào có nhiều số nguyên tố hơn

#include <iostream>
#include <math.h>
using namespace std;

class DayNguyen
{
private:
    int n;
    int *a;

public:
    void nhap();
    void xuat();
    bool operator >= (DayNguyen X);
    int soNguyenTo(int n);
};

void DayNguyen::nhap()
{
    cout << "Nhap so phan tu cua day: ";
    cin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        cin >> a[i];
    }
}

void DayNguyen::xuat()
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int DayNguyen::soNguyenTo(int n)
{
    if (n < 2)
    {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

bool DayNguyen::operator>=(DayNguyen X) {
    int count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (soNguyenTo(a[i]) == 1)
        {
            count1++;
            cout << a[i] << " ";
        }
    }
    cout << endl;
    for (int i = 0; i < X.n; i++)
    {
        if (soNguyenTo(X.a[i]) == 1)
        {
            count2++;
            cout << X.a[i] << " ";
        }
    }
    cout << endl;
    if (count1 > count2) return true;
    else if (count1 < count2) return false;
    else return false;
}

int main()
{
    DayNguyen X, Y;
    cout << "Nhap day X: " << endl;
    X.nhap();
    cout << "Nhap day Y: " << endl;
    Y.nhap();
    cout << "Day X: ";
    X.xuat();
    cout << "Day Y: ";
    Y.xuat();
    if (X >= Y)
    {
        cout << "Day X co nhieu so nguyen to hon day Y" << endl;
    }
    else
    {
        cout << "Day Y co nhieu so nguyen to hon day X" << endl;
    }
}
