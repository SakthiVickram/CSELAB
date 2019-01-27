#include <stdio.h>
#include <stdlib.h>

int main()
{
FILE *fp;
char type[10],name[10];
int size;
unsigned int addr =2000;
fp=fopen("loader.txt","r");

printf("ADDRESS VARIABLE SIZE\n");
while(!feof(fp))
   {
       fscanf(fp,"%s%s",type,name);
       if(strcmp(type,"int")==0)
        size=2;
        if(strcmp(type,"float")==0)
        size=4;
        if(strcmp(type,"char")==0)
            size=1;
         if(strcmp(type,"double")==0)
            size=8;
            addr+=size;
         printf("%u\t %s\t %d\n",addr,name,size);

   }
    return 0;
}
