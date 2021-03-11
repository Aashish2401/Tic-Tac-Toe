#include"xando.h"

int xando::checkwin(char X[3][3],int n)
{

	if(X[0][0]==X[0][1]&&X[0][1]==X[0][2]&&X[0][2]=='x'||X[1][0]==X[1][1]&&X[1][1]==X[1][2]&&X[1][2]=='x'||X[2][0]==X[2][1]&&X[2][1]==X[2][2]&&X[2][2]=='x'||X[0][0]==X[1][1]&&X[1][1]==X[2][2]&&X[2][2]=='x'||X[0][2]==X[1][1]&&X[1][1]==X[2][0]&&X[2][0]=='x'||X[0][0]==X[1][0]&&X[1][0]==X[2][0]&&X[2][0]=='x'||X[0][1]==X[1][1]&&X[1][1]==X[2][1]&&X[2][1]=='x'||X[0][2]==X[1][2]&&X[1][2]==X[2][2]&&X[2][2]=='x')
  	{
   	dispgrid(X);
		gotoxy(1,7);
   	cout<<"Player X wins!!!";
   	getch();
      xscore+=2;
      writescore();
   	return 1;
   }

 	else if(X[0][0]==X[0][1]&&X[0][1]==X[0][2]&&X[0][2]=='o'||X[1][0]==X[1][1]&&X[1][1]==X[1][2]&&X[1][2]=='o'||X[2][0]==X[2][1]&&X[2][1]==X[2][2]&&X[2][2]=='o'||X[0][0]==X[1][1]&&X[1][1]==X[2][2]&&X[2][2]=='o'||X[0][2]==X[1][1]&&X[1][1]==X[2][0]&&X[2][0]=='o'||X[0][0]==X[1][0]&&X[1][0]==X[2][0]&&X[2][0]=='o'||X[0][1]==X[1][1]&&X[1][1]==X[2][1]&&X[2][1]=='o'||X[0][2]==X[1][2]&&X[1][2]==X[2][2]&&X[2][2]=='o')
	{
   	dispgrid(X);
   	gotoxy(1,7);
   	cout<<"Player O wins!!!!";
   	getch();
      yscore+=2;
      writescore();
   	return 1;
   }

   else if(n>=9)
   {
      dispgrid(X);
   	gotoxy(1,7);
   	cout<<"Its a draw";
   	getch();
      xscore++;
      yscore++;
      writescore();
   	return 1;
   }


   return 0;

}

void xando::dispgrid(char X[3][3])
{

	gotoxy(1,1);
   cout<<X[0][0]<<"|"<<X[0][1]<<"|"<<X[0][2]<<"\n_____\n"<<X[1][0]<<"|"<<X[1][1]<<"|"<<X[1][2]<<"\n_____\n"<<X[2][0]<<"|"<<X[2][1]<<"|"<<X[2][2];

}

void xando::players2()
{

	clrscr();
	char a;
	int x=1,y=1,n=0;
	char X[3][3]={"   ","   ","   "};
	for(int i=0;;i++)
   {

   	clrscr();
		dispgrid(X);
		gotoxy(8,1);
		cout<<"Player ";
		if(n%2==0)
			cout<<"1's turn.(X)";

		else
			cout<<"2's turn.(O)";

		gotoxy(x,y);

      a=getch();
      if(a==left)
         x-=2;

      if(a==down)
         y+=2;

      if(a==right)
         x+=2;

      if(a==up)
         y-=2;

      gotoxy(x,y);

      if(a=='x')
      {

			if(n%2==0)
         {

				n++;
				X[((y-1)/2)][((x-1)/2)]=a;
            gotoxy(1,1);
            if(n==9)
            	Check=checkwin(X,n);

            if(Check==1)
            	return;

         }

      }
		else if(a=='o')
		{

			if(n%2!=0)
         {

				n++;
            X[((y-1)/2)][((x-1)/2)]=a;
				gotoxy(1,1);

         }

      }

		Check=checkwin(X,n);

      if(Check==1)
      	return;
         
		gotoxy(x,y);

   }

}

void xando::players1()
{

	randomize();
	clrscr();
	char a;
	int x=1,y=1,n=0;
	char X[3][3]={"   ","   ","   "};

	while(n<=9)
   {

		dispgrid(X);
		gotoxy(8,1);
		cout<<"Player ";

		if(n%2==0)
			cout<<"1's turn.(X)";

		else
			cout<<"2's turn.(O)";

      a=up;
      while(a!='x')
      {

		gotoxy(x,y);
		a=getch();

		if(a==left)
			x-=2;

		if(a==down)
			y+=2;

		if(a==right)
			x+=2;

		if(a==up)
			y-=2;

      }

		if(a=='x'&&X[((y-1)/2)][((x-1)/2)]!='x'&&X[((y-1)/2)][((x-1)/2)]!='o')
      {

			if(n%2==0)
         {

				n++;

            X[((y-1)/2)][((x-1)/2)]=a;

				gotoxy(1,1);

            if(n==9)
            	Check=checkwin(X,n);

            if(Check==1)
            	return;
         }

      }

		if(n%2!=0)
      {

			a='o';
			n++;

         if(((X[2][0]==X[1][0]&&X[1][0]=='o')||(X[0][2]==X[0][1]&&X[0][1]=='o')||(X[2][2]==X[1][1]&&X[1][1]=='o')))
         	if(X[0][0]!='x'&&X[0][0]!='o')
				{
            	X[0][0]=a;
               goto checked;
            }

		   if(((X[0][0]==X[0][2]&&X[0][2]=='o')||(X[2][1]==X[1][1]&&X[1][1]=='o')))
         	if(X[0][1]!='x'&&X[0][1]!='o')
         	{
					X[0][1]=a;
               goto checked;
            }

			if(((X[2][2]==X[1][2]&&X[1][2]=='o')||(X[0][0]==X[0][1]&&X[0][1]=='o')||(X[2][0]==X[1][1]&&X[1][1]=='o')))
         	if(X[0][2]!='x'&&X[0][2]!='o')
            {
					X[0][2]=a;
               goto checked;
            }

			if(((X[2][0]==X[0][0]&&X[0][0]=='o')||(X[1][2]==X[1][1]&&X[1][1]=='o')))
         	if(X[1][0]!='x'&&X[1][0]!='o')
            {
					X[1][0]=a;
               goto checked;
            }

			if(((X[0][0]==X[2][2]&&X[2][2]=='o')||(X[2][0]==X[0][2]&&X[0][2]=='o')||(X[0][1]==X[2][1]&&X[2][1]=='o')||(X[1][0]==X[1][2]&&X[1][2]=='o')))
         	if(X[1][1]!='x'&&X[1][1]!='o')
            {
					X[1][1]=a;
               goto checked;
            }

			if(((X[0][2]==X[2][2]&&X[2][2]=='o')||(X[1][0]==X[1][1]&&X[1][1]=='o')))
         	if(X[1][2]!='x'&&X[1][2]!='o')
            {
					X[1][2]=a;
               goto checked;
            }

			if(((X[0][0]==X[1][0]&&X[1][0]=='o')||(X[2][2]==X[2][1]&&X[2][1]=='o')||(X[0][2]==X[1][1]&&X[1][1]=='o')))
         	if(X[2][0]!='x'&&X[2][0]!='o')
            {
					X[2][0]=a;
               goto checked;
            }

			if(((X[2][0]==X[2][2]&&X[2][2]=='o')||(X[0][1]==X[1][1]&&X[1][1]=='o')))
         	if(X[2][1]!='x'&&X[2][1]!='o')
            {
            	X[2][1]=a;
               goto checked;
            }

			if(((X[2][0]==X[2][1]&&X[2][1]=='o')||(X[0][2]==X[1][2]&&X[1][2]=='o')||(X[0][0]==X[1][1]&&X[1][1]=='o')))
         	if(X[2][2]!='x'&&X[2][2]!='o')
            {
					X[2][2]=a;
               goto checked;
            }

         if(((X[2][0]==X[1][0]&&X[1][0]=='x')||(X[0][2]==X[0][1]&&X[0][1]=='x')||(X[2][2]==X[1][1]&&X[1][1]=='x')))
         	if(X[0][0]!='x'&&X[0][0]!='o')
				{
            	X[0][0]=a;
               goto checked;
            }

		   if(((X[0][0]==X[0][2]&&X[0][2]=='x')||(X[2][1]==X[1][1]&&X[1][1]=='x')))
         	if(X[0][1]!='x'&&X[0][1]!='o')
         	{
					X[0][1]=a;
               goto checked;
            }

			if(((X[2][2]==X[1][2]&&X[1][2]=='x')||(X[0][0]==X[0][1]&&X[0][1]=='x')||(X[2][0]==X[1][1]&&X[1][1]=='x')))
         	if(X[0][2]!='x'&&X[0][2]!='o')
            {
					X[0][2]=a;
               goto checked;
            }

			if(((X[2][0]==X[0][0]&&X[0][0]=='x')||(X[1][2]==X[1][1]&&X[1][1]=='x')))
         	if(X[1][0]!='x'&&X[1][0]!='o')
            {
					X[1][0]=a;
               goto checked;
            }

			if(((X[0][0]==X[2][2]&&X[2][2]=='x')||(X[2][0]==X[0][2]&&X[0][2]=='x')||(X[0][1]==X[2][1]&&X[2][1]=='x')||(X[1][0]==X[1][2]&&X[1][2]=='x')))
         	if(X[1][1]!='x'&&X[1][1]!='o')
            {
					X[1][1]=a;
               goto checked;
            }

			if(((X[0][2]==X[2][2]&&X[2][2]=='x')||(X[1][0]==X[1][1]&&X[1][1]=='x')))
         	if(X[1][2]!='x'&&X[1][2]!='o')
            {
					X[1][2]=a;
               goto checked;
            }

			if(((X[0][0]==X[1][0]&&X[1][0]=='x')||(X[2][2]==X[2][1]&&X[2][1]=='x')||(X[0][2]==X[1][1]&&X[1][1]=='x')))
         	if(X[2][0]!='x'&&X[2][0]!='o')
            {
					X[2][0]=a;
               goto checked;
            }

			if(((X[2][0]==X[2][2]&&X[2][2]=='x')||(X[0][1]==X[1][1]&&X[1][1]=='x')))
         	if(X[2][1]!='x'&&X[2][1]!='o')
            {
            	X[2][1]=a;
               goto checked;
            }

			if(((X[2][0]==X[2][1]&&X[2][1]=='x')||(X[0][2]==X[1][2]&&X[1][2]=='x')||(X[0][0]==X[1][1]&&X[1][1]=='x')))
         	if(X[2][2]!='x'&&X[2][2]!='o')
            {
					X[2][2]=a;
               goto checked;
            }


         back:
         x=random(3);
         y=random(3);

         if(X[y][x]!='x'&&X[y][x]!='o')
         {

         	X[y][x]=a;
            gotoxy(1,1);

         }

         else
         	goto back;

      }

   checked:

   Check=checkwin(X,n);

   if(Check==1)
   	return;

   x=y=1;
   }

}

void xando::writescore()
{
	ofstream fout;
   fout.open("Scores.XO",ios::binary);
   fout.write((char *)this,sizeof(xando));
   fout.close();
}

void xando::dispscore()
{
	ifstream fin;
   fin.open("Scores.XO",ios::binary);
   fin.read((char *)this,sizeof(xando));
   clrscr();
   cout<<"X Score:"<<xscore;
   cout<<"\nO score:"<<yscore;
   getch();
   clrscr();
   fin.close();
}

void xando::resetscore()
{
	ofstream fout;
   fout.open("Scores.XO",ios::binary);
   xscore=0;
   yscore=0;
   fout.write((char *)this,sizeof(xando));
   fout.close();
}
