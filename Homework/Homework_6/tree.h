 #define MAX 50

typedef struct treenode {
  char* user; 
  char* password; 
  unsigned int depth;
  struct treenode* leftChild;
  struct treenode* rightChild;
}node;

void instructions ();

node* addUser (node* , char* , char*, int); 

void delUser (node*, char* , char* , int* ); 

void alpha (node*);  

char password[MAX], username[MAX];