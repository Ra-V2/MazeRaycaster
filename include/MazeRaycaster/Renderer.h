#pragma once

#include <GLFW/glfw3.h>

class Renderer
{
public:
	Renderer();
	~Renderer();

	bool initRenderer(GLFWwindow* window);
	void renderEntity();


private:
	GLFWwindow* glfwWindow;
	int height;
	int width;
	
};