//
//  CWMonarchy.cpp
//  CW
//
//  Created by Kibervise on 25.04.2018.
//  Copyright © 2018 Kibervise. All rights reserved.
//

#include "Monarchy.hpp"
#include <string>

//------------------------------------------------------
//конструктор по умолчанию
Monarchy::Monarchy(): State(), monarch_person(""){
    
}

//------------------------------------------------------
//конструктор
Monarchy::Monarchy(string Name, string Capital, double Area, string *Language, unsigned int Size, string Monarch_Person):State(Name, Capital, Area, Language, Size), monarch_person(Monarch_Person)
{
}

//------------------------------------------------------
//деструктор
Monarchy::~Monarchy()
{
}

//------------------------------------------------------
//метод инициализации поля имени монарха
void Monarchy::set_monarch_person(string Monarch_Person) { monarch_person = Monarch_Person; }

//------------------------------------------------------
//метод для получения значения поля имени
string Monarchy::get_monarch_person() const { return monarch_person; }

//------------------------------------------------------
//
void Monarchy::inputData()
{
    State::inputData();
    
    while(true){
        cout << "Enter monarch person: ";
        getline(cin, monarch_person);
        if (monarch_person.empty()){
            cout << "Error! Incorrect monarch name! " << endl;
        }else{
            break;
        }
    }
}

//------------------------------------------------------
//метод для вывода значений полей на экран
void Monarchy::show() const
{
    State::show();
    cout << "Monarch person of monarchy:" << monarch_person << endl;
}


istream& operator>>(istream&is, Monarchy &M)
{
    is >> M.name;
    is >> M.capital;
    is >> M.area;
    is >> M.size;
    is.get();
    M.language = new string[M.size];
    for(int i = 0; i < M.size; i++){
        getline(is, M.language[i]);
    }
    is >> M.monarch_person;
    return is;
}


ostream& operator<<(ostream&os, Monarchy &M)
{
    os << M.name << endl;
    os << M.capital << endl;
    os << M.area << endl;
    os << M.size << endl;
    for(int i = 0; i < M.size; i++){
        os << M.language[i] << endl;
    }
    os << M.monarch_person << endl;
    return os;
}

/*
ofstream& operator<<(ofstream& of, Monarchy& M) {
    of << M.name << endl;
    of << M.capital << endl;
    of << M.area << endl;
    of << M.size << endl;
    for(int i = 0; i < M.size; i++){
        of << M.language[i] << endl;
    }
    of << M.monarch_person << endl;
    return of;
}

ifstream& operator>>(ifstream& in, Monarchy& M) {
    in.get();
    
    getline(in, M.name);
    getline(in, M.capital);
    in >> M.area;
    in >> M.size;
    in.get();
    M.language = new string[M.size];
    for(int i = 0; i < M.size; i++){
        getline(in, M.language[i]);
    }
    in >> M.monarch_person;
    return in;
}
 */

