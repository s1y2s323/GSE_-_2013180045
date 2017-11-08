#include "stdafx.h"
#include "sCeneMgr.h"



sCeneMgr::sCeneMgr(int windowSizeX,int windowSizeY)
{
	g_Renderer = new Renderer(500, 500);
	WindowWidth = windowSizeX;
	WindowHeight = windowSizeY;
	m_StartTime = (float)timeGetTime()*0.001f;
	m_StartTime2 = (float)timeGetTime()*0.001f;

	m_texCharacter = g_Renderer->CreatePngTexture("./Textures/PNGs/gomdori.png");
	for (int i = 0; i < ObjCount; i++)
	{
		obj[i] = NULL;
	}
	AddObject(0, 0, OBJECT_BUILDING,-1);
	
}




bool sCeneMgr::BoxBoxCollisionTest(float minX, float minY, float maxX, float maxY, float minX1, float minY1, float maxX1, float maxY1)
{
	if (minX > maxX1)
		return false;
	if (maxX < minX1)
		return false;

	if (minY > maxY1)
	    return false;
	if (maxY < minY1)
		return false;

	return true;
}

void sCeneMgr::UpdateAllObjects(float elapsedTime)
{
	for (int i = 0; i < ObjCount; i++)
	{
		if (obj[i] != NULL)
		{
			
			if (obj[i]->GetLife() < 0.0001f || obj[i]->GetLifeTime() < 0.0001f)
			{
				DeleteObject(i);
				//delete obj[i];
				//obj[i] = NUll;
			}
			else
			{
				obj[i]->Update(elapsedTime);
			}
		}
	}

	CollisionTest();
	BulletShot();
	CharacterShot();
}
void sCeneMgr::DrawObjects()
{
	g_Renderer->DrawSolidRect(0, 0, 0, WindowWidth, 0, 0, 0, 0.4);
	for (int i = 0; i < ObjCount; i++)
	{
		if (obj[i] != NULL)
		{			
			if (obj[i]->GetType() == OBJECT_BUILDING)
			{
				g_Renderer->DrawTexturedRect(
					obj[i]->GetpositionX(),
					obj[i]->GetpositionY(),
					0,
					obj[i]->Getsize(),
					obj[i]->m_color.getX(),
					obj[i]->m_color.getY(),
					obj[i]->m_color.getZ(),
					obj[i]->m_color.getW(),
					m_texCharacter
				);
			}
			else
			{
				g_Renderer->DrawSolidRect(
					obj[i]->GetpositionX(),
					obj[i]->GetpositionY(),
					0,
					obj[i]->Getsize(),
					obj[i]->m_color.getX(),
					obj[i]->m_color.getY(),
					obj[i]->m_color.getZ(),
					obj[i]->m_color.getW()
				);
			}
		}
	}

}
int sCeneMgr::AddObject(float x,float y,int type,int num)
{
	for (int i = 0; i < ObjCount; i++)
	{
		if (obj[i] == NULL)
		{
			obj[i] = new Object(x, y,type);
			obj[i]->SetArrowOwn(num);
		
			return i;
		}
	}
	return -1;
}

void sCeneMgr::DeleteObject(int index)
{
	if (obj[index] != NULL)
	{
		delete obj[index];
		obj[index] = NULL;
	}
}
void sCeneMgr::CollisionTest()
{
	for (int i = 0; i < ObjCount; i++)
	{
		
		if (obj[i] != NULL)
		{
			for (int j = 0; j < ObjCount; j++)
			{
				if (i == j)
					continue;
				if (obj[j] != NULL)
				{
					float minX, minY;
					float maxX, maxY;

					float minX1, minY1;
					float maxX1, maxY1;

					minX = obj[i]->GetpositionX() - obj[i]->Getsize()/ 2.f;
					minY = obj[i]->GetpositionY() - obj[i]->Getsize()/ 2.f;
					maxX = obj[i]->GetpositionX() + obj[i]->Getsize()/ 2.f;
					maxY = obj[i]->GetpositionY() + obj[i]->Getsize()/ 2.f;
					
					minX1= obj[j]->GetpositionX ()- obj[j]->Getsize() / 2.f;
					minY1 = obj[j]->GetpositionY() - obj[j]->Getsize() / 2.f;
					maxX1= obj[j]->GetpositionX() + obj[j]->Getsize() / 2.f;
					maxY1 = obj[j]->GetpositionY() + obj[j]->Getsize() / 2.f;
					if (BoxBoxCollisionTest(minX, minY, maxX, maxY, minX1, minY1, maxX1, maxY1))
					{
						CollisionAfer(i, j);
						
						//DeleteObject(i);
					}
				}
			}
			
		}
	}
}
void sCeneMgr::BulletShot()
{
	float NowTime = (float)timeGetTime()*0.001f;
	if (NowTime - m_StartTime >= 0.5f)
	{
		AddObject(0, 0, 2,-1);
	    m_StartTime = NowTime;
	}
}
void sCeneMgr::CharacterShot()
{
	
	for (int i = 0; i < ObjCount; i++)
	{
		if (obj[i] != NULL && obj[i]->GetType()==OBJECT_CHARACTER)
		{
			obj[i]->m_nowTime = (float)timeGetTime()*0.001f;
			if (obj[i]->m_nowTime - obj[i]->GetstartTime() >= 0.5f)
			{
				AddObject(obj[i]->GetpositionX(), obj[i]->GetpositionY(), 3,i);	
				//if (num >= ObjCount-1)
				//	DeleteObject(num);
				//else
				//{
				
					obj[i]->SetstartTime(obj[i]->m_nowTime);
					//obj[num]->SetArrowOwn(i);
				//}
							
			}
		}
	}
	
}
void sCeneMgr::CollisionAfer(int i, int j)
{
	if (obj[i]->GetType() == OBJECT_BUILDING && obj[j]->GetType() == OBJECT_CHARACTER)
	{
		obj[i]->SetLife(obj[i]->GetLife()-obj[j]->GetLife());
		DeleteObject(j);
	}
	else if (obj[i]->GetType() == OBJECT_CHARACTER && obj[j]->GetType() == OBJECT_BULLET)
	{
		
			obj[i]->SetLife(obj[i]->GetLife() - obj[j]->GetLife());
			DeleteObject(j);
		
	}
	else if (obj[i]->GetType() == OBJECT_BUILDING  && obj[j]->GetType()==OBJECT_ARROW)
	{
		
			obj[i]->SetLife(obj[i]->GetLife() - obj[j]->GetLife());
			DeleteObject(j);		
	}
	else if (obj[i]->GetType() == OBJECT_CHARACTER && obj[j]->GetType() == OBJECT_ARROW)
	{
		if (i != obj[j]->GetArrowOwn())
		{
			obj[i]->SetLife(obj[i]->GetLife() - obj[j]->GetLife());
			DeleteObject(j);
		}
	}
}
Object* sCeneMgr::Getobject(int index)
{
	return obj[index];
}
sCeneMgr::~sCeneMgr()
{
}
