#include <iostream>
#include <list>
#include <string>
#include <stdexcept>
using namespace std;

struct Product {
    string id;
    int quantity;
};

void addProduct(list<Product>& stock, const string& id, int quantity) {
    for (auto& product : stock) {
        if (product.id == id) {
            product.quantity += quantity;
            return;
        }
    }
    stock.push_back({ id, quantity });
}

void processOrders(list<Product>& stock, list<Product>& orders) {
    for (auto it = orders.begin(); it != orders.end(); ) {
        auto stockIt = find_if(stock.begin(), stock.end(), [&it](const Product& product) {
            return product.id == it->id;
        });

        if (stockIt != stock.end() && stockIt->quantity >= it->quantity) {
            stockIt->quantity -= it->quantity;
            it = orders.erase(it);
        } else {
            ++it;
        }
    }
}

void displayStock(const list<Product>& stock) {
    cout << "Асортимент на складі:" << endl;
    for (const auto& product : stock) {
        cout << "ID: " << product.id << ", Кількість: " << product.quantity << endl;
    }
}

void displayOrders(const list<Product>& orders) {
    cout << "Замовлення:" << endl;
    for (const auto& order : orders) {
        cout << "ID: " << order.id << ", Кількість: " << order.quantity << endl;
    }
}

int main() {
    list<Product> stock = { {"A001", 10}, {"A002", 5}, {"A003", 20} };
    list<Product> orders = { {"A001", 3}, {"A003", 15}, {"A002", 6} };

    bool error = true;
    cout << "До додавання нових виробів:" << endl;
    displayStock(stock);
    displayOrders(orders);

    bool option = false;

    // Додавання нових виробів
    while (true) {
        cout << "Для додавання нових виробів натисніть 1, інакше — 0: ";
        cin >> option;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Помилка вводу." << endl;
            continue;
        }
        if (!option) break;

        string id;
        int quantity;

        cout << "Введіть код товару: ";
        cin >> id;

        while (true) {
            cout << "Введіть кількість даного товару: ";
            cin >> quantity;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Помилка вводу." << endl;
            } else break;
        }

        addProduct(stock, id, quantity);
    }

    cout << "\nПісля додавання нових виробів:" << endl;
    displayStock(stock);

    // Додавання нових замовлень
    while (true) {
        cout << "Для додавання нових замовлень натисніть 1, інакше — 0: ";
        cin >> option;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Помилка вводу." << endl;
            continue;
        }
        if (!option) break;

        string id;
        int quantity;

        cout << "Введіть код товару: ";
        cin >> id;

        while (true) {
            cout << "Введіть кількість даного товару: ";
            cin >> quantity;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Помилка вводу." << endl;
            } else break;
        }

        addProduct(orders, id, quantity);
    }

    processOrders(stock, orders);

    cout << "\nПісля обробки замовлень:" << endl;
    displayStock(stock);
    displayOrders(orders);

    return 0;
}
