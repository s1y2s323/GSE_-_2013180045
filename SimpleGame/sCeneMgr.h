#pragma once
#include "Object.h"
#include "Renderer.h"
#define ObjCount 50
class sCeneMgr
{
public:
	sCeneMgr();
	~sCeneMgr();

	void buildObjects();
	void update();  //animaition;
	Object* Getobject(int index);
	
private:
	//std::vector<Object> *m_objects;
	
	Object obj[ObjCount];

};

