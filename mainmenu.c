#include<stdio.h>
#include<stdlib.h>
#include"structure.h"
#include"insert.h"
#include"print.h"
#include"save.h"
#include"read.h"
#include"delete.h"
#include"sort.h"
#include"modify.h"

st* head=NULL;
int main(){
	int ch;
	read(&head);
	while(1){
		printf("--------------------------------------------------------\n");
		printf("        *******STUDENT RECORDS*******\n");
		printf("\n\tEnter option\n\t 1.Add\n\t 2.Delete\n\t 3.Sort\n\t 4.Modify\n\t 5.Save\n\t 6.Print\n\t 7.Exit\n");
		printf("-----------------------------------------------------------\n");
		printf("Enter:");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				insert(&head);
				break;
			case 2:
				delete(&head);
				break;
			case 3:
				sort(&head);
				print(head);
				break;
			case 4:
				modify(&head);
				break;
			case 5:
				save(&head);
				break;
			case 7:
				return 0;
			case 6:
				print(head);
				break;
			default:
				printf("Entre the valid Number...\n");
		}
	}
}
