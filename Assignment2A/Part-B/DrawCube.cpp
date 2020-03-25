// DrawCube.cpp
// Generate a Cube


#include "GL/glew.h"
#include <stdio.h>
#include <stdlib.h>
#include "GLFW/glfw3.h"
#include "include/Angel.h"

typedef  vec4  point4;
typedef  vec4  color4;

GLuint shader_programme;
GLuint vao;

int Index = 0;
const int NumVertices = 36;
point4 points[NumVertices];
color4 colors[NumVertices];

// global color variable
GLint col;
//----------------------------------------------------------------------------

point4 vertices[8] = {
	point4(-0.5, -0.5, 0.5, 1.0),
	point4(-0.5, 0.5, 0.5, 1.0),
	point4(0.5, 0.5, 0.5, 1.0),
	point4(0.5, -0.5, 0.5, 1.0),
	point4(-0.5, -0.5, -0.5, 1.0),
	point4(-0.5, 0.5, -0.5, 1.0),
	point4(0.5, 0.5, -0.5, 1.0),
	point4(0.5, -0.5, -0.5, 1.0)
};

// RGBA olors
color4 vertex_colors[8] = {
	color4(0.0, 0.0, 0.0, 1.0),  // black
	color4(1.0, 0.0, 0.0, 1.0),  // red
	color4(1.0, 1.0, 0.0, 1.0),  // yellow
	color4(0.0, 1.0, 0.0, 1.0),  // green
	color4(0.0, 0.0, 1.0, 1.0),  // blue
	color4(1.0, 0.0, 1.0, 1.0),  // magenta
	color4(1.0, 1.0, 1.0, 1.0),  // white
	color4(0.0, 1.0, 1.0, 1.0)   // cyan
};

void
quad(int a, int b, int c, int d)
{
	points[Index] = vertices[a]; Index++;
	points[Index] = vertices[b]; Index++;
	points[Index] = vertices[c]; Index++;
	points[Index] = vertices[a]; Index++;
	points[Index] = vertices[c]; Index++;
	points[Index] = vertices[d]; Index++;
}
void
colorcube()
{
	quad(1, 0, 3, 2);
	quad(2, 3, 7, 6);
	quad(3, 0, 4, 7);
	quad(6, 5, 1, 2);
	quad(4, 5, 6, 7);
	quad(5, 4, 0, 1);
}

void init(void)
{
	colorcube();
	GLuint vert_shader, frag_shader;
	/* GL shader programme object [combined, to link] */

	// Specifiy the vertices for a triangle
	//GLfloat points[] = { -0.5, 0.5, 0.5, 0.5, 0.0, -0.5 };


	// Create and initialize a buffer object
	GLuint buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);

	// Create a vertex array object

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	// "attribute #0 is created from every 2 variables in the above buffer, of type
	// float (i.e. make me vec2s)"
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, NULL);

	// Load shaders and use the resulting shader program
	const char *vertex_shader = "#version 410\n"
		"in vec4 vPosition;"
		"void main () {"
		"	gl_Position = vPosition;"
		"}";
	/* the fragment shader colours each fragment (pixel-sized area of the
	triangle) */
	const char *fragment_shader = "#version 410\n"
		"uniform vec4 color = vec4(1.0, 0.0, 0.0, 1.0);"
		"out vec4 FragColor;"
		"void main () {"
		"	/*FragColor = vec4( 1.0, 0.0, 0.0, 1.0 );*/"
		"	FragColor = color;"
		"}";



	vert_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vert_shader, 1, &vertex_shader, NULL);
	glCompileShader(vert_shader);
	frag_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(frag_shader, 1, &fragment_shader, NULL);
	glCompileShader(frag_shader);
	shader_programme = glCreateProgram();
	glAttachShader(shader_programme, frag_shader);
	glAttachShader(shader_programme, vert_shader);
	glLinkProgram(shader_programme);


}

void mouse_exit(GLFWwindow* window, int button, int action, int mods) {
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) {
		// exit the application
		glfwDestroyWindow(window);
		glfwTerminate();
		exit(EXIT_SUCCESS);
	}
}

void keyboard_color(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (action == GLFW_PRESS) {
		col = glGetUniformLocation(shader_programme, "color");
		int r = 0, g = 0, b = 0;
		while (r == 0 && g == 0 && b == 0) {
			r = rand() % 2;
			g = rand() % 2;
			b = rand() % 2;
		}
		vec4 m = vec4(r, g, b, 1.0);
		glUniform4fv(col, 1, m);
	}
}


//----------------------------------------------------------------------------

int main(int argc, char **argv)
{
	GLFWwindow *window = NULL;
	const GLubyte *renderer;
	const GLubyte *version;
	/* start GL context and O/S window using the GLFW helper library */
	if (!glfwInit()) {
		fprintf(stderr, "ERROR: could not start GLFW3\n");
		return 1;
	}

	/* We must specify 3.2 core if on Apple OS X -- other O/S can specify
	anything here. I defined 'APPLE' in the makefile for OS X
	Remove the #ifdef #endif and play around with this - you should be starting
	an explicit version anyway, and some non-Apple drivers will require this too.
	*/
#ifdef __APPLE__
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif
	window = glfwCreateWindow(640, 640, "Draw Cube", NULL, NULL);

	if (!window) {
		fprintf(stderr, "ERROR: could not open window with GLFW3\n");
		glfwTerminate();
		return 1;
	}
	glfwMakeContextCurrent(window);
	/* start GLEW extension handler */
	glewExperimental = GL_TRUE;
	glewInit();
	renderer = glGetString(GL_RENDERER); /* get renderer string */
	version = glGetString(GL_VERSION);	 /* version as a string */
	printf("Renderer: %s\n", renderer);
	printf("OpenGL version supported %s\n", version);
	init();

	// link shader once
	glUseProgram(shader_programme);

	// callbacks
	glfwSetMouseButtonCallback(window, mouse_exit);
	glfwSetKeyCallback(window, keyboard_color);

	do {
		glClear(GL_COLOR_BUFFER_BIT);     // clear the window
		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, NumVertices);    // draw the points
													   /* update other events like input handling */
		glfwPollEvents();
		glfwSwapBuffers(window);
	} while (!glfwWindowShouldClose(window));

	// Close OpenGL window and terminate GLFW
	glfwTerminate();
	return 0;

}
