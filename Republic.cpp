//
//  CWRepublic.cpp
//  CW
//
//  Created by Kibervise on 25.04.2018.
//  Copyright © 2018 Kibervise. All rights reserved.
//

#include "Republic.hpp"
#include "State.hpp"
#include <string>

//------------------------------------------------------------
//конструктор по умолчанию
Republic::Republic(): State(), republicType(presidential) {
    
}

//------------------------------------------------------------
//конструктор
Republic::Republic(string Name, string Capital, double Area, string *Language, unsigned int Size, type Type):State(Name, Capital, Area, Language, Size), republicType(Type)
{
    
}

//------------------------------------------------------------
//деструктор
Republic::~Republic()
{
}

//------------------------------------------------------------
//set метод для инициализации поля типа республики
void Republic::set_republicType(type Type) { republicType = Type; }

//------------------------------------------------------------
//get метод для получения значения поля имени
type Republic::get_republicType() const { return republicType; }

//------------------------------------------------------------
//
void Republic::inputData()
{
    State::inputData();
    
    int repType = 0;
    printf( "Choose type of republic:" );
    printf( "\n\t 0 - Presidential ");
    printf( "\n\t 1 - Parliamentary ");
    printf( "\n\t 2 - Presidential-Parliamentary ");
    cout << "\nYour choice: ";
    cin >> repType;
    cout << "Republic type: ";
    switch (repType)
    {
        case 0:
            cout << "Presidential republic" << endl;
            republicType = presidential;
            break;
        case 1:
            cout << "Parliamentary respublic" << endl;
            republicType = parliamentary;
            break;
        case 2:
            cout << "Presidential-Parliamentary respublic" << endl;
            republicType = pres_parliam;
            break;
        default:
            if( repType < 0 || repType > 2){
                cout << "Error! Try again!" << endl << endl;
            }
            break;
    }
    
    
}
//------------------------------------------------------------
//метод для вывода значений полей на экран
void Republic::show() const //??????????????
{
    State::show();
    cout << "Type of republic: ";
    switch (republicType)
    {
        case 0:
            cout << "Presidential republic" << endl;
            break;
        case 1:
            cout << "Parliamentary respublic" << endl;
            break;
        case 2:
            cout << "Presidential-Parliamentary respublic" << endl;
            break;
    }
}

istream& operator>>(istream&is, Republic &R)
{
    is >> R.name;
    is >> R.capital;
    is >> R.area;
    is >> R.size;
    R.language = new string[R.size];
    is.get();
    for(int i = 0; i < R.size; i++){
        getline(is, R.language[i]);
    }
    string republicType_s;
    getline(is, republicType_s);
    if (republicType_s == "presidential")
        R.republicType = presidential;
    else if (republicType_s == "parliamentary")
        R.republicType = parliamentary;
    else
        R.republicType = pres_parliam;
    return is;
}


ostream& operator<<(ostream&os, Republic &R)
{
    os << R.name << endl;
    os << R.capital << endl;
    os << R.area << endl;
    os << R.size << endl;
    for(int i = 0; i < R.size; i++){
        os << R.language[i] << endl;
    }
    if (R.republicType == presidential)
        os << "presidential" << endl;
    else if (R.republicType == parliamentary)
        os << "parliamentary" << endl;
    else
        os << "pres_parliam" << endl;
    return os;
}

/*
ofstream& operator<<(ofstream& of, Republic& R) {
    of << R.name << endl;
    of << R.capital << endl;
    of << R.area << endl;
    of << R.size << endl;
    for(int i = 0; i < R.size; i++){
        of << R.language[i] << endl;
    }
    if (R.republicType == presidential)
        of << "presidential" << endl;
    else if (R.republicType == parliamentary)
        of << "parliamentary" << endl;
    else
        of << "pres_parliam" << endl;
    return of;
}

ifstream& operator>>(ifstream& in, Republic& R) {
    in.get();
    
    getline(in, R.name);
    getline(in, R.capital);
    in >> R.area;
    in >> R.size;
    R.language = new string[R.size];
    in.get();
    for(int i = 0; i < R.size; i++){
        getline(in, R.language[i]);
    }
    string republicType_s;
    getline(in, republicType_s);
    if (republicType_s == "presidential")
        R.republicType = presidential;
    else if (republicType_s == "parliamentary")
        R.republicType = parliamentary;
    else
        R.republicType = pres_parliam;
    return in;
}

*/




