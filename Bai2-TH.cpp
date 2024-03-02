//Bài : 2
//Xây dựng lớp latop thuộc tính gồm: model, hãng sản xuất, giá, thời gian bảo hành.
// Các phương thức của lớp: phương thức toán tử nhập, xuất và các phương thức khác.
// Viết chương trình nhập thông tin cho n laptop.
// In danh sách theo thứ tự tăng dần của giá.
// Tìm laptop dưới giá x(x là số nguyên dương nhập từ bàn phím)
//Bổ sung: thay cá hàm của lớp thành hàm bạn.
//Bổ sung các hàm đặc biệt vào các lớp

#include <iostream>
#include <string>
using namespace std;

class Laptop
{
private:
    string model;
    string hangSanXuat;
    int gia;
    int thoiGianBaoHanh;

public:
    friend istream &operator >> (istream &is, Laptop &X);
    friend ostream &operator << (ostream &os, Laptop X);
    bool operator < (Laptop X);
    bool operator > (Laptop X);
    Laptop();
    ~Laptop();
    Laptop(string model, string hangSanXuat, int gia, int thoiGianBaoHanh);
    friend int getGia(Laptop X);
};

Laptop::Laptop()
{
    model = "";
    hangSanXuat = "";
    gia = 0;
    thoiGianBaoHanh = 0;
}

Laptop::~Laptop()
{
}

Laptop::Laptop(string model, string hangSanXuat, int gia, int thoiGianBaoHanh)
{
    this->model = model;
    this->hangSanXuat = hangSanXuat;
    this->gia = gia;
    this->thoiGianBaoHanh = thoiGianBaoHanh;
}

int getGia(Laptop X)
{
    return X.gia;
}

istream &operator >> (istream &is, Laptop &X)
{
    cout << "Nhap model: ";
    is >> X.model;
    cout << "Nhap hang san xuat: ";
    is >> X.hangSanXuat;
    cout << "Nhap gia: ";
    is >> X.gia;
    cout << "Nhap thoi gian bao hanh: ";
    is >> X.thoiGianBaoHanh;
    return is;
}

ostream &operator << (ostream &os, Laptop X)
{
    os << "Model: " << X.model << endl;
    os << "Hang san xuat: " << X.hangSanXuat << endl;
    os << "Gia: " << X.gia << endl;
    os << "Thoi gian bao hanh: " << X.thoiGianBaoHanh << endl;
    return os;
}

bool Laptop::operator < (Laptop X)
{
    return gia < X.gia;
}

bool Laptop::operator > (Laptop X)
{
    return gia > X.gia;
}

class DanhSachLaptop
{
private:
    Laptop *a;
    int n;

public:
    friend void nhap(DanhSachLaptop &X, int n);
    friend void xuat(DanhSachLaptop &X, int n);
    friend void sapXep(DanhSachLaptop &X, int n);
    friend void timLaptopDuoiGiaX(DanhSachLaptop &X, int n, int x);
};

void nhap(DanhSachLaptop &X, int n)
{
    X.n = n;
    X.a = new Laptop[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin laptop thu " << i + 1 << ": " << endl;
        cin >> X.a[i];
    }
}

void xuat(DanhSachLaptop &X, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Thong tin laptop thu " << i + 1 << ": " << endl;
        cout << X.a[i];
    }
}

void sapXep(DanhSachLaptop &X, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (X.a[i] > X.a[j])
            {
                Laptop temp = X.a[i];
                X.a[i] = X.a[j];
                X.a[j] = temp;
            }
        }
    }
}

void timLaptopDuoiGiaX(DanhSachLaptop &X, int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (getGia(X.a[i]) < x)
        {
            cout << "Thong tin laptop duoi gia " << x << ": " << endl;
            cout << X.a[i];
        }
    }
}

int main()
{
    int n;
    cout << "Nhap so luong laptop: ";
    cin >> n;
    DanhSachLaptop ds;
    nhap(ds, n);
    xuat(ds, n);
    sapXep(ds, n);
    cout << "Danh sach laptop sau khi sap xep: " << endl;
    xuat(ds, n);
    int x;
    cout << "Nhap gia x: ";
    cin >> x;
    timLaptopDuoiGiaX(ds, n, x);
    return 0;
}

