#include "Camera.h"
#include <iostream>

Camera::Camera()
{
	camMode = FREECAM;
	reset();
	setPerspective();
}

Camera::~Camera()
{
}

void Camera::reset()
{
	m_Position.m_X = 0.0;
	m_Position.m_Y = 0.0;
	m_Position.m_Z = 0.0;
	m_Focus.m_X = 100.0;
	m_Focus.m_Y = 0.0;
	m_Focus.m_Z = 0.0;
	m_Up.m_X = 0.0;
	m_Up.m_Y = 1.0;
	m_Up.m_Z = 0.0;
	m_VertRotation = 0.0;
	m_VertRotFootPrint = 0.0;
	m_HorRotation = 0.0;
	m_FOV = 75.0;
	m_Ratio = 1.0;
	m_Near = 0.1;
	m_Far = 5000.0;
}

Vector3 Camera::getPos()
{
	return m_Position;
}

float Camera::getPosX()
{
	return m_Position.m_X;
}

float Camera::getPosY()
{
	return m_Position.m_Y;
}

float Camera::getPosZ()
{
	return m_Position.m_Z;
}

void Camera::setPos(Vector3 v)
{
	m_Position.m_X = v.m_X;
	m_Position.m_Y = v.m_Y;
	m_Position.m_Z = v.m_Z;
}

void Camera::setPos(float x, float y, float z)
{
	m_Position.m_X = x;
	m_Position.m_Y = y;
	m_Position.m_Z = z;
}

Vector3 Camera::getFocus()
{
	return m_Focus;
}

float Camera::getFocusX()
{
	return m_Position.m_X;
}

float Camera::getFocusY()
{
	return m_Position.m_Y;
}

float Camera::getFocusZ()
{
	return m_Position.m_Z;
}

void Camera::setFocus(Vector3 v)
{
	m_Focus.m_X = v.m_X;
	m_Focus.m_Y = v.m_Y;
	m_Focus.m_Z = v.m_Z;
}

void Camera::setFocus(float x, float y, float z)
{
	m_Focus.m_X = x;
	m_Focus.m_Y = y;
	m_Focus.m_Z = z;
}

Vector3 Camera::getUp()
{
	return m_Up;
}

float Camera::getUpX()
{
	return m_Up.m_X;
}

float Camera::getUpY()
{
	return m_Up.m_Y;
}

float Camera::getUpZ()
{
	return m_Up.m_Z;
}

void Camera::setUp(Vector3 v)
{
	m_Up.m_X = v.m_X;
	m_Up.m_Y = v.m_Y;
	m_Up.m_Z = v.m_Z;
}

void Camera::setUp(float x, float y, float z)
{
	m_Up.m_X = x;
	m_Up.m_Y = y;
	m_Up.m_Z = z;
}

void Camera::setCamMode(cameraMode m)
{
	camMode = m;
}

void Camera::updateCamera()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(m_Position.m_X, m_Position.m_Y, m_Position.m_Z,
			  m_Focus.m_X   , m_Focus.m_Y   , m_Focus.m_Z,
			  m_Up.m_X      , m_Up.m_Y      , m_Up.m_Z);
}

void Camera::moveForward(float amount)
{
	switch(camMode)
	{
		case FREECAM:
		{
			freeCamMoveForward(amount);
			break;
		}
		case ORBIT:
		{
			break;
		}
		case FPS:
		{
			FPSCamMoveForward(amount);
			break;
		}
	}
}

void Camera::moveRight(float amount)
{
	switch(camMode)
	{
		case FREECAM:
		{
			freeCamMoveRight(amount);
			break;
		}
		case ORBIT:
		{
			break;
		}
		case FPS:
		{
			FPSCamMoveRight(amount);
			break;
		}
	}
}

void Camera::moveUp(float amount)
{
	switch(camMode)
	{
		case FREECAM:
		{
			freeCamMoveUp(amount);
			break;
		}
		case ORBIT:
		{
			break;
		}
		case FPS:
		{
			break;
		}
	}
}

void Camera::rotateDown(float amount)
{
	m_VertRotation -= amount*((float)M_PI/180.0);
	//m_HorRotation = 0;
	switch(camMode)
	{
		case FREECAM:
		{
			freeCamRotate();
			break;
		}
		case ORBIT:
		{
			break;
		}
		case FPS:
		{
			//m_VertRotFootPrint += m_VertRotation;
			if(m_VertRotation > 84.0*((float)M_PI/180.0))
			{
				//m_VertRotFootPrint = 89.99*(M_PI/180);
				m_VertRotation = 84.0*((float)M_PI/180.0);
			}
			if(m_VertRotation < -84.0*((float)M_PI/180.0))
			{
				//m_VertRotFootPrint = -89.99*(M_PI/180);
				m_VertRotation = -84.0*((float)M_PI/180.0);
			}
			freeCamRotate();
			break;
		}
	}
}

void Camera::rotateRight(float amount)
{
	//m_VertRotation = 0;
	m_HorRotation += amount*((float)M_PI/180.0);
	switch(camMode)
	{
		case FREECAM:
		{
			freeCamRotate();
			break;
		}
		case ORBIT:
		{
			break;
		}
		case FPS:
		{
			freeCamRotate();
			break;
		}
	}
}

void Camera::freeCamMoveForward(float amount)
{
	float vecArray[16];
	glGetFloatv(GL_MODELVIEW_MATRIX, vecArray);

	m_Position.m_X += -vecArray[2] * amount;
	m_Position.m_Y += -vecArray[6] * amount;
	m_Position.m_Z += -vecArray[10] * amount;
	m_Focus.m_X += -vecArray[2] * amount;
	m_Focus.m_Y += -vecArray[6] * amount;
	m_Focus.m_Z += -vecArray[10] * amount;
}

void Camera::freeCamMoveRight(float amount)
{
	float vecArray[16];
	glGetFloatv(GL_MODELVIEW_MATRIX, vecArray);
	
	m_Position.m_X += vecArray[0] * amount;
	m_Position.m_Y += vecArray[4] * amount;
	m_Position.m_Z += vecArray[8] * amount;
	m_Focus.m_X += vecArray[0] * amount;
	m_Focus.m_Y += vecArray[4] * amount;
	m_Focus.m_Z += vecArray[8] * amount;
}

void Camera::freeCamRotate()
{
	Vector3 tempVec;
	Vector3 tempVec2;
	/*
	tempVec.m_Z = m_Focus.m_Z-m_Position.m_Z;
	tempVec.m_X = ((m_Focus.m_X-m_Position.m_X)*(float)cos(m_VertRotation*M_PI/180)) + ((m_Focus.m_Y-m_Position.m_Y)*(float)sin(m_VertRotation*M_PI/180));
	tempVec.m_Y = ((m_Focus.m_X-m_Position.m_X)*(float)-sin(m_VertRotation*M_PI/180)) + ((m_Focus.m_Y-m_Position.m_Y)*(float)cos(m_VertRotation*M_PI/180));

	m_Focus.m_Z = (tempVec.m_Z*(float)cos(m_HorRotation*M_PI/180) + (tempVec.m_X*(float)sin(m_HorRotation*M_PI/180))) + m_Position.m_Z;
	m_Focus.m_X = (tempVec.m_Z*(float)-sin(m_HorRotation*M_PI/180)) + (tempVec.m_X*(float)cos(m_HorRotation*M_PI/180)) + m_Position.m_X;
	m_Focus.m_Y = tempVec.m_Y + m_Position.m_Y;
	*/

	m_Focus.m_Y = m_Position.m_Y+(float)(sin(m_VertRotation));
	m_Focus.m_X = m_Position.m_X+(float)(cos(m_VertRotation)*cos(m_HorRotation));
	m_Focus.m_Z = m_Position.m_Z+(float)(cos(m_VertRotation)*sin(m_HorRotation));

	m_Up.m_X = m_Position.m_X-m_Focus.m_X;
	m_Up.m_Y = abs(m_Position.m_Y+(float)(100*sin(m_VertRotation+M_PI/2))) ;
	m_Up.m_Z = m_Position.m_Z-m_Focus.m_Z;

	/*
	tempVec.m_Z = ((m_Focus.m_Z-m_Position.m_Z)*(float)cos(m_HorRotation*M_PI/180)) + ((m_Focus.m_X-m_Position.m_X)*(float)sin(m_HorRotation*M_PI/180));
	tempVec.m_X = ((m_Focus.m_Z-m_Position.m_Z)*(float)(-sin(m_HorRotation*M_PI/180))) + ((m_Focus.m_X-m_Position.m_X)*(float)cos(m_HorRotation*M_PI/180));
	tempVec.m_Y = m_Focus.m_Y - m_Position.m_Y;

	tempVec2.m_Z = (tempVec.m_Z*(float)cos(m_VertRotation*M_PI/180)) + (tempVec.m_Y*(float)(-sin(m_VertRotation*M_PI/180)));
	tempVec2.m_X = tempVec.m_X;
	tempVec2.m_Y = (tempVec.m_Z*(float)sin(m_VertRotation*M_PI/180)) + (tempVec.m_Y*(float)cos(m_VertRotation*M_PI/180));

	m_Focus.m_Z = tempVec2.m_Z + m_Position.m_Z;
	m_Focus.m_X = (tempVec2.m_X*(float)cos(m_VertRotation*M_PI/180) + (tempVec2.m_Y*(float)sin(m_VertRotation*M_PI/180))) + m_Position.m_X;
	m_Focus.m_Y = (tempVec2.m_X*(float)(-sin(m_VertRotation*M_PI/180)) + (tempVec2.m_Y*(float)cos(m_VertRotation*M_PI/180))) + m_Position.m_Y;
	*/
}

void Camera::freeCamMoveUp(float amount)
{
	float vecArray[16];
	glGetFloatv(GL_MODELVIEW_MATRIX, vecArray);

	m_Position.m_X += vecArray[1] * amount;
	m_Position.m_Y += vecArray[5] * amount;
	m_Position.m_Z += vecArray[9] * amount;
	m_Focus.m_X += vecArray[1] * amount;
	m_Focus.m_Y += vecArray[5] * amount;
	m_Focus.m_Z += vecArray[9] * amount;
}

void Camera::FPSCamMoveForward(float amount)
{
	float vecArray[16];
	glGetFloatv(GL_MODELVIEW_MATRIX, vecArray);

	float tempFloat = 1/(sqrt(pow(-vecArray[10], 2) + pow(-vecArray[2], 2)));

	Vector3 tempVec;
	tempVec.m_X = -vecArray[2] * tempFloat;
	tempVec.m_Z = -vecArray[10] * tempFloat;

	m_Position.m_X += tempVec.m_X * amount;
	m_Position.m_Z += tempVec.m_Z * amount;
	m_Focus.m_X += tempVec.m_X * amount;
	m_Focus.m_Z += tempVec.m_Z * amount;
}

void Camera::FPSCamMoveRight(float amount)
{
	float vecArray[16];
	glGetFloatv(GL_MODELVIEW_MATRIX, vecArray);
	
	m_Position.m_X += vecArray[0] * amount;
	m_Position.m_Z += vecArray[8] * amount;
	m_Focus.m_X += vecArray[0] * amount;
	m_Focus.m_Z += vecArray[8] * amount;
}

void Camera::setCamPerspectives(float fov, float ratio, float cnear, float cfar)
{
	m_FOV = fov;
	m_Ratio = ratio;
	m_Near = cnear;
	m_Far = cfar;
	setPerspective();
}

void Camera::setCamOrtho2D(float left, float right, float down, float up)
{
	m_Left = left;
	m_Right = right;
	m_Down = down;
	m_Top = up;
}

void Camera::setFOV(float fov)
{
	m_FOV = fov;
	setPerspective();
}

void Camera::setRatio(float ratio)
{
	m_Ratio = ratio;
	setPerspective();
}

void Camera::setNear(float cnear)
{
	m_Near = cnear;
	setPerspective();
}

void Camera::setFar(float cfar)
{
	m_Far = cfar;
	setPerspective();
}

void Camera::setPerspective()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(m_FOV, m_Ratio, m_Near, m_Far);
}

void Camera::setOrtho2DBegin()
{
	glDisable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
		glLoadIdentity();
		OPENGL_Facade::ortho2DRender(m_Left, m_Right, m_Down, m_Top);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
			glLoadIdentity();
			glTranslatef(0, 0, 0);
}

void Camera::setOrtho2DEnd()
{
		glPopMatrix();
		glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
}