//
//  main.cpp
//  CourseWork
//
//  Created by Kibervise on 17.04.2018.
//  Copyright © 2018 Kibervise. All rights reserved.
//

#include "State.cpp"
#include "Republic.cpp"
#include "Monarchy.cpp"
#include "ContainerList.cpp"
#include "Menu.cpp"
#include <iostream>

using namespace std;

int main(){
    usersMenu menu = usersMenu();
    menu.runMenu();
}

