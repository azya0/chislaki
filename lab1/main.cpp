#include <iostream>
#include <cmath>
#include <iomanip>

// функция для методов
double function(double var) {
    return pow(var, 5) + pow(var, 2) - 5;
}

// Класс, реализующий метод половинного деления
class MPD {
private:
    // точность
    double e;

public:
    explicit MPD(double e = 0.001) {
        this->e = e;
    }
    // метод. a и b - концы отрезка. a < b
    double run(double a, double b) const {
        double result;

        while((b - a) / 2 > e) {
            result = (a + b) / 2;

            if ((function(a) * function(result)) > 0) a = result;
            else b = result;
        }

        return result;
    }
};

// Класс, реализующий метод хорд
class MH {
    // Точность
    double e;
public:
    explicit MH(double e = 0.001) {
        this->e = e;
    }

    // метод. a и b - концы отрезка. a < b
    double run(double a, double b) const {
        while (std::abs(b - a) > e) {
            a = a - (b - a) * function(a) / (function(b) - function(a));
            b = b - (a - b) * function(b) / (function(a) - function(b));
        }

        return a;
    }
};

int main() {
    system("chcp 1251");

    std::cout.setf(std::ios::fixed);

    for (int index = 2; index <= 15; index++) {
        std::cout << std::setprecision(8) << std::setw(10) << MPD(pow(10, -1 * index)).run(-1000, 1000) << ' ';
    }

    std::cout << '\n';

//    for (int index = 2; index <= 15; index++) {
//        std::cout << std::setprecision(8) << std::setw(10) << MH(pow(10, -1 * index)).run(-1.5, 0.5) << ' ';
//    }

    return 0;
}
