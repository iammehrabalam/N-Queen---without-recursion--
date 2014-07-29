#include<stdio.h>
int check(int chess[100][100],int n);
int checkrow(int chess[100][100],int n,int row,int col);
int checkcolumn(int chess[100][100],int n,int row,int col);
int checkleftdia(int chess[100][100],int n,int row,int col);
int checkrightdia(int chess[100][100],int n,int row,int col);
void mat(int chess[100][100],int n)
{
	int i,j,k;
	for(i=0;i<n;i++)
		{
			printf("\t\t");
			for(k=0;k<n;k++)
			printf("----");
			printf("\n\t\t|");
		  for(j=0;j<n;j++)
			 printf(" %d |",chess[i][j]);
		     printf("\n");
		     
	    }
	      printf("\t\t");
	      for(k=0;k<n;k++)
			printf("----");
			printf("\n");
	      printf("\n");
}
int queen(int n)
{
	static int chess[100][100],statusrecord[2][100],i=0,j=0,point=0,l=0,status=0,f=0,count=0;
		for(i=0;i<n;)
		{
		  for(;j<n;j++)
		     { 
		     f=0;
			  if(checkrow(chess,n,i,j)==1)
			  {
			    if(checkcolumn(chess,n,i,j)==1)
			      {
			      	if(checkleftdia(chess,n,i,j)==1)
			      	{
			      		if(checkrightdia(chess,n,i,j)==1)
			      		{
			      			chess[i][j]=1;
			      			statusrecord[0][i]=i;
			      			statusrecord[1][i]=j;
			      			//printf("	statusrecord[1][i]=%d\n",statusrecord[1][0]);
			      			point++;
			      			f=1;
			      			break;
			      		}
			      	}
			      }
			  }
	        } 
	        if(i==n-1)
	        	{
	        		if(check(chess,n)==1)
	        			{count++;
	        			if(count<=2)
	        			{
	        				printf("\n\t\tSolution Number is %d\n\n",count);
	        			    mat(chess,n);
	        		    }
	        		    }
	        		--point;
	        		i=statusrecord[0][point];
	        	    j=statusrecord[1][point];
	        	    chess[i][j]=0;
	        	    j++;
	        	}
	        else if(f==0)
	        {
	        	--point;
	        	i=statusrecord[0][point];
	        	j=statusrecord[1][point];
	        	chess[i][j]=0;
	        	j++;
	        }
	        else
	        {
	        	j=0;
				i++;
	        }
	        if(statusrecord[1][0]==l)
	        {
	        	//printf("i=%d\n",statusrecord[1][0]);
	        	l++;
	        }
	        else
	        if(l==n&&statusrecord[1][0]+1<l)
	        break;
	    }
	return count;
}
int main()
{
	int n,total;
	printf("\t\t\tN-QUEEN PROBLEM\n\n");
	printf("Enter size of chess board (NxN):: ");
	scanf("%d",&n);
	total=queen(n);
	if(total>2)
	printf("\n\n\t\t\t\tand more....");
	printf("\n\n\tTotal possible solution is equal to %d",total);
	return 0;
}
int check(int chess[100][100],int n)//check N queen placed or not
{
	int i,j,count=0;
		
	for(i=0;i<n;i++)
	{	
		for(j=0;j<n;j++)
		{
			if(chess[i][j]==1)
			{
				count++;
				break;
			}
		}
	}
	if(count==n)
		return 1;
	return 0;
}
int checkrow(int chess[100][100],int n,int row,int col)
{
	int i;
	for(i=col-1;i>=0;i--)
		if(chess[row][i]==1)
			return 0;
	return 1;
}
int checkcolumn(int chess[100][100],int n,int row,int col)
{
	int i;
	for(i=row-1;i>=0;i--)
		if(chess[i][col]==1)
			return 0;
	return 1;
}
int checkleftdia(int chess[100][100],int n,int row,int col)
{
	int i,j;
	for(i=row-1,j=col+1;i>=0&&j<=n-1;i--,j++)
		if(chess[i][j]==1)
			return 0;
	return 1;
}
int checkrightdia(int chess[100][100],int n,int row,int col)
{
	int i,j;
	for(i=row-1,j=col-1;i>=0&&j>=0;i--,j--)
		if(chess[i][j]==1)
			return 0;
	return 1;
}
