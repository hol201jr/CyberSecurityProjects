
/*
Author: Manny H
Title: Ceaser_Decrypter
Date: 12/13/2023

Description:
This c++ is an upgraded version of the two ceaser cypher decrypter cpp files {freq.cpp and ProgramAsign1.cpp}
For the purpose of plaining more with C++ and creating a cleaner file system and code.
The program will read in a cypher text from a file and aquire the frequency at which each letter appears in the text file
from which the program will generate random keys based on the frequencies in hopes that the text will be readable.
*/

// Inlcuding headers to read from a file
#include <iostream>
#include <fstream>
#include <cstdlib> //for exit function good practice
// Headers for Dynamic string array
#include <vector>
#include <string>
#include <map>
// Header for traversing a string's characters
#include <bits/stdc++.h>

using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;
using namespace std;

// Function to insert value into map by key reference map
void insert_value(map<char, int> &m, char letter)
{

    // Use build in iterator to find the key and update the value of the map
    std::map<char, int>::iterator it = m.find(letter);

    // If the key is found and not the end of the map
    if (it != m.end())
    {
        // insert key-> value into val and increment
        int val = it->second;
        ++val;
        // cout << "Found key " << it->first << ": Value " << val << " " << endl;
        // insert into key -> value
        it->second = val;
    }
    // Deals with none Cap characters and none alphabetical characters (eg. / %^@)
    else
    {
        cout << "Key not in Map" << endl;
    }
}

int main()
{

    // create a map with <char , int> pair
    map<char, int> mp;

    // insert values into map for each letter in the alphabet
    for (int i = 0; i < 26; i++)
    {
        char character = 'A';
        char newChar = character + i;
        mp[newChar] = 0;
    }

    // Check if the values where placed into the Map correctly
    map<char, int>::iterator it = mp.begin();

    // Iterate through the map and print the elements UN-COMMENT TO SEE MAP
    /*while (it != mp.end()) {
        cout << "Key: " << it->first
             << ", Value: " << it->second << endl;
        ++it;
    }*/

    // cin
    ifstream indata;

    // Cypher text will be stored as strings
    std::string message;

    // Potential use of array for multiple lines - not implemented
    // std::vector<std::string> arrayOfMessages;

    // Open the file
    indata.open("ciphertext.txt");

    // Check if file is there
    if (!indata)
    {
        cerr << "Error file not found. Please make sure the file is in the CWD" << endl;
        exit(1);
    }
    // If file is there store the text file information
    else
    {
        indata >> message;
        cout << "This is the encrypted message" << endl;
        while (!indata.eof())
        {
            cout << message << endl;
            // Testing to read until end of file
            for (auto &ch : message)
            {
                // cout << ch << " ";
                insert_value(mp, ch);
            }

            // Will trigger the EOF flag if no value is found in the file
            indata >> message;
        }

        // close the fileusing std::cerr;
        indata.close();

        cout << "This is the end of the chipher message" << endl;
        cout << "Will now start writting to file occurances.txt" << endl;

        // Create and open a text file
        ofstream ToFile("occurances.txt");

        // Check if the values where placed into the Map correctly
        map<char, int>::iterator checker = mp.begin();

        // Iterate through the map and print the elements
        while (checker != mp.end())
        {
            ToFile << "Key " << checker->first << ":" << checker->second << endl;
            ++checker;
        }

        // Close the file
        ToFile.close();
    }

    return 0;
}
