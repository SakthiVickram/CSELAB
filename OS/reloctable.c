#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
FILE *fp;
char type[10],name[10];
int size,offset=0;
unsigned int addr =2000;
fp=fopen("loader.txt","r");

printf("OFFSET VARIABLE SIZE\n");
while(!feof(fp))
   {

       fscanf(fp,"%s%s\n",type,name);
       if(strcmp(type,"int")==0)
        size=2;
        if(strcmp(type,"float")==0)
        size=4;
        if(strcmp(type,"char")==0)
            size=1;
         if(strcmp(type,"double")==0)
            size=8;
          printf("%d\t %s\t %d\n",offset,name,size);
        offset+=size;

   }
    return 0;
}
