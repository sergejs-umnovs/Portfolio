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
	Shader shader("VertexShader.vsh", "FragmentShader.fsh"); // use a pre-written class, which makes a shader program

	unsigned int VBO, VAO; // variables to store vertex buffer object and vertex array object names
	float verts[] = { // vertex position and color data
		 0.0f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
		-0.5f,-0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
		 0.5f,-0.5f, 0.0f, 0.0f, 0.0f, 1.0f
	};

	glGenVertexArrays(1, &VAO); // generate a vertex array object name
	glGenBuffers(1, &VBO); // generate a vertex buffer object name

	glBindVertexArray(VAO); // make vertex array object
	glBindBuffer(GL_ARRAY_BUFFER, VBO); // make vertex buffer object
	glBufferData(GL_ARRAY_BUFFER,sizeof(verts),verts,GL_STATIC_DRAW); // load data into VBO 
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0); // tell vertex shader the location of vertex position data
	glEnableVertexAttribArray(0); // enable position attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)(3*sizeof(float))); // tell vertex shader the location of vertex color data
	glEnableVertexAttribArray(1); // enable color attribute

	glBindVertexArray(0); // unbind VAO
	

	while (!glfwWindowShouldClose(window)) { // main rendering loop
		glfwSwapBuffers(window); // needed to make OpenGL show the result
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // clear the screen with white color
		glClear(GL_COLOR_BUFFER_BIT);

		shader.use(); // use shader program to draw 
		
		glBindVertexArray(VAO); // bind our VAO to get data
		glDrawArrays(GL_TRIANGLES, 0, 3); // draw the triangle
		glfwPollEvents(); // listen to events (key press, mouse movement, etc.)
	}

	glDeleteBuffers(1, &VBO); // delete everything to free the memory
	glDeleteVertexArrays(1, &VAO);
	glDeleteProgram(shader.ID);

	glfwTerminate();
	return 0;
}
