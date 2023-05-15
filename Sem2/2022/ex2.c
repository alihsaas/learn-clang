#include <complex.h>
#include <stdio.h>
#include <math.h>

#define SIZE 1

typedef struct {
	float x,y, r, theta;
	char form;
} Complex;

Complex READ_COMPLEX() {
	printf("ENTER FORM: r (rectangular), p (polar)");
	char f;
	do {
		scanf("%c", &f);
	} while (f != 'r' && f != 'p');
	Complex x;
	x.form = f;
	switch (f) {
		case 'r':
			printf("ENTER X AND Y");
			scanf("%f", &x.x);
			scanf("%f", &x.y);
			break;
		case 'p':
			printf("ENTER R AND THETA");
			scanf("%f", &x.r);
			scanf("%f", &x.theta);
			break;
	};
	return x;
}

Complex COMPLETE_COMPLEX(Complex *x) {
	if (x->form == 'r') {
		x->r = sqrt(x->x*x->x + x->y*x->y);
		x->theta = (x->x == 0) ? 3.14 / 2 : atan(x->y/x->x);
	} else {
		x->x = x->r*cos(x->theta);
		x->y = x->r*sin(x->theta);
	}
}

void READ_ARRAY(Complex array[SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		array[i] = READ_COMPLEX();
		COMPLETE_COMPLEX(&array[i]);
	}
}

int main(int argc, char const *argv[])
{
	Complex array[SIZE];
	READ_ARRAY(array);

	for (int i=0; i<SIZE; i++) {
		printf("x=%f | y=%f | r=%f | theta=%f\n", array[i].x, array[i].y, array[i].r, array[i].theta);
	}
	return 0;
}