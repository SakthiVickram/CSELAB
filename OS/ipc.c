#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/uio.h>
#include<sys/types.h>
int main()
{i
nt pid,pfd[2],n,s,c,i;
if(pipe(pfd)==-1)
{p
rintf("\nError in pipe connection\n");
exit(1);
}
pid=fork();
if(pid>0)
{p
rintf("\nParent Process");
printf("\n\n\tSummationSeries");
printf("\nEnter the number:");
scanf("%d",&n);
close(pfd[0]);
write(pfd[1],&n,sizeof(n));
close(pfd[1]);
exit(0);
}e
lse
{c
lose(pfd[1]);
read(pfd[0],&n,sizeof(n));
printf("\nChild Process");
i=0;
s=0;
close(pfd[0]);
printf("\n Series is:");
while(i<=n)
{s
=s+i;
printf("%d ",s);
i++;
}
}
}