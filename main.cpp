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
                cout << "Введите фамилию контакта:" << endl;
                string second_name;
                cin >> second_name;
                cout << "Введите имя контакта:" << endl;
                string first_name;
                cin >> first_name;
                cout << "Введите отчество контакта:" << endl;
                string third_name;
                cin >> third_name;
                cout << "Введите адрес контакта:" << endl;
                string address;
                cin >> address;
                cout << "Введите дату рождения контакта:" << endl;
                string date_of_birth;
                cin >> date_of_birth;
                cout << "Введите email контакта:" << endl;
                string email;
                cin >> email;
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
                cout << "Записать контакт в телефонную книгу? y/n" << endl;
                string ans;
                cin >> ans;
                if(ans == "y"){
                    tel_book.Insert(first_name, second_name, third_name, address, date_of_birth, email, number);
                }
                Window();
                cin >> a;
            }
                break;
    
            case 2:
            {
                cout << "Введите фамилию контакта, которого хотите удалить из телефонной книги:" << endl;
                string second_name;
                cin >> second_name;
                tel_book.Erase(second_name);
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
                cout << "Фамилия контакта, который хоитите изменить:" << endl;
                string second_name;
                cin >> second_name;
                cout << "Какое поле вы хотите изменить?" << endl;
                cout << "first_name - 1 \n second_name - 2 \n third_name - 3 \n address - 4 \n date_of_birth - 5 \n email - 6 \n number - 7" << endl;
                int ans;
                cin >> ans;
                tel_book.Update(second_name, ans);
                Window();
                cin >> a;
            }
                break;
            case 6:
            {
                cout << "Вы точно хотите отчистить телефонную книгу? y/n" << endl;
                string ans;
                cin >> ans;
                if(ans == "y"){
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
