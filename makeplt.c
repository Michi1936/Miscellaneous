#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  FILE *plt;
  FILE *numbers;
  char imgName[32];
  double angVel=0;
  char fName[64];
  char line[256];
  int XSIZE=0;
  int YSIZE=0;
  double interval=0.1;
  char readline[256];
  char value[16];
  int row=0;
  int i=0;
  numbers=fopen("numbers.h", "r");
  if(numbers==NULL){
    printf("Error!\n");
    return -1;
  }

  while(fgets(readline,256,numbers)!=NULL){
    if(row==5){
      i=0; 
      while(readline[14+i]!='\n'){
        value[i]=readline[14+i];
        i++;
      }
      XSIZE=atoi(value);
    }
    if(row==6){
      i=0; 
      while(readline[14+i]!='\n'){
        value[i]=readline[14+i];
        i++;
      }
      YSIZE=atoi(value);
    }
    row++;
}


  printf("Enter image name\n");
  scanf("%s", imgName);
  printf("Enter anglar velocity\n");
  scanf("%lf", &angVel);
  sprintf(fName, "%f_%s_plot.dat", angVel, imgName);

  plt=fopen("rigid_anime.plt", "w");

  sprintf(line,"set xrange[-1:%f]\n",(XSIZE+10)*interval);
  fprintf(plt,"%s",line);
  sprintf(line,"set yrange[-1:%f]\n",(YSIZE+10)*interval);
  fprintf(plt,"%s",line);
  sprintf(line,"set size ratio %f 1.0\n",(double)((YSIZE+20)/(XSIZE+20)));
  fprintf(plt,"%s",line);
  sprintf(line,"do for[i=1:t:2]{\n");
  fprintf(plt,"%s",line);
  sprintf(line,"print i\n");
  fprintf(plt,"%s",line);
  sprintf(line,"plot '%s' index 0 u 2:3 w p lt 5, '%s' index i u 2:3 w p lt 7, '%s' index i+1 u 2:3 w p lt 10\n", fName, fName, fName);
  fprintf(plt,"%s",line);
  sprintf(line,"}\n");
  fprintf(plt,"%s",line);

  fclose(plt);
  fclose(numbers);
  return 0;
}
