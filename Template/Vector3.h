#pragma once
#include "OriginalHeaders.h"
class Vector3 {
public:
	float x, y, z;

	//x,y,z������0�ɂ��鏉����
	Vector3() {
		x, y, z = 0;
	}

	//x,y�������w�肷�鏉����
	Vector3(float X, float Y) {
		x = X;
		y = Y;
		z = 0;
	}

	//x,y,z�������w�肷�鏉����
	Vector3(float X, float Y, float Z) {
		x = X;
		y = Y;
		z = Z;
	}

	~Vector3() {

	}

	//-------------------------operator-----------------------

	//�����Z
	Vector3 operator+(Vector3 vector) {
		return Vector3(x + vector.x, y + vector.y, z + vector.z);
	};

	//�����Z
	Vector3 operator-(Vector3 vector) {
		return Vector3(x - vector.x, y - vector.y, z - vector.z);
	};

	//����
	float operator*(Vector3 vector) {
		return x * vector.x + y * vector.y + z * vector.z;
	}

	//�O��
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


	//������Ԃ��֐�
	float Magnitude() {
		return x * x + y * y + z * z;
	}

	//�P�ʃx�N�g����Ԃ��֐�
	Vector3 UnitVector() {
		return Vector3(x / Magnitude(), y / Magnitude(), z / Magnitude());
	}

	

private:

};


