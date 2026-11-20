#include <stdio.h>
#include <math.h>

int varcount;
int eqcount;

//a function to find determinant of any matrix
int det(int matrix_size, int matrix[matrix_size][matrix_size])
{
    //okay so first lets make a map and think what we gotta do
    //I'll first accept the inputs from the user and go element by element to get the cofactor in that spot
    //So 2 for loops to iterate thru every element 
    //then I'll delete that respective row and coloumn from the new matrix and apply determinant function on it 
    //this new matrix will be defined inside the function as it gotta be temporary
    //following this I'll multiply the element with the determinant of the new matrix and also multiply (-1)^(i+j)
    //ig this will return the output as determinant using recursion
    if (matrix_size==1)
    {
        return matrix[0][0];
    }
    if(matrix_size!=2)
    {
        int determinant=0;
        int temp_matrix[matrix_size-1][matrix_size-1];
        for (int i=0;i<matrix_size;i++)
        {
            for (int m=0;m<matrix_size;m++)
            {
                for (int n=0;n<matrix_size;n++)
                {
                    if (m<i&&n!=0)
                    {
                        temp_matrix[m][n-1]=matrix[m][n];
                    }
                    if (m>i&&n!=0)
                    {
                        temp_matrix[m-1][n-1]=matrix[m][n];
                    }
                }
            }
            //now we have deleted the row and coloumn from the matrix
            //the following code is to find number of elements in a matrix
            int size=sqrt(sizeof(temp_matrix)/sizeof(temp_matrix[0][0]));
            //THIS IS IT, THE REUCRSIVE STEP!!!!!!!!!!!
            if (i%2==0)
            determinant+=(matrix[i][0]*det(size, temp_matrix));
            else 
            determinant-=(matrix[i][0]*det(size, temp_matrix));
        }
        return determinant;
    }
    if (matrix_size==2)
    {
        return (matrix[0][0]*matrix[1][1]-matrix[1][0]*matrix[0][1]);
    }
}


int main()
{
    
 //get the info about the equations
    printf("\nWhat is the variable count of the series of equations you have: ");
    scanf("%d", &varcount);
    printf("\nHow many equations do you have: ");
    scanf("%d", &eqcount);
    while (eqcount!=varcount)
    {
        if (eqcount>varcount)
        {
            printf("\nSolution to this can be found, but I am a bad Coder ToT, so please enter only %d equations.",varcount);
        }
        else
        {
            printf("\nSolution to this can't be found");
        }
        printf("\nWhat is the variable count of the series of equations you have: ");
        scanf("%d", &varcount);
        printf("\nHow many equations do you have: ");
        scanf("%d", &eqcount);
    }
    printf("\nSolution to this can found!\n\n");

    int matrix1[varcount][varcount];
    int cons_mat[varcount][1];
    int final_ans_mat[varcount][1];

 //get input for the matrix
    for (int i=0;i<varcount;i++)
    {
        printf("\nEnter your %dth equation's coefficients in a particular order which has to be followed in other equations too:\n", i+1);
        for (int j=0;j<varcount;j++)
        {
            printf("\nEnter your %dth coefficient:",j+1);
            scanf("%d", &matrix1[i][j]);
        }
        printf("\nPlease enter your %dth equation's constant:", i+1);
        scanf("%d", &cons_mat[i][0]);
    }
 //check if the answers can be found
 //So we have to check if the determinant of the matrix is non-zero or not. If its zero then solutions are either infinite or they don't exist lol.
 //First we find the determinant...
    int dotorminant = det(varcount, matrix1);
    int cof[varcount][varcount];
    if (dotorminant==0)
    {
        printf("\nThe system doesn't have a unique solution. It might have infinitely many solutions or no solution.\n");
        return 0;
    }
    else
    {
        //now we need cofactor matrix
        for(int i=0;i<varcount;i++)
        {
            for(int j=0;j<varcount;j++)
            {
                int matrix2[varcount-1][varcount-1];
                int row = i;
                int coloumn = j;
                for(int m=0;m<varcount;m++)
                {
                    for(int n=0;n<varcount;n++)
                    {
                        if (m<row && n<coloumn)
                        {
                            matrix2[m][n] = matrix1[m][n];
                        }
                        if (m>row && n<coloumn)
                        {
                            matrix2[m-1][n] = matrix1[m][n];
                        }
                        if (m<row && n>coloumn)
                        {
                            matrix2[m][n-1] = matrix1[m][n];
                        }
                        if (m>row && n>coloumn)
                        {
                            matrix2[m-1][n-1] = matrix1[m][n];
                        }
                    }
                }
                if ((i+j)%2 == 0)
                    cof[i][j] = det(varcount-1, matrix2);
                else
                    cof[i][j] = -det(varcount-1, matrix2);
            }
        }
        //multiplying cofactor matrix with the constant matrix
        for(int i=0;i<varcount;i++)
        {
            final_ans_mat[i][0] = 0;
            for(int j=0;j<varcount;j++)
            {
                final_ans_mat[i][0]+=cof[j][i]*cons_mat[j][0];
            }
        }
        // now we print the answer
        for (int i=0;i<varcount;i++)
        {
            printf("\n\nYour %dth variable is %d\n",i+1,final_ans_mat[i][0]/dotorminant);
        }


    }
}
