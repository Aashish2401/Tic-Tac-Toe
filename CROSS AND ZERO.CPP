#include"X&O.h"
#include"loading.h"

void main()
{

	system("title Tic Tac Toe");
	xando X;
   int y;
	start:

   cout<<"****************************** TIC TAC TOE ************************************";
   loading();
   clrscr();
   cout<<"****************************** TIC TAC TOE ************************************";
   cout<<"\n\n\n1.Play Game\n2.Scores\n3.Reset Stats\n4.Credits\n5.Exit\n\nEnter your choice:";
	cin>>y;
   if(y==1)
   {

   	clrscr();
		cout<<"1.1 Player\n2.2 Players";
   	cout<<"\n\nEnter your choice:";
		cin>>y;
   	clrscr();

		if(y==1)
			X.players1();

		else
			X.players2();

   	clrscr();
   	Check=0;
      goto start;

	}

   else if(y==2)
   {
   	clrscr();
      X.dispscore();
      clrscr();
      goto start;
   }

   else if(y==3)
   {
   	clrscr();
      X.resetscore();
      cout<<"Scores Have Been Reset.";
      getch();
      clrscr();
      goto start;
   }
   else if(y==4)
   {
   	clrscr();
   	cout<<"The Tic Tac Toe Game";
      cout<<"\n\nDeveloped By: Aashish Srinivasan";
      cout<<"\n\nDeveloped In: C++";
      cout<<"\n\nGame Version: 1.0";
      cout<<"\n\nFor Support Contact: aashish.srinivasan@gmail.com";
      getch();
      clrscr();
   	goto start;
   }

}

