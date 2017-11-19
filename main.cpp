#include "stdafx.h"
#include <iostream>
#include <utility>
#include <sstream>
using namespace std;
void print(int * array, unsigned int size);

void merge(int * arr_left, int size_left , int * arr_right, int size_right,int * tmp) 
{
	unsigned int i =0 , j= 0 , t = 0;
	while (i < size_left && j < size_right)
	{
		tmp[t++] = arr_left[i] < arr_right[j] ? arr_left[i++] : arr_right[j++];
	}
	while (i < size_left)
	{
		tmp[t++]=arr_left[i++];
	}
	while (j < size_right)
	{
		tmp[t++]=arr_right[j++];
	}
}
void merge_sort(int * array,int size)
{
	if (size<2)  
	{
		return;
	}
	int size_left = size / 2;
	int size_right = size - size_left;
	int * tmp = new int [size];
	merge_sort(array,size_left);
	merge_sort(array+size_left,size_right);
	merge(array,size_left, array + size_left,size_right,tmp);
	for (unsigned int i = 0; i < size;i++)
	{
		array[i] = tmp[i];
	}
	delete[] tmp;
}

bool read(int * array, unsigned int size)
{
	string mas;
	unsigned int i = 0, array_count = 0;
	getline(cin, mas);
	istringstream stream(mas);
	for (i; i < size; i++)
	{
		if (stream >> array[i])
		{
			array_count++;
		}
	}
	if (array_count == size && stream.eof()) return true;
	else return false;
}
void print(int * array, unsigned int size)
{
	for (unsigned int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
}
bool size_s(unsigned int &size)
{
	string str;
	getline(cin, str);
	istringstream stream(str);
	if (!(stream >> size))
	{
		return false;
	}
	else
	{
		if (stream.eof()) { return true; }
		else { return false; }
	}
}

int main()
{
	int * array;
	unsigned int size;
	if (size_s(size) && size>0)
	{
		array = new int[size];
		if (read(array, size))
		{
			merge_sort(array,size);
			print(array, size);
			cin.get();
		}
		else
		{
			cout << "fail input ";
			cin.get();
		}
		delete[] array;
	}
	else { cout << "size error"; cin.get(); }
	return 0;
}
