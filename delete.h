#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"structure.h"


void rollno(st** head){
	if(*head==NULL){
		printf("NO DATA........\n");
		return;
	}
	int data;
	printf("Enter the rollno to delete: ");	
	scanf("%d",&data);
	st* temp=*head;
	if((*head)->rollno==data){
		*head=temp->next;
		free(temp);	
		printf("Delete Successfully\n");
		return;
	}
	else{
		while(temp->next!=NULL){
			if(temp->next->rollno==data){
				st* prev=temp->next;
				temp->next=prev->next;
				free(prev);
				printf("Delete Successfully\n");
				return;
			}
			temp=temp->next;	
		}
	}
	printf("Rollno Not Found......\n");
}

void name(st** head){
	if(*head==NULL){
		printf("NO DATA.....\n");
		return;
	}
	int c=0;
	char str[30];
	printf("Enter the Name to delete: ");
	scanf("%29s",str);
	st* temp=*head;
	while(temp!=NULL){
		if(strcmp(temp->name,str)==0){
			printf("\t------------------------------------------------------------\n");
			printf("\t %-10d|\t %-10s|\t %-10f|\n",temp->rollno,temp->name,temp->mark);
			printf("\t------------------------------------------------------------\n");
			c++;
		}
		temp=temp->next;
	}
	temp=*head;
	if(c==0){
		printf("NO RECORDS FOUND...........\n");
		return;
	}
	else if(c==1){
		if(strcmp((*head)->name,str)==0){
			*head=temp->next;
			free(temp);	
			//return;
		}
		else{
			while(temp->next!=NULL){
				if(strcmp(temp->next->name,str)==0){
					st* prev=temp->next;
					temp->next=prev->next;
					free(prev);
					break;
				}
				temp=temp->next;	
			}
		}
	}
	else if(c>1){
		rollno(head);
	}
	printf("Deleted Successfully.......\n");
	
}

void mark(st** head){
	if(*head==NULL){
                printf("NO DATA.....\n");
                return;
        }
        int c=0;
	float per;
        printf("Enter the Mark to delete: ");
        scanf("%f",&per);
        st* temp=*head;
        while(temp!=NULL){
                if(temp->mark==per){
			printf("\t------------------------------------------------------------\n");
                        printf("\t %-10d|\t %-10s|\t %-10f|\n",temp->rollno,temp->name,temp->mark);
			printf("\t------------------------------------------------------------\n");
                        c++;
                }
                temp=temp->next;
        }
        temp=*head;
        if(c==0){
                printf("NO RECORDS FOUND...........\n");
                return;
        }
        else if(c==1){
                if((*head)->mark==per){
                        *head=temp->next;
                        free(temp);
                        //return;
                }
                else{
                        while(temp->next!=NULL){
                                if(temp->next->mark==per){
                                        st* prev=temp->next;
                                        temp->next=prev->next;
                                        free(prev);
                                        break;
                                }
                                temp=temp->next;
                        }
                }
	}
	else if(c>1){
               	rollno(head);
        }
        printf("Deleted Successfully.......\n");

}

int delete(st** head){
	int op;
	while(1){
		printf("\t\nEnter the Option\n\t1.Rollno\n\t2.Name\n\t3.Mark\n\t4.Exit\n");
		printf("\tEnter: ");
		scanf("%d",&op);
		switch(op){
			case 1:
				rollno(head);
				break;
			case 2:
				name(head);
				break;
			case 3:
				mark(head);
				break;
			case 4:
				return 0;
			default:
				printf("Enter the valid option\n");
		}
	}
}

