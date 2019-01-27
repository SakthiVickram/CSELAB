#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define max 100

struct table
{
    char name[20];
    char type[15];
    int addr;
};

int main()
{
    struct table ob[50];
char str[100];
char w1[5]="void",w2[5]="int";
int i=0,len;
FILE *fp;
fp=fopen("source.txt","r+");

ob[0].addr=1000;


while (fgets(str,max, fp) != NULL)
{
    if((strstr(str,"include" ) != NULL) && (strstr(str,"#") != NULL) && (strstr(str, ".h") != NULL)) //find header files
    {
    //printf("include there");

	strcpy(ob[i].name,"include");
	strcpy(ob[i].type,"header files");
	if(i!=0)
	 ob[i].addr=ob[i-1].addr+1;
     i++;
    }
if( ( (strstr(str,w1)) ||(strstr(str,w2)) )  && (strstr(str,"main()")) )   //find main function
{
    if(strstr(str,w1))
    strcpy(ob[i].name,w1);
    if(strstr(str,w2))
    strcpy(ob[i].name,w2);
	 strcpy(ob[i].type,"return type");
	   if(i!=0)
          ob[i].addr=ob[i-1].addr+1;
            i++;
}
/*if(  (strstr(str,w2) ) && !(strstr(str,w3))  )           //find declaration
{
 puts(str);
 char temp[15];
for(i=3;str[i]!=';';i++)
{
    temp[i-3]=str[i];
//char *token = strtok(str, ",");
//printf("%s\n", token);
   /* if( ( (str[i]>=' a ') || (str[i]<=' z' ) )  && ( (str[i]!=',')&&(str[i]!=' ') ) )
    {
        printf("yes:%c",str[i]);

    }
}
temp[i]='/0';
//puts(temp);

}*/

if(strstr(str,"printf"))  //find printf
{
    strcpy(ob[i].name,"printf");
    strcpy(ob[i].type,"keyword   ");
     ob[i].addr=ob[i-1].addr+1;
    i++;
}
if(strstr(str,"scanf"))  //find scanf
{
    strcpy(ob[i].name,"scanf");
    strcpy(ob[i].type,"keyword   ");
     ob[i].addr=ob[i-1].addr+1;
    i++;
}

if(strchr(str,'=')  ) //find operators
{
     strcpy(ob[i].name,"equalto");
    strcpy(ob[i].type,"operator");
     ob[i].addr=ob[i-1].addr+1;
    i++;
}
if (strchr(str,'+'))
{
    strcpy(ob[i].name,"plus");
    strcpy(ob[i].type,"operator");
     ob[i].addr=ob[i-1].addr+1;
    i++;
}
if(strchr(str,'-'))
{
     strcpy(ob[i].name,"minus");
    strcpy(ob[i].type,"operator");
     ob[i].addr=ob[i-1].addr+1;
    i++;
}
if(strchr(str,'*'))
{
    strcpy(ob[i].name,"multiplication");
    strcpy(ob[i].type,"operator");
     ob[i].addr=ob[i-1].addr+1;
    i++;
}
if(strchr(str,' /') )
{
    strcpy(ob[i].name,"division");
    strcpy(ob[i].type,"operator");
     ob[i].addr=ob[i-1].addr+1;
    i++;
}

printf("l:%s",str);
len=i;
}

printf("symbol table:\n");
printf("Sno\tname\ttype\t\taddress\n");
for (i=0;i<len ;i++)
{

    printf("%d\t%s\t%s\t%d\n",i,ob[i].name,ob[i].type,ob[i].addr);
   /* printf("Sno:%d)\n",i);
    printf("name:%s\n",ob[i].name);
    printf("type:%s\n",ob[i].type);
    printf("address:%d\n",ob[i].addr);
*/
}
 fclose(fp);
return 0;
}
