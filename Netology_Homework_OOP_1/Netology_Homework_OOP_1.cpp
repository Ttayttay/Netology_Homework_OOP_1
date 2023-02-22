#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>

using namespace std;

class address {
public:
    // Конструктор
    address(string city, string street, int building, int flat);

    // Методы
    string fullAddr();

private:
    string city;
    string street;
    int building;
    int flat;
};

address::address(string city, string street, int building, int flat){
    this->city = city;
    this->street = street;
    this->building = building;
    this->flat = flat;
}

string address::fullAddr() {
    string addr = city + ", " + street + ", " + to_string(building) + ", " + to_string(flat);
    return addr;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    setlocale(LC_ALL, "Russian");

    string cityName, streetName;
    int size, buildingNum, flatNum;
    ifstream in("in.txt");

    in >> size;

    string* addrString = new string[size];

    if (in.is_open()) {
        for (int i = 0; i < size; i++) {
            in >> cityName >> streetName >> buildingNum >> flatNum;

            address addr(cityName, streetName, buildingNum, flatNum);

            addrString[i] = addr.fullAddr();
        }
    }
    else {
        cout << "Не удалось открыть файл!" << endl;
    }
    in.close();

    ofstream out("out.txt");
    out << size << endl;
    for (int i = 0; i < size; i++) {
        out << addrString[i] << endl;
    }
    out.close();

    delete[] addrString;
}