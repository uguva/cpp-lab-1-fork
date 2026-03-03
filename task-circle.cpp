#include <iostream>
#include <cmath>

using namespace std;

int main() {
    const double PI = 3.1415926535;
    double r, angle;

    cout << "--- ЗАДАНИЕ 1d: ОКРУЖНОСТЬ ---" << endl;
    cout << "Введите радиус окружности: ";
    cin >> r;
    cout << "Введите угол сектора (в градусах): ";
    cin >> angle;

    if (r <= 0) {
        cout << "Ошибка: Радиус должен быть положительным!" << endl;
        return 1;
    }

    cout << "Длина окружности: " << 2 * PI * r << endl;
    cout << "Площадь круга: " << PI * r * r << endl;
    cout << "Площадь сектора: " << (PI * r * r * angle) / 360.0 << endl;

    return 0;
}
