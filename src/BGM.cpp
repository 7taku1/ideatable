#include "BGM.h"
BGM::BGM(ofxTuioObject * _blob):ofxTuioObject(_blob) {
    vol=0.0;
    angle=_blob->getAngle();
    FID=_blob->getFiducialId();
    musicname="/sounds/"+ofToString(FID)+".mp3";
    music.loadSound(musicname);
    music.setMultiPlay(true);
    music.setLoop(true);
    music.setVolume(vol);
    music.play();
}

BGM::~BGM(){
    music.stop();
}

void BGM::draw() {

}

void BGM::update(ofxTuioObject * _tuioObject) {
    ofxTuioObject::update(_tuioObject);
    vol=_tuioObject->getAngle()/(2.0*3.141592653589793238);
    music.setVolume(vol);
}

void BGM::touchAction(ofxTuioCursor * _cursor){

}
