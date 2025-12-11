#include <iostream>
#include <cmath>

using namespace std;

class Shape {
public:
    //  віртуальна функція — кожна фігура визначає свій обʼєм
    virtual double getVolume() const = 0;

    // Віртуальний деструктор 
    virtual ~Shape() {}
};

class Parallelepiped : public Shape {
private:
    double a, b, c;
public:
    Parallelepiped(double a, double b, double c) : a(a), b(b), c(c) {}

    double getVolume() const override {
        return a * b * c;
    }
};

class Pyramid : public Shape {
private:
    double a, b, h;
public:
    Pyramid(double a, double b, double h) : a(a), b(b), h(h) {}

    double getVolume() const override {
        return (a * b * h) / 3.0;
    }
};

class Sphere : public Shape {
private:
    double r;
public:
    Sphere(double r) : r(r) {}

    double getVolume() const override {
        return (4.0 / 3.0) * M_PI * pow(r, 3);
    }
};

class Tetrahedron : public Shape {
private:
    double a;
public:
    Tetrahedron(double a) : a(a) {}

    double getVolume() const override {
        return pow(a, 3) / (6 * sqrt(2));
    }
};

int main() {

    Shape* shape; // Один вказівник основа поліморфізму

    shape = new Parallelepiped(3, 4, 5);
    cout << "Об'єм паралелепіпеда: " << shape->getVolume() << endl;
    delete shape;

    shape = new Pyramid(3, 4, 5);
    cout << "Об'єм піраміди: " << shape->getVolume() << endl;
    delete shape;

    shape = new Sphere(3);
    cout << "Об'єм кулі: " << shape->getVolume() << endl;
    delete shape;

    shape = new Tetrahedron(3);
    cout << "Об'єм тетраедра: " << shape->getVolume() << endl;
    delete shape;

    return 0;
}
