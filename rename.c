#include <stdio.h>
#include <string.h>

void write(double input, FILE *fp){
  fprintf(fp, "%f\n", input);
}

int main(int argc, char *argv[])
{
  FILE *fp;
  char fName[20];
  FILE *temp;
  char ext[9]="_plot.txt";
  int i;
  char c;

  temp=fopen("num.h", "r");
  if(temp==NULL){
    printf("damn it!\n");
    return -1;
  }
  i=0;
  while((c=fgetc(temp))!=EOF){
    if(c=='.'){
      break;
    }
    printf("%c",c);
    if(i>1){
      fName[i-2]=c;
    }
    i++;
   
  }
  i++;
  fName[i]='\0';
  printf("\n%s\n", fName);

  sprintf(fName,"%s%s", fName, ext);
  printf("\n%s\n", fName);
  fp = fopen(fName, "w");

  for(i=0; i<10; i++){
    write((double)(i*0.1), fp);
  }

  fclose(fp);
  fclose(temp);

  return 0;
}
