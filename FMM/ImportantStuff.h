#pragma once
#include "Matrix.h"
#include "Timer.h"

void  WorkFuncTime(Matrix const& a, Matrix const& b, std::function<Matrix(Matrix, Matrix)> func);
Matrix WorkFuncTime(Matrix const& a, Matrix const& b, std::function<Matrix(Matrix, Matrix)> func, bool d, char s, char name);
Matrix WorkFuncTime(Matrix const& a, Matrix const& b, std::function<Matrix(Matrix, Matrix, int)> func, int d, char s, char name);
Matrix WorkFuncTime(Matrix const& a, Matrix const& b, std::function<Matrix(Matrix, Matrix, int)> func, int d, char s, char name, Timer& timer);


