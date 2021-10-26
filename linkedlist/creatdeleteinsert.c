//creat linklist 
// inset midll end ,delete inset delete
//recursive
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct Node{
	int data;
	struct Node *next;
};
void print(struct Node *head){
	if (head==NULL)
		return ;
		printf("%d\t",head->data);
		print(head->next);
}
int main(){
	int val;
	struct Node *head=NULL,*ptr,*p,*tail;
	printf("to stop the insertion enter -1\n");
	do{
	printf("enter the value of element\n");
		scanf("%d",&val);
		if(val!=-1){
		ptr=(struct Node *)malloc(sizeof(struct Node));
			ptr->data=val;
			if(head==NULL)
				head=ptr;
			else
				p->next=ptr;
			p=ptr;
		}
	}while(val!=-1);// createing linkedlist till we -1
	tail=p;
	p=head;
	while(1){
	int flag=-1;
	printf("-----------Menu----------\n");
	printf("\t1: insert at begining\n");
	printf("\t2: insert at end\n");
	printf("\t3: insert at kth\n");
	printf("\t4: Delete at begining\n");
	printf("\t5: Delete at end\n");
	printf("\t6: Delete at middle\n");
	printf("\t7:exit()\n");
	scanf("%d",&val);
	switch(val){
		case 1:{ 
			printf("Enter the value to be inserted\n");
			scanf("%d",&val);
			ptr=(struct Node *)malloc(sizeof(struct Node));ptr->data=val;
			ptr->next=head;
			head=ptr;
		}
		break;
		case 2:{
			printf("Enter the value to be inserted\n");
			scanf("%d",&val);		
			ptr=(struct Node *)malloc(sizeof(struct Node));ptr->data=val;
			tail->next=ptr;
			tail=ptr;
		}	
		break;
		case 3:{
			printf("Enter the value to be inserted and position 'K' \n");
			int k;struct Node *prev=NULL;
			scanf("%d%d",&val,&k);
			p=head;
			k=k;
			while(k--){
				prev=p;
				p=p->next;
			}
			if(prev!=NULL&&p==NULL){
				ptr=(struct Node *)malloc(sizeof(struct Node));ptr->data=val;
				tail->next=ptr;
				tail=ptr;
			}
			else if(prev==NULL && p!=NULL){
				ptr=(struct Node *)malloc(sizeof(struct Node));ptr->data=val;
				ptr->next=head;
				head=ptr;
			}
			else{
				ptr=(struct Node *)malloc(sizeof(struct Node));ptr->data=val;
				prev->next=ptr;
				ptr->next=p;
			}
			}
		break;
		case 4:{
			p=head;
			head=head->next;
			free(p);
		}
		break;
		case 5:{
			p=head;
			if(p->next=NULL){
				free(head);
				break;
			}
			while(p->next->next!=NULL){
				p=p->next;
			}
			p->next=NULL;
		}
		case 6:{
			p=head,ptr=head;
			struct Node *slow=NULL;
			while(ptr!=NULL){
				slow=p;
				p=p->next;
				ptr=ptr->next;
				if(ptr!=NULL)ptr=ptr->next;
			}
			slow->next=p->next;
		}
		case 7:{
			flag=0;
		}
		break;
		default:break;
	}
	if(flag==0)break;
	}
	print(head);
	return 0;
}
