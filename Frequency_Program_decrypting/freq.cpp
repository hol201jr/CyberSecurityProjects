//including header files
//This file prints out the frequency of the number of appearance
//of a letter in the cipherText
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
//main
int main()
{

    int frequencies[26]={0};
        
        //Input The cipher text here
   char ch[1000] = 
   "KEKPRLBNOLMKYBPRGPBMMLTJLJBAZIPTKVRLKPVILIVJBAZWBATVKYBWUSMLIRAKIPVGPBMTPORLIRRLKSJBNCYLIEKJBAZWBATVKYIPSBQRLKATVKPBNOLRBAIGKNVATVRWNVRQNCBQICCBQRLKARLTVTVOBTPORBAIGKTRLIWYQBWCIWOKJBAZIPTKVCTGKOBBOCKIPYATJWBVBQRRBOKRUIJGRLKRWNVRRLKSCBVRKEKPTQRLKSVNJJKKYTPCTATRTPOOBEKWPAKPRVNWEKTCCIPJKKEKPTQRLKSVNJJKKYTPTAZWBETPORLKTWBMPTPRKWPICVKJNWTRSRLKUKVRRLKSCCUKIUCKRBVISTVMKLIEKVKJNWKYBNWVKCEKVQWBARLKPVIKDJKZRQBWRLKZIWRVRLIRMKKTRLKWYBPRGPBMIUBNRBWJIPRRICGIUBNR";

int i = 0, alphabet[26] = {0}, j;

   while (ch[i] != '\0') {
      if (ch[i] >= 'A' && ch[i] <= 'Z') {
         j = ch[i] - 'A';
         ++alphabet[j];
      }
      ++i;
   }
      for(int i=0; i<26; i++){
       cout<<"Letter: "<< char('A'+i)<<" occurrence "<<alphabet[i]<<endl;
   }
}