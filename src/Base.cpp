#include "Base.h"
/*TuioObject�̃��b�p�[�ł��B
��������src/Sample.cpp���Q�l�ɂ��Ă�������
*/
Base::Base(ofxTuioObject * _tuioObject)
{
    //�I�u�W�F�N�g��ID�ŏ�������
    x=_tuioObject->getX();
    y=_tuioObject->getY();
    if(_tuioObject->getFiducialId()<SAMPLE_NUM)
    {
        FID=_tuioObject->getFiducialId();
        sample.update(_tuioObject);
        index=1;//�ォ�珇�Ԃɔԍ����ӂ�
    }

}

//�}�[�J�[ID�̎擾
int Base::getFiducialId()
{
    return FID;
}

//�`�揈��
void Base::draw()
{
    //index�ɐU�蕪�����ԍ��ł��̃I�u�W�F�N�g��draw()���Ă�
    switch(index)
    {
    case 1:
        sample.draw();
        break;
    }
}

//��Ԃ̍X�V
void Base::update(ofxTuioObject * _tuioObject)
{
    x=_tuioObject->getX();
    y=_tuioObject->getY();
    //draw()�Ɠ��l��
    switch(index)
    {
    case 1:
        sample.update(_tuioObject);
        break;
    }
}

//X���W�̎擾
float Base::getX()
{
    return x;
}

//Y���W�̎擾
float Base::getY()
{
    return y;
}

//�^�b�`����
void Base::touchAction(ofxTuioCursor * _tuioCursor)
{
    switch(index)
    {
    case 1:
        sample.isRange(_tuioCursor);
        break;
    }
}

//��������
void Base::destroy()
{
    switch(index)
    {
    case 1:
        sample.destroy();
        break;
    }
}

