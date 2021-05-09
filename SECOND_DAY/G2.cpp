#include "iostream"
#include "vector"

using namespace std;
int n;
long k;
vector<long long> fibs;

void create_fibs_sequence() {
    fibs[0] = 1;
    fibs[1] = 2;
    for (int i = 2; i <= n; ++i)
        fibs[i] = fibs[i - 1] + fibs[i - 2];

//    for (int i = 0; i <= n; ++i)
//        cout << "Length: " << i << " Count:" << fibs[i] << " ";
//    cout << "\n";
}


int main() {
    cin >> n >> k;
    fibs.resize(n + 2);
    create_fibs_sequence();
    int prev = -1;
    for (int i = n-1; i >= 0; --i) {
        if (prev == 1) {
            cout << 0;
            prev=0;
        } else if (fibs[i] <= k) {
            cout << 1;
            k -= fibs[i];
            prev = 1;
        }else{
            cout << 0;
            prev=0;
        }

    }
    return 0;
}

//3 4
//101


//Алгоритм:
//Предположим что первый  - это ноль;
//Значит это могут быть номера >fibs[2] {0,1,2}

//то есть после нуля могут быть след варианты: 000,001; 010;


//Предположим что первый  - это один;
//Значит это могут быть номера <=fibs[2] {3,4}

//то есть после нуля могут быть след варианты: 100,101

//Поняли - что второй вариант нас устраивает;
//k-=fibs[2] = 4-3=1

//Также нужно учитывать - если была поставлена до этого 1 - после может быть только нолик!!!!


//Пример последовательностей Фиббоначи:
//000    - 0
//001    - 1
//010    - 2
//100    - 3
//101    - 4

//2+
