#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
struct node *root=NULL;

void append(){
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	if(temp==NULL){
		printf("Insufficient memory");
		exit(1);
	}
	printf("\nAppending at the end\n");
	printf("Enter data");
	scanf("%d",&temp->data);
	temp->next=NULL;	
	if(root==NULL){
		root=temp;
	}
	else{
		struct node *ptr;
		ptr = root;
		while(ptr->next!=NULL){
			ptr = ptr->next;
		}
		ptr->next = temp;
	}
	
}

void insertBegin(){
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\nInserting at the begining\n");
	printf("Enter the element to be inserted at the begining ");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if(root==NULL){
		root=temp;
	}
	else{
		temp->next=root;
		root=temp;
	}	
}

void insertAt(){
	struct node* prev=root,*temp;
	int loc,i=1;
	temp = (struct node*)malloc(sizeof(struct node));
	if(temp==NULL){
		printf("Insufficient memory ");
		exit(1);
	}
	printf("\nEnter the location of the node to be inserted ");
	scanf("%d",&loc);
	if(loc==1){
		insertBegin();
	}
	else if(loc>length() + 1 || loc<1){
		printf("Invalid index\n");
	}
	else if(loc==length() + 1){
		append();
	}
	else{
		printf("Enter data ");
		scanf("%d",&temp->data);
		while(i<loc-1){
			prev = prev->next;
			i++;
		}
		temp->next = prev->next;
		prev->next=temp;
	}
}

void deleteNode(){
	struct node* temp;
	int loc;
	
	if(loc>length() || loc<1){
		printf("Index out of bound\n");
	}
	else if(loc==1){
		temp=root;
		root = temp->next;
		temp->next = NULL;
		free(temp);
	}
	else{
		printf("\nEnter the location of the node to be deleted ");
		scanf("%d",&loc);
		struct node *q;
		temp=root;
		int i=1;
		while(i<loc-1){
			temp=temp->next;
			i++;
		}
		q=temp->next;
		temp->next = q->next;
		temp->next = NULL;
		free(q);
	}
}
void deleteEnd(int loc){
	struct node *q,*temp;
	temp=root;
	int i=1;
	while(i<loc-1){
		temp=temp->next;
		i++;
	}
	q=temp->next;
	temp->next = q->next;
	temp->next = NULL;
	free(q);
	printf("\nLast node deleted\n");
}

int detectLoop(){
	// detects whether there is a loop in the list   E.g: 1->2->3->4->2
	struct node* slow=root,*fast=root;
	while(slow && fast && fast->next){ 				// slow !=null && fast != null & fast->next !=null
		slow = slow->next;
		fast = fast->next->next;
		if(fast == slow){
			printf("Found loop in the list\n");
			return 1;
		}
	}
	printf("\nThe Linked List is Linear\n");
	return 0;
}

void reverse(){
	// finds the reverse of the list
	struct node* curr,*temp,*prev=NULL;
	curr = root;
	while(curr!=NULL){
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp ;
	}
	root = prev;
}

void sort(){
	int x;
	struct node* temp,*i,*j;
	temp = root;
	for(i=temp; i->next!=NULL; i=i->next){
		for(j=i->next; j!=NULL; j=j->next){
			if(i->data > j->data){
				x = i->data;
				i->data = j->data;
				j->data = x;
			}
		}
	}
	root = temp;
	printf("The list is sorted\n");
}

void midList(){
	// finds the middle of the list
	struct node* fast,*slow;
	int c=1;
	fast = root;
	slow = root;
	while(fast != NULL && fast->next !=NULL){
		fast = fast->next->next;
		slow = slow->next;
		c++;		
	}
	printf("\n%dth node is the middel node\n",c);
	printf("Data of the middle node: ");
	printf("%d\n",slow->data);
}


int length(){
	int c=0;
	struct node* temp=root;
	while(temp!=NULL){
		c++;
		temp=temp->next;
	}
	return c;
}
void deleteAfterNode(){
	struct node* temp,*curr;
	int key;
	printf("Enter the node data after which the node is to be deleted ");
	scanf("%d",&key);
	temp = root;
	while(temp!=NULL){
		if(temp->data == key){
			break;
		}
		temp=temp->next;
	}
	curr = temp->next;
	temp->next = temp->next->next;
	free(curr);
	printf("The node after %d is deleted\n",key);
}

void deleteBeforeNode(){
	struct node* temp,*curr;
	int key;
	printf("Enter the node data before which the node is to be deleted ");
	scanf("%d",&key);
	temp = root;
	while(temp!=NULL){
		if(temp->next->next->data == key){
			break;
		}                                      // this is incomplete.....
		temp=temp->next;
	}
	curr = temp->next;
	temp->next = temp->next->next;
	free(curr);
	printf("The node after %d is deleted\n",key);
}

int search(){
	int key;
	printf("\nEnter the element to be searched ");
	scanf("%d",&key);
	struct node*temp;
	temp=root;
	while(temp != NULL){
		if(key == temp->data){
			printf("Element is present\n");
			return 0;
		}
		temp = temp->next;
	}
	printf("Element is not present\n");
}

void display(){
	struct node* temp;
	temp=root;
	if(temp==NULL){
		printf("List is empty!!\n");
	}
	else{
		printf("\nLinked List: ");
		while(temp !=NULL){
			printf("%d->",temp->data);
			temp=temp->next;
		}
	}
	printf("\n\n");
}

int main(){
	
	int key;
	int ch,c;
	int pos;
	do{
		printf("Enter your choice ");
		printf("\n1.Create list by appending\n2.Display the linked list\n3.Insert at the begining\n4.Insert at any position\n5.Delete from the begining\n");
		printf("6.Delete from the end\n7.Delete from any position\n8.Search an element\n9.Sort the elements in ascending order");
		printf("\n10.Reverse the list\n11.Length of the list\n12.Middle of the list\n13.Delete after the node\n0.Exit\n");
		
		printf("YOUR CHOICE = ");
		scanf("%d",&ch);
		switch(ch){
			case 0 : printf("\t**********SIGNING OFF*************\n") ;
					printf("\t\t  SRIMAN BEHERA");
					exit(0);
					
			case 1: ap:append();
					printf("Press 1 to continue appending or 0 to exit ");
					scanf("%d",&c);
					if(c==1){
						goto ap;
					}
					break;
			case 2: display();
					break;
			case 3: insertBegin();
					break;
			case 4: insertAt();
					break;
			case 5: deleteNode(1);
					break;
			case 6: deleteEnd(length());
					break;
			case 7: printf("Enter the positon ");
					scanf("%d",&pos);
					deleteNode(pos);
					break;
			case 8: 
					search();
					break;
			case 9: sort();
					break;
			case 10: reverse();
					break;
			case 11: printf("The length is %d\n",length());
					break;
			case 12: midList();
					break;
			case 13: deleteAfterNode();
					break;
			default: printf("Invalid choice\n");
		}
		printf("\n");
	}
	while(ch != 0);
	return 0;
}

