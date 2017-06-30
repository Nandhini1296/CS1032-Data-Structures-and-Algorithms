#include<conio.h>
#include<stdio.h>
#include<malloc.h>
struct node{
int data;
struct node *next,*prev;
};
struct node *start=NULL;
struct node *create_list(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_bef(struct node *);
struct node *insert_aft(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_bef(struct node *);
struct node *delete_aft(struct node *);
struct node *delete_list(struct node *);
int main(){
int choice;
do{
printf("\n\n*****DOUBLY LINKED LIST*****\n\n");
printf("1. CREATE THE LIST\n");
printf("2. DISPLAY\n3. INSERT AT BEGINNING\n4. INSERT AT END\n5. INSERT BEFORE VALUE\n6. INSERT AFTER VALUE");
printf("\n7. DELETE AT BEGINNING\n8. DELETE AT END\n9. DELETE BEFORE VALUE\n10.DELETE AFTER VALUE\n11.DELETE LIST\n12.EXIT");
printf("\nEnter choice:");
scanf("%d",&choice);
switch(choice){
	case 1: start=create_list(start);
		printf("\nList Created");
		break;
	case 2: start=display(start);
		break;
	case 3: start=insert_beg(start);
		break;
	case 4: start=insert_end(start);
		break;
	case 5: start= insert_bef(start);
		break;
	case 6:  start=insert_aft(start);
		 break;
	case 7: start=delete_beg(start);
		break;
	case 8: start=delete_end(start);
		break;
	case 9: start=delete_bef(start);
		break;
	case 10:start=delete_aft(start);
		 break;
	case 11:start=delete_list(start);
		break;
}}while(choice!=12);
getch();
return 0;
}
struct node *create_list(struct node *start){
struct node *newnode, *ptr;
int val;
printf("\nEnter -1 to End list");
printf("\nEnter data to enter:");
scanf("%d",&val);
while(val!=-1){
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=val;
	if (start==NULL){
	newnode->next=NULL;
	newnode->prev=NULL;
	start=newnode;
	}
	else{
	ptr=start;
	while(ptr->next!=NULL){
	ptr=ptr->next;
	}
	ptr->next=newnode;
	newnode->prev=ptr;
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
start->prev=newnode;
newnode->next=start;
newnode->prev=NULL;
start=newnode;
printf("Inserted");
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
ptr->next=newnode;
newnode->prev=ptr;
newnode->next=NULL;
printf("\nInserted");
return start;
}
struct node *insert_bef(struct node *start){
int val,num;
struct node *ptr,*newnode;
newnode= (struct node *)malloc(sizeof(struct node *));
printf("\nEnter the value to be inserted:");
scanf("%d",&num);
printf("\nEnter the value before which it has to be inserted:");
scanf("%d",&val);
ptr=start;
while(ptr->data!=val){
ptr=ptr->next;
}
newnode->data= num;
newnode->next=ptr;
newnode->prev=ptr->prev;
ptr->prev->next=newnode;
ptr->prev=newnode;
return start;
printf("Inserted");
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
newnode->prev=ptr;
newnode->next=ptr->next;
ptr->next->prev=newnode;
ptr->next=newnode;
printf("Inserted");
return start;
}
struct node *delete_beg(struct node *start){
struct node *ptr;
ptr=start;
start=start->next;
start->prev=NULL;
free(ptr);
return start;
}
struct node *delete_end(struct node *start){
struct node *ptr;
ptr=start;
while(ptr->next!=NULL){
 ptr=ptr->next;
}
ptr->prev->next=NULL;
free(ptr);
return start;
}
struct node *delete_bef(struct node *start){
int val;
struct node *ptr,*temp;
ptr=start;
printf("\nEnter the node to be deleted");
scanf("%d",&val);
while(ptr->data!=val){
	ptr=ptr->next;
}
temp=ptr->prev;
if(temp==start)
	start=delete_beg(start);
else{
	ptr->prev=temp->prev;
	temp->prev->next=ptr;
}
free(temp);
return start;
}
struct node *delete_aft(struct node *start){
int val;
struct node *ptr,*temp;
ptr=start;
printf("Enter the node  after which the data has to be deleted");
scanf("%d",&val);
while(ptr->data!=val){
   ptr=ptr->next;
}
temp=ptr->next;
ptr->next=temp->next;
temp->next->prev=ptr;
free(temp);
return start;
}
struct node *delete_list(struct node *start){
while(start!=NULL){
	start=delete_beg(start);
}
return start;
}


