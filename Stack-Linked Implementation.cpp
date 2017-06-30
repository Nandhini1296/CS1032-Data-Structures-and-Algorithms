#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct stack{
int data;
struct stack *next;
};
struct stack *top=NULL;
struct stack *push(struct stack *, int);
struct stack *pop(struct stack *);
struct stack *display(struct stack *);
int peek(struct stack *);
int main(int argc, char *argv[]){
int val,option;

 do {
 printf("\nSTACK- LINKED IMPLEMENTATION\n");
 printf("\n1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n5.EXIT");
 printf("\nEnter your choice:");
 scanf("%d",&option);
 switch(option) {
	case 1:
		printf("\nEnter the number to be pushed into the stack:");
		scanf("%d",&val);
		top= push(top, val);
		break;
	case 2:
		top=pop(top);
		break;
	case 3:
		val=peek(top);
		if(val!=-1)
		printf("\nThe value stored at the top of the stack is:%d",val);
		else
		printf("\nSTACK IS EMPTY");
		break;
	case 4:
		top=display(top);
		break;
} }while(option!=5);
 return 0;
 }
 struct stack *push(struct stack *top, int val){
	struct stack *ptr;
	ptr=(struct stack *)malloc(sizeof(struct stack));
	ptr->data=val;
	if(top==NULL){
		ptr->next=NULL;
		top=ptr;
	}
	else{
		ptr->next=top;
		top=ptr;
	}
	return top; }

 struct stack *display(struct stack *top){
	struct stack *ptr;
	ptr=top;
	if(top==NULL)
	printf("\nSTACK IS EMPTY");
	else
	{
	while (ptr!=NULL){
		printf("\n|%d|",ptr->data);
		ptr=ptr->next;
	}}
 return top;
 }
 struct stack *pop(struct stack *top) {
	struct stack *ptr;
	ptr=top;
	if(top==NULL)
	printf("\nSTACK UNDERFLOW");
	else{
		top=top->next;
		printf("\nThe value being deleted is:%d",ptr->data);
		free(ptr);
	}
	return top;
 }
 int peek (struct stack *top) {
	if(top==NULL)
	return -1;
	else
	return top->data;
 }

