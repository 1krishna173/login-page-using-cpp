#include<bits/stdc++.h>
using namespace std;
class temp{
   string username,password,Email;
   fstream file;
   public:
   void login();
   void signup();
   void forgot();
}obj;
int main()
{
   char choice;

   cout<<"1. Login\n";
   cout<<"2. SignUp\n";
   cout<<"3. Forget Password\n";
   cout<<"4. Exit\n";
   cout<<"--------Enter your choice--------\n";
   cin>>choice;
   cin.ignore();
   switch(choice){
      case '1':
      obj.login();
      break;
      case '2':
      obj.signup();
      break;
      case '3':
      obj.forgot();
      break;
      case '4':
      return 0;
      break;
      default:
      cout<<"Invalid selection";
      break;

   }
   return 0;
}
void temp:: signup(){
   cout<<"Please enter your username ";
   getline(cin,username);
   cout<<"Enter Your password ";
   getline(cin,password);
   cout<<"Enter your Email ";
   getline(cin,Email);
   file.open("logindata.txt",file.out| file.app);
   file<<username<<"*"<<Email<<"*"<<password<<endl;
   file.close();
}
void temp:: login(){
   string searchpass,usern;
   cout<<"-------LOGIN-----------\n";
    cout<<"Please enter your username ";
   getline(cin,usern);
   cout<<"Enter Your password ";
   getline(cin,searchpass);
   file.open("logindata.txt",file.in);
    bool found = false;
   
    while (getline(file, username, '*') &&
           getline(file, Email, '*') &&
           getline(file, password, '\n')) {
        if (username == usern && password == searchpass) {
            cout << "LOGIN SUCCESS \n";
            cout << "Your Email id is : " << Email << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "LOGIN FAILED: Invalid username or password.\n";
    }

    file.close();
}
void temp:: forgot(){
   string searchpass,usern,email;
    cout<<"Please enter your username ";
   getline(cin,usern);
   cout<<"Enter Your email ";
   getline(cin,email);
   file.open("logindata.txt",file.in);
   while(getline(file,username,'*') && getline(file, Email, '*') &&
           getline(file, password, '\n')) {
               if(username==usern && email==Email){
                  cout<<password<<endl;
                  return ;
               }
           }
    cout<<"Not found"<<endl;
   
}