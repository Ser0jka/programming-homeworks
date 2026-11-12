#ifndef BANK_HPP
#define BANK_HPP

#include <exception>
#include <string>

// Собственный класс исключения.
class WrongAccountTypeException : public std::exception {
private:
    std::string message;

public:
    explicit WrongAccountTypeException(const std::string& newMessage);
    const char* what() const noexcept override;
};

class BankAccount {
private:
    std::string* owner;
    double* balance;

public:
    BankAccount(std::string newOwner, double newBalance);
    virtual ~BankAccount();

    std::string GetOwner() const;
    double GetBalance() const;
    virtual void Show() const = 0;
    virtual double CalcBenefit() const = 0;
};

class SavingsAccount : public BankAccount {
private:
    double* rate;

public:
    SavingsAccount(std::string owner, double balance, double newRate);
    ~SavingsAccount() override;

    void SetRate(double newRate);
    void Show() const override;
    double CalcBenefit() const override;
};

class PremiumAccount : public BankAccount {
private:
    double* cashback;

public:
    PremiumAccount(std::string owner, double balance, double newCashback);
    ~PremiumAccount() override;

    void SetCashback(double newCashback);
    void Show() const override;
    double CalcBenefit() const override;
};

class BankClient {
private:
    BankAccount* account;

public:
    explicit BankClient(BankAccount* newAccount);
    ~BankClient();

    static BankClient* Create(int accountType);
    void ChangeRate(double newRate);
    void ChangeCashback(double newCashback);
    void Show() const;
};

#endif
