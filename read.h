#include <stdio.h>
#include <stdlib.h>
#include "structure.h"

void read(st **head)
{
    FILE *fp = fopen("student.xlsx", "r");
    if (fp == NULL)
    {
        printf("FILE NOT EXIST\n");
        return;
    }
    char buffer[100];
    for (int i = 0; i < 4; i++)
    {
		fgets(buffer, sizeof(buffer), fp);
    }
    st *temp = *head;
    while (1)
    {
        st *nn =(st*)malloc(sizeof(st));
        if (fscanf(fp, "%d %19s %f",&nn->rollno,nn->name,&nn->mark) != 3)
        {
            free(nn);
            break;
        }
        nn->next = NULL;
        // printf(" %d %s %.2f\n",nn->rollno,nn->name,nn->mark);
        if (roll < nn->rollno)
            roll = nn->rollno;
        if (*head == NULL)
        {
            *head = nn;
            temp = nn;
        }
        else
        {
            temp->next = nn;
            temp = nn;
        }
    }
    fclose(fp);
    printf("READ SUCCESS......\n");
}