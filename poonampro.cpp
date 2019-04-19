#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define CLRSCR system("cls");
using namespace std;
int main()
{
	CLRSCR
 	int time_slice,process_id[10],need[10];
int waiting_time[10],turn_around_time[10],i,j,no_of_processes,n1;
	int burst_time[10],flag[10],ttat=0,twt=0;
	float awt,atat;
	printf("\t\t ROUND ROBIN SCHEDULING"); 
	printf("\n Enter the number of Processes \n");
 	scanf("%d",&no_of_processes);
	n1=no_of_processes;
 	printf("\n Enter the Timeslice \n");
 	scanf("%d",&time_slice);
	for(i=1;i<=no_of_processes;i++)
	{
   		printf("\n Enter the process ID %d \t",i);
   		scanf("%d",&process_id[i]);
   		printf("\n Enter the Burst Time for the process \t");
   		scanf("%d",&burst_time[i]);
   		need[i]=burst_time[i];
	}
	for(i=1;i<=no_of_processes;i++)
 	{
  		flag[i]=1;
		waiting_time[i]=0;
	}
while(no_of_processes!=0)
	{
   		for(i=1;i<=no_of_processes;i++)
   		{
    		if(need[i]>=time_slice)
			{
				for(j=1;j<=no_of_processes;j++)
       			{
					if((i!=j)&&(flag[i]==1)&&(need[j]!=0))
	  				waiting_time[j]+=time_slice;
				}
      			need[i]-=time_slice;
      			if(need[i]==0)
      			{
					flag[i]=0;
					no_of_processes--;
				}
			}
     		else
    		{
				for(j=1;j<=no_of_processes;j++)
      			{
					if((i!=j)&&(flag[i]==1)&&(need[j]!=0))
	  				waiting_time[j]+=need[i];
				}
       			need[i]=0;
       			no_of_processes--;
       			flag[i]=0;
			}
		}
	}
	for(i=1;i<=n1;i++)
	{
		turn_around_time[i]=waiting_time[i]+burst_time[i];
  		twt=twt+waiting_time[i];
  		ttat=ttat+turn_around_time[i];
	}
	awt=(float)twt/n1;
atat=(float)ttat/n1;
	//printf("\n\n ROUND ROBIN SCHEDULING ALGORITHM \n\n");
	printf("\n\n Process \t Process ID  \t BurstTime \t Waiting Time \t TurnaroundTime \n ");
	for(i=1;i<=n1;i++)
{printf("\n %5d \t %5d \t\t %5d \t\t %5d \t\t %5d          n",i,process_id[i],burst_time[i],waiting_time[i],turn_around_time[i]);
	}
	printf("\n The average Waiting Time %f",awt);
	printf("\n The average Turn around Time %f",atat);
	getch();
}      

