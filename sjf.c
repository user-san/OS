#include<stdio.h>
struct process
{
    int at,wt,tat,bt;
};
void main()
{
        struct process pc[10];
        int n;
        printf("Enter number of process:");
       scanf("%d",&n);
        int bust[10];
        int i,j,k,count=0,shortpc=0;
        float avg_tat=0.0,avg_wt=0.0;
        for(i=0; i<n; i++)
        { printf("Enter arrival time for pid %d:",i+1);
                scanf("%d",&pc[i].at);
                printf("Enter Burst time for pid %d:",i+1);
                scanf("%d",&pc[i].bt);
              bust[i]=pc[i].bt;
        }
        pc[9].bt=10000;
        bust[9]=pc[9].bt;   
          int t=0;                  
        while(count!=n)
        {

           shortpc=9;
           pc[9].bt=1000;
           for(i=0; i<n; i++)
           {
                   if(pc[i].bt <pc[shortpc].bt && (pc[i].at<=t && pc[i].bt!=0))
                   { shortpc=i;}
           }
            if(shortpc!=9)
            { t+=pc[shortpc].bt;
           pc[shortpc].bt=0;
            }
            else
                    t++;
           if(pc[shortpc].bt==0 && shortpc!=9)
           {
                  count++;
                  pc[shortpc].wt=t -pc[shortpc].at-bust[shortpc];
                  pc[shortpc].tat=t-pc[shortpc].at;
                  avg_tat+=pc[shortpc].tat;
                  avg_wt+=pc[shortpc].wt;
           }
        }
printf("PID\tTAT\tWT\n");
for(i=0; i<n; i++)
{
   printf("%d\t%d\t%d\n",i+1,pc[i].tat,pc[i].wt);
}
printf("The average turn around time :%f \n The average waiting time: %f",avg_tat/n,avg_wt/n);
}
