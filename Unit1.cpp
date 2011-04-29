//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <SysUtils.hpp >
#include "Unit1.h" // ������ ������� ��������
#include "Unit2.h" // ������ ����� "��� ��������"
#include "Unit3.h" // ������, �� ������ ����� TPizza � TViewEvent

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
  

void __fastcall TForm1::Button1Click(TObject *Sender)
{
Label1->Visible=true;
Label2->Visible=true;
Label3->Visible=true;
Image1->Visible=false;
CheckListBox1->Visible=false;
Edit4->Visible=false;
Label4->Visible=false;
Label5->Visible=false;
Label6->Visible=false;
Label7->Visible=false;
Label9->Visible=false;
Label10->Visible=false;
Label11->Visible=false;
StringGrid2->Visible=false;

ClientWidth=645;
Edit1->Visible=true;
Edit2->Visible=true;
Edit3->Visible=true;
Button5->Visible=true;
Button6->Visible=true; 
Button8->Visible=false;
Form1->Position=poScreenCenter;
StringGrid1->Visible=true;

m.Look(*StringGrid1);



}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
CheckListBox1->Visible=false;
Label1->Visible=false;
Label2->Visible=false;
Label3->Visible=false;
Edit1->Visible=false;
Edit2->Visible=false;
Edit3->Visible=false;
Edit4->Visible=false;
Button5->Visible=false;
Button6->Visible=false;
Button8->Visible=false;
Label4->Visible=false;
Label5->Visible=false;
Label6->Visible=false;
Label7->Visible=false;
Label9->Visible=false;
Label10->Visible=false;
Label11->Visible=false;
StringGrid1->Visible=true;
StringGrid2->Visible=false;
Image1->Visible=false;
ClientWidth=513;


  m.Look(*StringGrid1);



}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button6Click(TObject *Sender)
{
if((Edit1->Text.Length()==0)||(Edit2->Text.Length()==0)||(Edit3->Text.Length()==0))
{
message.ShowError();
}   else {

     m.getdata(Edit1->Text,Edit2->Text,Edit3->Text);
     m.diskWrite();
     int n=m.diskCount();
Edit1->Text="";
Edit2->Text="";
Edit3->Text="";

StringGrid1->RowCount=n+2;
for(int i=0;i<n;i++)
    {
m.diskRead(i);
m.ShowData(*StringGrid1,i+1);



    }
     Edit1->SetFocus();

  }
}


//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
Label8->Visible=true;

Image1->Visible=false;
ClientWidth=513;
Label1->Visible=false;
Label2->Visible=false;
Label3->Visible=false;
Label9->Visible=false;
Label10->Visible=false;
Label11->Visible=false;
Edit1->Visible=false;
Edit2->Visible=false;
Edit3->Visible=false;
Button5->Visible=false;
Button6->Visible=false;
Button8->Visible=true;
StringGrid1->Visible=false;
CheckListBox1->Visible=true;


        m.Look(*StringGrid1);
        int n=m.diskCount();
     for(int i=0;i<n+1;i++)
{
  m.diskRead(i);
  
}
   if (CheckListBox1->Items->Count==0){
  for(int i=1;i<=StringGrid1->RowCount-1;i++)

{
 CheckListBox1->Items->Add(StringGrid1->Cells[1][i]) ;
 CheckListBox1->Items->Add(StringGrid1->Cells[4][i]) ;

}
  for (int i=0;i<=CheckListBox1->Count-1;i+=2)
  CheckListBox1->Header[i]=true;
}


}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{

first_row.ShowRow(*StringGrid1);
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button5Click(TObject *Sender)
{

AnsiString aut=Edit1->Text;



  if((Edit1->Text.Length()==0))
{   m.ShowError();

}   else {
                                    
  int n=StringGrid1->RowCount+1;

 for(int i=1;i<n;i++)
 if (StringGrid1->Cells [1][i]==aut)
 for(int j=i;j<n;j++)
 {StringGrid1->Cells [0][j]=StringGrid1->Cells [0][j+1];
  StringGrid1->Cells [1][j]=StringGrid1->Cells [1][j+1];
  StringGrid1->Cells [2][j]=StringGrid1->Cells [2][j+1];
  StringGrid1->Cells [3][j]=StringGrid1->Cells [3][j+1];
  StringGrid1->Cells [4][j]=StringGrid1->Cells [4][j+1];
 };
 StringGrid1->RowCount=n-1;
 n=StringGrid1->RowCount-1;
 m.getdata(StringGrid1->Cells [1][1],StringGrid1->Cells [2][1],
           StringGrid1->Cells [4][1]);
 m.diskDel();
 for(int i=2; i<n; i++)
 {m.getdata(StringGrid1->Cells [1][i],StringGrid1->Cells [2][i],
            StringGrid1->Cells [4][i]);
  m.diskWrite();
  Edit1->Text="";
 };  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit3KeyPress(TObject *Sender, char &Key)
{
if((Key>='0')&&(Key<='9'))
return;

if(Key==VK_BACK)
return;

if(Key==VK_RETURN)
return;
         
Key=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit2KeyPress(TObject *Sender, char &Key)
{
 if((Key>='0')&&(Key<='9'))
return;

if(Key==VK_BACK)
return;

if(Key==VK_RETURN) {
Edit3->SetFocus();
return;             }

Key=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
Form2->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
int sum=0,check=0,rows=0;
for (int i=0; i<CheckListBox1->Items->Count; i++)
if(CheckListBox1->Checked[i])  {check++;}
if(check==0)
{
    if (Application->MessageBox("�� ������ �� ��������",
            "�������",MB_OK)==IDOK);
}else
            { StringGrid2->Cells[0][0]="���� ����������";
 for (int i=0,q=1; i<CheckListBox1->Items->Count; i++)

  {
        if (CheckListBox1->Checked[i])
        { ++rows;
        sum+=StrToInt(CheckListBox1->Items->Strings[i]);
        Edit4->Text=sum;
        Label4->Caption=sum;

        StringGrid2->Cells[0][q]=CheckListBox1->Items->Strings[i-1];
        ++q;
  }
   StringGrid2->Visible=true;
   StringGrid2->RowCount=check+1;

     }
Edit4->Visible=true;
Label4->Visible=true;   
Label5->Visible=true;
Label6->Visible=true;
Label7->Visible=true;
Label9->Visible=true;
Label10->Visible=true;
Label11->Visible=true;

         }
 }

//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1KeyPress(TObject *Sender, char &Key)
{
  if(Key==VK_RETURN) {
Edit2->SetFocus();
return;             }


}
//---------------------------------------------------------------------------


void __fastcall TForm1::Edit4KeyPress(TObject *Sender, char &Key)
{
 if(Key==VK_RETURN) {

 Label5->Caption=(StrToInt(Edit4->Text)-StrToInt(Label4->Caption));
return;             }
}
//---------------------------------------------------------------------------


