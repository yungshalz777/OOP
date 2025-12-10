#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;
float PI = 3.14;

class Cube {
public:
    Cube(double side) : side(side) {} // constructor з параметром довж сторони

    double getVolume() const {
        return pow(side, 3);
    }

    double getSurfaceArea() const { 
        return 6 * pow(side, 2);
    }

    void info(ostream& out) const {
        out << "Куб: " << endl;
        out << " Сторона: " << side << endl;
        out << " Об’єм: " << getVolume() << endl;
        out << " Площа поверхні: " << getSurfaceArea() << endl;
    }

private:
    double side;
};

class Sphere {
public:
    Sphere(double radius) : radius(radius) {} // constructor з параметром радіусу

    double getVolume() const {
        return (4.0 / 3.0) * PI * pow(radius, 3);
    }

    double getSurfaceArea() const { // Обчислення площі поверхні сфери
        return 4 * PI * pow(radius, 2);
    }

    void info(ostream& out) const {
        out << "Сфера: " << endl;
        out << " Радіус: " << radius << endl;
        out << " Об’єм: " << getVolume() << endl;
        out << " Площа поверхні: " << getSurfaceArea() << endl;
    }

private:
    double radius;
};

class SphereInCube : public Cube, public Sphere {
public:
    SphereInCube(double side) : Cube(side), Sphere(side / 2) {} // Сфера вписана в куб (радіус = половина сторони куба)

    void info(ostream& out) const {
        Cube::info(out);
        Sphere::info(out);
    }
};

int main() {
    SphereInCube obj(10); //куб зі стороною 10
    ofstream fout("output.txt"); // open file для запису

    if (!fout) { // Перевірка чи файл відкрився
        cerr << "Не вдалося відкрити файл для запису." << endl;
        return 1;
    }

    obj.info(fout);
    fout.close();

    cout << "Інформація про об’єкт записана у файл output.txt" << endl;

    return 0;
}
