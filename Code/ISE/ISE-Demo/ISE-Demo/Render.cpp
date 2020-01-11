#include "Render.h"



Render::Render(void)
{
	 rotX = false;
	 rotY= false;
	 rotZ= false;

	angX = 0;
	angY= 0;
	angZ= 0;

	tran= false;
	tranX= 0;
	tranY= 0;
	tranZ= 0;

	texture = true;
}


Render::~Render(void)
{
}

void Render::translate(float x, float y, float z)
{
	tran = true;
	tranX = x;
	tranY = y;
	tranZ = z;
}

void Render::rotate(Axis axis, float angle)
{
	switch(axis)
	{
	case xAxis:
		angX = angle;
		rotX = true;
		break;
	case yAxis:
		angY = angle;
		rotY = true;
		break;
	case zAxis:
		angZ = angle;
		rotZ =  true;
		break;
	default:
		//error
		break;
	}
}

void Render::setWireFrame(bool enable)
{
	if(enable)
	{
		OPENGL_Facade::enableWire();
	}
	else
	{
		OPENGL_Facade::disableWire();
	}
}

void Render::bindTex(Texture &tex)
{
	//texture = true;
	//OPENGL_Facade::enableTexture();
	
	//tex.bind();
}

void Render::setColour(float R, float G, float B)
{
	//OPENGL_Facade::polyColour(R,G,B);
}

void Render::render(VAO &data)
{
	OPENGL_Facade::enableTexture();
	OPENGL_Facade::pushMatrix();
	
	if (tran)
	{
		OPENGL_Facade::transform(tranX,tranY,tranZ);
	}
	if(rotX)
	{
		OPENGL_Facade::rotate(angX,1.f,0.0,0.0);
	}
	if(rotY)
	{
		OPENGL_Facade::rotate(angY,0.f,1.f,0.f);
	}
	if(rotZ)
	{
		OPENGL_Facade::rotate(angZ,0.f,0.f,1.f);
	}
	OPENGL_Facade::render(data);
	OPENGL_Facade::popMatrix();
	//after pop
	tran = false;
	rotX = false;
	rotY = false;
	rotZ = false;

	texture = false;
	OPENGL_Facade::polyColour(1.f,1.f,1.f);
	//OPENGL_Facade::disableTexture();
}