#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
//#include <windows.h>

//
// Программа, которая рисует два треугольника - один жёлтый, второй - красный
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

const char* redFragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main() {\n"
"	FragColor = vec4(1.0f,0.0f,0.0f,1.0f);\n"
"}\n\0";

const char* yellowFragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main() {\n"
"	FragColor = vec4(1.0f,0.8f,0.0f,1.0f);\n"
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



	unsigned int redFragmentShader = glCreateShader(GL_FRAGMENT_SHADER); // создаём пустышку
	glShaderSource(redFragmentShader, 1, &redFragmentShaderSource, NULL);
	glCompileShader(redFragmentShader);
	glGetShaderiv(redFragmentShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(redFragmentShader, 512, NULL, infoLog);
		std::cout << "Red fragment shader compilation failed\n" <<
			infoLog << std::endl;
	}

	unsigned int yellowFragmentShader = glCreateShader(GL_FRAGMENT_SHADER); // создаём пустышку
	glShaderSource(yellowFragmentShader, 1, &yellowFragmentShaderSource, NULL);
	glCompileShader(yellowFragmentShader);
	glGetShaderiv(yellowFragmentShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(yellowFragmentShader, 512, NULL, infoLog);
		std::cout << "Yellow fragment shader compilation failed\n" <<
			infoLog << std::endl;
	}



	unsigned int redShaderProgram, yellowShaderProgram;

	redShaderProgram = glCreateProgram();
	glAttachShader(redShaderProgram, vertexShader);
	glAttachShader(redShaderProgram, redFragmentShader);
	glLinkProgram(redShaderProgram);
	glGetProgramiv(redShaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(redShaderProgram, 512, NULL, infoLog);
		std::cout << "An error occured when linking shaders to red shader program\n" << infoLog << std::endl;
	}
	
	yellowShaderProgram = glCreateProgram();
	glAttachShader(yellowShaderProgram, vertexShader);
	glAttachShader(yellowShaderProgram, yellowFragmentShader);
	glLinkProgram(yellowShaderProgram);
	glGetProgramiv(yellowShaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(yellowShaderProgram, 512, NULL, infoLog);
		std::cout << "An error occured when linking shaders to yellow shader program\n" << infoLog << std::endl;
	}



	glDeleteShader(redFragmentShader);
	glDeleteShader(yellowFragmentShader);
	glDeleteShader(vertexShader);

	//::::::::::::::::
	//::SHAPE  SETUP::
	//::::::::::::::::

	//float regTriVertices[] = {
	//	 -0.2f,  0.57735f,  0.0f,
	//	 -0.7f, -0.288675f, 0.0f,
	//	  0.3f, -0.288675f, 0.0f
	//};

	float vertices1[] = {
		0.1f, 0.7f, 0.0f,
		0.1f, 0.0f, 0.0f,
		0.4f, 0.0f, 0.0f
	};

	float vertices2[] = {
		-0.1f, 0.7f, 0.0f,
		-0.1f, 0.0f, 0.0f,
		-0.4f, 0.0f, 0.0f
	};

	//float convMatrix[4] = {
	//	0.0f, 0.0f,
	//	0.0f, 0.0f
	//};
	//float convertedVertices[] = {
	//	0.0f, 0.0f, 0.0f,
	//	0.0f, 0.0f, 0.0f,
	//	0.0f, 0.0f, 0.0f
	//};

	unsigned int VBO1, VAO1, VBO2, VAO2; // для хранения id

	glGenVertexArrays(1, &VAO1);
	glGenBuffers(1, &VBO1); // делай 1 буфер

	glGenVertexArrays(1, &VAO2);
	glGenBuffers(1, &VBO2);

	glBindVertexArray(VAO1);// сделай из выделенного пространства рабочий буфеp
	glBindBuffer(GL_ARRAY_BUFFER, VBO1); // сделай из выделенного пространства рабочий буфер
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW); // добавь в буфер данные
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(VAO2);
	glBindBuffer(GL_ARRAY_BUFFER, VBO2);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW); // добавь в буфер данные
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);


	//glBindBuffer(GL_ARRAY_BUFFER, 0);

	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	//glBindVertexArray(0);

	//float x = 0;

	while (!glfwWindowShouldClose(window)) { // 8.
		processInput(window);
		glClearColor(0.0f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		//convMatrix[0] =			cosf(x);//x.x
		//convMatrix[1] =         sinf(x);//x.y
		//convMatrix[2] =	-sinf(x);//y.x
		//convMatrix[3] =			cosf(x);//y.y
		
		//convertedVertices[0] = vertices[0] * convMatrix[0] + vertices[1] * convMatrix[2];
		//convertedVertices[1] = vertices[0] * convMatrix[1] + vertices[1] * convMatrix[3];

		//convertedVertices[3] = vertices[3] * convMatrix[0] + vertices[4] * convMatrix[2];
		//convertedVertices[4] = vertices[3] * convMatrix[1] + vertices[4] * convMatrix[3];

		//convertedVertices[6] = vertices[6] * convMatrix[0] + vertices[7] * convMatrix[2];
		//convertedVertices[7] = vertices[6] * convMatrix[1] + vertices[7] * convMatrix[3];


		//glBufferData(GL_ARRAY_BUFFER, sizeof(convertedVertices), convertedVertices, GL_DYNAMIC_DRAW);
		glUseProgram(redShaderProgram);
		glBindVertexArray(VAO1);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glUseProgram(yellowShaderProgram);
		glBindVertexArray(VAO2);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glfwSwapBuffers(window);
		glfwPollEvents();
		//x += 0.01f;
		//Sleep(20);
	}

	glDeleteVertexArrays(1, &VAO1);
	glDeleteBuffers(1, &VBO1);
	glDeleteVertexArrays(1, &VAO2);
	glDeleteBuffers(1, &VBO2);
	glDeleteProgram(redShaderProgram);
	glDeleteProgram(yellowShaderProgram);


	glfwTerminate();
	return 0;
}