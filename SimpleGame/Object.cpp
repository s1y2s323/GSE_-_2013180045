#include "stdafx.h"
#include "Object.h"


Object::Object(float x,float y,int type)
{
	if (type == 0)
	{
		m_color.set(1, 0, 0, 1);	
		m_size = 50;
		m_life = 500;
	}
	else if (type == 1)
	{
		m_color.set(0, 1, 0, 1);
		m_size = 10;
		m_life = 10;
	}
	else if (type == 2)
	{
		m_color.set(0, 0, 1, 1);
		m_size = 2;
		m_life = 20;
	}
	else if (type == 3)
	{
		m_color.set(0.5, 1, 1, 1);		
		m_size = 5;
		m_life = 20;
	}
	m_pos.set(x, y, 0);
	m_dir.set(200.f *(((float)std::rand() / (float)RAND_MAX) - 0.5f),
		200.f *(((float)std::rand() / (float)RAND_MAX) - 0.5f), 0);
	

	//m_life = 10000.0f;
	m_lifeTime = 100000.0f;

	m_type = type;

	m_startTime = (float)timeGetTime()*0.001f;
	
}


Object::~Object()
{
}
void Object::Update(float elapsedTime)
{
	
	float elapseTimeInSecond = elapsedTime / 1000.f;
	if (m_type != 0)
	{
		m_pos.set(m_pos.getX() + m_dir.getX()*elapseTimeInSecond,
			m_pos.getY() + m_dir.getY()*elapseTimeInSecond, 0);
	}
	
	if (m_pos.getX() > 250 || m_pos.getX() <-250)
	{
		m_dir.set(-m_dir.getX(),m_dir.getY(),0);
	}
	if (m_pos.getY() > 250 || m_pos.getY() < -250)
	{
		m_dir.set(m_dir.getX(), -m_dir.getY(), 0);

	}
	if (m_life > 0.0f)
	{
		//m_life -= 0.5f;
	}
	if (m_lifeTime > 0.0f)
	{
		m_lifeTime -= 0.5f;
	}
}

float Object::GetLife()
{
	return m_life;
}

float Object::GetLifeTime()
{
	return m_lifeTime;
}
int Object::GetType()
{
	return m_type;
}
void Object::SetLife(float life)
{
	m_life = life;
}

void Object::SetstartTime(float time)
{
	m_startTime = time;

}
float Object::GetstartTime()
{
	return m_startTime;
}

int Object::GetArrowOwn()
{
	return CheckArrowOwn;
}
void Object::SetArrowOwn(int num)
{
	CheckArrowOwn = num;
}