#include "BankAccount.hpp"
#include <cmath>
#include <iostream>
#include <stdexcept>

BankAccount::BankAccount() : BankAccount("Без имени", 0) {}

BankAccount::BankAccount(const std::string& owner, double balance)
    : owner(owner), balance(balance) {
    if (!std::isfinite(balance) || balance < 0) {
        throw std::invalid_argument("Баланс должен быть конечным и неотрицательным.");
    }
}

void BankAccount::Show() const {
    std::cout << *this << '\n';
}

BankAccount& BankAccount::operator+=(double amount) {
    *this = *this + amount;
    return *this;
}

BankAccount BankAccount::operator+(double amount) const {
    return BankAccount(owner, balance + amount);
}

BankAccount BankAccount::operator-(double amount) const {
    return *this + (-amount);
}

BankAccount BankAccount::operator*(double factor) const {
    return BankAccount(owner, balance * factor);
}

BankAccount BankAccount::operator/(double divisor) const {
    if (divisor == 0) {
        throw std::invalid_argument("Делить баланс на ноль нельзя.");
    }
    return BankAccount(owner, balance / divisor);
}

BankAccount& BankAccount::operator++() {
    return *this += 1;
}

BankAccount BankAccount::operator++(int) {
    BankAccount old(*this);
    ++(*this);
    return old;
}

BankAccount& BankAccount::operator--() {
    return *this += -1;
}

BankAccount BankAccount::operator--(int) {
    BankAccount old(*this);
    --(*this);
    return old;
}

bool BankAccount::operator>(const BankAccount& other) const {
    return balance > other.balance;
}

bool BankAccount::operator<(const BankAccount& other) const {
    return balance < other.balance;
}

bool BankAccount::operator==(const BankAccount& other) const {
    return balance == other.balance;
}

bool BankAccount::operator!=(const BankAccount& other) const {
    return !(*this == other);
}

std::istream& operator>>(std::istream& in, BankAccount& account) {
    std::string owner;
    double balance;
    if (in >> owner >> balance) {
        if (!std::isfinite(balance) || balance < 0) {
            in.setstate(std::ios::failbit);
        } else {
            account = BankAccount(owner, balance);
        }
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const BankAccount& account) {
    return out << account.owner << ", баланс " << account.balance << " руб.";
}
