// LAB 1

//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//#include <iostream>
//
//#define WIDTH 800
//#define HEIGHT 600
//
//const char* vertexShaderSource = "#version 330 core\n"
//"layout (location = 0) in vec3 aPos;\n"
//"uniform mat4 transform;\n"
//"void main()\n"
//"{\n"
//"   gl_Position = transform * vec4(aPos, 1.0f);\n"
//"}\0";
//
//const char* fragmentShaderSource = "#version 330 core\n"
//"out vec4 FragColor;\n"
//"void main()\n"
//"{\n"
//"   FragColor = vec4(247/255.0, 153/255.0, 45/255.0, 1.0);\n"
//"}\n\0";
//
//const char* outlineFragmentShaderSource = "#version 330 core\n"
//"out vec4 FragColor;\n"
//"void main()\n"
//"{\n"
//"   FragColor = vec4(0.0, 0.0, 0.0, 1.0); // Чорний колір\n"
//"}\n\0";
//
////Координати вершин
//float vertices[] = {
//        -0.4f, 0.5f, 0.0f,
//        -0.2f, 0.7f, 0.0f,
//        -0.2f, 0.5f, 0.0f,
//        -0.1f, 0.6f, 0.0f,
//        -0.1f, 0.3f, 0.0f,
//        -0.2f, 0.4f, 0.0f,
//        -0.3f, 0.3f, 0.0f,
//        -0.2f, 0.2f, 0.0f,
//        0.1f, 0.5f, 0.0f,
//        0.4f, 0.2f, 0.0f,
//        0.2f, 0.2f, 0.0f,
//        0.2f, -0.2f, 0.0f,
//        0.1f, -0.1f, 0.0f,
//        0.3f, -0.3f, 0.0f,
//        0.1f, -0.5f, 0.0f,
//        0.2f, -0.4f, 0.0f,
//        0.0f, -0.6f, 0.0f,
//        0.2f, -0.6f, 0.0f,
//};
//
//unsigned int indices[] = {
//    0, 1, 2,
//    1, 3, 4,//Паралелограм
//    1, 5, 4,
//    5, 4, 7,//Ромб
//    5, 6, 7,
//    7, 8, 9,
//    7, 10, 11,
//    12, 13, 14,
//    15, 16, 17,
//};
//
//unsigned int line_indices[] = {
//    0, 1,
//    0, 2,
//    1, 5,
//    1, 3,
//    5, 4,
//    3, 4,
//    5, 6,
//    6, 13,
//    7, 8,
//    8, 9,
//    7, 9,
//    13, 16,
//    16, 17,
//    15, 17,
//    12, 14,
//    10, 11,
//};
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//    glViewport(0, 0, width, height);
//}
//
//void processInput(GLFWwindow* window)
//{
//    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//        glfwSetWindowShouldClose(window, true);
//}
//
//void renderTriangles(unsigned int shaderProgram, unsigned int VAO, glm::mat4 transform)
//{
//    glUseProgram(shaderProgram);
//    unsigned int transformLoc = glGetUniformLocation(shaderProgram, "transform");
//    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
//
//    glBindVertexArray(VAO);
//    glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(unsigned int), GL_UNSIGNED_INT, 0);
//    glBindVertexArray(0);
//}
//
//void renderLines(unsigned int outlineShaderProgram, unsigned int lineVAO, glm::mat4 transform)
//{
//    glUseProgram(outlineShaderProgram);
//    unsigned int transformLoc = glGetUniformLocation(outlineShaderProgram, "transform");
//    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
//    glBindVertexArray(lineVAO);
//    glDrawElements(GL_LINES, sizeof(line_indices) / sizeof(unsigned int), GL_UNSIGNED_INT, 0);
//    glBindVertexArray(0);
//}
//
//int main()
//{
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//
//    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Creature", NULL, NULL);
//    if (window == NULL)
//    {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//    glfwMakeContextCurrent(window);
//
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//    {
//        std::cout << "Failed to initialize GLAD" << std::endl;
//        return -1;
//    }
//
//    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//    unsigned int vertexShader, fragmentShader, outlineFragmentShader, shaderProgram, outlineShaderProgram;
//
//    vertexShader = glCreateShader(GL_VERTEX_SHADER);
//    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//    glCompileShader(vertexShader);
//
//    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//    glCompileShader(fragmentShader);
//
//    outlineFragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(outlineFragmentShader, 1, &outlineFragmentShaderSource, NULL);
//    glCompileShader(outlineFragmentShader);
//
//    shaderProgram = glCreateProgram();
//    glAttachShader(shaderProgram, vertexShader);
//    glAttachShader(shaderProgram, fragmentShader);
//    glLinkProgram(shaderProgram);
//
//    outlineShaderProgram = glCreateProgram();
//    glAttachShader(outlineShaderProgram, vertexShader);
//    glAttachShader(outlineShaderProgram, outlineFragmentShader);
//    glLinkProgram(outlineShaderProgram);
//
//    glDeleteShader(vertexShader);
//    glDeleteShader(fragmentShader);
//    glDeleteShader(outlineFragmentShader);
//
//    unsigned int VBO, VAO, EBO;
//
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//    glGenBuffers(1, &EBO);
//
//    glBindVertexArray(VAO);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
//    glBindVertexArray(0);
//
//    unsigned int lineVAO, lineVBO, lineEBO;
//
//    glGenVertexArrays(1, &lineVAO);
//    glGenBuffers(1, &lineVBO);
//    glGenBuffers(1, &lineEBO);
//
//    glBindVertexArray(lineVAO);
//    glBindBuffer(GL_ARRAY_BUFFER, lineVBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, lineEBO);
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(line_indices), line_indices, GL_STATIC_DRAW);
//
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
//    glBindVertexArray(0);
//
//    float up_down = 0.0f, left_right = 0.0f, speed = 0.0001f;
//    glm::vec2 displacementVector = glm::vec2(0.5f, 1.0f);  
//
//    while (!glfwWindowShouldClose(window))
//    {
//        processInput(window);
//
//        glClearColor(60 / 255.0, 75 / 255.0, 203 / 255.0, 1.0);
//        glClear(GL_COLOR_BUFFER_BIT);
//
//        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) 
//        {
//            up_down += displacementVector.y * speed; 
//        }
//        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) 
//        {
//            up_down -= displacementVector.y * speed;  
//        }
//        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) 
//        {
//            left_right -= displacementVector.x * speed; 
//        }
//        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) 
//        {
//            left_right += displacementVector.x * speed; 
//        }
//
//        glm::mat4 transform = glm::translate(glm::mat4(1.0f), glm::vec3(left_right, up_down, 0.0f));
//
//        renderTriangles(shaderProgram, VAO, transform);
//        renderLines(outlineShaderProgram, lineVAO, transform);
//
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//
//    glDeleteVertexArrays(1, &VAO);
//    glDeleteBuffers(1, &VBO);
//    glDeleteBuffers(1, &EBO);
//
//    glDeleteVertexArrays(1, &lineVAO);
//    glDeleteBuffers(1, &lineVBO);
//    glDeleteBuffers(1, &lineEBO);
//
//    glfwTerminate();
//    return 0;
//}
//

// LAB 2

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
const float PHI = (1.0f + sqrt(5.0f)) / 2.0f;
const float SCALE = 0.5f;

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void setMat4(unsigned int ID, const std::string& name, const glm::mat4& mat)
{
    glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"uniform mat4 model;"
"uniform mat4 projection;"
"uniform mat4 view;"
"void main()\n"
"{\n"
"   gl_Position = projection * view * model * vec4(aPos, 1.0f);\n"
"}\0";
const char* fragmentOctahedronShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.937f, 0.137f, 0.235f, 1.0f); // #ef233c\n"
"}\n\0";
const char* fragmentDodecahedronShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.0f, 0.243f, 0.125f, 1.0f); // #003e1f\n"
"}\n\0";
const char* fragmentPlaneShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);\n"
"}\n\0";


int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glEnable(GL_DEPTH_TEST);

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    int  success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    unsigned int fragmentShaderOctahedron = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShaderOctahedron, 1, &fragmentOctahedronShaderSource, NULL);
    glCompileShader(fragmentShaderOctahedron);
    glGetShaderiv(fragmentShaderOctahedron, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShaderOctahedron, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    unsigned int fragmentShaderDodecahedron = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShaderDodecahedron, 1, &fragmentDodecahedronShaderSource, NULL);
    glCompileShader(fragmentShaderDodecahedron);
    glGetShaderiv(fragmentShaderDodecahedron, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShaderDodecahedron, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    unsigned int fragmentShaderPlane = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShaderPlane, 1, &fragmentPlaneShaderSource, NULL);
    glCompileShader(fragmentShaderPlane);
    glGetShaderiv(fragmentShaderPlane, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShaderPlane, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    unsigned int shaderProgramOctahedron = glCreateProgram();
    glAttachShader(shaderProgramOctahedron, vertexShader);
    glAttachShader(shaderProgramOctahedron, fragmentShaderOctahedron);
    glLinkProgram(shaderProgramOctahedron);
    glGetProgramiv(shaderProgramOctahedron, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgramOctahedron, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    unsigned int shaderProgramDodecahedron = glCreateProgram();
    glAttachShader(shaderProgramDodecahedron, vertexShader);
    glAttachShader(shaderProgramDodecahedron, fragmentShaderDodecahedron);
    glLinkProgram(shaderProgramDodecahedron);
    glGetProgramiv(shaderProgramDodecahedron, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgramDodecahedron, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    unsigned int shaderProgramPlane = glCreateProgram();
    glAttachShader(shaderProgramPlane, vertexShader);
    glAttachShader(shaderProgramPlane, fragmentShaderPlane);
    glLinkProgram(shaderProgramPlane);
    glGetProgramiv(shaderProgramPlane, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgramPlane, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShaderOctahedron);
    glDeleteShader(fragmentShaderDodecahedron);
    glDeleteShader(fragmentShaderPlane);

    float octahedron_vertices[] = {
        /*0.0f,  0.0f, 0.7f,
        0.0f,  -0.7f, 0.0f,
        -0.7f,  0.0f,  0.0f,

        0.0f,  0.0f, 0.7f,
        0.0f,  -0.7f, 0.0f,
        0.7f,  0.0f,  0.0f,

        0.0f,  0.0f, 0.7f,
        0.7f,  0.0f, 0.0f,
        0.0f,  0.7f,  0.0f,

        0.0f,  0.0f, 0.7f,
        0.0f,  0.7f, 0.0f,
        -0.7f,  0.0f,  0.0f,

        0.0f,  0.0f, -0.7f,
        0.0f,  -0.7f, 0.0f,
        -0.7f,  0.0f,  0.0f,

        0.0f,  0.0f, -0.7f,
        0.0f,  -0.7f, 0.0f,
        0.7f,  0.0f,  0.0f,

        0.0f,  0.0f, -0.7f,
        0.7f,  0.0f, 0.0f,
        0.0f,  0.7f,  0.0f,

        0.0f,  0.0f, -0.7f,
        0.0f,  0.7f, 0.0f,
        -0.7f,  0.0f,  0.0f,*/

       SCALE * 0.0f,  SCALE * 0.0f, SCALE * 1.0f,  // D
       SCALE * 0.0f, -SCALE * 1.0f, SCALE * 0.0f,  // A
       SCALE * 0.0f,  SCALE * 1.0f, SCALE * 0.0f,  // B
       SCALE * 1.0f,  SCALE * 0.0f, SCALE * 0.0f,  // E
      -SCALE * 1.0f,  SCALE * 0.0f, SCALE * 0.0f,  // C
       SCALE * 0.0f,  SCALE * 0.0f, -SCALE * 1.0f, // F
    };

    int octahedron_indices[] = {
        0, 1, 3, // D-A-E
        0, 3, 2, // D-E-B
        0, 2, 4, // D-B-C
        0, 4, 1, // D-C-A
        5, 1, 3, // F-A-E
        5, 3, 2, // F-E-B
        5, 2, 4, // F-B-C
        5, 4, 1  // F-C-A
    };

    float dodecahedron_vertices[] = {
        SCALE * 1.0f,  SCALE * 1.0f,  SCALE * 1.0f,//0 A
        SCALE * 1.0f,  SCALE * 1.0f, -SCALE * 1.0f,//1 B
        SCALE * 1.0f, -SCALE * 1.0f,  SCALE * 1.0f,//2 C
        SCALE * 1.0f, -SCALE * 1.0f, -SCALE * 1.0f,//3 D
        SCALE * -1.0f, SCALE * 1.0f,  SCALE * 1.0f,//4  E
        SCALE * -1.0f, SCALE * 1.0f, -SCALE * 1.0f,//5 F 
        SCALE * -1.0f, SCALE * -1.0f, SCALE * 1.0f,//6 G
        SCALE * -1.0f, SCALE * -1.0f, -SCALE * 1.0f,//7 H
        SCALE * 0.0f,  SCALE * (1.0f / PHI), SCALE * PHI,//8 I
        SCALE * 0.0f,  SCALE * (1.0f / PHI), SCALE * -PHI,//9 J 
        SCALE * 0.0f,  SCALE * (-1.0f / PHI), SCALE * PHI,//10 K
        SCALE * 0.0f,  SCALE * (-1.0f / PHI), SCALE * -PHI,//11 L
        SCALE * PHI,   SCALE * 0.0f,  SCALE * (1.0f / PHI),//12 M
        SCALE * PHI,   SCALE * 0.0f,  SCALE * (-1.0f / PHI),//13 U
        SCALE * -PHI,  SCALE * 0.0f,  SCALE * (1.0f / PHI),//14 O
        SCALE * -PHI,  SCALE * 0.0f,  SCALE * (-1.0f / PHI),//15 P
        SCALE * (1.0f / PHI), SCALE * PHI,   SCALE * 0.0f,//16 Q
        SCALE * (-1.0f / PHI), SCALE * PHI,  SCALE * 0.0f,//17 R
        SCALE * (1.0f / PHI), SCALE * -PHI,  SCALE * 0.0f,//18 S
        SCALE * (-1.0f / PHI), SCALE * -PHI, SCALE * 0.0f//19 T
    };

    unsigned int dodecahedron_indices[] = {
        0, 8, 8, 4, 4, 17, 17, 16, 16, 0,
        6, 10, 10, 2, 2, 18, 18, 19, 19, 6,
        8, 10, 10, 6, 6, 14, 14, 4, 4, 8,
        10, 8, 8, 0, 0, 12, 12, 2, 2, 10,
        14, 6, 6, 19, 19, 7, 7, 15, 15, 14,
        17, 4, 4, 14, 14, 15, 15, 5, 5, 17,
        7, 19, 19, 18, 18, 3, 3, 11, 11, 7,
        18, 2, 2, 12, 12, 13, 13, 3, 3, 18,
        12, 0, 0, 16, 16, 1, 1, 13, 13, 12,
        1, 16, 16, 17, 17, 5, 5, 9, 9, 1,
        13, 1, 1, 9, 9, 11, 11, 3, 3, 13,
        9, 5, 5, 15, 15, 7, 7, 11, 11, 9,
    };

    const int num_of_steps = 20;
    const int total_values = (6 * (num_of_steps - 1) * (num_of_steps - 1)) * 3;
    float plane_vertices[total_values];
    int k = 0;

    for (int i = 0; i < num_of_steps - 1; i++) {
        for (int j = 0; j < num_of_steps - 1; j++) {
            float x1 = -1 + i * (2.0f / num_of_steps);
            float y1 = -1 + j * (2.0f / num_of_steps);
            float x2 = -1 + (i + 1) * (2.0f / num_of_steps);
            float y2 = -1 + (j + 1) * (2.0f / num_of_steps);

            plane_vertices[k++] = x1; plane_vertices[k++] = y1; plane_vertices[k++] = sin(x1) * sqrt(fabs(y1));
            plane_vertices[k++] = x2; plane_vertices[k++] = y1; plane_vertices[k++] = sin(x2) * sqrt(fabs(y1));
            plane_vertices[k++] = x1; plane_vertices[k++] = y2; plane_vertices[k++] = sin(x1) * sqrt(fabs(y2));

            plane_vertices[k++] = x2; plane_vertices[k++] = y1; plane_vertices[k++] = sin(x2) * sqrt(fabs(y1));
            plane_vertices[k++] = x1; plane_vertices[k++] = y2; plane_vertices[k++] = sin(x1) * sqrt(fabs(y2));
            plane_vertices[k++] = x2; plane_vertices[k++] = y2; plane_vertices[k++] = sin(x2) * sqrt(fabs(y2));
        }
    }

    glm::vec3 positions[] = {
        glm::vec3(2.0f,  0.0f,  0.0f),
        glm::vec3(-2.0f,  0.0f,  0.0f),
    };

    unsigned int VBOs[3], VAOs[3], EBOs[3];
    glGenVertexArrays(3, VAOs);
    glGenBuffers(3, VBOs);
    glGenBuffers(3, EBOs);

    glBindVertexArray(VAOs[0]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(plane_vertices), plane_vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(VAOs[1]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(octahedron_vertices), octahedron_vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[0]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(octahedron_indices), octahedron_indices, GL_STATIC_DRAW);

    glBindVertexArray(VAOs[2]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[2]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(dodecahedron_vertices), dodecahedron_vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(dodecahedron_indices), dodecahedron_indices, GL_STATIC_DRAW);


    glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
    float rotate_side = 0.0f, rotate_up = 0.0f, vec_up = 1.0f;

    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        glClearColor(213.0f / 255.0f, 242.0f / 255.0f, 227.0f / 255.0f, 1.0f); // rgba: #d5f2e3
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
            rotate_up += 0.05f;
        }
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
            rotate_up -= 0.05f;
        }
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
            rotate_side -= 0.05f;
        }
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
            rotate_side += 0.05f;
        }

        if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS) {
            projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        }
        if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS) {
            projection = glm::ortho(-3.0f, 3.0f, -3.0f, 3.0f, 0.1f, 100.0f);
        }

        glm::mat4 view = glm::mat4(1.0f);
        float radius = 6.0f;
        float camX = static_cast<float>(sin(glm::radians(rotate_side)) * cos(glm::radians(rotate_up)) * radius);
        float camZ = static_cast<float>(cos(glm::radians(rotate_side)) * cos(glm::radians(rotate_up)) * radius);
        float camY = static_cast<float>(sin(glm::radians(rotate_up)) * radius);
        if ((sin(glm::radians(rotate_up)) == 1) || (sin(glm::radians(rotate_up)) == -1))
            vec_up *= -1;
        view = glm::lookAt(glm::vec3(camX, camY, camZ), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, vec_up, 0.0f));

        glUseProgram(shaderProgramPlane);
        setMat4(shaderProgramPlane, "view", view);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glBindVertexArray(VAOs[0]);
        glm::mat4 model = glm::mat4(1.0f);
        setMat4(shaderProgramPlane, "projection", projection);
        setMat4(shaderProgramPlane, "model", model);
        glDrawArrays(GL_TRIANGLES, 0, sizeof(plane_vertices) / sizeof(float));

        glUseProgram(shaderProgramOctahedron);
        setMat4(shaderProgramOctahedron, "view", view);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glBindVertexArray(VAOs[1]);
        model = glm::translate(model, positions[0]);
        setMat4(shaderProgramOctahedron, "projection", projection);
        setMat4(shaderProgramOctahedron, "model", model);
        glDrawElements(GL_TRIANGLES, sizeof(octahedron_indices) / sizeof(unsigned int), GL_UNSIGNED_INT, 0);

        glUseProgram(shaderProgramDodecahedron);
        setMat4(shaderProgramDodecahedron, "view", view);
        setMat4(shaderProgramDodecahedron, "projection", projection);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glBindVertexArray(VAOs[2]);
        model = glm::mat4(1.0f);
        model = glm::translate(model, positions[1]);
        setMat4(shaderProgramDodecahedron, "model", model);
        glDrawElements(GL_LINES, sizeof(dodecahedron_indices) / sizeof(unsigned int), GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(3, VAOs);
    glDeleteBuffers(3, VBOs);
    glDeleteProgram(shaderProgramOctahedron);
    glDeleteProgram(shaderProgramDodecahedron);
    glDeleteProgram(shaderProgramPlane);

    glfwTerminate();
    return 0;
}
