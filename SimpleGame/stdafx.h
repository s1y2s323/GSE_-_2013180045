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
#include <cstdlib>
#include <windows.h> 
#include <string>
//#pragma comment( lib, "winmm.lib" ) 
using namespace std;



template <class T>class Vec4
{
private:
	T x, y, z, w;
public:
	Vec4() { x = y = z =w= 0; };
	Vec4(T xValue, T yValue, T zValue, T wValue)
	{
		x = xValue;
		y = yValue;
		z = zValue;
		w = wValue;
	}
	void set(const T &xValue, const T&yValue, const T&zValue, const T&wValue)
	{
		x = xValue;
		y = yValue;
		z = zValue;
		w = wValue;
	}
	void add(const T&xValue, const T&yValue, const T&zValue, const T&wValue)
	{
		x += xValue;
		y += yValue;
		z += zValue;
		w += wValue;
	}
	T getX() const { return x; };
	T getY() const { return y; };
	T getZ() const { return z; };
	T getW() const { return w; };
};

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

template <class T>class Vec2
{
private:
	T x, y;
public:
	Vec2() { x = y = 0; };
	Vec2(T xValue, T yValue)
	{
		x = xValue;
		y = yValue;
		
	}
	void set(const T &xValue, const T&yValue)
	{
		x = xValue;
		y = yValue;
		
	}
	void add(const T&xValue, const T&yValue)
	{
		x += xValue;
		y += yValue;
		
	}
	T getX() const { return x; };
	T getY() const { return y; };
	
};