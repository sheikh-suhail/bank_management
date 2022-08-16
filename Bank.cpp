#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctime>
using namespace std;

class Account
{
    long accNumber;
    string name;
    float balance;
    string password;

public:
    Account()
    {
        this->accNumber = 0;
        this->name = "";
        this->balance = 0;
        this->password = "";
    }
    Account(long acc, string n, float bal, string pas)
    {
        this->accNumber = acc;
        this->name = n;
        this->balance = bal;
        this->password = pas;
    }
    /*Account(Account &a)
    {
        this->accNumber = a.getAccNumber();
        this->name = a.getName();
        this->balance = a.getBalance();
        this->password=a.getPassword();
    }*/

    long getAccNumber()
    {
        return this->accNumber;
    }
    void setPassword(string pass)
    {
        this->password = pass;
    }
    string getPassword()
    {
        return this->password;
    }

    void setAccNumber(long accNumber)
    {
        this->accNumber = accNumber;
    }

    string getName()
    {
        return this->name;
    }

    void setName(string name)
    {
        this->name = name;
    }
    float getBalance()
    {
        return this->balance;
    }

    void setBalance(float balance)
    {
        this->balance = balance;
    }

    void addBalance(float b)
    {
        this->balance += b;
    }
};

class AccountList
{
    map<long, Account> accounts;

public:
    void addAccount(long acc, string name, float bal, string pass)
    {
        Account a(acc, name, bal, pass);
        accounts[acc] = a;
    }
    string Password(long acc)
    {
        if (accounts.find(acc) == accounts.end())
        {
            cout << "account does't exist" << endl;
            return "";
        }
        else
            return accounts[acc].getPassword();
    }

    void deleteAccount(long a)
    {
        if (accounts.find(a) == accounts.end())
        {
        }
        else
            accounts.erase(a);
    }

    float getBalance(long ac)
    {
        if (accounts.find(ac) == accounts.end())
        {
            return -1;
        }
        else
            return accounts[ac].getBalance();
    }

    bool transfer(long a1, long a2, float amt)
    {
        int bal = accounts[a1].getBalance();
        if (bal < amt)
        {
            cout << "Insufficient balence" << endl;
        }
        else
        accounts[a1].addBalance((-1)*amt);
        accounts[a2].addBalance(amt);
        return true;
    }

    int isPresent(long ac)
    {
        return accounts.find(ac) != accounts.end();
    }

    void addBalance(long ac, float b)
    {
        if (accounts.find(ac) == accounts.end())
        {
            cout << "account not present" << endl;
        }
        else{
            float bal = accounts[ac].getBalance();
            bal=bal+b;
            accounts[ac].setBalance(bal);
            }
    }

    void displayAccount(long ac)
    {

        if (accounts.find(ac) == accounts.end())
        {
            cout << "account not present" << endl;
        }
        else
        {
            cout << "------------Account details--------------------" << endl;
            cout << "ac number: " << accounts[ac].getAccNumber() << endl;
            cout << "name: " << accounts[ac].getName() << endl;
            cout << "balance: " << accounts[ac].getBalance() << endl;
            cout << "-----------------------------------------------" << endl;
        }
    }

    void displayAll()
    {
        for (auto it = accounts.begin(); it != accounts.end(); it++)
        {
            cout << "------------Account details--------------------" << endl;
            cout << "ac number: " << it->second.getAccNumber() << endl;
            cout << "name: " << it->second.getName() << endl;
            cout << "balance: " << it->second.getBalance() << endl;
            cout << "-----------------------------------------------" << endl;
        }
    }

    void chageName(long acc, string name)
    {
        if (accounts.find(acc) == accounts.end())
        {
            cout << "account not present" << endl;
        }
        else
            accounts[acc].setName(name);
    }
    void chagePassword(long acc, string pass)
    {
        if (accounts.find(acc) == accounts.end())
        {
            cout << "account not present" << endl;
        }
        else
            accounts[acc].setPassword(pass);
    }
    void chageBalence(long acc, float bal)
    {
        if (accounts.find(acc) == accounts.end())
        {
            cout << "account not present" << endl;
        }
        else
            accounts[acc].setBalance(bal);
    }
};

class Transaction
{
    string time;
    string type;
    string message;

public:
    Transaction(string time, string type,string message)
    {
        this->time = time;
        this->type = type;
        this->message=message;
    }
    void display()
    {
        cout << "____________________________________________" << endl;
        cout << time << endl;
        cout << type << endl;
        cout<<message<<endl;
        cout << "____________________________________________" << endl;
    }
    pair<string, string> getTransaction()
    {
        return make_pair(time, type);
    }
};
class TrancationList
{

    map<long, vector<Transaction>> list;

public:
    void addTransaction(long no, Transaction t)
    {
        list[no].push_back(t);
    }
    void displayAll(long acc)
    {
        for (auto it : list[acc])
        {
            it.display();
        }
    }
};

void admin(AccountList &Al, TrancationList &Tl)
{
    int condition = 0;
    while (condition != 6)
    {
        cout << "welcome ADMIN" << endl;
        cout << "choose the following please" << endl;
        cout << "press 1 to add account " << endl;
        cout << "press 2 to delete account " << endl;
        cout << "press 3 to check all account " << endl;
        cout << "press 4 to see password of account " << endl;
        cout << "press 5 to edit account " << endl;
        cout << "press 6 to exit" << endl;
        cin >> condition;
        if (condition == 1)
        {
            string n = "", p = "";
            long acc;
            float b;
            cout << "enter name" << endl;
            cin >> n;
            cout << "enter account number" << endl;
            cin >> acc;
            cout << "enter password" << endl;
            cin >> p;
            cout << "enter balance" << endl;
            cin >> b;
            Al.addAccount(acc, n, b, p);
        }
        if (condition == 2)
        {
            long acc = 0;
            cout << "enter account number" << endl;
            cin >> acc;
            Al.deleteAccount(acc);
        }
        if (condition == 3)
        {
            Al.displayAll();
        }
        if (condition == 4)
        {
            long acc;
            cout << "enter the account number" << endl;
            cin >> acc;
            cout << Al.Password(acc) << endl;
        }
        if (condition == 5)
        {
            long acc;
            cout << "enter the account number" << endl;
            cin >> acc;
            int num;
            cout << "choose the following please" << endl;
            cout << "press 1 to edit name " << endl;
            cout << "press 2 to edit balence " << endl;
            cout << "press 3 to edit password " << endl;
            cin >> num;
            if (num == 1)
            {
                string name = "";
                cout << "enter the new name" << endl;
                cin >> name;
                Al.chageName(acc, name);
            }
            else if (num == 2)
            {
                float bal;
                cout << "enter the new balence" << endl;
                cin >> bal;
                Al.chageBalence(acc, bal);
            }
            else if (num == 3)
            {
                string name = "";
                cout << "enter the new Password" << endl;
                cin >> name;
                Al.chagePassword(acc, name);
            }
            else
            {
                cout << "not a valid option" << endl;
            }
        }
        if (condition == 6)
        {
            condition = 6;
        }
    }
}

void customer(AccountList &Al, TrancationList &Tl)
{
    long acc;
    cout << "enter the account number" << endl;
    cin >> acc;
    if (Al.isPresent(acc) == false)
    {
        cout << "account not present" << endl;
        return;
    }
    string pass;
    cout << "enter the password" << endl;
    cin >> pass;
    int i = 3;
    while (Al.Password(acc) != pass && i > 0)
    {
        cout << "wrong password!!! enter again" << endl;
        cin >> pass;
        i--;
    }

    int condition = 0;
    while (condition != 3)
    {
        cout << "welcome CUSTOMER" << endl;
        cout << "choose the following please" << endl;
        cout << "press 1 to see account details" << endl;
        cout << "press 2 to see transaction history  " << endl;
        cout << "press 3 to exit" << endl;
        cin >> condition;
        if (condition == 1)
        {
            Al.displayAccount(acc);
        }
        if (condition == 2)
        {
            Tl.displayAll(acc);
        }
        if (condition == 3)
        {
            condition = 3;
        }
    }
}

void staff(AccountList &Al, TrancationList &Tl)
{
    int condition = 0;
    while (condition != 5)
    {
        cout << "welcome STAFF" << endl;
        cout << "choose the following please" << endl;
        cout << "press 1 to see transaction history  " << endl;
        cout << "press 2 to transfer " << endl;
        cout << "press 3 to withdraw " << endl;
        cout << "press 4 to deposit " << endl;
        cout << "press 5 to exit" << endl;
        cin >> condition;
        if (condition == 1)
        {
            long acc;
            cout << "enter the account number" << endl;
            cin >> acc;
            Tl.displayAll(acc);
        }
        if (condition == 2)
        {
            long senderaccountno, recieveraccountno;
            float amount;
            cout << "please enter  sender account number" << endl;
            cin >> senderaccountno;
            if (Al.isPresent(senderaccountno) == false)
            {
                cout << "account not present" << endl;
                return;
            }
            cout << "please enter  receiver account number" << endl;
            cin >> recieveraccountno;
            if (Al.isPresent(recieveraccountno) == false)
            {
                cout << "account not present" << endl;
                return;
            }
            cout << "please enter amount" << endl;
            cin >> amount;
            bool flag = Al.transfer(senderaccountno, recieveraccountno, amount);
            if (flag)
            {   time_t now = time(0);
                string str_time = ctime(&now);
                string msg1="RS ";
                msg1+=to_string(amount)+" was transferred to Ac no "+to_string(recieveraccountno);
                Transaction t1(str_time,"money Transfer",msg1);
                Tl.addTransaction(senderaccountno,t1);
                string msg2="RS ";
                msg2+=to_string(amount)+" was transferred from Ac no "+to_string(senderaccountno);
                Transaction t2(str_time,"money Tranfer",msg2);
                Tl.addTransaction(recieveraccountno,t2);
            }
        }
        if (condition == 3)  // withdraw
        {
            long  accountno = 0;
            float amount = 0;
            cout << "please enter account number" << endl;
            cin >> accountno;
            if (Al.isPresent(accountno) == false)
            {
                cout << "account not present" << endl;
                return;
            }
            cout << "please enter amount" << endl;
            cin >> amount;
            if(Al.getBalance(accountno)<amount)
            {
                cout<<"insufficient funds"<<endl;
            }
            else
            {
                Al.addBalance(accountno,(-1)*amount);
                time_t now = time(0);
                string str_time = ctime(&now);
                string msg1="RS ";
                msg1+=to_string(amount)+" was withdrawn ";
                Transaction t1(str_time,"money Withdrawal",msg1);
                Tl.addTransaction(accountno,t1);
            }
        }
        if (condition == 4)
        {
            long  accountno = 0;
            float amount = 0;
            cout << "please enter account number" << endl;
            cin >> accountno;
            if (Al.isPresent(accountno) == false)
            {
                cout << "account not present" << endl;
                return;
            }
            cout << "please enter amount" << endl;
            cin >> amount;
                Al.addBalance(accountno,amount);
                time_t now = time(0);
                string str_time = ctime(&now);
                string msg1="RS ";
                msg1+=to_string(amount)+" was deposited ";
                Transaction t1(str_time,"money Deposit",msg1);
                Tl.addTransaction(accountno,t1);
            
        }
        if (condition == 5)
        {
            condition = 5;
        }
    }
}
int main()
{
    AccountList Al;
    TrancationList Tl;
    int choice = 0;
    while (choice != 4)
    {
        cout << "_____________________________________________________" << endl;
        cout << "YOU want to login as:\t\t\t\t\t\t" << endl
             << endl;
        cout << "1-ADMIN" << endl;
        cout << "2-STAFF" << endl;
        cout << "3-CUSTOMER" << endl;
        cout << "4-exit" << endl;
        cout << "_____________________________________________________" << endl;
        cin >> choice;
        if (choice == 1)
        {
            admin(Al, Tl);
        }
        if (choice == 2)
        {
            staff(Al, Tl);
        }
        if (choice == 3)
        {
            customer(Al, Tl);
        }
        if (choice == 4)
        {
            choice = 4;
        }
    }

    return 0;
}