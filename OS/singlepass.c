#include <stdio.h>
#include <stdlib.h>
struct optab
{
    char mnemonic[15];
    char code[5];
     char val1[5];
     char val2[5];
}ob[10];

void splits(char [],char[10][10]);
int main()
{
char str[15],split[10][10];
int i,j,no,l=0,a,size;
printf("Enter the number of statements:");
scanf("%d",&size);
fflush(stdin);
     for(j=0;j<size;j++)
     {

        printf("Enter the code: ");
         gets(str);
                                            if(strstr(str,"LDA"))
                                        {
                                                splits(str,split);
                                                      //  for(i=0;i < 2;i++)
                                                              //  printf("%s\n",split[i]);

                                                strcpy(ob[l].mnemonic,"LDA");
                                                strcpy(ob[l].code,"3A");
                                                        no=atoi(split[1]);
                                                     a=no%100;
                                                     if(a==0)
                                                        strcpy(ob[l].val1,"00");
                                                      else
                                                      {

                                                            itoa(a,ob[l].val1,10);
                                                      }
                                                      no/=100;
                                                      itoa(no,ob[l].val2,10);

                                                     l++;
                                        }
                                        if(strstr(str,"SUB"))
                                        {
                                            splits(str,split);
                                             strcpy(ob[l].mnemonic,"SUB");
                                                strcpy(ob[l].code,"90");
                                            l++;
                                        }
                                        if(strstr(str,"STA"))
                                        {
                                            splits(str,split);
                                            strcpy(ob[l].mnemonic,"STA");
                                                strcpy(ob[l].code,"32");
                                         no=atoi(split[1]);
                                                     a=no%100;
                                                     if(a==0)
                                                        strcpy(ob[l].val1,"00");
                                                      else
                                                         itoa(a,ob[l].val1,10);

                                                      no/=100;
                                                      itoa(no,ob[l].val2,10);

                                                     l++;
                                        }
                                        if(strstr(str,"HLT"))
                                        {
                                             strcpy(ob[l].mnemonic,"HLT");
                                                strcpy(ob[l].code,"76");
                                        }

   }
                                        printf("mnemonic  opcode val1  val2\n");
                                            for(i=0;i<size;i++)
                                            {

                                                printf("%s  %s  %s %s\n",ob[i].mnemonic ,ob[i].code,ob[i].val1,ob[i].val2);
                                                          }
    return 0;
}


void splits(char str[],char split[10][10])
{
int r,c,i;
r=c=0;
                for(i=0;i<=strlen(str);i++)
                    {
                                if(str[i]== ' ' || str[i]=='\0')
                                    {
                                            split[r][c]='\0';
                                            r++;
                                            c=0;
                                    }
                                else{
                                        split[r][c]=str[i];
                                        c++;
                                        }
                    }
}
