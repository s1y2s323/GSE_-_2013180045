#pragma once
#include "Object.h"
#include "Renderer.h"
#include "Sound.h"
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

	void Drawtext(int index);

	void SoundExplosion();

	void Animate();

	void DrawSnow();
	
	float snowTime = 0.0f;

	void CollisionAfer(int i,int j);
private:
	//std::vector<Object> *m_objects;
	
	Renderer *g_Renderer;
	Renderer *m_renderer;
	Sound *m_sound;

	int soundBG;
	int soundEX;



	int m_texCharacter;
	int m_texCharacter2;
	int m_background;
	int m_texBullet;
	int m_texParticle;
	Object *obj[ObjCount];
	
	int WindowWidth;
	int WindowHeight;
	float m_redCharTime;
	float m_blueCharTime;
	float m_redArrowTime;
	float m_blueArrowTime;
	
	

	float soundTime = 0.0f;

	int AniX=0, AniY=0;

	float m_bulletTime;

	float m_startTime = 0.0f;
};

class Timer
{
private :
	float Time = 0.0f;
public:
	void addTime(float time);
	float getTime();
};

