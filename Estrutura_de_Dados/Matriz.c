/***********************************************************************************
    Author:      Lucas Pacheco.
    Description: Simple Matrix
    Date:        22/01/2021
************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define VET_BUFFER 10
#define MATRIX_BUFFER (VET_BUFFER * VET_BUFFER)
/*
    Was a little tricky to handle matrixes with pointers, but here it is.
*/

int    read_Matx   (int* mat, int* mWidth, int* mHeight);
int    write_Matx  (int* mat, int  mWidth, int  mHeight);
double matx_Average(int* mat, int  mWidth, int  mHeight);

int*   matx_Sum    (int* mat1, int* mat2, int mWidth, int mHeight);
int*   matx_Mul    (int* mat1, int* mat2, int width1, int height1, int width2, int height2);
int    freematrix  (int* mat);

int main()
{
    int mat[VET_BUFFER][VET_BUFFER];
    int mat2[VET_BUFFER][VET_BUFFER];
    int* matsum;
    int* matmul;

    int num_Elements; /* Number of elements */
    int width1, height1, width2, height2;   
    double average;


/*(1)*/
    printf("\nType your values to the FIRST matrix or a character to exit: \n");
    if (!(num_Elements = read_Matx(mat[0], &width1, &height1)))
    {
        fprintf(stderr, "Error: the number of elements cant be 0 and must be in buffer matrix range.\n");
        return 1;
    }

    printf("Your first matrix: ");
    write_Matx(mat[0], width1, height1);


/*(2)*/
    printf("\nType your values to the SECOND matrix or a character to exit: \n");
    if (!(num_Elements = read_Matx(mat2[0], &width2, &height2)))
    {
        fprintf(stderr, "Error: the number of elements cant be 0 and must be in buffer matrix range.\n");
        return 1;
    }

    printf("Your second matrix: ");
    write_Matx(mat2[0], width2, height2);

    if (width1 != width2 || height1 != height2)
    {
        printf("Error: incompatible matrixes for sum.\n");
    }
    else
    {
        matsum = matx_Sum(mat[0], mat2[0], width1, height1);

        printf("\n\nYour sum matrix: ");
        write_Matx(matsum, width1, height1);   
        printf("Average of %d elements of the sum matrix: %.3lf\n", num_Elements, matx_Average(matsum, width1, height1));
        freematrix(matsum);
    }
    

    if (width1 != height2)
        printf("Not multiplication frindly.\n");    
    else
    {
        printf("Multiplication:");
        matmul = matx_Mul(mat[0], mat2[0], width1, height1, width2, height2);  
        write_Matx(matmul, height1, height1);
        freematrix(matmul);
    }

    printf("All done!\n");




    return 0;
}


int read_Matx (int* mat, int* mWidth, int* mHeight)
{
    int i, totalNumbers = 0;
    int nLines = 0, nColumns = 0;
    int maxColumn; /* when you were done with a line, this will force the next lines to be the same size */
    int toComplete;    
    char choice, buf;

    do
    {
        i = 0;
        
        while(scanf("%d", mat++)) i++; 
        mat--;
        getchar();

        if (!nLines) /* the first row typed sets the column limit */
            maxColumn = i;

        nLines++;
        nColumns = i;
        
        totalNumbers += maxColumn;

        if (maxColumn > nColumns)
        {
            toComplete = maxColumn - nColumns; /* to complete a row */

            printf("Numbers missing to complete this row\n"
                   "Please type %d more: ", toComplete);

            for (i = 0; i < toComplete; i++)
                scanf("%d", mat++);     

        }
        else if (maxColumn < nColumns)
        {
            printf("Over row range! Max range: %d\n", maxColumn);
            return 0;
        }
         
        printf("\nEnter (J) to Jump line or (Q) to quit:\n");   
        scanf("%c%c", &buf, &choice);

        if (choice == 'j' || choice == 'J')
            printf("You must type %d values:\n", maxColumn);

    } while (!(choice == 'q' || choice == 'Q'));

    mat = NULL;
    
    if (totalNumbers > MATRIX_BUFFER - 1) /* Possibly -1 because if we complete all buffer NULL will take the last adress */
        totalNumbers = 0;

    *mWidth  = maxColumn;
    *mHeight = nLines;

    return totalNumbers;
}

int write_Matx(int* mat, int mWidth, int mHeight)
{   
    printf("\nMATRIX:  \n");
    for (int i = 0; i < mHeight; i++)
    {
        printf("|");
            for (int j = 0; j < mWidth; j++)
            {
                printf("%3d", *(mat++)); /* To print the matrixes elements */

                if (j < mWidth - 1) /* to print the correct  number of spaces */
                    printf(" ");
            }
        printf("|\n");
    }
}

double matx_Average(int* mat, int mWidth, int mHeight)
{
    double sum = 0.0;
    for (int i = 0; i < mWidth * mHeight; i++)
        sum += (double)*(mat++);
    
    return sum / (double)(mWidth * mHeight);
}

int* matx_Sum(int* mat1, int* mat2, int mWidth, int mHeight)
{
    int* matrix_Sum = (int *)malloc(sizeof(int) * (mWidth * mHeight));
    
    for (int i = 0; i < mWidth * mHeight; i++)
        matrix_Sum[i] = mat1[i] + mat2[i];
    
    return matrix_Sum;
}

int* matx_Mul(int* mat1, int* mat2, int width1, int height1, int width2, int height2)
{
    int* matrix_Mul = (int *)malloc(sizeof(int) * (width2 * height1));
    int i, j, k;   
    i = j = k = 0;

    for (int i = 0; i < width2; i++)
    {
        for (j = 0; j < width2; j++) 
        {
            matrix_Mul[i * width2 + j] = 0;
            
            for (int k = 0; k < width1; k++)
               matrix_Mul[i * width2 + j] += mat1[i * width1 + k] * mat2[j + width2 * k]; 

        }
    }

    return matrix_Mul;
}

int freematrix(int* mat)
{
    free(mat);
}