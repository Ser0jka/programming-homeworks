#include "BankAccount.hpp"
#include <iostream>
#include <stdexcept>

int main() {
    BankAccount account;
    const BankAccount other("Петров", 1000);

    std::cout << "Счёт по умолчанию: ";
    account.Show();
    std::cout << "Введите фамилию и баланс через пробел: ";
    if (!(std::cin >> account)) {
        std::cout << "Ошибка: введите фамилию и неотрицательный баланс.\n";
        return 1;
    }

    BankAccount copy(account);  // Конструктор копирования.
    BankAccount assigned;
    assigned = other;
    std::cout << "\nКопия: " << copy << "\nПосле присваивания: " << assigned << '\n';

    // Для арифметики используем счёт с известным начальным балансом.
    std::cout << "\nother + 200: " << (other + 200)
              << "\nother - 200: " << (other - 200)
              << "\nother * 2: " << (other * 2)
              << "\nother / 2: " << (other / 2) << '\n';
    copy += 100;
    std::cout << "Копия после += 100: " << copy << '\n';

    BankAccount counter(other);
    std::cout << "\n++counter: " << ++counter << '\n';
    std::cout << "counter++: " << counter++ << '\n';
    std::cout << "После counter++: " << counter << '\n';
    std::cout << "--counter: " << --counter << '\n';
    std::cout << "counter--: " << counter-- << '\n';
    std::cout << "После counter--: " << counter << '\n';

    std::cout << "\nСравнение с балансом 1000 руб.\n" << std::boolalpha
              << "account > other: " << (account > other) << '\n'
              << "account < other: " << (account < other) << '\n'
              << "account == other: " << (account == other) << '\n'
              << "account != other: " << (account != other) << '\n';

    try {
        std::cout << (other / 0) << '\n';
    } catch (const std::invalid_argument& error) {
        std::cout << error.what() << '\n';
    }
}
