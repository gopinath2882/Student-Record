#include<stdio.h>
#include<stdlib.h>
#include"structure.h"

int print(st* head){
	if(head==NULL){
		printf("NO RECORDS.....\n");
		return 0;
	}
	st* temp=head;
	printf("-------------------------------------------------------------\n");
	printf("            ********STUDENTS RECORDS********                 \n");
	printf("-------------------------------------------------------------\n");
	printf("| %-10s | %-20s | %-10s |\n", "Roll No", "Name", "Mark");
	printf("-------------------------------------------------------------\n");

	while(temp != NULL)
	{
    	   printf("| %-10d | %-20s | %-10.2f |\n",
           temp->rollno,
           temp->name,
           temp->mark);

    	 temp = temp->next;
	}
}


