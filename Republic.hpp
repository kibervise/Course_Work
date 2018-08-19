//
//  Republic.hpp
//  CourseWork
//
//  Created by Kibervise on 17.04.2018.
//  Copyright © 2018 Kibervise. All rights reserved.
//

#ifndef Republic_hpp
#define Republic_hpp
#include "State.hpp"
#include <string>

enum type               //тип enum для перечисления видов республики
{
    presidential, parliamentary, pres_parliam
};

class Republic : public State   //класс Республика
{
private:
    type republicType;  //поле типа республики
public:
    Republic();         //конструктор по умолчанию
    Republic(string Name, string Capital, double Area, string *Language, unsigned int Size, type Type); //конструктор
    ~Republic();        //деструктор
    void set_republicType(type);    //set метод для инициализации поля типа республики
    type get_republicType() const;  //get метод для получения значения поля имени
    void inputData();
    void show() const;              //метод для вывода значений полей на экран
    
    friend ostream &operator<<(ostream&os, Republic &R); //метод перегрузки оператора <<
    friend istream &operator>>(istream&is, Republic &R); ////метод перегрузки оператора >>
    
    /*
    virtual ofstream& download_in_file(ofstream& of)=0;
    virtual ifstream& download_from_file(ifstream& in) = 0;
    friend ofstream& operator<<(ofstream& of, Republic& R);
    friend ifstream& operator>>(ifstream& in, Republic& R);
    */
};

#endif /* Republic_hpp */



