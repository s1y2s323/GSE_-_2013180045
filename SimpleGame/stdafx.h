#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <utility>
#include <vector>
#include <iostream>
#include <random>
#include <ctime>
#include <functional>
#include <time.h>

using namespace std;

template <class T>class Vec3
{
private:
	T x, y, z;
public:
	Vec3() { x = y = z = 0; };
	Vec3(T xValue, T yValue, T zValue)
	{
		x = xValue;
		y = yValue;
		z = zValue;
	}
	void set(const T &xValue, const T&yValue, const T&zValue)
	{
		x = xValue;
		y = yValue;
		z = zValue;
	}
	void add(const T&xValue, const T&yValue, const T&zValue)
	{
		x += xValue;
		y += yValue;
		z += zValue;
	}
	T getX() const { return x; };
	T getY() const { return y; };
	T getZ() const { return z; };
};