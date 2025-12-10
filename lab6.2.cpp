#include <iostream>
#include <type_traits>
using namespace std;

template <typename T>
class Checksum {
public:
    static int calculate(T value) {
        static_assert(is_integral<T>::value, "Тип даних має бути цілочисельним.");
        int checksum = 0;
        while (value) {
            checksum += value & 1;   // Додаємо молодший біт
            value >>= 1;             // Зсуваємо число вправо
        }
        return checksum;
    }
};

int main() {
    int intValue = 4;
    char charValue = 25;
    long longValue = 42561231;

    cout << "Контрольна сума (int): " << Checksum<int>::calculate(intValue) << endl;
    cout << "Контрольна сума (char): " << Checksum<char>::calculate(charValue) << endl;
    cout << "Контрольна сума (long): " << Checksum<long>::calculate(longValue) << endl;

    return 0;
}
