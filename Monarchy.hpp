//
//  CWMonarchy.hpp
//  CW
//
//  Created by Kibervise on 25.04.2018.
//  Copyright © 2018 Kibervise. All rights reserved.
//

#ifndef Monarchy_hpp
#define Monarchy_hpp
#include "State.hpp"
#include <string>

class Monarchy : public State   //класс Монархия
{
private:
    string monarch_person;              //поле имени монарха
public:
    Monarchy();                         //конструктор по умолчанию
    Monarchy(string Name, string Capital, double Area, string *Language, unsigned int Size, string Monarch_Person); //конструктор
    ~Monarchy();                        //деструктор
    
    void set_monarch_person(string);    //set метод для инициализации поля имени монарха
    string get_monarch_person() const;  //get метод для получения значения поля имени
    void inputData();
    void show() const;                  //метод для вывода значений полей на экран
    
    friend ostream &operator<<(ostream&os, Monarchy &M); //метод перегрузки оператора <<
    friend istream &operator>>(istream&is, Monarchy &M); //метод перегрузки оператора >>
    /*
    virtual ofstream& download_in_file(ofstream& of)=0;
    virtual ifstream& download_from_file(ifstream& in) = 0;
    friend ofstream& operator<<(ofstream& of, Monarchy& M);
    friend ifstream& operator>>(ifstream& in, Monarchy& M);
*/
};

#endif /* Monarchy_hpp */

