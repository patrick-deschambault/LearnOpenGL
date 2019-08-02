// FirstOpenGL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//STL libraries
#include <iostream>

//GL Files
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

float vertices[] = {

	-0.5f, -0.5f, 0.0f,
	0.5f, -0.5f, 0.0f,
	0.0f, 0.5f, 0.0f

};


int main()
{
	//Init GL
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

	//Create Window GLFW
	GLFWwindow* window = glfwCreateWindow(800, 600, "My first GLFW Window!", NULL, NULL);
	if (window == nullptr)
	{
		std::cout << "Failed to create GLFW Window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	//GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	//Tell opengl size of window for rendering
	glViewport(0, 0, 800, 600);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


	unsigned int VBO;
	glGenBuffers(1, &VBO);


	glBindBuffer(GL_ARRAY_BUFFER, VBO);



	//Loop to keep window
	while (!glfwWindowShouldClose(window))
	{
		//Input
		processInput(window);


		//Process rendering
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//check and call events and swap the buffers
		glfwSwapBuffers(window);
		glfwPollEvents();

	}


	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

}


