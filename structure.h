#ifndef STRUCTURE_H
#define STRUCTURE_H

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int rollno;
	char name[30];
	float mark;
	struct node* next;
}st;

int roll;
//exturn st* head=NULL;
#endif
