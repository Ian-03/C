#include<stdio.h>
#include<string.h>

void gline (char[], int);

void expand (char [],char []);

int main(){
  
  const int max=1000;
  char s1[max],s2[max];

  gline (s1,max);

  expand (s1,s2);

  return 0;
}

void expand (char s1[], char s2[]){

  int j=0;

  for (int i=0; s1[i]!='\0'; i++){
  
    if (s1[i]=='-' && i!=0 && i!=strlen(s1)-1){

      do{
         s1[i-1]++;
         s2[j++]=s1[i-1];
      }while (s1[i-1]!=s1[i+1]);

      i++;

    }else s2[j++]=s1[i];
  }

  printf("%s",s2);
}

void gline (char s1[], int max){

  int c,i;

  for(i=0; i<max-1 && (c=getchar())!='\n' && c!=EOF; i++){
    s1[i]=c;
  }
  if(c=='\n'){
    s1[i++]=c;
  }
  s1[i]='\0';

}
