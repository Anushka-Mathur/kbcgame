#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<process.h>
#include<stdlib.h>


int n=0,pno=0;
long tempmoney=0;
void game();
void countmoney();
void large();
void pldisplay();
void rules();
void adaddq();
void adview();
void addelq();


class player
{
 public:
  char tempname[30];
  char pname[30];
  long pmoney;
  void getinfo()
  {
   cout<<"Enter name:";
   gets(pname);
   pmoney=0;
   pno++;
  }
  void modinfo()
  {
   pmoney=tempmoney;
  }
  void putinfo()
  {
   cout<<endl;
   cout<<"Name:";
   puts(pname);
   cout<<"Money earned:"<<pmoney;
  }
};

player P;

class ques
{
  public:
   int qno;
   int g;
   long money;
   char q[200];
   char a[20],b[20],c[20],d[20],o,ans,cor;
   void getques();
   void putques();
   void displayques();
   void copt();
   void prizemoney();
};

void display_menu()
{
 clrscr();
 int w,q,b,c=0;
 char f,m,g[4],o[4];
 i:cout<<"Welcome to KBC"<<endl;
 cout<<"Kindly choose your preferred option"<<endl;
 cout<<"1. Admin"<<endl;
 cout<<"2. Player"<<endl;
 cout<<"3. Exit"<<endl;
 cout<<"Enter choice=";
 cin>>w;
 while(1)
 {
  switch(w)
  {
    case 1: l:cout<<"Enter security code=";
	    for(int s=0;s<4;s++)
		  {
		     g[s]=getch();
		     cout<<"*";
		  }
		  g[4]='\0';
		  cout<<endl<<endl;
		  if(strcmp(g,"1357")==0)
		  {
		   clrscr();
		   while(1)
		   {
		    u:cout<<endl<<"Kindly choose your preferred option"<<endl<<endl;
		    cout<<"1.View questions"<<endl;
		    cout<<"2.Add questions"<<endl;
		    cout<<"3.Delete questions"<<endl;
		    cout<<"4.Exit from admin menu"<<endl<<endl;
		    cout<<"Enter choice=";
		    cin>>q;

		    switch(q)
		    {
		     case 1: adview();
			     break;
		     case 2: adaddq();
			    break;
		     case 3: addelq();
			     break;
		     case 4: clrscr();
			     goto i;
		     default: cout<<"Invalid Choice"<<endl;
			     goto u;
		    }
		   }
		  }
		 else
		 {
		  cout<<'\t'<<"Wrong security code"<<endl;
		  cout<<endl<<endl<<"Would you like to continue as an admin? (y/n)";
		  cin>>f;
		  if(f=='y'||f=='Y')
		  {
		    goto l;
		  }
		  else
		   if(f=='N'||f=='n')
		   {
		     goto i;
		   }
		  }
	  break;
  case 2: e:cout<<"Enter security code=";
	  for(int b=0;b<4;b++)
		  {
		     o[b]=getch();
		     cout<<"*";
		  }
	  o[4]='\0';
	  cout<<endl<<endl;
	  if(strcmp(o,"2002")==0)
		  {
		   clrscr();
		   while(1)
		   {
		    z:cout<<endl<<"Kindly choose your preferred option"<<endl<<endl;
		    cout<<"1.Play the game"<<endl;
		    cout<<"2.View the player with maximum amount of money"<<endl;
		    cout<<"3.Display all players"<<endl;
		    cout<<"4.Exit from player menu"<<endl<<endl;
		    cout<<"Enter choice=";
		    cin>>q;

		    switch(q)
		    {
		     case 1: rules();
			     break;
		     case 4: clrscr();
			     goto i;
		     case 2: large();
			     break;
		     case 3: pldisplay();
			     break;
		     default: cout<<"Invalid Choice"<<endl;
			     goto z;
		    }
		   }
		  }
		 else
		 {
		  cout<<'\t'<<"Wrong security code"<<endl;
		  cout<<endl<<endl<<"Would you like to continue as an player? (y/n)";
		  cin>>f;
		  if(f=='y'||f=='Y')
		  {
		    goto e;
		  }
		  else
		   if(f=='N'||f=='n')
		   {
		     goto i;
		   }
		  }
	  break;
  case 3: exit(0);
  default:cout<<"Invalid choice"<<endl;
	  goto i;

 }
 }
}
void ques::getques()
{
     cout<<"Enter question number=";
     cin>>qno;
     cout<<"Enter new question=";
     gets(q);
     cout<<"Enter option A=";
     gets(a);
     cout<<"Enter option B=";
     gets(b);
     cout<<"Enter option C=";
     gets(c);
     cout<<"Enter option D=";
     gets(d);
     cout<<"Enter correct option=";
     cin>>cor;
     cout<<"Question Entered";

}

void ques::putques()
{
     cout<<qno<<".";
     puts(q);
     cout<<"A."<<a<<endl;
     cout<<"B."<<b<<endl;
     cout<<"C."<<c<<endl;
     cout<<"D."<<d<<endl;
     cout<<"Correct option="<<cor<<endl;
}

//Here it Displays the Question
void ques::displayques()
{
    cout<<"Question No:"<<qno<<endl;
    puts(q);
    cout<<endl;
    cout<<"A."<<a<<endl;
    cout<<"B."<<b<<endl;
    cout<<"C."<<c<<endl;
    cout<<"D."<<d<<endl;
    cout<<"Enter option(press q to quit)=";
    cin>>ans;
    copt();
}

void ques::copt()
{
     if(ans==cor)
     {
       cout<<"Correct answer!!!"<<endl;
       o='y';
       prizemoney();
     }
     else
     {
	if(ans=='q'||ans=='Q')
	{
	  o='q';
	  cout<<"Thank you for playing!!!!";
	  prizemoney();
	}
	else
	{
	  o='n';
	  prizemoney();
	}
     }
}


void ques::prizemoney()
{

 if(o=='y')
 {
  g=qno;
  switch(g)
  {
   case 1: money=1000;
	   tempmoney=1000;
	   cout<<"Your current amount is Rs"<<money<<endl;
	   break;
   case 2: money=2000;
	   tempmoney=2000;
	   cout<<"Your current amount is Rs"<<money<<endl;
	   cout<<"You have reached your first checkpoint"<<endl;
	   break;
   case 3: money=3000;
	   tempmoney=3000;
	   cout<<"Your current amount is Rs"<<money<<endl;
	   break;
   case 4: money=5000;
	   tempmoney=5000;
	   cout<<"Your current amount is Rs"<<money<<endl;
	   break;
   case 5: money=10000;
	   tempmoney=10000;
	   cout<<"Your current amount is Rs"<<money<<endl;
	   cout<<"You have reached your second checkpoint"<<endl;
	   break;
   case 6: money=20000;
	   tempmoney=20000;
	   cout<<"Your current amount is Rs"<<money<<endl;
	   break;
   case 7: money=40000;
	   tempmoney=40000;
	   cout<<"Your current amount is Rs"<<money<<endl;
	   break;
   case 8: money=80000;
	   tempmoney=80000;
	   cout<<"Your current amount is Rs"<<money<<endl;
	   break;
   case 9: money=160000;
	   tempmoney=160000;
	   cout<<"Your current amount is Rs"<<money<<endl;
	   break;
   case 10: money=320000;
	    tempmoney=320000;
	    cout<<"Your current amount is Rs"<<money<<endl;
	    cout<<"You have reached your third checkpoint"<<endl;
	    break;
   case 11: money=640000;
	    tempmoney=640000;
	    cout<<"Your current amount is Rs"<<money<<endl;
	    break;
   case 12: money=1250000;
	    tempmoney=1250000;
	    cout<<"Your current amount is Rs"<<money<<endl;
	    break;
   case 13: money=2500000;
	    tempmoney=2500000;
	    cout<<"Your current amount is Rs"<<money<<endl;
	    break;
   case 14: money=5000000;
	    tempmoney=5000000;
	    cout<<"Your current amount is Rs"<<money<<endl;
	    break;
   case 15: money=10000000;
	    tempmoney=10000000;
	    cout<<"You have won Rs"<<money<<endl;
	    cout<<"CONGRATULATION!!!You have become to Crorepati!!!!"<<endl;
	    break;

   }
  }
  else
  {
    g=qno-1;
    if(o=='n')
       {
	  cout<<"Wrong answer"<<endl;
	  cout<<"Sorry, You cannot continue the game anymore"<<endl;
	  if(g>=2&&g<5)
	  {
	    cout<<"Well tried!!! You have won Rs.2000"<<endl;
	    tempmoney=2000;
	  }
	  if(g>=5&&g<10)
	  {
	    cout<<"Well tried!!! You have won Rs.10000"<<endl;
	    tempmoney=10000;
	  }
	  if(g>=10&&g<15)
	  {
	    cout<<"Well tried!!! You have won Rs.3200000"<<endl;
	    tempmoney=3200000;
	  }
	  countmoney();
	  getch();
	  clrscr();
	  display_menu();

      }
     else
      {
	if(o=='q'||o=='Q')
	{
	  cout<<"Sorry, You cannot continue the game anymore"<<endl;
	   if(g>=2&&g<5)
	    {
	     cout<<"Well tried!!! You have won Rs.2000"<<endl;
	     tempmoney=2000;
	    }

	  if(g>=5&&g<10)
	      {
	       cout<<"Well tried!!! You have won Rs.10000"<<endl;
	       tempmoney=10000;
	      }

	  if(g>=10&&g<15)
	      {
	       cout<<"Well tried!!! You have won Rs.3200000"<<endl;
	       tempmoney=3200000;
	      }

	 }

       countmoney();
       getch();
       clrscr();
       display_menu();
    }
  }
}


ques Q;


void main()
{
 clrscr();
 int w,q,b,c=0;
 char f,m,g[4],o[4];
 i:cout<<"Welcome to KBC"<<endl;
 cout<<"Kindly choose your preferred option"<<endl;
 cout<<"1. Admin"<<endl;
 cout<<"2. Player"<<endl;
 cout<<"3. Exit"<<endl;
 cout<<"Enter choice=";
 cin>>w;
 while(1)
 {
  switch(w)
  {
    case 1: l:cout<<"Enter security code=";
	    for(int s=0;s<4;s++)
		  {
		     g[s]=getch();
		     cout<<"*";
		  }
		  g[4]='\0';
		  cout<<endl<<endl;
		  if(strcmp(g,"1357")==0)
		  {
		   clrscr();
		   while(1)
		   {
		    u:cout<<endl<<"Kindly choose your preferred option"<<endl<<endl;
		    cout<<"1.View questions"<<endl;
		    cout<<"2.Add questions"<<endl;
		    cout<<"3.Delete questions"<<endl;
		    cout<<"4.Exit from admin menu"<<endl<<endl;
		    cout<<"Enter choice=";
		    cin>>q;

		    switch(q)
		    {
		     case 1: adview();
			     break;
		     case 2: adaddq();
			    break;
		     case 3: addelq();
			     break;
		     case 4: clrscr();
			     goto i;
		     default: cout<<"Invalid Choice"<<endl;
			     goto u;
		    }
		   }
		  }
		 else
		 {
		  cout<<'\t'<<"Wrong security code"<<endl;
		  cout<<endl<<endl<<"Would you like to continue as an admin? (y/n)";
		  cin>>f;
		  if(f=='y'||f=='Y')
		  {
		    goto l;
		  }
		  else
		   if(f=='N'||f=='n')
		   {
		     goto i;
		   }
		  }
	  break;
  case 2: e:cout<<"Enter security code=";
	  for(int b=0;b<4;b++)
		  {
		     o[b]=getch();
		     cout<<"*";
		  }
	  o[4]='\0';
	  cout<<endl<<endl;
	  if(strcmp(o,"2002")==0)
		  {
		   clrscr();
		   while(1)
		   {
		    z:cout<<endl<<"Kindly choose your preferred option"<<endl<<endl;
		    cout<<"1.Play the game"<<endl;
		    cout<<"2.View player with most amount of money"<<endl;
		    cout<<"3.Display all players"<<endl;
		    cout<<"4.Exit from player menu"<<endl<<endl;
		    cout<<"Enter choice=";
		    cin>>q;

		    switch(q)
		    {
		     case 1: rules();
			     break;
		     case 2: large();
			     break;
		     case 3: pldisplay();
			     break;
		     case 4: clrscr();
			     goto i;
		     default: cout<<"Invalid Choice"<<endl;
			     goto z;
		    }
		   }
		  }
		 else
		 {
		  cout<<'\t'<<"Wrong security code"<<endl;
		  cout<<endl<<endl<<"Would you like to continue as an player? (y/n)";
		  cin>>f;
		  if(f=='y'||f=='Y')
		  {
		    goto e;
		  }
		  else
		   if(f=='N'||f=='n')
		   {
		     goto i;
		   }
		  }
	  break;
  case 3: exit(0);
  default:cout<<"Invalid choice"<<endl;
	  goto i;

 }
 }

}


void adaddq()
{
  ofstream f1;
  f1.open("QUESTION.DAT",ios::binary|ios::app);
  Q.getques();
  f1.write((char*)&Q,sizeof(Q));
  f1.close();
}

void adview()
{
 ifstream f1;
 f1.open("QUESTION.DAT",ios::binary);
 while(f1.read((char*)&Q,sizeof(Q)))
 {
  clrscr();
  Q.putques();
  cout<<"\n\t\tPress Any Key To Continue\n";
  getch();
 }
 f1.close();

 n++;
}

void addelq()
{

 int qnum;
 ifstream f1;
 f1.open("QUESTION.DAT",ios::binary);
 ofstream f2;
 f2.open("TEMP.DAT",ios::binary);
 cout<<"Enter the question number to be deleted=";
 cin>>qnum;
 while(f1.read((char*)&Q,sizeof(Q)))
 {
   if(Q.qno!=qnum)
   {
    f2.write((char*)&Q, sizeof(Q));
   }
 }
 f1.close();
 f2.close();
 remove("QUESTION.DAT");
 rename("TEMP.DAT","QUESTION.DAT");
 cout<<"Question Deleted"<<endl;
}

void rules()
{
  ofstream f1;
  f1.open("PLAYER.DAT",ios::binary|ios::app);
  P.getinfo();
  f1.close();
  cout<<endl;
  clrscr();
  cout<<"WELCOME TO THE KBC GAME";
  cout<<endl<<"RULES OF THE GAME";
  cout<<endl<<"1. There are 15 questions in this game, and for answering each,you'll win the amount corresponding to that question.";
  cout<<endl<<"2. If you answered any question incorrectly, then you'll lose the game.";
  cout<<endl<<"3. If you quit the game, you'll win the previous indicated amount";
  cout<<endl<<"4. When entering your options, please enter the choice in capital letter";
  cout<<endl;
  for(int i=0;i<80;i++)
  {
   cout<<"*";
  }
  cout<<endl<<"Prize Money:";
  cout<<"\t15. 1,00,00,000\n";
  cout<<"\t\t14. 50,00,000\n";
  cout<<"\t\t13. 25,00,000\n";
  cout<<"\t\t12. 12,50,000\n";
  cout<<"\t\t11. 6,40,000\n";
  cout<<"\t\t10. 3,20,000 (Third checkpoint)\n";
  cout<<"\t\t9. 1,60,000\n";
  cout<<"\t\t8. 80,000\n";
  cout<<"\t\t7. 40,000\n";
  cout<<"\t\t6. 20,000\n";
  cout<<"\t\t5. 10,000 (Second checkpoint)\n";
  cout<<"\t\t4. 5,000\n";
  cout<<"\t\t3. 3,000\n";
  cout<<"\t\t2. 2,000 (First checkpoint)\n";
  cout<<"\t\t1. 1,000\n";
  cout<<"\n\t\tPress Any Key To Continue\n";
  getch();
  clrscr();
  game();
}

void game()
{
   ofstream f2;
   ifstream f1;
   f1.open("QUESTION.DAT",ios::binary);
   f1.seekg(0,ios::beg);
   while(f1.read((char*)&Q,sizeof(Q)))
   {
    Q.displayques();
    if(Q.o=='q'||Q.o=='Q')
     break;
   }
   cout<<tempmoney;
   P.pmoney=tempmoney;
   cout<<endl;
   cout<<"Thank you so much for playing!!!";
   f1.close();
   countmoney();
}


void countmoney()
{
   ofstream f2;
   f2.open("PLAYER.DAT",ios::binary|ios::app);
   P.pmoney=tempmoney;
   f2.write((char*)&P,sizeof(P));
   f2.close();
}


void large()
{
 clrscr();
 int y,large=0;
 char largename[50];
 ifstream f1;
 f1.open("PLAYER.DAT",ios::binary);
 while(f1.read((char*)&P,sizeof(P)))
 {
  y=P.pmoney;
  if(large<y)
  {
    large=P.pmoney;
    strcpy(largename,P.pname);
  }
 }
 cout<<endl<<'\t';
 cout<<"PLAYER WITH THE MOST AMOUNT OF MONEY EARNED IS";
 cout<<endl;
 cout<<"Name=";
 puts(largename);
 cout<<"Money="<<large;
 f1.close();
 getch();
}

void pldisplay()
{
 clrscr();
 ifstream f1;
 f1.open("PLAYER.DAT",ios::binary);
 cout<<"*********PLAYER Details********";
 while(f1.read((char*)&P,sizeof(P)))
 {
  P.putinfo();
 }
 f1.close();
 getch();
}






