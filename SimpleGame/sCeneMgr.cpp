#include "stdafx.h"
#include "sCeneMgr.h"
#include "Object.h"
#include <iostream>

sCeneMgr::sCeneMgr()
{
}






void sCeneMgr::update()
{
	mt19937 engine((unsigned int)time(NULL));                    // MT19937 난수 엔진
	uniform_int_distribution<int> distribution(-1, 1);       // 생성 범위
	auto generator = bind(distribution, engine);
	for (int i = 0; i < ObjCount; i++)
	{
		//g_Renderer->DrawSolidRect(obj[i].GetpositionX(), obj[i].GetpositionY(), 0, obj[i].Getsize(), 1, 0, 1, 1);
		obj[i].Setposition(obj[i].GetpositionX()+ generator() , obj[i].GetpositionY() + generator(),0);
	
	}
}
void sCeneMgr::buildObjects()
{
	mt19937 engine((unsigned int)time(NULL));                    // MT19937 난수 엔진
	uniform_int_distribution<int> distribution(0, 100);       // 생성 범위
	auto generator = bind(distribution, engine);
	
	for (int i = 0; i < ObjCount; i++)
	{
		obj[i].Setposition(generator(), generator(), 10);
		obj[i].Setsize(20);
	}
	//m_objects.push_back(Object());
	
	//m_objects.push_back(Object);
	//p_object->Setposition(100, 100, 10);
	//p_object->Setsize(20);
	
}
Object* sCeneMgr::Getobject(int index)
{
	return& obj[index];
}
sCeneMgr::~sCeneMgr()
{
}
