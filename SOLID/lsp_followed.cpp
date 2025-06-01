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
    
    private:
   
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

class DepositForSaving :public SavingAccount
{
public:
    void deposit(SavingAccount *sav, double deposit_amnt)
    {

        sav->deposit(deposit_amnt);
    }
   
   
};

class DepositForFix_Saving : public DepositForSaving{

 DepositForFix_Saving( FixedDepositAccout *fix, double fix_depo_amnt,SavingAccount *sav, double sav_depo_amnt){
    fix->deposit(fix_depo_amnt);
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

//    DepositForSaving* ds = new DepositForSaving(); 
//    ds->deposit(sa1,2000);
   
   FixedDepositAccout* fd1 = new FixedDepositAccout();
   DepositForFix_Saving* dfs = new DepositForFix_Saving(fd1,6500,sa2,45000);
   
 
 
    return 0;
}
