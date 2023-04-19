#include "Renderer.h"

#include <iostream>

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

bool Renderer::initRenderer(GLFWwindow* window)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 1024, 1024, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_TEXTURE_2D);

	glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height) //lambda function to change viewport when window resize
	{
			glViewport(0, 0, width, height);
	});

	return true;
}
