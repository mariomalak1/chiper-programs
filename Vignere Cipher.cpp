#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
using namespace std;
// functions of program here
char encrypted_character3(int nAscii ){
    char enc_character;
    enc_character = ((nAscii % 26) + 'A');
    return enc_character;
}
// function to make the keyword is upper case only
string upper_case(string str){
    for (auto & c: str) c = toupper(c);
    return str;
}
string keyword_adjust3(string keyword , int sizeof_word , int counter = 0){
    // to insert all characters of keyword into array
    string array_keyword[keyword.length()] = {};
    for(int i = 0 ; i < keyword.length() ; i++){
        array_keyword[i] = keyword[i];
    }
    // to make keyword is as length of original word
    const int length_keyword = keyword.length();
    for(int i = 0 ; i < ((sizeof_word) - length_keyword) ; i++){
        if (counter == (sizeof(array_keyword) / sizeof(array_keyword[0]))){
            counter = 0;
            i--;
        }
        else{
            keyword.insert( (keyword.length()),array_keyword[counter]);
            counter++;
        }
    }
    return keyword;
}
int aad_characters3(char character_org , char character_key ,int nAscii = 0){
    nAscii = character_org + character_key;
    return nAscii;
}
string encrypted_message3(string message , string keyword){
    string encrypted_message;
    char enc_character;
    int nAscii = 0;
    for (int i = 0; i < message.length() ; i++){
        if((message[i] >= 65) && (message[i] <= 91)){
            nAscii = aad_characters3(message[i],keyword[i]);
            enc_character = encrypted_character3( nAscii );
            encrypted_message += enc_character;
        }
        else{
            encrypted_message += message[i];
        }
    }
    return encrypted_message;
}
char description_character3(char enc_char, char keyword_char ,char dec_char = ' ' , int  counter = 0){
    dec_char = (enc_char - 'A');
    for (int i = 0; i < 26 ; i++){
        if (((65 + i + keyword_char) % 26) == dec_char){
            dec_char = i + 65;
            break;
        }
        else{
            counter += 1;
        }
    }
    if (counter == 26){
        dec_char = enc_char;
    }
    return dec_char;
}
string description_message3(string enc_message , string keyword , string dec_message = ""){
    for (int i = 0; i < enc_message.length() ; i++){
        if((enc_message[i] >= 65) && (enc_message[i] < 91)){
            dec_message += description_character3(enc_message[i] , keyword[i]);
        }
        else{
            dec_message += enc_message[i];
        }
    }
    return dec_message;
}
void response_print(){
    cout << "1- Cipher a message " << endl;
    cout << "2- Decipher a message " << endl;
    cout << "3- End " << endl ;
    cout << "What do you like to do today : " ;
}
void vignere_cipher(){
    string response , message , keyword;
    response_print();
    bool isRun = true;
    while (isRun){
        cin >> response;
        if ((response == "1" ) or (response == "2" )){
            if (response == "1"){
                while (true) {
                    cout << "Enter Your Message, And it be less than 80 character : ";
                    cin.ignore();
                    getline(cin , message);
                    cout << "Enter Your Keyword : ";
                    getline(cin, keyword);
                    if ((message.length() > 80) or (keyword.length() > 8) or (keyword.length() == 0) or (message.length() == 0)){
                        cout << "Please Make  Your Message Less Than 80 or Keyword Less Than 8 " << endl;
                    }
                    else{
                        message = upper_case(message);
                        keyword = keyword_adjust3(upper_case(keyword) , message.length());
                        cout << encrypted_message3(message,keyword) << endl;
                        cin.ignore();
                        break;
                    }
                }
            }

            else{
                while (true) {
                    cout << "Enter Your Message To Decrypt, And it be less than 80 character : ";
                    cin.ignore();
                    getline(cin , message);
                    cout << "Enter Your Keyword : ";
                    getline(cin, keyword);
                    if ((message.length() > 80) or (keyword.length() > 8) or (keyword.length() == 0) or (message.length() == 0)){
                        cout << "Please Make  Your Message Less Than 80 or Keyword Less Than 8 " << endl;
                    }
                    else{
                        message = upper_case(message);
                        keyword = keyword_adjust3(upper_case(keyword) , message.length());
                        cout << description_message3(message , keyword) << endl;
                        cin.ignore();
                        break;
                    }
                }
            }
        }
        else if (response == "3"){
            isRun = false;
            cout << "end of the program " << endl;
        }
        else{
            cout << "Please Enter 1 Or 2 Or 3 Only" << endl;
            cin.ignore();
            response_print();
        }
    }
}
int main() {
    vignere_cipher();
    return 0;
}
