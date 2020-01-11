#include "GameObject.h"

Object3D::Object3D()
{
	m_pos.m_X = 0.0;
	m_pos.m_Y = 0.0;
	m_pos.m_Z = 0.0;
	m_translate.m_X = 0.0;
	m_translate.m_Y = 0.0;
	m_translate.m_Z = 0.0;
	m_angle.m_X = 0.0;
	m_angle.m_Y = 0.0;
	m_angle.m_Z = 0.0;
	m_Enable = true;
}

int Object3D::isType()
{
	return (int)1;
}

void Object3D::enable(bool e)
{
	m_Enable = e;
}

bool Object3D::getEnable()
{
	return m_Enable;
}

void Object3D::translate(float x, float y, float z)
{
	m_translate.m_X = x;
	m_translate.m_Y = y;
	m_translate.m_Z = z;
	m_pos.m_X += x;
	m_pos.m_Y += y;
	m_pos.m_Z += z;
}

void Object3D::setPos(float x, float y, float z)
{
	m_pos.m_X = x;
	m_pos.m_Y = y;
	m_pos.m_Z = z;
}

Vector3 Object3D::getPos()
{
	return m_pos;
}

float Object3D::getPosX()
{
	return m_pos.m_X;
}

float Object3D::getPosY()
{
	return m_pos.m_Y;
}

float Object3D::getPosZ()
{
	return m_pos.m_Z;
}

void Object3D::setScript(const char* file)
{
	m_Script = file;
}

std::string Object3D::getScript()
{
	std::string s(m_Script, 0, sizeof(m_Script));
	return s;
}

std::string Object3D::getName()
{
	return m_Name;
}

void Object3D::setName(std::string n)
{
	m_Name = n;
}

std::string Object3D::getTexture()
{
	return m_Texture;
}

void Object3D::setTexture(std::string t)
{
	m_Texture = t;
}

float Object3D::getTranslateX()
{
	return m_translate.m_X;
}

float Object3D::getTranslateY()
{
	return m_translate.m_Y;
}

float Object3D::getTranslateZ()
{
	return m_translate.m_Z;
}

void Object3D::setRotation(Axis axis, float angle)
{
	switch(axis)
	{
	case Axis::xAxis:
		{
			m_angle.m_X = angle;
		}
	case Axis::yAxis:
		{
			m_angle.m_Y = angle;
		}
	case Axis::zAxis:
		{
			m_angle.m_Z = angle;
		}
	}
}

float Object3D::getRotationX()
{
	return m_angle.m_X;
}

float Object3D::getRotationY()
{
	return m_angle.m_Y;
}

float Object3D::getRotationZ()
{
	return m_angle.m_Z;
}