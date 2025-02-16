#include "encryption.h"
#include <fstream>
#include <cctype>
using namespace std;

bool performCeaserCipher(string& content, bool encrypt){
    int shift= encrypt ? 3 : -3;
    for (char& ch:content){
        if(isalpha(ch)) {
            // cc header file is used above
            char base =isupper(ch) ? 'A' : 'a';
            ch= static_cast<char>((ch - base + shift + 26)%26 + base);
        }
    }
    return true;
}

bool encryptFile(const string& filename,bool encrypt){
    // open input file
    ifstream inFile(filename);
    if(!inFile){
        return false;
    }
    // read the file content
    string content((istreambuf_iterator<char>(inFile)),{});
    inFile.close();
    if (performCeaserCipher(content,encrypt)){
         // create an output file and write the modified content
         ofstream outFile(encrypt ? "encrypted_"+filename : "decrypted_"+filename);
         if(!outFile){
             return false;
         }
         outFile << content;
         outFile.close();
         return true;

    }
       

    

}