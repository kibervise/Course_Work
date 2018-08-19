//
//  State.cpp
//  CourseWork
//
//  Created by Kibervise on 17.04.2018.
//  Copyright © 2018 Kibervise. All rights reserved.
//

#include "State.hpp"
#include <string>
using namespace std;

//---------------------------------------------
//конструктор по умолчанию
State::State():name(""), capital(""), area(0), language(new string[0]), size(0){
}

//------------------------------------------------
//конструктор
State::State(string Name, string Capital, double Area, string *Language, unsigned int Size): name(Name), capital(Capital), area(Area), language(Language), size(Size)
{
    language = new string[Size];
    for(int i = 0; i < Size; i++)
    {
        language[i] = Language[i];
    }
}

//------------------------------------------------
//деструктор
State::~State()
{
    delete [] language;
}

//------------------------------------------------
//методы set
void State::set_name(string Name) { name = Name; }
void State::set_capital(string Capital) { capital = Capital; }
void State::set_area(double Area) { area = Area; }
void State::set_language(string *Language, unsigned int Size)
{
    size = Size;
    language = new string[Size];
    for(int i = 0; i < Size; i++){
        language[i] = Language[i];
    }
}

//------------------------------------------------
//методы get
string State::get_name() const { return name; }
string State::get_capital() const { return capital; }
double State::get_area() const { return area; }
unsigned int State::get_size() const { return size;} //??????
string *State::get_language() const { return language; }

//-----------------------------------------------
//метод дляввода значений полей
void State::inputData(){
    cin.get();
    while(true){
        cout << "Enter the name: ";
        getline(cin, name);
        if (name.empty()){
            cout << "Error! Name is empty! " << endl;
        }else{
            break;
        }
    }
    
    while(true){
        cout << "Enter the capital: ";
        getline(cin, capital);
        if (capital.empty()){
            cout << "Error! Capital is empty" << endl;
        }else{
            break;
        }
    }
    
    string tmpArea;
    while (true) {
        cout << "Enter the area: ";
        getline(cin, tmpArea);
        area = atof(tmpArea.c_str());
        if (!area) {
            cout << "Error! Capital is empty, try again" << endl;
        }
        else {
            break;
        }
    }
    
    string tmpSize;
    while(true){
        cout << "Enter the quality of languages: ";
        getline(cin, tmpSize);
        size = atoi(tmpSize.c_str());
        language = new string[size];
        for(int i = 0; i < size; i++){
            cout << "Enter the language: ";
            getline(cin, language[i]);
        }
        
        if(!size){
            cout << "Error! Uncorrect quality of language(s), try again" << endl;
        }else{
            break;
        }
    }
}


//-----------------------------------------------
//метод для вывода значений полей на экран
void State::show() const
{
    cout << "Name: " << name << endl;
    cout << "Capital:" << capital << endl;
    cout << "Area: " << area << endl;
    cout << "Size of languages: " << size << endl;
    cout << "Languages: ";
    for(int i = 0; i < size; i++)
    {
        cout << language[i] << " ";
    }
    cout << endl;
}
