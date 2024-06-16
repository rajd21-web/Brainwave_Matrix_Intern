#include<iostream>
using namespace std;
class ATM{
    private:
        int balance;
        int pinCode,success;
    public:
       ATM(int bal,int pin){
            balance= bal;
            pinCode=pin;
}
int getBalance(){
    return balance;
}
int withdraw(int amount,int pin){
    if(pin !=pinCode){
    return false;
    }
    if(amount > balance){
        return false;
    }
    balance -= amount;
    return true;
}
void deposit(int amount){
    balance += amount;
}
int transfer(int amount, ATM receiver, int pin){

    if(pin!=pinCode){
        return false;
}
     success = withdraw(amount, pin);
     if(success){
        receiver.deposit(amount);
        return true;
     }
     else{
        return false;
     }
     
     }
};

int main(){

    ATM atm(1000,5678);             //Minimum balance and pin is already set 
    int choice,amount,success,pin;
    char op;
 do{
        cout<< "\n$$$$$$$$$$$$$$$$$$$$$$$$$$"
			<< " WELCOME to RAJ BANK "
			<< "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
        cout<<"1. View Balance"<<endl;
        cout<<"2. Cash Withdrawl"<<endl;
        cout<<"3. Cash Deposit"<<endl;
        cout<<"4. Cash Transfer"<<endl;
        cout<<"5. Exit"<<endl;
        cout<< "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"
            << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
		cout<<"Enter Your Choice : ";
		cin>>choice;
        switch(choice){
        case 1:
            cout<<"Your Balance : "<<atm.getBalance();
            break;
        case 2:
            cout<<"Your Available Balance : "<<atm.getBalance()<<endl;
            cout<<"Enter the Amount to Withdraw : ";
            cin>>amount;
            success = atm.withdraw(amount,5678);
            if(success){
                cout<<"Withdraw Successfull......"<<endl;
                }
                else{
                    cout<<"Insufficient Balance..."<<endl;
                    
                }cout<<"Your Available Balance : "<<atm.getBalance()<<endl;
                break;
        case 3:
        cout<<"Your Available Balance : "<<atm.getBalance()<<endl;
            cout<<"Enter the Amount to Deposit : ";
            cin>>amount;
            atm.deposit(amount);
            cout<<"Deposit Successfull...."<<endl;
            cout<<"Your Available Balance : "<<atm.getBalance()<<endl;
            break;
        case 4:
             cout<<"Your Available Balance : "<<atm.getBalance()<<endl;
            cout<<"Enter the Amount to Transfer : ";
            cin>>amount;
            cout<<"Enter Security Code : ";
            cin>>pin;
            success= atm.transfer(amount,atm,pin);
            if(success){
                cout<<"Transferred Successfully....."<<endl;
            }
            else{
                cout<<"Invalid pin or Insufficient Balance"<<endl;
                cout<<"Your Available Balance : "<<atm.getBalance()<<endl;
            }cout<<"Your Available Balance : "<<atm.getBalance()<<endl;
            break;
        case 5:  
            cout<<"Thanks for using ATM of RAJ BANK\n               Visit Again......"<<endl;
            exit(1);
            break;
            default:
            cout<<"Invalid Choice"<<endl;
        }
        cout<<"\nDo you want to try another transaction [Yes(Y) / No(N)] :";
        cin>>op;
        }while(op=='Y'||op=='y');
   if(op=='N'||op=='n'){
            cout<<"\nThanks for using ATM of RAJ BANK\n               Visit Again......"<<endl;
   }
   }
 
   
