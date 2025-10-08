#include <iostream>
#include <cmath>
#include <locale>
using namespace std;

class FunctionCalculator {
private:
    double x, y, z, a, b;

public:
    FunctionCalculator(double x, double y, double z) : x(x), y(y), z(z) {}

    double calculateB() {
        b = pow(fabs(y+x),0.2)/pow(fabs(z),1.34)+pow(y-z,2)/(1+pow(sin(z),2))+pow(fabs(z-y),3)/(z/cos(pow(x,2)));
        return b;
    }

    double calculateA() {
        a = (sqrt(pow(fabs(pow(x, 2) - 1), 0.3)) - pow(fabs(sin(y + 2 * b)), 1 / 3)) / (1 + x + pow(y, 2) / 2 + pow(z, 3) / 6);
        return a;
    }
};

int main() {
    setlocale(LC_CTYPE, "ukr");
    double x = 0.48 * 8;
    double y = 0.47 * 8;
    double z = -1.32 * 8;

    FunctionCalculator calculator(x, y, z);

    double b = calculator.calculateB();
    double a = calculator.calculateA();

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout <<endl<<"Çàâäàííÿ 2"<<endl<<endl;
    for (float i = -1; i <= 1; i += 0.2) {
        float x = i;

        FunctionCalculator AnotherCalculator(x, y, z);

        double b = AnotherCalculator.calculateB();
        double a = AnotherCalculator.calculateA();
        cout << "x = " << x << endl;
        cout << "a = " << a << endl;
        cout << "b = " << b << endl<<endl;
    }

    return 0;
}
