#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;

int findMinIndex(const vector<int>& arr) {
    return distance(arr.begin(), min_element(arr.begin(), arr.end()));
}

int sumBetweenNegatives(const vector<int>& arr) {
    auto firstNeg = find_if(arr.begin(), arr.end(), [](int x) { return x < 0; });
    if (firstNeg == arr.end()) return 0;

    auto secondNeg = find_if(firstNeg + 1, arr.end(), [](int x) { return x < 0; });
    if (secondNeg == arr.end()) return 0;

    return accumulate(firstNeg + 1, secondNeg, 0);
}

int sumOfSpecial(const vector<int>& arr) {
    int sum = 0;
    for (size_t i = 0; i < arr.size(); i++) {
        if (abs(arr[i]) <= 2) sum += arr[i];
    }
    return sum;
}

void customSort(vector<int>& arr) {
    stable_partition(arr.begin(), arr.end(), [](int x) { return abs(x) <= 1; });
}

int main() {

    vector<int> arr = { 2, -3, 5, 1, -4, 0, -1, 6, 1 };

    int minIndex = findMinIndex(arr) + 1;
    cout << "Номер мінімального елемента: " << minIndex << endl;

    int sum = sumBetweenNegatives(arr);
    cout << "Сума елементів між першими двома від’ємними елементами: " << sum << endl;

    cout << "Сума елементів, модуль яких менший або дорівнює 2: " 
         << sumOfSpecial(arr) << endl;

    customSort(arr);
    cout << "Перетворений масив: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
