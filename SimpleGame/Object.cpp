#include "stdafx.h"
#include "Object.h"


Object::Object(float x,float y,int type,int team)
{
	if (team == 0)
	{
		teamNum = 0;
		if (type == 0)
		{
			m_color.set(0.8, 0.8, 0.8, 1);
			m_size = 50;
			m_life = 500;
		}
		else if (type == 1)
		{
			m_color.set(1, 0, 0, 1);
			m_size = 10;
			m_life = 100;
		}
		else if (type == 2)
		{
			m_color.set(1, 0, 0, 1);
			m_size = 4;
			m_life = 15;
		}
		else if (type == 3)
		{
			m_color.set(0.5, 0.2, 0.7, 1);
			m_size = 4;
			m_life = 10;
		}
	}
	else if (team == 1)
	{
		teamNum = 1;		
		if (type == 0)
		{
			m_color.set(1, 0, 0, 1);
			m_size = 50;
			m_life = 500;
		}
		else if (type == 1)
		{
			m_color.set(0, 0, 1, 1);
			m_size = 10;
			m_life = 100;
		}
		else if (type == 2)
		{
			m_color.set(0, 0, 1, 1);
			m_size = 4;
			m_life = 15;
		}
		else if (type == 3)
		{
			m_color.set(1, 1, 0, 1);
			m_size = 4;
			m_life = 10;
		}
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
		if (m_type == 2 || m_type == 3)
		{
			Delete = true;
		}
			
		m_dir.set(-m_dir.getX(),m_dir.getY(),0);
	}
	if (m_pos.getY() > 400 || m_pos.getY() < -400)
	{
		if (m_type == 2 || m_type == 3)
		{
			Delete = true;
		}
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

int Object::GetTeamNum()
{
	return teamNum;
}

void Object::SetTeamNum(int team)
{
	teamNum = team;
}

bool Object::GetDelete()
{
	return Delete;
}

float Object::GetGuage()
{
	if (m_type == 0)
	{
		return m_life / 500.f;
	}
	else if (m_type == 1)
	{
		return m_life / 100.f;
	}
	else if (m_type == 2)
	{
		return m_life / 15.f;
	}
	else if (m_type == 3)
	{
		return m_life / 10.f;
	}
}

