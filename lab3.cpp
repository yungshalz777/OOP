#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include <stdexcept>
#include <limits>

using namespace std;

class motor {
private:
    float V;
    float P;
    string ZavNomer;
public:
    motor(float volume, float power, string ZavodNomer)
        : V(volume), P(power), ZavNomer(ZavodNomer) {}

    void operator+=(const float dv) {
        P += dv;
    }

    float getVolume() const { return V; }
    string getZavodNomer() const { return ZavNomer; }
    float getPower() const { return P; }

    void setVolume(float vol) { V = vol; }
    void setPower(float pow) { P = pow; }
    void setZavodNomer(string num) { ZavNomer = num; }

    void info() const {
        cout << "Volume: " << V << ", Power: " << P
            << ", Nomer Zavoda: " << ZavNomer << endl;
    }
};

class automobil {
private:
    int NomerReg;
    string Marka;
    string Color;
public:
    motor Dvygun;

    automobil(int Nomer, string color, string marka, motor mot)
        : NomerReg(Nomer), Marka(marka), Color(color), Dvygun(mot) {}

    void setMotor(motor mot) {
        Dvygun = mot;
    }

    void setMarka() {
        cin >> Marka;
    }

    void setColor() {
        cin >> Color;
    }

    void setNomerReg() {
        cin >> NomerReg;
    }

    int getNomerReg() {
        return NomerReg;
    }

    string getColor() {
        return Color;
    }

    string getMarka() {
        return Marka;
    }

    void info() {
        cout << "Marka: " << Marka << ", Color: " << Color
            << ", Registration Nomer: " << NomerReg << endl;
        cout << "Motor: ";
        Dvygun.info();
    }

    void search(int s) {
        if (s == NomerReg)
            cout << "value is found!" << endl;
        else
            cout << "Value is not found!" << endl;
    }

    void search(float s, int c) {
        switch (c) {
        case(1): {
            if (s == Dvygun.getPower())
                cout << "value is found!" << endl;
            else
                cout << "Value is not found!" << endl;
            break;
        }
        case(2): {
            if (s == Dvygun.getVolume())
                cout << "value is found!" << endl;
            else
                cout << "Value is not found!" << endl;
            break;
        }
        }
    }

    void search(string s, int c) {
        switch (c) {
        case(1): {
            if (s._Equal(Color))
                cout << "value is found!" << endl;
            else
                cout << "Value is not found!" << endl;
            break;
        }
        case(2): {
            if (s._Equal(Marka))
                cout << "value is found!" << endl;
            else
                cout << "Value is not found!" << endl;
            break;
        }
        case(3): {
            if (s._Equal(Dvygun.getZavodNomer()))
                cout << "value is found!" << endl;
            else
                cout << "Value is not found!" << endl;
            break;
        }
        }
    }

    void SearchChoose() {
        cout << "insert value to search(1-nomer of registration, 2-color, 3-marka, 4-power, 5-volume, 6-zavod nomer)" << endl;
        int opt;
        try {
            cin >> opt;
            if (cin.fail()) {
                throw invalid_argument("Invalid input for search option");
            }
        }
        catch (const invalid_argument& e) {
            cin.clear();
            cin.ignore(10000, '\n'); // Çàì³ñòü numeric_limits<streamsize>::max()
            cout << e.what() << endl;
            return;
        }

        switch (opt) {
        case(1): {
            int s;
            try {
                cout << "insert value:";
                cin >> s;
                if (cin.fail()) {
                    throw invalid_argument("Invalid input for registration number");
                }
            }
            catch (const invalid_argument& e) {
                cin.clear();
                cin.ignore(10000, '\n'); // Çàì³ñòü numeric_limits<streamsize>::max()
                cout << e.what() << endl;
                break;
            }
            search(s);
            break;
        }
        case(2): {
            string s;
            cout << "insert value:";
            cin >> s;
            search(s, 1);
            break;
        }
        case(3): {
            string s;
            cout << "insert value:";
            cin >> s;
            search(s, 2);
            break;
        }
        case(4): {
            float s;
            try {
                cout << "insert value:";
                cin >> s;
                if (cin.fail()) {
                    throw invalid_argument("Invalid input for power");
                }
            }
            catch (const invalid_argument& e) {
                cin.clear();
                cin.ignore(10000, '\n'); // Çàì³ñòü numeric_limits<streamsize>::max()
                cout << e.what() << endl;
                break;
            }
            search(s, 1);
            break;
        }
        case(5): {
            float s;
            try {
                cout << "insert value:";
                cin >> s;
                if (cin.fail()) {
                    throw invalid_argument("Invalid input for volume");
                }
            }
            catch (const invalid_argument& e) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << e.what() << endl;
                break;
            }
            search(s, 2);
            break;
        }
        case(6): {
            string s;
            cout << "insert value:";
            cin >> s;
            search(s, 3);
            break;
        }
        default: {
            cout << "invalid search value option" << endl;
            break;
        }
        }
    }

    friend istream& operator>>(istream& is, automobil& p) {
        cout << "Insert Marka: ";
        is >> p.Marka;
        cout << "Insert reg nomer: ";
        is >> p.NomerReg;
        cout << "Insert color: ";
        is >> p.Color;
        return is;
    }

    friend ostream& operator<<(ostream& os, const automobil& p) {
        os << "Color: " << p.Color << "\n"
            << "Reg Nomer: " << p.NomerReg << "\n"
            << "Marka: " << p.Marka << "\n"
            << "Power: " << p.Dvygun.getPower() << "\n"
            << "Volume: " << p.Dvygun.getVolume() << "\n"
            << "Nomer Zavoda: " << p.Dvygun.getZavodNomer() << "\n";
        return os;
    }
};

int main() {
    motor Fiat(10, 10, "Fatta");
    Fiat.info();
    Fiat += 2;
    Fiat.info();
    motor Lambo(20, 15, "Cool");
    Lambo.info();
    automobil Skoda(1234, "Red", "Skoda", Fiat);
    cout << Skoda;
    bool option = 0;
    cout << "Do you want to change something?(1-yes,0-no): ";
    cin >> option;
    while (option != 0) {
        Skoda.setMotor(Lambo);
        cin >> Skoda;
        cout << Skoda;
        cout << "Do you want to change something?(1-yes,0-no): ";
        cin >> option;
    }
    Skoda.SearchChoose();
}
