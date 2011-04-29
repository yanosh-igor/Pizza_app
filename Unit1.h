//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <CheckLst.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TButton *Button2;
        TStringGrid *StringGrid1;
        TImage *Image1;
        TButton *Button4;
        TEdit *Edit1;
        TEdit *Edit2;
        TEdit *Edit3;
        TButton *Button6;
        TEdit *Edit4;
        TButton *Button5;
        TButton *Button7;
        TCheckListBox *CheckListBox1;
        TButton *Button8;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TStringGrid *StringGrid2;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        TLabel *Label11;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Edit3KeyPress(TObject *Sender, char &Key);
        void __fastcall Edit2KeyPress(TObject *Sender, char &Key);
        void __fastcall Button7Click(TObject *Sender);
        void __fastcall Button8Click(TObject *Sender);
        void __fastcall Edit1KeyPress(TObject *Sender, char &Key);
        void __fastcall Edit4KeyPress(TObject *Sender, char &Key);
        
       private:	// User declarations
public:
  	// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
#pragma argsused



//---------------------------------------------------------------------------

extern PACKAGE TForm1 *Form1;

//---------------------------------------------------------------------------
#endif
