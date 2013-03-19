//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

AnsiString text1,text2,text3;
AnsiString ver_inf = "Ezbuilder Update Tool 1.0\nCopyRight erspicu_brox 2009.01.01";

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
  exit(1);        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
 ShowMessage(ver_inf);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
  Edit1->Text = "";
  Edit1->PasteFromClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
  OpenDialog1->Execute();
  if(OpenDialog1->FileName != "")
  {
    Edit1->Text = OpenDialog1->FileName ;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
  AnsiString cmd,sCurDir;
  sCurDir = ExtractFilePath(Application->ExeName);
  if(Edit1->Text != "" )
  {
    ShowMessage(text1);
    Form1->Visible =false;
    cmd = sCurDir+"tool\\ez_profile_installer.exe" ;
    cmd = "\"" + cmd + "\"";
    cmd = cmd + " ";
    cmd = cmd + " \""+ Edit1->Text +"\" ";
    cmd = "\"" + cmd + "\"";
    system ( cmd.c_str() );
    ShowMessage(text2);
    exit(1);
  }else
  {
     ShowMessage(text3);
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
    if ( FileExists ("tool\\ez_update_lang.txt") )
    {
       Memo1->Lines->LoadFromFile("tool\\ez_update_lang.txt");
       Form1->Caption = Memo1->Lines->operator [](0);
       Button1->Caption =  Memo1->Lines->operator [](1);
       Button2->Caption =  Memo1->Lines->operator [](2);
       Button3->Caption =  Memo1->Lines->operator [](3);
       Button4->Caption =  Memo1->Lines->operator [](5);
       Button5->Caption =  Memo1->Lines->operator [](4);
       Label1->Caption = Memo1->Lines->operator [](6)+"  ";
       text1 =  Memo1->Lines->operator [](7);
       text2 =  Memo1->Lines->operator [](8);
       text3 =  Memo1->Lines->operator [](9);


     }else
     {
       ShowMessage("No Language File !");
       text1 = "Profile install begin!";
       text2 = "Profile install finished!";
       text3 = "Please input profile information!";

     }
}
//---------------------------------------------------------------------------



