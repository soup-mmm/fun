#ifdef __APPLE_CC__
#else
#include <GL/glut.h>
#endif
void triangle(
    float Fxyz, bool Fnp, // set which way your facing
    float x1, float y1, float z1,// set position of point
    float x2, float y2, float z2,
    float x3, float y3, float z3){

    // Finds the triangle normal and sets front and back face
    float ax = x2 - x1;
    float ay = y2 - y1;
    float az = z2 - z1;
    float bx = x3 - x1;
    float by = y3 - y1;
    float bz = z3 - z1;
    float nx = ay * bz - az * by;
    float ny = az * bx - ax * bz;
    float nz = ax * by - ay * bx;

    float normal = 0.0f;
    if (Fxyz == 0)
        normal = nz;

    else if (Fxyz == 1)
        normal = ny;

    else if (Fxyz == 2)
        normal = nx;

    bool reverse = false;
    if (Fnp && normal < 0.0f)
        reverse = true;
    if (!Fnp && normal > 0.0f)
        reverse = true;
    glBegin(GL_TRIANGLES);
    if (!reverse)
    {
        glVertex3f(x1, y1, z1);
        glVertex3f(x2, y2, z2);
        glVertex3f(x3, y3, z3);
    }
    else
    {
        glVertex3f(x1, y1, z1);
        glVertex3f(x3, y3, z3);
        glVertex3f(x2, y2, z2);
    }
  glEnd();
  glFlush();
}

void display() {
    glColor3f(1, 0, 0);
    triangle(0, true,/*face*/ -0.6, -0.75, 0.5,/*1*/0.6, -0.75, 0,/*2*/0, 0.75, 0/*3*/);
}

int main(int argc, char** argv) {
  // make the window
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(400, 300);
  glutCreateWindow("Template");
  // Enable face culling
  glEnable(GL_CULL_FACE);
  glCullFace(GL_BACK);
  glFrontFace(GL_CCW);
  // start the window
  glutDisplayFunc(display);
  glutMainLoop();
}
