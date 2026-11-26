#pragma once
#include <iosfwd>
#include <string>

class BankAccount {
private:
    std::string owner;
    double balance;

public:
    BankAccount();
    BankAccount(const std::string& owner, double balance);
    BankAccount(const BankAccount& other) = default;
    ~BankAccount() = default;

    void Show() const;

    BankAccount& operator=(const BankAccount& other) = default;
    BankAccount& operator+=(double amount);
    BankAccount operator+(double amount) const;
    BankAccount operator-(double amount) const;
    BankAccount operator*(double factor) const;
    BankAccount operator/(double divisor) const;

    BankAccount& operator++();
    BankAccount operator++(int);
    BankAccount& operator--();
    BankAccount operator--(int);

    bool operator>(const BankAccount& other) const;
    bool operator<(const BankAccount& other) const;
    bool operator==(const BankAccount& other) const;
    bool operator!=(const BankAccount& other) const;

    friend std::istream& operator>>(std::istream& in, BankAccount& account);
    friend std::ostream& operator<<(std::ostream& out, const BankAccount& account);
};
