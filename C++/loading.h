void loading()
{
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t";
   cout<<"--------------------";
   char x='X',y='O';
   cout<<"\n\n\t\t\t";
   cout<<"--------------------";
   gotoxy(1,12);
   cout<<"\t\t\t";
   for(int i=1;i<=20;i++)
   {
   	for(long j=0;j<99999999;j++);

   	if((i%2)!=0)
      	cout<<x;
      else
      	cout<<y;
   }
}
