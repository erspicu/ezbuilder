
#20090502 new

use Getopt::Long;

my $change_input_dir = "";
my $change_output_dir = "";
my $profile_dir = "";
my $load_profile = "";
my $fullscreen = "";

GetOptions ('change_input_dir=s' => \$change_input_dir , 'change_output_dir=s' => \$change_output_dir,
'profile_dir=s' => \$profile_dir,'fullscreen' => \$fullscreen  );


if($change_input_dir eq "")
{
  $change_input_check = "0" ;
}else
{
  $change_input_check = "1";
} 

if($change_output_dir eq "")
{
  $change_output_check = "0" ;
}else
{
  $change_output_check = "1";
} 



#########

#ezbuilder 3.1 change
if ($change_input_check == "0" )
{
  $change_input_dir = "MediaFile";
}
if ($change_output_check == "0" )
{
  $change_output_dir = "DoneFile";
}

#########


#if ( $load_profile ne "" and $profile_dir ne "" )
#{
#  system "cls";
#  print "\nWarning! \"load_profile\" [$load_profile] and \"profile_dir\" [$profile_dir] all exist.\n\n";
#  system "pause"; 
#  exit;
#}
 



##########################################################################################
#參數前置區

#ezbuilder整體參數
open(INF,"tool/ini/setup.ini");
@inftmp = <INF>;
close(INF);

foreach $line (@inftmp) {
    @tmp = split( /=/, $line );
    $tmp[1] =~ s/\n//;
    $inf{"$tmp[0]"} = $tmp[1];
}

#ezbuilder語言
open(INF,"tool/ezbuilder_lang.txt");
@inftmp = <INF>;

close(INF);
foreach $line (@inftmp) {
    @tmp = split( /=/, $line );
    $tmp[1] =~ s/\n//;
    $ez_text{"$tmp[0]"} = $tmp[1];
}

##########################################################################################


##########################################################################################
#profile載入前置區

if ( $profile_dir ne "" )
{

   #if ( $load_profile ne "")
   #{
   #   $profile_target = $load_profile;
   #}else
   #{
      $profile_target = $profile_dir;
   #}  

   #$profile_target =~ s/"//g;

   if ( -e "tool\\profile\\$profile_target\\bat_work.txt" )
   {

     #$profile_target_file = $profile_target;    
  
     #if ( $profile_dir eq "" )
     #{ 
     #  open (FILE, $profile_target);
     #  $profile_target =<FILE>;
     #  close(FILE);
     #}
  
     #$profile_target =~ s/"//g;
     $target_check = 1;
     system "cls";
     if ( -e "tool\\profile\\$profile_target\\comment.txt" )
     {
        open(FILE,"tool\\profile\\$profile_target\\comment.txt");
        $target_comment = <FILE>;
        close(FILE);
     }
     else
     {
        $target_comment = $profile_target;  
     }
     
     print "\n$ez_text{text_1}\n\n$ez_text{text_2}\n\n";

     #if ( $load_profile ne "")
     #{
     #  print "Profile target\n[$load_profile]\n\n";
     #  print "Profile path\n[$profile_target]\n\n";      
     #}else
     #{
       print "Profile path\n[$profile_dir]\n\n"; 
     #}

     print "Profile Loaded\n[$target_comment]\n\n";
   }
   else
   {
      print "\nNot find [$profile_target] file\n\n";
      system "pause";
      system "cls";
   }
}

if($change_input_check eq "1") 
{
   print  "MediaFile DIR change\n[$change_input_dir]\n\n"; 
}

if($change_output_check eq "1") 
{
   print  "DoneFile DIR change\n[$change_output_dir]\n\n"; 
}

if( $fullscreen )
{
   print  "Force FullScreen !\n"; 
} 


##########################################################################################



#主要profile處理區
while (1 and $target_check != 1 ) 
{
   if ( $access_dir eq "" ) { print "$ez_text{text_1}\n\n$ez_text{text_2}\n\n"; }  

   print "$ez_text{text_3}\n\n";
   $list = 1 ;
  
   opendir (DIR ,"tool\\profile\\$access_dir");
   while(defined( $dir = readdir(DIR)))
   {

      @tmp=split(/\./,"$dir");
      $subname = $tmp[-1];


      if ($dir ne '.' and $dir ne '..' and $subname ne 'txt')
      {


         if ( -e "tool\\profile\\$access_dir$dir\\comment.txt" )
         {
              open(FILE,"tool\\profile\\$access_dir$dir\\comment.txt");
              $comment = <FILE>;
              close(FILE);

              if( -d "tool\\profile\\$access_dir$dir" and -e "tool\\profile\\$access_dir$dir\\dir_tag.txt" )
              { print "[$list] \" $comment \"\n"; }
              else
              {print "[$list] $comment\n";}
 
         }
         else
         {  
              if( -d "tool\\profile\\$access_dir$dir" and -e "tool\\profile\\$access_dir$dir\\dir_tag.txt" )
              { print "[$list] \" $dir \"\n"; }
              else
              {print "[$list] $dir\n";}
         }


         $save_list[$list-1] =  "$dir";
         $list++;
      }
   }
   closedir (DIR);
  
   if ($list == 1)
   {
      system "cls";
      print "$ez_text{text_4}\n\n$ez_text{text_6}\n\n";
      $inf{auto_poweroff} == 0;
      system "pause" ;
     exit;
   }
 
   print "\n$ez_text{text_5} ";
   $profile_choose = <>;

   if ( $profile_choose < $list and $profile_choose >= 1 )
   {
   }else
   {  
       print "\n$ez_text{text_7}\n\n";
       system "pause";
       system "cls";

       open(FILE,"tool\\profile\\$access_dir$dir\\comment.txt");
       $comment = <FILE>;
       close(FILE);

       if ( $access_dir ne "" ) { print "$ez_text{text_1}\n\n$ez_text{text_2}\n\n"; }

       if ( $access_dir ne "" ) { print "\" $comment \"\n\n"; }
       redo;
   }
   
   if ( -e "tool\\profile\\$access_dir$save_list[$profile_choose-1]\\dir_tag.txt" )
   {
         $access_dir = "$access_dir$save_list[$profile_choose-1]\\" ;
         system "cls";
         if ( -e "tool\\profile\\$access_dir\\comment.txt" )
         {
            open(FILE,"tool\\profile\\$access_dir\\comment.txt");
            $comment = <FILE>;
            close(FILE);

            print "$ez_text{text_1}\n\n$ez_text{text_2}\n\n";
            print "\" $comment \"\n\n"; 
         }
         else
         {
            print "$ez_text{text_1}\n\n$ez_text{text_2}\n\n";
            print "$access_dir\n\n";      
         } 

         redo;
   }else
   {
      $access_dir = "$access_dir$save_list[$profile_choose-1]\\" ;
   }  

   last;

}

      if ( $target_check == 1 )
      {
         $access_dir = "$profile_target\\";
      }

      #設定參數載入
      open (FILE,"tool\\profile\\${access_dir}profile_setup.txt");
      @data = <FILE>;
      close(FILE);
      $o = 0;
      foreach $line (@data)
      {
           @tmp = split( /=/, $line );
           $tmp[1] =~ s/\n//;
           $setup_data[$o] = $tmp[0];
           $o ++ ;
           $profile_setup{"$tmp[0]"} = $tmp[1];
      } 

      open (FILE,"tool\\profile\\${access_dir}font_style.txt");
      @data = <FILE>;
      close(FILE);      
      $font_style = join("",@data); #字型載入

      open (FILE,"tool\\profile\\${access_dir}avs_deal.txt");
      @data = <FILE>;
      close(FILE);      
      $avs_deal = join("",@data); #avs處理效果載入

      open (FILE,"tool\\profile\\${access_dir}bat_work.txt");
      @data = <FILE>;
      close(FILE);      
      $bat_work = join("",@data); #bat工作流程載入

$avs_deal_org = $avs_deal ;
$bat_work_org = $bat_work ; 

$count = 0;

#print "\n[切分點 $change_input_dir ]\n";
#system "pause";


opendir( DIR,"$change_input_dir");
open (BAT,">tool/build.bat");
while(defined( $dir = readdir(DIR)))
{
   if ($dir ne '.' and $dir ne '..')
   { 
      @tmp=split(/\./,"$dir");
      $subname = $tmp[-1];

      $main_name = $dir;
      pop (@tmp);   
      $main_name = join(".",@tmp); 
     #=~ s/\.$tmp[-1]//;

      #電影檔avs載入,剃除字幕檔
        
         $subname_tmp =  $subname  ;
         $subname = lc "$subname" ;

###################################################################      
      # ezbuilder file linker 處理區開始
  
      if( $subname eq "efl")
      {
      
            #ezbuilder 3.1 change
            open (EFL,"$change_input_dir\\$dir");
            $efl_file = <EFL>;
            close(EFL);
            $efl_file =~ s/"//g;
            $efl_file_check = 1;
            @tmp_elf =split(/\./,"$efl_file");
            pop (@tmp_elf);
            $elf_f = join(".",@tmp_elf); 
            @tmp=split(/\./,"$main_name");
            pop (@tmp);
            $main_name = join(".",@tmp);
      }
      
      # ezbuilder file linker 結束
###################################################################

  
      if( $subname eq "srt" or $subname eq "style" or
          $subname eq "ssa" or $subname eq "idx"   or
          $subname eq "sub"  or $subname eq "ass" 
         )
       {
         if ( $subname ne  $subname_tmp )
         {
             rename("$change_input_dir\\$main_name.$subname_tmp","$change_input_dir\\$main_name.$subname")
         }
       }     

      if( $subname ne "srt" and $subname ne "style" and
          $subname ne "db"  and $subname ne "idx"   and
          $subname ne "sub"  and $subname ne "ass"   and
          $subname ne "ssa" )
      {
          open(FILE,">temp/temp_avs_$count.avs");
 
          #設定檔參數載入
          foreach $line (@setup_data)
          {
           $avs_deal_org =~ s/$line/$profile_setup{"$line"}/g;
           $bat_work_org =~ s/$line/$profile_setup{"$line"}/g;
          } 
          
          #檔案載入avs profile內容

          #elf
          if ( $efl_file_check == 1 )
          {
             $avs_deal = $avs_deal_org;
             #$x = "..\\MediaFile\\File_To_Load";
             #$avs_deal =~ s/$x/$efl_file/g;
              $avs_deal =~ s/..\\MediaFile\\File_To_Load/$efl_file/g; 
          }
          else
          {
             $avs_deal = $avs_deal_org;
             $avs_deal =~ s/File_To_Load/$dir/g;
             ##ezbuilder 3.1 change
             if ( $change_input_check == "1" )
             { 
               $avs_deal =~ s/..\\MediaFile\\/$change_input_dir\\/g;
             } 
          }
          ######## 20090502   
          if ( $fullscreen )
          {
             $avs_deal =~ s/FL_SETUP/true/g;
             #system "pause"; 
          }else
          {
             $avs_deal =~ s/FL_SETUP/false/g;
             #system "pause";      
          }  
          #########
          print FILE $avs_deal;

          #檔案載入bat work profile內容
          $bat_work = $bat_work_org;
          $bat_work =~ s/AvsNumberLoad/$count/g;
          $bat_work =~ s/MainFileLoad/$main_name/g;
          $bat_work =~ s/DoneFile/$change_output_dir/g;
          
             #ezbuilder 3.1新增
          if ( $efl_file_check  == 1 )
          {
               $bat_work =~ s/File_To_Load/$efl_file/g;
          }else
          {
               if($change_input_check ==1)
               {
                  $bat_work =~ s/File_To_Load/"$change_input_dir\\$dir"/g;   
               }else
               {
                 $bat_work =~ s/File_To_Load/"..\\MediaFile\\$dir"/g;  
               }    
          }
          $bat_work =~ s/CPU_CORES/$inf{CPU_cores}/g;
        

          print BAT $bat_work; 

          $loaded = 0;

          #檢查是否有idx&sub字幕檔,有的話載入
          if( -e "$change_input_dir/$main_name.idx" )
          { 
            if ( $change_input_check == 1 )
            {
               print FILE  "\nvobsub(\"$change_input_dir\\$main_name.idx\")\n";
            }else
            {
               print FILE  "\nvobsub(\"..\\$change_input_dir\\$main_name.idx\")\n";
            } 
            $loaded = 1;
          }
          #elf
          if ( $efl_file_check == 1 and -e "$elf_f.idx")
          {
            print FILE  "\nvobsub(\"$elf_f.idx\")\n";
            $loaded = 1;
          }

          #檢查是否有ass字幕檔,有的話載入
          if( -e "$change_input_dir/$main_name.ass" and $inf{textsub_direct} == 1 and $loaded == 0)
          {

            if ( $change_input_check == 1 ) 
            {
                 print FILE  "\ntextsub(\"$change_input_dir\\$main_name.ass\")\n";
            }else
            {
                 print FILE  "\ntextsub(\"..\\$change_input_dir\\$main_name.ass\")\n";
            }
            $loaded = 1; 
          }
          #elf
          if( $efl_file_check == 1 and -e "$elf_f.ass" and $inf{textsub_direct} == 1 and $loaded == 0)
          { 
            print FILE  "\ntextsub(\"$elf_f.ass\")\n";
            $loaded = 1; 
          }

          #檢查是否有ssa字幕檔,有的話載入
          if( -e "$change_input_dir/$main_name.ssa" and $inf{textsub_direct} == 1 and $loaded == 0)
          { 

            if ( $change_input_check == 1 ) 
            {
              print FILE  "\ntextsub(\"$change_input_dir\\$main_name.ssa\")\n";     
            }else
            {
               print FILE  "\ntextsub(\"..\\$change_input_dir\\$main_name.ssa\")\n";
            }
            $loaded = 1;   
          } 
          #elf
          if( $efl_file_check == 1 and -e "$elf_f.ssa" and $inf{textsub_direct} == 1 and $loaded == 0)
          { 
            print FILE  "\ntextsub(\"$elf_f.ssa\")\n";
            $loaded = 1; 
          }


          #檢查是否有ass字幕檔,有的話轉換成srt載入
          if( -e "$change_input_dir/$main_name.ass" and $inf{textsub_direct} != 1 and $loaded == 0)
          { 
            open(FILE_t,"$change_input_dir/$main_name.ass");
            @data = <FILE_t>;
            close(FILE_t);
  
            $encode_type = "utf16-le";

            for($i=0;$i<=30;$i++)
            {
                if( $data[$i] =~/Style: Default/g)
                {
                     $encode_type = $inf{language};
                     last;
                 }
            }
            system ("tool\\ass2srt.exe -f $encode_type -t utf16-le -c -o  \"$change_input_dir/$main_name.ass\" \"$change_input_dir/$main_name.srt\" ");
            open( STYLE,">$change_input_dir/$main_name.srt.style");
            print STYLE "$font_style"; 
            close(STYLE);
            $del ="del \"$change_input_dir\\$main_name.srt.style\" \"$change_input_dir\\$main_name.srt\"\n$del";
            if ( $change_input_check == 1 ) 
            {
               print FILE  "\ntextsub(\"$change_input_dir\\$main_name.srt\")\n";
            }else
            {
               print FILE  "\ntextsub(\"..\\$change_input_dir\\$main_name.srt\")\n";  
            } 
            $loaded = 1; 
          }

          # ezbuilder file linker版本 檢查是否有ass字幕檔,有的話轉換成srt載入
          if( $efl_file_check == 1 and -e "$elf_f.ass"  and $inf{textsub_direct} != 1 and $loaded == 0)
          { 
            open(FILE_t,"$elf_f.ass");
            @data = <FILE_t>;
            close(FILE_t);
  
            $encode_type = "utf16-le";

            for($i=0;$i<=30;$i++)
            {
                if( $data[$i] =~/Style: Default/g)
                {
                     $encode_type = $inf{language};
                     last;
                 }
            }
            system ("tool\\ass2srt.exe -f $encode_type -t utf16-le -c -o  \"$elf_f.ass\" \"$elf_f.ass.srt\" ");
            open( STYLE,">$elf_f.style");
            print STYLE "$font_style"; 
            close(STYLE);
            $del ="del \"$elf_f.srt.style\" \"$elf_f.srt\"\n$del";
            print FILE  "\ntextsub(\"$elf_f.srt\")\n";
            $loaded = 1; 
          }

          #檢查是否有ssa字幕檔,有的話轉換成srt載入
          if( -e "$change_input_dir/$main_name.ssa" and $inf{textsub_direct} != 1 and $loaded == 0)
          {
            open(FILE_t,"$change_input_dir/$main_name.ssa");
            @data = <FILE_t>;
            close(FILE_t);
  
            $encode_type = "utf16-le";

            for($i=0;$i<=30;$i++)
            {
                if( $data[$i] =~/Style: Default/g)
                {
                     $encode_type = $inf{language};
                     last;
                 }
            }
            system ("tool\\ass2srt.exe -f $encode_type -t utf16-le -c -o  \"$change_input_dir\\$main_name.ssa\" \"$change_input_dir\\$main_name.srt\" ");
            open( STYLE,">$change_input_dir/$main_name.srt.style");
            print STYLE "$font_style"; 
            close(STYLE);
            $del ="del \"$change_input_dir\\$main_name.srt.style\" \"$change_input_dir\\$main_name.srt\"\n$del";
            print FILE  "\ntextsub(\"..\\$change_input_dir\\$main_name.srt\")\n";
            $loaded = 1;
          } 


          # ezbuilder file linker版本 檢查是否有ssa字幕檔,有的話轉換成srt載入
          if($efl_file_check == 1 and -e "$elf_f.ssa" and $inf{textsub_direct} != 1 and $loaded == 0)
          {
            open(FILE_t,"$elf_f.ssa");
            @data = <FILE_t>;
            close(FILE_t);
  
            $encode_type = "utf16-le";

            for($i=0;$i<=30;$i++)
            {
                if( $data[$i] =~/Style: Default/g)
                {
                     $encode_type = $inf{language};
                     last;
                 }
            }
            system ("tool\\ass2srt.exe -f $encode_type -t utf16-le -c -o  \"$elf_f.ssa\" \"$elf_f.srt\" ");
            open( STYLE,">$elf_f.srt.style");
            print STYLE "$font_style"; 
            close(STYLE);
            $del ="del \"$elf_f.srt.style\" \"$elf_f.srt\"\n$del";
            print FILE  "\ntextsub(\"$elf_f.srt\")\n";
            $loaded = 1;
          } 



          #檢查是否有srt字幕檔,有的話載入
          if( -e "$change_input_dir/$main_name.srt" and $loaded == 0)
          { 

             open( STYLE,">$change_input_dir/$main_name.srt.style");
             print STYLE "$font_style"; 
             close(STYLE);
             $del ="del \"$change_input_dir\\$main_name.srt.style\"\n$del";
             if( $change_input_check == "1")
             {
                 print FILE  "\ntextsub(\"$change_input_dir\\$main_name.srt\")\n";  
             }else
             { 
                 print FILE  "\ntextsub(\"..\\$change_input_dir\\$main_name.srt\")\n";
             }
             $loaded = 1;
          }   

          # ezbuilder file linker版本 檢查是否有srt字幕檔,有的話載入
          if($efl_file_check == 1 and  -e "$elf_f.srt" and $loaded == 0)
          { 

             open( STYLE,">$elf_f.srt.style");
             print STYLE "$font_style"; 
             close(STYLE);
             $del ="del \"$elf_f.srt.style\"\n$del";
             print FILE  "\ntextsub(\"$elf_f.srt\")\n";
             $loaded = 1;
          } 

          if ( $inf{normalize} == 1 ){ print FILE "normalize()\n";}
          print FILE "\nreturn last"; 
          close(FILE);


          if( $subname eq "avs")
          {  
              system ("copy \"$change_input_dir\\$main_name.avs\" \"temp\\temp_avs_$count.avs\" ");
          }
          
          # ezbuilder file linker 版本 avs直接載入
          if( $efl_file_check == 1 and $subname eq "avs")
          {  
              system ("copy \"$elf_f.avs\" \"temp\\temp_avs_$count.avs\" ");
          }

          $count++;
          $efl_file_check = 0 ;
      } 
   }
} 
print BAT "$del\n";
close(BAT);
closedir(DIR);

##########################################################################################
#末項處理

if ( $count == 0 ) 
{
  system "cls";
  $inf{auto_poweroff} == 0;
  print "\n$ez_text{text_9}\n\n";
  system "pause";
}

if($inf{load_avs} == 1)
{
      open(FILE,"tool/avs_insert.txt");
      @data = <FILE>;
      close(FILE);
      $insert = join("",@data);
      $count = 0 ;
      opendir( DIR,"$change_input_dir");
      while(defined( $dir = readdir(DIR)))
      {
         if ($dir ne '.' and $dir ne '..')
         { 
            @tmp=split(/\./,"$dir");
            $subname = $tmp[-1];

            $main_name = $dir;
            $main_name =~ s/\.$tmp[-1]//;

            if( $subname ne "srt" and $subname ne "style" and $subname ne "db")
            {
      
                   open(FILE,"temp/temp_avs_$count.avs");
                   @data_org = <FILE>;
                   close(FILE);
                   $data_org[-1] = "$insert\n$data_org[-1]";  
                   open(FILE,">temp/temp_avs_$count.avs");
                   print FILE @data_org;
                   close(FILE);
                   $count++;
            } 
         }
      } 
      closedir(DIR);
}

system "tool\\build.bat";

# if($inf{auto_poweroff} == 1){ system "shutdown -s -c \"$ez_text{text_8}\" -t 20"; }




