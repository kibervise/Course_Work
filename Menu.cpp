//
//  CWMenu.cpp
//  CW
//
//  Created by Kibervise on 25.04.2018.
//  Copyright © 2018 Kibervise. All rights reserved.
//

#include "Menu.hpp"
#include "ContainerList.hpp"
#include <string>

//----------------------------------------------------
//конструктор по умолчанию
usersMenu::usersMenu(){
    tmpMenu = new ContainerList;
}

//----------------------------------------------------
//деструктор
usersMenu::~usersMenu(){
    delete tmpMenu;
}

//----------------------------------------------------
// метод для создания Республики
void usersMenu::createRepublic(){
    Republic *rep = new Republic;
    rep->inputData();
    tmpMenu->pushInList(rep);
    
}

//----------------------------------------------------
// метод для создания Монархии
void usersMenu::createMonarchy(){
    Monarchy *mon = new Monarchy;
    mon->inputData();
    tmpMenu->pushInList(mon);
}

//----------------------------------------------------
// метод для вывода на экран
void usersMenu::showObject() const{
    tmpMenu->showList();
}

//----------------------------------------------------
// метод для удаления всех обьектов
void usersMenu::removeAllObjects() const{
    tmpMenu->deleteAllList();
}

//----------------------------------------------------
// метод сохранения в файл
void usersMenu::saveToTheFile(){
    tmpMenu->saveToFileContainer();
}

//----------------------------------------------------
// метод для вывода из файла
void usersMenu::loadFromTheFile(){
    tmpMenu->readFromFileContainer();
}

//----------------------------------------------------
//Сортировка контейнера за площадью
void usersMenu::sortList(){
    tmpMenu->sortListContainer();
}

//----------------------------------------------------
//Метод для вывода площади заданной республики
void usersMenu::doRequest() const{
    string republicNameForArea;
    cout << "Enter the name of republic: ";
    cin >> republicNameForArea;
    tmpMenu->request(republicNameForArea);
}

//----------------------------------------------------
//метода для отображения меню
void usersMenu::runMenu() {
    
    int choice = 0;
    while(choice != 9){
        printf( "\t\t--------------MENU--------------\n" );
        printf( "\n\t\t|1| - Create a monarchy " );
        printf( "\n\t\t|2| - Create a republic " );
        printf( "\n\t\t|3| - Show the list " );
        printf( "\n\t\t|4| - Remove the list " );
        printf( "\n\t\t|5| - Save to the file " );
        printf( "\n\t\t|6| - Load from the file " );
        printf( "\n\t\t|7| - Sort objects " );
        printf( "\n\t\t|8| - Do request " );
        printf( "\n\t\t|9| - Leave the program " );
        printf("\n\n\t\t--------------------------------\n");
        cout << "\nYour choise: ";
        cin >> choice;
        
        switch (choice)
        {
            case 1:
                createMonarchy();
                break;
                
            case 2:
                createRepublic();
                break;
                
            case 3:
                showObject();
                break;
                
            case 4:
                removeAllObjects();
                break;
                
            case 5:
                saveToTheFile();
                break;
                
            case 6:
                loadFromTheFile();
                break;
                
            case 7:
                sortList();
                break;
                
            case 8:
                doRequest();
                break;
                
            case 9:
                cout << "\n\t\t\tBye :)\n" << endl;
                break;
                
            default:
                if( choice < 1 || choice > 9)
                {
                    cout << "\tError! Your choice isn't correct! Please, try again! " << endl;
                }
                break;
        }
    }
}

