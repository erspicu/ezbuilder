//---------------------------------------------------------------------------
#define NO_WIN32_LEAN_AND_MEAN
#include <shlobj.h>
#include <vcl.h>
#include <stdio.h>
#pragma hdrstop
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

AnsiString ver_date = "2009.01.01";
AnsiString version = "Ezbuilder File Linker\n\ncopyright by erspicu_brox\n\nVer " + ver_date ;


//--------------


///
AnsiString szPreDir = "";
int __stdcall BrowseProc(HWND hwnd,UINT uMsg, LPARAM lParam, LPARAM lpData )
{
    char szDir[MAX_PATH];

    switch(uMsg)
    {
        case BFFM_INITIALIZED:
            SendMessage(hwnd, BFFM_SETSTATUSTEXT,0, (LPARAM)"");
            if (szPreDir != "")
                SendMessage(hwnd, BFFM_SETSELECTION, TRUE, (LPARAM)szPreDir.c_str());
            break;
        case BFFM_SELCHANGED:
            if(SHGetPathFromIDList((LPITEMIDLIST)lParam, szDir));
                //Form1->Label3->Caption = szDir;
            break;
    }
    return 0;
}
///



                       
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
   exit(1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
   OpenDialog1->Execute();
   Edit1->Text = OpenDialog1->FileName ;
   if (OpenDialog1->FileName != "")
   {
     Button1->Enabled = true;
   }
   //if ( CheckBox1->Checked == true && Edit2->Text ==""  )
   //{
   //  Button1->Enabled = false;
   //}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
   FILE *fp;
   AnsiString file_name;
   AnsiString   sCurDir;
   AnsiString media_file,message;
   int len,cut_loc=0;
   len = Edit1->Text.Length();
   len--;
   while (len >= 1)
   {
     if ( Edit1->Text[len] == '\\' )
     {
       cut_loc = len ;
       break;
     }
     len--;
   }
   media_file = Edit1->Text ;
   media_file.Delete(1,cut_loc);
   sCurDir = ExtractFilePath(Application->ExeName);
   if ( Edit2->Text == "" ) file_name = sCurDir + "MediaFile\\" + media_file + ".efl";
   else
   {
      file_name = Edit2->Text + "\\" + media_file + ".efl";
      //ShowMessage ( file_name);
   }
   fp = fopen ( file_name.c_str(),"w");
   fprintf(fp,"\"%s\"",Edit1->Text.c_str());
   fclose(fp);
   message = "[" +media_file +  "] linker file done!" ;
   ShowMessage (message);
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------


void __fastcall TForm1::FormCreate(TObject *Sender)
{
  AnsiString  sCurDir ;
  FILE *fp;
  sCurDir = ExtractFilePath(Application->ExeName);
  sCurDir = sCurDir +  "tool\\ezlinker_lang.txt" ;
  if ( fp = fopen(sCurDir.c_str(),"r") )
  {
     fclose (fp);
     Memo1->Lines->LoadFromFile(sCurDir);
     Label1->Caption = Memo1->Lines->operator [](0) + "     ";
     Button3->Caption = Memo1->Lines->operator [](1);
     Button4->Caption = Memo1->Lines->operator [](2);
     Button1->Caption  = Memo1->Lines->operator [](3) ;
     Button2->Caption  = Memo1->Lines->operator [](4);
     Form1->Caption = Memo1->Lines->operator [](5);
     Button5->Caption  = Memo1->Lines->operator [](6);
     Button6->Caption  = Memo1->Lines->operator [](7);
  }else
  {
      ShowMessage("No Language File !");
  }

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Edit1Change(TObject *Sender)
{
  if (Edit1->Text == "" ) Button1->Enabled = false;
  else
  Button1->Enabled = true;;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
     ShowMessage(version);
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

//---------------------------------------------------------------------------


void __fastcall TForm1::Edit2Change(TObject *Sender)
{
  if ( Edit2->Text != "" ) Button6->Enabled = true;
  else   Button6->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
   BROWSEINFO    info;
    char          szDir[MAX_PATH];
    char          szDisplayName[MAX_PATH];
    LPITEMIDLIST  pidl;
    LPMALLOC      pShellMalloc;

    Button4->Enabled = false;

    if(SHGetMalloc(&pShellMalloc) == NO_ERROR)
    {
        memset(&info, 0x00, sizeof(info));
        info.hwndOwner = 0;
        info.pidlRoot  = NULL;
        info.pszDisplayName = szDisplayName;
        info.lpszTitle = "Browse <DIR>";
        info.ulFlags   = BIF_RETURNONLYFSDIRS|BIF_STATUSTEXT|BIF_DONTGOBELOWDOMAIN;
        info.lpfn      = BrowseProc;

        pidl = SHBrowseForFolder(&info);

        if(pidl)
        {
            if(SHGetPathFromIDList(pidl, szDir))
            {
                if ( szDir != "" ) Edit2->Text = szDir ;
                szPreDir = szDir;
            }

            //ShowMessage (info.pszDisplayName);

            pShellMalloc->Free(pidl);
            pShellMalloc->Release();
        }
    }
    Button4->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
   Edit2->Text = "";     
}
//---------------------------------------------------------------------------

