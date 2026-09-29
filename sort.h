#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"structure.h"

int count(st* temp){
	int c=0;
	while(temp!=NULL){
		c++;
		temp=temp->next;
	}
	return c;
}

void sort_name(st** head){
	if(*head==NULL){
		printf("NO DATA......\n");
		return;
	}
	int c=count(*head),size=sizeof(st)-8;
	st* temp=*head;
	st**p=(st**)malloc(c*sizeof(st*));
	for(int i=0;i<c;i++){
		p[i]=temp;
		temp=temp->next;
	}
	//temp=*head;
	for(int i=0;i<c;i++){
		for(int j=0;j<c-1-i;j++){
			if(strcmp(p[j]->name,p[j+1]->name)>0){
				st t;
				memcpy(&t,p[j],size);
				memcpy(p[j],p[j+1],size);
				memcpy(p[j+1],&t,size);
			}
		}
	}
}

void sort_mark(st** head){
	if(*head==NULL){
                printf("NO DATA......\n");
                return;
        }
        int c=count(*head),size=sizeof(st)-8;
        st* temp=*head;
        st**p=(st**)malloc(c*sizeof(st*));
        for(int i=0;i<c;i++){
                p[i]=temp;
                temp=temp->next;
        }
        //temp=*head;
        for(int i=0;i<c;i++){
                for(int j=0;j<c-1-i;j++){
                        if(p[j]->mark<p[j+1]->mark){
                                st t;
                                memcpy(&t,p[j],size);
                                memcpy(p[j],p[j+1],size);
                                memcpy(p[j+1],&t,size);
                        }
                }
        }

}

int sort(st** head){
	int op;
label:	printf("\tEnter the option\n\t1.Name\n\t2.Mark\n");
	printf("\tEnter : ");
	scanf("%d",&op);
	if(op==1){
		sort_name(head);
		printf("Sort Done.......\n");
	}
	else if(op==2){
		sort_mark(head);
		printf("Sort Done.......\n");
	}
	else{
		printf("Invalid Option.....\n");
		goto label;
	}
	return 0;
}
