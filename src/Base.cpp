#include "Base.h"

Base::Base(ofxTuioObject * _tuioObject){
    //�I�u�W�F�N�g��ID�ŏ�������
<<<<<<< HEAD
    if(_tuioObject->getFiducialId()<){
        index=1;
=======
    if(_tuioObject->getFiducialId()<SAMPLE_NUM){
        FID=_tuioObject->getFiducialId();
        sample=new Sample(_tuioObject);
        index=1;//�ォ�珇�Ԃɔԍ����ӂ�
>>>>>>> origin/master
    }

}
//�f�t�H���g�R���X�g���N�^(�K����̃R���X�g���N�^���ĂԂ���)
Base::Base(){
    //�K�������ŃC���X�^���X���쐬
<<<<<<< HEAD
=======
    sample=new Sample();
>>>>>>> origin/master
}

//�}�[�J�[ID�̎擾
int Base::getFid(){
    return FID;
}
//�`�揈��
void Base::draw(){
    //index�ɐU�蕪�����ԍ��ł��̃I�u�W�F�N�g��draw()���Ă�
    switch(index){
<<<<<<< HEAD
=======
        case 1:
            sample.draw();
            break;
>>>>>>> origin/master
    }
}
//��Ԃ̍X�V
void Base::update(ofxTuioObject * _tuioObject){
    //draw()�Ɠ��l��
    switch(index){
<<<<<<< HEAD
=======
        case 1:
            sample.update(_tuioObject);
            break;
>>>>>>> origin/master
    }
}
//�^�b�`���ɕK���Ă΂��
void Base::touchAction(ofxTuioCursor * _tuioCursor){
        switch(index){
<<<<<<< HEAD
=======
            case 1:
                sample.touchAction(_tuioCursor);
                break;
>>>>>>> origin/master
        }
}
//�������ɌĂ΂��
void Base::destroy(){
        switch(index){
<<<<<<< HEAD
=======
            case 1:
                sample.destroy();
                break;
>>>>>>> origin/master
        }
}

