#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <iostream>
#include "ShaderLoader.h"


//Программа, которая рисует цветной треугольник


void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}
void processInput(GLFWwindow* window) {

}

#define W_WIDTH 800
#define W_HEIGHT 600

int main() {
	glfwInit(); 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); 
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 
	GLFWwindow* window = glfwCreateWindow(W_WIDTH, W_HEIGHT, "LearnOpenGL", NULL, NULL); 

	if (window == NULL) {
		std::cout << "no window for you" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window); // 5.
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); 
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "GLAD not working" << std::endl;
		return -1;
	}

	glViewport(0, 0, W_WIDTH, W_HEIGHT);  // 7.

	//user code here
	Shader shader("C:/Users/redst/Desktop/repos/VertexShader.vsh", "C:/Users/redst/Desktop/repos/FragmentShader.fsh");

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
		processInput(window);
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