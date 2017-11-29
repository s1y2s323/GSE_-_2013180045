#pragma once
class Object
{
	//이름
	//위치
	//크기(부피)
	//
	
public:
	Object();
	Object(float x,float y,int type,int team);
	float GetLife();
	float GetLifeTime();
	int GetType();
	void SetLife(float life);

	void Update(float elapseTime);
	
	void Setposition(double x, double y, double z) { m_pos.set(x,y,z); };
	
	double GetpositionX() { return m_pos.getX(); };
	double GetpositionY() { return m_pos.getY(); };
	double GetpositionZ() { return m_pos.getZ(); };
	
	
	void Setsize(int size) { m_size = size; };
	double Getsize() { return m_size; };
	//void SetDir(double x, double y,double z) { m_dir.set(x, y,0); };
	double GetdirX() { return m_dir.getX(); };
	double GetdirY() { return m_dir.getY(); };

	void Setdir(double x, double y, double z) { m_dir.set(x, y, z); };
	void SetColor(double x, double y, double z, double w) { m_color.set(x, y, z, w); };

	float GetstartTime();
	void SetstartTime(float time);

	int GetArrowOwn();
	void SetArrowOwn(int num);

	int GetTeamNum();
	void SetTeamNum(int team);

	bool GetDelete();

	float GetGuage();

	int GetDir();
	//Object(int posx,int posy, float x, float y, float z,int size)	
	//{
	//	
	//	this->x = x;
	//	this->y = y;
	//	this->z = z;
	//	this->size = size;
	//}
	Vec4<float> m_color;
	//float m_color[4];
	~Object();
	float m_nowTime;

private:
	Vec3<double> m_pos;  //위치
	Vec3<double> m_dir;
	int m_size;	
	int m_type;

	float m_life;
	float m_lifeTime;

	float m_startTime;
	double speed = 0.01;

	int CheckArrowOwn;

	int teamNum;

	bool Delete = false;

	
};

