#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include "Telephone_book.hpp"
using namespace std;

Telephone_book::Telephone_book(){
    ifstream fin(path);
    if(!fin.is_open()){
        cout << "Ошибка открытия файла" << endl;
    }
    else{
        cout << "Файл открыт" << endl;
//        char ch;
//        while(fin.get(ch)){
//            cout << ch;
//        }
//        cout << endl;
        if(!fin.eof()){
            size_t size;
            fin.read((char*)&size, sizeof(size_t));
            for(int i = 0; i < size; i++){
                Human human;
                human.read(fin);
                tb.emplace(human.second_name, human);
            }
        }
    }
    fin.close();
}

Telephone_book::~Telephone_book(){
    ofstream fout(path);
    if(!fout.is_open()){
        cout << "Ошибка открытия файла" << endl;
    }
    else{
        cout << "Файл открыт" << endl;
        size_t l = tb.size();
        fout.write((const char*)& l, sizeof(size_t));
        for(auto element : tb){
            element.second.write(fout);
        }
    }
    fout.close();
}

void Telephone_book::Insert(string first_name, string second_name, string third_name, string address, string date_of_birth, string email, vector<string> number){
    Human human(first_name, second_name, third_name, address, date_of_birth, email, number);
    tb.emplace(second_name, human);
}

void Telephone_book::Erase(string second_name){
    for(auto element : tb){
        if(element.second.second_name == second_name){
            tb.erase(element.first);
            break;
        }
    }
}

void Telephone_book::Print_all(){
    for(auto element : tb){
        cout << element.second.second_name << "\t" << element.second.first_name <<
        "\t" << element.second.third_name << "\t" << element.second.address << "\t" << element.second.date_of_birth << "\t" <<
        element.second.email << "\t" << element.second.number << endl;
    }
}

void Telephone_book::Find(string second_name){
    if(tb.find(second_name) != tb.end()){
        cout << tb[second_name];
    }
    else{
        cout << "Данного контакта в телефонной книге нет" << endl;
    }
}

void Telephone_book::Update(string second_name, int ans){
    if(tb.find(second_name) != tb.end()){
        switch (ans) {
            case 1:
            {
                cout << "Введите новое имя контакта:" << endl;
                string first_name;
                cin >> first_name;
                tb[second_name].first_name = first_name;
                break;
            }
            case 2:
            {
                cout << "Введите новую фамилию контакта:" << endl;
                string second_name_2;
                cin >> second_name_2;
                tb[second_name].second_name = second_name_2;
                break;
            }
            case 3:
            {
                cout << "Введите новое отчество контакта:" << endl;
                string third_name;
                cin >> third_name;
                tb[second_name].third_name = third_name;
                break;
            }
            case 4:
            {
                cout << "Введите новый адрес контакта:" << endl;
                string address;
                cin >> address;
                tb[second_name].address = address;
                break;
            }
            case 5:
            {
                cout << "Введите новую дату рождения контакта:" << endl;
                string date_of_birth;
                cin >> date_of_birth;
                tb[second_name].date_of_birth = date_of_birth;
                break;
            }
            case 6:
            {
                cout << "Введите новый email контакта:" << endl;
                string email;
                cin >> email;
                tb[second_name].email = email;
                break;
            }
            case 7:
            {
                string c;
                vector<string> number;
                while(c != "n"){
                    cout << "Введите номер телефона контакта:" << endl;
                    string number_1;
                    cin >> number_1;
                    number.push_back(number_1);
                    cout << "Добавить еще номер? y/n" << endl;
                    cin >> c;
                }
                tb[second_name].number = number;
                break;
            }
            default:
                cout << "Такого поля нет!" << endl;
                break;
        }
    }
    else{
        cout << "Данного контакта в телефонной книге нет" << endl;
    }
}

void Telephone_book::Clear(){
    tb.clear();
}

Human::Human(string first_name, string second_name, string third_name, string address, string date_of_birth, string email, vector<string> number){
    this->first_name = first_name;
    this->second_name = second_name;
    this->third_name = third_name;
    this->address = address;
    this->date_of_birth = date_of_birth;
    this->email = email;
    this->number = number;
}

void Human::writeStr(const string& str, ostream& fout){
    size_t l = str.length();
    fout.write((const char*)& l, sizeof(size_t));
    fout.write(str.data(), l);
}

void Human::readStr(string &str, istream &fin){
    size_t l;
    fin.read((char*)& l, sizeof(size_t));
    char* s = new char[l+1];
    fin.read(s, l);
    str[l] = 0;
    str = s;
    delete[] s;
}

void Human::write(ostream &fout){
    writeStr(first_name, fout);
    writeStr(second_name, fout);
    writeStr(third_name, fout);
    writeStr(address, fout);
    writeStr(date_of_birth, fout);
    writeStr(email, fout);
    size_t l = number.size();
    fout.write((const char*)& l, sizeof(size_t));
    for(int i = 0; i < number.size(); i++){
        writeStr(number[i], fout);
    }
}

void Human::read(istream &fin){
    readStr(first_name, fin);
    readStr(second_name, fin);
    readStr(third_name, fin);
    readStr(address, fin);
    readStr(date_of_birth, fin);
    readStr(email, fin);
    size_t l;
    fin.read((char*)& l, sizeof(size_t));
    for(int i = 0; i < l; i++){
        string tmp;
        readStr(tmp, fin);
        number.push_back(tmp);
    }
}

void Window(){
    cout << "Выберите действие:" << endl;
    cout << "1 - Добавить контакт в телефонную книгу." << endl;
    cout << "2 - Удалить контакт из телефонной книги." << endl;
    cout << "3 - Найти контакт в телефонной книге." << endl;
    cout << "4 - Вывести содержимое телефонной книги." << endl;
    cout << "5 - Изменить информацию о контакте в телефонной книге." << endl;
    cout << "6 - Отчистить телефонную книгу." << endl;
    cout << "7 - Закрыть телефонную книгу." << endl;
}

ostream& operator <<(ostream& os, Human& human){
    return os << human.second_name << "\t" << human.first_name << "\t" << human.third_name << "\t" << human.address << "\t" << human.date_of_birth << "\t" << human.email << "\t" << human.number << endl;
}

ostream& operator <<(ostream& os, vector<string>& number){
    for(int i = 0; i < number.size(); i++){
        os << i+1 << ") " << number[i] << "\t";
    }
    return os;
}


