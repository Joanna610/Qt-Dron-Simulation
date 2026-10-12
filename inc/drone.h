#ifndef DRONE_H
#define DRONE_H

#include <QMatrix4x4>
#include <unordered_map>
#include <iterator>

#include "inc/Object.h"

struct Matrices{
    QMatrix4x4 mvpMatrix;
    QMatrix4x4 normalMatrix;
};

class Drone
{
public:
    Drone();
    ~Drone() = default;

    bool setShaders(QOpenGLShaderProgram *shaderProgramm);
    std::vector<Matrices> setMatrices(const QMatrix4x4& worldToView) const;
    void drawElement(const int & index) const;
    void startPropellers();
    void moveForward();
    void moveBackward();
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();

private:
    std::unordered_multimap<std::string, std::unique_ptr<Object>>         m_objects;
};

#endif // DRONE_H
