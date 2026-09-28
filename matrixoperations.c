#include<stdio.h>
void AddMatrix(int A[10][10],int B[10][10],int C[10][10],int m,int n)
    {
        int i,j;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                C[i][j]=A[i][j]+B[i][j];
            }
        }
    }
void subtractMatrix(int A[10][10],int B[10][10],int C[10][10],int m,int n)
    {
        int i,j;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                C[i][j]=A[i][j]-B[i][j];
            }
        }
    }
void multiplyMatrix(int A[10][10],int B[10][10],int C[10][10],int m,int n,int p)
    {
        int i,j,k;
        for(i=0;i<m;i++)
        {
            for(j=0;j<p;j++)
            {
                C[i][j]=0;
                for(k=0;k<n;k++)
                {
                    C[i][j]+=A[i][k]*B[k][j];
                }
            }
        }
    }
void transposematrix(int A[10][10],int C[10][10],int m,int n)
    {
        int i,j;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                C[j][i]=A[i][j];
            }
        }
    }
void DisplayMatrix(int C[10][10],int m,int n)
    {
        int i,j;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                printf("%d\t",C[i][j]);
            }
            printf("\n");
        }
    }
void sparseMatrix(int A[10][10],int m,int n)
{
    int i,j,count=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(A[i][j]!=0)
            {
                count++;
            }
        }
    }
    int sparse[count][3],k=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(A[i][j]!=0)
            {
                sparse[k][0]=i;
                sparse[k][1]=j;
                sparse[k][2]=A[i][j];
                k++;
            }
        }
    }
    printf("Sparse matrix representation:\n");
    for(i=0;i<count;i++)
    {
        printf("%d %d %d\n",sparse[i][0],sparse[i][1],sparse[i][2]);
    }
}

int main(){
    int A[10][10],B[10][10],C[10][10],i,j,m,n;
     printf("Enter the size of matrix A: ");
     scanf("%d%d",&m,&n);
     printf("Enter the elements of matrix A:");
     for(i=0;i<m;i++)
     {
        for(j=0;j<n;j++)
        {
            scanf("%d",&A[i][j]);
        }
     }
    printf("Enter the size of Matrix B:");
    scanf("%d%d",&m,&n);
    printf("Enter the elements of matrix B:");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&B[i][j]);   
        }
    }

int x = 1;
while(x != 7){
printf("Enter 1 for addition :\n""Enter 2 for subtraction :\n""Enter 3 for display :\n""Enter 4 for multiplication :\n""Enter 5 for transpose :\n""Enter 6 for sparse matrix :\n""Enter 7 for exit :\n""Your choice : ");
scanf("%d",&x);
switch (x)
{
    case 1:
        AddMatrix(A, B, C, m, n);
        DisplayMatrix(C, m, n); // Calling display here so you can actually see the result
        break;
        
    case 2:
        subtractMatrix(A, B, C, m, n);
        DisplayMatrix(C, m, n);
        break;
                         
    case 3:
        DisplayMatrix(C, m, n);
        break;
    case 4:
        multiplyMatrix(A, B, C, m, n, n); // Assuming square matrices for multiplication
        DisplayMatrix(C, m, n);
        break;
    case 5:
        transposematrix(A, C, m, n);
        DisplayMatrix(C, n, m); // Note the dimensions are swapped for transpose
        break;
    case 6:
        sparseMatrix(A, m, n);
        break;
    case 7:
        printf("Exiting the program.\n");
        break;
        
    default: // 'default' is better than 'case 5' because it catches ANY invalid number entered
        printf("Invalid input\n");
        break;
}
}


     
return 0;
    }