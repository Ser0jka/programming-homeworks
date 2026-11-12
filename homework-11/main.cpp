#include "Bank.hpp"

#include <clocale>
#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    setlocale(LC_ALL, "");

    BankClient* savingsClient = BankClient::Create(1);
    BankClient* premiumClient = BankClient::Create(2);

    cout << "Обычная работа программы\n";
    savingsClient->ChangeRate(10);
    premiumClient->ChangeCashback(8);
    savingsClient->Show();
    premiumClient->Show();

    cout << "\n1. Проверка invalid_argument\n";
    try {
        BankClient* wrongClient = BankClient::Create(3);
        delete wrongClient;
    } catch (const invalid_argument& error) {
        cout << "Исключение обработано: " << error.what() << '\n';
    }

    cout << "\n2. Проверка out_of_range\n";
    try {
        savingsClient->ChangeRate(150);
    } catch (const out_of_range& error) {
        cout << "Исключение обработано: " << error.what() << '\n';
    }

    cout << "\n3. Проверка собственного класса исключения\n";
    try {
        savingsClient->ChangeCashback(5);
    } catch (const WrongAccountTypeException& error) {
        cout << "Исключение обработано: " << error.what() << '\n';
    }

    delete savingsClient;
    delete premiumClient;
    return 0;
}
