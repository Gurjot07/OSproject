#include<stdio.h>
struct processes
{
    char name;
    int at,b,ct,wt,tt,priority,bt1;     
}process[20],process1[20];
void main()
{
	struct processes short_queue;
    int x,time=0,time1,time2,number,total=0,m,pf2=0,number2,s,posi,z,flag=0;
    float waiting_time=0,turnaround_times= 0;
    printf("\nEnter Total Number of Processes:\t");
    scanf("%d",&number);
    s=number;
    for(x=0;x<number;x++)
    { 
    	printf("\n Your Process name::");
    	fflush(stdin);
        scanf("%c",&process[x].name);
        printf("\n Details For Your processor %c::\n",process[x].name);
        printf("Enter The Arrival Time Of Process::");
        scanf("%d",&process[x].at);
        printf("\nEnter The Burst Time Of Process::");
        scanf("%d",&process[x].b);
        process[x].bt1=process[x].b;
        printf(" \nEnter The Priority Of Process::\t");
        scanf("%d",&process[x].priority);
    }
    printf("\nEnter Time Quantum for Fixed priority queue::");
    scanf("%d",&time1);
    printf("\nEnter Time Quantum for Round Robin queue::");
    scanf("%d",&time2);
    printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
    for(x=0;x<number;x++)
    {
        posi=x;
        for(z=x+1;z<number;z++)
        {
            if(process[z].at<process[posi].at)
                posi=z;
        }
        short_queue=process[x];
        process[x]=process[posi];
        process[posi]=short_queue;
    }
    time=process[0].at;
    for(x=0;number!=0;x++)
    {
    	while(total!=time1)
    	{
    		total++;
    		if(process[x].at<=time)
    		{
    			for(z=x+1;z<number;z++)
    			{
    				if(process[z].at==time&&process[z].priority<process[x].priority)
    				{
    					process1[pf2]=process[x];
						pf2++;
    					for(m=x;m<number-1;m++)
    						process[m]=process[m+1];
    					number--;
						total=0;
    					x=z-1;
    					z--;
					}
				}
			}
			time++;
			process[x].b--;
			if(process[x].b==0)
			{
				process[x].tt=time-process[x].at;
				process[x].wt=process[x].tt-process[x].bt1;
				printf("%c\t|\t%d\t|\t%d\n",process[x].name,process[x].tt,process[x].wt);
				waiting_time+=time-process[x].at-process[x].bt1; 
    			turnaround_times+=time-process[x].at;
    			for(m=x;m<number-1;m++)
    				process[m]=process[m+1];x--;
    			number--;
				total=time1;break;
			}
		}
		total=0;
		if(process[x].b!=0)
		{
			process1[pf2]=process[x];
			pf2++;
			for(m=x;m<number-1;m++)
    			process[m]=process[m+1];
    		number--;
		}
			if(x==number-1)
				x=-1;
	}
	
	number2=pf2;
	for(total=0;number2!=0;) 
	{ 
		if(process1[total].b<=time2&&process1[total].b>0) 
    	{ 
    		time+=process1[total].b; 
    		process1[total].b=0; 
    		flag=1; 
    	} 
    	else if(process1[total].b>time2) 
    	{ 
    		process1[total].b-=time2; 
    		time+=time2; 
    	} 
    	if(process1[total].b==0&&flag==1) 
    	{ 
    		number2--; 
    		process1[total].tt=time-process1[total].at;
			process1[total].wt=process1[total].tt-process1[total].bt1; 
			printf("%c\t|\t%d\t|\t%d\n",process1[total].name,process1[total].tt,process1[total].wt); 
    		turnaround_times+=time-process1[total].at; 
    		waiting_time+=time-process1[total].at-process1[total].bt1;
    		for(m=total;m<number2;m++)
    			process1[m]=process1[m+1];total--;
    		flag=0; 
    	} 

    	if(total==number2-1) 
      		total=0; 
    	else 
    		total++; 
    }
    printf("\nAverage Waiting Time is:: %f\n",waiting_time*1.0/s); 
    printf("\nAverage Turnaround Time is:: %f",turnaround_times*1.0/s);   
}
