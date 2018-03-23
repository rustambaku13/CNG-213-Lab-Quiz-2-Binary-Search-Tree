#include<stdio.h>
#include<stdlib.h>
#define NUM_GRADE 15
struct Node{
	struct Node *left;
	struct Node *right;
	int grade;
	int counter;
};

typedef struct Node *Tree;
Tree insertTree(Tree, int);
void showHighest(Tree);
void displayTree(Tree,int);
int main(){
	int i;
	Tree myTree=NULL;
	int grade;
	for(i=0;i<NUM_GRADE;i++){
		printf("\nPlease enter your grade:\n");
		scanf("%d",&grade);
		myTree=insertTree(myTree,grade);
		
	}
	showHighest(myTree);
	printf("\n\n\n\n\n");
	displayTree(myTree,0);
}

void displayTree(Tree t, int depth){
	if(t==NULL){
		
	}
	else{
	int i=0;
	
	displayTree(t->right,depth+1);
	for(i;i<=depth;i++){
		printf("\t");
	}
	printf("%d(%d)\n",t->grade,t->counter);
	displayTree(t->left,depth+1);
	
	
	}
	//Auxiliary function just to test so that my tree is filled correctly
}
void showHighest(Tree t){
	if(t==NULL){
		printf("The tree is empty\n");
	}
	else if(t->right==NULL){
		printf("The highest grade is %d, and %d students scored this grade\n",t->grade,t->counter);
	}
	else{
		showHighest(t->right);
	}
	
}
Tree insertTree(Tree t, int grade){
	
	if(t==NULL){
		t=(Tree)malloc(sizeof(struct Node));
		if(t==NULL){
			printf("not enough space\n");
			
		}
		else{
		t->left=NULL;
		t->right=NULL;
		t->grade=grade;
		t->counter=1;
		}
	}
	
	else if(t->grade<grade){
		t->right=insertTree(t->right,grade);
	}
	else if(t->grade>grade){
		t->left=insertTree(t->left,grade);
		
	}
	
	else if(t->grade==grade){
		t->counter++;
	}
	
	return t;
	
	
}
