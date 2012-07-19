#ifndef BGM_H_INCLUDED
#define BGM_H_INCLUDED
#pragma once
#include "ofxTuio.h"
#include "ofMain.h"
#define SAMPLE_NUM 5
class BGM : public ofxTuioObject {
private:
    float default_angle,radius;
    int r,g,b;
public:
    BGM(ofxTuioObject * _blob);
    BGM() {};
    ~BGM() {};
    void draw();
    void update(ofxTuioObject * _blob);
    bool isRange(ofxTuioCursor * _cursor);
    bool isActionRange(ofxTuioCursor * _cursor);
    void touchAction(ofxTuioCursor * _cursor);
    float sumdist(float x,float y);
};
#endif // BGM_H_INCLUDED
