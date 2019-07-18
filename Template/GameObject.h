#pragma once
using namespace std;
#include "OriginalHeaders.h"
#include <vector>
#include <string>
class GameObject {
public:

	//生成されたときに一番最初に呼び出されます。Start関数よりも先に呼び出されます
	virtual void Awake();
	//生成されたときに呼び出されます。Awake関数よりも後に呼び出されます。
	virtual void Start();
	//最初に呼び出されるUpdateです。
	virtual void FirstUpdate();
	//通常呼び出されるUpdateです。
	virtual void Update();
	//最後に呼び出されるUpdateです。
	virtual void LateUpdate();

	//[非推奨]これを使わずにObjectManagerのInstantiateを使って初期化してください
	GameObject();
	//[非推奨]これを使わずにObjectManagerのDestroyを使って初期化してください
	~GameObject();

	//オブジェクトのアクティブを切り替えます
	void SetActive(bool);
	//オブジェクトのアクティブを取得します
	bool GetActive();

	//オブジェクトの座標を取得します
	Vector3 GetPosition();
	//オブジェクトの座標を設定します
	void SetPosition(Vector3 newPos);

	//親との相対座標を取得します
	Vector3 GetLocalPosition();
	//親との相対座標を設定します
	void SetLocalPosition(Vector3 newPos);

	//現在の大きさを取得します
	Vector3 GetScale();
	//大きさを設定します
	void SetScale(Vector3 newScale);

	//現在の回転を取得します
	Vector3 GetRotation();
	//回転角度を設定します
	void SetRotation(Vector3 newRotation);

	//このオブジェクト自体の拡大率を取得します
	Vector3 GetLocalScale();
	//このオブジェクト自体の拡大率を設定します
	void SetLocalScale(Vector3 newScale);

	//現在の速度を取得します
	Vector3 GetVelocity();
	//速度を設定します
	void SetVelocity(Vector3 newVelocity);

	//このオブジェクトの名前を取得します
	string GetName();
	//このオブジェクトの名前を設定します
	void SetName(string newName);

	//このオブジェクトのタグを取得します
	string GetTag();
	//このオブジェクトにタグを設定します
	void SetTag(string newTag);
	//タグとtargetが一致しているかを返します
	bool CompareTag(string target);

	//親のオブジェクトを取得します
	GameObject* GetParent();
	//親を設定します
	void SetParent(GameObject* parent);

	//index番目の子供オブジェクトを取得します
	GameObject* GetChild(int index);
	//子供オブジェクトの数を取得します
	int GetChildCount();
	//子供を追加します
	void AddChild(GameObject* child);


	//オブジェクトを回転させます
	void Rotate(Vector3 angle);

	void Move(Vector3 range);

protected:
	bool isActive;

	Vector3 position;
	Vector3 localPosition;
	Vector3 scale;
	Vector3 localScale;
	Vector3 rotation;
	Vector3 velocity;

	string name;
	string tag;

	GameObject* parent;
	vector<GameObject*> child;
};

