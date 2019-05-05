#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>
#include"board.h"
#include"command.h"
#include"input_val.h"
typedef struct paint_struct
{
 char** board;//the board
 int num_rows;//the number of rows present in the board
 int num_cols;//the number of columns in the board
}paint;//end of structure
void checkArgs(int num_args,char* args[],int* num_rows,int* num_cols)
{
 /*
   Function to check and read the arguments(if num_args is valid)
   @num_args:Number of arguments on the command line
   @args:The arguments that are stored on the command line
   @num_rows:The number of rows in the board
   @num_cols:The number of columns in the board
   @return:None(Since it has 'void' as its return type)
 */
 int num_args_read1,num_args_read2;
 if(num_args!=1&&num_args!=3)
   {
    printf("Wrong number of command line arguements entered.\n");
    printf("Usage: ./paint.out [num_rows num_cols]\n");
    *num_rows=10;
    *num_cols=10;
    printf("Making default board of %d X %d.\n",*num_rows,*num_cols);
   }
 else if(num_args==1)
        {
         *num_rows=10;
         *num_cols=10;
        }
 else if(num_args==3)
        {
         num_args_read1=sscanf(args[1],"%d",num_rows);
         num_args_read2=sscanf(args[2],"%d",num_cols);
         if(num_args_read1!=1||num_args_read2!=1)
           {
            if(num_args_read1!=1)
              {
               printf("The number of rows is not an integer.\n");
              }
            if(num_args_read2!=1)
              {
               printf("The number of columns is not an integer.\n");
              }
            *num_rows=10;
            *num_cols=10;
            printf("Making default board of %d X %d.\n",*num_rows,*num_cols);
           }
         if(*num_rows<=0||*num_cols<=0)
           {
            if(*num_rows<=0)
              {
               printf("The number of rows is less than 1.\n");
              }
            else
            {
             printf("The number of columns is less than 1.\n");
            }
            *num_rows=10;
            *num_cols=10;
            printf("Making default board of %d X %d.\n",*num_rows,*num_cols);
           }
        }
}//end of function
void executeCommands(char** board,int num_rows,int num_cols)
{
 /*
   Function to execute the commands
   @board:The board
   @num_rows:The number of rows in the board
   @num_cols:The number of columns in the board
   @return:None(Since it has 'void' as its return type)
 */
 char command,dimension;
 char fileName[100];
 int start_x,start_y,end_x,end_y;
 int row,col;
 int pos;
 int num_args_read;
 do
 {
  printBoard(board,num_rows,num_cols);
  printf("Enter your command: ");
  scanf(" %c",&command);
  if(command=='q')
    {
     if(!input_correct(true))
       {
        printf("Unrecognized command. Type h for help.\n");
        continue;
       }
     destroyBoard(board,num_rows);
     return;
    }
  else if(command=='h')
         {
          if(!input_correct(true))
            {
             printf("Unrecognized command. Type h for help.\n");
             continue;
            }
          print_help();
         }
  else if(command=='w')
         {
          num_args_read=scanf(" %d %d %d %d",&start_x,&start_y,&end_x,&end_y);
          if(!checkFormatting(num_args_read,4))
            {
             printf("Improper draw command.\n");
             continue;
            }
          if(start_x<0||start_x>=num_rows||start_y<0||start_y>=num_cols||end_x<0||end_x>=num_rows||end_y<0||end_y>=num_cols)
            {
             printf("Improper draw command.\n");
            }
          else
          {
           fillCanvas(board,num_rows,num_cols,start_x,start_y,end_x,end_y);
          }
         }
  else if(command=='e')
         {
          num_args_read=scanf(" %d %d",&row,&col);
          if(!checkFormatting(num_args_read,2))
            {
             printf("Unrecognized command. Type h for help.\n");
             continue;
            }
          if(row<0||row>=num_rows||col<0||col>=num_cols)
            {
             printf("Improper erase command.\n");
            }
          else
          {
           erasePoint(board,row,col);
          }
         }
  else if(command=='r')
         {
          num_args_read=scanf(" %d %d",&row,&col);
          if(!checkFormatting(num_args_read,2))
            {
             printf("Unrecognized command. Type h for help.\n");
             continue;
            }
          if(row<1||col<1)
            {
             printf("Improper resize command.\n");
            }
          else
          {
           resizeBoard(&board,&num_rows,&num_cols,row,col);
          }
         }
  else if(command=='a')
         {
          num_args_read=scanf(" %c %d",&dimension,&pos);
          if(!checkFormatting(num_args_read,2))
            {
             printf("Improper add command.\n");
             continue;
            }
          if((dimension!='r'&&dimension!='c')||pos<0)
            {
             printf("Improper add command.\n");
            }
          else if(dimension=='r'&&pos>num_rows)
                 {
                  printf("Improper add command.\n");
                 }
          else if(dimension=='c'&&pos>num_cols)
                 {
                  printf("Improper add command.\n");
                 }
          else
          {
           addRowCol(&board,&num_rows,&num_cols,dimension,pos);
          }
         }
  else if(command=='d')
         {
          num_args_read=scanf(" %c %d",&dimension,&pos);
          if(!checkFormatting(num_args_read,2))
            {
             printf("Improper delete command.\n");
             continue;
            }
          if((dimension!='r'&&dimension!='c')||pos<0)
            {
             printf("Improper delete command.\n");
            }
          else if(dimension=='r'&&pos>=num_rows)
                 {
                  printf("Improper delete command.\n");
                 }
          else if(dimension=='c'&&pos>=num_cols)
                 {
                  printf("Improper delete command.\n");
                 }
          else
          {
           delRowCol(&board,&num_rows,&num_cols,dimension,pos);
          }
         }
  else if(command=='s')
         {
          scanf("%s",fileName);
          if(!saveFile(board,num_rows,num_cols,fileName))
            {
             printf("Improper save command or file could not be created.\n");
            }
         }
  else if(command=='l')
         {
          scanf(" %s",fileName);
          if(!loadFile(&board,&num_rows,&num_cols,fileName))
            {
             printf("Failed to open file: %s\n", fileName);
            }
         }
  else
  {
   input_correct(true);
   printf("Unrecognized command. Type h for help.\n");
  }
 }while(true);//exits the while loop as well as the program
}
int main(int num_args,char* args[])
{
 paint canvas;
 checkArgs(num_args,args,&canvas.num_rows,&canvas.num_cols);
 canvas.board=createBoard(canvas.num_rows,canvas.num_cols);
 executeCommands(canvas.board,canvas.num_rows,canvas.num_cols);
 return 0;
}//end of main
