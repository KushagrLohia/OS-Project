//In this we have added sorting technique
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
int n,p;
int ttime=0;                                     //Declaring the variable
float avg_wt=0;
float avg_tat=0;
printf("Enter the number of Processes: ");
scanf("%d",&n);                  			  //Asking value from user
int process[n];                			     //Declaring the variable
double complition_time[n], turnaround_time[n], waiting_time[n], arrival_time[n], burst_time[n], min, temp;  //Declaring the variable
printf("\n");
for(int i=0;i<n;i++)       			      //Asking burst time and arrival time from user
	{
	 	printf("Enter the value of arrival time for process %d: ",i);
		scanf("%d",&p);
		if(p==0)                //if-else condition as if the user enter arrival time as 0 it will display an error
		{					
		printf("zero not allowed\n");
		printf("Re-enter the arrival time: ");
		scanf("%lf",&arrival_time[i]);
		}
		else
			arrival_time[i]=p;
		printf("Enter the value of burst time for process %d: ",i);
		scanf("%lf",&burst_time[i]);
		printf("\n");
		process[i]=i+1; 
	}
printf("---------------------values that are enterd---------------------------\n\n");
printf("\t\t\t_________________________________________________________________\n");
printf("\t\t\t|	Process	|	Arrival Time	|	Burst Time	|\n");
printf("\t\t\t_________________________________________________________________\n");

for(int i=0;i<n;i++)       		      //Printing the values
	{
	
	printf("\t\t\t|	P%d	|	   %0.00lf	   	|	%0.00lf		|\n",process[i], arrival_time[i], burst_time[i]);
	printf("\t\t\t_________________________________________________________________\n");
	}
printf("\n\n\n");
printf("\n\n\n");
printf("-----------------------Applying the SJF-----------------------------\n\n");
printf("\n\n\n");
for(int i=0;i<n;i++)
  {
    for(int j=0;j<n-1;j++)
    {
      if(arrival_time[j]>arrival_time[j+1])
      {
        
        temp = burst_time[j+1];
        burst_time[j+1] = burst_time[j];
        burst_time[j] = temp;
	
	    temp = process[j+1];
        process[j+1] = process[j];
        process[j] = temp;

	    temp = arrival_time[j];
        arrival_time[j] = arrival_time[j+1];
        arrival_time[j+1] = temp;
      
      }
    }
  }

long int k = 1;
  double b_time = 0;
  for(int j=0;j<n;j++)
  {
    b_time = b_time + 2 + burst_time[j];
    min = burst_time[k];

    for(int i=k;i<n;i++)
    {
      if((b_time >= arrival_time[i])&&(burst_time[i]<min))
      {
        temp = burst_time[k];
        burst_time[k] = burst_time[i];
        burst_time[i] = temp;

        temp = arrival_time[k];
        arrival_time[k] = arrival_time[i];
        arrival_time[i] = temp;

        temp = process[k];
        process[k] = process[i];
        process[i] = temp;
      }
    }
    k++;
  }

}
