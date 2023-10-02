#include <iostream>
#include <string.h>
#include<iomanip>
using namespace std;

class student{
    private:
        int roll;
       char name[20];
        int age;
        char gender;
        int fee;

    public:
        void setdata()
        {
            cout<<"Enter roll no : ";
            cin>>roll;
            

            cout<<"Enter name : ";
            cin>>name;
           

            cout<<"Enter age : ";
            cin>>age;
            

            cout<<"Enter gender : ";
            cin>>gender;
            cout<<endl;

            calcfees();
    
        }

        void modify()
        {
            cout<<"roll no is  "<<roll;
            
            

            cout<<"Enter name : ";
            cin>>name;
           

            cout<<"Enter age : ";
            cin>>age;
            

            cout<<"Enter gender : ";
            cin>>gender;
            cout<<endl;

            
    
        }

        void calcfees()
        {
            if (age>18)
            fee=10000;
            else
            fee=5000;
            
        }

        
        void showdata()
        {
            cout<<"Roll no : "<<roll<<endl;
            cout<<"Name : "<<name<<endl;
            cout<<"Age : "<<age<<endl;
            cout<<"Gender: "<<gender<<endl;
            cout<<"Fees : "<<fee<<endl;

        }
        
        int getroll_no()
        {
            return roll;
        }

       char * getname ()
        {
            return name;
        }


};

void menu()
{
    cout<<endl<<"******Student Records*****"<<endl;
    cout<<endl;
    cout<<"0.Exit"<<endl;
    cout<<"1.Register student "<<endl;
    cout<<"2.Show all students "<<endl;
    cout<<"3.Search student"<<endl;
    cout<<"4.Search student by name :"<<endl;
    cout<<"5.Modify data"<<endl;
    cout<<"6.Delete record"<<endl;

    cout<<endl;
    cout<<"Enter your choice ";

}

int main()

{
    student s[3];
    int ch,n=0;
    int roll_no,flag=0;
    int flag_n=0;
    char  name[20];
    int pos;




    do
    {
       menu();
       cin>>ch;
       cout<<endl;
       switch(ch)
       {
           case 1:
           s[n].setdata();
           n++;
           break;

           case 2:
           if(n>0)
           {
               for (int i=0;i<n;i++)
               {
                   s[i].showdata();
                   cout<<endl;
               }
           }
           else
           {
               cout<<"No student entry";
           }     
            break; 

            case 0:
            break;

            case 3:
            if(n>0)
            {
                cout<<"Enter your roll no : ";
                cin>>roll_no;
                for (int i=0;i<n;i++)
               {
                  if(roll_no==s[i].getroll_no())
                  {
                      s[i].showdata();
                      flag++;

                  }
                  
               }

            } 
            else
            {
               cout<<"No student entry";
            }
            if(flag==0)
            {
                cout<<endl<<"roll No not found ";
            }

            break;

            case 4:
            if(n>0)
            {
                cout<<"Enter name of student : ";
                cin>>name;
                for (int i=0;i<n;i++)
               {
                   
                 // if(name==s[i].getname())
                 if(strcmpi(name,s[i].getname())==0)
                  
                    {
                       
                         
                        s[i].showdata(); 
                        flag_n++;                    

                    }
                  
               }
                if(flag_n==0)
                    {
                        cout<<endl<<"Name No not found ";
                    }

            } 
            else
            {
               cout<<"No student entry";
            }
           

            break;

            case 5:
            if(n>0)
            {
                cout<<"Enter roll no to modify record : ";
                cin>>roll_no;
                for (int i=0;i<n;i++)
               {
                   if(roll_no==s[i].getroll_no())
                   {
                       s[i].modify();
                       flag++;
                   }
                   
            
                  
               }
                if(flag==0)
                    {
                        cout<<endl<<"roll No not found ";
                    }

            } 
            else
            {
               cout<<"No student entry";
            }
           

            break;

            case 6:
            
            if(n>0)
            {
                cout<<"Enter roll for deleting record : ";
                cin>>roll_no;
                for (int i=0;i<n;i++)
               {
                   if(roll_no==s[i].getroll_no())
                   {
                       cout<<"This entry is being deleted "<<endl;
                       s[i].showdata();
                       pos=i;
                       flag++;
                   }                
            
                  
               }
               for(int i=pos ; i<n ; i++)
               {
                   s[i]=s[i+1];
               }
               n--;

                if(flag==0)
                    {
                        cout<<endl<<"roll No not found ";
                    }

            } 
            else
            {
               cout<<"No student entry";
            }
           

            break;

           default:
           cout<<"Invalid choice";
           break;


       }
    } while (ch);
    
    

    return 0;
}// g++ practice5.cpp
