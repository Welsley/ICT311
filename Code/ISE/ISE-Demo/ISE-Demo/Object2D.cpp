#include "GameObject.h"

Object2D::Object2D()
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

int Object2D::isType()
{
	return (int)0;
}

bool Object2D::getEnable()
{
	return m_Enable;
}

void Object2D::enable(bool e)
{
	m_Enable = e;
}

void Object2D::translate(float x, float y, float z)
{
	m_pos.m_X += x;
	m_pos.m_Y += y;
	m_pos.m_Z += z;
}

void Object2D::setPos(float x, float y, float z)
{
	m_pos.m_X = x;
	m_pos.m_Y = y;
	m_pos.m_Z = z;
}

Vector3 Object2D::getPos()
{
	return m_pos;
}

float Object2D::getPosX()
{
	return m_pos.m_X;
}

float Object2D::getPosY()
{
	return m_pos.m_Y;
}

float Object2D::getPosZ()
{
	return m_pos.m_Z;
}

void Object2D::setScript(const char* file)
{
	m_Script = file;
}

std::string Object2D::getScript()
{
	std::string s(m_Script, 0, sizeof(m_Script));
	return s;
}

std::string Object2D::getName()
{
	return m_Name;
}

void Object2D::setName(std::string n)
{
	m_Name = n;
}

std::string Object2D::getTexture()
{
	return m_Texture;
}

void Object2D::setTexture(std::string t)
{
	m_Texture = t;
}

float Object2D::getTranslateX()
{
	return m_translate.m_X;
}

float Object2D::getTranslateY()
{
	return m_translate.m_Y;
}

float Object2D::getTranslateZ()
{
	return m_translate.m_Z;
}

void Object2D::setRotation(Axis axis, float angle)
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

float Object2D::getRotationX()
{
	return m_angle.m_X;
}

float Object2D::getRotationY()
{
	return m_angle.m_Y;
}

float Object2D::getRotationZ()
{
	return m_angle.m_Z;
}