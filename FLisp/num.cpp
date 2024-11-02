#include "type.h"
#include "error.h"
#include "num.h"


Flisp_Num Flisp_Num_Add(Flisp_Num a, Flisp_Num b) {
	Flisp_Num r;
	r.num = a.num + b.num;
	return r;
}


Flisp_Num Flisp_Num_Sub(Flisp_Num a, Flisp_Num b) {
	Flisp_Num r;
	r.num = a.num - b.num;
	return r;
}


Flisp_Num Flisp_Num_Mul(Flisp_Num a, Flisp_Num b) {
	Flisp_Num r;
	r.num = a.num * b.num;
	return r;
}


Flisp_Num Flisp_Num_Div(Flisp_Num a, Flisp_Num b) {
	Flisp_Num r;
	if (b.num != 0) {
		r.num = a.num / b.num;
	}
	else {
		Flisp_noise("Dived By 0");
	}
	return r;
}
