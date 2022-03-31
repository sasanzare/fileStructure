
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct request{
	int request_track_number;
	bool status;
};

/*
	Status clear
*/
void clear(struct request *req,int no_of_requests){
  for (int i = 0 ;i<no_of_requests;i++){
    req[i].status=false;
  }
}

/*
	First Come First Serve (FCFS)
*/
void FCFS(struct request req[],int no_of_requests,int initial_head){
    int i=0,seek_time=0;
    printf("\n\r\n\r=============  Disk Scheduling First Come First Serve(FCFS)  =============\n\r\n\r%d ",initial_head );
	for(;i<no_of_requests;i++){
        printf("-> %d ", req[i].request_track_number);
		seek_time += abs(req[i].request_track_number - initial_head);
		initial_head = req[i].request_track_number;
	}
	printf("\n\r\n\rSeek Time: %d\n\r", seek_time);
}

/*
	Shortest Seek Time First (SSTF)
*/
void SSTF(struct request req[],int no_of_requests,int initial_head){
	int seek_time=0,i;
	printf("\n\r\n\r=============  Disk Scheduling Shortest Seek Time First(SSTF)  =============\n\r\n\r%d ",initial_head );
	clear(req,no_of_requests);
	int n = no_of_requests;
	while(n)
	{
		int min = 1e9;
		int min_track_number, position;
		for(i=0;i<no_of_requests;i++)
		{
			if(abs(initial_head - req[i].request_track_number) < min && req[i].status == false)
			{
				min = abs(initial_head - req[i].request_track_number);
				min_track_number = req[i].request_track_number;
				position = i;
			}
		}
		initial_head = req[position].request_track_number;
		req[position].status = true;
		printf("-> %d ",min_track_number);
		seek_time += min;
		n--;
	}

	printf("\n\r\n\rSeek Time: %d\n\r", seek_time);


}

/*
	Scan
*/
void SCAN(struct request req[],int no_of_requests,int initial_head,int limit,int choice){
  	int seek_time=0,i,j;
	printf("\n\r\n\r=============  Disk Scheduling SCAN  =============\n\r\n\r%d ",initial_head );
	clear(req,no_of_requests);
	if(choice == 1)
	{
		for(i=initial_head;i<limit;i++)
		{
			for(j=0;j<no_of_requests;j++)
			{
				if(req[j].request_track_number == i && req[j].status == false)
				{
					printf("-> %d ", req[j].request_track_number);
					req[j].status = true;
					seek_time += abs(req[j].request_track_number - initial_head);
					initial_head = req[j].request_track_number;
				}
			}
		}
		printf("-> %d ", limit-1);
		seek_time += abs(limit-1 - initial_head);
		initial_head = limit-1;
		for(i=initial_head;i>=0;i--)
		{
			for(j=0;j<no_of_requests;j++)
			{
				if(req[j].request_track_number == i && req[j].status == false)
				{
					printf("-> %d ", req[j].request_track_number);
					req[j].status = true;
					seek_time += abs(req[j].request_track_number - initial_head);
					initial_head = req[j].request_track_number;
				}
			}
		}
		seek_time += abs(initial_head - 0);
		printf("0 \n");
	}
	else if(choice == 2)
	{
		for(i=initial_head;i>=0;i--)
		{
			for(j=0;j<no_of_requests;j++)
			{
				if(req[j].request_track_number == i && req[j].status == false)
				{
					printf("-> %d ", req[j].request_track_number);
					req[j].status = true;
					seek_time += abs(req[j].request_track_number - initial_head);
					initial_head = req[j].request_track_number;
				}
			}
		}
		printf("-> %d ", 0);
		seek_time += abs(0 - initial_head);
		initial_head = 0;
		for(i=initial_head;i<limit;i++)
		{
			for(j=0;j<no_of_requests;j++)
			{
				if(req[j].request_track_number == i && req[j].status == false)
				{
					printf("-> %d ", req[j].request_track_number);
					req[j].status = true;
					seek_time += abs(req[j].request_track_number - initial_head);
					initial_head = req[j].request_track_number;
				}
			}
		}
		seek_time += abs(limit-1 - initial_head );
		printf("-> %d ", limit-1);

	}
	printf("\n\r\n\rSeek Time: %d\n\r", seek_time);
}

/*
	C-Scan
*/
void C_SCAN(struct request req[],int no_of_requests,int initial_head,int limit,int choice){
  	int seek_time=0,i,j;
	printf("\n\r\n\r=============  Disk Scheduling C-SCAN  =============\n\r\n\r%d ",initial_head );
	clear(req,no_of_requests);
	int cp_initial_head = initial_head;
	if(choice == 1)
	{
		for(i=initial_head;i<limit;i++)
		{
			for(j=0;j<no_of_requests;j++)
			{
				if(req[j].request_track_number == i && req[j].status == false)
				{
					printf("-> %d ", req[j].request_track_number);
					req[j].status = true;
					seek_time += abs(req[j].request_track_number - initial_head);
					initial_head = req[j].request_track_number;
				}
			}
		}
		printf("-> %d  \n", limit-1);
		seek_time += abs(limit-1 - initial_head);
		initial_head = 0;
		for(i=0;i<cp_initial_head;i++)
		{
			for(j=0;j<no_of_requests;j++)
			{
				if(req[j].request_track_number == i && req[j].status == false)
				{
					printf("-> %d ", req[j].request_track_number);
					req[j].status = true;
					seek_time += abs(req[j].request_track_number - initial_head);
					initial_head = req[j].request_track_number;
				}
			}
		}
	}
	else if(choice == 2)
	{
		for(i=initial_head;i>=0;i--)
		{
			for(j=0;j<no_of_requests;j++)
			{
				if(req[j].request_track_number == i && req[j].status == false)
				{
					printf("-> %d ", req[j].request_track_number);
					req[j].status = true;
					seek_time += abs(req[j].request_track_number - initial_head);
					initial_head = req[j].request_track_number;
				}
			}
		}
		printf("-> %d ", 0 );
		seek_time += abs(initial_head - 0);
		initial_head = limit-1;
		for(i=limit;i>cp_initial_head;i--)
		{
			for(j=0;j<no_of_requests;j++)
			{
				if(req[j].request_track_number == i && req[j].status == false)
				{
					printf("-> %d ", req[j].request_track_number);
					req[j].status = true;
					seek_time += abs(req[j].request_track_number - initial_head);
					initial_head = req[j].request_track_number;
				}
			}
		}
	}
	printf("\n\r\n\rSeek Time : %d\n\r", seek_time);

}

/*
	LOOK
*/
void LOOK(struct request req[],int no_of_requests,int initial_head,int limit,int choice){
  	int seek_time=0,i,j;
	printf("\n\r\n\r=============  Disk Scheduling LOOK  =============\n\r\n\r%d ",initial_head );
	clear(req,no_of_requests);
	if(choice == 1)
	{
		for(i=initial_head;i<limit;i++)
		{
			for(j=0;j<no_of_requests;j++)
			{
				if(req[j].request_track_number == i && req[j].status == false)
				{
					printf("-> %d ", req[j].request_track_number);
					req[j].status = true;
					seek_time += abs(req[j].request_track_number - initial_head);
					initial_head = req[j].request_track_number;
				}
			}
		}
		for(i=initial_head;i>=0;i--)
		{
			for(j=0;j<no_of_requests;j++)
			{
				if(req[j].request_track_number == i && req[j].status == false)
				{
					printf("-> %d ", req[j].request_track_number);
					req[j].status = true;
					seek_time += abs(req[j].request_track_number - initial_head);
					initial_head = req[j].request_track_number;
				}
			}
		}
	}
	else if(choice == 2)
	{
		for(i=initial_head;i>=0;i--)
		{
			for(j=0;j<no_of_requests;j++)
			{
				if(req[j].request_track_number == i && req[j].status == false)
				{
					printf("-> %d ", req[j].request_track_number);
					req[j].status = true;
					seek_time += abs(req[j].request_track_number - initial_head);
					initial_head = req[j].request_track_number;
				}
			}
		}
		for(i=initial_head;i<limit;i++)
		{
			for(j=0;j<no_of_requests;j++)
			{
				if(req[j].request_track_number == i && req[j].status == false)
				{
					printf("-> %d ", req[j].request_track_number);
					req[j].status = true;
					seek_time += abs(req[j].request_track_number - initial_head);
					initial_head = req[j].request_track_number;
				}
			}
		}
	}
	printf("\n\r\n\rSeek Time : %d\n\r", seek_time);

}

/*
	C-LOOK
*/
void C_LOOK(struct request req[],int no_of_requests,int initial_head,int limit,int choice){
  	int seek_time=0,i,j;
	printf("\n\r\n\r=============  Disk Scheduling C-LOOK  =============\n\r\n\r%d ",initial_head );
	clear(req,no_of_requests);
	int cp_initial_head = initial_head;
	if(choice == 1)
	{
		for(i=initial_head;i<limit;i++)
		{
			for(j=0;j<no_of_requests;j++)
			{
				if(req[j].request_track_number == i && req[j].status == false)
				{
					printf("-> %d ", req[j].request_track_number);
					req[j].status = true;
					seek_time += abs(req[j].request_track_number - initial_head);
					initial_head = req[j].request_track_number;
				}
			}
		}
		initial_head = 0;
		for(i=0;i<cp_initial_head;i++)
		{
			for(j=0;j<no_of_requests;j++)
			{
				if(req[j].request_track_number == i && req[j].status == false)
				{
					printf("-> %d ", req[j].request_track_number);
					req[j].status = true;
					seek_time += abs(req[j].request_track_number - initial_head);
					initial_head = req[j].request_track_number;
				}
			}
		}
	}
	else if(choice == 2)
	{
		for(i=initial_head;i>=0;i--)
		{
			for(j=0;j<no_of_requests;j++)
			{
				if(req[j].request_track_number == i && req[j].status == false)
				{
					printf("-> %d ", req[j].request_track_number);
					req[j].status = true;
					seek_time += abs(req[j].request_track_number - initial_head);
					initial_head = req[j].request_track_number;
				}
			}
		}
		initial_head = limit-1;
		for(i=limit;i>cp_initial_head;i--)
		{
			for(j=0;j<no_of_requests;j++)
			{
				if(req[j].request_track_number == i && req[j].status == false)
				{
					printf("-> %d ", req[j].request_track_number);
					req[j].status = true;
					seek_time += abs(req[j].request_track_number - initial_head);
					initial_head = req[j].request_track_number;
				}
			}
		}
	}
	printf("\n\r\n\rSeek Time : %d\n\r", seek_time);
}

/*
 main
*/
int main(){
	int i=0,no_of_requests,initial_head,limit,previous_head,choice;
	printf("\n\r===========  HOMEWORK 2 CREATED BY SASAN ZARE  ===========\n\r\n\rPlease Enter The Number Of Requests : ");
	scanf("%d",&no_of_requests);
    struct request req[no_of_requests];
	printf("\n\rPlease Enter The Cylinder Size : ");
	scanf("%d",&limit);
	printf("\n\rPlease Enter The Previous Position Of R/W head (Number >= 0 && Number < %d) : ",limit);
	scanf("%d",&previous_head);
    printf("\n\rPlease Enter The Current Position Of R/W Head (Number >= 0 && Number < %d) : ",limit);
	scanf("%d",&initial_head);
    printf("\n\r");
	for (; i < no_of_requests; ++i){
        printf("[%d]Please Enter The Request (Number >= 0 && Number < %d) : ",i+1,limit);
        scanf("%d",&req[i].request_track_number);
        req[i].status = false;
	}
	choice = (previous_head - initial_head > 0 )?2:1;
	FCFS( req,no_of_requests,initial_head);
	SSTF( req,no_of_requests,initial_head);
	SCAN( req,no_of_requests,initial_head,limit,choice);
	C_SCAN( req,no_of_requests,initial_head,limit,choice);
	LOOK( req,no_of_requests,initial_head,limit,choice);
	C_LOOK( req,no_of_requests,initial_head,limit,choice);
	printf("\n\r\n\r===========  Have a Good Time ===========\n\r");
	return 0;
}
