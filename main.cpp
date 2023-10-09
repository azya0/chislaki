#include <iostream>
#include <cmath>

// ������� ��� �������
double function(double var) {
    return pow(tan(var), 3) - var + 1;
}

// �����, ����������� ����� ����������� �������
class MPD {
private:
    // ��������
    double e;

public:
    explicit MPD(double e = 0.001) {
        this->e = e;
    }
    // �����. a � b - ����� �������. a < b
    double run(double a, double b) const {
        double result;

        while((b - a) / 2 > e) {
            result = (a + b) / 2;

            std::cout << "a = " << a << " b = " << b << " result = " << result << '\n';

            if ((function(a) * function(result)) > 0) a = result;
            else b = result;
        }

        return result;
    }
};

// �����, ����������� ����� ����
class MH {
    // ��������
    double e;
public:
    explicit MH(double e = 0.001) {
        this->e = e;
    }

    // �����. a � b - ����� �������. a < b
    double run(double a, double b) const {
        while (std::abs(b - a) > e) {
            a = a - (b - a) * function(a) / (function(b) - function(a));
            b = b - (a - b) * function(b) / (function(a) - function(b));

            std::cout << "a = " << a << " b = " << b << " a - b = " << a - b << '\n';
        }

        return a;
    }
};

int main() {
    system("chcp 1251");

    std::cout << "������ ����������� �������:\n";
    std::cout << MPD().run(-1.5, 0.5);
    std::cout << "\n������ ����:\n";
    std::cout << MH().run(-1.5, 0.5);
    return 0;
}
