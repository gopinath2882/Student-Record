#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"structure.h"

void mod_rollno(st** head);
void mod_name(st** head);
void mod_mark(st** head);

int modify(st** head){
	int op;
label:
	printf("\tEnter the option\n\t1.Rollno\n\t2.Name\n\t3.mark\n");
	printf("\tEnter: ");
	scanf("%d",&op);
	if(op==1){
		mod_rollno(head);
	}
	else if(op==2){
		mod_name(head);
	}
	else if(op==3){
		mod_mark(head);
	}
	else{
		printf("\tEnter the valid option\n");
		goto label;
	}
}

void mod_rollno(st** head){
	if(*head==NULL){
		printf("\tNO DATA....\n");
		return;
	}
	int roll,c=0;
	printf("\tEnter the Rollno to Search: ");
	scanf("%d",&roll);
	st* temp=*head;
	while(temp!=NULL){
		if(temp->rollno==roll){
			printf("---------------------------------------------------\n");
			printf("\t|%-10d|\t%-10s|\t%-10f|",temp->rollno,temp->name,temp->mark);
			printf("---------------------------------------------------\n");
			c++;
			break;
		}
		temp=temp->next;
	}
	if(c==0){
		printf("\tRoll Not Found.......\n");
		return;
	}
	printf("\t\nEnter the Rollno to modify:");
	scanf("%d",&roll);
	temp->rollno=roll;
	
	printf("\tModified Successfully......\n");
}
void mod_name(st** head){
	if(*head==NULL){
		printf("\tNO DATA....\n");
		return;
	}
	char str[30],nstr[30];
	int c=0;
	printf("\tEnter the Name to search: ");
	scanf("%29s",str);
	st* temp=*head;
	while(temp!=NULL){
		if(strcmp(temp->name,str)==0){
			printf("\t----------------------------------------------------------\n");
			printf("\t|%-10d|\t%-10s|\t%-15f|\n",temp->rollno,temp->name,temp->mark);
			printf("\t----------------------------------------------------------\n");
			c++;
		}
		temp=temp->next;
	}
	if(c==0){
		printf("\tNO DATA FOUND.....\n");
		return;
	}
	temp=*head;
	printf("\tEnter the Name to Modify:");
	scanf("%29s",nstr);
	if(c==1){
		while(temp!=NULL){
			if(strcmp(temp->name,str)==0){
				strcpy(temp->name,nstr);
				break;
			}
			temp=temp->next;
		}
	}
	else if(c>1){
		int roll;
		printf("\t\nEnter the Rollno to modify :");
		scanf("%d",&roll);
		while(temp!=NULL){
			if(temp->rollno==roll){
				strcpy(temp->name,nstr);
				break;
			}
			temp=temp->next;
		}
	}
	printf("\tModified Successfully......\n");
}
void mod_mark(st** head){
	if(*head==NULL){
                printf("\tNO DATA....\n");
                return;
        }
        float mark,nmark;
        int c=0;
        printf("\tEnter the Mark to search: ");
        scanf("%f",&mark);
        st* temp=*head;
        while(temp!=NULL){
                if(temp->mark==mark){
			printf("\t----------------------------------------------------------\n");
            printf("\t|%-10d|\t%-10s|\t%-10f|\n",temp->rollno,temp->name,temp->mark);
			printf("\t----------------------------------------------------------\n");
                        c++;
                }
                temp=temp->next;
        }
        if(c==0){
                printf("\tNO DATA FOUND.....\n");
                return;
        }
        temp=*head;
        printf("\tEnter the Name to Modify:");
        scanf("%f",&nmark);
        if(c==1){
                while(temp!=NULL){
                        if(temp->mark==mark){
                                temp->mark=nmark;
                                break;
                        }
                        temp=temp->next;
                }
        }
        else if(c>1){
                int roll;
                printf("\t\nEnter the Rollno to modify :");
                scanf("%d",&roll);
                while(temp!=NULL){
                        if(temp->rollno==roll){
                                temp->mark=nmark;
                                break;
                        }
                        temp=temp->next;
                }
        }
        printf("\tModified Successfully......\n");

}
