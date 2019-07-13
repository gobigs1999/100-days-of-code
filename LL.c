#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct Node{
    int data;
    struct Node *next;
};

typedef struct Node node;
typedef struct Node *nodePtr;

int compareAscending(int d1,int d2)
{
    return d1>d2;
}

int compareDescending(int d1,int d2){
    return d1<d2;
}

typedef int (*compare_func)(int a,int b);


nodePtr addNode(nodePtr *head,int data,compare_func compare){

    nodePtr newNode = (nodePtr)calloc(1,sizeof(node));
    newNode->data = data;

    nodePtr tempPtr,prevPtr;
    for(tempPtr = *head; tempPtr && compare(newNode->data,tempPtr->data); prevPtr = tempPtr, tempPtr=tempPtr->next);

    if((*head) == tempPtr){
        newNode->next = *head;
        *head = newNode;
        
    }
    else{
        newNode->next = prevPtr->next;
        prevPtr->next = newNode;
    }
}

void printList(nodePtr head){
    nodePtr tempPtr = head;
    for(tempPtr = head;tempPtr;printf("%d ",tempPtr->data),tempPtr = tempPtr->next);
    printf("\n");
}

int main(){
    // int arr[] = {1,3,2,87,34,90,23,78};
    node *head1 = NULL , *head2 = NULL, *head3 = NULL, *head4 = NULL;
    int data;
    
    printf("Enter 0 to quit...");

    for(;1;){
        printf("\nData : ");
        scanf("%d",&data);
        if(data == 0){
            printf("Terminating...\n");
            break;
        }

        addNode(&head1, data,compareAscending);
        addNode(&head2, data,compareDescending);
        if(data%2)
            addNode(&head3,data,compareAscending);
        else
            addNode(&head4,data,compareAscending);

        printf("\nAscending List       : ");
        printList(head1);
        printf("Descending List      : ");
        printList(head2);
        printf("Odd Ascending List   : ");
        printList(head3);
        printf("Even Ascending List  : ");
        printList(head4);
    }

    free(head1);
    free(head2);
    free(head3);
    free(head4);

    return 0;
}