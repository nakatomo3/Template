#pragma once
#include "Component.h"
class VisualComponent :	public Component {
public:
	VisualComponent();
	~VisualComponent();

	//�`��Ɋ�����R���|�[�l���g�ł��鎞������I�[�o�[���C�h���Ďg�p�B
	virtual void Draw();

	//�Ō�ɕ`�悷��p�̊֐��BUI�Ȃǂ�z��
	virtual void LateDraw();

};

