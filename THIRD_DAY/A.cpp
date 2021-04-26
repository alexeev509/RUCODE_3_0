#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double x_a, y_a, x_b, y_b, x_c, y_c;
    cin >> x_a >> y_a >> x_b >> y_b >> x_c >> y_c;
    //Для векторного произведение
    double dx_a_c = x_c - x_a;
    double dy_a_c = y_c - y_a;
    double dx_a_b = x_b - x_a;
    double dy_a_b = y_b - y_a;
    //Для скалярного произведение
    double dx_b_c = x_c - x_b;
    double dy_b_c = y_c - y_b;
    double dx_b_a = x_a - x_b;
    double dy_b_a = y_a - y_b;
    
    double scalar_mult = dx_b_c * dx_b_a + dy_b_c * dy_b_a;
    //проверяем - где лежит точка - левее ЛУЧА или правее (левее - если скалярное произведение векторов <0)
    if (scalar_mult < 0) {
        //Если левее - выводим расстояние от точки A до точки B
        cout << fixed << setprecision(5) << sqrt(pow(x_a - x_b, 2) + pow(y_a - y_b, 2));
    } else {
        //Если правее - считаем площадь треугольника (как векторное произведение деленное на 2) и делим на основание
        //S=AC*AB/2=(|CB|*h)/2  => h = (AC*AB)/|CB|
        double h = (abs(dy_a_c * dx_a_b-dx_a_c * dy_a_b)) / (sqrt(pow(x_c - x_b, 2) + pow(y_c - y_b, 2)));
        cout << fixed << setprecision(5) << h;
    }
    return 0;
}
