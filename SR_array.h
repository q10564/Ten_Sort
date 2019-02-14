#pragma once
#include "stdafx.h"
#include <iostream>
using namespace std;
class SR_array
{
public:
	SR_array();
	~SR_array();
	int getMax();

public:
	int length;
	int *array;
	int *array_copy;
	int max;
	void rand_arr();
	void arr_copy();
	void Input_arr(CString value);
};

