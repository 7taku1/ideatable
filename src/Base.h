#include "index.h"
#include "ofxTuio.h"
class Base{
    private:
    //�ȉ��ɃI�u�W�F�N�g��ǉ�
        Sample sample;
        int index;
        int FID;
    public:
        Base(ofxTuioObject * _tuioObject);
        Base();
        int getFid();
        void draw();
        void update(ofxTuioObject * _tuioObject);
        void touchAction(ofxTuioCursor * _tuioCursor);
        void destroy();
};
