#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include "tree.h"

int main() {

  node* n = NULL;
  node* tree = NULL; 
  char del[] = "del", add[] = "add", view[] = "view", option[MAX];  
  char *pass, *user;    
  int i, j, check = 0;

  instructions();

  while (1){

        scanf("%s", &option);
        if (strcmp (option, view) == 0){
            alpha (tree);
            printf("\n\n");
        }else{

        scanf("%s %s", &username, &password);
        
        if (strcmp (option, add) == 0){

            user = (char*)malloc(sizeof(int*) * strlen(username));
            pass = (char*)malloc(sizeof(int*) * strlen(password));

            for (i = 0; i < username[i] != '\0'; i++){
              user[i] = username[i];
            }
            user[i] = '\0';

            for (i = 0; i < password[i] != '\0'; i++){
               pass[i] = password[i];
            }
            pass[i] = '\0';

            n = addUser (tree, user, pass, 0);    

            if (tree == NULL){
                tree = n;
            }

        }else if (strcmp (option, del) == 0){

            user = (char*)malloc(sizeof(int*) * strlen(username));
            pass = (char*)malloc(sizeof(int*) * strlen(password));

            for (i=0; i<username[i] != '\0';i++){
              user[i] = username[i];
            }
            user[i] = '\0';
            
            for (i=0; i<password[i] != '\0';i++){
               pass[i]=password[i];
            }
            pass[i] = '\0';
            
            check = 0;
            delUser(tree, user, pass, &check);
            if (check==0){
            printf("Wrong password\n\n");
            }
        }else printf("Error: The input is misspelled, try again.\n\n");
            
        }
    }

    return 0;
}
    
void instructions (){

    printf("These are the instruccions to use this program: ");
    printf("\nType 'del' or 'add' in lowercase, then a space, then the username, a space, and at final the password.");
    printf("\nThe program will not let you advance if you dont input 3 strings.");
    printf("\nExamples: add juan 123    del ana ilikedogs   add lulu uwu98\n\n");
}

node* addUser (node* pos, char* user, char* pass, int d) {
  node* temp;
  if (pos == NULL) {
    pos = (node*) malloc (sizeof (node));
    pos -> user = user;
    pos -> password = pass;
    pos -> depth = d;
    printf ("User '%s' has been added.\n\n", user, pass);
  
  } else {
    if (strcmp (pos -> user, user) == 0) {
      if (pos -> password != NULL){
      printf("This user was already created\n\n");
      }
      else{
          pos -> password = pass;
          printf ("User: '%s' has been added.\n\n", user, pass);
      }
    } else if (strcmp (pos -> user, user) > 0) { 
      temp = addUser (pos -> leftChild, user, pass, d + 1);
      if (pos -> leftChild == NULL) {
	pos -> leftChild = temp;
      }
    } else if (strcmp (pos -> user, user) < 0){
      temp = addUser(pos -> rightChild, user, pass, d + 1); 
      if (pos -> rightChild == NULL) {
	pos -> rightChild = temp;
      }
    }
  }
  return pos;
}

void delUser (node* pos, char* user, char* pass, int* n){
    if (pos != NULL) {
        
        delUser (pos -> leftChild, user, pass, n);
        delUser (pos -> rightChild, user, pass, n);
        if (strcmp (pos -> user, user) == 0 && strcmp(pos -> password, pass) == 0){
            pos -> password = NULL;
            printf("The user '%s' has been eliminated  \n\n", user);
            *n = 1;
        }
    }
}

void alpha (node* pos) {
  if (pos != NULL) {
    alpha(pos -> leftChild);
    if (pos -> password != NULL){
    printf("%s ", pos -> user);
    }
    alpha(pos -> rightChild);
  }
}