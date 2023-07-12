#include<iostream.h>
#include<fstream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
class student
{
private:
char buf[45],name[10],sem[10],branch[10];
public:
void read()
{
cout<<"Name: "<<endl;
cin>>name;
cout<<"Semester: "<<endl;
cin>>sem;
cout<<"Branch: "<<endl;
cin>>branch;
}
void pack(fstream &ofile)
{
read();
strcpy(buf,"");
strcat(buf,name);
strcat(buf,"|");
strcat(buf,sem);
strcat(buf,"|");
strcat(buf,branch);
strcat(buf,"|");
while(strlen(buf)<45)
strcat(buf,"!");
strcat(buf,"\n");
ofile.write(buf,strlen(buf));
}
void unpack(fstream &ifile)
{
char extra[45];
while(!ifile.eof())
{
ifile.getline(name,10,'|');
ifile.getline(sem,10,'|');
ifile.getline(branch,10,'|');
ifile.getline(extra,45,'\n');
cout<<name<<"\t"<<sem<<"\t"<<branch<<"\n";
} }
int search(fstream &ifile,char key[])
{
char extra[45];
while(!ifile.eof())
{
 ifile.getline(name,10,'|');
 ifile.getline(sem,10,'|');
 ifile.getline(branch,10,'|');
 ifile.getline(extra,45,'\n');
 if(strcmp(name,key)==0)
{
cout<<"Record found and details are:"<<endl;
cout<<"Name: "<<name<<endl;
cout<<"Semester: "<<sem<<endl;
cout<<"Branch: "<<branch<<endl;
return 1;
} }
return 0;
}
void modify(fstream &iofile,char key[])
{
if(search(iofile,key))
{
cout<<"Record found,enter modification details:"<<endl;
iofile.seekp(-47,ios::cur);
pack(iofile);
}
else
cout<<"Sorry!No such record\n";
}
};
void main() {
int n,i,ch;
student stu;
fstream ofile;
ofile.open("student.txt",ios::trunc|ios::app);
ofile.close();
clrscr();
for(;;)
{
clrscr();
cout<<"1. Insert\n2. Display all\n3. Search\n4. Modify\n5. 
Exit\n";
cout<<"Enter your choice"<<endl;
cin>>ch;
switch(ch)
{
case 1: fstream ofile;
ofile.open("student.txt",ios::out|ios::app);
cout<<"Enter the no. of students"<<endl;
cin>>n;
for(i=0;i<n;i++)
{
stu.pack(ofile);
}
ofile.close();
break;
case 2: fstream infile;
infile.open("student.txt",ios::in);
stu.unpack(infile);
getch();
infile.close();
break;
case 3: cout<<"Enter the record name to be searched"<<endl;
char key[10];
cin>>key;
fstream ifile;
ifile.open("student.txt",ios::in);
if(stu.search(ifile,key)==0)
cout<<"record not found\n";
getch();
ifile.close();
break;
case 4: fstream iofile;
iofile.open("student.txt",ios::in|ios::out);
cout<<"Enter the record name to be modified"<<endl;
cin>>key;
stu.modify(iofile,key);
getch();
iofile.close();
break;
default: exit(0);
} } }
