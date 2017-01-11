/*
.
.
Author : Dwi Ilham Yanuar
www.github.com/IlhamYanuar

make 3D shape "scarecrow"
.
.
*/

#include <GL/glut.h>       // gltools library

typedef float	M3DVector3f[3];
// Rotation amounts
static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;

void m3dCrossProduct(M3DVector3f result, const M3DVector3f u, const M3DVector3f v)
	{
	result[0] = u[1]*v[2] - v[1]*u[2];
	result[1] = -u[0]*v[2] + v[0]*u[2];
	result[2] = u[0]*v[1] - v[0]*u[1];
	}

void m3dFindNormal(M3DVector3f result, const M3DVector3f point1, const M3DVector3f point2,
							const M3DVector3f point3)
	{
	M3DVector3f v1,v2;		// Temporary vectors

	// Calculate two vectors from the three points. Assumes counter clockwise
	// winding!
	v1[0] = point1[0] - point2[0];
	v1[1] = point1[1] - point2[1];
	v1[2] = point1[2] - point2[2];

	v2[0] = point2[0] - point3[0];
	v2[1] = point2[1] - point3[1];
	v2[2] = point2[2] - point3[2];

	// Take the cross product of the two vectors to get
	// the normal vector.
	m3dCrossProduct(result, v1, v2);
	}


// Called to draw scene
void RenderScene(void)
	{
	GLUquadricObj *pObj; // Quadric object
	M3DVector3f vNormal;	// Storeage for calculated surface normal

	// Clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/****************************************************************************/

	/****************************************************************************/


	// Save the matrix state and do the rotations
	glPushMatrix();
	glTranslatef(0.0f, 10.0f, 0.0f);
	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);


    // Set material color
	glColor3ub(128, 128, 128);
	/********************************************************************************/
	pObj =gluNewQuadric();
	gluQuadricNormals(pObj, GLU_SMOOTH);

	//kepala
	glColor3ub(205,133,63);//body color
	gluSphere(pObj, 2.5f, 26, 13);
	glPushMatrix();
		glColor3ub(0.0f, 0.0f, 0.0f);
		glTranslatef(-1.0, -0.20, 2.4f);
		gluSphere(pObj, 0.4f, 26, 13);//left eye
		glTranslatef(2.0, 0.0, 0.0f);
		gluSphere(pObj, 0.4f, 26, 13);//right eye
	glPopMatrix();

	//kuping
	glPushMatrix();
		glColor3ub(205,133,63);//body color
		glTranslatef(-2.2f, -0.50f, 0.30f);
		gluSphere(pObj, 0.6f, 26, 13);//left ear
		glTranslatef(4.4f, 0.0f, 0.0f);
		gluSphere(pObj, 0.6f, 26, 13);//rigth ear
	glPopMatrix();

	//topi(caping)
	glColor3ub(219,219,112);//hat color
	glPushMatrix();
		//glTranslatef(
		glRotatef(240.0f, 1.0f, 0.0f, 0.0f);
		glDisable(GL_CULL_FACE);
		gluCylinder(pObj, 3.0f, 0.0f, 6.0f, 26, 1);
		gluCylinder(pObj, 3.0f, 4.0f, 0.5f, 26, 1);
		glEnable(GL_CULL_FACE);
	glPopMatrix();


	//rambut
	glColor3ub(0,0,0);
	glPushMatrix();
		glTranslatef(0.0f, 0.1f, -0.1f);
		gluSphere(pObj, 2.58f, 26, 13);
	//right hair twist
	glPopMatrix();
	glPushMatrix();
		glTranslatef(1.3f, -2.0f, -0.8f);
		gluSphere(pObj, 0.5f, 26, 13);
		glTranslatef(0.2f, -0.40f, -0.4f);
		gluSphere(pObj, 0.5f, 26, 13);
		glTranslatef(0.2f, -0.30f, -0.3f);
		gluSphere(pObj, 0.5f, 26, 13);
		glTranslatef(0.2f, -0.20f, -0.2f);
		gluSphere(pObj, 0.5f, 26, 13);
	glPopMatrix();
	//left hair twist
	glPushMatrix();
		glTranslatef(-1.3f, -2.0f, -0.8f);
		gluSphere(pObj, 0.5f, 26, 13);
		glTranslatef(-0.2f, -0.40f, -0.4f);
		gluSphere(pObj, 0.5f, 26, 13);
		glTranslatef(-0.2f, -0.30f, -0.3f);
		gluSphere(pObj, 0.5f, 26, 13);
		glTranslatef(-0.2f, -0.20f, -0.2f);
		gluSphere(pObj, 0.5f, 26, 13);
	glPopMatrix();

	//leher+tongkat
	glColor3ub(205,133,63);//body color
	glPushMatrix();
		glRotatef(90.0f, 1.0, 0.0, 0.0f);
		glDisable(GL_CULL_FACE);
		gluCylinder(pObj, 0.5f, 0.5f, 29.0f, 26, 13);
		glTranslatef(0.0f, 0.0f, 29.0f);
		gluDisk(pObj, 0.0f, 0.5f, 26, 13);
	glPopMatrix();

	//hand
	//left hand
	glColor3ub(205,133,63);//body color
	glPushMatrix();
		glTranslatef(0.0f, -3.6f, 0.0f);
		glRotatef(160.0f, 1.0, 0.0, 1.0f);
		gluCylinder(pObj, 0.5f, 0.5f, 13.0f, 26, 13);
		glTranslatef(0.0f, 0.0f, 13.0f);
		gluDisk(pObj, 0.0f, 0.5f, 26, 13);
	glPopMatrix();
	//left hand
	glColor3ub(205,133,63);//body color
	glPushMatrix();
		glTranslatef(0.0f, -3.6f, 0.0f);
		glRotatef(160.0f, 1.0, 0.0, -1.0f);
		gluCylinder(pObj, 0.5f, 0.5f, 13.0f, 26, 13);
		glTranslatef(0.0f, 0.0f, 13.0f);
		gluDisk(pObj, 0.0f, 0.5f, 26, 13);
	glPopMatrix();

	//pink blus
	glColor3ub(	10,10,10);
	//triangle mesh
	glBegin(GL_TRIANGLES);
		//1atas
		{
        M3DVector3f vPoints[3] = {{3.0f, -3.50f, 0.70f},
								{ 3.0f, -3.50f, -0.70f },
								{-3.0f,-3.50f,-0.70f }};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
		//2atas
		{
        M3DVector3f vPoints[3] = {{-3.0f, -3.50f, 0.70f},
								{ 3.0f, -3.50f, 0.70f },
								{-3.0f,-3.50f,-0.70f }};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
		//3bawah
		{
        M3DVector3f vPoints[3] = {{3.40f, -10.0f, 3.10f},
								{ 3.40f, -10.0f, -3.10f },
								{-3.40f,-10.0f,-3.10f }};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
		//4bawah
		{
        M3DVector3f vPoints[3] = {{-3.40f, -10.0f, 3.10f},
								{ 3.40f, -10.0f, 3.10f },
								{-3.40f,-10.0f,-3.10f }};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
		//5depan
		{
        M3DVector3f vPoints[3] = {{3.0f, -3.50f, 0.70f},
								{-3.0f, -3.50f, 0.70f},
								{ 3.40f, -10.0f, 3.10f }};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
		//6depan
		{
        M3DVector3f vPoints[3] = {{-3.0f, -3.50f, 0.70f},
								{ -3.40f, -10.0f, 3.10f },
								{3.40f, -10.0f, 3.10f}};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
		//7belakang
		{
        M3DVector3f vPoints[3] = {{3.0f, -3.50f, -0.70f},
								{ 3.40f, -10.0f, -3.10f },
								{-3.0f, -3.50f, -0.70f}};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
		//8belakang
		{
        M3DVector3f vPoints[3] = {{-3.0f, -3.50f, -0.70f},
								{3.40f, -10.0f, -3.10f},
								{ -3.40f, -10.0f, -3.10f }};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
		//9kanan
		{
        M3DVector3f vPoints[3] = {{3.40f, -10.0f, -3.10f},
								{3.0f, -3.50f, -0.7},
								{3.40f, -10.0f, 3.10f}};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
		//10kanan
		{
        M3DVector3f vPoints[3] = {{3.40f, -10.0f, 3.10f},
								{3.0f, -3.50f, -0.7},
								{3.0f, -3.50f, 0.7}};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
		//11kiri
		{
        M3DVector3f vPoints[3] = {{-3.40f, -10.0f, -3.10f},
								{-3.40f, -10.0f, 3.10f},
								{-3.0f, -3.50f, -0.7}};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
		//12kiri
		{
        M3DVector3f vPoints[3] = {{-3.40f, -10.0f, 3.10f},
								{-3.0f, -3.50f, 0.7},
								{-3.0f, -3.50f, -0.7}};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
	glEnd();

	//puff
	//left puff
	glPushMatrix();
		glTranslatef(-3.2f, -4.40f, 0.0f);
		gluSphere(pObj,1.10f, 26, 13);
		glRotatef(90.0f, 1.0f,  -1.80f, 0.0f);
		gluCylinder(pObj, 1.1f, 1.4f, 1.0f, 26, 13);
		glTranslatef(0.0f, 0.0f, 1.0f);
		gluDisk(pObj, 0.0f, 1.4f, 26, 13);
	glPopMatrix();
	//right puff
	glPushMatrix();
		glTranslatef(3.2f, -4.40f, 0.0f);
		gluSphere(pObj,1.10f, 26, 13);
		glRotatef(90.0f, 1.0f,  1.80f, 0.0f);
		gluCylinder(pObj, 1.1f, 1.4f, 1.0f, 26, 13);
		glTranslatef(0.0f, 0.0f, 1.0f);
		gluDisk(pObj, 0.0f, 1.4f, 26, 13);
	glPopMatrix();

	//dada
	glPushMatrix();
		glTranslatef(-1.2f, -6.50f, 0.50f);
		gluSphere(pObj,2.0f, 26, 13);//left breast
		glTranslatef(2.40f, 0.0f, 0.0f);
		gluSphere(pObj, 2.0f, 26, 13);//rigth breast
	glPopMatrix();

	//skirt
	//brown skirt
	glColor3ub(	92,51,23);
	glPushMatrix();
		glTranslatef(0.0f, -2.0f, 0.0f);
		glRotatef(90, 1.0f, 0.0f, 0.0f);
		gluCylinder(pObj, 0.0f, 7.0f, 18.0f, 26, 13);
	glPopMatrix();
	//black belt
	glPushMatrix();
	glColor3ub(	0,0,0);
		glTranslatef(0.0f, -10.3f, 0.0f);
		glRotatef(90, 1.0f, 0.0f, 0.0f);
		gluCylinder(pObj, 3.3f, 3.5f, 0.8f, 26, 13);
	glPopMatrix();



	glPopMatrix();

	/********************************************************************************/

	// Display the results
	glutSwapBuffers();
	}

// This function does any needed initialization on the rendering
// context.
void SetupRC()
    {
    // Light values and coordinates
    GLfloat  ambientLight[] = { 0.3f, 0.3f, 0.3f, 1.0f };
    GLfloat  diffuseLight[] = { 0.7f, 0.7f, 0.7f, 1.0f };
    GLfloat  specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat  specref[] = { 1.0f, 1.0f, 1.0f, 1.0f };

    glEnable(GL_DEPTH_TEST);	// Hidden surface removal
    glFrontFace(GL_CCW);		// Counter clock-wise polygons face out
    glEnable(GL_CULL_FACE);		// Do not calculate inside of jet

    // Enable lighting
    glEnable(GL_LIGHTING);

    // Setup and enable light 0
    glLightfv(GL_LIGHT0,GL_AMBIENT,ambientLight);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuseLight);
    glLightfv(GL_LIGHT0,GL_SPECULAR, specular);
    glEnable(GL_LIGHT0);

    // Enable color tracking
    glEnable(GL_COLOR_MATERIAL);

    // Set Material properties to follow glColor values
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    // All materials hereafter have full specular reflectivity
    // with a high shine
    glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
    glMateriali(GL_FRONT, GL_SHININESS, 128);

    // white background
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f );

    glEnable(GL_NORMALIZE);
    }

/////////////////////////////////////////////////////
// Handle arrow keys
void SpecialKeys(int key, int x, int y)
    {
    if(key == GLUT_KEY_UP)
        xRot-= 5.0f;

    if(key == GLUT_KEY_DOWN)
        xRot += 5.0f;

    if(key == GLUT_KEY_LEFT)
        yRot -= 5.0f;

    if(key == GLUT_KEY_RIGHT)
        yRot += 5.0f;

    if(key > 356.0f)
        xRot = 0.0f;

    if(key < -1.0f)
        xRot = 355.0f;

    if(key > 356.0f)
        yRot = 0.0f;

    if(key < -1.0f)
        yRot = 355.0f;

    // Refresh the Window
    glutPostRedisplay();
    }


//////////////////////////////////////////////////////////
// Reset projection and light position
void ChangeSize(int w, int h)
    {
    GLfloat fAspect;
    GLfloat lightPos[] = { -50.f, 50.0f, 100.0f, 1.0f };

    // Prevent a divide by zero
    if(h == 0)
        h = 1;

    // Set Viewport to window dimensions
    glViewport(0, 0, w, h);

    // Reset coordinate system
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    fAspect = (GLfloat) w / (GLfloat) h;
    gluPerspective(45.0f, fAspect, 1.0f, 225.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
    glTranslatef(0.0f, 0.0f, -50.0f);
    }

int main(int argc, char* argv[])
    {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600,600);
	glutCreateWindow(".:OpenGL - Cute Scarecrow:.");
    glutReshapeFunc(ChangeSize);
    glutSpecialFunc(SpecialKeys);
    glutDisplayFunc(RenderScene);
    SetupRC();
    glutMainLoop();

    return 0;
    }
