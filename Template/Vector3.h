#pragma once
class Vector3 {
public:

	//x,y,z成分を0にする初期化
	Vector3() {
		x, y, z = 0;
	}

	//x,y成分を指定する初期化
	Vector3(float X, float Y) {
		x = X;
		y = Y;
		z = 0;
	}

	//x,y,z成分を指定する初期化
	Vector3(float X, float Y, float Z) {
		x = X;
		y = Y;
		z = Z;
	}

	~Vector3() {

	}

	//-------------------------operator-----------------------

	//足し算
	Vector3 operator+(Vector3 vector) {
		return Vector3(x + vector.x, y + vector.y, z + vector.z);
	};

	//引き算
	Vector3 operator-(Vector3 vector) {
		return Vector3(x - vector.x, y - vector.y, z - vector.z);
	};

	//内積
	float operator*(Vector3 vector) {
		return x * vector.x + y * vector.y + z * vector.z;
	}

	//外積
	Vector3 operator^(Vector3 vector) {
		return Vector3(
			y*vector.z - z * vector.y,
			z*vector.x - x * vector.z,
			x*vector.y - y * vector.x
		);
	}

	Vector3 operator/(float num) {
		return Vector3(x / num, y / num, z / num);
	}

	bool operator==(Vector3 vector) {
		if (x == vector.x && y == vector.y && z == vector.z) {
			return true;
		}
		return false;
	}

	bool operator!=(Vector3 vector) {
		if (x == vector.x && y == vector.y && z == vector.z) {
			return false;
		}
		return true;
	}


	//長さを返す関数
	float Magnitude() {
		return x * x + y * y + z * z;
	}

	//単位ベクトルを返す関数
	Vector3 UnitVector() {
		return Vector3(x / Magnitude(), y / Magnitude(), z / Magnitude());
	}

	void Set(float _x, float _y, float _z) {
		x = _x;
		y = _y;
		z = _z;
	}

	float GetX() {
		return x;
	}

	float GetY() {
		return y;
	}

	float GetZ() {
		return z;
	}

private:
	float x, y, z;
};



