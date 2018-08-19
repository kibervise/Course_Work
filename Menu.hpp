//
//  CWMenu.hpp
//  CW
//
//  Created by Kibervise on 25.04.2018.
//  Copyright © 2018 Kibervise. All rights reserved.
//

#ifndef Menu_hpp
#define Menu_hpp
#include "ContainerList.hpp"
#include <string>


class usersMenu{    //класс пользовательского меню
private:
    ContainerList *tmpMenu;
public:
    usersMenu();    //конструктор по умолчанию
    ~usersMenu();   //деструктор
    
    void createRepublic();      // метод для создания Республики
    void createMonarchy();      // метод для создания Монархии
    void showObject() const;          // метод для вывода на экран
    void removeAllObjects() const;    // метод для удаления всех обьектов
    void saveToTheFile();       // метод сохранения в файл
    void loadFromTheFile();     // метод для вывода из файла
    void sortList();            //Сортировка контейнера за площадью
    void doRequest() const;           //Метод для вывода площади заданной республики
    void runMenu();             //метода для отображения меню
};

#endif /* Menu_hpp */
