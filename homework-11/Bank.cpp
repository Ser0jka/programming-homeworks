#include "Bank.hpp"

#include <iostream>
#include <stdexcept>

using namespace std;

WrongAccountTypeException::WrongAccountTypeException(const string& newMessage)
    : message(newMessage) {}

const char* WrongAccountTypeException::what() const noexcept {
    return message.c_str();
}

BankAccount::BankAccount(string newOwner, double newBalance) {
    if (newOwner.empty()) {
        throw invalid_argument("Имя владельца не может быть пустым");
    }
    if (newBalance < 0) {
        throw out_of_range("Баланс не может быть отрицательным");
    }

    owner = new string(newOwner);
    balance = new double(newBalance);
}

BankAccount::~BankAccount() {
    delete owner;
    delete balance;
}

string BankAccount::GetOwner() const {
    return *owner;
}

double BankAccount::GetBalance() const {
    return *balance;
}

SavingsAccount::SavingsAccount(string owner, double balance, double newRate)
    : BankAccount(owner, balance) {
    if (newRate < 0 || newRate > 100) {
        throw out_of_range("Ставка должна быть от 0 до 100 процентов");
    }
    rate = new double(newRate);
}

SavingsAccount::~SavingsAccount() {
    delete rate;
}

void SavingsAccount::SetRate(double newRate) {
    if (newRate < 0 || newRate > 100) {
        throw out_of_range("Ставка должна быть от 0 до 100 процентов");
    }
    *rate = newRate;
}

void SavingsAccount::Show() const {
    cout << "Сберегательный счёт: " << GetOwner()
         << ", баланс: " << GetBalance()
         << ", ставка: " << *rate << "%\n";
}

double SavingsAccount::CalcBenefit() const {
    return GetBalance() * *rate / 100;
}

PremiumAccount::PremiumAccount(string owner, double balance,
                               double newCashback)
    : BankAccount(owner, balance) {
    if (newCashback < 0 || newCashback > 100) {
        throw out_of_range("Кешбэк должен быть от 0 до 100 процентов");
    }
    cashback = new double(newCashback);
}

PremiumAccount::~PremiumAccount() {
    delete cashback;
}

void PremiumAccount::SetCashback(double newCashback) {
    if (newCashback < 0 || newCashback > 100) {
        throw out_of_range("Кешбэк должен быть от 0 до 100 процентов");
    }
    *cashback = newCashback;
}

void PremiumAccount::Show() const {
    cout << "Премиальный счёт: " << GetOwner()
         << ", баланс: " << GetBalance()
         << ", кешбэк: " << *cashback << "%\n";
}

double PremiumAccount::CalcBenefit() const {
    return 10000 * *cashback / 100;
}

BankClient::BankClient(BankAccount* newAccount) {
    account = newAccount;
}

BankClient::~BankClient() {
    delete account;
}

BankClient* BankClient::Create(int accountType) {
    if (accountType == 1) {
        return new BankClient(new SavingsAccount("Сергей", 80000, 7.5));
    }
    if (accountType == 2) {
        return new BankClient(new PremiumAccount("Сергей", 250000, 5));
    }

    throw invalid_argument("Тип счёта должен быть равен 1 или 2");
}

void BankClient::ChangeRate(double newRate) {
    SavingsAccount* savings = dynamic_cast<SavingsAccount*>(account);
    if (savings == nullptr) {
        throw WrongAccountTypeException(
            "Ставку можно изменить только у сберегательного счёта");
    }

    savings->SetRate(newRate);
}

void BankClient::ChangeCashback(double newCashback) {
    PremiumAccount* premium = dynamic_cast<PremiumAccount*>(account);
    if (premium == nullptr) {
        throw WrongAccountTypeException(
            "Кешбэк можно изменить только у премиального счёта");
    }

    premium->SetCashback(newCashback);
}

void BankClient::Show() const {
    account->Show();
    cout << "Выгода: " << account->CalcBenefit() << " руб.\n";
}
