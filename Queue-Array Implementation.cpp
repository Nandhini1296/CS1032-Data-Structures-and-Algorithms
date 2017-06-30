#include<stdio.h>
#include<conio.h>
#define MAX 10
int queue[MAX];
int front = -1,rear=-1;
void insert(void);
int delete_element(void);
int peek(void);
void display(void);
int main(){
	int option,val;
	do{
		printf("\n\n****QUEUE-ARRAY IMPLEMENTATION****");
		printf("\n1.INSERT ELEMENT\n2.DELETE  ELEMENT\n3.PEEK\n4.DISPLAY\n5.EXIT\n");
		printf("Enter your option: ");
		scanf("%d",&option);
		switch(option){
			case 1:
				insert();
				break;
			case 2:
				val=delete_element();
				if(val!=-1)
				printf("\nThe number deleted is:%d",val);
				break;
			case 3:
				val=peek();
				if(val!=-1)
				printf("\nThe first value in queue is:%d",val);
				break;
			case 4:
				display();
				break;
			}}while(option!=5);
		getch();
		return 0;
}
void insert(){
int num;
printf("\nEnter the number to be inserted in the queue:");
scanf("%d",&num);
if(rear==MAX-1)
printf("\nOVERFLOW");
else if(front==-1&&rear==-1)
front = rear=0;
else
rear++;
queue[rear]=num;
}
int delete_element(){
int val;
if(front ==-1||front>rear){
	printf("\nUNDERFLOW");
	return -1;
}
else{
	val=queue[front];
	front++;
	if(front>rear)
	front=rear=-1;
	return val;
}
}

int peek(){
	if(front==-1||front>rear){
		printf("\nEMPTY QUEUE");
		return -1;
	}
	else{
		return queue[front];}}
void display(){
	int i;
	printf("\n");
	if(front==-1||front>rear)
	printf("\nEMPTY QUEUE");
	else{
		for(i=front;i<=rear;i++)
		printf("\t|%d|",queue[i]);
	}
	}

