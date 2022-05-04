#include<iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <cstring>
#include <string>
# include <bits/stdc++.h>
#include <map>
using namespace std;

// code of all Cipher here

// all functions and variables of Affine_Cipher 0
int a0 = 0,b0 = 0, c0 = 0;
string massage0;
void check_validity0(int num)
{
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(256,'\n');
        cout<<"Please enter an integer:\n";
        cin>>num;
    }
}
int display_choices0 ()
{
    int choice;
    cout<<"Ahlan User ya user ya habibi.\n";
    cout<<"What do you like to do today?\n";
    cout<<"1- Cipher a message\n"
          "2- Decipher a message\n"
          "3- End\n"
          "Please enter 1 or 2 or 3:\n";
    // Get the choice from the user
    cin>>choice;
    while (cin.fail() or (choice>3 or choice <1) )
    {
        cin.clear();
        cin.ignore(256,'\n');
        cout<<"Please enter 1 or 2 or 3:\n";
        cin>>choice;
    }

    return choice;
}
void get_parameters0 ()
{
    cout<<"Please enter the parameters of cipher and decipher a and b and c:\n "
          "(a * b) mod 26 should equal 1\n";
    // Get the parameters
    while ((a0 * c0) % 26 != 1)
    {
        cout<<"Please Enter the a:\n";
        cin>>a0 ;
        check_validity0(a0);
        cout<<"Please Enter the b:\n";
        cin>>b0 ;
        check_validity0(b0);
        cout<<"Please Enter the c:\n";
        cin>>c0;
        check_validity0(c0);
    }

}
void cipher0 ()
{
    int length = massage0.length();
    for (int i=0; i<length; i++)
    {
        if (massage0[i] >= 'a' and massage0[i] <='z')
        {
            int x = int(massage0[i] % 97);
            massage0[i] = char((a0 *x + b0) % 26 + 97);
        }
        if (massage0[i]>= 'A' and massage0[i] <='Z')
        {
            int x = int(massage0[i] % 65);
            massage0[i] = char((a0 *x + b0) % 26 + 65);
        }
    }
    cout<<"The deciphered message is:   "<<massage0<<endl;
}
void decipher0 ()
{
    int length = massage0.length();
    for (int i=0; i<length; i++)
    {
        if (massage0[i]>= 'a' and massage0[i] <='z')
        {
            int y = int(massage0[i] % 97);
            massage0[i] = char((c0 *(y- b0) % 26 + 26) % 26 + 97);
        }
        if (massage0[i]>= 'A' and massage0[i] <='Z')
        {
            int y = int(massage0[i] % 65);
            massage0[i] = char((c0 *(y-b0) % 26 + 26) % 26 + 65);

        }
    }
    cout<<"The deciphered message is:   "<<massage0<<endl;
}
void Affine_Cipher()
{
    int choice = display_choices0();
    if (choice == 1)
    {
        cout<<"Please enter the massage to cipher:\n";
        while (massage0.empty())
            getline(cin,massage0);
        get_parameters0();
        cipher0();
    }
    else if (choice == 2)
    {
        cout<<"Please enter the massage to decipher:\n";
        while (massage0.empty())
        {
            getline(cin,massage0);
        }
        get_parameters0();
        decipher0();
    }
    else if (choice == 3)
    {
        cout<<"end of cipher " << endl;
    }

}
// end of Affine_Cipher 0

// all functions and variables of Caesar_Cipher 1
string massage1, dir_shift1;
int shift1;
int display_choices1 ()
{
    int choice;
    cout<<"Ahlan User ya user ya habibi.\n";
    cout<<"What do you like to do today?\n";
    cout<<"1- Cipher a message\n"
          "2- Decipher a message\n"
          "3- End\n"
          "Please enter 1 or 2 or 3:\n";
    // Get the choice from the user
    cin>>choice;
    while (cin.fail() or (choice>3 or choice <1) )
    {
        cin.clear();
        cin.ignore(256,'\n');
        cout<<"Please enter 1 or 2 or 3:\n";
        cin>>choice;
    }

    return choice;
}
void get_shift1 ()
{
    cout<<"Please enter the direction of cipher or decipher:\n "
          "enter '+' if the shift from the right\n "
          "enter '-' if the shift from the left\n ";

    // Get right or left
    getline(cin,dir_shift1);

    //check that the dir_shift is '-' or '-'
    while (dir_shift1 != "+" and dir_shift1 != "-")
    {
        cout<<"Please enter '+' or '-' only:\n";
        getline(cin,dir_shift1);
    }
    // Get the number of shifts
    cout<<"Please enter the number of shifts:\n";
    cin>>shift1;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(256,'\n');
        cout<<"Please enter an integer:\n";
        cin>>shift1;
    }
    // Modify the number of shifts
    if (fabs(shift1) > 26)
        shift1 = shift1 % 26;
    if (shift1 < 0)
        shift1 += 26;
}
void cipher1 ()
{
    int length = massage1.length();
    if (dir_shift1 == "+")
    {
        for (int i=0; i<length; i++)
        {
            if (massage1[i]>= 'a' and massage1[i] <='z')
            {
                if (char(int(massage1[i]) + shift1)>= 'a' and char(int(massage1[i]) + shift1) <='z')
                    massage1[i] = char(int(massage1[i]) + shift1);
                else
                    massage1[i] = char(int(massage1[i]) + shift1 - 26);
            }
            if (massage1[i]>= 'A' and massage1[i] <='Z')
            {
                if (char(int(massage1[i]) + shift1)>= 'A' and char(int(massage1[i]) + shift1) <='Z')
                    massage1[i] = char(int(massage1[i]) + shift1);
                else
                    massage1[i] = char(int(massage1[i]) + shift1 - 26);
            }
        }
    }
    else if (dir_shift1 == "-")
    {
        for (int i=0; i<length; i++)
        {
            if (massage1[i]>= 'a' and massage1[i] <='z')
            {
                if (char(int(massage1[i]) - shift1)>= 'a' and char(int(massage1[i]) - shift1) <='z')
                    massage1[i] = char(int(massage1[i]) - shift1);
                else
                    massage1[i] = char(int(massage1[i]) - shift1 + 26);
            }
            if (massage1[i]>= 'A' and massage1[i] <='Z')
            {
                if (char(int(massage1[i]) - shift1)>= 'A' and char(int(massage1[i]) - shift1) <='Z')
                    massage1[i] = char(int(massage1[i]) - shift1);
                else
                    massage1[i] = char(int(massage1[i]) - shift1 + 26);
            }
        }
    }
    cout<<"The ciphered message is:    "<<massage1<<endl;

}
void decipher1 ()
{
    int length = massage1.length();
    if (dir_shift1 == "+")
    {
        for (int i=0; i<length; i++)
        {
            if (massage1[i]>= 'a' and massage1[i] <='z')
            {
                if (char(int(massage1[i]) - shift1)>= 'a' and char(int(massage1[i]) - shift1) <='z')
                    massage1[i] = char(int(massage1[i]) - shift1);
                else
                    massage1[i] = char(int(massage1[i]) - shift1 + 26);
            }

            if (massage1[i]>= 'A' and massage1[i] <='Z')
            {
                if (char(int(massage1[i]) - shift1)>= 'A' and char(int(massage1[i]) - shift1) <='Z')
                    massage1[i] = char(int(massage1[i]) - shift1);
                else
                    massage1[i] = char(int(massage1[i]) - shift1 + 26);
            }
        }
    }
    else if (dir_shift1 == "-")
    {
        for (int i=0; i<length; i++)
        {
            if (massage1[i]>= 'a' and massage1[i] <='z')
            {
                if (char(int(massage1[i]) + shift1)>= 'a' and char(int(massage1[i]) + shift1) <='z')
                    massage1[i] = char(int(massage1[i]) + shift1);
                else
                    massage1[i] = char(int(massage1[i]) + shift1 - 26);
            }
            if (massage1[i]>= 'A' and massage1[i] <='Z')
            {
                if (char(int(massage1[i]) + shift1)>= 'A' and char(int(massage1[i]) + shift1) <='Z')
                    massage1[i] = char(int(massage1[i]) + shift1);
                else
                    massage1[i] = char(int(massage1[i]) + shift1 - 26);
            }
        }
    }
    cout<<"The deciphered message is:   "<<massage1<<endl;
}
void Caesar_Cipher()
{
    int choice = display_choices1();
    if (choice == 1)
    {
        cout<<"Please enter the massage to cipher:\n";
        while (massage1.empty())
        {
            getline(cin,massage1);
        }
        get_shift1();
        cipher1();
    }
    else if (choice == 2)
    {
        cout<<"Please enter the massage to decipher:\n";
        while (massage1.empty())
        {
            getline(cin,massage1);
        }
        get_shift1();
        decipher1();
    }
    else if (choice == 3)
    {
        cout<<"end of cipher " << endl;
    }
}
// end of Caesar_Cipher 1

// all functions and variable of Atbash_Cipher 2
string massage2;
int display_choices2()
{
    int choice;
    cout<<"Ahlan User ya user ya habibi.\n";
    cout<<"What do you like to do today?\n";
    cout<<"1- Cipher a message\n"
          "2- Decipher a message\n"
          "3- End\n"
          "Please enter 1 or 2 or 3:\n";
    // Get the choice from the user
    cin>>choice;
    while (cin.fail() or (choice>3 or choice <1) )
    {
        cin.clear();
        cin.ignore(256,'\n');
        cout<<"Please enter 1 or 2 or 3:\n";
        cin>>choice;
    }

    return choice;
}
void cipher2 ()
{
    int length = massage2.length();
    for (int i=0; i<length; i++)
    {
        if (massage2[i]>= 'a' and massage2[i] <='z')
        {
            int x = int(massage2[i]) % 97;
            massage2[i] = char(122 - x);
        }
        if (massage2[i]>= 'A' and massage2[i] <='Z')
        {
            int x = int(massage2[i]) % 65;
            massage2[i] = char(90 - x);
        }
    }
    cout<<"The deciphered message is:   "<<massage2<<endl;
}
void decipher2 ()
{
    int length = massage2.length();
    for (int i=0; i<length; i++)
    {
        if (massage2[i]>= 'a' and massage2[i] <='z')
        {
            int x = int(massage2[i]) % 97;
            massage2[i] = char(122 - x);
        }
        if (massage2[i]>= 'A' and massage2[i] <='Z')
        {
            int x = int(massage2[i]) % 65;
            massage2[i] = char(90 - x);
        }
    }
    cout<<"The deciphered message is:   "<<massage2<<endl;
}
void Atbash_Cipher()
{
    int choice = display_choices2();
    if (choice == 1)
    {
        cout<<"Please enter the massage to cipher:\n";
        while (massage2.empty())
            getline(cin,massage2);
        cipher2();
    }
    else if (choice == 2)
    {
        cout<<"Please enter the massage to decipher:\n";
        while (massage2.empty())
        {
            getline(cin,massage2);
        }
        decipher2();
    }
    else if (choice == 3)
    {
        cout<<"end of cipher " << endl;
    }

}
// end of Atbash_Cipher 2

// all functions of vignere_cipher 3
char encrypted_character3(int nAscii ){
    char enc_character;
    enc_character = ((nAscii % 26) + 'A');
    return enc_character;
}
// function to make the keyword is upper case only
string upper_case3(string str){
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
                        message = upper_case3(message);
                        keyword = keyword_adjust3(upper_case3(keyword) , message.length());
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
                        message = upper_case3(message);
                        keyword = keyword_adjust3(upper_case3(keyword) , message.length());
                        cout << description_message3(message , keyword) << endl;
                        cin.ignore();
                        break;
                    }
                }
            }
        }
        else if (response == "3"){
            isRun = false;
            cout<<"end of cipher " << endl;
        }
        else{
            cout << "Please Enter 1 Or 2 Or 3 Only" << endl;
            cin.ignore();
            response_print();
        }
    }
}
// end of vignere_cipher 3

// functions of Baconian_Cipher 4
string upper_case4(string str){
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
    cout << "If You Want To Encrypt Message Enter 1 , And To decrypt Enter 2, And To Quit Enter 3 : ";
    cin >> response;
    while (true){
        if (response == "3"){
            cout<<"end of cipher " << endl;
            break;
        }
        if ((response == "1" ) or (response == "2" )){
            if (response == "1"){
                while (true) {
                    cout << "Enter Your Message : ";
                    cin >> message ;
                    message = upper_case4(message);
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
            cout << "Please Enter 1 Or 2 or 3 only " << endl;
            cout << "If You Want To Encrypt Message Enter 1 , And To decrypt Enter 2, if you want to quit cipher enter 3 :  ";
            cin >> response;

        }
    }
}
// end of Baconian_Cipher 4

// functions of simple_sbstitution_cipher 5
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
    cout << "If You Want To Encrypt Message Enter 1 , And To decrypt Enter 2, And To Quit Enter 3 : ";
    cin >> response;
    while (true){
        if (response == "3"){
            cout<<"end of cipher "<< endl;
            break;
        }
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
// end of simple_sbstitution_cipher 5

// all functions and variables of polybius_square_cipher 6
int a, b, c, d, e, choose;
char n1, n2, n3, n4, n5;
string word, wordd;
void encryption_function6(){

    // here the user input the numbers in order he want
    cout<<"please enter the numbers: ";
    cin>>a>>b>>c>>d>>e;
    // print the table with numbers that the user enter
    cout<<" "<<"|"<<a<<"|"<<b<<"|"<<c<<"|"<<" "<<d<<" "<<"|"<<e<<endl;
    cout<<a<<"|"<<"A"<<"|"<<"B"<<"|"<<"C"<<"|"<<" "<<"D"<<" "<<"|"<<"E"<<endl;
    cout<<b<<"|"<<"F"<<"|"<<"G"<<"|"<<"H"<<"|"<<"I"<<"/"<<"J"<<"|"<<"K"<<endl;
    cout<<c<<"|"<<'L'<<"|"<<"M"<<'|'<<'N'<<'|'<<" "<<'O'<<" "<<'|'<<'P'<<endl;
    cout<<d<<'|'<<'Q'<<'|'<<'R'<<'|'<<'S'<<'|'<<" "<<'T'<<" "<<'|'<<'U'<<endl;
    cout<<e<<'|'<<'V'<<'|'<<'W'<<'|'<<'X'<<'|'<<" "<<'Y'<<" "<<'|'<<'Z'<<endl;


    cout<<"please enter the word you want to encrypt: ";
    cin.ignore();
    getline(cin, word);

    for (int i = 0; i < word.length(); i++)
    {
        switch (word.at(i))
        {
            case ' ': cout<<' ';
                break;
            case 'a': cout<<a<<a;
                break;
            case 'b': cout<<b<<a;
                break;
            case 'c': cout<<c<<a;
                break;
            case 'd': cout<<d<<a;
                break;
            case 'e': cout<<e<<a;
                break;
            case 'f': cout<<a<<b;
                break;
            case 'g': cout<<b<<b;
                break;
            case 'h': cout<<c<<b;
                break;
            case 'i': cout<<d<<b;
                break;
            case 'j': cout<<d<<b;
                break;
            case 'k': cout<<e<<b;
                break;
            case 'l': cout<<a<<c;
                break;
            case 'm': cout<<b<<c;
                break;
            case 'n': cout<<c<<c;
                break;
            case 'o': cout<<d<<c;
                break;
            case 'p': cout<<e<<c;
                break;
            case 'q': cout<<a<<d;
                break;
            case 'r': cout<<b<<d;
                break;
            case 's': cout<<c<<d;
                break;
            case 't': cout<<d<<d;
                break;
            case 'u': cout<<e<<d;
                break;
            case 'v': cout<<a<<e;
                break;
            case 'w': cout<<b<<e;
                break;
            case 'x': cout<<c<<e;
                break;
            case 'y': cout<<d<<e;
                break;
            case 'z': cout<<e<<e;
                break;

        }

    }

}
void decryption_function6(){
    // here the user input the numbers in order he want
    cout<<"please enter the numbers: ";
    cin>>n1>>n2>>n3>>n4>>n5;
    // print the table with numbers that the user enter
    cout<<" "<<"|"<<n1<<"|"<<n2<<"|"<<n3<<"|"<<n4<<"|"<<n5<<endl;
    cout<<n1<<"|"<<"A"<<"|"<<"B"<<"|"<<"C"<<"|"<<"D"<<"|"<<"E"<<endl;
    cout<<n2<<"|"<<"F"<<"|"<<"G"<<"|"<<"H"<<"|"<<"I"<<"|"<<"K"<<endl;
    cout<<n3<<"|"<<'L'<<"|"<<"M"<<'|'<<'N'<<'|'<<'O'<<'|'<<'P'<<endl;
    cout<<n4<<'|'<<'Q'<<'|'<<'R'<<'|'<<'S'<<'|'<<'T'<<'|'<<'U'<<endl;
    cout<<n5<<'|'<<'V'<<'|'<<'W'<<'|'<<'X'<<'|'<<'Y' <<'|'<<'Z'<<endl;

    char table[6][6] = {
            {' ',n1,n2,n3,n4,n5},
            {n1,'A','B','C','D','E'},
            {n2,'F','G','H','I','K'},
            {n3,'L','M','N','O','P'},
            {n4,'Q','R','S','T','U'},
            {n5,'V','W','X','Y','Z'}
    };

    cout<<"please enter the word you want to decrypt: ";
    cin.ignore();
    getline(cin, wordd);
    string decoded_word = "";
    for(int i=0;i<wordd.length();i+=2){
        for (int j = 0; j < 6; j++){
            for (int k = 0; k < 6; k++){
                if (wordd[i] == table[j][0])
                {
                    int column = j;
                    if (wordd[i+1] == table[0][k])
                    {
                        int row = k;
                        decoded_word += table[row][column];
                    }

                }


            }

        }

    }
    cout<<"the decoded word is "<<decoded_word;

}
void polybius_square_cipher(){
    while(true) {
        cout << "If You Want To Encrypt Message Enter 1 , And To decrypt Enter 2, And To Quit Enter 3 : ";
        cin >> choose;
        if (choose == 1) {
            encryption_function6();
        } else if (choose == 2) {
            decryption_function6();
        }
        else if (choose == 3){
            cout<<"end of cipher " << endl;
            break;
        }
        else{
            cout << "please enter 1 or 2 or 3 " << endl;
            cin.ignore();
        }
    }
}
// end of polybius_square_cipher 6

// all functions and variables of morse_code 7
void decryption(){
    map <string,char> decoding{
            {".-",'a'},
            {"-...",'b'},
            {"-.-.",'c'},
            {"-..",'d'},
            {".",'e'},
            {"..-.",'f'},
            {"--.",'g'},
            {"....",'h'},
            {"..",'i'},
            {".---",'j'},
            {"-.-",'k'},
            {".-..",'l'},
            {"--",'m'},
            {"-.",'n'},
            {"---",'o'},
            {".--.",'p'},
            {"--.-",'q'},
            {".-.",'r'},
            {"...",'s'},
            {"-",'t'},
            {"..-",'u'},
            {"...-",'v'},
            {".--",'w'},
            {"-..-",'x'},
            {"-.--",'y'},
            {"--..",'z'}
    };

    string word, wrd, decoded;
    cout<<"enter the word you want to decrypt: ";
    cin.ignore();
    getline(cin, word);
    word += ' ';
    decode_loop:
    for (int i = 0; i < word.length(); i++)
    {
        if (word[i] != ' ')
        {
            wrd.push_back(word[i]);
        }
        else if (word[i] == ' ')
        {
            for ( auto iter = decoding.begin(); iter != decoding.end(); iter++)
            {
                string key = iter ->first;
                char value = iter ->second;
                if (decoding.find(wrd) != decoding.end())
                {
                    if (wrd == key)
                    {
                        decoded.push_back(value);
                        wrd.clear();
                        break;
                    }

                }

            }
            if (int(char(word[i])) == 32 && int(char(word[i+1])) == 32 && int(char(word[i+2])) == 32)
            {
                decoded.push_back(' ');
            }


        }


    }
    cout<<" the decrypted word is "<< decoded;

}
void encryption(){
    string word;
    cout<<"please enter the word you want to encrypt: ";
    cin.ignore();
    getline(cin, word);

    for (int i = 0; i < word.length(); i++)
    {
        switch (word[i])
        {
            case ' ': cout<<' '<<' ';
                break;
            case 'a': cout<<".-"<<' ';
                break;
            case 'b': cout<<"-..."<<' ';
                break;
            case 'c': cout<<"-.-."<<' ';
                break;
            case 'd': cout<<"-.."<<' ';
                break;
            case 'e': cout<<"."<<' ';
                break;
            case 'f': cout<<"..-."<<' ';
                break;
            case 'g': cout<<"--."<<' ';
                break;
            case 'h': cout<<"...."<<' ';
                break;
            case 'i': cout<<".."<<' ';
                break;
            case 'j': cout<<".---"<<' ';
                break;
            case 'k': cout<<"-.-"<<' ';
                break;
            case 'l': cout<<".-.."<<' ';
                break;
            case 'm': cout<<"--"<<' ';
                break;
            case 'n': cout<<"-."<<' ';
                break;
            case 'o': cout<<"---"<<' ';
                break;
            case 'p': cout<<".--."<<' ';
                break;
            case 'q': cout<<"--.-"<<' ';
                break;
            case 'r': cout<<".-."<<' ';
                break;
            case 's': cout<<"..."<<' ';
                break;
            case 't': cout<<"-"<<' ';
                break;
            case 'u': cout<<"..-"<<' ';
                break;
            case 'v': cout<<"...-"<<' ';
                break;
            case 'w': cout<<".--"<<' ';
                break;
            case 'x': cout<<"-..-"<<' ';
                break;
            case 'y': cout<<"-.--"<<' ';
                break;
            case 'z': cout<<"--.."<<' ';
                break;
            case '1': cout<<".----"<<' ';
                break;
            case '2': cout<<"..---"<<' ';
                break;
            case '3': cout<<"...--"<<' ';
                break;
            case '4': cout<<"....-"<<' ';
                break;
            case '5': cout<<"....."<<' ';
                break;
            case '6': cout<<"-...."<<' ';
                break;
            case '7': cout<<"--..."<<' ';
                break;
            case '8': cout<<"---.."<<' ';
                break;
            case '9': cout<<"----."<<' ';
                break;
            case '0': cout<<"-----"<<' ';
                break;
            case '.': cout<<".-.-.-"<<' ';
                break;
            case ',': cout<<"--..--"<<' ';
                break;
            case '?': cout<<"..--.."<<' ';
                break;
        }
    }




}
void morse_code(){
    int choose;
    while(true) {
        cout << "If You Want To Encrypt Message Enter 1 , And To decrypt Enter 2, And To Quit Enter 3 : ";
        cin >> choose;
        if (choose == 1) {
            encryption();
        } else if (choose == 2){
            decryption();
        } else if (choose == 3){
            cout<<"end of cipher " << endl;
            break;
        }
        else{
            cout << "please enter 1 or 2 or 3" << endl;
            cin.ignore();
        }
    }
}
// end of morse_code 7


// all functions and variables of Xor_cipher 8
string massage8;
char key8;
int display_choices8 ()
{
    int choice;
    cout<<"Ahlan User ya user ya habibi.\n";
    cout<<"What do you like to do today?\n";
    cout<<"1- Cipher a message\n"
          "2- Decipher a message\n"
          "3- End\n"
          "Please enter 1 or 2 or 3:\n";
    // Get the choice from the user
    cin>>choice;
    while (cin.fail() or (choice>3 or choice <1) )
    {
        cin.clear();
        cin.ignore(256,'\n');
        cout<<"Please enter 1 or 2 or 3:\n";
        cin>>choice;
    }

    return choice;
}
void get_key ()
{
    cout<<"Please enter the secret key:\n";
    cin>>key8;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(256,'\n');
        cout<<"Enter a valid key";
        cin>>key8;
    }
    cin.clear();
    cin.ignore(256,'\n');
}
void cipher8 ()
{
    int length = massage8.size();
    for (int i=0; i<length; i++)
        massage8[i] = massage8 [i] xor key8;

    cout<<"The ciphered massage is: "<<massage8<<endl;

    // Print Hexa Values
    cout<<"Hexa Values: ";
    for (int i=0; i<length; i++)
        printf("%02x", (unsigned char) massage8[i]);
    cout<<endl;

}
void decipher8 ()
{
    int length = massage8.size();
    for (int i=0; i<length; i++)
        massage8[i] = massage8 [i] xor key8;

    cout<<"The ciphered massage is: "<<massage8<<endl;

    // Print Hexa Values
    cout<<"Hexa Values: ";
    for (int i=0; i<length; i++)
        printf("%02x", (unsigned char) massage8[i]);
    cout<<endl;
}
void Xor_cipher ()
{
    int choice = display_choices8();
    if (choice == 1)
    {
        get_key ();
        cout<<"Please enter the massage to cipher:\n";
        while (massage8.empty())
            getline(cin,massage8);
        cipher8();
    }
    else if (choice == 2)
    {
        get_key ();
        cout<<"Please enter the massage to decipher:\n";
        while (massage8.empty())
        {
            getline(cin,massage8);
        }
        decipher8();
    }
    else if (choice == 3)
    {
        cout<<"end of cipher " << endl;
    }

}
// end of Xor_cipher 8

// functions of rail_fence 9
string cut_spaces9(string message, string str = ""){
    for(int i = 0; i < message.length(); i++){
        if (message[i] == ' '){
            continue;
        }
        else{
            str += message[i];
        }
    }
    return str;
}
string first_sen9(string message , string first_mes1 = "", string first_mes2 = "", int reminder = 0 ){
    reminder = message.length() - 1;
    for(int i =0; i < 1000; i++){
        if (reminder < 4){
            break;
        }
        else{
            reminder -= 4;
        }
    }
    for(int i = 0; i <= (message.length() - reminder) ;){
        first_mes1 += message[i];
        i += 4;
    }
    for(int i = 0; i < first_mes1.length(); i++){
        first_mes2 += first_mes1[i];
        for(int j = 0; j < 3 ; j++){
            first_mes2 += '*';
        }
    }
    first_mes1 = "";
    for(int i = 0; i < (first_mes2.length() - 3); i++){
        first_mes1 += first_mes2[i];
    }
    return first_mes1;
}
string second_sen9(string message , string second_mes = ""){
    for(int i = 0; i < message.length(); i++){
        if (!((i % 2) == 0)){
            second_mes += message[i];
        }
        else{
            second_mes += '*';
        }
    }
    return second_mes;
}
string third_sen9(string message, string third_mes = "" , string third_mes2 = ""){
    for(int i = 2; i < message.length();){
        third_mes += message[i];
        i += 4;
    }
    third_mes2 += "**";
    for(int i = 0; i < third_mes.length(); i++){
        third_mes2 += third_mes[i];
        for (int j = 0; j < 3; ++j) {
            third_mes2 += '*';
        }
    }
    third_mes = "";
    for(int i = 0; i < message.length(); i++){
        third_mes += third_mes2[i];
    }
    return third_mes;
}
string encrypt_message9(string first, string second, string third, string fourth = "" , string enc_mes = ""){
    fourth = first + second + third;
    for (int i = 0; i < fourth.length(); i++){
        if(fourth[i] == '*'){
            continue;
        }
        else{
            enc_mes += fourth[i];
        }
    }
    return enc_mes;
}
void rail_fence(){
    char response;
    cout << "If You Want To Encrypt Message Enter 1, And To Quit Enter 3 : ";
    cin >> response;
    while(true) {
        if (response == '1') {
            string message, enc_message, first, second, third;
            cout << "Please enter your message : " << endl;
            getline(cin, message);
            message = cut_spaces9(message);
            first = first_sen9(message);
            second = second_sen9(message);
            third = third_sen9(message);
            enc_message = encrypt_message9(first, second, third);
            cout << enc_message << endl;
        }
        else if(response == '2'){
            cout<<"end of cipher " << endl;
            break;
        }
        else{
            cout << "please enter 1 or 2" << endl;
            cin.ignore();
        }
    }
}
// end of rail_fence 9

// main functions of all Cipher
void all_Cipher() {
    string response;
    cout << "please enter numbers from 1 to 10 only to encrypt or decrypt a message " << endl;
    cout << "Affine Cipher --> 1 " << endl;
    cout << "Caesar Cipher --> 2 " << endl;
    cout << "Atbash Cipher  --> 3" << endl;
    cout << "Vignere Cipher  --> 4" << endl;
    cout << " Baconian Cipher  --> 5" << endl;
    cout << "Simple Substitution Cipher  --> 6" << endl;
    cout << " Polybius Square Cipher  --> 7" << endl;
    cout << "  Morse Code  --> 8" << endl;
    cout << "  XOR Cipher  --> 9" << endl;
    cout << "  Rail-fence Cipher  --> 10" << endl;
    cout << "if you want to end the program --> 0" << endl;
    while (true) {
        cout << "Enter Number of cipher that you want : ";
        cin >> response;
        if (response == "0") {
            cout << "End of the program thank you " << endl;
            break;
        } else if (response == "1") {
            Affine_Cipher();
        } else if (response == "2") {
            Caesar_Cipher();
        } else if (response == "3") {
            Atbash_Cipher();
        } else if (response == "4") {
            vignere_cipher();
        } else if (response == "5") {
            Baconian_Cipher();
        } else if (response == "6") {
            simple_sbstitution_cipher();
        } else if (response == "7") {
            polybius_square_cipher();
        } else if (response == "8") {
            morse_code();
        } else if (response == "9") {
            Xor_cipher();
        } else if (response == "10") {
            rail_fence();
        } else {
            cout << "please enter from 0 to 10 only " << endl;
            cin.ignore();
        }
    }
}
int main(){
    all_Cipher();
    return 0;
}