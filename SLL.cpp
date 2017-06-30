#include<conio.h>
#include<stdio.h>
#include<malloc.h>
struct node{
int data;
struct node *next;
};
struct node *start=NULL;
struct node *create_list(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_bef(struct node *);
struct node *insert_aft(struct node *);
struct node *insert_bet(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_node(struct node *);
struct node *delete_aft(struct node *);
struct node *delete_list(struct node *);
int main(){
int choice;
do{
printf("\n\n*****SINGLY LINKED LIST*****\n\n");
printf("1. CREATE  LIST\n");
printf("2. DISPLAY\n3. INSERT AT BEGINNING\n4. INSERT AT END\n5. INSERT BEFORE NODE\n6. INSERT AFTER NODE");
printf("\n7. INSERT BETWEEN NODES\n8. DELETE AT BEGINNING\n9. DELETE AT END\n10.DELETE NODE\n11.DELETE AFTER NODE\n12.DELETE LIST\n13.EXIT");
printf("\nEnter your choice:");
scanf("%d",&choice);
switch(choice){
	case 1:	start=create_list(start);
		printf("\nList Created");
		break;
	case 2:  start=display(start);
		break;
	case 3:  start=insert_beg(start);
		break;
	case 4:  start=insert_end(start);
		break;
	case 5:  start= insert_bef(start);
		break;
	case 6:   start=insert_aft(start);
		 break;
	case 7:  start=insert_bet(start);
		break;
	case 8:  start=delete_beg(start);
		break;
	case 9:  start=delete_end(start);
		break;
	case 10: start=delete_node(start);
		 break;
	case 11: start=delete_aft(start);
		 break;
	case 12: start=delete_list(start);
		 break;
}}
while(choice!=13);
getch();
return 0;
}
struct node *create_list(struct node *start){
struct node *newnode, *ptr;
int val;
printf("\nEnter -1 to end list");
printf("\nEnter data to enter:");
scanf("%d",&val);
while(val!=-1){
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=val;
	if (start==NULL){
	newnode->next=NULL;
	start=newnode;
	}
	else{
	ptr=start;
	while(ptr->next!=NULL){
	ptr=ptr->next;
	}
	ptr->next=newnode;
	newnode->next=NULL;
}
printf("\nEnter data to enter:");
scanf("%d",&val);
}
return start;
}
struct node *display( struct node *start){
struct node *ptr;
if(start==NULL){
printf("Empty\n");
}
ptr=start;
while(ptr!=NULL){
printf("|%d|",ptr->data);
ptr=ptr->next;
}
return start;
}
struct node *insert_beg(struct node *start){
struct node *ptr, *newnode;
int num;
printf("\nEnter the number to be inserted:");
scanf("%d",&num);
newnode= (struct node *)malloc(sizeof(struct node *));
if(start==NULL){
printf("Underflow");
}
newnode->data=num;
newnode->next=start;
start=newnode;
return start;
}
struct node *insert_end(struct node *start){
struct node *ptr, *newnode;
int num;
printf("\nEnter the number to be inserted:");
scanf("%d",&num);
newnode= (struct node *)malloc(sizeof(struct node*));
ptr=start;
while(ptr->next!=NULL){
ptr=ptr->next;
}
newnode->data=num;
newnode->next=NULL;
ptr->next=newnode;
return start;
}
struct node *insert_bef(struct node *start){
int val,num;
struct node *ptr,*preptr,*newnode;
newnode= (struct node *)malloc(sizeof(struct node *));
printf("\nEnter the value to be inserted:");
scanf("%d",&num);
printf("\nEnter the value before which it has to be inserted:");
scanf("%d",&val);
ptr=start;
while(ptr->data!=val){
preptr=ptr;
ptr=ptr->next;
}
newnode->data= num;
newnode->next=ptr;
preptr->next=newnode;
return start;
}
struct node *insert_aft(struct node *start){
int num, val;
struct node *ptr, *newnode;
newnode =(struct node *)malloc(sizeof(struct node *));
printf("\nEnter the data:");
scanf("%d",&num);
printf("\nEnter the value after which it has to be inserted:");
scanf("%d",&val);
ptr=start;
newnode->data=num;
while(ptr->data!=val){
ptr=ptr->next;
}
if(ptr->next!=NULL){
 newnode->next=ptr->next;
 ptr->next=newnode;
}
else{
 newnode->next=NULL;
 ptr->next=newnode;
}
return start;
}
struct node *insert_bet(struct node *start){
int val1,val2, num;
struct node *newnode,*preptr,*ptr;
newnode = (struct node *)malloc(sizeof(struct node *));
printf("Enter the data:");
scanf("%d",&num);
newnode->data=num;
printf("\nEnter the values between which it has to entered:");
scanf("%d%d",&val1,&val2);
ptr=start;
while(ptr->data!=val1){
ptr=ptr->next;
}
preptr=ptr;
ptr=ptr->next;
newnode->next=ptr;
preptr->next=newnode;
return start;
}
struct node *delete_beg(struct node *start){
struct node *ptr,*preptr;
ptr=start;
start=start->next;
free(ptr);
return start;
}
struct node *delete_end(struct node *start){
struct node *ptr,*preptr;
ptr=start;
while(ptr->next!=NULL){
	preptr=ptr;
	ptr=ptr->next;
}
preptr->next=NULL;
free(ptr);
return start;
}
struct node *delete_node(struct node *start){
int val;
struct node *ptr,*preptr;
ptr=start;
preptr=ptr;
printf("\nEnter the node to be deleted");
scanf("%d",&val);
if(ptr->data==val){
	start=delete_beg(start);
	return start;
}
else{
while(ptr->data!=val){
	preptr=ptr;
	ptr=ptr->next;
}
preptr->next=ptr->next;
free(ptr);
return start;
}}
struct node *delete_aft(struct node *start){
int val;
struct node *ptr,*preptr;
ptr=start;
preptr=ptr;
printf("Enter the node  after which the data has to be deleted");
scanf("%d",&val);
while(preptr->data!=val){
	preptr=ptr;
	ptr=ptr->next;}
preptr->next=ptr->next;
free(ptr);
return start;}
struct node *delete_list(struct node *start){
struct node *ptr;
if(start!=NULL){
ptr=start;
while(ptr!=NULL){
	start=delete_beg(ptr);
	ptr=start;
}}
return start;
}

