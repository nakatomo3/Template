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

Color::Color(float R, float G, float B) {
	if (R > COLOR_FLOAT_MAX || G > COLOR_FLOAT_MAX || B > COLOR_FLOAT_MAX || R < 0 || G < 0 || B < 0) {
		LogWriter::LogWorning("Color��float�^�ŏ���������ꍇ��0�`1�͈̔͂Ŏw�肵�Ă��������B�@�w�肵��RGB=(%f,%f,%f)",R,G,B);
	}
	
	if (R > COLOR_FLOAT_MAX) {
		r = COLOR_FLOAT_MAX;
	} else if (R < 0) {
		r = 0;
	} else {
		r = R;
	}

	if (G > COLOR_FLOAT_MAX) {
		g = COLOR_FLOAT_MAX;
	} else if (G < 0) {
		g = 0;
	} else {
		g = G;
	}

	if (B > COLOR_FLOAT_MAX) {
		b = COLOR_FLOAT_MAX;
	} else if (B < 0) {
		b = 0;
	} else {
		b = B;
	}
	a = COLOR_FLOAT_MAX;
}

Color::Color(float R, float G, float B, float A) {
	if (R > COLOR_FLOAT_MAX || G > COLOR_FLOAT_MAX || B > COLOR_FLOAT_MAX || A > COLOR_FLOAT_MAX || R < 0 || G < 0 || B < 0 || A < 0) {
		LogWriter::LogWorning("Color��float�^�ŏ���������ꍇ��0�`1�͈̔͂Ŏw�肵�Ă��������B�@�w�肵��RGBA=(%f,%f,%f,%f)", R, G, B, A);
	}

	if (R > COLOR_FLOAT_MAX) {
		r = COLOR_FLOAT_MAX;
	} else if (R < 0) {
		r = 0;
	} else {
		r = R;
	}

	if (G > COLOR_FLOAT_MAX) {
		g = COLOR_FLOAT_MAX;
	} else if (G < 0) {
		g = 0;
	} else {
		g = G;
	}

	if (B > COLOR_FLOAT_MAX) {
		b = COLOR_FLOAT_MAX;
	} else if (B < 0) {
		b = 0;
	} else {
		b = B;
	}
	if (A > COLOR_FLOAT_MAX) {
		a = COLOR_FLOAT_MAX;
	} else if (A < 0) {
		a = 0;
	} else {
		a = A;
	}
}


Color::~Color() {
}
