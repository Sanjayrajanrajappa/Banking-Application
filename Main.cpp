//Header:

#include <iostream>
#include <fstream>
#include <string>
using std::cout;
using std::cin;
using std::getline;
using std::ws;
using std::string;
using std::ifstream;
using std::ofstream;
using std::ios_base;
using std::endl;

//Functions

class Bank
{
    double balance;
public:
    Bank(double initialBalance)
    {
        balance = initialBalance;
    }
    double balance_check()
    {
        return balance;
    }
    void withdraw_amount(double amount)
    {
        if(amount>balance)
        {
            cout<<"\nInsufficient funds. Withdrawl failed!"<<endl;
        }
        else 
        {
            balance-=amount;
            cout<<amount<<" has been withdrawn from your account."<<endl;
            cout<<"\nRemaining balance is: "<<balance<<endl;
        }
    }
    void deposit_amount(double amount)
    {
        balance+=amount;
        cout<<amount<<" has been deposited in your account."<<endl;
        cout<<"\nRemaining balance is: "<<balance<<endl;
    }
};
//Main:

int main()
{
    //Initializations:

    int choice0,choice1;
    string name0,name1,password0,password1;
    double balance,balance0,balance1,withdraw,deposit;

    //Program:

    cout<<"Welcome to SAT Bank"<<endl;
    cout<<"\nWhat do you want to do?"<<endl;
    cout<<"Login (1) or Sign up (2): ";
    cin>>choice0;
    switch(choice0)
    {
        case 1:
        {
            cout<<"Enter Name: ";
            cin>>name1;
            cout<<"Enter Password: ";
            cin>>password1;
            ifstream readFile("login_details.data");
            while(readFile>>name0>>password0>>balance0)
            {
                if(name1 == name0 && password1 == password0)
                {
                    goto banking;
                }
                else
                {
                    cout<<"User not found!"<<endl;
                }
            }
        break;
        }
        case 2:
        {
            cout<<"Enter Name: ";
            cin>>name1;
            cout<<"Enter Password: ";
            cin>>password1;
            cout<<"Confirm Password: ";
            cin>>password1;
            cout<<"Enter Balance: ";
            cin>>balance1;
            ofstream writeFile("login_details.data",ios_base::app);
            writeFile<<'\n'<<name1<<' '<<password1<<' '<<balance1;
        break;
        }
        default:
            cout<<"Invalid Choice!"<<endl;
        break;
    }
    banking:
        Bank Account(balance0);
        do
        {
            cout<<"\nWhat do you want to do?";
            cout<<"\n1.Check Balance\n2.Withdraw Amount\n3.Deposit Amount\n4.Exit";
            cout<<"\nEnter Your Choice: ";
            cin>>choice1;
            switch(choice1)
            {
                case 1:
                {
                    cout<<"\nBalance: "<<Account.balance_check()<<endl;
                break;
                }
                case 2:
                {
                    cout<<"\nAmount To Be Withdrawn: ";
                    cin>>withdraw;
                    Account.withdraw_amount(withdraw);

                break;
                }
                case 3:
                {   
                    cout<<"\nAmount To Be Deposited: ";
                    cin>>deposit;
                    Account.deposit_amount(deposit);
                break;
                }
                case 4:
                {
                    cout<<"\nThank You For Choosing SAT BANK!";
                    cout<<"\n";
                break;
                }
                default:
                    cout<<"\nINVALID CHOICE!";
                break;
            }
        }while(choice1!=4);
    return 0;
}
