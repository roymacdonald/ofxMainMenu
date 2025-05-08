#include "ofApp.h"
#include "ofxMainMenu.h"



void ofApp::setup(){
    ofxMainMenu::addMenu("menu1");
    ofxMainMenu::addMenu("menu1");
    ofxMainMenu::addMenu("menu2");//this will not add anything as it already exists.
    
    ofxMainMenu::addAppMenuItem("Main ", "a",[](){
        std::cout<<"Main!\n";
    });
    
    //menu1 already exists so it will add to it.
    ofxMainMenu::addMenuItem("menu1","Item 1", "a",[](){
        std::cout<<"menu1 item1!\n";
    });
    //TestMenu does not exist, so it will create it and add to it
    ofxMainMenu::addMenuItem("TestMenu","Menu 1", "a",[](){
        std::cout<<"test menu1!\n";
    });
        

    ofxMainMenu::addAppMenuItem("Menu 2", "c", [&](){
        callback();
    });
    
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
