#ifndef COMMAND_H
 #define COMMAND_H
 #include<stdbool.h>
 void print_help();
 void fillHorizontal(char** board,int row,int start_y,int end_y);
 void fillVertical(char** board,int col,int start_x,int end_x);
 void fillLeftDiagonal(char** board,int start_x,int start_y,int end_x,int end_y);
 void fillRightDiagonal(char** board,int start_x,int start_y,int end_x,int end_y);
 void fillCanvas(char** board,int num_rows,int num_cols,int start_x,int start_y,int end_x,int end_y);
 void erasePoint(char** board,int row,int col);
 void resizeBoard(char*** board,int* num_rows,int* num_cols,int row,int col);
 void addRow(char*** board,int* num_rows,int* num_cols,int pos);
 void addColumn(char*** board,int* num_rows,int* num_cols,int pos);
 void addRowCol(char*** board,int* num_rows,int* num_cols,char dimensions,int pos);
 void delRow(char*** board,int* num_rows,int* num_cols,int pos);
 void delColumn(char*** board,int* num_rows,int* num_cols,int pos);
 void delRowCol(char*** board,int* num_rows,int* num_cols,char dimensions,int pos);
 bool saveFile(char** board,int num_rows,int num_cols,char fileName[]);
 bool loadFile(char*** board,int* num_rows,int* num_cols,char fileName[]);
#endif
