#include <iostream>
#include <string>
#include <map>
#include"Telephone_book.hpp"
using namespace std;

void Telephone_book::Insert(string first_name, string second_name, string number, string job){
    Human human(first_name, second_name, number, job);
    tb.emplace(second_name, human);
}

void Telephone_book::Erase(string number){
    for(auto element : tb){
        if(element.second.number == number){
            tb.erase(element.first);
            break;
        }
    }
}

void Telephone_book::Print_all(){
    for(auto element : tb){
        cout << element.second.first_name << "\t" << element.second.second_name <<
        "\t" << element.second.number << "\t" << element.second.job << endl;
    }
}

void Telephone_book::Find(string second_name){
    if(tb.find(second_name) != tb.end()){
        cout << tb[second_name];
    }
    else{
        cout << "Данного пользователя в телефонной книге нет" << endl;
    }
}

void Telephone_book::Update(string second_name, string first_name, string number, string job){
    if(tb.find(second_name) != tb.end()){
        tb[second_name].first_name = first_name;
        tb[second_name].number = number;
        tb[second_name].job = job;
    }
    else{
        Insert(first_name, second_name, number, job);
    }
}

void Telephone_book::Clear(){
    tb.clear();
}
Human::Human(string first_name, string second_name, string number, string job){
    this->first_name = first_name;
    this->second_name = second_name;
    this->number = number;
    this->job = job;
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
    return os << human.first_name << "\t" << human.second_name << "\t" << human.number << "\t" << human.job << endl;
}
