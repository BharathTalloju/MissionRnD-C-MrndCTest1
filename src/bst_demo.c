#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	char data;
	struct node *left_child;
	struct node *right_child;
}NODE;

NODE *create_node(int value){
	NODE *temp = NULL;

	temp = (NODE*)malloc(sizeof(NODE));
	temp-> data = value;

	return temp;
}

int main(){
 NODE *n;

 n = create_node(46);
 printf("%d",n-> data);
}
