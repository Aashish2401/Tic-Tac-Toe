#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>
#include<fstream.h>

#define up 72
#define down 80
#define left 75
#define right 77

int Check=0;

class xando
{

	int xscore;
   int yscore;

public:

	int checkwin(char X[3][3],int n);
	void dispgrid(char X[3][3]);
	void players2();
	void players1();
   void writescore();
   void dispscore();
   void resetscore();
};
