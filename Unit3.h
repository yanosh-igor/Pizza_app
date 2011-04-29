//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
#include<fstream.h>


//---------------------------------------------------------------------------
class TPizza
{
protected:
char name[50];
unsigned int number,weight,amount,price;

public:
 void getdata(AnsiString&,AnsiString&,AnsiString&);
 void diskRead(int);
 void diskWrite();
 void diskDel();
 int diskCount();
 void ShowError();
};
//---------------------------------------------------------------------------
class TViewEvent : public TPizza
{
public:
 void ShowData(TStringGrid& tr,int n);
 void ShowRow(TStringGrid& row);
 void ShowError();
 void Look(TStringGrid& tr);

}  ;
 TPizza message;
 TViewEvent first_row, m;

 
#endif
 