#include "stdafx.h"
#include "sCeneMgr.h"
#include "Object.h"
#include <iostream>

sCeneMgr::sCeneMgr(int windowSizeX,int windowSizeY)
{
	m_WindowSizeX = windowSizeX;
	m_WindowSizeY = windowSizeY;
	g_Renderer = new Renderer(m_WindowSizeX, m_WindowSizeY);

	////Load shaders
	//m_SolidRectShader = CompileShaders("./Shaders/SolidRect.vs", "./Shaders/SolidRect.fs");
	//
	////Create VBOs
	//CreateVertexBufferObjects();
	//
	//if (m_SolidRectShader > 0 && m_VBORect > 0)
	//{
	//	m_Initialized = true;
	//}
}


bool sCeneMgr::ScreenCollisionTest(int width, int height,int i)
{
	if (obj[i].GetpositionX() < 0)	
		obj[i].SetDir(obj[i].GetdirX()*-1,obj[i].GetdirY(),0);	
		
	if (obj[i].GetpositionX()> width)
		obj[i].SetDir(obj[i].GetdirX()*-1, obj[i].GetdirY(), 0);

	if (obj[i].GetpositionY() < 0)
		obj[i].SetDir(obj[i].GetdirX(), obj[i].GetdirY()*-1, 0);

	if (obj[i].GetpositionY() > height)
		obj[i].SetDir(obj[i].GetdirX(), obj[i].GetdirY()*-1, 0);
	return true;
}

bool sCeneMgr::BoxBoxCollisionTest(int minX,int maxX,int minY,int maxY,int minX1,int maxX1,int minY1,int maxY1)
{
	if (minX > maxX1)
		return false;
	if (maxX < minX1)
		return false;

	if (minY > maxY1)
	    return false;
	if (maxY < minY1)
		return false;
}

void sCeneMgr::update()
{
	mt19937 engine((unsigned int)time(NULL));                    // MT19937 난수 엔진
	uniform_real_distribution<double> distribution(-1, 1);       // 생성 범위
	auto generator = bind(distribution, engine);
	for (int i = 0; i < ObjCount; i++)
	{
		//if (BoxBoxCollisionTest(0, 500, 0, 500, 500, 0, 0, 500) == true)
		ScreenCollisionTest(500, 500, i);
			
		//g_Renderer->DrawSolidRect(obj[i].GetpositionX(), obj[i].GetpositionY(), 0, obj[i].Getsize(), 1, 0, 1, 1);
		//obj[i].Setposition(obj[i].GetpositionX()+ generator() , obj[i].GetpositionY() + generator(),0);
		obj[i].add(0.1*obj[i].GetdirX(),0.1*obj[i].GetdirY(),0);
		//obj[i].Setposition(obj[i].GetpositionX() + 0.05, obj[i].GetpositionY() + 0.05, 0);	
	}
}
void sCeneMgr::Draw()
{
	for (int i = 0; i < 50; i++)
	g_Renderer->DrawSolidRect(Getobject(i)->GetpositionX(), Getobject(i)->GetpositionY(), 0, 20, 1, 0, 1, 1);

}
void sCeneMgr::buildObjects()
{
	mt19937 engine((unsigned int)time(NULL));                    // MT19937 난수 엔진
	uniform_int_distribution<int> distribution(-200, 200);       // 생성 범위
	uniform_real_distribution<double> distribution2(-1.0, 1.0);
	auto generator = bind(distribution, engine);
	auto dir = bind(distribution2, engine);

	
	for (int i = 0; i < ObjCount; i++)
	{
		obj[i].Setposition(generator(), generator(), 0);
		obj[i].Setsize(10);
		obj[i].SetDir(dir(),dir(),0);
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
