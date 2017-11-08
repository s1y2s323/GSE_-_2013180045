#pragma once
#include "Object.h"
#include "Renderer.h"
//#include "stdafx.h"
#define ObjCount 50

#define OBJECT_BUILDING 0
#define OBJECT_CHARACTER 1
#define OBJECT_BULLET 2 
#define OBJECT_ARROW 3
class sCeneMgr
{
public:
	sCeneMgr(int windowSizeX, int windowSizeY);
	~sCeneMgr();


	Object* Getobject(int index);
	void CollisionTest();
	bool BoxBoxCollisionTest(float minX, float maxX, float minY, float maxY, float maxX1, float minX1, float maxY1, float minY1);
	void UpdateAllObjects(float elapsedTime);
	
	void BulletShot();
	void CharacterShot();
	
	void DrawObjects();
	int GetObjCount();
	void DeleteObject(int index);
	int AddObject(float x, float y,int type,int num);

	void CollisionAfer(int i,int j);
private:
	//std::vector<Object> *m_objects;
	
	Renderer *g_Renderer;
	Renderer *m_renderer;

	int m_texCharacter;

	Object *obj[ObjCount];
	
	int WindowWidth;
	int WindowHeight;
	float m_StartTime;
	float m_StartTime2;
};

