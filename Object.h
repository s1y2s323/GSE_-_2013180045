#pragma once
class Object
{
	//�̸�
	//��ġ
	//ũ��(����)
	//
	
public:
	Object();
	void Setposition(int x,int y,int z) { m_pos.set(x,y,z); };
	int GetpositionX() { return m_pos.getX(); };
	int GetpositionY() { return m_pos.getY(); };
	int GetpositionZ() { return m_pos.getZ(); };
	void Setsize(int size) { m_size = size; };
	int Getsize() { return m_size; };
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
	Vec3<int> m_pos;  //��ġ
	int m_size;
	
	
	float x, y, z;

	int size;
};

