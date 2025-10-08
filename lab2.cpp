#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
using namespace std;

class motor {
private:
    float V;
    float P;
    string ZavNomer;

public:

    motor(float volume, float power, string ZavodNomer)
        : V(volume), P(power), ZavNomer(ZavodNomer) {}


    float getVolume() const { return V; }
    string getZavodNomer() const { return ZavNomer; }
    float getPower() const { return P; }
    void setVolume(float vol) { V=vol; }
    void setPower(float pow) { P = pow; }
    void setZavodNomer(string num) { ZavNomer = num; }


    void info() const {
        cout << "Volume: " << V << ", Power: " << P
            << ", Nomer Zavoda: " << ZavNomer << endl;
    }
    
};
class automobil {
private:
   // motor Dvygun; 
    int NomerReg;
    string Marka;
    string Color;
public:
    motor Dvygun;
    automobil(int Nomer, string color, string marka, motor mot)
        : NomerReg(Nomer),Marka(marka),Color(color), Dvygun(mot){}

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

};
int main()
{
    motor Fiat(10,10,"Goyra");
    Fiat.info();
    Fiat.setPower(12);
    Fiat.info();
    motor Lambo(20, 10, "Cool");
    Lambo.info();
    automobil Skoda(1234,"Red","Skoda",Fiat);
    Skoda.info();
    bool option = 0;
    cout << "Do you want to change something?(1-yes,0-no): ";
    cin >> option;
    while (option = 0) {
        Skoda.setMotor(Lambo);
        cout << "Insert color: ";
        Skoda.setColor();
        cout << "Insert Registration Nomer: ";
        Skoda.setNomerReg();
        cout << "Insert marka: ";
        Skoda.setMarka();
        Skoda.info();
        cout << "Do you want to change something?(1-yes,0-no): ";
        cin >> option;
    }
}

