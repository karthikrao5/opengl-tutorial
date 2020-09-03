//
// Created by Karthik Rao on 8/31/20.
//

#ifndef OPENGL_TUTORIAL_CONTROLS_H
#define OPENGL_TUTORIAL_CONTROLS_H

#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

class Controls {
    GLFWwindow* window;
    // position
    glm::vec3 position = glm::vec3(0, 0, 5);
    // horizontal angle : toward -Z
    float horizontalAngle = 3.14f;
    // vertical angle : 0, look at the horizon
    float verticalAngle = 0.0f;
    // Initial Field of View
    float initialFoV = 45.0f;

    float speed = 3.0f; // 3 units / second
    float mouseSpeed = 0.005f;

    double xOffset, yOffset;
public:
    explicit Controls(GLFWwindow* window);
    void computeMatricesFromInputs();

    glm::mat4 getProjectionMatrix();

    glm::mat4 getViewMatrix();

private:
    glm::mat4 projectionMatrix{};
    glm::mat4 viewMatrix{};
    void setMouseWheelPos(double xOffset, double yOffset);
};

#endif //OPENGL_TUTORIAL_CONTROLS_H
