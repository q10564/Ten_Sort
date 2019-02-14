#include "stdafx.h"
#include "SR_array.h"


SR_array::SR_array()
{
	this->length = 0;
	this->array = new int[length];
	this->array_copy = new int[length];
}


SR_array::~SR_array()
{
	//delete []array;
}

void SR_array::rand_arr()
{
	for (int i = 0; i < length; i++)
	{
		int j = rand()%length;
		int k = array[i];
		array[i] = array[j];
		array[j] = k;
	}
	arr_copy();
}

int SR_array::getMax()
{
	this->max = array[0];
	for (int i = 1; i < length; i++)
	{
		if (array[i] > this->max)
		{
			this->max = array[i];
		}
	}
	return this->max;
}

void SR_array::arr_copy()
{
	for (int i = 0; i < length; i++)
	{
		array_copy[i] = array[i];
	}
}
void SR_array::Input_arr(CString value)
{
	int len = value.GetLength();
	int splitlen = 0;
	char *split = ",";
	for (int i = 0; i < len; i++)
	{
		if (value.GetAt(i) == split[0])
		{
			splitlen++;
		}
	}
	//arr = SR_array(splitlen + 1);
	this->length = splitlen + 1;
	this->array = new int[splitlen + 1];
	this->array_copy = new int[splitlen + 1];
	CString v = value;
	for (int i = 0; i < splitlen + 1; i++)
	{
		int first = v.Find(split[0]);
		if (first != -1)
		{
			array[i] = _ttoi(v.Left(first));
			int length = v.Delete(0, first + 1);
			v = v.Right(length);
		}
		else
		{
			array[i] = _ttoi(v);
		}
	}
	arr_copy();
	getMax();
}
