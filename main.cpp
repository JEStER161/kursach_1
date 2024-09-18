#include "Telephone_book.hpp"

int main() {
    Telephone_book tel_book;
    cout << "Добро пожаловать в телефонную книгу!!!" << endl;
    int a = 0;
    Window();
    cin >> a;
    while(a != -1){
        switch (a) {
            case 1:
            {
                cout << "Введите имя контакта:" << endl;
                string first_name;
                cin >> first_name;
                cout << "Введите фамилию контакта:" << endl;
                string second_name;
                cin >> second_name;
                cout << "Введите номер телефона контакта:" << endl;
                string number;
                cin >> number;
                cout << "Введите место работы контакта:" << endl;
                string job;
                cin >> job;
                cout << "Записать контакт в телефонную книгу? Да/Нет" << endl;
                string ans;
                cin >> ans;
                if(ans == "Да"){
                    tel_book.Insert(first_name, second_name, number, job);
                }
                Window();
                cin >> a;
            }
                break;
    
            case 2:
            {
                cout << "Введите номер телефона контакта, котрого хотите удалить из телефонной книги:" << endl;
                string number;
                cin >> number;
                tel_book.Erase(number);
                cout << "Контакт удален" << endl;
                Window();
                cin >> a;
            }
                break;
            case 3:
            {
                cout << "Введите фамилию контакта: " << endl;
                string second_name;
                cin >> second_name;
                tel_book.Find(second_name);
                Window();
                cin >> a;
            }
                break;
            case 4:
            {
                tel_book.Print_all();
                Window();
                cin >> a;
            }
                break;
            case 5:
            {
                cout << "Фамилию контакта, который хоитите изменить:" << endl;
                string second_name;
                cin >> second_name;
                cout << "Введите новое имя контакта:" << endl;
                string first_name;
                cin >> first_name;
                cout << "Введите новый номер телефона контакта:" << endl;
                string number;
                cin >> number;
                cout << "Введите новое место работы контакта:" << endl;
                string job;
                cin >> job;
                tel_book.Update(second_name, first_name, number, job);
                Window();
                cin >> a;
            }
                break;
            case 6:
            {
                cout << "Вы точно хотите отчистить телефонную книгу? Да/Нет" << endl;
                string ans;
                cin >> ans;
                if(ans == "Да"){
                    tel_book.Clear();
                }
                Window();
                cin >> a;
            }
                break;
            case 7:
                a = -1;
                break;
            
        }
    }
    return 0;
}
