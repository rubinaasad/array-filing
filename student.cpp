// struct student.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include<fstream>
#include<cstring>
#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<conio.h>
#include<sstream>
using namespace std;

#pragma warning (disable: 4996)
const int Max=100;
int cur_size=0;
int rollNumber[Max];
char userName[Max][20];
double marks[Max][5];
char sFileName[32]="D:\\array.txt";
void input(int index)
{
	
	cout<<"Enter Roll NO: " ;
	cin>>rollNumber[index];
	cout<<"Enter First Name: ";
	cin.ignore();
	cin.getline(userName[index],20);
	cout<<"Enter Marks for 1.Differential Geometry \n 2.Linear algebra \n 3.Real Analysis \n 4.Programming \n 5.ODE : " <<endl;
	for(int i=0;i<5;i++)
	{
		cin>>marks[index][i];
	}


}

void output(int index)
{
	cout<<"\n" <<endl;
	cout<<"Roll NO: " <<rollNumber[index] <<endl;
	cout<<"First Name: " <<userName[index] <<endl;
	cout<<"Marks for 1.Differential Geometry \n 2.Linear algebra \n 3.Real Analysis \n 4.Programming \n 5.ODE : " <<endl;
	for(int i=0;i<5;i++)
	{
		cout<<marks[index][i] <<endl;
	}
}


void write_data()
{
	
	fstream f;
	f.open(sFileName,ios::out);
	if(!f.is_open())
	{
		cout<<"unable to open file..." <<endl;
	}

	if(Max>cur_size)
	{
		for(int i=0;i<cur_size;i++)
		{
		f<<rollNumber[i] <<" "<<userName[i] <<" ";
		for(int j=0;j<5;j++)
		{
			f<<marks[i][j]<<" ";
		}
		f<<endl;
		}
		
	}
	f.close();
	
}
void read_data()
{

	fstream f;
	f.open(sFileName,ios::in);
	if(f.is_open()==false)
	{
		cout<<"Unable to open file..." <<endl;
	}
	while(f.eof()==false)
	{
		if(f>>rollNumber[cur_size]>>userName[cur_size]>>marks[cur_size][0]>>marks[cur_size][1]>>marks[cur_size][2]>>marks[cur_size][3]>>marks[cur_size][4])
			cur_size++;
	}
	f.close();
}
void add_student()
{
	if(Max>cur_size)
	{
		input(cur_size);
		cur_size++;
		cout<<"Record added..." <<endl;
	}
	write_data();
	system("pause");
}


void display_all()
{
	for(int i=0;i<cur_size;i++)
	{
		output(i);
	}
	
	system("pause");
}
void search_student(int n)
{
	bool found=false;
	for(int i=0;i<cur_size;i++)
	{
		if(n==rollNumber[i])
		{
			output(i);
		found=true;
		break;
		}
	}
	if(found==false)
	cout<<"record not found..." <<endl;
	system("pause");
	
}


void modify_student(int n)
{
	bool found=false;
	for(int i=0;i<cur_size;i++)
	{
		if(n==rollNumber[i])
		{
			output(i);
			cout<<"update the record..." <<endl;
			input(i);
			found=true;
			break;
		
		}
	}
	write_data();
	if(found==false)
	cout<<"Record not found..." <<endl;
	system("pause");
}

void delete_student(int &cur_size,int n)
{
	bool flag=false;
	for (int i=0;i<cur_size;i++) 
	{
		if(n==rollNumber[i])
		{
			rollNumber[i]=rollNumber[i+1];
			strcpy(userName[i],userName[i+1]);
			marks[i][5]=marks[i+1][5];
			cur_size--;
			cout<<"Record deleted...";
			flag=true;
			break;
		}
		
	}
	write_data();
	if(flag==false)
		cout<<"Record not found..."<<endl;
	system("pause");
}

char menu()
{
	cout<<"\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout<<"\n\n\t1.CREATE STUDENT RECORD";
	cout<<"\n\n\t2.DISPLAY ALL STUDENTS RECORDS";
	cout<<"\n\n\t3.SEARCH STUDENT RECORD ";
	cout<<"\n\n\t4.MODIFY STUDENT RECORD";
	cout<<"\n\n\t5.DELETE STUDENT RECORD";
	cout<<"\n\n\t6. EXIT";
	cout<<"\n\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout<<"\n\n\tPlease Enter Your Choice (1-6): ";
	char choice;
	cin>>choice;
	return choice;
	system("pause");
}


int _tmain(int argc, _TCHAR* argv[])
{
	read_data();
	
	int num;
	char choice;
	cout.setf(ios::fixed|ios::showpoint);
	cout<<setprecision(2); 
	do
	{
		system("cls");
		choice=menu();
		system("cls");
		
		switch(choice)
		{
		case '1':	add_student();
			break;
		case '2':	display_all();
			break;
		case '3':	cout<<"\n\n\tPlease Enter Student's ID number: "; cin>>num;
			search_student(num);
			break;
		case '4':	cout<<"\n\n\tPlease Enter Student's ID number: "; cin>>num;
			modify_student(num);
			break;
		case '5':	cout<<"\n\n\tPlease Enter Student's ID number: "; cin>>num;
			delete_student(cur_size,num);
			break;
		case '6':	exit(0);;
		default:	cout<<"\a";
		}
	}while(choice!='6');
	
	return 0;
}

