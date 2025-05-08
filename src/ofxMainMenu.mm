//
//  menu.m
//  MainMenuExample2
//
//  Created by Roy Macdonald on 07-05-25.
//

#import <Foundation/Foundation.h>
// ofAppMenu.mm

#include "ofxMainMenu.h"
#import <Cocoa/Cocoa.h>
// A little Obj-C++ wrapper to hold your C++ lambda
@interface LambdaMenuItem : NSMenuItem{
@public
    std::function<void()> handler;
}
@end


@implementation LambdaMenuItem
- (void)invoke:(id)sender {
    if (self->handler) self->handler();
}
@end


static NSMutableArray<LambdaMenuItem *> *gLambdaMenuItems = nil;

NSMenu* _addMenu(const std::string& title){
    
    [NSApplication sharedApplication];
    NSMenu *mainBar = [NSApp mainMenu];
    NSString * nstitle = [NSString stringWithUTF8String:title.c_str()];
    NSMenuItem * menu = [mainBar itemWithTitle:nstitle];
    if(menu!=nil){
        NSLog(@"menu %s already exists", title.c_str());
        return menu.submenu;
    }
    
        
    NSMenuItem *toolsBarItem = [[NSMenuItem alloc] initWithTitle:nstitle action:NULL keyEquivalent:@""];
    NSMenu     *toolsMenu    = [[NSMenu alloc] initWithTitle:nstitle];
    [toolsBarItem setSubmenu:toolsMenu];
//        [mainBar addItem:toolsBarItem];
    NSInteger itemIndex = mainBar.numberOfItems-1;
    if(itemIndex < 0) itemIndex = 0;
    [mainBar insertItem:toolsBarItem atIndex:itemIndex];
    
    return toolsMenu;
    
    
}

void ofxMainMenu::addMenu(const std::string& title){
    _addMenu(title);
}

// Call this from your C++ setup()

void _addMenuItem(    NSMenu    *menu, const std::string& title,  const std::string& keyShortcut, std::function<void()> lambda)
{
    if(menu == nil) return;
    NSString *nstitle = [NSString stringWithUTF8String:title.c_str()];
    
    if([menu itemWithTitle:nstitle]){
        NSLog(@"_addMenuItem: item %s already exists", title.c_str());
        return;
    }
    
    if (!gLambdaMenuItems)
        gLambdaMenuItems = [[NSMutableArray alloc] init];
    
    // Create our special item

    NSString *nsKeyShortcut = [NSString stringWithUTF8String:keyShortcut.c_str()];
    
    
    LambdaMenuItem *item = [[LambdaMenuItem alloc]
       initWithTitle:nstitle
             action:@selector(invoke:)
      keyEquivalent:nsKeyShortcut];
    item.target  = item;           // so invoke: is called on it
    item->handler = lambda;         // stash your C++ lambda

    // Insert before “Quit”
    NSInteger itemIndex = menu.numberOfItems-1;
    if(itemIndex < 0) itemIndex = 0;
    [menu insertItem:item atIndex:itemIndex];
    [gLambdaMenuItems addObject:item];
}
void ofxMainMenu::addMenuItem(const std::string& menu_name, const std::string& item_name, const std::string& keyShortcut, std::function<void()> lambda){
    _addMenuItem(_addMenu(menu_name), item_name, keyShortcut, lambda);
}
void ofxMainMenu::addAppMenuItem(const std::string& title,  const std::string& keyShortcut, std::function<void()> lambda)
{
    [NSApplication sharedApplication];
    NSMenu    *mainMenu     = [NSApp mainMenu];
    NSMenuItem *appMenuItem = [mainMenu itemAtIndex:0];
    NSMenu    *appMenu      = appMenuItem.submenu;
    _addMenuItem(appMenu, title, keyShortcut, lambda);
//    if (!gLambdaMenuItems)
//        gLambdaMenuItems = [[NSMutableArray alloc] init];
//    
//    // Create our special item
//    NSString *nstitle = [NSString stringWithUTF8String:title.c_str()];
//    NSString *nsKeyShortcut = [NSString stringWithUTF8String:keyShortcut.c_str()];
//    
//    
//    LambdaMenuItem *item = [[LambdaMenuItem alloc]
//       initWithTitle:nstitle
//             action:@selector(invoke:)
//      keyEquivalent:nsKeyShortcut];
//    item.target  = item;           // so invoke: is called on it
//    item->handler = lambda;         // stash your C++ lambda
//
//    // Insert before “Quit”
//    NSInteger quitIndex = appMenu.numberOfItems-1;
//    [appMenu insertItem:item atIndex:quitIndex];
//    [gLambdaMenuItems addObject:item];
}
