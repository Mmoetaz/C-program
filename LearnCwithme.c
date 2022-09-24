//BY MMB
/* Mohamed Moetaz Boughalmi*/
#include<stdio.h>
#include<stdlib.h>
typedef struct{
	char *name;
	int age;
	int id;
}employee;
typedef struct n{
	employee elem;
	struct n* next;
	struct n* prev;
	
}nnode;
typedef nnode *list;

employee emp(){
	employee e;
	e.name=malloc(sizeof(char)*20);
	printf("Name: ");
	scanf("%s",e.name);
	printf("Age:");
	scanf("%d",&e.age);
	printf("ID:");
	scanf("%d",&e.id);
	return e;
}

void empty(list *l){
	*l=NULL;
}

void fill(list *l){
	list p;
	p=(list)malloc(sizeof(list));
	p->elem=emp();
	if(*l==NULL){
		p->next=NULL;
		p->prev=NULL;
		*l=p;
	}else{
		p->prev=NULL;
		p->next=*l;
		(*l)->prev=p;
		*l=p;
	}
}

void show_fifo(list l){
	list p;
	p=l;
	while(p->next!=NULL){
		p=p->next;
	}
	while(p!=NULL){
		printf("\n\t\t\t___________\n");
		printf("\t\t\tName:%s\n",p->elem.name);
		printf("\t\t\tage:%d\n",p->elem.age);
		printf("\t\t\tID:%d\n",p->elem.id);
		printf("\n\t\t\t___________\n");
		p=p->prev;
	}
}

void show_lifo(list l){
	list p=l;
	while(p!=NULL){
		printf("\n\t\t\t___________\n");
		printf("\t\t\tName:%s\n",p->elem.name);
		printf("\t\t\tage:%d\n",p->elem.age);
		printf("\t\t\tID:%d\n",p->elem.id);
		printf("\n\t\t\t___________\n");
		p=p->next;
	}
}

void show_more_18(list l){
	list p;
	p=l;
	while(p!=NULL){
		if(p->elem.age>=18){
			printf("\n\t\t\t___________\n");
			printf("\t\t\tName:%s\n",p->elem.name);
			printf("\t\t\tage:%d\n",p->elem.age);
			printf("\t\t\tID:%d\n",p->elem.id);
			printf("\n\t\t\t___________\n");	
		}
		p=p->next;
	}
}

void show_less_18(list l){
	list p;
	p=l;
	while(p!=NULL){
		if(p->elem.age<18){
			printf("\n\t\t\t___________\n");
			printf("\t\t\tName:%s\n",p->elem.name);
			printf("\t\t\tage:%d\n",p->elem.age);
			printf("\t\t\tID:%d\n",p->elem.id);
			printf("\n\t\t\t___________\n");	
		}
		p=p->next;
	}
}

main(){
	int i;
	list l;
	empty(&l);
	printf("Please put a '_' between the first name and the name without spaces!! \n(ej: John_Smith):");
	printf("\n\nIf you want to Enter a new User ==> PRESS 1");
	printf("\nIf you want to Display the list from the beginning ==> PRESS 2");
	printf("\nIf you want to Display the list from the end ==> PRESS 3");
	printf("\nIf you want to Display people aged 18 or more ==> PRESS 4");
	printf("\nIf you want to Display people aged less than 18 ==> PRESS 5");
	printf("\nLeave ==> PRESS 0\n");
	do{
		printf("\nChoice:");
		scanf("%d",&i);
		if(i==1){
			fill(&l);
		}else if(i==2){
			if(l==NULL)
				printf("NULL!");
			else
				show_fifo(l);
		}else if(i==3){
			if(l==NULL)
				printf("NULL");
			else
				show_lifo(l);
		}else if(i==4)
				show_more_18(l);		
		else if(i==5){
				show_less_18(l);		
		}
		
	}while(i!=0);
	
}
