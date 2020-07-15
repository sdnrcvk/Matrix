#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
		
	srand(time(NULL));
	int s,c;
	printf("Enter matrix row :");
	scanf(" %d",&s);
	printf("Enter matrix column :");
	scanf(" %d",&c);
	
	int matris1[s+2][c+2];
	int matris2[3][3];
	int matris3[s][c];
	int a,b;

	int i, j;
	for(i=0;i<s+2;i++){
		for(j=0;j<c+2;j++)
		{
			int upper = 255,lower = 0;
			if(i==0 || j==0 || i==s+1 || j==c+1)
				matris1[i][j]=0;
			else
				matris1[i][j]= (rand() % (upper - lower + 1)) + lower;
		}
	}
	
	printf("\n	   ImageMatrix	\n\n");
	for( i=0;i<s+2;i++){
		for(j=0;j<c+2;j++){
				
			printf("%5d", matris1[i][j]);
		}
		printf("\n");					
	}
	
	printf("\n\tV FILTER\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
		{
			printf("\n V[%dx%d]:",i,j);
			scanf(" %d",&matris2[i][j]);
		}
	}
	printf("\n	KernelMatrix	\n\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%5d", matris2[i][j]);
		}
		printf("\n");
	}
	
	printf("\n	OutputMatrix \n\n");
	for(i=1;i<s+1;i++){
		for(j=1;j<c+1;j++){
			matris3[i-1][j-1]=
			matris1[i-1][j-1]*matris2[0][0]+
			matris1[i-1][j]*matris2[0][1]+
			matris1[i-1][j+1]*matris2[0][2]+
			matris1[i][j-1]*matris2[1][0]+
			matris1[i][j]*matris2[1][1]+
			matris1[i][j+1]*matris2[1][2]+
			matris1[i+1][j-1]*matris2[2][0]+
			matris1[i+1][j]*matris2[2][1]+
			matris1[i+1][j+1]*matris2[2][2];
			
			printf("%5d",matris3[i-1][j-1]);
		
		}
		printf("\n");
	}
	
	return 0;
}
