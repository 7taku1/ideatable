#include "testApp.h"
//--------------------------------------------------------------
void testApp::setup() {
    ofAddListener(tuio.objectAdded,this,&testApp::objectAdded);
    ofAddListener(tuio.objectRemoved,this,&testApp::objectRemoved);
    ofAddListener(tuio.objectUpdated,this,&testApp::objectUpdated);
    ofAddListener(tuio.cursorAdded,this,&testApp::tuioAdded);
    ofAddListener(tuio.cursorRemoved,this,&testApp::tuioRemoved);
    ofAddListener(tuio.cursorUpdated,this,&testApp::tuioUpdated);
    //フレームレート設定
    ofSetFrameRate(60);
    //背景色を黒に
    ofBackground(0,0,0);
    //3333番ポートで通信開始
    tuio.start(3333);
    log="";
}
//--------------------------------------------------------------
void testApp::update() {
    tuio.getMessage();
}

//--------------------------------------------------------------
void testApp::draw() {
    obj_itr=objects.begin();
    ofEnableAlphaBlending();
    ofSetColor(0,0,0,50);
    ofRect(0,0,ofGetWidth(),ofGetHeight());
    #ifdef DEBUG
    ofDrawBitmapString(log,20,20);
    #endif
    ofDisableAlphaBlending();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key) {
    #ifdef DEBUG
    log="Key Pressed : keycode:"+ofToString(key);
    #endif
}

//--------------------------------------------------------------
void testApp::keyReleased(int key) {
    #ifdef DEBUG
    log="Key Released : keycode:"+ofToString(key);
    ofLog()<<"Key Released : keycode:"<<key;
    #endif
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ) {
    log="Mouse Moved: X: "+ofToString(x)
        +" Y: "+ofToString(y);
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button) {
    log="Mouse Dragged: "+ofToString(button)
        +" X: "+ofToString(x)
        +" Y: "+ofToString(y);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button) {
    log="Mouse Pressed: "+ofToString(button)
        +" X: "+ofToString(x)
        +" Y: "+ofToString(y);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button) {
    log="Mouse Released: "+ofToString(button)+
        " X: "+ofToString(x)+
        " Y: "+ofToString(y);
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo) {
}

void testApp::objectAdded(ofxTuioObject & tuioObject) {
    objects.insert(map<int,ofxTuioObject>::value_type(tuioObject.getFiducialId(),
                   tuioObject));
    log="New Object: "+ofToString(tuioObject.getFiducialId())+
        " X: "+ofToString(tuioObject.getX())+
        " Y: "+ofToString(tuioObject.getY());
}

void testApp::objectRemoved(ofxTuioObject & tuioObject) {
    objects.erase(tuioObject.getFiducialId());
    for(line_itr=lines.begin();line_itr!=lines.end();++line_itr){
        if((*line_itr).getFromID()==tuioObject.getFiducialId()||
           (*line_itr).getToID()==tuioObject.getFiducialId()){
                lines.erase(line_itr);
                break;
           }
    }
    log="Object Removed: "+ofToString(tuioObject.getFiducialId())+
        " X: "+ofToString(tuioObject.getX())+
        " Y: "+ofToString(tuioObject.getY());
}

void testApp::objectUpdated(ofxTuioObject & tuioObject) {
    objects[tuioObject.getFiducialId()].update(&tuioObject);
    for(line_itr=lines.begin();line_itr!=lines.end();line_itr++) {
        (*line_itr).update(&tuioObject);
    }
    log="Object Updated: "+ofToString(tuioObject.getFiducialId())+
        " X: "+ofToString(tuioObject.getX())+
        " Y: "+ofToString(tuioObject.getY());
}

void testApp::tuioAdded(ofxTuioCursor & tuioCursor) {
    log="New Cursor: "+ofToString(tuioCursor.getFingerId())+
        " X: "+ofToString(tuioCursor.getX())+
        " Y: "+ofToString(tuioCursor.getY());
}

void testApp::tuioRemoved(ofxTuioCursor & tuioCursor) {
    log="Cursor Removed: "+ofToString(tuioCursor.getFingerId())+
        " X: "+ofToString(tuioCursor.getX())+
        " Y: "+ofToString(tuioCursor.getY());
}

void testApp::tuioUpdated(ofxTuioCursor & tuioCursor) {
    log="Cursor Updated: "+ofToString(tuioCursor.getFingerId())+
        " X: "+ofToString(tuioCursor.getX())+
        " Y: "+ofToString(tuioCursor.getY());
}
