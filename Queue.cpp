#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Queue{
    int size;
    int *arr;
    int front;
    int rear;
    public:
    Queue(int n){
        size = n;
        front = 0;
        rear = -1;
        arr = (int*)calloc(size,sizeof(int));
        cout<<"Created a queue successfully\n";
    }

    bool isFull(){
        if(rear+1 == size){
            cout<<"\nQueue is Full\n";
            return true;
        }
        return false;
    }
    bool isEmpty(){
        if(rear +1  == front){
            cout<<"\nQueue is Empty\n";
            return true;
        }
        return false;
    }

    void insertQ(int n){
        if(isFull()){
            cout<<"Can't insert new Element\n";
            return;
        }
        rear++;
        arr[rear] = n;
    }

    int deleteQ(){
        if(isEmpty()){
            cout<<"Can't delete any element\n";
            return -1;
        }
        int temp = arr[front];
        front++;
        return temp;
    }
    void printQ(){
        if(isEmpty())return;
        for(int i=front;i<=rear;i++)cout<<arr[i]<<" ";
    }
    ~Queue(){
        free(arr);
        cout<<"Destroyed the queue successfully\n";
    }
};

int main(){
    Queue q(5);
    int choice,flag=0,n;

    while(1){
        cout<<"\nOperations : 1) Insert 2) Delete 3) Print 4) Exit\nChoice : ";
        cin>>choice;
        switch(choice){
            case 1:
                cout << "\nEnter the input data : ";
                cin >> n;
                q.insertQ(n);
                break;
            case 2:
                n = q.deleteQ();
                if(n != -1)
                    cout << "\nData removed : " << n << endl;
                break;
            case 3:
                q.printQ();
                break;
            case 4:
                flag=1;
                break;
            default:
                cout<<"\nInvalid Option";
        }
        if(flag)break;
    }
    
    return 0;
}