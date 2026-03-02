#include <iostream>
#include <cmath> // для функции sqrt
using namespace std;

int main() {
    double length, width;
    double perimeter, area, diagonal;
    
    cout << "Программа для вычисления параметров прямоугольника\n";
    cout << "================================================\n\n";
    
    cout << "Введите длину прямоугольника: ";
    cin >> length;
    
    cout << "Введите ширину прямоугольника: ";
    cin >> width;
    
    // Вычисления
    perimeter = 2 * (length + width);           // Периметр
    area = length * width;                       // Площадь
    diagonal = sqrt(length * length + width * width); // Диагональ (теорема Пифагора)
    
    cout << "\nРезультаты вычислений:\n";
    cout << "----------------------------------------\n";
    cout << "Длина: " << length << endl;
    cout << "Ширина: " << width << endl;
    cout << "----------------------------------------\n";
    cout << "Периметр: " << perimeter << endl;
    cout << "Площадь: " << area << endl;
    cout << "Диагональ: " << diagonal << endl;
    cout << "----------------------------------------\n";
    
    return 0;
}
