#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

void step2(){


}

int main(){
cout<< "Testing the program" << endl;
int status  = std::system("ls -l");
cout<< status;

std::string const HOME = std::getenv("HOME") ? std::getenv("HOME") : ".";

cout<< endl;
//std::ifstream myfile(HOME + "/path/in/home/folder.txt");

//char* pubPath = "/Home/Documents/Computer Security Class/Lab3/prog3/program3/keys/pubkey.pem";
//char* secret = "/Home/Documents/Computer Security Class/Lab3/prog3/program3/keys/symm_key.bin";

cout<< "Ecrypting the message" <<endl;
//First step of part b takes the encrypted message and 3rd party keys and outputs a hexdump symmetric.txt
int decrypted = std::system("openssl rsautl -encrypt -pubin -inkey pubkey.pem -in symm_key.bin -raw -hexdump -out symmetric.txt");

cout<< decrypted<<endl;


  ofstream myfile;
  myfile.open ("example.txt");
  myfile << "Manuel Holguin\n800748822";
  myfile.close();
  
  //This section is to solve part two for b were I encrypt a message with my name and banner Id using openSSL DES
  //openssl enc -des -kfile symmetric.txt -in example.txt -out top_secret.enc

int encrypt = std::system("openssl enc -des -kfile symmetric.txt -in example.txt -out top_secret.enc");

cout << encrypt;

// Final step is to sign the file from the previous step
//openssl dgst -sign privekey.pem -keyform PEM -sha256 -out top_secret.enc.sign -binary data.zip

int signature = std::system("openssl dgst -sign privekey.pem -keyform PEM -sha256 -out top_secret.enc.sign -binary top_secret.enc");

cout << signature;

return 0;
}