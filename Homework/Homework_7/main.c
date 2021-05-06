#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define MAX 50

int equal (int, int[]);

void instructions();

int cont = 0;

int main(){

  int pin[MAX], timediff[MAX] = {0}, i, check, n, j, flag, activecont = 0, actives, x, diff;
  char c, ans[5]; 
  srand(time(0)); //generate a randon pin for new workers

  FILE* leer = fopen ("empleados.txt", "r");
  FILE* newUser = fopen ("empleados.txt", "a");
  FILE* escribir = fopen ("registro.txt", "a");
  FILE* state = fopen ("activo.txt", "a");
  FILE* rstate = fopen ("activo.txt", "r");

  instructions();
  
  while ((c = fgetc(leer)) != EOF){
      if (c == '\n'){
        cont++;
      }
    }

    rewind(leer);

    for (i = 0; i < cont; i++){
      fscanf(leer, "%d", &pin[i]);
    }

    while ((c = fgetc(rstate)) != EOF){
      if (c == '\n'){
        activecont++;
      }
    }

  do{

  scanf("%s", &ans);

  if (strcmp ("adduser", ans) == 0){
  
    do{
      flag = 0;
      j = 0;
      n = (rand () % 200) + 1;
      
      while (j < MAX){
        if (pin[j++] == n){
          flag = 1;
        }
      }

    }while (flag == 1);

    fprintf(newUser, "%d\n", n);

    printf("The pin for the new worker is: '%d'\n", n);

  }else if (strcmp("pin", ans) == 0){

    actives = 0;

    scanf("%d", &check);

    if (equal(check, pin) == 1){

      fprintf(state, "%d\n", check);

      time_t tiempo = time(0);                       
        struct tm *tlocal = localtime(&tiempo);      
        char output[128];
        strftime(output,128,"%d/%m/%y %H:%M:%S",tlocal);
        timediff[0] = 

        rewind (rstate);

      for (i = 0; i < activecont; i++){
          
          fscanf(rstate, "%d", &x);
          if (x == check){
            actives++;
          }
      }

      if (actives % 2 == 0){                                    
        fprintf(escribir, "User with the pin '%d' STARTED working at %s\n", check, output);
      }else{
        fprintf(escribir, "User with the pin '%d' STOPPED working at %s\n", check, output);
      }

    }else printf("That pin doesn't exist\n");   

  }else if (strcmp ("exit", ans) != 0){
    printf("Error. Wrong input, try again.\n");
  }

  printf("\n");

  }while (strcmp ("exit", ans) != 0);
  
  fclose (leer);
  fclose (newUser);
  fclose (escribir);
  fclose (state);
  fclose (rstate);

  return 0;
}

int equal (int check, int pin[]){

  int i, pos;

  for(i = 0; i < cont; i++){

      if (pin[i] == check){ 
        return 1;
      }
      
  }

  return 0;
}

void instructions(){

  printf("To use this program you need to put the commnands in lowercase.");
  printf("\nIf you add and user you must exit the program and run it again if you want to put the attendence");
  printf("\nCommands: \n'adduser' that creates a pin for a new worker");
  printf("\n'pin' to type the pin of the worker, for example: 'pin 123' or 'pin 555'");
  printf("\n'exit' to end the program\n\n");
}
