#include "ofApp.h"
#include "ofxMainMenu.h"



void ofApp::setup(){
    
    //All the menus are added before the "Window" menu, and are added .
    ofxMainMenu::addMenu("menu1");
    ofxMainMenu::addMenu("menu1");
    ofxMainMenu::addMenu("menu2");//this will not add anything as it already exists.
    
    ofxMainMenu::addAppMenuItem("Main ", "a",[](){
        // the following block will be executed when the menu is selected
        std::cout<<"Main!\n";
    });
    
    //menu1 already exists so it will add to it.
    ofxMainMenu::addMenuItem("menu1","Item 1", "b",[](){
        std::cout<<"menu1 item1!\n";
    });
    
    ofxMainMenu::addSeparatorToMenu("menu1");
    //menu1 already exists so it will add to it.
    ofxMainMenu::addMenuItem("menu1","Item 2", "x",[](){
        std::cout<<"menu1 item2!\n";
    });
    
    
    
    //TestMenu does not exist, so it will create it and add to it
    ofxMainMenu::addMenuItem("TestMenu","Menu 1", "c",[](){
        std::cout<<"test menu1!\n";
    });
        

    //Notice that we are passing the "current" scope to the lambda function by putting the & between the []. This way we can call the class member function "callback()";
    ofxMainMenu::addAppMenuItem("Menu 2", "d", [&](){
        callback();
    });
    //the following will add a separator to the main menu, before the "Quit" element
    ofxMainMenu::addSeparatorToAppMenu();
    
}
//--------------------------------------------------------------
void ofApp::callback(){
    std::cout<<"callback!\n";
}
//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
