#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <vector>
using namespace std;

void fake();

void fake2();

int main(int argc, char **argv) {

  int i, encode_key, temp;
  char b, a;
  bool choice = 0, cont_choice = 1;
  ifstream myfile;
  vector<char> rainfall;
  vector<char> rainfall_c;
  

  if (argc > 1) {
    myfile.open(argv[1]);
  } else {
    cout << "Usage: inputfile [Missing Input File]";
    return -1;
  }

    cout << "Encrypting or Decrypting file? [0 = decrypt| 1 = encrypt]  ";
    cin >> choice;

    if (choice) {
        rainfall.clear();
      cout << "KEY to encrypt/decrypt file: [IMPORTANT: DO NOT FORGET KEY]  ";
      cin >> encode_key;
      if (myfile.is_open()) {
        while (myfile >> noskipws >> b) {
          temp = b ^ encode_key;
          char temp_c = (char)temp;
          rainfall.push_back(temp_c);
        }
        myfile.close();      }

      else
        cout << endl << "Unable to open file" << endl;

      ofstream fout;
      fout.open(argv[1]);
      for (i = 0; i < rainfall.size(); i++) {
        fout << rainfall[i];
      }
      rainfall.clear();
      fout.close();
      fake();
    }

    if (!choice) {
        rainfall_c.clear();
      cout << "KEY to encrypt/decrypt file: [IMPORTANT: DO NOT FORGET KEY]  ";
      cin >> encode_key;
      if (myfile.is_open()) {
        while (myfile >> a) {
          temp = a ^ encode_key;
          char temp_c = (char)temp;
          rainfall_c.push_back(temp_c);
        }
        myfile.close();
      }

      else
        cout << "Unable to open file";

      ofstream fout;
      fout.open(argv[1]);
      for (i = 0; i < rainfall_c.size(); i++) {
        fout << rainfall_c[i];
      }
      fout.close();
              rainfall_c.clear();

      fake2();
    }
    cout << endl << endl << endl << endl << endl << endl << endl << "Done, Press any Key to Exit....";
    cin >> cont_choice;
  return 0;
}

void fake() {
  ifstream screengrab("carmike.txt");
  string line;
  bool poo = 1;
  if (poo) {
    if (screengrab) // same as: if (myfile.good())
    {

      while (getline(screengrab,
                     line)) // same as: while (getline( myfile, line ).good())
      {
        cout << line << endl;
        Sleep(1);
      }
      screengrab.close();
    }
  }
}

void fake2() {
  ifstream screengrab("carmike2.txt");
  string line;
  bool poo = 1;
  if (poo) {
    if (screengrab) // same as: if (myfile.good())
    {

      while (getline(screengrab,
                     line)) // same as: while (getline( myfile, line ).good())
      {
        cout << line << endl;
        Sleep(1);
      }
      screengrab.close();
    }
  }
}