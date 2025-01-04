#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
struct Human{
    string first_name;
    string second_name;
    string third_name;
    string address;
    string date_of_birth;
    string email;
    vector<string> number;
    
    Human(string first_name = "", string second_name = "", string third_name = "", string address = "", string date_of_birth = "", string email = "", vector<string> number = {});
    void writeStr(const string& str, ostream& fout);
    void readStr(string& str, istream& fin);
    void write(ostream& fout);
    void read(istream& fin);
};

class Telephone_book{
public:
    Telephone_book();
    ~Telephone_book();
    void Insert(string first_name, string second_name, string third_name, string address, string date_of_birth, string email, vector<string> number);
    void Erase(string second_name);
    void Print_all();
    void Find(string second_name);
    void Update(string second_name, int ans);
    void Clear();
private:
    map<string, Human> tb;
    string path = "/Users/ilya/Documents/kusrsach/Myfile.txt";
};

void Window();

ostream& operator <<(ostream& os, Human& human);

ostream& operator <<(ostream& os, vector<string>& number);
