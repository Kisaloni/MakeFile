#include<iostream>
#include<fstream>
#include<string>
#include<cksupport.h>
#include<conio.h>

using namespace std;

int Mygets(char*);
class Application
{
    char name[100];
    fstream file;
    char *getfilename();
    inline void Write();
public:
    void Create();
    void Open();
};

void Application::Open()
{
    cout<<"\nEnter file name : ";
    fflush(stdin);
    this->getfilename();
    ifstream file;
    file.open(name);
    if(!file.is_open())
    {
        cout<<"\nfile not opened";
    }
    else
    {
        cout<<"\nContents in file....\n";
        char str[255];
        while(!file.eof())
        {
            file.getline(str, 255);
            cout<<str<<endl;
        }
        file.close();
        cout<<"\nFile ends";
    }
}

void Application::Write()
{
    char line[100];
    while(1)
    {
        if(Mygets(line))
        {
            file<<line;
            break;
        }
        else
        {
            file<<line<<endl;
            cout<<endl;
        }
    }
}

char* Application::getfilename()
{
    int cnt=0;
    cout<<".txt    \b\b\b\b\b\b\b\b";
    while(1)
    {
        name[cnt]=getch();
        if(name[cnt]=='\n'||name[cnt]=='\r')
        {
         break;
        }
        else if(name[cnt]=='\b')
        {
         cout<<"\b \b";
         cnt--;
        }
        else
        {
         cout<<name[cnt];
         cnt++;
        }
        cout<<".txt    \b\b\b\b\b\b\b\b";
    }
    name[cnt++]='.';
    name[cnt++]='t';
    name[cnt++]='x';
    name[cnt++]='t';
    name[cnt]='\0';
    return name;
}

void Application::Create()
{
    cout<<"\nCreating new file";
    cout<<"\nEnter file name : ";
    fflush(stdin);
    this->getfilename();
    file.open(name,ios::out);
    if(!file.is_open())
    {
        cout<<"\nfile not created";
    }
    else
    {
        cout<<endl<<name<<" is created successfully :\n(press ~ to save or end the file)\n";
        Set_tcol(9);
        this->Write();
        file.close();
    }
    Set_tcol(8);
    cout<<"\n File saved successfully";
}

int main()
{
    Application App;
    int choice;
    Set_col(15,0);
    Set_tcol(12);
    cout<<"\n<<<<<<<<<  Welcome to MakeFile  >>>>>>>>>";
    do{
        Set_tcol(13);
        cout<<"\nSelect operations :\n"<<"1.New File\n"<<"2.Open File\n"<<"3.Exit  ";
        cin>>choice;
        Set_tcol(6);
        switch(choice)
        {
            case 1:
                App.Create();
                break;
            case 2:
                App.Open();
                break;
            case 3:break;
            default:
                Set_tcol(8);
                cout<<"\nWrong input";
                break;
        }
    }while(choice!=3);
    return 0;
}
int Mygets(char*s)
{
    int i=0;
    while(1)
    {
        s[i]=getche();
        if(s[i]=='~')
        {
            s[i]='\0';
            return 1;
            break;
        }
        if(s[i]=='\b')
        {
            i--;
            printf(" \b");
        }
        else if(s[i]==13)
        {
            s[i]='\0';
            break;
        }
        else
        {
            i++;
        }
    }
    return 0;
}
