#pragma once
#include "Component.h"
class VisualComponent :	public Component {
public:
	VisualComponent();
	~VisualComponent();

	//描画に干渉するコンポーネントである時これをオーバーライドして使用。
	virtual void Draw();

	//最後に描画する用の関数。UIなどを想定
	virtual void LateDraw();

};

