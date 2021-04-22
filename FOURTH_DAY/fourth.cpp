#include <iostream>
//http://e-maxx.ru/algo/export_extended_euclid_algorithm
using namespace std;

long long a,b,n,m,x,y;;

long long gcdex (long long a, long long b, long long & x, long long & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    long long x1, y1;
    long long d = gcdex (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}


int main(){
    cin>>a>>b>>n>>m;
    gcdex (m, n, x, y);
    x = (x % n + n) % n;
    y = (y % m + m) % m;
    cout<<(a*m*x+b*n*y)%(m*n);
    return 0;
}

