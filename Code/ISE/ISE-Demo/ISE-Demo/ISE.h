#pragma once



// ------------------------------ Major systems											#~
#include "AssetMng.h"
#include "OPENGL_Facade.h"
#include "SFML_Facade.h"
#include "SFML_Input.h"
#include "SFML_Texture.h"
#include "GameObjectFactory.h"
#include "Input.h"
#include "RenderEngine.h"



// ------------------------------ Misc systems											#`
#include "Clock.h"



/**
 * @brief [brief description]
 * @details [long description]
 * @author [author]
 * 
 */
class ISE
{
public:
// ------------------------------ Inflatable Strawberries Engine						#-----
	ISE();
	~ISE();
	void ISEupdate();


	
// ------------------------------ Misc													#`
	float MIgetDeltaTime();



// ------------------------------ Asset Manager											#I
	void AMloadModel(std::string l);
	void AMloadTexture(std::string l);



// ------------------------------ Game Object											#II
	void GOcreate3DObject(std::string name, std::string texture);
	void GOset3DObjectModel(int i, std::string l);
	void GOset3DObjectTexture(int i, std::string l);
	void GOenable3DObject(int i, bool e);
	void GOtranslate3DObject(int i, float x, float y, float z);
	void GOrotate3DObject(int i, float x, float y, float z);
	void GOcreateHUD(std::string name, std::string texture);
	void GOsetHUDModel(int i, std::string l);
	void GOsetHUDTexture(int i, std::string l);
	void GOenableHUD(int i, bool e);
	void GOtranslateHUD(int i, float x, float y, float z);
	void GOrotateHUD(int i, float x, float y, float z);
	

	
// ------------------------------ Input													#III
	bool IOisKeyPressed(Keyboard::Key k);
	bool IOisKeyReleased(Keyboard::Key k);
	bool IOisMousePressed(Mouse::Button m);
	bool IOisMouseReleased(Mouse::Button m);
	void IOlockMouse();
	void IOunlockMouse();
	void IOsetLockMousePosition(int x, int y);
	int IOgetMouseXPosition();
	int IOgetMouseYPosition();
	int IOgetMouseXVector();
	int IOgetMouseYVector();



// ------------------------------ Render Engine											#IV
	void REwindowSetSize(int w, int h);
	int REwindowGetWidth();
	int REwindowGetHeight();
	void REwindowSetTitle(std::string t);
	void RErenderGameObjects();
	void REsystemCycle();
	void REcameraSetPerspective(float fov, float cnear, float cfar);
	void REcameraMoveForward(float x);
	void REcameraMoveBackward(float x);
	void REcameraMoveLeft(float x);
	void REcameraMoveRight(float x);
	void REcameraMoveUp(float x);
	void REcameraMoveDown(float x);
	void REcameraChangeMode(Camera::cameraMode m);
	void REcameraLookUp(float x);
	void REcameraLookDown(float x);
	void REcameraLookLeft(float x);
	void REcameraLookRight(float x);
	void REenableWireframe(bool e);
	bool REwireframeState();
	void REloadTexture(std::string t);



private:
// ------------------------------ Misc													#`
	Clock								m_DeltaTime;



// ------------------------------ Inflatable Strawberries Engine						#-----
	float								m_2DLeft;
	float								m_2DRight;
	float								m_2DDown;
	float								m_2DUp;
	float								m_Width;
	float								m_Height;
	float								m_FOV;
	float								m_Ratio;
	float								m_Near;
	float								m_Far;



// ------------------------------ Asset Manager											#I
	AssetMng							m_AssetManager;



// ------------------------------ Game Object											#II
	std::vector<GameObject*>			m_GameObject;
	GameObjectFactory					m_GameObjectFactory;



// ------------------------------ Input													#III
	Input								m_Input;
	


// ------------------------------ Render Engine											#IV
	RenderEngine						m_RenderEngine;
};