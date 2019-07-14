#include<iostream>
#include<stdlib.h>

using namespace std;

class Stack{
    private:
        int top,size;
    public:
        int* stack;
    
    Stack(int n){
        top = -1;
        size = n;
        stack = (int*)malloc(n*sizeof(int));
        cout << "\nCreated new stack successfully\n";
    }

    bool isFull(){
        if (top+1 == size)
        {
            cout<<"\nStack is Full. Can't add any elements\n";
            return true;
        }
        return false;
    }

    bool isEmpty(){
        if(top < 0){
            cout << "\nStack is empty. Can't remove any elements\n";
            return true;
        }
        return false;
    }

    void push(int n){
        if(isFull())return;
        
        top++;
        stack[top] = n;
        cout << "\nAdded\n";
    }

    int pop(){
        if(isEmpty())return -1;
        
        int temp = stack[top];
        top--;
        return temp;
    }

    void print(){
        if(top < 0)
            cout << "\nStack is empty\n";
        else{
            cout << "\nData in the stack are : ";
            int i=top;
            while(i>=0){
                printf("%d ",stack[i]);
                i--;
            }
        }
        cout<<endl;
    }

    ~Stack(){
        cout<<"Destroying Stack...\nTerminating Process...\n";
        free(stack);
    }
};

int main(void){
    int size,choice;
    int n;

    cout<<"\nEnter the size of the stack : ";
    cin>>size;
    Stack s(size);
    int flag=0;

    while(1){
        cout<<"\nOperations : \n1) Push\n2) Pop\n3) Print\n4) Exit\nChoice : ";
        cin>>choice;
        switch(choice){
            case 1:
                cout << "\nEnter the input data : ";
                cin >> n;
                s.push(n);
                break;
            case 2:
                n = s.pop();
                if(n != -1)
                    cout << "\nData removed : " << n << endl;
                break;
            case 3:
                s.print();
                break;
            case 4:
                flag=1;
                break;
            default:
                cout<<"\nInvalid Option";
        }
        if(flag)break;
    }
    
    printf("\n");
    return 0;
}