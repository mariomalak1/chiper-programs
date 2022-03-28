#include <iostream>
using namespace std;
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
    string message, enc_message , first , second , third;
    cout <<"Please enter your message : " << endl;
    getline(cin, message);
    message = cut_spaces9(message);
    first = first_sen9(message);
    second = second_sen9(message);
    third = third_sen9(message);
    enc_message = encrypt_message9(first , second , third);
    cout << enc_message << endl;
}
int main() {
    rail_fence();
    return 0;
}