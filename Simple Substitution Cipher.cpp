#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
string lowercase(string theMessage , string message = ""){
    for(int i = 0; i < theMessage.length() ; i++){
        message += tolower(theMessage[i]);
    }
    return message;
}
string keyword_adjust5(string key , string keyword = "" , string alp = "abcdefghijklmnopqrstuvwxyz" , int counter = 0){
    for (int i = 0 ; i < alp.length() ; i++){
        for (int j = 0 ; j < key.length() ; j++){
            if (alp[i] == key[j]){
                break;
            }
            else{
                counter += 1;
            }
        }
        if (counter == key.length() ){
            keyword += alp[i];
        }
        counter = 0;
    }
    keyword = key + keyword;
    return keyword;
}
string encrypted_message5(string message , string keyword,  string alp = "abcdefghijklmnopqrstuvwxyz", string enc_message = ""){
    for (int i = 0; i < message.length(); i++) {
        if ((message[i] < 122) and (message[i] > 90)) {
            for (int j = 0; j < alp.length(); j++) {
                if (message[i] == alp[j]) {
                    enc_message += keyword[j];
                    break;
                }
            }
        }
        else{
            enc_message += message[i];
        }
    }
    return enc_message;
}
string decrypted_message5(string enc_message , string keyword, string alp = "abcdefghijklmnopqrstuvwxyz" , string dec_message = ""){
    for (int i = 0; i < enc_message.length(); i++) {
        if ((enc_message[i] < 122) and (enc_message[i] > 90)) {
            for (int j = 0; j < alp.length(); j++) {
                if (enc_message[i] == keyword[j]) {
                    dec_message += alp[j];
                    break;
                }
            }
        }
        else{
            dec_message += enc_message[i];
        }
    }
    return dec_message;
}
void simple_sbstitution_cipher(){
    string response , message , keyword;
    cout << "If You Want To Encrypt Message Enter 1 , And To decrypt Enter 2 : ";
    cin >> response;
    while (true){
        if ((response == "1" ) or (response == "2" )){
            if (response == "1"){
                while (true) {
                    cout << "Enter Your Message : ";
                    cin.ignore();
                    getline(cin , message);
                    cout << "Enter Your Keyword : ";
                    getline(cin, keyword);
                    if ((keyword.length() == 0) or (message.length() == 0)){
                        cout << "please enter message or keyword" << endl;
                    }
                    else{
                        message = lowercase(message);
                        keyword = keyword_adjust5(lowercase(keyword));
                        cout << encrypted_message5(message,keyword) << endl;
                        break;
                    }
                }
                break;
            }

            else{
                while (true) {
                    cout << "Enter Your Message To Decrypt : ";
                    cin.ignore();
                    getline(cin , message);
                    cout << "Enter Your Keyword : ";
                    getline(cin, keyword);
                    if ((keyword.length() == 0) or (message.length() == 0)){
                        cout << "please enter message or keyword" << endl;
                    }
                    else{
                        message = lowercase(message);
                        keyword = keyword_adjust5(lowercase(keyword));
                        cout << decrypted_message5(message , keyword) << endl;
                        break;
                    }
                }
                break;
            }
        }
        else{
            cout << "Please Enter 1 Or 2 Only" << endl;
            cout << "If You Want To Encrypt Message Enter 1 , And To decrypt Enter 2 : ";
            cin >> response;

        }
    }
}
int main() {
    simple_sbstitution_cipher();
    return 0;
}
