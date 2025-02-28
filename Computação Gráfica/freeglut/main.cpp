#include <GL/glut.h>
#include <math.h>

// Ângulos das juntas do braço robótico
float anguloBase = 0.0f;
float anguloBraco1 = 0.0f;
float anguloBraco2 = 60.0f;
float anguloGarra = 15.0f;

// Posição da bolinha
float posicaoBolaX = 6.0f;
float posicaoBolaY = 0.5f;
float posicaoBolaZ = 0.0f;

// Ângulos para rotação da câmera
float anguloCamera = 10.0f;
float distanciaCamera = 30.0f; // Distância inicial da câmera

// Intensidade e posição da luz
float intensidadeLuz = 0.8f;
float anguloLuzHorizontal = 0.0f;
float anguloLuzVertical = 45.0f;

// Flag para indicar se a bola está presa
bool bolaPresa = false;

void inicializa()
{
    glClearColor(0.53f, 0.81f, 0.98f, 1.0f); // Céu azul
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat luzAmbiente[] = {0.2f, 0.2f, 0.2f, 1.0f};
    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
}

void atualizaIntensidadeELuz()
{
    GLfloat luzDifusa[] = {intensidadeLuz, intensidadeLuz, intensidadeLuz, 1.0f};
    GLfloat luzEspecular[] = {intensidadeLuz, intensidadeLuz, intensidadeLuz, 1.0f};

    // Calcula a posição da luz com base nos ângulos de rotação
    float posicaoLuzX = 10.0f * cos(anguloLuzHorizontal * M_PI / 180.0f);
    float posicaoLuzY = 10.0f * sin(anguloLuzVertical * M_PI / 180.0f);
    float posicaoLuzZ = 10.0f * sin(anguloLuzHorizontal * M_PI / 180.0f);
    GLfloat posicaoLuz[] = {posicaoLuzX, posicaoLuzY, posicaoLuzZ, 1.0f};

    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
    glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);
}

void aplicaMaterialPrateado()
{
    GLfloat mat_ambient[] = {0.2, 0.2, 0.2, 1.0};
    GLfloat mat_diffuse[] = {0.75, 0.75, 0.75, 1.0};
    GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat mat_shininess[] = {50.0};

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void aplicaMaterialVermelhoBrilhante()
{
    GLfloat mat_ambient[] = {0.3, 0.0, 0.0, 1.0};
    GLfloat mat_diffuse[] = {0.8, 0.1, 0.1, 1.0};
    GLfloat mat_specular[] = {1.0, 0.2, 0.2, 1.0};
    GLfloat mat_shininess[] = {60.0};

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void aplicaMaterialAmarelo()
{
    GLfloat mat_ambient[] = {0.3, 0.3, 0.0, 1.0};
    GLfloat mat_diffuse[] = {0.8, 0.8, 0.0, 1.0};
    GLfloat mat_specular[] = {1.0, 1.0, 0.0, 1.0};
    GLfloat mat_shininess[] = {50.0};

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void aplicaMaterialVerde()
{
    GLfloat mat_ambient[] = {0.0, 0.3, 0.0, 1.0};
    GLfloat mat_diffuse[] = {0.1, 0.8, 0.1, 1.0};
    GLfloat mat_specular[] = {0.2, 1.0, 0.2, 1.0};
    GLfloat mat_shininess[] = {10.0};

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void desenhaCubo(float largura, float altura, float profundidade)
{
    glPushMatrix();
    glScalef(largura, altura, profundidade);
    glutSolidCube(1.0);
    glPopMatrix();
}

void desenhaEsfera(float raio)
{
    glutSolidSphere(raio, 20, 20);
}

void desenhaPlano()
{
    aplicaMaterialVerde();
    glBegin(GL_QUADS);
    glNormal3f(0.0, 1.0, 0.0);
    glVertex3f(-50.0, 0.0, -50.0);
    glVertex3f(50.0, 0.0, -50.0);
    glVertex3f(50.0, 0.0, 50.0);
    glVertex3f(-50.0, 0.0, 50.0);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    float cameraX = distanciaCamera * sin(anguloCamera * M_PI / 180.0f);
    float cameraZ = distanciaCamera * cos(anguloCamera * M_PI / 180.0f);

    gluLookAt(cameraX, 10.0, cameraZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    atualizaIntensidadeELuz();

    desenhaPlano();

    glPushMatrix();
    glRotatef(anguloBase, 0.0, 1.0, 0.0);
    aplicaMaterialVermelhoBrilhante();
    desenhaCubo(10.0, 1.0, 10.0);

    glPushMatrix();
    glTranslatef(0.0, 3.0, 0.0);
    glRotatef(anguloBraco1, 0.0, 1.0, 0.0);
    aplicaMaterialPrateado();
    desenhaCubo(1.0, 6.0, 1.0);

    glPushMatrix();
    glTranslatef(0.0, 3.0, 0.0);
    glRotatef(anguloBraco2, 1.0, 0.0, 0.0);
    glTranslatef(0.0, 3.0, 0.0);
    desenhaCubo(1.0, 8.0, 1.0);

    glPushMatrix();
    glTranslatef(-0.6, 5.0, 0.0);
    glRotatef(-anguloGarra, 0.0, 0.0, 1.0);
    desenhaCubo(0.3, 1.5, 0.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.6, 5.0, 0.0);
    glRotatef(anguloGarra, 0.0, 0.0, 1.0);
    desenhaCubo(0.3, 1.5, 0.5);
    glPopMatrix();

    if (bolaPresa)
    {
        glPushMatrix();
        glTranslatef(0.0, 5.0, 0.0);
        aplicaMaterialAmarelo();
        desenhaEsfera(0.5);
        glPopMatrix();
    }

    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    if (!bolaPresa)
    {
        glPushMatrix();
        glTranslatef(posicaoBolaX, posicaoBolaY, posicaoBolaZ);
        aplicaMaterialAmarelo();
        desenhaEsfera(0.5);
        glPopMatrix();
    }

    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (float)w / (float)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void teclado(unsigned char tecla, int x, int y)
{
    switch (tecla)
    {
    case 27:
        exit(0);
    case 'a':
        anguloCamera -= 5.0f;
        break;
    case 'd':
        anguloCamera += 5.0f;
        break;
    case 'w':
        anguloBraco2 += 5.0;       // Aumenta o ângulo para levantar o braço
        if (anguloBraco2 > 130.0f) // Limite superior para o braço
            anguloBraco2 = 130.0f;
        break;
    case 's':
        anguloBraco2 -= 5.0;        // Diminui o ângulo para abaixar o braço
        if (anguloBraco2 < -130.0f) // Limite inferior ao tocar o chão
            anguloBraco2 = -130.0f;
        break;
    case 'q':
        anguloBraco1 += 5.0;
        break;
    case 'e':
        anguloBraco1 -= 5.0;
        break;
    case 'r':
        if (anguloGarra > 0)
            anguloGarra -= 5.0;
        break;
    case 'f':
        if (anguloGarra < 30)
            anguloGarra += 5.0;
        break;
    case 'b':
        bolaPresa = true;
        posicaoBolaX = 0.0;
        posicaoBolaY = 5.0;
        posicaoBolaZ = 0.0;
        break;
    case 'c':
        bolaPresa = false;
        posicaoBolaX = 0.0;
        posicaoBolaY = 0.5;
        posicaoBolaZ = 0.0;
        break;
    case '+':
        intensidadeLuz += 0.1f;
        if (intensidadeLuz > 1.0f)
            intensidadeLuz = 1.0f;
        break;
    case '-':
        intensidadeLuz -= 0.1f;
        if (intensidadeLuz < 0.0f)
            intensidadeLuz = 0.0f;
        break;
    case 'z': // Aproxima a câmera
        distanciaCamera -= 1.0f;
        if (distanciaCamera < 5.0f)
            distanciaCamera = 5.0f; // Limita a proximidade mínima
        break;
    case 'x': // Afasta a câmera
        distanciaCamera += 1.0f;
        if (distanciaCamera > 50.0f)
            distanciaCamera = 50.0f; // Limita a distância máxima
        break;
    }
    glutPostRedisplay();
}

void tecladoEspecial(int tecla, int x, int y)
{
    switch (tecla)
    {
    case GLUT_KEY_LEFT:
        anguloLuzHorizontal -= 5.0f;
        break;
    case GLUT_KEY_RIGHT:
        anguloLuzHorizontal += 5.0f;
        break;
    case GLUT_KEY_UP:
        if (anguloLuzVertical < 90.0f)
            anguloLuzVertical += 5.0f;
        break;
    case GLUT_KEY_DOWN:
        if (anguloLuzVertical > 0.0f)
            anguloLuzVertical -= 5.0f;
        break;
    }
    glutPostRedisplay();
}

void menu(int opcao)
{
    switch (opcao)
    {
    case 1: // Reiniciar tudo
        anguloBase = 0.0f;
        anguloBraco1 = 0.0f;
        anguloBraco2 = 60.0f;
        anguloGarra = 15.0f;
        distanciaCamera = 30.0f;
        intensidadeLuz = 0.8f;
        bolaPresa = false;
        break;
    case 0: // Sair
        exit(0);
    }
    glutPostRedisplay();
}

void criarMenu()
{
    glutCreateMenu(menu);
    glutAddMenuEntry("Reiniciar Tudo", 1);
    glutAddMenuEntry("Sair", 0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Braco Robotico com Menu Adicionado");

    inicializa();
    criarMenu();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(teclado);
    glutSpecialFunc(tecladoEspecial);

    glutMainLoop();
    return 0;
}
