#include <iostream>
#include <vector>
using namespace std;

class DepositOnlyAccout
{

public:
    virtual void deposit(double amnt) = 0;
};

class WithdrawOnlyAccout
{
public:
    virtual void withdraw(double amnt) = 0;
};

class SavingAccount : public WithdrawOnlyAccout,  DepositOnlyAccout
{
private:
    double balance;

public:
    SavingAccount()
    {
        balance = 0;
    }

    void deposit(double amnt) override
    {
        this->balance += amnt;
        cout << "Deposited: " << amnt << " in Savings Account. New Balance: " << balance << endl;
    }

    void withdraw(double amnt) override
    {
        if (balance >= amnt)
        {
            balance -= amnt;
            cout << "Withdrawn: " << amnt << " from Savings Account. New Balance: " << balance << endl;
        }
        else
        {
            cout << "Insufficient funds in Savings Account!\n";
        }
    }
};

class FixedDepositAccout : public DepositOnlyAccout
{
private:
    double balance = 0;

public:
    void deposit(double amnt) override
    {
        if (balance > 0)
        {
            balance += amnt;
            cout << "Deposited: " << amnt << " in Fixed Term Account. New Balance: " << balance << endl;
        }
    }
};

class Deposit
{
public:
    Deposit(SavingAccount *sav, double deposit_amnt)
    {

        sav->deposit(deposit_amnt);
    }

    Deposit(FixedDepositAccout *fix, double fit_depo_amnt, SavingAccount *sav, double sav_depo_amnt)
    {
        fix->deposit(fit_depo_amnt);
        sav->deposit(sav_depo_amnt);
    }
};

class withdraw
{
public:
    withdraw(SavingAccount *sav, double withdraw_amnt)
    {
        sav->withdraw(withdraw_amnt);
    }
};

int main()
{
    SavingAccount* sa1 = new SavingAccount();
    SavingAccount* sa2 = new SavingAccount();
    FixedDepositAccout* fa1 = new FixedDepositAccout();

    Deposit* depo1 = new Deposit(sa1, 600);
    Deposit* depo2 = new Deposit(fa1, 500, sa2, 400);
    withdraw* wit1 = new withdraw(sa1, 200);
   

    return 0;
}
