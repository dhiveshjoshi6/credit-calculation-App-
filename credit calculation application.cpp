//header files
#include<iostream>
#include<conio.h>
#include<string>

#include<stdlib.h>
#include"windows.h"
using namespace std;

//function definition for setting cursor position in the console window
void gotoxy(int x, int y)
{
COORD coord;
coord.X=x;
coord.Y=y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
//class definition
class applicant
{
//data member for string the info of the applicants
string name;
int age;
string address;
int m_sal;
int h_loan;
int p_loan;
int no_chq_bounce;
int own_house;
char spouse_working;
char dependent_parents;
int company_tier;
public:
//class functions declarations
void get_data();
int calc_liabilities();
void display_score();
};
//function for receiving and string loan applicants details
void applicant::get_data()
{
system("cls");
cout<<"name of the applicant;";
getline(cin,name);
cout<<"age:";
cin>>age;

cin.clear();
cin.ignore(1000,'\n');

cout<<"address:";
getline(cin ,address);

cin.clear();
cin.ignore(1000,'\n');
cout<<"monthly salary:";
cin>>m_sal;
cout<<"total home loan EMI:";
cin>>h_loan;
cout<<"total personal loan EMI:";
cin>>p_loan;
cout<<"cheque bounces in last six months:";
cin>>no_chq_bounce;
cout<<"own house?(y or n):";
cin>>own_house;
cout<<"spouse working? (y or n):";
cin>>spouse_working;
cout<<"dependent on parents?(y or n):";
cin>>dependent_parents;
cout<<"company tier ? (1, 2, or 3):";
cin>>company_tier;
}

//function for calculating credit scores

int applicant::calc_liabilities()
{int score=0;
int liabilities;
if(age>22&&age<=30)
score=score+2;
if(age>30&&age<=35)
score=score+1;
else
score=score-1;
liabilities=h_loan+p_loan;
if(liabilities<=m_sal/4)
score=score+5;
if(liabilities>m_sal/4 && liabilities <=m_sal/3)
score=score+3;
if(liabilities>m_sal/3 && liabilities <=m_sal/2)
score=score+1;
if(liabilities>m_sal/2)
score=score-1;
 if (no_chq_bounce>1)
 score=score-2;
 if (no_chq_bounce==1)
 score=score-1;
 if (no_chq_bounce==0)
 score=score+1;
 if(p_loan>h_loan)
 score=score-1;
 else
  score=score+1;
  if(own_house=='y')
   score=score+1;
   if(spouse_working=='y')
    score=score+1;
    if(dependent_parents=='y')
    ;
    else
    score=score+1;
    if(company_tier==1)
    score=score+3;
    if(company_tier==2)
    score=score+2;
    if(company_tier==3)
    score=score+1;
    return(score);
    }
//displaying credit scores and coustomer rating

    void applicant::display_score()
    {
int sc = calc_liabilities();
//displaying the result
if(sc>=9)
cout<<"the applicant: "<<name<<" is at low risk.\n credit score="<<sc<<"\n credit can be given.";
else
{
if(sc>5 && sc<9)
cout<<"the applicant : "<<name<<" is at average risk.\ncredit score="<<sc<<"\n credit can be given with due precautions:\n1 house at cost.\n2 Jewellery at cost.\n3 shift to higher paying job .";
else
cout<<"the applicant : "<<name<<" is at high risk.\n credit score= "<<sc<<" \n credit can not be given :";

}
getch();
    }

// main function
int main()
{
char flag='f';
applicant a;
char ch;
while(1)
{
system("cls");
gotoxy(31,8);
cout<<"credit calc";
gotoxy(31,9);
cout<<"--------";
gotoxy(22,12);
cout<<"1-enter loan applicants details";
gotoxy(22,13);
cout<<"2-display credit score";
gotoxy(22,14);
cout<<"3-Exit";
gotoxy(22,16);
cout<<"select an option by typing the numeric code:\n";
ch=getch();
switch(ch)
{
case('1'):
{
a.get_data();
flag='t';
break;
}
case('2'):
{
if(flag=='f')
{
gotoxy(22,18);
cout<<"loan applicants details yet not entered!press any key to continue.. ";
getch();
}
else
a.display_score();
break;
}
case('3'):
{
    exit(1);
break;
}
default:
{gotoxy(22,18);
cout<<"invalid choice! press any key to continue..";
getch();
}
}// end of switch case block
}//end of while block
}//end of main()


