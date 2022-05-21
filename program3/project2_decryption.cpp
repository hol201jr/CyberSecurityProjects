#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;
//message decryption using command
void decrypt(string z , string y){
    //openssl rsautl -encrypt -pubin -inkey pubkey.pem -in symm_key.bin -raw -hexdump -out symmetric.txt
    std::string str = "openssl rsautl -decrypt -inkey " + z + " -in top_secret.enc > top_secret.txt";
    const char *c = str.c_str(); 
    int dec  = std::system(c);
cout<< dec;
}

//function to run commandline system verification of a signature
void verification(string x[] , string y , string z){
    string si = "";
    string un = "";
cout<< "Inside the verification algo";
    for(int i = 0 ; i < 3 ; i++){
        if(i <= 2 ){
            si += x[i];
        }
        if(i <= 1){
            un += x[i];
        }
    }//"+ y + "" + si + "+ un
    std::string str = "openssl dgst -verify pubkey.pem -keyform PEM -sha256 -signature top_secret.enc.sign -binary top_secret.enc" ;
    const char *c = str.c_str();
//openssl dgst -verify key.pub -keyform PEM -sha256 -signature data.zip.sign -binary data.zip
int verify  = std::system(c);
cout<< verify;

//after verification run the decryption process from the file
decrypt(z, un);
}

int main(){

string decryptionFile ="top_secret.enc.sign";
string fname [3] = {"top_secret",".enc",".sign"};
string publickey = "pubkey.pem";
string symmkey = "symmetric.txt";

verification(fname, publickey , symmkey);


}
