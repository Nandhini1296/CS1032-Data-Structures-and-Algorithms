#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 6
 int stack[MAX], top=-1;
 void push(int stack[],int val);
 int pop(int stack[]);
 int peek(int stack[]);
 void display(int stack[]);
 int main( int argc, char *argv[]) {
 int val, option;
 do{
 printf("\nSTACK-ARRAY IMPLEMENTATION\n");
 printf("\n1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n5.EXIT");
 printf("\nEnter your choice:");
 scanf("%d",&option);
 switch(option){
	case 1:
		printf("\nEnter the number to be pushed into the stack:");
		scanf("%d",&val);
		push(stack, val);
		break;
	case 2:
		if(val!=-1)
		printf("\nThe value deleted from stack is:%d",val);
		val=pop(stack);
		break;
	case 3:
		val=peek(stack);
		if(val!=-1)
		printf("\nThe value stored at the top of the stack is:%d",val);
		break;
	case 4:
		display(stack);
		break;
	} }while(option!=5);
 return 0;
 }
 void push(int stack[], int val){
	if(top==MAX-1){
		printf("\nSTACK OVERFLOW");
	}
	else{
		top++;
		stack[top]=val;
	}
 }
 int pop(int stack[]){
	int val;
	if(top==-1){
		printf("\nSTACK UNDERFLOW");
		return -1;
	}
	else{
		val=stack[top];
		top--;
		return (stack[top]);} }
 int peek(int stack[]){
	if (top==-1){
		printf("\nSTACK IS EMPTY");
		return -1;
	}
	else
	return(stack[top]); }
 void display(int stack[]) {
	int i;
	if(top==-1)
	printf("\nSTACK IS EMPTY");
	else{
		for(i=top;i>=0;i--)
		printf("\n|%d|",stack[i]);
		printf("\n"); 
		}
		}
		

