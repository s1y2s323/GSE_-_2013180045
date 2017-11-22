/*
Copyright 2017 Lee Taek Hee (Korea Polytech University)

This program is free software: you can redistribute it and/or modify
it under the terms of the What The Hell License. Do it plz.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY.
*/

#include "stdafx.h"

#include "Dependencies\glew.h"
#include "Dependencies\freeglut.h"
#include "windows.h"
#include "Object.h"
#include "sCeneMgr.h"
#include <cstdlib>
#include <iostream>
//Object *p_object = new Object();
sCeneMgr* scene = NULL;

bool LButtonDown = false;
DWORD prevTime = 0;



void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);
	glClearDepth(1.f);
	
	DWORD currTime = timeGetTime();
	DWORD elapsedTime = currTime - prevTime;
	prevTime = currTime;
	std::cout << currTime << std::endl;
	scene->UpdateAllObjects((float)elapsedTime);
	scene->DrawObjects();	

	glutSwapBuffers();
}

void Idle(void)
{
	RenderScene();
}

void MouseInput(int button, int state, int x, int y)
{
	RenderScene();
	if (button == GLUT_LEFT_BUTTON &&state == GLUT_DOWN)
	{
		LButtonDown = true;
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		if (LButtonDown && (-y+400) <0)
		{
			for (int i = 0; i < 1; i++)
			{
				
				scene->BlueCharacterAdd(x - 250, -y + 400, OBJECT_CHARACTER, TEAM_BLUE);
			}
		}
		LButtonDown = false;
	}
	RenderScene();
}
void MotionInput(int x, int y)
{
	if (LButtonDown)
	{
		//clicked
		for (int i = 0; i < 100; i++)
		{
			//g_SceneMgr->AddActorObject(x - 250, -y + 250);
		}
	}
	RenderScene();
}
void KeyInput(unsigned char key, int x, int y)
{
	RenderScene();
}

void SpecialKeyInput(int key, int x, int y)
{
	RenderScene();
}

int main(int argc, char **argv)
{
	// Initialize GL things
	//BuildObject();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 800);
	glutCreateWindow("Game Software Engineering KPU");

	glewInit();
	if (glewIsSupported("GL_VERSION_3_0"))
	{
		std::cout << " GLEW Version is 3.0\n ";
	}
	else
	{
		std::cout << "GLEW 3.0 not supported\n ";
	}
	
	// Initialize Renderer
	//g_Renderer = new Renderer(500, 500);
	//if (!g_Renderer->IsInitialized())
	//{
	//	std::cout << "Renderer could not be initialized.. \n";
	//}

	glutDisplayFunc(RenderScene);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyInput);
	glutMotionFunc(MotionInput);
	glutMouseFunc(MouseInput);
	glutSpecialFunc(SpecialKeyInput);

	scene = new sCeneMgr(500, 800);
	//for (int i = 0; i < 30; i++)
	//{
	//	float x = 250.f * 2.f * ((float)std::rand() / (float)RAND_MAX - 0.5f);
	//	float y = 250.f * 2.f * ((float)std::rand() / (float)RAND_MAX - 0.5f);
	//	scene->AddObject(x, y,OBJECT_CHARACTER);
	//}
	prevTime = timeGetTime();
	
	glutMainLoop();
	delete scene;

    return 0;
}

