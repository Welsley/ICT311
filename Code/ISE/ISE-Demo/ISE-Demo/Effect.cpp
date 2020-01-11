#include "GameObject.h"

Effect::Effect()
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

int Effect::isType()
{
	return (int)2;
}

void Effect::enable(bool e)
{
	m_Enable = e;
}

bool Effect::getEnable()
{
	return m_Enable;
}

void Effect::translate(float x, float y, float z)
{
	m_pos.m_X += x;
	m_pos.m_Y += y;
	m_pos.m_Z += z;
}

void Effect::setPos(float x, float y, float z)
{
	m_pos.m_X = x;
	m_pos.m_Y = y;
	m_pos.m_Z = z;
}

Vector3 Effect::getPos()
{
	return m_pos;
}

float Effect::getPosX()
{
	return m_pos.m_X;
}

float Effect::getPosY()
{
	return m_pos.m_Y;
}

float Effect::getPosZ()
{
	return m_pos.m_Z;
}

void Effect::setScript(const char* file)
{
	m_Script = file;
}

std::string Effect::getScript()
{
	std::string s(m_Script, 0, sizeof(m_Script));
	return s;
}

std::string Effect::getName()
{
	return m_Name;
}

void Effect::setName(std::string n)
{
	m_Name = n;
}

std::string Effect::getTexture()
{
	return m_Texture;
}

void Effect::setTexture(std::string t)
{
	m_Texture = t;
}

float Effect::getTranslateX()
{
	return m_translate.m_X;
}

float Effect::getTranslateY()
{
	return m_translate.m_Y;
}

float Effect::getTranslateZ()
{
	return m_translate.m_Z;
}

void Effect::setRotation(Axis axis, float angle)
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

float Effect::getRotationX()
{
	return m_angle.m_X;
}

float Effect::getRotationY()
{
	return m_angle.m_Y;
}

float Effect::getRotationZ()
{
	return m_angle.m_Z;
}