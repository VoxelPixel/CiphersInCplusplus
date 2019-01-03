/*********
 -*- Made by VoxelPixel
 -*- For YouTube Tutorial
 -*- https://github.com/VoxelPixel
 -*- Support me on Patreon: https://www.patreon.com/voxelpixel
*********/

#include <iostream>
#include <regex>

using namespace std;

void cipherEncryption(){
    string message;
    cout << "Enter message: ";
    getline(cin , message);
    cin.ignore();

    // removing white space from message
    message = regex_replace(message, regex("\\s+"), "");

    cout << "Enter key(number of rails): ";
    int rails;
    cin >> rails;
    cin.ignore();

    // creating empty matrix
    char railMatrix[rails][message.length()];
    for (int i = 0; i < rails; i++){
        for (int j = 0; j < message.length(); j++){
            railMatrix[i][j] = '.';
        }
    }

    // testing newly created matrix
//    for (int i = 0; i < rails; i++){
//        for (int j = 0; j < message.length(); j++){
//            cout << railMatrix[i][j];
//        }
//        cout << endl;
//    }

    // putting message letters one by one in rail matrix in zig-zag
    int row = 0;
    int check = 0;
    for (int i = 0; i < message.length(); i++){
        if (check == 0){
            railMatrix[row][i] = message[i];
            row++;
            if(row == rails){
                check = 1;
                row--;
            }
        } else if (check == 1){
            row--;
            railMatrix[row][i] = message[i];
            if (row == 0){
                check = 0;
                row = 1;
            }
        } // if-else
    } // for

    // creating encrypted text
    string encrypText = "";
    for (int i = 0; i < rails; i++){
        for (int j = 0; j < message.length(); j++){
//            cout << railMatrix[i][j];
            encrypText += railMatrix[i][j];
        }
//        cout << endl;
    }

    // removing '.' from encrypted Text
    encrypText = regex_replace(encrypText, regex("\\."), "");
    cout << "Encrypted Text: " << encrypText;
}

void ciphetDecryption(){
    string message;
    cout << "Enter message: ";
    getline(cin , message);
    cin.ignore();

    // removing white space from message
    message = regex_replace(message, regex("\\s+"), "");

    cout << "Enter key(number of rails): ";
    int rails;
    cin >> rails;
    cin.ignore();

    // creating empty matrix
    char railMatrix[rails][message.length()];
    for (int i = 0; i < rails; i++){
        for (int j = 0; j < message.length(); j++){
            railMatrix[i][j] = '.';
        }
    }

    // testing newly created matrix
//    for (int i = 0; i < rails; i++){
//        for (int j = 0; j < message.length(); j++){
//            cout << railMatrix[i][j];
//        }
//        cout << endl;
//    }

    // putting message letters one by one in rail matrix in zig-zag
    int row = 0;
    int check = 0;
    for (int i = 0; i < message.length(); i++){
        if (check == 0){
            railMatrix[row][i] = message[i];
            row++;
            if(row == rails){
                check = 1;
                row--;
            }
        } else if (check == 1){
            row--;
            railMatrix[row][i] = message[i];
            if (row == 0){
                check = 0;
                row = 1;
            }
        } // if-else
    } // for

    // reordering rails
    int ordr = 0;
    for (int i = 0; i < rails; i++){
        for (int j = 0; j < message.length(); j++){
            string temp = "";
            temp += railMatrix[i][j];
            if(regex_match(temp, regex("\\."))){
                // skipping '.'
                continue;
            } else {
                // adding cipher letters one by one diagonally
                railMatrix[i][j] = message[ordr];
                ordr++;
            } // if-else
        } // inner for
    } // for

    // testing reordering
//    for (int i = 0; i < rails; i++){
//        for (int j = 0; j < message.length(); j++){
//            cout << railMatrix[i][j];
//        }
//        cout << endl;
//    }

    // converting rows back into a message of single line
    string decrypText = "";
    check = 0;
    row = 0;
    for (int i = 0; i < message.length(); i++){
        if (check == 0){
            decrypText += railMatrix[row][i];
            row++;
            if (row == rails){
                check = 1;
                row--;
            }
        } else if (check == 1){
            row--;
            decrypText += railMatrix[row][i];
            if (row == 0){
                check = 0;
                row = 1;
            }
        } // if else
    } // for

    // removing '.' from decrypted text
    decrypText = regex_replace(decrypText, regex("\\.+"), "");
    cout << "Decrypted Text: " << decrypText;
}

int main()
{
    cout << "1. Encryption\n2. Decryption\nChoose(1,2): ";
    int choice;
    cin >> choice;
    cin.ignore();

    if (choice == 1){
        cout << endl << "Encryption" << endl;
        cipherEncryption();

    } else if (choice == 2) {
        cout << endl << "Decryption" << endl;
        ciphetDecryption();

    } else {
        cout << endl << "Invalid Choice" << endl;
    }

    return 0;
}
