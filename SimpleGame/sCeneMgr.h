#pragma once
#include "Object.h"
#include "Renderer.h"
//#include "stdafx.h"
#define ObjCount 50

#define OBJECT_BUILDING 0
#define OBJECT_CHARACTER 1
#define OBJECT_BULLET 2 
#define OBJECT_ARROW 3

#define TEAM_RED 0
#define TEAM_BLUE 1

#define LEVEL_ARROW 0.4
#define LEVEL_BULLET 0.4
#define LEVEL_BUILDING 0.1
#define LEVEL_CHACRACTER 0.5
class sCeneMgr
{
public:
	sCeneMgr(int windowSizeX, int windowSizeY);
	~sCeneMgr();


	Object* Getobject(int index);
	void CollisionTest();
	bool BoxBoxCollisionTest(float minX, float maxX, float minY, float maxY, float maxX1, float minX1, float maxY1, float minY1);
	void UpdateAllObjects(float elapsedTime);
	
	void RedBulletShot();
	void BlueBulletShot();

	void RedCharacterAdd();
	void BlueCharacterAdd(float x, float y, int type, int num);
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
	int m_texCharacter2;

	Object *obj[ObjCount];
	
	int WindowWidth;
	int WindowHeight;
	float m_redCharTime;
	float m_blueCharTime;
	float m_redArrowTime;
	float m_blueArrowTime;

	float m_bulletTime;
};

