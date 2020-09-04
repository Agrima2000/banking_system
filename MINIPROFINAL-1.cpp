#include<iostream>
#include<string.h>
#include"PROJECT.h"
#include<iomanip>
#include<fstream>
#include<stdlib.h>
#include<windows.h>
using namespace std;

void write_acc()
{
	 BANK B;
	 fstream f;
    f.open("Banks.dat",ios::in|ios::app);
    B.Create();
    f.write((char *)&B,sizeof(BANK));
    f.close();
}

void display_acc(int n)
{
    int flag=0;
    BANK B;
	 fstream f;
    f.open("Banks.dat",ios::in|ios::out|ios::binary);
    if(!f)
    {
    	cout<<"\nFile Could Not Be Opened....Press 0 to exit.....";
    	exit(0);
	}
	f.seekg(0);
	f.read(reinterpret_cast<char *>(&B),sizeof(BANK));
	while(!f.eof())
    {
	if(B.returnAccNo()==n)
	{
	    flag=1;
		B.showDetail();
		f.read((char*)&B,sizeof(B));
	}

	f.read(reinterpret_cast<char *>(&B),sizeof(BANK));
    }
	f.close();
	if(flag==0)
	{
	  cout<<"\nRecord Not Found\n";
	}
}

void edit(int ino,int qty1, int op)
{
    BANK B;
    fstream file;
    file.open("Banks.dat",ios::in|ios::out);
    if(!file)
    {
        cout<<setw(10)<<"\n\t\tFile Not Found...\n";
    }
    file.seekg(0);
    while(file.read((char*)&B,sizeof(BANK)))
    {
        if(B.returnAccNo()==ino)
        {
            if(op==1)
            B.Withdraw(qty1);
            else if(op==2)
            B.Deposit(qty1);
            int pos=-1*sizeof(B);
            file.seekp(pos,ios::cur);
            file.write((char*)&B,sizeof(BANK));
        }
    }
}

void modify_acc(int n)
{
    BANK B;
    int pos=0;
    fstream f;
    f.open("Banks.dat",ios::in|ios::out|ios::binary);
    if(!f)
    {
    	cout<<"\nFile Could Not Be Opened.....Press 0 to exit.....\n";
    	exit(0);
	}
		while(f.read((char*)&B,sizeof(BANK)))
        {
            if(B.returnAccNo()==n)
            {
                B.showDetail();
                cout<<"enter new details";
                B.Modify(n);
                int pos=-1*sizeof(B);
                f.seekp(pos,ios::cur);
                f.write((char*)&B,sizeof(BANK));
            }
        }
		f.close();
}

void delete_acc(int n)
{
	BANK B;
    fstream f;
    f.open("Banks.dat",ios::in|ios::out|ios::binary);
    if(!f)
    {
    	cout<<"\nFile Could Not Be Opened.....Press 0 to exit.....\n";
    	exit(0);
	}
    ofstream f1;
    f1.open("Temp.dat",ios::out|ios::app);
    f.seekg(0,ios::beg);
    while(f.read((char*)(&B),sizeof(B)))
        {
            if(B.returnAccNo()!=n)
            {
                f1.write((char*)(&B),sizeof(B));
            }
        }
        f.close();
        f1.close();
        remove ("Banks.dat");
        rename("Temp.dat","Banks.dat");
        cout<<"\nRecord Deleted..\n";
}

void display_all()
{
	BANK B;
	fstream f;
    f.open("Banks.dat",ios::in|ios::out);
    if(!f)
    {
    	cout<<"\nFile Could Not Be Opened.....Press 0 to exit.....";
    	exit(0);
	}
    cout<<"\n\n\t\t\tACCOUNT HOLDER LIST\n\n";
    cout<<"*************************************************************************"<<endl;
    cout<<"    ACCOUNT NUMBER              NAME            TYPE          BALANCE\n";
    cout<<"*************************************************************************"<<endl;
    while(f.read(reinterpret_cast<char *>(&B),sizeof(B)))
    {
        B.report();
    }
    f.close();
}
void Withdraw1(int n)
{
	 BANK B;
	 float bal;
	 fstream f;
     f.open("Banks.dat",ios::in|ios::out);
     if(!f)
     {
    	cout<<"\nFile Could Not Be Opened.....Press 0 to exit.....";
    	exit(0);
     }
	f.read(reinterpret_cast<char *>(&B),sizeof(BANK));
	while(!f.eof())
    {
        if((B.returnAccNo())==n)
        {
          cout<<"Enter Amount : ";
          cin>>bal;
          edit(n,bal,1);
          display_acc(n);
        }
        f.read(reinterpret_cast<char *>(&B),sizeof(BANK));
    }
	f.close();
}

void deposit1(int n)
{
    BANK B;
    float bal;
    fstream f;
    f.open("Banks.dat",ios::in|ios::out);
    if(!f)
    {
    	cout<<"\nFile Could Not Be Opened.....Press 0 to exit.....";
    	exit(0);
	}
	f.read(reinterpret_cast<char *>(&B),sizeof(BANK));
	while(!f.eof())
    {
	if((B.returnAccNo())==n)
	{
       cout<<"Enter Amount : ";
	    cin>>bal;
       edit(n,bal,2);
       display_acc(n);
	}
    f.read(reinterpret_cast<char *>(&B),sizeof(BANK));
    }
    f.close();
}
main()
{
	int  op,num;
    do{
        system("cls");
        cout<<"\n\t\t*********WELCOME TO THE BANK OF DEHRADUN*******"<<endl;
        cout<<"\n\t\t1.  New Account"<<endl;
        cout<<"\n\t\t2.  Deposit"<<endl;
        cout<<"\n\t\t3.  Withdraw"<<endl;
        cout<<"\n\t\t4.  Balance Inquiry"<<endl;
        cout<<"\n\t\t5.  Complete Account Holder's List"<<endl;
        cout<<"\n\t\t6.  Close an Account"<<endl;
        cout<<"\n\t\t7.  Modify an Account"<<endl;
        cout<<"\n\t\t8.  Exit"<<endl;
        cout<<"\n\t\tSelect from options (1-8) : ";
        cin>>op;

        switch(op)
        {
        case 1:
            write_acc();
            break;
        case 2:
            cout<<"\nEnter Account Number:";	//DEPOSIT
            cin>>num;
            deposit1(num);
            break;
        case 3:
            cout<<"\nEnter Account Number:";	//WITHDRAw
            cin>>num;
            Withdraw1(num);
            break;
        case 4:
            cout<<"\nEnter Account Number:";	//display_acc
            cin>>num;
            display_acc(num);
            break;
        case 5:
            system("cls");
            display_all();
            break;
        case 6:
            cout<<"\nEnter Account Number:";	//delete_acc
            cin>>num;
            delete_acc(num);
            break;
        case 7:
            cout<<"\nEnter Account Number:";	//modify
            cin>>num;
            modify_acc(num);
            break;
        case 8:
            cout<<"\n\t\t********THANKS FOR VISITING********\n";
            exit(0);
            break;
        default:
            cout<<"\n\t\t********Wrong choice********\n";
        }
        cout<<"\nPress 0 to continue : ";
        cin>>op;
    }while(op==0);

}


