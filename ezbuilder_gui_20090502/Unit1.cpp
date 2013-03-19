//---------------------------------------------------------------------------
#define NO_WIN32_LEAN_AND_MEAN
#include <shlobj.h>
#include <WindowsX.h>
#define BIF_NEWDIALOGSTYLE 0x0040
#include <vcl.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;


//void profile_return(void)

///
AnsiString szPreDir = "";
int __stdcall BrowseProc(HWND hwnd,UINT uMsg, LPARAM lParam, LPARAM lpData )
{
    char szDir[MAX_PATH];

    switch(uMsg)
    {
        case BFFM_INITIALIZED:
            SendMessage(hwnd, BFFM_SETSTATUSTEXT,0, (LPARAM)"Greetings");
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





AnsiString ver_date = "2009.05.18\n\n";
AnsiString version = "Ezbuilder GUI\n\ncopyright by erspicu_brox\n\nVer " + ver_date ;




TStringList* listbox_dir_save = new TStringList();
TStringList* comment_inf = new TStringList();
AnsiString c_dir= "tool\\profile\\";
AnsiString ezbuilder_core,x1,x2,x3,x4,x5,x6,x7;


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
   DIR *pdir;
    struct dirent *pent;
    AnsiString tmp,tmp2,tmp3,tmp4;

    ListBox1->Clear();
    Memo2->Lines->Delete(0);
    //Image1->Picture->LoadFromFile("myico-8bit.ico");

////////////
if ( FileExists ("tool\\ezbuilder_gui_lang.txt") )
{
     Memo1->Lines->LoadFromFile("tool\\ezbuilder_gui_lang.txt");
     ezbuilder_core = Memo1->Lines->operator [](0);
     Form1->Caption = Memo1->Lines->operator [](1);
     x1 = Memo1->Lines->operator [](2);
     Edit1->Text = x1;
     x2 = Memo1->Lines->operator [](3);
     x3 = Memo1->Lines->operator [](4);
     Button1->Caption =  Memo1->Lines->operator [](5);
     Button2->Caption =  Memo1->Lines->operator [](6);
     Button3->Caption =  Memo1->Lines->operator [](7);
     x4  =  Memo1->Lines->operator [](8);
     x5  =  Memo1->Lines->operator [](9);
     Button4->Caption =  Memo1->Lines->operator [](10);
     Button5->Caption =  Memo1->Lines->operator [](11);
     Button6->Caption =  Memo1->Lines->operator [](12);
     Button7->Caption =  Memo1->Lines->operator [](13);
     CheckBox1->Caption =  Memo1->Lines->operator [](14)+ "    ";
     Button8->Caption =  Memo1->Lines->operator [](15);
     Label1->Caption =  Memo1->Lines->operator [](16)+ "    ";
     Button9->Caption =  Memo1->Lines->operator [](17);
     CheckBox2->Caption =  Memo1->Lines->operator [](18)+ "    ";
     x6 =  Memo1->Lines->operator [](19);
     x7 =  Memo1->Lines->operator [](20);
     CheckBox3->Caption =  Memo1->Lines->operator [](21)+ "    ";
}else
{
     ShowMessage("No Language File !");
     x1 = "Profile Choose : ";
     x2 = "[DIR ] ";
     x3 = "[Item] ";
     x4 = "ezbuilder start running";
     x5 = "ezbuilder finshed !";
}




////////////

    Button1->Enabled =false;
    pdir=opendir(c_dir.c_str());
    while ((pent=readdir(pdir)))
    {
       tmp = pent->d_name ;
       if (tmp != "." && tmp != "..")
       {
           tmp2 = c_dir + tmp +"\\comment.txt";
           tmp3 = c_dir  + tmp +"\\dir_tag.txt";
           if ( FileExists(tmp2))
           {
                comment_inf->LoadFromFile(tmp2);
                if ( FileExists(tmp3) )
                {
                  tmp4 = x2 + "  " + comment_inf->operator [](0);
                  ListBox1->Items->Add(tmp4);
                }else
                {
                  tmp4 = x3 + "  "  + comment_inf->operator [](0);
                  ListBox1->Items->Add(tmp4);
                }
            }
            else
            {
                if ( FileExists(tmp3) )
                {
                  tmp4 = x2 + "  " + tmp;
                  ListBox1->Items->Add(tmp4);
                }else
                {
                  tmp4 = x3 + "  "  + tmp;
                  ListBox1->Items->Add(tmp4);
                }
            }
            listbox_dir_save->Add(tmp);
       }
    }
    closedir(pdir);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
     exit(1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
  ShowMessage(version);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ListBox_Choose(TObject *Sender)
{

  AnsiString tmp,tmp2,tmp3,tmp4,tmp5,tmp6;
  DIR *pdir;
  struct dirent *pent;

  tmp =  c_dir + listbox_dir_save->operator [](ListBox1->ItemIndex) + "\\dir_tag.txt";
  c_dir = c_dir + listbox_dir_save->operator [](ListBox1->ItemIndex) +"\\";

  if ( c_dir != "tool\\profile\\" ) Button1->Enabled = true;
  else  Button1->Enabled = false;

  tmp5 = ListBox1->Items->operator [](ListBox1->ItemIndex);

  Edit1->Text = x1 + tmp5;

  listbox_dir_save->Clear();
  ListBox1->Clear();
  Application->ProcessMessages();
  if (FileExists(tmp)) //檢查是否是一個目錄項目
  {
////////////////////////////////////////
     pdir=opendir(c_dir.c_str());

     while ((pent=readdir(pdir)))
     {
         tmp = pent->d_name ;
         if (tmp != "." && tmp != ".." && tmp!= "comment.txt" &&  tmp!= "dir_tag.txt" )
         {
             tmp2 = c_dir  + tmp +"\\comment.txt";
             tmp3 = c_dir  + tmp +"\\dir_tag.txt";
             if ( FileExists(tmp2) )
             {
                comment_inf->Clear();
                comment_inf->LoadFromFile(tmp2);
                if ( FileExists(tmp3) )
                {
                  tmp4 = x2 + "  " + comment_inf->operator [](0);
                  ListBox1->Items->Add(tmp4);
                }else
                {
                  tmp4 = x3 + "  "  + comment_inf->operator [](0);
                  ListBox1->Items->Add(tmp4);
                }
             }
             else
             {
                if ( FileExists(tmp3) )
                {
                  tmp4 = x2 + "  " + tmp;
                  ListBox1->Items->Add(tmp4);
                }else
                {
                  tmp4 = x3 + "  "  + tmp;
                  ListBox1->Items->Add(tmp4);
                }
             }
             listbox_dir_save->Add(tmp);
         }
     }
     closedir(pdir);
//////////////////////////////////////
  }else
  {
     tmp6 = c_dir;
     tmp6.Delete(1,13);
     tmp6.Delete(tmp6.Length(),1);
     AnsiString cmd ="";
     cmd = ezbuilder_core + " -profile_dir ";
     cmd =  cmd +"\"";
     cmd = cmd + tmp6 + "\"";
     if(Edit2->Text != "")
     {
        cmd = cmd + " -change_input_dir ";
        cmd = cmd + "\""+ Edit2->Text +"\"";
     }

     if(Edit3->Text != "")
     {
        cmd = cmd + " -change_output_dir ";
        cmd = cmd + "\""+  Edit3->Text +"\"";
     }
     //////////// ezbuilder 0.4 add
     if ( CheckBox3->Checked == true )
     {
         cmd = cmd + " -fullscreen ";
     }
     ///////////
     if ( CheckBox1->Checked == true )
     {
         Memo2->Lines->Add(cmd);

//////////////////////////  12345678
    int i,l;
    DIR *pdir;
    struct dirent *pent;
    AnsiString tmp,tmp2,tmp3,tmp4,tmp5;

    c_dir.Delete(c_dir.Length(),1);

    l = c_dir.Length();
    i=l;
    while ( c_dir[l] != '\\'  ) l--;

    l++;
    c_dir.Delete(l,i-l+1);

    tmp5 = c_dir;

    tmp3 = c_dir + "comment.txt";

    if ( FileExists(tmp3) )
    {
        comment_inf->LoadFromFile(tmp3);
        Edit1->Text = x1 + x2 + "  " +  comment_inf->operator [](0);
    }else if ( c_dir != "tool\\profile\\" )
    {
         l = tmp5.Length();
         tmp5.Delete(l,1);
         l = tmp5.Length();
         while ( tmp5[l] != '\\'  )l--;
         tmp5.Delete(1,l);
         Edit1->Text = x1 + tmp5;
    }
    if ( c_dir == "tool\\profile\\" )  Edit1->Text = x1;
    listbox_dir_save->Clear();
    ListBox1->Clear();
    pdir=opendir(c_dir.c_str());
    while ((pent=readdir(pdir)))
    {
       tmp = pent->d_name ;
       if (tmp != "." && tmp != ".." && tmp!= "comment.txt" &&  tmp!= "dir_tag.txt")
       {
           tmp2 = c_dir + tmp +"\\comment.txt";
           tmp3 = c_dir  + tmp +"\\dir_tag.txt";
           if ( FileExists(tmp2))
           {
                comment_inf->LoadFromFile(tmp2);
                if ( FileExists(tmp3) )
                {
                  tmp4 = x2 + "  "+ comment_inf->operator [](0);
                  ListBox1->Items->Add(tmp4);
                }else
                {
                  tmp4 = x3 + "  "  + comment_inf->operator [](0);
                  ListBox1->Items->Add(tmp4);
                }
            }
            else
            {
                if ( FileExists(tmp3) )
                {
                  tmp4 = x2 + "  " + tmp;
                  ListBox1->Items->Add(tmp4);
                }else
                {
                  tmp4 = x3 + "  "  + tmp;
                  ListBox1->Items->Add(tmp4);
                }
            }
            listbox_dir_save->Add(tmp);
       }
    }
    closedir(pdir);
    if ( c_dir == "tool\\profile\\" )
    {
       Button1->Enabled = false;
    }
////////////////////////  12345678

     }else
     {
         Form1->Visible = false;

         if (CheckBox2->Checked == true )
         {
             AnsiString poweroff;
             system ( cmd.c_str() );
             poweroff = "shutdown -s -c \"" + x6 + "\" -t 20";
             poweroff = "\"" + poweroff + "\"";
             system ( poweroff.c_str() );
         }else
         {
             ShowMessage(x4);
             system ( cmd.c_str() );
             ShowMessage(x5);
             exit(1);
         }
     }
  }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int i,l;
    DIR *pdir;
    struct dirent *pent;
    AnsiString tmp,tmp2,tmp3,tmp4,tmp5;

    c_dir.Delete(c_dir.Length(),1);

    l = c_dir.Length();
    i=l;
    while ( c_dir[l] != '\\'  ) l--;

    l++;
    c_dir.Delete(l,i-l+1);

    tmp5 = c_dir;

    tmp3 = c_dir + "comment.txt";

    if ( FileExists(tmp3) )
    {
        comment_inf->LoadFromFile(tmp3);
        Edit1->Text = x1 + x2 + "  " +  comment_inf->operator [](0);
    }else if ( c_dir != "tool\\profile\\" )
    {
         l = tmp5.Length();
         tmp5.Delete(l,1);
///////////////////////////
         l = tmp5.Length();
         while ( tmp5[l] != '\\'  )l--;
         tmp5.Delete(1,l);
         Edit1->Text = x1 + tmp5;
///////////////////////////
    }
    if ( c_dir == "tool\\profile\\" )  Edit1->Text = x1;

///////////////////////////////  xyz

    listbox_dir_save->Clear();
    ListBox1->Clear();


    pdir=opendir(c_dir.c_str());
    while ((pent=readdir(pdir)))
    {
       tmp = pent->d_name ;
       if (tmp != "." && tmp != ".." && tmp!= "comment.txt" &&  tmp!= "dir_tag.txt")
       {
           tmp2 = c_dir + tmp +"\\comment.txt";
           tmp3 = c_dir  + tmp +"\\dir_tag.txt";
           if ( FileExists(tmp2))
           {
                comment_inf->LoadFromFile(tmp2);
                if ( FileExists(tmp3) )
                {
                  tmp4 = x2 + "  "+ comment_inf->operator [](0);
                  ListBox1->Items->Add(tmp4);
                }else
                {
                  tmp4 = x3 + "  "  + comment_inf->operator [](0);
                  ListBox1->Items->Add(tmp4);
                }
            }
            else
            {
                if ( FileExists(tmp3) )
                {
                  tmp4 = x2 + "  " + tmp;
                  ListBox1->Items->Add(tmp4);
                }else
                {
                  tmp4 = x3 + "  "  + tmp;
                  ListBox1->Items->Add(tmp4);
                }
            }
            listbox_dir_save->Add(tmp);
       }
    }
    closedir(pdir);
    if ( c_dir == "tool\\profile\\" )
    {
       Button1->Enabled = false;
    }

}
//---------------------------------------------------------------------------



/*void __fastcall TForm1::ListBox_key_enter(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if(Key==13)
   {
//////////////////////////////////////////////////////////////
  AnsiString tmp,tmp2,tmp3,tmp4,tmp5,tmp6;
  DIR *pdir;
  struct dirent *pent;

  tmp =  c_dir + listbox_dir_save->operator [](ListBox1->ItemIndex) + "\\dir_tag.txt";
  c_dir = c_dir + listbox_dir_save->operator [](ListBox1->ItemIndex) +"\\";

  if ( c_dir != "tool\\profile\\" ) Button1->Enabled = true;
  else  Button1->Enabled = false;

  tmp5 = ListBox1->Items->operator [](ListBox1->ItemIndex);

  Edit1->Text = x1 + tmp5;

  listbox_dir_save->Clear();
  ListBox1->Clear();
  Application->ProcessMessages();
  if (FileExists(tmp)) //檢查是否是一個目錄項目
  {
////////////////////////////////////////
     pdir=opendir(c_dir.c_str());

     while ((pent=readdir(pdir)))
     {
         tmp = pent->d_name ;
         if (tmp != "." && tmp != ".." && tmp!= "comment.txt" &&  tmp!= "dir_tag.txt" )
         {
             tmp2 = c_dir  + tmp +"\\comment.txt";
             tmp3 = c_dir  + tmp +"\\dir_tag.txt";
             if ( FileExists(tmp2) )
             {
                comment_inf->Clear();
                comment_inf->LoadFromFile(tmp2);
                if ( FileExists(tmp3) )
                {
                  tmp4 = x2 + "  " + comment_inf->operator [](0);
                  ListBox1->Items->Add(tmp4);
                }else
                {
                  tmp4 = x3 + "  "  + comment_inf->operator [](0);
                  ListBox1->Items->Add(tmp4);
                }
             }
             else
             {
                if ( FileExists(tmp3) )
                {
                  tmp4 = x2 + "  " + tmp;
                  ListBox1->Items->Add(tmp4);
                }else
                {
                  tmp4 = x3 + "  "  + tmp;
                  ListBox1->Items->Add(tmp4);
                }
             }
             listbox_dir_save->Add(tmp);
         }
     }
     closedir(pdir);
//////////////////////////////////////
  }else
  {
     FILE *fp;
     fp = fopen ("tool\\profile_target.txt","w");
     tmp6 = c_dir;
     tmp6.Delete(1,13);
     tmp6.Delete(tmp6.Length(),1);
     fprintf (fp,"\"%s\"",tmp6.c_str());
     fclose(fp);
     Form1->Visible = false;
     ShowMessage(x4);
     system ("Ezbuilder_08b.exe -load_profile \"tool\\profile_target.txt\"  ");
     //system ("pause");
     //Button1->Enabled = true;
     //Button2->Enabled = true;
     //Button3->Enabled = true;
     ShowMessage(x5);
     //Form1->Visible = true;
     exit(1);
  }
//////////////////////////////////////////////////////////////
   }
}
*/
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
        info.lpszTitle = "Browse Title";
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


void __fastcall TForm1::Button5Click(TObject *Sender)
{
   BROWSEINFO    info;
    char          szDir[MAX_PATH];
    char          szDisplayName[MAX_PATH];
    LPITEMIDLIST  pidl;
    LPMALLOC      pShellMalloc;

    Button5->Enabled = false;

    if(SHGetMalloc(&pShellMalloc) == NO_ERROR)
    {
        memset(&info, 0x00, sizeof(info));
        info.hwndOwner = 0;
        info.pidlRoot  = NULL;             
        info.pszDisplayName = szDisplayName;
        info.lpszTitle = "Browse Title";
        info.ulFlags   = BIF_RETURNONLYFSDIRS|BIF_STATUSTEXT|BIF_DONTGOBELOWDOMAIN;
        info.lpfn      = BrowseProc;

        pidl = SHBrowseForFolder(&info);

        if(pidl)
        {
            if(SHGetPathFromIDList(pidl, szDir))
            {
                if ( szDir != "" ) Edit3->Text = szDir ;
                szPreDir = szDir;
            }

            //ShowMessage (info.pszDisplayName);

            pShellMalloc->Free(pidl);
            pShellMalloc->Release();
        }
    }
    Button5->Enabled = true;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button6Click(TObject *Sender)
{
  Edit2->Text = "";        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
  Edit3->Text = "";        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit2Change(TObject *Sender)
{
   if(Edit2->Text == "" ) Button6->Enabled = false;
   else Button6->Enabled = true;
   if ( Edit2->Text != "" &&  Edit2->Text == Edit3->Text )
   {
      ShowMessage (x7);
      Edit2->Text = "";
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit3Change(TObject *Sender)
{
   if(Edit3->Text == "" ) Button7->Enabled = false;
   else Button7->Enabled = true;
   if ( Edit3->Text != "" &&  Edit3->Text == Edit2->Text )
   {
      ShowMessage (x7);
      Edit3->Text = "";
   }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
  if ( CheckBox1->Checked == true && Memo2->Lines->operator [](0) != "" ) Button8->Enabled = true;
  else  Button8->Enabled = false;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Memo2Change(TObject *Sender)
{
  if ( CheckBox1->Checked == true && Memo2->Lines->operator [](0) != "" )
  Button8->Enabled = true;
  if ( Memo2->Lines->Count != 0 ) Button9->Enabled = true;
  else
  Button9->Enabled = false;
  if ( Memo2->Lines->Count != 0 ) Button8->Enabled = true;
  else
  Button8->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
 Form1->Visible = false ;
 Memo2->Lines->SaveToFile("tool\\batch_wok.bat");
 if (CheckBox2->Checked == true )
 {
   AnsiString poweroff;
   system ("tool\\batch_wok.bat");
   poweroff = "shutdown -s -c \"" + x6 + "\" -t 20";
   poweroff = "\"" + poweroff + "\"";
   system ( poweroff.c_str() );
 }else
 {
    ShowMessage(x4);
    system ("tool\\batch_wok.bat");
    ShowMessage(x5);
    exit(1);
 }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button9Click(TObject *Sender)
{
  Memo2->Lines->Delete( Memo2->Lines->Count -1  );
}
//---------------------------------------------------------------------------








