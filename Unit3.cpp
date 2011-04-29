//---------------------------------------------------------------------------


#pragma hdrstop
#include "Unit1.h" // модуль головної програми
#include "Unit3.h" // модуль, що містить класи

//---------------------------------------------------------------------------

#pragma package(smart_init)

 void TPizza::getdata(AnsiString& a1,AnsiString& a2,AnsiString& a3) //отримує дані
{

strncpy(name,a1.c_str(),50);
weight=StrToInt(a2);
amount=1;
price=StrToInt(a3);

};
//---------------------------------------------------------------------------


void TPizza::ShowError()   //виводить помилку при редагуванні
{
   if (Application->MessageBox("Заповніть будь ласка усі поля",
            "Помилка",MB_OK)==IDOK);



}

void TPizza::diskRead(int pn)   //відкриває існуючий файл для читання
{
ifstream infile;
infile.open("Pizza.dat",ios::binary);
infile.seekg(pn*sizeof(TPizza));
infile.read((char*)this,sizeof(*this));
};
//---------------------------------------------------------------------------
void TPizza::diskWrite()  //відкриття файлу в режимі додавання в кінець
{
ofstream outfile;
outfile.open("Pizza.dat",ios::app|ios::binary);
outfile.write((char*)this,sizeof(*this));
};
//---------------------------------------------------------------------------
void TPizza::diskDel()      //видаляє дані із файлу якщо він існує
{
ofstream outfile;
outfile.open("Pizza.dat",ios::trunc|ios::binary);  ///якщо файл існує вилучає його
outfile.write((char*)this,sizeof(*this));
};
//---------------------------------------------------------------------------
int TPizza::diskCount()        //повертає кількість елементів у файлі
{
TPizza per;
ifstream infile;
infile.open("Pizza.dat",ios::binary);
infile.seekg(0,ios::end);
return(int)(infile.tellg()/64);
};
//---------------------------------------------------------------------------



void TViewEvent::ShowData(TStringGrid& tr,int n)   //заповнює таблицю даними
{number=n;
tr.Cells[0][n]=IntToStr(number);
tr.Cells[1][n]=name;
tr.Cells[2][n]=IntToStr(weight);
tr.Cells[3][n]=IntToStr(amount);
tr.Cells[4][n]=FloatToStr(price);

};
//---------------------------------------------------------------------------
void TViewEvent::ShowRow(TStringGrid& row)     //заповнює 1 рядок таблиці
{
row.Cells[0][0]="№";
row.Cells[1][0]="Назва продукції";
row.Cells[2][0]="Вага";
row.Cells[3][0]="К-сть";
row.Cells[4][0]="Ціна";

} ;

//---------------------------------------------------------------------------
void TViewEvent::ShowError()         //виводить помилку, якщо не обрано жодного об'єкту
{
if (Application->MessageBox("Будьте ласкаві, введіть назву продукції",
            "Помилка",MB_OK)==IDOK);

}
//-------------------------------------------------------------------------
void TViewEvent::Look(TStringGrid& tr)  //виконує усі необхідні методи для виведення даних із файлу
{

int n=m.diskCount();
tr.RowCount=n+1;
for(int i=0;i<n;i++)
{
m.diskRead(i);
m.ShowData(tr,i+1);
}

}
