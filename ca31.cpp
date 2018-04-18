#include<stdio.h>
#include<iostream>
struct process
{
int pid;
int btime;
int wtime;
int ttime;
int prtime;
} p[10];
main()
{
int i,j,k,n,ttur,twat,temppro,tempburst,temppir;
float awat,atur;
printf("Enter no. of process :");
scanf("%d", &n);
for(i=0; i<n; i++)
{
printf("\nBurst time for process P%d (in ms) :",(i+1));
scanf("\t%d", &p[i].btime);
printf("\n Enter priority\t");
scanf("%d",&p[i].prtime);
p[i].pid = i+1;
}
for(i=0;i<n;i++)
{
for(j=i+1;p[j].prtime;)
{
tempburst=p[i].btime;
p[i].btime=p[j].btime;
p[j].btime=tempburst;
temppro=p[i].pid;
p[i].pid=p[j].pid;
p[j].pid=temppro;
temppir=p[i].prtime;
p[i].prtime=p[j].prtime;
p[j].prtime=temppir;
}
}
p[0].wtime = 0;
for(i=0; i<n; i++)
{
p[i+1].wtime = p[i].wtime + p[i].btime;
p[i].ttime = p[i].wtime + p[i].btime;
}
ttur = twat = 0;
for(i=0; i<n; i++)
{
ttur+=p[i].ttime;
twat+=p[i].wtime;
}
awat = (float)twat/n;
atur = (float)ttur/n;

printf("\n priority Scheduling ALGORITHM \n\n");
for(i=0; i<38; i++)
printf("-");
printf("\n Process B-Time T-Time W-Time Priority\n");
for(i=0; i<38; i++)
printf("-");
for(i=0; i<n; i++)
printf("\n P%d\t%4d\t%3d\t%2d\t%d",p[i].pid,p[i].btime,p[i].ttime,p[i].wtime,p[i].prtime);
printf("\n");
for(i=0;i<38;i++)
printf("-");
printf("|");
for(i=0;i<n;i++)
{
k = p[i].btime/2;
for(j=0; j<k;j++)
printf(" ");
printf("P%d",p[i].pid);
for(j=k+1;j<p[i].btime;j++)
printf(" ");
printf("|");
}
printf("\n");
printf("-");
for(i=0;i<(p[n-1].ttime + 2*n);i++)
printf("-");
printf("\n");
printf("0");
for(i=0;i<n;i++)
{
for(j=0;j<p[i].btime;j++)
printf(" ");
printf("%2d",p[i].ttime);
}
printf("\n\nAverage waiting time: %5.2fms", awat);
printf("\nAverage turn around time : %5.2fms\n", atur);
}
