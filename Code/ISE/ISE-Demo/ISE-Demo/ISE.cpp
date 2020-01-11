#include "ISE.h"

// ------------------------------ Inflatable Strawberries Engine						#-----
ISE::ISE()
{
	m_RenderEngine.create(1280, 768, "Inflatable Strawberries Engine");
	m_RenderEngine.setPerspective(75.0, 1280.0/768.0, 0.1, 5000.0);
	m_RenderEngine.setWinPos(0.0, 0.0);
	m_RenderEngine.setCameraPosition(0.0, 35.0, 0.0);
	m_RenderEngine.setCameraFocus(0.0, 35.0, -50.0);
	m_RenderEngine.setCameraUp(0.0, 1.0, 0.0);
	m_RenderEngine.setCameraMode(Camera::FREECAM);
	m_RenderEngine.setWireFrame(false);
	m_2DLeft = 0.0;
	m_2DRight = 1.0;
	m_2DDown = 0.0;;
	m_2DUp = 1.0;
	m_FOV = 75.0;
	m_Ratio = 1.0;
	m_Near = 0.1;
	m_Far = 5000.0;
	m_Width = 1280.0;
	m_Far = 768.0;
}

ISE::~ISE()
{
}

void ISE::ISEupdate()
{
	m_Ratio = m_Width/m_Height;
	m_2DRight = m_Width;
	m_2DUp = m_Height;
	m_RenderEngine.update();
	//m_RenderEngine.setPerspective(m_FOV, m_Ratio, m_Near, m_Far);
	m_Input.mouseUpdate();
}



// ------------------------------ Misc													#`
float ISE::MIgetDeltaTime()
{
	return m_DeltaTime.getElapsed();
}



// ------------------------------ Asset Manager											#I
void ISE::AMloadModel(std::string l)
{
	m_AssetManager.Load(AssetMng::AS_OBJ, l);
}

void ISE::AMloadTexture(std::string l)
{
	m_AssetManager.Load(AssetMng::AS_TEXTURE, l);
}



// ------------------------------ Game Object											#II
void ISE::GOcreate3DObject(std::string name, std::string texture)
{
	m_GameObject.push_back(m_GameObjectFactory.Create(GameObjectFactory::OBJECT3D));
	int test = m_GameObject.max_size();
	test;
	test;
	m_GameObject[m_GameObject.size()-1]->setName(name);
	AMloadModel(name);
	m_GameObject[m_GameObject.size()-1]->setTexture(texture);
	AMloadTexture(texture);
}

void ISE::GOset3DObjectModel(int i, std::string l)
{
	m_GameObject[i]->setName(l);
}

void ISE::GOset3DObjectTexture(int i, std::string l)
{
	m_GameObject[i]->setTexture(l);
}

void ISE::GOenable3DObject(int i, bool e)
{
	m_GameObject[i]->enable(e);
}

void ISE::GOtranslate3DObject(int i, float x, float y, float z)
{
	m_GameObject[i]->translate(x, y, z);
}

void ISE::GOrotate3DObject(int i, float x, float y, float z)
{
	m_GameObject[i]->setRotation(Axis::xAxis, x);
	m_GameObject[i]->setRotation(Axis::yAxis, y);
	m_GameObject[i]->setRotation(Axis::zAxis, z);
}

void ISE::GOcreateHUD(std::string name, std::string texture)
{
	m_GameObject.push_back(m_GameObjectFactory.Create(GameObjectFactory::hud));
	int test = m_GameObject.max_size();
	test;
	test;
	m_GameObject[m_GameObject.size()-1]->setName(name);
	AMloadModel(name);
	m_GameObject[m_GameObject.size()-1]->setTexture(texture);
	AMloadTexture(texture);
}

void ISE::GOsetHUDModel(int i, std::string l)
{
	m_GameObject[i]->setName(l);
}

void ISE::GOsetHUDTexture(int i, std::string l)
{
	m_GameObject[i]->setTexture(l);
}

void ISE::GOenableHUD(int i, bool e)
{
	m_GameObject[i]->enable(e);
}

void ISE::GOtranslateHUD(int i, float x, float y, float z)
{
	m_GameObject[i]->translate(x, y, z);
}

void ISE::GOrotateHUD(int i, float x, float y, float z)
{
	m_GameObject[i]->setRotation(Axis::xAxis, x);
	m_GameObject[i]->setRotation(Axis::yAxis, y);
	m_GameObject[i]->setRotation(Axis::zAxis, z);
}



// ------------------------------ Input													#III
bool ISE::IOisKeyPressed(Keyboard::Key k)
{
	return m_Input.isPress(k);
}

bool ISE::IOisKeyReleased(Keyboard::Key k)
{
	return m_Input.isReleased(k);
}

bool ISE::IOisMousePressed(Mouse::Button m)
{
	return m_Input.isMousePress(m);
}

bool ISE::IOisMouseReleased(Mouse::Button m)
{
	return m_Input.isMouseReleased(m);
}

void ISE::IOlockMouse()
{
	m_Input.lockMouse();
}

void ISE::IOunlockMouse()
{
	m_Input.releaseMouse();
}

void ISE::IOsetLockMousePosition(int x, int y)
{
	m_Input.setMouseLockPosition(x, y);
}

int ISE::IOgetMouseXPosition()
{
	int x = 0;
	int y = 0;

	m_Input.getMouseLocation(x, y);

	return x;
}

int ISE::IOgetMouseYPosition()
{
	int x = 0;
	int y = 0;

	m_Input.getMouseLocation(x, y);

	return y;
}

int ISE::IOgetMouseXVector()
{
	int x = 0;
	int y = 0;

	m_Input.getMouseVec(x, y);

	return x;
}

int ISE::IOgetMouseYVector()
{
	int x = 0;
	int y = 0;

	m_Input.getMouseVec(x, y);

	return y;
}



// ------------------------------ Render Engine											#IV
void ISE::REwindowSetSize(int w, int h)
{
	m_Width = w;
	m_Height = h;
	m_RenderEngine.setWidth(m_Width);
	m_RenderEngine.setHeight(m_Height);
}

int ISE::REwindowGetWidth()
{
	return m_RenderEngine.getWidth();
}

int ISE::REwindowGetHeight()
{
	return m_RenderEngine.getHeight();
}

void ISE::REwindowSetTitle(std::string t)
{
	m_RenderEngine.setTitle(t);
}

void ISE::RErenderGameObjects()
{
	VAO tempVAO;
	Texture tempTex;
	for(int i = 0; i < m_GameObject.size(); i++)
	{
		if(m_GameObject[i]->getEnable())
		{
			m_AssetManager.getData(m_GameObject[i]->getName(), tempVAO);
			//m_AssetManager.getData(m_GameObject[i]->getTexture(), tempTex);
			m_AssetManager.getData(m_GameObject[i]->getTexture());
			m_RenderEngine.translate(m_GameObject[i]->getTranslateX(), m_GameObject[i]->getTranslateY(), m_GameObject[i]->getTranslateZ());
			m_RenderEngine.rotate(Axis::xAxis, m_GameObject[i]->getRotationX());
			m_RenderEngine.rotate(Axis::yAxis, m_GameObject[i]->getRotationY());
			m_RenderEngine.rotate(Axis::zAxis, m_GameObject[i]->getRotationZ());
			m_RenderEngine.bindTex(tempTex);

			m_RenderEngine.setOrtho2D(m_2DLeft, m_2DRight, m_2DDown, m_2DUp);
			m_RenderEngine.Ortho2DBegin();
			if(m_GameObject[i]->isType() == 3)
			{
				m_RenderEngine.renderV(tempVAO);
			}
			m_RenderEngine.Ortho2DEnd();
			if(m_GameObject[i]->isType() == 1)
			{
				m_RenderEngine.renderV(tempVAO);
			}
		}
	}
}

void ISE::REsystemCycle()
{
	m_RenderEngine.display();
}

void ISE::REcameraSetPerspective(float fov, float cnear, float cfar)
{
	m_FOV = fov;
	m_Near = cnear;
	m_Far = cfar;
}

void ISE::REcameraMoveForward(float x)
{
	m_RenderEngine.moveCameraForward(x*m_DeltaTime.getElapsed());
}

void ISE::REcameraMoveBackward(float x)
{
	m_RenderEngine.moveCameraForward(-x*m_DeltaTime.getElapsed());
}

void ISE::REcameraMoveLeft(float x)
{
	m_RenderEngine.moveCameraLeft(-x*m_DeltaTime.getElapsed());
}

void ISE::REcameraMoveRight(float x)
{
	m_RenderEngine.moveCameraLeft(x*m_DeltaTime.getElapsed());
}

void ISE::REcameraMoveUp(float x)
{
	m_RenderEngine.moveCameraUp(x*m_DeltaTime.getElapsed());
}

void ISE::REcameraMoveDown(float x)
{
	m_RenderEngine.moveCameraUp(-x*m_DeltaTime.getElapsed());
}

void ISE::REcameraChangeMode(Camera::cameraMode m)
{
	m_RenderEngine.setCameraMode(m);
}

void ISE::REcameraLookUp(float x)
{
	m_RenderEngine.rotateCameraUp(x*m_DeltaTime.getElapsed());
}

void ISE::REcameraLookDown(float x)
{
	m_RenderEngine.rotateCameraUp(-x*m_DeltaTime.getElapsed());
}

void ISE::REcameraLookLeft(float x)
{
	m_RenderEngine.rotateCameraLeft(x*m_DeltaTime.getElapsed());
}

void ISE::REcameraLookRight(float x)
{
	m_RenderEngine.rotateCameraLeft(-x*m_DeltaTime.getElapsed());
}

void ISE::REenableWireframe(bool e)
{
	m_RenderEngine.setWireFrame(e);
}

bool ISE::REwireframeState()
{
	return m_RenderEngine.getWireFrame();
}

void ISE::REloadTexture(std::string t)
{
	m_AssetManager.Load(AssetMng::AS_TEXTURE, t);
}