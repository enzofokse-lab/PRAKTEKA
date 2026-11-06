#include <iostream>
#include <limits> // Для очистки буфера ввода
#include <cmath>  // Не обязательно для целочисленного метода, но оставим для универсальности

using namespace std;

// Функция для безопасного ввода положительного целого числа (для объема)
long long getPositiveLongLong(const string& prompt) {
    long long value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            if (value < 0) {
                cout << "Ошибка: Объем не может быть отрицательным. Попробуйте снова.\n";
            }
            else {
                return value;
            }
        }
        else {
            cout << "Ошибка: Введено не число. Пожалуйста, введите целое число.\n";
            cin.clear(); // Сбрасываем флаг ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер ввода
        }
    }
}

// Функция для безопасного ввода положительного ненулевого целого числа (для скорости)
int getPositiveNonZeroInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            if (value <= 0) {
                cout << "Ошибка: Скорость должна быть больше нуля. Попробуйте снова.\n";
            }
            else {
                return value;
            }
        }
        else {
            cout << "Ошибка: Введено не число. Пожалуйста, введите целое число.\n";
            cin.clear(); // Сбрасываем флаг ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер ввода
        }
    }
}

int main() {
    // Установка локали для корректного отображения русских символов (опционально, зависит от компилятора)
     setlocale(LC_ALL, "Russian"); 

    cout << "========================================" << endl;
    cout << "   Древний архивариус: Оцифровка свитков" << endl;
    cout << "========================================" << endl;
    cout << endl;
    cout << "Инструкция:" << endl;
    cout << "1. Введите общий объем текста в символах (целое число >= 0)." << endl;
    cout << "2. Введите скорость сканера в символах в минуту (целое число > 0)." << endl;
    cout << endl;

    // Ввод данных с защитой
    long long volume = getPositiveLongLong("Введите объем текста в символах: ");
    int speed = getPositiveNonZeroInt("Введите скорость сканера (симв/мин): ");

    // Расчет времени с округлением вверх
    // Если объем 0, то время тоже 0
    long long time_minutes = 0;
    if (volume > 0) {
        // Формула округления вверх: (a + b - 1) / b
        time_minutes = (volume + speed - 1) / speed;
    }

    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << "Результат расчета:" << endl;
    cout << "Объем: " << volume << " симв." << endl;
    cout << "Скорость: " << speed << " симв./мин" << endl;
    cout << "Расчетное время выполнения работы: " << time_minutes << " минут(ы)" << endl;
    cout << "----------------------------------------" << endl;

    return 0;
}