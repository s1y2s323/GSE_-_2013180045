#pragma once
#include "Object.h"
#include "Renderer.h"
#define ObjCount 50
class sCeneMgr
{
public:
	sCeneMgr(int windowSizeX, int windowSizeY);
	~sCeneMgr();

	void buildObjects();
	void update();  //animaition;
	Object* Getobject(int index);
	bool BoxBoxCollisionTest(int minX, int maxX, int minY, int maxY, int maxX1, int minX1, int maxY1, int minY1);
	bool ScreenCollisionTest(int width, int height, int i);
	void Draw();
	
private:
	//std::vector<Object> *m_objects;
	int m_WindowSizeX;
	int	m_WindowSizeY;
	Renderer *g_Renderer = NULL;

	Object obj[ObjCount];

};

