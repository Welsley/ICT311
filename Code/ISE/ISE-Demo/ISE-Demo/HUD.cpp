#include "GameObject.h"

HUD::HUD()
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

int HUD::isType()
{
	return (int)3;
}

void HUD::enable(bool e)
{
	m_Enable = e;
}

bool HUD::getEnable()
{
	return m_Enable;
}

void HUD::translate(float x, float y, float z)
{
	m_translate.m_X = x;
	m_translate.m_Y = y;
	m_translate.m_Z = z;
	m_pos.m_X += x;
	m_pos.m_Y += y;
	m_pos.m_Z += z;
}

void HUD::setPos(float x, float y, float z)
{
	m_pos.m_X = x;
	m_pos.m_Y = y;
	m_pos.m_Z = z;
}

Vector3 HUD::getPos()
{
	return m_pos;
}

float HUD::getPosX()
{
	return m_pos.m_X;
}

float HUD::getPosY()
{
	return m_pos.m_Y;
}

float HUD::getPosZ()
{
	return m_pos.m_Z;
}

void HUD::setScript(const char* file)
{
	m_Script = file;
}

std::string HUD::getScript()
{
	std::string s(m_Script, 0, sizeof(m_Script));
	return s;
}

std::string HUD::getName()
{
	return m_Name;
}

void HUD::setName(std::string n)
{
	m_Name = n;
}

std::string HUD::getTexture()
{
	return m_Texture;
}

void HUD::setTexture(std::string t)
{
	m_Texture = t;
}

float HUD::getTranslateX()
{
	return m_translate.m_X;
}

float HUD::getTranslateY()
{
	return m_translate.m_Y;
}

float HUD::getTranslateZ()
{
	return m_translate.m_Z;
}

void HUD::setRotation(Axis axis, float angle)
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

float HUD::getRotationX()
{
	return m_angle.m_X;
}

float HUD::getRotationY()
{
	return m_angle.m_Y;
}

float HUD::getRotationZ()
{
	return m_angle.m_Z;
}