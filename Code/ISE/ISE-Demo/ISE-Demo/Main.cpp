#include "Main.h"

int main()
{
	ISE engine;
	
	engine.REloadTexture("Data\\Menu2.jpg");
	engine.GOcreate3DObject("Data\\SlenderZombie.obj","Data\\zombieTex.jpg");
	engine.GOtranslate3DObject(0, 50.0, 0.0, 0.0);
	engine.GOcreate3DObject("Data\\Terrain.obj","Data\\grass.jpg");
	engine.GOtranslate3DObject(1, 0.0, -40.0, 0.0);
	engine.GOcreate3DObject("Data\\tree.obj","Data\\cannon.bmp");
	engine.GOtranslate3DObject(2, 300.0, -25.0, 150.0);
	engine.GOcreate3DObject("Data\\rock.obj","Data\\rock.jpg");
	engine.GOtranslate3DObject(3, 270.0, -25.0, 190.0);
	engine.GOcreateHUD("Data\\faces.obj", "Data\\group_photo.jpg");
	engine.GOtranslateHUD(4, winWidth/2, winHeight/2, 0.0);
	engine.GOcreate3DObject("Data\\SlenderZombie.obj","Data\\zombieTex.jpg");
	engine.GOtranslate3DObject(5, -75.0, 0.0, 50.0);
	engine.GOcreate3DObject("Data\\SlenderZombie.obj","Data\\zombieTex.jpg");
	engine.GOtranslate3DObject(6, 75.0, 0.0, 145.0);
	engine.GOcreate3DObject("Data\\SlenderZombie.obj","Data\\zombieTex.jpg");
	engine.GOtranslate3DObject(7, 540.0, 0.0, -325.0);
	engine.GOcreate3DObject("Data\\SlenderZombie.obj","Data\\zombieTex.jpg");
	engine.GOtranslate3DObject(8, 395.0, 0.0, -600.0);
	engine.GOcreate3DObject("Data\\SlenderZombie.obj","Data\\zombieTex.jpg");
	engine.GOtranslate3DObject(9, 215.0, 0.0, -1000.0);
	engine.GOcreate3DObject("Data\\SlenderZombie.obj","Data\\zombieTex.jpg");
	engine.GOtranslate3DObject(10, 840.0, 0.0, 1000.0);
	engine.GOcreate3DObject("Data\\SlenderZombie.obj","Data\\zombieTex.jpg");
	engine.GOtranslate3DObject(11, 600.0, 0.0, 405.0);
	engine.GOcreate3DObject("Data\\SlenderZombie.obj","Data\\zombieTex.jpg");
	engine.GOtranslate3DObject(12, 120.0, 0.0, -300.0);
	engine.GOcreate3DObject("Data\\SlenderZombie.obj","Data\\zombieTex.jpg");
	engine.GOtranslate3DObject(13, 490.0, 0.0, -400.0);
	engine.GOcreate3DObject("Data\\SlenderZombie.obj","Data\\zombieTex.jpg");
	engine.GOtranslate3DObject(14, 395.0, 0.0, -525.0);
	engine.GOcreate3DObject("Data\\SlenderZombie.obj","Data\\zombieTex.jpg");
	engine.GOtranslate3DObject(15, 1215.0, 0.0, -1255.0);
	engine.GOcreate3DObject("Data\\SlenderZombie.obj","Data\\zombieTex.jpg");
	engine.GOtranslate3DObject(16, 760.0, 0.0, 955.0);
	engine.GOcreate3DObject("Data\\SlenderZombie.obj","Data\\zombieTex.jpg");
	engine.GOtranslate3DObject(17, 430.0, 0.0, 340.0);
	engine.GOcreate3DObject("Data\\SlenderZombie.obj","Data\\zombieTex.jpg");
	engine.GOtranslate3DObject(18, -10.0, 0.0, -340.0);
	engine.GOcreate3DObject("Data\\tree.obj","Data\\cannon.bmp");
	engine.GOtranslate3DObject(19, -30.0, -25.0, 590.0);
	engine.GOcreate3DObject("Data\\rock.obj","Data\\rock.jpg");
	engine.GOtranslate3DObject(20, -50.0, -25.0, -545.0);
	engine.GOcreate3DObject("Data\\tree.obj","Data\\cannon.bmp");
	engine.GOtranslate3DObject(21, -430.0, -25.0, 750.0);
	engine.GOcreate3DObject("Data\\rock.obj","Data\\rock.jpg");
	engine.GOtranslate3DObject(22, -500.0, -25.0, 695.0);
	engine.GOenableHUD(4, false);
	engine.REwindowSetSize(winWidth, winHeight);
	engine.IOsetLockMousePosition((int)(winWidth/2), (int)(winHeight/2));
	engine.REcameraChangeMode(Camera::FPS);
	engine.IOunlockMouse();
	
	//Input input;
	bool w = false;
	bool d = false;
	int cool = 0;
	//input.setMouseLockPosition(640, 384);

	bool run = true;
	glEnable(GL_TEXTURE_2D);
	while(run)
	{
		engine.ISEupdate();
		updateInput(engine, run);
		engine.IOlockMouse();

		engine.RErenderGameObjects();
		engine.REsystemCycle();
	}

	return 0;
}

void updateInput(ISE &engine, bool &run)
{
	engine.REcameraLookUp(engine.IOgetMouseYVector()*250.0);
	engine.REcameraLookLeft(engine.IOgetMouseXVector()*35000.0);

	float speed = 150000.0;
	if(engine.IOisKeyPressed(Keyboard::W))
	{
		engine.REcameraMoveForward(speed);
		//std::cout << cool << " W" << std::endl;
		//std::cout<<"W" <<std::endl;
	}
	else if(engine.IOisKeyPressed(Keyboard::S))
	{
		engine.REcameraMoveBackward(speed);
		//std::cout<<"S" <<std::endl;
		//std::cout << cool << " S" << std::endl;
	}
	if(engine.IOisKeyPressed(Keyboard::A))
	{
		engine.REcameraMoveLeft(speed);
		//std::cout<<"A" <<std::endl;
		//std::cout << cool << " A" << std::endl;
	}
	else if(engine.IOisKeyPressed(Keyboard::D))
	{
		engine.REcameraMoveRight(speed);
		//std::cout<<"D" <<std::endl;
		//std::cout << cool << " D" << std::endl;
	}
	if(engine.IOisKeyReleased(Keyboard::K))
	{
		engine.REenableWireframe(!engine.REwireframeState());
	}
	if(engine.IOisKeyPressed(Keyboard::Escape))
	{
		run = false;
	}
	if(engine.IOisKeyReleased(Keyboard::X))
	{
		enableMenu = false;
		if(gameEnd)
		{
			gameEnd = false;
		}
		else
		{
			gameEnd = true;
			engine.GOsetHUDTexture(4, "Data\\group_photo.jpg");
			engine.GOenableHUD(4, true);
		}
	}
	if(engine.IOisKeyReleased(Keyboard::M))
	{
		gameEnd = false;
		if(enableMenu)
		{
			engine.GOsetHUDTexture(4, "Data\\group_photo.jpg");
			engine.GOenableHUD(4, false);
			enableMenu = false;
		}
		else
		{
			engine.GOsetHUDTexture(4, "Data\\Menu2.jpg");
			engine.GOenableHUD(4, true);
			enableMenu = true;
		}
	}
	if(engine.IOisKeyPressed(Keyboard::L))
	{
		engine.IOlockMouse();
	}
	if(engine.IOisKeyPressed(Keyboard::U))
	{
		engine.IOunlockMouse();
	}
	if(gameEnd)
	{
		if((engine.IOisMousePressed(Mouse::Left)) || (engine.IOisMousePressed(Mouse::Right)) || (engine.IOisMousePressed(Mouse::Middle)) || (engine.IOisMousePressed(Mouse::XButton1)) || (engine.IOisMousePressed(Mouse::XButton2)))
		{
			run = false;
		}
	}
}