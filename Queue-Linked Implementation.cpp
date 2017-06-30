#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct node{
    int info;
    struct node *ptr;
}*front,*rear,*temp,*front1;
int peek();
void insert_element(int data);
void delete_element();

void display();
int count = 0;
main(){
int no, ch, e;
do{
printf("*******QUEUE-LINKED IMPLEMENTATION********")
printf("\n1.ENQUEUE\n2.DEQUEUE\n3.PEEK\n4.DISPLAY\n5.EXIT");
 printf("\n Enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &no);
            insert_element(no);
            break;
        case 2:
            delete_element();
            break;
        case 3:
            e = peek();
            if (e != 0)
                printf("Front element : %d", e);
            else
                printf("\n No front element in Queue as queue is empty");
            break;
        case 4:
            display();
            break;}} while(ch!=5);

}
void insert_element(int data){
    if (rear == NULL){
        rear = (struct node *)malloc(1*sizeof(struct node));
        rear->ptr = NULL;
        rear->info = data;
        front = rear;}
    else {
        temp=(struct node *)malloc(1*sizeof(struct node));
        rear->ptr = temp;
        temp->info = data;
        temp->ptr = NULL;
 
        rear = temp; 
		}
    count++;
} 
void display(){
    front1 = front;
     if ((front1 == NULL) && (rear == NULL)){
        printf("Queue is empty");
        return; }
    while (front1 != rear) {
        printf("%d ", front1->info);
        front1 = front1->ptr;  }
    if (front1 == rear)
        printf("%d", front1->info);
}
void delete_element(){
    front1 = front;
     if (front1 == NULL) {
        printf("\n Error: Trying to display elements from empty queue");
        return;
    }
    else
        if (front1->ptr != NULL){
            front1 = front1->ptr;
            printf("\n Dequed value : %d", front->info);
            free(front);
            front = front1;
        }
        else {
            printf("\n Dequed value : %d", front->info);
            free(front);
            front = NULL;
            rear = NULL; }
        count--;
}
int peek(){
    if ((front != NULL) && (rear != NULL))
        return(front->info);
    else
        return 0;
		}

