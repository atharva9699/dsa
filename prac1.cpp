#include<iostream>
#include<string.h>
using namespace std;

struct student{
    int roll;
    char name[20];
    float marks;

};
void swap(student &a, student&b)
{
    student temp=a;
    a=b;
    b=temp;
}
void create(student s[],int n)
{
    for (int i=0;i<n;i++)
    {
        cout<<"Enter roll no:";
        cin>>s[i].roll;
        cout<<"Enter name:";
        cin>>s[i].name;
        cout<<"Enter marks";
        cin>>s[i].marks;
        
    }
}
void display(student s[],int n)
{
    cout<<"rollno"
        <<"  "
        <<"name"
        <<"  "
        <<"marks" <<endl;
        for(int i=0;i<n;i++)
        {
            cout<< s[i].roll <<"\t"<<s[i].name <<"\t"<< s[i].marks <<endl;
        }
}
void bubble (student s[],int n)
{
    int i,j;
    student temp;
    for(i=1;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(s[j].roll >s[j+1].roll)
            {
                temp = s[j];
                s[j]=s[j+1];
                s[j+1]=temp;

            }
        }
    }
}
void insertion(student s[],int n)
{
   for(int i=1;i<n;i++)
   {
    student key;
    key =s[i];
    int j=i-1;
    while(j>=0 && strcmp(s[j].name,key.name)>0)
    {
        s[j+1]=s[j];
        j--;
    }
    s[j+1]=key;
   } 
}
void same_sgpa(student s[],int n)
{
    float marks;
    cout<<"\n Enter marks of the student :";
    cin>>marks;
    for(int i=0;i<n;i++)
    {
        if(marks==s[i].marks)
        {
            cout<<s[i].roll <<"\t"<<s[i].name <<"\t"<<s[i].marks<<endl;
        }
    }
}
int main(){
    student s[20];
    int ch=1,n;

    do
    {
        cout<<"1.Create Record:" <<endl;
        cout<<"2.Bubble Sort:"<<endl;
        cout<<"3.Insertion sort:"<<endl;
        cout<<"4.Search students with the same marks"<<endl;
        cout<<"Enter your choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:
            cout<<"Enter no of Students\n";
            cin>>n;
            create(s,n);
            display(s,n);
            break;

            case 2:
            bubble(s,n);
            display(s,n);
            break;
            case 3:
            insertion(s,n);
            display(s,n);
            break;

            case 4:
            same_sgpa(s,n);
            break;

          

        }
}while(ch!=5);
return 0;
}





