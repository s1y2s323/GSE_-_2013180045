#pragma once
class Object
{
	//�̸�
	//��ġ
	//ũ��(����)
	//
	
public:
	Object();
	void Setposition(double x, double y, double z) { m_pos.set(x,y,z); };
	void add(double x, double y, double z) { m_pos.add(x, y, z); };
	double GetpositionX() { return m_pos.getX(); };
	double GetpositionY() { return m_pos.getY(); };
	double GetpositionZ() { return m_pos.getZ(); };
	void Setsize(int size) { m_size = size; };
	double Getsize() { return m_size; };
	void SetDir(double x, double y,double z) { m_dir.set(x, y,0); };
	double GetdirX() { return m_dir.getX(); };
	double GetdirY() { return m_dir.getY(); };

	void Setdir(double x, double y, double z) { m_dir.set(x, y, z); };

	//Object(int posx,int posy, float x, float y, float z,int size)	
	//{
	//	
	//	this->x = x;
	//	this->y = y;
	//	this->z = z;
	//	this->size = size;
	//}
	
	~Object();
	
private:
	Vec3<double> m_pos;  //��ġ
	Vec3<double> m_dir;
	int m_size;	
	double speed = 0.0001;
};

