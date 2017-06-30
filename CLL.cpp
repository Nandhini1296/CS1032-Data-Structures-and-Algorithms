#include<stdio.h>
#include<conio.h>
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
struct node *delete_end(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_list(struct node *);
int main(){
int option;
do{
printf("\n\n******CIRCULAR LINKED LIST******\n");
printf("1. CREATE LIST\n2. DISPLAY LIST\n3. INSERT AT BEGINNING\n4. INSERT AT END");
printf("\n5. DELETE AT BEGINNING\n6. DELETE AT END\n7. DELETE LIST\n8. EXIT");
printf("\nEnter your option:");
scanf("%d",&option);
switch (option){
	case 1:  start=create_list(start);
		break;
	case 2:  start=display(start);
		break;
	case 3:  start=insert_beg(start);
		 break;
	case 4:  start=insert_end(start);
		 break;
	case 5:  start=delete_beg(start);
		 break;
	case 6:  start=delete_end(start);
		break;
	case 7:  start=delete_list(start);
		break;
}
}while(option!=8);
getch();
return 0;
}
struct node *create_list(struct node *start){
struct node *newnode,*ptr;
int num;
printf("\nEnter -1 to end:");
printf("\nEnter the data:");
scanf("%d",&num);
while(num!=-1){
	newnode=(struct node *)malloc(sizeof(struct node ));
	newnode->data=num;
	if(start==NULL){
	newnode->next=newnode;
	start=newnode;
	}
	else{
	ptr=start;
	while(ptr->next!=start)
		ptr=ptr->next;
	ptr->next=newnode;
	newnode->next=start;}
	printf("\nEnter the data:");
	scanf("%d",&num);}
return start;
}
struct node *display(struct node *start){
	struct node *ptr;
	ptr=start;
	if(start==NULL){
	printf("\nEmpty list");
	}
	else{
	while(ptr->next!=start){
	printf("|%d|",ptr->data);
	ptr=ptr->next;}
	printf("|%d|",ptr->data);
	}
return start;
}
struct node *insert_beg(struct node *start){
struct node *newnode,*ptr;
int num;
printf("\nEnter the data:");
scanf("%d",&num);
newnode=(struct node *)malloc(sizeof(struct node));
newnode->data=num;
ptr=start;
while(ptr->next!=start)
	ptr=ptr->next;
ptr->next=newnode;
newnode->next=start;
start=newnode;
return start;
}
struct node *insert_end(struct node *start){
struct node *ptr,*newnode;
int num;
printf("\nEnter the data:");
scanf("%d",&num);
newnode=(struct node *)malloc(sizeof(struct node ));
newnode->data=num;
ptr=start;
while(ptr->next!=start)
	ptr=ptr->next;
ptr->next=newnode;
newnode->next=start;
return start;
}
struct node *delete_beg(struct node *start){
struct node *ptr;
ptr=start;
while(ptr->next!=start)
	ptr=ptr->next;
ptr->next=start->next;
free(start);
start=ptr->next;
return start;
}
struct node *delete_end(struct node *start){
struct node *ptr,*preptr;
ptr=start;
while(ptr->next!=start){
preptr=ptr;
ptr=ptr->next;
}
preptr->next=ptr->next;
free(ptr);
return start;
}
struct node *delete_list(struct node *start){
struct  node *ptr;
ptr=start;
while(ptr->next!=start)
	start=delete_end(start);
free(start);
return start;
}

