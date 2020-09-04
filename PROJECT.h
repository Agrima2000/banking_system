#include<iostream>
#include<string.h>
#include<iomanip>
#include<fstream>
#include<stdlib.h>
#include<windows.h>
using namespace std;
class BANK
{
	private:
		char AccHolder[20],FathersName[20],Address[50],AccType,email[20],state[20],con[20];
		int c,x,age,pin,AccNo,dd,mm,yy;
      long long int adhaar,MobNo;
      float NetBal,WithAmt,DepAmt;
		char gender;
	public:
	   BANK()
	   {
	      NetBal=0.00;
       }
		void Create();
		void showDetail();
		void Deposit(float);
		void Withdraw(float);
		void Modify(int);
		void report()const;
		int returnAccNo()const;
		int returnBal()const;

};

void BANK::Create()
{
	cout<<"\nAccount Holder Name : ";
	cin.ignore();
	gets(AccHolder);
	cout<<"\nFather's Name : ";
	cin.ignore();
	gets(FathersName);
	cout<<"\nDOB (dd/mm/yy) : ";
	cin>>dd>>mm>>yy;
	cout<<"\nAge : ";
	cin>>age;
	cout<<"\nGender M for 'Male' and F for 'Female' : ";
	cin.ignore();
	cin>>gender;
	cout<<"\nResidential Address : ";
	cin.ignore();
	gets(Address);
	cout<<"\nArea Pin Code : ";
	cin>>pin;
	cout<<"\nState : ";
	cin.ignore();
	gets(state);
	cout<<"\nNationality :";
	cin.ignore();
	gets(con);
	cout<<"\nContact Number : ";
	cin.ignore();
	cin>>MobNo;
	cout<<"\nEmail Address :";
	cin.ignore();
	gets(email);

	cout<<"\nProof of identification (any one)";

        cout<<"\nPress1: Adhaar Number"<<endl;
        cout<<"\nPress2: Driving License"<<endl;
        cout<<"\nPress3: Voter ID"<<endl;
        cout<<"\nPress4: exit"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>x;
        switch(x)
        {
            case 1:
                cout<<"Enter your unique identification number"<<endl;
                cin.ignore();
                cin>>adhaar;
            break;
            case 2:
                cout<<"Enter your DL no."<<endl;
                cin.ignore();
                cin>>adhaar;
            break;
            case 3:
                cout<<"Enter your voter_id no."<<endl;
                cin.ignore();
                cin>>adhaar;
            break;
            case 4:
                exit(0);
            break;
            default:
            cout<<"Invalid Choice"<<endl;
        }
   cin.ignore();
	cout<<"\nNew Account Number : ";
	cin>>AccNo;
	cout<<"\nType of account you wish to open : ";
	cin>>AccType;
}
void BANK::showDetail()
{
   cout<<"\n\t\t**********BANK DETAILS:**********"<<endl;
   cout<<"\n\t\tAccount Holder Name : "<<AccHolder<<endl;
   cout<<"\n\t\tFather's Name : "<<FathersName<<endl;
   cout<<"\n\t\tDOB : "<<dd<<"/"<<mm<<"/"<<yy<<endl;
	cout<<"\n\t\tAge : "<<age<<endl;
	cout<<"\n\t\tGender : "<<gender<<endl;
	cout<<"\n\t\tResidential Address : "<<Address<<endl;
	cout<<"\n\t\tPin Code : "<<pin<<endl;
	cout<<"\n\t\tState : "<<state<<endl;
	cout<<"\n\t\tNationality : "<<con<<endl;
	cout<<"\n\t\tContact Number : "<<MobNo<<endl;
	cout<<"\n\t\tEmail Address : "<<email<<endl;
	cout<<"\n\t\tNew Account Number : "<<AccNo<<endl;
	cout<<"\n\t\tAccount Type : "<<AccType<<endl;
	cout<<"\n\t\tAccount Balance : "<<NetBal<<endl;
	cout<<"\n\t\t....YOUR ACCOUNT HAS BEEN SUCESSFULLY CREATED....\n";
}
void BANK::Deposit(float DepAmt)
{
      strcpy(AccHolder,AccHolder);
      strcpy(FathersName,FathersName);
      dd=dd;mm=mm;yy=yy;
      age=age;
      gender=gender;
      strcpy(Address,Address);
      pin=pin;
      strcpy(state,state);
      strcpy(con,con);
      MobNo=MobNo;
      strcpy(email,email);
      adhaar=adhaar;
      AccType=AccType;
      NetBal=NetBal+DepAmt;
      cout<<"\nYour Account"<<AccNo<<" has credited an amount of "<<DepAmt<<endl;
      cout<<"\nCurrent balance is :"<<NetBal<<endl;
}

void BANK::Withdraw(float WithAmt)
{
   strcpy(AccHolder,AccHolder);
   strcpy(FathersName,FathersName);
   dd=dd;mm=mm;yy=yy;
   age=age;
   gender=gender;
   strcpy(Address,Address);
   pin=pin;
   MobNo=MobNo;;
   strcpy(email,email);
   adhaar=adhaar;
   AccType=AccType;
           if((WithAmt<NetBal)&&(NetBal>500))
           {
               NetBal=NetBal-WithAmt;
               cout<<AccNo<<" has withdrawn an amount of "<<WithAmt<<endl;
           }
           else
           {
               cout<<"\nYour account balance is low"<<endl;
           }
}

void BANK::Modify(int Acc)
{
    int c;

        cout<<"\nPress1: Change in Account Holder Name"<<endl;
        cout<<"\nPress2: Change in Date of Birth"<<endl;
        cout<<"\nPress3: Change of Address"<<endl;
        cout<<"\nPress4: Change in Contact No"<<endl;
        cout<<"\nPress5: Change in AccType"<<endl;
        cout<<"\nPress6: Exit"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>c;
        switch(c)
        {
            case 1:

            if(Acc==AccNo)
            {
                cout<<"\nEnter New account Holder Name : ";
                cin.ignore();
                gets(AccHolder);
                cout<<"\n......Account Holder Name has been successfully updated......"<<endl;
                cout<<"New Account Holder Name is:"<<AccHolder<<endl;
            }
            else
            cout<<"\nInvalid Account Number";

            break;

            case 2:

              if(Acc==AccNo)
            {
                cout<<"\nEnter Date of Birth: ";
                cin>>dd;cout<<"/";cin>>mm;cout<<"/";cin>>yy;
                cout<<"\n......Date of Birth has been successfully updated......"<<endl;
                cout<<"New DOB is:"<<dd<<"/"<<mm<<"/"<<yy<<endl;
            }
            else
            cout<<"\nInvalid Account Number";

            case 3:
            cout<<"\nEnter Account number : ";
            cin>>Acc;
            if(Acc==AccNo)
            {
                cout<<"\nEnter New Address : ";
                cin.ignore();
                gets(Address);
                cout<<"\n......Address has been successfully updated......";
            }
            else
            cout<<"\nInvalid Account Number";
            break;

             case 4:
            cout<<"\nEnter Account number : ";
            cin>>Acc;
            if(Acc==AccNo)
            {
                cout<<"\nEnter New Contact Number : ";
                cin>>MobNo;
                cout<<"\n......Contact Number has been successfully updated......";
            }
            else
            cout<<"\nInvalid Account Number";

            break;

             case 5:
            cout<<"\nEnter Account number : ";
            cin>>Acc;
            if(Acc==AccNo)
            {
                cout<<"\nWhich Account type you want (S or C): ";
                cin>>AccType;
                cout<<"\n......Account Type has been successfully updated......";
            }
            else
            {
                cout<<"\nInvalid Account Number";
            }
            break;

            case 6:
                exit(0);
            break;

            default:
            cout<<"Invalid Choice"<<endl;
        }

}

void BANK::report()const
{
    cout<<setw(8)<<AccNo<<setw(30)<<AccHolder<<setw(13)<<AccType<<setw(16)<<NetBal<<setw(20)<<endl;
}
int BANK::returnAccNo()const
{
    return AccNo;
}

int BANK::returnBal()const
{
    return NetBal;
}

