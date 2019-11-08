/*This is a cpp file which will run on Borland(Don't try in codeblocks)
It takes the inputs from user and creates a html file about your resume.
the html file is also stylized with css.
*/

#include<fstream.h> 

#include<string.h> 

#include<stdio.h> 

#include<conio.h> 

#include<process.h> 

 

void main() 

{ 

char name[30],file[30],*blank=".html"; 

char temp[200],ch; 

cout<<"Enter Name Of The WebPage : "; 

gets(name); 

strcpy(file,name); 

strcat(file,blank); 

ofstream fout(file); 

if(!fout) 

{ 

cout<<"Error In Developing The Page :"; 

exit(1); 

} 

fout<<"<html>"; 

   fout<<"<head><style>"; 

   fout<<"\nimg{border-radius: 80%;margin-left:50;margin-right:60;margin-top:50;}"; 

   fout<<"\n* {box-sizing :border-box;}"; 

   fout<<"\n.column {float: left;padding: 10px;}"; 

   fout<<"\n.left, .right {width: 30%;}\n.middle {width: 15%;}"; 

   fout<<"\n.row:after {content: \"\";display: table;clear: both;}"; 

   fout<<"\ntd,th {padding:10;text-align:center;border-bottom: 2px solid lime;-webkit-border-radius:20px;}"; 

   fout<<"\ntr:hover {background-color:#f5f5f5;}</style></head>\n"; 

   fout<<"<body bgcolor=\"#E2A9F3\">"; 

   fout<<"<p><font color=\"red\" face=\"algerian\" size=7>"; 

   cout<<"\nEnter the proper location/URL of your image with file format(Press $ to bypass this field):"; 

   gets(temp); 

   if(strcmpi(temp,"$")!=0) 

   fout<<"<img src=\""<<temp<<"\" style=\"width:160\" align=\"left\""; 

   else 

   fout<<"<img src=\"nopic.jpg\" style=\"width:160\" align=\"left\""; 

   fout<<"<br><hr size=3 color=\"black\"><b>&emsp;&emsp;&emsp;&emsp;&emsp;"; 

   cout<<"\nEnter your first name:"; 

   gets(temp); 

   fout<<temp<<"</font><font face=\"algerian\" color=\"blue\" size=7> "; 

   cout<<"\nEnter your last name:"; 

   gets(temp); 

   fout<<temp<<"</b> </font><hr size=3 color=\"black\">"; 

   fout<<"<div class=\"row\"><div class=\"column left\">"; 

   fout<<"<p align=\"left\"><font face=\"Brush Script MT\" color=\"blue\" size=6>"; 

   cout<<"\nEnter your address:"; 

   gets(temp); 

   fout<<temp<<"</font></div><div class=\"column middle\"></div><div class=\"column right\">"; 

   fout<<"<p align =\"right\"><font face=\"Brush Script MT\" color=\"red\" size=6>E-mail:"; 

   cout<<"\nEnter your e-mail address:"; 

   gets(temp); 

   fout<<temp<<"<br>Contact No.:"; 

   cout<<"\nEnter your contact number:"; 

   gets(temp); 

   fout<<temp<<"</font></p></div><br><br><br><br><br><br><br><br><br><hr size=2 color=\"black\"></p>"; 

   fout<<"<table><col bgcolor=\"#4CAF50\" color=\"white\" width=400><col width=900>"; 

   fout<<"<tr><td>Job profile:</td><td>"; 

   cout<<"\nEnter your job profile:"; 

   gets(temp); 

   fout<<temp<<"</td></tr><tr><td>Academic Record:</td><td><ul>"; 

   do{ 

   cout<<"\nEnter your academic record:"; 

   gets(temp); 

   fout<<"<li>"<<temp<<"</li>"; 

   cout<<"\nDo you want to add more records(y/n):"; 

   ch=getche(); 

   cout<<endl; 

   }while(ch=='y' || ch=='Y'); 

   fout<<"</ul></td></tr><tr><td>Hobby:</td><td><ul>"; 

   do{ 

   cout<<"\nEnter your hobbies:"; 

   gets(temp); 

   fout<<"<li>"<<temp<<"</li>"; 

   cout<<"\nDo you want to add more hobbies(y/n):"; 

   ch=getche(); 

   cout<<endl; 

   }while(ch=='y' || ch=='Y'); 

   fout<<"</ul></td></tr><tr><td>Languages known:</td><td><ul>"; 

   do{ 

   cout<<"\nLanguages known by you:"; 

   gets(temp); 

   fout<<"<li>"<<temp<<"</li>"; 

   cout<<"\nDo you want to add more languages(y/n):"; 

   ch=getche(); 

   cout<<endl; 

   }while(ch=='y' || ch=='Y'); 

   fout<<"</ul></td></tr><tr><td>Experience:</td><td><ul>"; 

   do{ 

   cout<<"\nEnter Your experience:"; 

   gets(temp); 

   fout<<"<li>"<<temp<<"</li>"; 

   cout<<"\nDo you want to add more experiences(y/n):"; 

   ch=getche(); 

   cout<<endl; 

   }while(ch=='y' || ch=='Y'); 

   fout<<"</ul></td></tr><tr><td>Skills:</td><td><ul>"; 

   do{ 

   cout<<"\nEnter your skills:"; 

   gets(temp); 

   fout<<"<li>"<<temp<<"</li>"; 

   cout<<"\nDo you want to add more skills(y/n):"; 

   ch=getche(); 

   cout<<endl; 

   }while(ch=='y' || ch=='Y'); 

   fout<<"</ul></td></tr><tr><th>Personal Details</th></tr><tr><td>Date of Birth(dd/mm/yyyy):</td><td>"; 

   cout<<"\nEnter your date of birth(dd/mm/yyyy):"; 

   gets(temp); 

   fout<<temp<<"</td></tr><tr><td>Father's name:</td><td>"; 

   cout<<"\nEnter your father's name:"; 

   gets(temp); 

   fout<<temp<<"</td></tr><tr><td>Mother's name:</td><td>"; 

   cout<<"\nEnter your mother's name:"; 

   gets(temp); 

   fout<<temp<<"</td></tr><tr><td>Martial Status:</td><td>"; 

   cout<<"\nMartial status:"; 

   gets(temp); 

   fout<<temp<<"</td></tr><tr><td>Sex:</td><td>"; 

   cout<<"\nEnter sex:"; 

   gets(temp); 

   fout<<temp<<"</td></tr><tr><td>Permanent address:</td><td>"; 

   cout<<"\nEnter your Permanent address:"; 

   gets(temp); 

   fout<<temp<<"</td></tr></table><br><hr size=3 color=\"black\"><br></body></html>"; 

   cout<<"\nEnd of your Resume Press any key to continue......"; 

   getch(); 

   fout.close(); 

} 
