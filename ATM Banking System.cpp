#include<iostream>
#include<fstream>
using namespace std;

char name[100],actype[100];
int bal,amt,pin,acno;
class Bank
{
    private:


    Bank()

   {
           cout<<"\n\n\n\n\t\t\t\t\t\t-----Welcome to AB Bank-----\n"<<endl;

           cout<<"\t\t\t\tEnter Account Name: ";
           cin>>name;

           cout<<"\t\t\t\tEnter Account Type: ";
           cin>>actype;

           cout<<"\t\t\t\tEnter Account No: ";
           cin>>acno;

           cout<<"\t\t\t\tEnter Opening Balance: ";
           cin>>bal;

           cout<<"\t\t\t\tEnter your pin: ";
           cin>>pin;

   }
     friend class Display_Details;

};

class Display_Details : public Bank
{
    public:
      void display()
      {
           cout<<"\n\t\t\t\t\t\tAccount Name: "<<name<<endl;

           cout<<"\t\t\t\t\t\tAccount Type: "<<actype<<endl;

           cout<<"\t\t\t\t\t\tAccount No: "<<acno<<endl;

           cout<<"\t\t\t\t\t\tCurrent Balance: "<<bal<<endl;

           cout<<"\t\t\t\t\t\tPin: "<<pin<<endl;

      }
};

class Deposit

{
     public:
       void display(int t)
       {
           amt=t;
           bal=bal+amt;
           cout<<"\n\t\t\t\t\t\tBalance After Deposit: "<<bal<<endl;
           cout<<"\t\t\t\t\t\t-----Thanks for being with AB Bank-----"<<endl;
           ofstream file;
          file.open("Account.txt",ios::out|ios::trunc);
          file<<name<<endl;
          file<<actype<<endl;
          file<<acno<<endl;
          file<<bal<<endl;
          file<<pin<<endl;
          file.close();

       }

};

class Withdraw
{
      public:
       void display(int a)
       {
           amt=a;
           if(amt>bal)
           cout<<"\t\t\t\t\t\t\tSorry your balance is less than amount..."<<endl;
           else
              {
                  bal=bal-amt;
                  cout<<"\n\t\t\t\t\t\tBalance after withdraw: "<<bal<<endl;
                  cout<<"\t\t\t\t\t\t-----Thanks for being with AB Bank-----"<<endl;
                  ofstream file;
                 file.open("Account.txt",ios::out|ios::trunc);
                 file<<name<<endl;
                 file<<actype<<endl;
                 file<<acno<<endl;
                 file<<bal<<endl;
                 file<<pin<<endl;
                 file.close();

              }
       }
};
class  Bill_Payment
{
    public:
       void display(int b)
       {
            amt=b;
           if(amt>bal)
           cout<<"\t\t\t\t\t\t\tSorry you don't have sufficient balance for making this payment"<<endl;
           else
              {
                  bal=bal-amt;
                  cout<<"\t\t\t\t\t\tBalance after payment: "<<bal<<endl;
                  cout<<"\t\t\t\t\t\t-----Thanks for being with AB Bank-----"<<endl;
                  ofstream file;
                file.open("Account.txt",ios::out|ios::trunc);
                file<<name<<endl;
                file<<actype<<endl;
                file<<acno<<endl;
                file<<bal<<endl;
                file<<pin<<endl;
                file.close();

              }
       }
};
class Change_Pin
{
      protected:
    int p;


};
class sub_pin:public Change_Pin

{

    public:
    void display(int p)

    {
          pin=p;
          cout<<"\t\t\t\t\t\tYour pin has changed successfully"<<endl;
          cout<<"\t\t\t\t\t\t-----Thanks for being with AB Bank-----"<<endl;
      ofstream file;
      file.open("Account.txt",ios::out|ios::trunc);
      file<<name<<endl;
      file<<actype<<endl;
      file<<acno<<endl;
      file<<bal<<endl;
      file<<pin<<endl;
      file.close();

       }
};


int main()
{
    system("color 47");
    Deposit d;
    Withdraw w;
    Bill_Payment bi;
    sub_pin c;
    Display_Details dd;

    int amount, choice,Pin;

   ofstream file;
   file.open("Account.txt",ios::out|ios::trunc);
   file<<name<<endl;
   file<<actype<<endl;
   file<<acno<<endl;
   file<<bal<<endl;
   file<<pin<<endl;
   file.close();

    do

      {
          cout<<"\n\t\t\t\t\t\t\t---------Main Menu---------\n"<<endl;

          cout<<"\t\t\t\t\t\t1:- Deposit Money"<<endl;

          cout<<"\t\t\t\t\t\t2:- Withdraw Money"<<endl;

          cout<<"\t\t\t\t\t\t3:- Bill Payment"<<endl;

          cout<<"\t\t\t\t\t\t4:- Pin Change"<<endl;

          cout<<"\t\t\t\t\t\t5:- Display Details"<<endl;

          cout<<"\t\t\t\t\t\t6:- Quit"<<endl;

          cout<<"\t\t\t\t\t\tEnter any Choice:";

          cin>>choice;

          switch (choice)
              {
                  case 1:
                  cout<<"\t\t\t\t\t\tEnter amount to deposit: ";
                  cin>>amount;
                  d.display(amount);
                  break;

                  case 2:
                  cout<<"\t\t\t\t\t\tEnter amount to withdraw: ";
                  cin>>amount ;
                  w.display(amount) ;
                  break ;

                  case 3:
                  cout<<"\t\t\t\t\t\tEnter amount to pay bill: ";
                  cin>>amount ;
                  bi.display(amount) ;
                  break ;

                  case 4:
                  cout<<"\t\t\t\t\t\tEnter your new pin: ";
                  cin>>Pin;
                  c.display(Pin);
                  break ;

                  case 5:
                  dd.display();
                  break;

                  case 6:
                  exit (0);




            }




       }
      while(1);

}
