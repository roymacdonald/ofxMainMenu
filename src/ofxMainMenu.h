//
//  menu.h
//  MainMenuExample2
//
//  Created by Roy Macdonald on 07-05-25.
//

#pragma once
#import <functional>
#include <string>


class ofxMainMenu{
public:
    static void addAppMenuItem(const std::string& title,  const std::string& keyShortcut, std::function<void()> lambda);
    static void addMenu(const std::string& title);
    static void addMenuItem(const std::string& menu_name, const std::string& item_name, const std::string& keyShortcut, std::function<void()> lambda);
};
