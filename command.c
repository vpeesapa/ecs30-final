#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"command.h"
void print_help()
{
 /*
   Function to print all the help information
   @return:None(Since it has 'void' as its return type)
 */
 printf("Commands:\n");
 printf("Help: h\n");
 printf("Quit: q\n");
 printf("Draw line: w row_start col_start row_end col_end\n");
 printf("Resize: r num_rows num_cols\n");
 printf("Add row or column: a [r | c] pos\n");
 printf("Delete row or column: d [r | c] pos\n");
 printf("Erase: e row col\n");
 printf("Save: s file_name\n");
 printf("Load: l file_name\n");
}//end of function
void fillHorizontal(char** board,int row,int start_y,int end_y)
{
 /*
   Function to fill a row
   @board:The board
   @row:The row which needs to modified
   @start_y:The starting value in the vertical direction
   @end_y:The ending value in the ertical direction
   @return:None(Since it has 'void' as its return type)
 */
 int j;
 if(start_y<end_y)
   {
    for(j=start_y;j<=end_y;j++)
       {
        if(board[row][j]=='*')
          {
           board[row][j]='-';
          }
        else if(board[row][j]!='*'&&board[row][j]!='-')
               {
                board[row][j]='+';
               }
       }
   }
 else
 {
  for(j=start_y;j>=end_y;j--)
       {
        if(board[row][j]=='*')
          {
           board[row][j]='-';
          }
        else if(board[row][j]!='*'&&board[row][j]!='-')
               {
                board[row][j]='+';
               }
       }
 }
}//end of function
void fillVertical(char** board,int col,int start_x,int end_x)
{
 /*
   Function to fill a column
   @board:The board
   @col:The column that needs to be modified
   @start_x:The starting value in the horizontal direction
   @end_x:The ending value in the vertical direction
   @return:None(Since it has 'void' as its return type)
 */
 int i;
 if(start_x<end_x)
   {
    for(i=start_x;i<=end_x;i++)
       {
        if(board[i][col]=='*')
          {
           board[i][col]='|';
          }
        else if(board[i][col]!='*'&&board[i][col]!='|')
               {
                board[i][col]='+';
               }
       }
   }
 else
 {
  for(i=start_x;i>=end_x;i--)
       {
        if(board[i][col]=='*')
          {
           board[i][col]='|';
          }
        else if(board[i][col]!='*'&&board[i][col]!='|')
               {
                board[i][col]='+';
               }
       }
 }
}//end of function
void fillLeftDiagonal(char** board,int start_x,int start_y,int end_x,int end_y)
{
 /*
   Function to fill the left primary diagonal
   @board:The board
   @start_x:The starting value in the horizontal direction
   @start_y:The starting value in the vertical direction
   @end_x:The ending value in the horizontal direction
   @end_y:The ending value in the vertical direction
   @return:None(Since it has 'void' as its return type)
 */
 int i,j;
 if(board[start_x][start_y]=='*')
   {
    board[start_x][start_y]='/';
   }
 else if(board[start_x][start_y]!='*'&&board[start_x][start_y]!='/')
        {
         board[start_x][start_y]='+';
        }
 if(start_x<end_x&&start_y<end_y)
   {
    for(i=start_x+1;i<=end_x;i++)
       {
        for(j=start_y+1;j<=end_y;j++)
           {
            if((j-start_y)==(i-start_x))
              {
               if(board[i][j]=='*')
                 {
                  board[i][j]='/';
                 }
               else if(board[i][j]!='*'&&board[i][j]!='/')
                      {
                       board[i][j]='+';
                      }
              }
           }
       }
   }
 else if(start_x>end_x&&start_y<end_y)
        {
         for(i=start_x-1;i>=end_x;i--)
            {
             for(j=start_y+1;j<=end_y;j++)
                {
                 if((j-start_y)==(i-start_x))
                   {
                    if(board[i][j]=='*')
                      {
                       board[i][j]='/';
                      }
                    else if(board[i][j]!='*'&&board[i][j]!='/')
                           {
                            board[i][j]='+';
                           }
                   }
                }
            }
        }
 else if(start_x<end_x&&start_y>end_y)
        {
         for(i=start_x+1;i<=end_x;i++)
            {
             for(j=start_y-1;j>=end_y;j--)
                {
                 if((j-start_y)==(i-start_x))
                   {
                    if(board[i][j]=='*')
                      {
                       board[i][j]='/';
                      }
                    else if(board[i][j]!='*'&&board[i][j]!='/')
                           {
                            board[i][j]='+';
                           }
                   }
                }
            }
        }
 else if(start_x>end_x&&start_y>end_y)
        {
         for(i=start_x-1;i>=end_x;i--)
            {
             for(j=start_y-1;j>=end_y;j--)
                {
                 if((j-start_y)==(i-start_x))
                   {
                    if(board[i][j]=='*')
                      {
                       board[i][j]='/';
                      }
                    else if(board[i][j]!='*'&&board[i][j]!='/')
                           {
                            board[i][j]='+';
                           }
                   }
                }
            }
        }
}//end of function
void fillRightDiagonal(char** board,int start_x,int start_y,int end_x,int end_y)
{
 /*  
   Function to fill the right primary diagonal
   @board:The board
   @start_x:The starting value in the horizontal direction
   @start_y:The starting value in the vertical direction
   @end_x:The ending value in the horizontal direction
   @end_y:The ending value in the vertical direction
   @return:None(Since it has 'void' as its return type)
 */
 int i,j;
 if(board[start_x][start_y]=='*')
   {
    board[start_x][start_y]='\\';
   }
 else if(board[start_x][start_y]!='*'&&board[start_x][start_y]!='\\')
        {
         board[start_x][start_y]='+';
        }
 if(start_x<end_x&&start_y<end_y)
   {
    for(i=start_x+1;i<=end_x;i++)
       {
        for(j=start_y+1;j<=end_y;j++)
           {
            if((j-start_y)==(start_x-i))
              {
               if(board[i][j]=='*')
                 {
                  board[i][j]='\\';
                 }
               else if(board[i][j]!='*'&&board[i][j]!='\\')
                      {
                       board[i][j]='+';
                      }
              }
           }
       }
   }
 else if(start_x>end_x&&start_y<end_y)
        {
         for(i=start_x-1;i>=end_x;i--)
            {
             for(j=start_y+1;j<=end_y;j++)
                {
                 if((j-start_y)==(start_x-i))
                   {
                    if(board[i][j]=='*')
                      {
                       board[i][j]='\\';
                      }
                    else if(board[i][j]!='*'&&board[i][j]!='\\')
                           {
                            board[i][j]='+';
                           }
                   }
                }
            }
        }
 else if(start_x<end_x&&start_y>end_y)
        {
         for(i=start_x+1;i<=end_x;i++)
            {
             for(j=start_y-1;j>=end_y;j--)
                {
                 if((j-start_y)==(start_x-i))
                   {
                    if(board[i][j]=='*')
                      {
                       board[i][j]='\\';
                      }
                    else if(board[i][j]!='*'&&board[i][j]!='\\')
                           {
                            board[i][j]='+';
                           }
                   }
                }
            }
        }
 else if(start_x>end_x&&start_y>end_y)
        {
         for(i=start_x-1;i>=end_x;i--)
            {
             for(j=start_y-1;j>=end_y;j--)
                {
                 if((j-start_y)==(start_x-i))
                   {
                    if(board[i][j]=='*')
                      {
                       board[i][j]='\\';
                      }
                    else if(board[i][j]!='*'&&board[i][j]!='\\')
                           {
                            board[i][j]='+';
                           }
                   }
                }
            }
        }
}//end of function
void fillCanvas(char** board,int num_rows,int num_cols,int start_x,int start_y,int end_x,int end_y)
{
 /*
   Function to fill the canvas at their appropriate spots
   @board:The board
   @num_rows:The number of rows in the board
   @num_cols:The number of columns in the board
   @start_x:The starting value in the horizontal direction
   @start_y:The starting value in the vertical direction
   @end_x:The ending value in the horizontal direction
   @end_y:The ending value in the vertical direction
   @return:None(Since it has 'void' as its return type)
 */
 if(start_x==end_x)//if the starting and ending points are in the same row
   {
    fillHorizontal(board,start_x,start_y,end_y);
   }
 else if(start_y==end_y)//if the starting and ending points are in the same column
        {
         fillVertical(board,start_y,start_x,end_x);
        }
 else if((start_y-end_y)/(start_x-end_x)==1)//if the starting and ending points are in the same diagonal
        {
         fillLeftDiagonal(board,start_x,start_y,end_x,end_y);
        }
 else if((start_y-end_y)/(start_x-end_x)==-1)
        {
         fillRightDiagonal(board,start_x,start_y,end_x,end_y);
        }
 else
 {
  printf("Cannot draw the line as it is not straight.\n");
 }
}//end of function
void erasePoint(char** board,int row,int col)
{
 /*
   Function to erase a point on the canvas
   @board:The board
   @row:The row in the point exists
   @col:The column in which the point exists
   @return:None(Since it has 'void' as its return type)
 */
 if(board[row][col]!='*')
   {
    board[row][col]='*';
   }
}//end of function
void resizeBoard(char*** board,int* num_rows,int* num_cols,int row,int col)
{
 /*
   Function to resize the board
   @board:The board
   @num_rows:The number of rows in the board
   @num_cols:The number of columns in the board
   @row:The number of rows the board should be resized to
   @col:The number of columns the board should be resized to
   @return:None(Since it has 'void' as its return type)
 */
 int i,j;
 if(col!=*num_cols)
   {
    for(i=0;i<*num_rows;i++)
       {
        (*board)[i]=(char *)realloc((*board)[i],col*sizeof(char));
        if(col>*num_cols)
          {
           for(j=*num_cols;j<col;j++)
              {
               (*board)[i][j]='*';
              }
          }
       }
   }
 if(row<*num_rows)
   {
    for(i=row;i<*num_rows;i++)
       {
        free((*board)[i]);
       }
    *board=(char **)realloc(*board,row*sizeof(char *));
   }
 else if(row>*num_rows)
        {
         *board=(char **)realloc(*board,row*sizeof(char *));
         for(i=*num_rows;i<row;i++)
            {
             (*board)[i]=(char *)malloc(col*sizeof(char));
             for(j=0;j<col;j++)
                {
                 (*board)[i][j]='*';
                }
            }
        }
 *num_rows=row;
 *num_cols=col;
}//end of function
void addRow(char*** board,int* num_rows,int* num_cols,int pos)
{
 /*
   Function to add a row in the board
   @board:The board
   @num_rows:The number of rows in the board
   @num_cols:The number of cols in the board
   @pos:The position where the row should be added
   @return:None(Since it has 'void' as its return type)
 */
 int i,j;
 *num_rows+=1;
 *board=(char **)realloc(*board,*num_rows*sizeof(char *));
 if(pos!=*num_rows-1)
   {
    for(i=*num_rows-1;i>pos;i--)
       {
        (*board)[i]=(char *)realloc((*board)[i],*num_cols*sizeof(char));
        for(j=0;j<*num_cols;j++)
           {
            (*board)[i][j]=(*board)[i-1][j];
           }
       }
    for(i=0;i<*num_cols;i++)
       {
        (*board)[pos][i]='*';
       }
   }
 else
 {
  for(i=0;i<*num_cols;i++)
       {
        (*board)[pos]=(char *)malloc(*num_cols*sizeof(char));
       }
  for(i=0;i<*num_cols;i++)
     {
      (*board)[pos][i]='*';
     }
 }
}//end of function
void addColumn(char*** board,int* num_rows,int* num_cols,int pos)
{
 /*
   Function to add a column at a certain position
   @board:The board
   @num_rows:The number of rows in the board
   @num_cols:The number of columns in the board
   @pos:The position where the column should be added at
   @return:None(Since it has 'void' as its return type)
 */
 int i,j;
 *num_cols+=1;
 if(pos!=*num_cols-1)
   {
    for(i=*num_cols-1;i>pos;i--)
       {
        for(j=0;j<*num_rows;j++)
           {
            (*board)[j]=(char *)realloc((*board)[j],*num_cols*sizeof(char));
            (*board)[j][i]=(*board)[j][i-1];
           }
       }
   }
 for(i=0;i<*num_rows;i++)
    {
     (*board)[i]=(char *)realloc((*board)[i],*num_cols*sizeof(char));
    }
 for(i=0;i<*num_rows;i++)
    {
     (*board)[i][pos]='*';
    }
}//end of function
void addRowCol(char*** board,int* num_rows,int* num_cols,char dimensions,int pos)
{
 /*
   Function to add a row or column depending on the type of dimension
   @board:The board
   @num_rows:The number of rows in the board
   @num_cols:The number of cols in the board
   @dimensions:One of the two dimensions of the board
   @pos:The position where the row or column should be added at
   @return:None(Since it has 'void' as its return type)
 */
 if(dimensions=='r')
   {
    addRow(board,num_rows,num_cols,pos);
   }
 else if(dimensions=='c')
        {
         addColumn(board,num_rows,num_cols,pos);
        }
}//end of function
void delRow(char*** board,int* num_rows,int* num_cols,int pos)
{
 /*
   Function to delete a row
   @board:The board
   @num_rows:The number of rows in the board
   @num_cols:The number of columns in the board
   @pos:The position of the row that needs to be deleted
 */
 int i,j;
 char temp;
 if(pos<=*num_rows-1)
   {
    for(i=pos;i<*num_rows-1;i++)
       {
        for(j=0;j<*num_cols;j++)
           {
            temp=(*board)[i][j];
            (*board)[i][j]=(*board)[i+1][j];
            (*board)[i+1][j]=temp;
           }
       }
    *num_rows-=1;
    *board=(char **)realloc(*board,*num_rows*sizeof(char *));
   }
}//end of function
void delColumn(char*** board,int* num_rows,int* num_cols,int pos)
{
 /*
   Function to delete a column at a given position
   @board:The board
   @num_rows:The number of rows in the board
   @num_cols:The number of columns in the board
   @pos:The position of the column that must be deleted
   @return:None(Since it has 'void' as its return type)
 */
 int i,j;
 char temp;
 if(pos<=*num_cols-1)
   {
    for(i=pos;i<*num_cols-1;i++)
       {
        for(j=0;j<*num_rows;j++)
           {
            temp=(*board)[j][i];
            (*board)[j][i]=(*board)[j][i+1];
            (*board)[j][i+1]=temp;
           }
       }
    *num_cols-=1;
    for(i=0;i<*num_rows;i++)
       {
        (*board)[i]=(char *)realloc((*board)[i],*num_cols*sizeof(char));
       }
   }
}//end of function
void delRowCol(char*** board,int* num_rows,int* num_cols,char dimensions,int pos)
{
 /*
   Function to delete a row or column depending on the type of dimension
   @board:The board
   @num_rows:The number of rows in the board
   @num_cols:The number of columns in the board
   @dimensions:One of the two dimensions of the board
   @pos:The position of the row or column that must be deleted
   @return:None(Since it has 'void' as its return type
 */
 if(dimensions=='r')
   {
    delRow(board,num_rows,num_cols,pos);
   }
 else if(dimensions=='c')
        {
         delColumn(board,num_rows,num_cols,pos);
        }
}//end of function
bool saveFile(char** board,int num_rows,int num_cols,char fileName[])
{
 /*
   Function to save the board in a file
   @board:The board
   @num_rows:The number of rows in the board
   @num_cols:The number of columns in the board
   @fileName:The name of the file
   @return:bool(Since it has 'bool' as its return type)
 */
 FILE* fp;
 int i,j;
 fp=fopen(fileName,"wb");
 if(fp==NULL)
   {
    return false;
   }
 else
 {
  fwrite(&num_rows,sizeof(int),1,fp);
  fwrite(&num_cols,sizeof(int),1,fp);
  for(i=0;i<num_rows;i++)
     {
      for(j=0;j<num_cols;j++)
         {
          fwrite(&board[i][j],sizeof(char),1,fp);
         }
     }
 }
 fclose(fp);
 return true;
}//end of function
bool loadFile(char*** board,int* num_rows,int* num_cols,char fileName[])
{
 /*
   Function to load a saved file
   @board:The board
   @num_rows:The number of rows in the board
   @num_cols:The number of columns in the board
   @fileName:The name of the file
   @return:bool(Since it has 'bool' as its return type)
 */
 FILE* fp;
 int i,j;
 fp=fopen(fileName,"rb");
 if(fp==NULL)
   {
    return false;
   }
 else
 {
  fread(num_rows,sizeof(int),1,fp);
  fread(num_cols,sizeof(int),1,fp);
  *board=(char **)malloc(*num_rows*sizeof(char *));
  for(i=0;!feof(fp)&&i<*num_rows;i++)
     {
      (*board)[i]=(char *)malloc(*num_cols*sizeof(char));
      for(j=0;j<*num_cols;j++)
         {
          fread(&(*board)[i][j],sizeof(char),1,fp);
         }
     }
 } 
 fclose(fp);
 return true;
}//end of function
