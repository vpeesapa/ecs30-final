#include<ctype.h>
#include<stdio.h>
#include<stdbool.h>
#include"input_val.h"
bool input_correct(bool isValid)
{
 /*
   Function to print a space after every command
   @isValid:Boolean variable that returns true if user input is valid
   @return:A boolean
 */
 char new_line='\n';
 do
 {
  scanf("%c",&new_line);
  if(!isspace(new_line))
    {
     isValid=false;
    }
 }while(new_line!='\n');
 return isValid;
}//end of function
bool checkFormatting(int num_args_read,int num_args_need)
{
 /*
   Function to get a valid type of user input
   @num_args_read:Number of arguments read by the scanf() function
   @num_args_need:Number of arguments needed to be read by the scanf() function
   @return:True if user input is valid, false otherwise
 */

 bool isValid=true;
 if(num_args_read!=num_args_need)
   {
    isValid=false;
   }
 isValid=input_correct(isValid);
 return isValid;
}//end of function

