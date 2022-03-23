#include<iostream>
#include<string.h>
using namespace std;
int main() {
   cout<<"Enter the message:\n";
   char msg[100];
   cin.getline(msg,100);
   int i, j, length,choice;
   //int array for the key elements shifts from A-Z
    int key [26] = {12,13,9,20,17,0,4,0,18,19,20,22,10,7,18,24,15,2,6,15,7,23,21,0,5,16};
cout<<"Enter your choice \n1. Encryption \n2. Decryption \n";
   cin>>choice;
   int k;
   cout << "Enter the Key to use from 1 - 26\n" ;
   cin>>k;
      if (choice==1){ //Encryption
      char ch;
      for(int i = 0; msg[i] != '\0'; ++i) {
         ch = msg[i];
         //encrypt for uppercase letter
         if (ch >= 'A' && ch <= 'Z'){
            ch = ch + key[k];
            if (ch > 'Z'){
               ch = ch - 'Z' + 'A' - 1;
            }
            msg[i] = ch;
         }
      }
      printf("Encrypted message: %s", msg);
   }
   else if (choice == 2) { //decryption
      char ch;
      for(int i = 0; msg[i] != '\0'; ++i) {
         ch = msg[i];
         //decrypt for uppercase letter
          if(ch >= 'A' && ch <= 'Z') {
            ch = ch - key[k];
            if(ch < 'A') {
               ch = ch + 'Z' - 'A' + 1;
            }
            msg[i] = ch;
         }
      }
      cout << "Decrypted message: " << msg;
   }
}