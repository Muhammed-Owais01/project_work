#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define SIZE 8


char board[SIZE][SIZE] = {{"X", " ", "X", " ", "X", " ", "X", " "},
                          {" ", "X", " ", "X", " ", "X", " ", "X"},
                          {"X", " ", "X", " ", "X", " ", "X", " "},
                          {" ", " ", " ", " ", " ", " ", " ", " "},
                          {" ", " ", " ", " ", " ", " ", " ", " "},
                          {" ", "O", " ", "O", " ", "O", " ", "O"},
                          {"O", " ", "O", " ", "O", " ", "O", " "},
                          {" ", "O", " ", "O", " ", "O", " ", "O"}};
// in this function we confermed k goti ha ya nhi frist person ki
 int conferm1(char board[][SIZE],int r,int c,char ch){
 	//c stand for colume 
 	//r stand for row
 	if(board[r][c]==ch){
 		return 1;
 	}else
 	return 0;
 }//end of confer1

//in this function we confermed k goti ha ya nhi secand person ki
 int conferm2(char board[][SIZE],int r,int c){
 	//c stand for colume 
 	//r stand for row
 	if(board[r][c]=='O'||board[r][c]=='X'){
 		return 0;
 	}else
 	return 1;
 }//end of conferm2

//this function chack if user move 2 col or row it can chack back
 int chackforbak(char board[][SIZE],int row,int col,int curent_row,int curent_col){
 	     char a=board[curent_row][curent_col];
 	     char b=' ';
 	     if(board[row][col]==b){
 	     	return 0;
 	     }
 	     if(board[row][col]==a){
 	     	return 0;
 	     }

 	return 1;
 }

//display the bord in start and when we play
void display(char board[][SIZE]){
      printf("====================\n");
      printf("  ||0|1|2|3|4|5|6|7|\n");
       printf(" _|=================\n");
      for ( int i = 0; i < SIZE;i++){
      	 //printf("| ||-|-|-|-|-|-|-|-|\n");
      	printf("|%d|", i);
      	for (int j = 0; j < SIZE; j++){
      		printf("|");
      		printf("%c",board[i][j] );
      	}

      	 printf("|");
         if(i==7){
         	printf("\n====================");
         }

      	printf("\n");
      	
      	
      }
      return;
}//end of display

void movepice(char board[][SIZE],int irow,int icol,int frow,int fcol,char a){
         board[irow][icol]=' ';
         board[frow][fcol]=a;
	return;
}

//this function can take input from 1st person
void fsinput(char board[][SIZE]){
	   int rowintial,colintial;//we use these veriabe for find courent location of guti
        int row,col;//we use these veribel for d
        int i=1;
        int a;
        //by this loop we take initil position of guti
        while(i==1){

           printf("enter the 'row'of guti which you want to move:" );
           scanf("%d",&rowintial);
           printf("enter the 'colume'of guti which you want to move:" );
           scanf("%d",&colintial);
           //now call the conferm function to cahck at given location guti is present or not 
            a =  conferm1(board,rowintial,colintial,'X');//call the function to 
           if ((rowintial<0||rowintial>7)||(colintial<0||colintial>7) )
           {
           	printf("you inter invalid location\n ");
           }else if(a==0){
           	   printf("enter the valide location the  is no your guti\n ");
           }else i=-1;
        }
          i=1;
        //take input for final loction of guti 
         while(i==1){

           printf("enter the 'row' of new location of pice:" );
           scanf("%d",&row);
           printf("enter the 'colume' of now location of pice:" );
           scanf("%d",&col);
           //now call the conferm function to cahck at given location guti is present or not 
            a =  conferm2(board,row,col);//call the function to know yha phaly sy hi goti to nhi gha
            int difrow=row-rowintial;
            int  difcol=col-colintial;
            int b;//use as  a mode function for row
            int c;//use as a mode function for colume
            if(difrow<0){
                b = difrow*(-1);
            }
            if(difcol<0){
            	c = difcol*(-1);
            }
           if ((row<0||row>7)&&(col<0||col>7) )
           {
           	printf("you inter invalid location this location not in board\n ");
           }else 
           if(a==0){
           	   printf("error! invalid location there is another pice present\n ");
           }else 
           if(difcol>2||difrow>2){
           	  printf("you can't move at this location it is not allowed\n");
           }else
            if(b==2&&c==2){
           	  if(difcol<0){
           	  	switch(difrow){
           	  	case -2:
           	  		if(chackforbak(board,row-1,col-1,rowintial,colintial)!=1){
           	  			printf("your move is roung enter valid adderass\n");	
           	  		}
           	  		break;
           	  	case 2: 
           	  		if(chackforbak(board,row+1,col-1,rowintial,colintial)!=1){
           	  		    printf("your move is roung enter valid adderass\n");
           	  	    }
           	  	    break;
           	  	default:printf("there is any problubme in your input \n");
           	  	}//end of switch of difro
           	  }//end of if difcol<0
           	  else
           	  if(difcol>0){
           	  	switch(difrow){
           	  	case -2:
           	  		if(chackforbak(board,row-1,col+1,rowintial,colintial)!=1){
           	  			printf("your move is roung enter valid adderass\n");
           	  		}
           	  		break;
           	  	case 2: 
           	  		if(chackforbak(board,row+1,col+1,rowintial,colintial)!=1){
           	  			printf("your move is roung enter valid adderass\n");
           	  		}
           	  		break;
           	  	default:printf("there is any problubme in your input \n");
           	  	}//end of switcah
           	  }//end of if difcol > 0
           	}//end of if b == 2 && a == 2
           	else 
           	if (b==1&&c==1){
           		if (board[row][col]!=' '){
           		 printf("you can't move hear becouse there is already an pice\n");
           		}
           	}else i=-1;
           }
           movepice(board,rowintial,colintial,row,col,'X');

	return;
}//end of input of frist preson


//in this function we take input for second person 
void scinput(char board[][SIZE]){
	   int rowintial,colintial;//we use these veriabe for find courent location of guti
        int row,col;//we use these veribel for d
        int i=1;
        int a;
        //by this loop we take initil position of guti
        while(i==1){

           printf("enter the 'row'of guti which you want to move:" );
           scanf("%d",&rowintial);
           printf("enter the 'colume'of guti which you want to move:" );
           scanf("%d",&colintial);
           //now call the conferm function to cahck at given location guti is present or not 
            a =  conferm1(board,rowintial,colintial,'O');//call the function to 
           if ((rowintial<0||rowintial>7)||(colintial<0||colintial>7) )
           {
           	printf("you inter invalid location\n ");
           }else if(a==0){
           	   printf("enter the valide location there  is no your pice\n ");
           }else i=-1;
        }
          i=1;
        //take input for final loction of guti 
         while(i==1){

           printf("enter the 'row' of new location of pice:" );
           scanf("%d",&row);
           printf("enter the 'colume' of now location of pice:" );
           scanf("%d",&col);
           //now call the conferm function to cahck at given location guti is present or not 
            a =  conferm2(board,row,col);//call the function to know yha phaly sy hi goti to nhi gha
            int difrow=row-rowintial;
            int  difcol=col-colintial;
            int b;//use as  a mode function for row
            int c;//use as a mode function for colume
            if(difrow<0){
                b = difrow*(-1);
            }
            if(difcol<0){
            	c = difcol*(-1);
            }

            if(b<1||c<1){
            	 printf("you can't move at this location it is not allowed\n");
            }else
            if ((row<0||row>7)&&(col<0||col>7) )
            {
           	printf("you inter invalid location this location not in board\n ");
            }else 
            if(a==0){
           	   printf("error! invalid location there is another pice present\n ");
            }else 
            if(difcol>2||difrow>2){
           	  printf("you can't move at this location it is not allowed\n");
            }else
             if(b==2&&c==2){
           	   if(difcol<0){
           	  	 switch(difrow){
           	  	 case -2:
           	  		if(chackforbak(board,row-1,col-1,rowintial,colintial)!=1){
           	  			printf("your move is roung enter valid adderass\n");	
           	  		}
           	  		break;
           	  	 case 2: 
           	  		if(chackforbak(board,row+1,col-1,rowintial,colintial)!=1){
           	  		    printf("your move is roung enter valid adderass\n");
           	  	    }
           	  	    break;
           	  	 default:printf("there is any problubme in your input \n");
           	  	 }//end of switch of difro
           	   }//end of if difcol<0
           	   else
           	    if(difcol>0){
           	  	  switch(difrow){
           	  	  case -2:
           	  		if(chackforbak(board,row-1,col+1,rowintial,colintial)!=1){
           	  			printf("your move is roung enter valid adderass\n");
           	  		}
           	  		break;
           	  	  case 2: 
           	  		if(chackforbak(board,row+1,col+1,rowintial,colintial)!=1){
           	  			printf("your move is roung enter valid adderass\n");
           	  		}
           	  		break;
           	  	  default:printf("there is any problubme in your input \n");
           	  	  }//end of switcah
           	    }//end of if difcol > 0
           	}//end of if b == 2 && a == 2
           	else 
           	if (b==1&&c==1){
           		if (board[row][col]!=' '){
           		 printf("you can't move hear becouse there is already an pice\n");
           		}
           	}else i=-1;
           }
           movepice(board,rowintial,colintial,row,col,'O');

	return;
}//end of input of frist preson

// this functon chack for bass condition to stope game
int chack(char board[][SIZE]){
	    // bool flag=true;
	    // char searchChar='X';//search for frist member guti
        // if(strchr(board[][],searchChar)!=NULL){
        //         flag=false;   //agar 1st person ki goti nhi milay gi to false kar day ga
	    // }
	    
	    // if (flag){
	    // 	return 0;
	    // }
         
        //  searchChar='O';//now search for secend member guti
        // if(strchr(board, searchChar)!=NULL){
        //         flag=false;   //agar 2nd person ki goti nhi milay gi to false kar day ga
	    // }
	    
	    // if (flag){
	    // 	return 0;
	    // }
      return 1;
}

///play game in the function
void playgame(char board[][SIZE],int i){
	    int a=chack(board);
	   if(a==0){
	   	  // if()
	   	return;
	   }
	   if(i%2==0){
	   	printf("tern of 1st person\n");
	   	fsinput(board);//call the function  1st person input
	   }
	   else{
	   	  printf("tern of secend person\n");
	   	 scinput(board);//call the function 2nd person input
	   }
	   system("cls");
	   display(board);
	   playgame(board,i-1);

	   return;
}

 int main(int argc, char const *argv[])
{
	display(board);
	//int c,r;//c stand for calume and r stand for row
    
    playgame(board,3000);
     
	return 0;
}