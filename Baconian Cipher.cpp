#include<iostream>
#include <string>
#include <cmath>
using namespace std;
string upper_case(string str){
    for (auto & c: str) c = toupper(c);
    return str;
}
string decToBinary4(int n , string nbinary = "")
{
    // array to store binary number
    int binaryNum[32];

    // counter for binary array
    int i = 0;
    while (n > 0) {

        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--){
        nbinary += to_string(binaryNum[j]);}
    return nbinary;

}
string get_encrypted_char_binary4(char char_message, string encrypted_char = "" , string encrypted_char_all  = "" ,int counter = 0, int binary_code = 00000){
    char_message -= 65;
    encrypted_char = decToBinary4((int)char_message);
    if (encrypted_char.length() == 0){
        counter = 5;
    }
    else if (encrypted_char.length() == 5){
        counter = 0;
    }
    else {
        counter = 5 - (encrypted_char.length());
    }
    while (counter > 0){
        encrypted_char_all += "0";
        counter --;
    }
    encrypted_char_all += encrypted_char;
    if (encrypted_char_all.length() == 4){
        encrypted_char_all += "0";
    }
    return encrypted_char_all;
}
string encrypted_char4(string binary_enc_char, string enc_char = ""){
    for (int i = 0; i < (binary_enc_char.length()); i++){
        if(binary_enc_char[i] == '0'){
            enc_char += 'a';
        }
        else if(binary_enc_char[i] == '1'){
            enc_char += 'b';
        }
    }

    return enc_char;
}
string encrypted_message4(string message ,string enc_message = "" , string enc_char_binary = ""){
    for (int i =0; i < message.length() ; i++) {
        if ((message[i] >= 65) or (message[i] <= 90)) {
            enc_char_binary = get_encrypted_char_binary4(message[i]);
            enc_message += (encrypted_char4(enc_char_binary));
        }
        else{
            enc_message += message[i];
        }
    }
    return enc_message;
}
string get_decrypted_char_binary4(string enc_char , string binary_char = ""){
    for(int i = 0 ; i <= 4 ; i++){
        if (enc_char[i] == 'a'){
            binary_char += "0";
        }
        else if (enc_char[i] == 'b'){
            binary_char += "1";
        }
        else{
            cout << "please enter valid message "<< endl;
            cout << "enc_char[i] " << enc_char[i] << endl;
            break;
        }
    }
    return binary_char;
}
int binaryToDec(long long n) {
    int dec = 0, i = 0, rem;
    while (n!=0) {
        rem = n % 10;
        n /= 10;
        dec += rem * pow(2, i);
        ++i;
    }
    return dec;
}
int get_dec_from_binary4(string binary_char , int dec_num = 0){
    dec_num = binaryToDec(stoi(binary_char));
    return dec_num;
}
char decrypted_char4(int dec_num , char dec_char = ' '){
    dec_num += 65;
    dec_char = dec_num;
    return dec_char;
}
string decrypted_message4(string encrypted_message , string enc_char = "" , string dec_message = "" , int counter = 0 , int counter2 = -5, char dec_char = ' '){
    while(counter <= encrypted_message.length() - 1) {
        for (int i = counter; i <= counter + 4; i++) {
            enc_char += encrypted_message[i];
        }
        enc_char = get_decrypted_char_binary4(enc_char);
        dec_char = decrypted_char4(get_dec_from_binary4(enc_char));
        dec_message += dec_char;
        dec_char = ' ';
        enc_char = "";

        // avoid
        counter += 5;
    }
    return dec_message;
}

[[noreturn]] void Baconian_Cipher(){
    string response , message;
    cout << "If You Want To Encrypt Message Enter 1 , And To decrypt Enter 2 : ";
    cin >> response;
    while (true){
        if ((response == "1" ) or (response == "2" )){
            if (response == "1"){
                while (true) {
                    cout << "Enter Your Message : ";
                    cin >> message ;
                    message = upper_case(message);
                    cout << encrypted_message4(message) << endl;
                    break;
                }
                break;
            }
            else{
                while (true) {
                    cout << "Enter Your Message To Decrypt : ";
                    cin.ignore();
                    getline(cin , message);
                    for (int i = 0 ; i < message.length(); i++){
                        if ((message[i] != 'a') or (message[i] != 'b')){
                            cout << "please enter valid message to decrypted " << endl;
                            cout << "message[i]" << message[i] << endl;
                            break;
                        }
                        else{
                            cout << decrypted_message4(message) << endl;
                            break;
                        }
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
int main(){
    Baconian_Cipher();
    return 0;
}