#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <windows.h>


// 
// Программа, которая рисует вращающийся треугольник
// 

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}
void processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

#define W_WIDTH 800
#define W_HEIGHT 800


const char* vertexShaderSource = "#version 330 core\n" // шейдер
"layout (location = 0) in vec3 aPos;\n"
"void main() {\n"
"	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0f);\n"
"}\n\0";

const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main() {\n"
"	FragColor = vec4(1.0f,0.0f,0.0f,1.0f);\n"
"}\n\0";


int main() {
	glfwInit(); // 1.
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // 2.
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // 3.
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // 4.
	GLFWwindow* window = glfwCreateWindow(W_WIDTH, W_HEIGHT, "LearnOpenGL", NULL, NULL); // 4.

	if (window == NULL) {
		std::cout << "no window for you" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window); // 5.
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); // 6.

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "GLAD not working" << std::endl;
		return -1;
	}


	//:::::::::::::::::
	//::SHADER  SETUP::
	//:::::::::::::::::

	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER); // создаём пустышку
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "Vertex shader compilation failed\n" << infoLog << std::endl;
	}



	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER); // создаём пустышку
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);


	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

	if (!success) {
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "Fragment shader compilation failed\n" <<
			infoLog << std::endl;
	}



	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "An error occured when linking shaders to program\n" << infoLog << std::endl;
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	//::::::::::::::::
	//::SHAPE  SETUP::
	//::::::::::::::::

	float vertices[] = {
		 0.0f,  0.57735f,  0.0f,
		-0.5f, -0.288675f, 0.0f,
		 0.5f, -0.288675f, 0.0f
	};
	float convMatrix[4] = {
		0.0f, 0.0f,
		0.0f, 0.0f
	};
	float convertedVertices[] = {
		0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f
	};

	unsigned int VBO, VAO; // для хранения id

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO); // делай 1 буфер

	glBindVertexArray(VAO);// сделай из выделенного пространства рабочий буфер

	glBindBuffer(GL_ARRAY_BUFFER, VBO); // сделай из выделенного пространства рабочий буфер
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // добавь в буфер данные

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	//glBindBuffer(GL_ARRAY_BUFFER, 0);

	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	//glBindVertexArray(0);

	float x = 0;

	while (!glfwWindowShouldClose(window)) { // 8.
		processInput(window);
		glClearColor(0.0f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		convMatrix[0] =			cosf(x);//x.x
		convMatrix[1] =         sinf(x);//x.y
		convMatrix[2] =	-sinf(x);//y.x
		convMatrix[3] =			cosf(x);//y.y
		
		convertedVertices[0] = vertices[0] * convMatrix[0] + vertices[1] * convMatrix[2];
		convertedVertices[1] = vertices[0] * convMatrix[1] + vertices[1] * convMatrix[3];

		convertedVertices[3] = vertices[3] * convMatrix[0] + vertices[4] * convMatrix[2];
		convertedVertices[4] = vertices[3] * convMatrix[1] + vertices[4] * convMatrix[3];

		convertedVertices[6] = vertices[6] * convMatrix[0] + vertices[7] * convMatrix[2];
		convertedVertices[7] = vertices[6] * convMatrix[1] + vertices[7] * convMatrix[3];


		glBufferData(GL_ARRAY_BUFFER, sizeof(convertedVertices), convertedVertices, GL_DYNAMIC_DRAW);
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glfwSwapBuffers(window);
		glfwPollEvents();
		x += 0.01f;
		//Sleep(20);
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(shaderProgram);

	glfwTerminate();
	return 0;
}