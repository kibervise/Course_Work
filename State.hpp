//
//  State.hpp
//  CourseWork
//
//  Created by Kibervise on 17.04.2018.
//  Copyright © 2018 Kibervise. All rights reserved.
//

#ifndef State_hpp
#define State_hpp
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class State             //класс держава
{
protected:
    string name;        //поле имени
    string capital;     //поле столицы
    double area;        //поле площади
    unsigned int size;  //поле количества языков
    string *language;   //поле языков
    
public:
    State();    //конструктор по умолчанию
    State(string Name, string Capital, double Area, string *Language, unsigned int Size);   //конструктор
    ~State();   //деструктор
    
    virtual void set_name(string);                      //set метод для инициализации поля имени
    virtual void set_capital(string);                   //set метод для инициализации поля столицы
    virtual void set_area(double);                      //set метод для инициализации поля площади
    virtual void set_language(string *, unsigned int);  //set метод для инициализации поля языков и поля их количества
    
    virtual string get_name() const;        //get метод для получения значения поля имени
    virtual string get_capital() const;     //get метод для получения значения поля столицы
    virtual double get_area() const;        //get метод для получения значения поля площади
    virtual unsigned int get_size() const;  //get метод для получения значения поля количества языков
    virtual string *get_language() const;   //get метод для получения значения поля языков
    
    virtual void inputData();   //метод дляввода значений полей
    virtual void show() const;  //метод для вывода значений полей на экран
    
};

#endif /* State_hpp */
