//**********************//
// HEADER FILES
//**********************//

#include<fstream>
#include "conio.h"
#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<iostream>
using namespace std;

//***************//
// CLASSES
//***************//

class book
{
	char bookno[6];
	char bookname[50];
	char authorname[20];
  public:
	void create_book()
	 {
		cout<<"\nNEW BOOK ENTRY...\n";
		cout<<"\nEnter The book no.";
		cin>>bookno;
		cout<<"\n\nEnter The Name of The Book ";
		cin>>bookname;
		cout<<"\n\nEnter The Author's Name ";
		cin>>authorname;
		cout<<"\n\n\nBook Created..";
	 }
	void show_book()
	 {
		cout<<"\nBook no. : ";
		cout<<bookno;
		cout<<"\nBook Name : ";
		puts(bookname);
		cout<<"Author Name : ";
		puts(authorname);
	 }

	void modify_book()
	 {
	 	cout<<"\nBook no. : "<<bookno;
		cout<<"\nModify Book Name : ";
		cin>>bookname;
		cout<<"\nModify Author's Name of Book:";
		cin>>authorname;
	 }
      char* returnbookno()
	 {
		return bookno;
	 }
      void report()
	 {
	  cout<<bookno<<setw(30)<<bookname<<setw(30)<<authorname<<endl;
	 }


};

class student
{
	char rollno[6];
	char name[20];
	char issuedbookno[6];
	int token;
  public:
	void create_student()
	 {
		cout<<"\nNEW STUDENT ENTRY...\n";
		cout<<"\nEnter The roll no. ";
		cin>>rollno;
		cout<<"\n\nEnter The Name of the student";
		cin>>name;
		token=0;
		issuedbookno[0]='\0';
		cout<<"\n\nStudent Record Created..";
	 }
      void show_student()
	 {
		cout<<"\nRoll no. : ";
		cout<<rollno;
		cout<<"\nStudent Name : ";
		puts(name);
		cout<<"\nNo of Book issued : "<<token;
		if(token==1)
		{
			cout<<"\nBook No "<<issuedbookno;
		}
	 }
      void modify_student()
	 {
	 	cout<<"\nRoll no. : "<<rollno;
		cout<<"\nModify Student Name : ";
		cin>>name;
	 }
      char* returnrollno()
	 {
		return rollno;
	 }
      char* returnissuedbookno()
	 {
		return issuedbookno;
	 }
      int returntoken()
	 {
		return token;
	 }
      void addtoken()
	 {
		token=1;
	 }
      void resettoken()
	 {
		token=0;
	 }
      void getissuedbookno(char t[])
	 {
		strcpy(issuedbookno,t);
	 }
      void report()
	 {
       cout<<"\t"<<rollno<<setw(20)<<name<<setw(10);
      cout<<token<<endl;
  }

};

//**********************************************************//
// FILE STREAM GLOBAL DECLARATION
//**********************************************************//

fstream fp,fp1;
book bk;
student st;

//**********************************************************//
// FUNCTIONS
//**********************************************************//

void write_book()
 {
	char ch;
	fp.open("book.dat",ios::out|ios::app);
	do
	 {
		bk.create_book();
		fp.write((char*)&bk,sizeof(book));
		cout<<"\n\n Do you want to add more record..(Enter y for yes /n for no?)";
		cin>>ch;
	 } while(ch=='y'||ch=='Y');
	fp.close();
 }
void write_student()
 {
	char ch;
	fp.open("student.dat",ios::out|ios::app);
	do
	{
		st.create_student();
		fp.write((char*)&st,sizeof(student));
		cout<<"\n\n Do you want to add more record..(Enter y for yes/n for no?)";
		cin>>ch;
	} while(ch=='y'||ch=='Y');
	fp.close();
 }

void displayspecificbook(char n[])
 {
	cout<<"\nBOOK DETAILS\n";
	int flag=0;
	fp.open("book.dat",ios::in);
	while(fp.read((char*)&bk,sizeof(book)))
	 {
		if(strcmp(bk.returnbookno(),n)==0)
		 {
			bk.show_book();
			flag=1;
		}
	 }
	fp.close();
	if(flag==0)
	 {
		cout<<"\n\nBook does not exist";
	 }
	cin.get();
 }
void displayspecificstudent(char n[])
 {
	cout<<"\nSTUDENT DETAILS\n";
	int flag=0;
	fp.open("student.dat",ios::in);
	while(fp.read((char*)&st,sizeof(student)))
	 {
		if((strcmp(st.returnrollno(),n)==0))
		 {
			st.show_student();
			flag=1;
		 }
	 }
	fp.close();
	if(flag==0)
	 {
		cout<<"\n\nStudent does not exist";
	 }
	cin.get();
 }


void modify_book()
 {
	char n[6];
	int found=0;
    cout<<"\n\n\t MODIFY BOOK RECORD.... ";
	cout<<"\n\n\tEnter The book no. of The book";
	cin>>n;
	fp.open("book.dat",ios::in|ios::out);
	while(fp.read((char*)&bk,sizeof(book)) && found==0)
	 {
		if(strcmp(bk.returnbookno(),n)==0)
		 {
			bk.show_book();
cout<<"\n Enter The New Details of book";   cout<<endl;
			bk.modify_book();
			int pos=(-1*sizeof(bk));
			fp.seekp(pos,ios::cur);
			fp.write((char*)&bk,sizeof(book));
			cout<<"\n\n\t Record Updated";
			found=1;
		}
	}
      fp.close();
	if(found==0)
	 {
		cout<<"\n\n Record Not Found ";
	 }
	cin.get();
 }

void modify_student()
 {
	char n[6];
	int found=0;
    cout<<"\n\n\tMODIFY STUDENT RECORD... ";
	cout<<"\n\n\tEnter The roll no. of The student";
	cin>>n;
	fp.open("student.dat",ios::in|ios::out);
	while(fp.read((char*)&st,sizeof(student)) && found==0)
	 {
		if(strcmp(st.returnrollno(),n)==0)
		 {
			st.show_student();
		      cout<<"\nEnter The New Details of  student";
			cout<<endl;
			st.modify_student();
			int pos=(-1*sizeof(st));
			fp.seekp(pos,ios::cur);
		      fp.write((char*)&st,sizeof(student));
			cout<<"\n\n\t Record Updated";
			found=1;
		 }
	 }
	fp.close();
	if(found==0)
	 {
		cout<<"\n\n Record Not Found ";
	 }
	cin.get();
 }

void delete_student()
 {
	char n[6];
	int flag=0;
	cout<<"\n\n\n\t...DELETE STUDENT...";
cout<<"\n\nEnter The roll no. of the Student you want to Delete : ";
	cin>>n;
	fp.open("student.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temp.dat",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&st,sizeof(student)))
	 {
		if(strcmp(st.returnrollno(),n)!=0)
		 {
			fp2.write((char*)&st,sizeof(student));
		 }
		else
		 {
			flag=1;
		 }
	 }
	fp2.close();
	fp.close();
	remove("student.dat");
	rename("Temp.dat","student.dat");
	if(flag==1)
	 {
		cout<<"\n\n\tRecord Deleted ..";
	 }
	else
	 {
		cout<<"\n\nRecord not found";
	 }
	cin.get();
 }
void delete_book()
 {
	char n[6];
system("clear");
	cout<<"\n\n\n\t...DELETE BOOK ...";
cout<<"\n\nEnter The Book no. of the Book You Want To ";        cout<<"Delete: ";
	cin>>n;
	fp.open("book.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temp.dat",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)& bk,sizeof(book)))
	 {
		if(strcmp(bk.returnbookno(),n)!= 0)
		 {
			fp2.write((char*)&bk,sizeof(book));
	 	 }
	 }
	fp2.close();
	fp.close();
	remove("book.dat");
	rename("Temp.dat","book.dat");
	cout<<"\n\n\tRecord Deleted ..";
	cin.get();
 }

void display_alls()
 {
system("clear");
	fp.open("student.dat",ios::in);
	if(!fp)
	 {
		cout<<"ERROR!!! FILE COULD NOT OPEN ";
		cin.get();
		return;
	 }
      cout<<"\n\n\t\tSTUDENT LIST\n\n";
cout<<"##############################################\n";
	cout<<"\tRoll No.";
	cout<<setw(10)<<"Name"<<setw(20)<<"Book Issued\n";
	cout<<"##############################################\n";
	while(fp.read((char*)&st,sizeof(student)))
	{
		st.report();
	}
	fp.close();
	cin.get();
}

void display_allb()
 {
system("clear");
	fp.open("book.dat",ios::in);
	if(!fp)
	 {
		cout<<"ERROR!!! FILE COULD NOT OPEN ";
		cin.get();
		return;
	 }
	cout<<"\n\n\t\tBook LIST\n\n";
	cout<<"##############################################\n";
	cout<<"Book Number"<<setw(20)<<"Book Name"<<setw(25);
	cout<<"Author\n";
	cout<<"##############################################\n";
	while(fp.read((char*)&bk,sizeof(book)))
	 {
		bk.report();
	 }
	fp.close();
	cin.get();
 }

void book_issue()
 {
	char sn[6],bn[6];
	int found=0,flag=0;
system("clear");
	cout<<"\n\n...ISSUE BOOK...";
	cout<<"\n\n\tEnter The student's roll no.";
	cin>>sn;
	fp.open("student.dat",ios::in|ios::out);
	fp1.open("book.dat",ios::in|ios::out);
	while(fp.read((char*)&st,sizeof(student))&& found==0)
	 {
	   if(strcmp(st.returnrollno(),sn)==0)
	    {
	      found=1;
	      if(st.returntoken()==0)
	       {
		   cout<<"\n\n\tEnter the book no. ";
		   cin>>bn;
		   while(fp1.read((char*)&bk,sizeof(book))&& flag==0)
		    {
			    if(strcmp(bk.returnbookno(),bn)==0)
			     {
			        bk.show_book();
			        flag=1;
			        st.addtoken();
			        st.getissuedbookno(bk.returnbookno());
			        int pos=(-1*sizeof(st));
			        fp.seekp(pos,ios::cur);
                         fp.write((char*)&st,sizeof(student));
  cout<<"\n\n\t Book issued successfully";
  cout<<"\n\nPlease Note: Write current date in backside of book and submit within 15 days\n. Fine of Rs.1 for each day will be taken after 15 days period";
			     }
		     }
		    if(flag==0)
		    {	   cout<<"Book no. does not exist";    }
	     }
	    else
	    {
		  cout<<"You have not returned the last book. Book can be issued only after returning the previous one.";
    }
       }
     if(found==0)
      {    cout<<"Student record not exist...";   }
     cin.get();
     fp.close();
     fp1.close();
 }}

void book_deposit()
{
	char sn[6],bn[6];
	int found=0,flag=0,day,fine;
system("clear");
	cout<<"\n\nBOOK DEPOSIT ...";
	cout<<"\n\n\tEnter The student's roll no.";
	cin>>sn;
	fp.open("student.dat",ios::in|ios::out);
	fp1.open("book.dat",ios::in|ios::out);
	while(fp.read((char*)&st,sizeof(student)) && found==0)
	 {
	  if(strcmp(st.returnrollno(),sn)==0)
	   {
	   found=1;
	   if(st.returntoken()==1)
	    {
		while(fp1.read((char*)&bk,sizeof(book))&& flag==0)
	      {
		   if(strcmp(bk.returnbookno(),st.returnissuedbookno())==0)
		    {
			bk.show_book();
			flag=1;
			cout<<"\n\nBook deposited in no. of days";
			cin>>day;
			if(day>15)
			 {
				 fine=(day-15)*1;
			       cout<<"\n\nFine has to deposited Rs";
				 cout<<fine;
			 }
			st.resettoken();
			int pos=(-1*sizeof(st));
			fp.seekp(pos,ios::cur);
			fp.write((char*)&st,sizeof(student));
		     cout<<"\n\n\t Book deposited successfully";
		    }
	      }
	     if(flag==0)
	      {
		    cout<<"Book no does not exist";
	      }
	     else
	      {
			cout<<"No book is issued..please check!!";
	      }
	   }
        }
      }
     if(found==0)
      cout<<"Student record not exist...";
     cin.get();
     fp.close();
     fp1.close();
   }

//******************************//
// INTRODUCTION FUNCTION
//******************************//

void intro()
 {
	system("clear");
	cout<<"LIBRARY MANAGEMENT SYSTEM";
	cout<<"\n\nMADE BY : G6 [HYDRA]";
	cout<<"\n\nTEAM MEMBERS:\nAMAN CHAUHAN 1805158\nARYAN MAHESHWARI 1805163\nGURJEET SINGH TATLA 1805174";
	cin.get();
 }

//*************************//
// ADMINISTRATOR MENU
//*************************//

void admin_menu()
 {
	int ch2;
	char num[6];
	cout<<"\n\n\n\t...ADMINISTRATOR MENU...";
	cout<<"\n\n\t1.CREATE STUDENT RECORD";
	cout<<"\n\n\t2.DISPLAY ALL STUDENTS RECORD";
	cout<<"\n\n\t3.DISPLAY SPECIFIC STUDENT RECORD ";
	cout<<"\n\n\t4.MODIFY STUDENT RECORD";
	cout<<"\n\n\t5.DELETE STUDENT RECORD";
	cout<<"\n\n\t6.CREATE BOOK ";
	cout<<"\n\n\t7.DISPLAY ALL BOOKS ";
	cout<<"\n\n\t8.DISPLAY SPECIFIC BOOK ";
	cout<<"\n\n\t9.MODIFY BOOK ";
	cout<<"\n\n\t10.DELETE BOOK ";
	cout<<"\n\n\t11.BACK TO MAIN MENU";
	cout<<"\n\n\tPlease Enter Your Choice (1-11): ";
	cin>>ch2;
	switch(ch2)
	 {
	 case 1:    system("clear");
			write_student();
			break;

	 case 2:    display_alls();
			break;

	 case 3:    	system("clear");
			cout<<"\n\n\tPlease Enter The roll no. ";
			cin>>num;
			displayspecificstudent(num);
			break;

	 case 4:    modify_student();
			break;

	 case 5:    delete_student();
			break;

	 case 6: 	system("clear");
			write_book();
			break;

	 case 7:    display_allb();
			break;

	 case 8:   system("clear");
			cout<<"\n\n\tPlease Enter The book No. ";
			cin>>num;
			displayspecificbook(num);
			break;

	 case 9:    modify_book();
			break;

	 case 10:   delete_book();
			break;

	 case 11: 	return;
			default:
			cout<<"\a";
	 }
	admin_menu();
 }

int main()
{
	char ch;
	intro();
	do
	{
		cout<<"\n\n\n\t MAIN MENU";
		cout<<"\n\n\t01. ADMINISTRATOR MENU";
		cout<<"\n\n\t02. BOOK ISSUE";
		cout<<"\n\n\t03. BOOK DEPOSIT";
		cout<<"\n\n\t04. EXIT";
		cout<<"\n\n\tPlease Select Your Option (1-4): ";
		cin>>ch;
		switch(ch)
		 {
			case '1':   system("clear");
				 	admin_menu();
					break;
			case '2':   book_issue();
				 	break;

			case '3':   book_deposit();
				 	break;

			case '4':   return 0;

			default :   cout<<"\a";
		 }
	 } while(ch!='4');
 }

//*****************//
// ENDGAME
//*****************//
