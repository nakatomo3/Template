#include "Color.h"
#include "LogWriter.h"
#define COLOR_INT_MAX 255
#define COLOR_FLOAT_MAX 1.0f
#define COLOR_MIN 0

Color::Color(unsigned int R, unsigned int G, unsigned int B) {
	if (R > COLOR_INT_MAX || G > COLOR_INT_MAX || B > COLOR_INT_MAX) {
		LogWriter::LogWorning("Color��int�^�ŏ���������ꍇ��0�`255�͈̔͂Ŏw�肵�Ă��������B�@�w�肵��RGB=(%d,%d,%d)", R, G, B);
	}

	if (R > COLOR_INT_MAX) {
		r = COLOR_INT_MAX;
	} else {
		r = R;
	}

	if (G > COLOR_INT_MAX) {
		g = COLOR_INT_MAX;
	} else {
		g = G;
	}

	if (B > COLOR_INT_MAX) {
		b = COLOR_INT_MAX;
	} else {
		b = B;
	}
	a = COLOR_INT_MAX;
}

Color::Color(unsigned int R, unsigned int G, unsigned int B, unsigned int A) {
	if (R > COLOR_INT_MAX || G > COLOR_INT_MAX || B > COLOR_INT_MAX || A > COLOR_INT_MAX) {
		LogWriter::LogWorning("Color��int�^�ŏ���������ꍇ��0�`255�͈̔͂Ŏw�肵�Ă��������B�@�w�肵��RGBA=(%d,%d,%d,%d)", R, G, B, A);
	}

	if (R > COLOR_INT_MAX) {
		r = COLOR_INT_MAX;
	} else {
		r = R;
	}

	if (G > COLOR_INT_MAX) {
		g = COLOR_INT_MAX;
	} else {
		g = G;
	}

	if (B > COLOR_INT_MAX) {
		b = COLOR_INT_MAX;
	} else {
		b = B;
	}

	if (A > COLOR_INT_MAX) {
		a = COLOR_INT_MAX;
	} else {
		a = A;
	}
}

Color Color::Nega() {
	return Color(255-r, 255-g, 255-b);
}


Color::~Color() {

}
