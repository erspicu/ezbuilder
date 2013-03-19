print "\n\nEzbuilder Profile install tool 1.0 \n\nCopyRight erspicu_brox 2009.01.01\n";

if ( $ARGV[0] ne "") { $url = $ARGV[0]; print "\nPROFILE [$url]\n"; }
else{    
print "\ninput profile download url : ";
$url =<>;
}

$work_dir = $0;
@tmp = split(/\\/ , $work_dir);
pop(@tmp);
pop(@tmp);
$work_dir = join("\\",@tmp);


$url  =~ s/\n//;
$x = "/";
$url  =~ s/\\/$x/g;
@tmp = split("/",$url);
$file = $tmp[-1];

print "\nprofile downloading...\n";

$s1 = substr($url,0,4);
$s2 = substr($url,0,3);

if ( $s1 ne "http" and $s2 ne "ftp" )
{
   #print "\n[檔案模式]\n\n";
   system "copy /b \"$url\" \"$work_dir\\temp\\$file\" ";
}else
{ 
   #print "\n[網路模式]\n\n";
   system "\"$work_dir\\tool\\wget.exe\" \"$url\" -O \"$work_dir\\temp\\$file\" ";
}


print "\ndownload finished...\n\n";
print "installing profile...\n";
system "\"$work_dir\\tool\\7za.exe\" x \"$work_dir\\temp\\$file\" -o\"$work_dir\\\" -r -y"; 
system "del \"$work_dir\\temp\\$file\" ";
print "\ninstall finished!\n\n";
system "pause";
