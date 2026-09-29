#include <stdio.h>
#include <stdlib.h>
#include "structure.h"

void save(st **head)
{
    if (*head == NULL)
    {
        printf("NO DATA......\n");
        return;
    }
    FILE *fp = fopen("student.xlsx", "w");
    fprintf(fp, "-------------------------------------------------------------\n");
    fprintf(fp, "            ********STUDENTS RECORDS********\n");
    fprintf(fp, "-------------------------------------------------------------\n");
    fprintf(fp, "| %-10s |    %-20s | %-10s |\n","Roll No", "Name", "Mark");
    st *temp = *head;
    while (temp != NULL)
    {
        fprintf(fp, " %-10d \t%-20s \t%-10.2f\n",temp->rollno,temp->name,temp->mark);
        temp = temp->next;
    }
    fclose(fp);
    printf("SAVED SUCCESS......\n");
}