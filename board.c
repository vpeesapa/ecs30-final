#include<stdio.h>
#include<stdlib.h>
#include"board.h"
char** createBoard(int num_rows,int num_cols)
{
 /*
   Function to allocate memory for the board
   @num_rows:The number of rows in the board
   @num_cols:The number of columns in the board
   @return:The board with memory allocated to it
 */
 int i,j;
 char** board=(char **)malloc(num_rows*sizeof(char *));
 for(i=0;i<num_rows;i++)
    {
     board[i]=(char *)malloc(num_cols*sizeof(char));
     for(j=0;j<num_cols;j++)
        {
         board[i][j]='*';
        }
    }
 return board;
}//end of function
void printBoard(char** board,int num_rows,int num_cols)
{
 /*
   Function to print the board
   @board:The board
   @num_rows:The number of rows in the board
   @num_cols:The number of columns in the board
   @return:None(Since it has 'void' as its return type)
 */
 int i,j;
 for(i=num_rows-1;i>=0;i--)
    {
     if(i<10)
       {
        printf(" %d ",i);
       }
     else
     {
      printf("%d ",i);
     }
     for(j=0;j<num_cols;j++)
        {
         if(j>=10)
           {
            printf(" %c  ",board[i][j]);
           }
         else
         {
          printf(" %c ",board[i][j]);
         }
        }
     printf("\n");
    }
 printf("   ");
 for(j=0;j<num_cols;j++)
    {
     printf(" %d ",j);
    }
 printf("\n");
}//end of function
void destroyBoard(char** board,int num_rows)
{
 /*
   Function to deallocate the memory assigned for the board
   @board:The board
   @num_rows:The number of rows in the board
   @retrun:None(Since it has 'void' as its return type)
 */
 int i;
 for(i=0;i<num_rows;i++)
    {
     free(board[i]);
    }
 free(board);
}//end of function
