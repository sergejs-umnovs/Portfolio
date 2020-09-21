#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <iostream>
#include "ShaderLoader.h"


//Program, which draws a tri-colored triangle


void framebuffer_size_callback(GLFWwindow* window, int width, int height) { // the callback function, that is being called by the window resizing
	glViewport(0, 0, width, height); // resize viewport
}

#define W_WIDTH 800
#define W_HEIGHT 600

int main() {
	glfwInit(); // initialize GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // set OpenGL version to 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); 
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 
	GLFWwindow* window = glfwCreateWindow(W_WIDTH, W_HEIGHT, "LearnOpenGL", NULL, NULL); // create a window

	if (window == NULL) { // check if window is successfully created
		std::cout << "no window for you" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window); // make the newly created window current
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); // set the callback function 
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) { // load OpenGL API
		std::cout << "GLAD not working" << std::endl; // check if it is fuccessfully loaded
		return -1;
	}

	glViewport(0, 0, W_WIDTH, W_HEIGHT);  // set an initial viewport

	//user code here
	Shader shader("C:/Users/redst/Desktop/repos/VertexShader.vsh", "C:/Users/redst/Desktop/repos/FragmentShader.fsh"); // use

	unsigned int VBO, VAO;
	float verts[] = {
		 0.0f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
		-0.5f,-0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
		 0.5f,-0.5f, 0.0f, 0.0f, 0.0f, 1.0f
	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER,sizeof(verts),verts,GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);
	
	//float timeVal, greenVal;
	int moveLocation;

	while (!glfwWindowShouldClose(window)) { // 8.
		glfwSwapBuffers(window);
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//timeVal = glfwGetTime();
		//greenVal = sin(timeVal) / 2.0f + 0.5f;
		//moveLocation = glGetUniformLocation(shader.ID, "move");
		shader.use();
		//glUniform4f(moveLocation, -0.2f, 0.0f, 0.0f, 0.0f);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glfwPollEvents();
	}

	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);
	glDeleteProgram(shader.ID);

	glfwTerminate();
	return 0;
}
