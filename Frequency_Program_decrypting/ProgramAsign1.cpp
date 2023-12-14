#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int main() {
    //char str_message[100], ch;
    //may implement to store the int value of the char
    int le [26] ={};
    //j and Key are not needed here 
    //int j;
    //int array for the key elements shifts
    int key[26] = {};
    //hardcode the piece of Cipher text here
char ch[500] = "PTPRKWPICVKJNWTRSRLKUKVRRLKSCCUKIUCKRBVISTVMKLIEKVKJNWKYBNWVKCEKVQWBARLKPVIKDJKZ";
//Will store the temp char to input into the decoded mess
int temp ;
//will store the decoded message to process
char message[500] = {};

//run while ch has next
int i = 0;
  while(i  <= 500){

    //check if text is between A - Z
    if(ch[i] >= 'A' && ch[i] <= 'Z'){

    
      if(ch[i] == 'K' ){
      //then insert to message
      temp = 'E' ;
      message[i] = temp;
      le[i] = 'k' - 'E';
      }
      else if(ch[i] == 'O' ){
      //then insert to message
        temp = 'G' ;
        message[i] = temp;
      }
       else if(ch[i] == 'L' ){
        //then insert to message
        temp = 'H' ;
        message[i] = temp;
      }
      else  if(ch[i] == 'P' ){
        //then insert to message
        temp = 'N' ;
        message[i] = temp;
      }
      else  if(ch[i] == 'B' ){
        //then insert to message
        temp = 'O' ;
        message[i] = temp;
      }
      else  if(ch[i] == 'R' ){
        //then insert to message
        temp = 'T' ;
        message[i] = temp;
      }
      else  if(ch[i] == 'N' ){
        //then insert to message
        temp = 'U' ;
        message[i] = temp;
        }
      else  if(ch[i] == 'E' ){
        //then insert to message
        temp = 'V' ;
        message[i] = temp;
        }
        else  if(ch[i] == 'M' ){
        //then insert to message
        temp = 'W' ;
        message[i] = temp;
        }
        else  if(ch[i] == 'Y' ){
        //then insert to message
        temp = 'D' ;
        message[i] = temp;
        }
        else  if(ch[i] == 'G' ){
        //then insert to message
        temp = 'K' ;
        message[i] = temp;
        }
        else  if(ch[i] == 'T' ){
        //then insert to message
        temp = 'I' ;
        message[i] = temp;
        }
        else  if(ch[i] == 'J' ){
        //then insert to message
        temp = 'C' ;
        message[i] = temp;
        }
        else  if(ch[i] == 'A' ){
        //then insert to message
        temp = 'M' ;
        message[i] = temp;
        }
        else  if(ch[i] == 'Z' ){
        //then insert to message
        temp = 'P' ;
        message[i] = temp;
        }
        else  if(ch[i] == 'V' ){
        //then insert to message
        temp = 'S' ;
        message[i] = temp;
        }
        else  if(ch[i] == 'W' ){
        //then insert to message
        temp = 'R' ;
        message[i] = temp;
        }
        else  if(ch[i] == 'S' ){
        //then insert to message
        temp = 'Y' ;
        message[i] = temp;
        }
        else  if(ch[i] == 'U' ){
        //then insert to message
        temp = 'B' ;
        message[i] = temp;
        }
        else  if(ch[i] == 'I' ){
        //then insert to message
        temp = 'A' ;
        message[i] = temp;
        }
        else  if(ch[i] == 'Q' ){
        //then insert to message
        temp = 'F' ;
        message[i] = temp;
        }
        else  if(ch[i] == 'C' ){
        //then insert to message
        temp = 'L' ;
        message[i] = temp;
        }
        else  if(ch[i] == 'D' ){
        //then insert to message
        temp = 'X' ;
        message[i] = temp;
        }
      else{
        message[i] = ch[i];
      }

    }
    ++i;
  }
printf("\n");
 cout << "Encrypted message: " << ch <<endl;
  cout << "Decrypted message: " << message <<endl;
printf("\n");
 cout << "interger Key: " << le <<endl;
printf("\n");
  return 0;
}