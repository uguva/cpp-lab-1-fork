#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

// Функция для очистки ввода при ошибке
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Функция для проверки положительности числа
double getPositiveValue(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        
        if (cin.fail()) {
            clearInput();
            cout << "Ошибка! Введите число.\n";
        } else if (value <= 0) {
            cout << "Ошибка! Значение должно быть положительным.\n";
        } else {
            return value;
        }
    }
}

// Функция для вычислений прямоугольника
void calculateRectangle() {
    double length, width;
    double perimeter, area, diagonal;
    
    cout << "\n=== ВЫЧИСЛЕНИЕ ПАРАМЕТРОВ ПРЯМОУГОЛЬНИКА ===\n\n";
    
    length = getPositiveValue("Введите длину прямоугольника: ");
    width = getPositiveValue("Введите ширину прямоугольника: ");
    
    // Вычисления
    perimeter = 2 * (length + width);
    area = length * width;
    diagonal = sqrt(length * length + width * width);
    
    // Вывод результатов
    cout << "\n┌──────────────────────────────────────┐\n";
    cout << "│         РЕЗУЛЬТАТЫ ВЫЧИСЛЕНИЙ         │\n";
    cout << "├──────────────────────────────────────┤\n";
    cout << "│ Длина:    " << length << "\t\t       │\n";
    cout << "│ Ширина:   " << width << "\t\t       │\n";
    cout << "├──────────────────────────────────────┤\n";
    cout << "│ Периметр: " << perimeter << "\t\t       │\n";
    cout << "│ Площадь:  " << area << "\t\t       │\n";
    cout << "│ Диагональ: " << diagonal << "\t\t       │\n";
    cout << "└──────────────────────────────────────┘\n";
}

// Функция для вычислений трапеции
void calculateTrapezoid() {
    double a, b, c, d, h;
    double perimeter, area, midline;
    
    cout << "\n=== ВЫЧИСЛЕНИЕ ПАРАМЕТРОВ ТРАПЕЦИИ ===\n\n";
    
    cout << "Введите параметры трапеции:\n";
    cout << "────────────────────────────\n";
    a = getPositiveValue("Верхнее основание (a): ");
    b = getPositiveValue("Нижнее основание (b): ");
    c = getPositiveValue("Левая боковая сторона (c): ");
    d = getPositiveValue("Правая боковая сторона (d): ");
    h = getPositiveValue("Высота (h): ");
    
    // Проверка существования трапеции
    if (h > min(c, d)) {
        cout << "\nПредупреждение: Высота больше боковой стороны!\n";
        cout << "Трапеция с такими параметрами может не существовать.\n";
        cout << "Хотите продолжить? (1 - да, 0 - нет): ";
        int choice;
        cin >> choice;
        if (choice != 1) {
            return;
        }
    }
    
    // Вычисления
    perimeter = a + b + c + d;
    area = (a + b) / 2 * h;
    midline = (a + b) / 2;
    
    // Вывод результатов
    cout << "\n┌──────────────────────────────────────┐\n";
    cout << "│         РЕЗУЛЬТАТЫ ВЫЧИСЛЕНИЙ         │\n";
    cout << "├──────────────────────────────────────┤\n";
    cout << "│ Верхнее основание: " << a << "\t\t       │\n";
    cout << "│ Нижнее основание:  " << b << "\t\t       │\n";
    cout << "│ Левая сторона:     " << c << "\t\t       │\n";
    cout << "│ Правая сторона:    " << d << "\t\t       │\n";
    cout << "│ Высота:            " << h << "\t\t       │\n";
    cout << "├──────────────────────────────────────┤\n";
    cout << "│ Периметр:          " << perimeter << "\t\t       │\n";
    cout << "│ Площадь:           " << area << "\t\t       │\n";
    cout << "│ Средняя линия:     " << midline << "\t\t       │\n";
    cout << "└──────────────────────────────────────┘\n";
}

// Функция для вычислений равнобедренной трапеции
void calculateIsoscelesTrapezoid() {
    double a, b, side;
    double h, perimeter, area, midline;
    
    cout << "\n=== ВЫЧИСЛЕНИЕ ПАРАМЕТРОВ РАВНОБЕДРЕННОЙ ТРАПЕЦИИ ===\n\n";
    
    a = getPositiveValue("Верхнее основание (a): ");
    b = getPositiveValue("Нижнее основание (b): ");
    side = getPositiveValue("Боковая сторона (c): ");
    
    // Проверка возможности существования
    double halfBaseDiff = (b - a) / 2;
    if (halfBaseDiff < 0) halfBaseDiff = -halfBaseDiff;
    
    if (side <= halfBaseDiff) {
        cout << "\nОшибка! Боковая сторона слишком мала для таких оснований.\n";
        return;
    }
    
    // Вычисление высоты для равнобедренной трапеции
    h = sqrt(side * side - halfBaseDiff * halfBaseDiff);
    
    // Вычисления
    perimeter = a + b + 2 * side;
    area = (a + b) / 2 * h;
    midline = (a + b) / 2;
    
    // Вывод результатов
    cout << "\n┌──────────────────────────────────────┐\n";
    cout << "│         РЕЗУЛЬТАТЫ ВЫЧИСЛЕНИЙ         │\n";
    cout << "├──────────────────────────────────────┤\n";
    cout << "│ Верхнее основание: " << a << "\t\t       │\n";
    cout << "│ Нижнее основание:  " << b << "\t\t       │\n";
    cout << "│ Боковая сторона:   " << side << "\t\t       │\n";
    cout << "│ Высота:            " << h << "\t\t       │\n";
    cout << "├──────────────────────────────────────┤\n";
    cout << "│ Периметр:          " << perimeter << "\t\t       │\n";
    cout << "│ Площадь:           " << area << "\t\t       │\n";
    cout << "│ Средняя линия:     " << midline << "\t\t       │\n";
    cout << "└──────────────────────────────────────┘\n";
}

// Функция для отображения меню
void showMenu() {
    cout << "\n┌─────────────────────────────────────┐\n";
    cout << "│         ВЫБЕРИТЕ ФИГУРУ              │\n";
    cout << "├─────────────────────────────────────┤\n";
    cout << "│ 1. Прямоугольник                     │\n";
    cout << "│ 2. Трапеция (общий случай)           │\n";
    cout << "│ 3. Равнобедренная трапеция           │\n";
    cout << "│ 4. Сравнить обе трапеции             │\n";
    cout << "│ 0. Выход                              │\n";
    cout << "└─────────────────────────────────────┘\n";
    cout << "Ваш выбор: ";
}

// Функция для сравнения двух типов трапеций
void compareTrapezoids() {
    cout << "\n=== СРАВНЕНИЕ ТРАПЕЦИЙ ===\n";
    cout << "\nСначала введите параметры для общей трапеции:\n";
    calculateTrapezoid();
    
    cout << "\nТеперь введите параметры для равнобедренной трапеции:\n";
    calculateIsoscelesTrapezoid();
    
    cout << "\nПримечание: Для корректного сравнения параметры должны быть сопоставимы.\n";
}

int main() {
    int choice;
    
    cout << "┌─────────────────────────────────────┐\n";
    cout << "│   ПРОГРАММА ВЫЧИСЛЕНИЯ ПАРАМЕТРОВ   │\n";
    cout << "│        ГЕОМЕТРИЧЕСКИХ ФИГУР          │\n";
    cout << "└─────────────────────────────────────┘\n";
    
    do {
        showMenu();
        cin >> choice;
        
        if (cin.fail()) {
            clearInput();
            cout << "Ошибка! Введите число от 0 до 4.\n";
            continue;
        }
        
        switch(choice) {
            case 1:
                calculateRectangle();
                break;
                
            case 2:
                calculateTrapezoid();
                break;
                
            case 3:
                calculateIsoscelesTrapezoid();
                break;
                
            case 4:
                compareTrapezoids();
                break;
                
            case 0:
                cout << "\nПрограмма завершена. Спасибо за использование!\n";
                break;
                
            default:
                cout << "Ошибка! Выберите пункт от 0 до 4.\n";
        }
        
        if (choice != 0) {
            cout << "\nНажмите Enter для продолжения...";
            cin.ignore();
            cin.get();
        }
        
    } while (choice != 0);
    
    return 0;
}
