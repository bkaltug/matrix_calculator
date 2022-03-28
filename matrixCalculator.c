#include<stdio.h>

void matAdd(int nRow, int nCol, double *A, double *B){
	
	double sumMatrix[nRow][nCol];
	
	int x=0;
		for(int i=0;i<nRow;i++){
				for(int j=0;j<nCol;j++){
					
				sumMatrix[i][j]=(*(B+x))+(*(A+x));
				x++;
				}
				
			}
			
				for(int i=0;i<nRow;i++){
				for(int j=0;j<nCol;j++){
					
				printf("%.2lf ",sumMatrix[i][j]);
				}
				
				printf("\n");
			}
	
}


void matMul(int nRow1,int nCol1, int nRow2, int nCol2,double A[nRow1][nCol1], double B[nRow2][nCol2]){
	
	double mulMatrix[nRow1][nCol2];
	int  a=0,b=0,x=0,y=0,z=0;
	printf("\n");
	
	for(int i=0;i<nRow1;i++){
		for(int j=0;j<nCol2;j++){
				mulMatrix[i][j]=0;
			
		}
		
	}
	
	
	
	while(1){
		
		while(x<nCol1){
				
				mulMatrix[a][b] += (A[z][x])*(B[x][y]);
				x++;
			}
			
			x=0;
			y++;
			
			
			if(b==nCol2-1 && a==nRow1-1){
				
		for(int i=0;i<nRow1;i++){
		for(int j=0;j<nCol2;j++){
			printf("%.2lf ",mulMatrix[i][j]);
			}
		
		printf("\n");
	
		}
			break;
			}
				
				else if(b==nCol2-1 && a<nRow1-1){
				b=0;
				a++;
				z++;
				y=0;
			}
			
			else if (b != nCol2-1){
				b++;
			}
		}
	}
	
	


void matTra (int nRow, int nCol, double A[nRow][nCol]){
	
	double B[nRow][nCol],C[nCol][nRow];
	
	printf("\nMatrix before transpose operation: \n");
	
				for(int i=0;i<nRow;i++){
		for(int j=0;j<nCol;j++){
			
		printf("%.2lf ",A[i][j]);
		}
		printf("\n");
	}
	
	
	if(nRow == nCol){
		
			
			
			for(int i=0;i<nRow;i++){
		for(int j=0;j<nCol;j++){
			
			B[i][j] = A[j][i];
		}
		
	}
	
		for(int i=0;i<nRow;i++){
			for(int j=0;j<nCol;j++){
			
		A[i][j]=B[i][j];
		}
		
	}
	
		printf("\nMatrix after transpose operation: \n");
	
	for(int i=0;i<nRow;i++){
		for(int j=0;j<nCol;j++){
			
		printf("%.2lf ",A[i][j]);
		}
		printf("\n");
	}
	}
	
	else{
	
		
			for(int i=0;i<nRow;i++){
		for(int j=0;j<nCol;j++){
			
			C[j][i] = A[i][j];
		}
		
	}
	
	printf("\nMatrix after transpose operation: \n");
	for(int i=0;i<nCol;i++){
		for(int j=0;j<nRow;j++){
			
		printf("%.2lf ",C[i][j]);
		}
		printf("\n");
	}
	
}
}


int main(void){
	
	int row1,column1,selection;
	
	printf("Enter the number of rows for the first operand matrix: ");
	scanf("%d",&row1);

	printf("\nEnter the number of columns for the first operand matrix:  ");
	scanf("%d",&column1);

	double matrix1[row1][column1];
	
	printf("\nPlease choose the matrix operation you want to do: ");
	printf("\n1. Matrix Addition");
	printf("\n2. Matrix Multiplication");
	printf("\n3. Matrix Transpose\n");
	scanf("%d",&selection);
	
	//undetermined selection
	if(selection>3 || selection <1 ){
		
		printf("\nInvalid input!");
	}
	
	//addition
	else if(selection == 1){
		
		
		double matrix2[row1][column1];
		
		
			printf("\nMatrix addition operation selected.");
			printf("\nCreate the content of the first operand matrix: ");
				
			for(int i=0;i<row1;i++){
				for(int j=0;j<column1;j++){
					
					scanf("%lf",&matrix1[i][j]);
				}
				
			}
			
				printf("\nCreate the content of the second operand matrix: ");
				
			for(int i=0;i<row1;i++){
				for(int j=0;j<column1;j++){
					
					scanf("%lf",&matrix2[i][j]);
				}
				
			}
			
			matAdd(row1,column1,matrix1,matrix2);
		
	}
	
	//multiplication
	else if(selection == 2){
		
		int row2,column2;
		
	printf("\nMatrix multiplication operation selected. ");
	printf("\nPlease enter the number of rows for the second operand matrix: ");
	scanf("%d",&row2);
	
	if(row2 != column1 ){
		printf("\nRow number of the second matrix must match the column number of the first matrix.");
	}
	else{
		
		printf("\nPlease enter number of columns for the second operand matrix: ");
		scanf("%d",&column2);
		
		double matrix1[row1][column1],matrix2[row2][column2];
		
		printf("\nCreate the content of the first operand matrix:\n");
		for(int i=0;i<row1;i++){
			for(int j=0;j<column1;j++){
				
				scanf("%lf",&matrix1[i][j]);
			}
		}
		
		printf("\nCreate the content of the second operand matrix:\n");
		for(int i=0;i<row2;i++){
			for(int j=0;j<column2;j++){
				
				scanf("%lf",&matrix2[i][j]);
			}
		}
		
		
	matMul(row1,column1,row2,column2,matrix1,matrix2);
		
	}
	
	
	}
	
		//transpose -- done
	else if(selection == 3){
	
	printf("\nMatrix transpose operation selected.");
	printf("\nCreate the content of the matrix: ");
	
	for(int i=0;i<row1;i++){
		for(int j=0;j<column1;j++){
			
			scanf("%lf",&matrix1[i][j]);
		}
	}
	
		matTra(row1,column1,matrix1);
	}
	


}
