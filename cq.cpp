#include<iostream>
using namespace std;
int cqueue[5];
int front =-1,rear=-1,n=5;
//insertion
void insertCQ(int val){
    if (( front == 0 && rear == n-1)||(front==rear+1)){
        cout<<"Queue Overflow\n";
    }
        if(front==-1){
            front=0;
            rear=0;
        }else{
            if(rear==n-1)
                rear=0;
            else
                rear=rear+1;
            
        }
        cqueue[rear]=val;

    }
//deletion
void deleteCQ(){
    if(front==-1){
        cout<<"Queue is empty\n";
        return;

    }
    cout<<"Element deleted form queue is:"<<cqueue[front]<<endl;
    if(front==rear){
        front=-1;
        rear=-1;
    }
    else{
        if(front==n-1){
            front=0;

        }else{
            front=front+1;
        }cout<<"\n";
    }
     
}
void displayCQ(){
    int f= front ,r=rear;
    if(front==-1){
        cout<<"Queue is empty"<<endl;
        return;

    }
    cout<<"Queue elements are:\n";
    if(f<=r){
        while(f<=r){
            cout<<cqueue[f]<<" ";
            f++;
        }cout<<"\n";
    }else{
    
      
        while(f<=n-1){
            cout<<cqueue[f]<<" ";
            f++;
        }cout<<"\n";
        

    }


}
























































int main(){
    int ch,val;
    cout<<"1)Insert \n:";
    cout<<"2)Delete:\n";
    cout<<"3)Display:\n";
    cout<<"4)Exit\n";

    do{
        cout<<"Enter your Choice:\n";
        cin>>ch;
        switch(ch){
            case 1:
            cout<<"Insert the element:\n";
            cin>>val;
            insertCQ(val);
            break;
            case 2:
            deleteCQ();
            break;
            case 3:
            displayCQ();
            break;
            case 4:
            cout<<"Exit\n";
            break;
            






        }
    }while(ch !=4);
      
    
}


