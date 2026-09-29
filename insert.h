#include<stdio.h>
#include<stdlib.h>
#include"structure.h"

int roll=0;
//add end
int insert(st** head){
	st* nn=(st*)malloc(sizeof(st));
	nn->rollno=++roll;
	nn->next=NULL;
	printf("Enter the new node name and marks:");
	scanf("%s%f",nn->name,&nn->mark);
	if((*head)==NULL){
		(*head)=nn;
	}
	else{
		st* temp=*head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=nn;
	}
}
