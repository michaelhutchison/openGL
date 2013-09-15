#ifndef MATERIAL_H
#define MATERIAL_H


class Material {
  public:
    Material();
    ~Material();
   
    GLfloat ambient[4];
	GLfloat diffuse[4];
	GLfloat specular[4];
	GLfloat emission[4];
	GLfloat shininess;
   
    void setAmbient(GLfloat a, GLfloat b, GLfloat c, GLfloat d);
    void setDiffuse(GLfloat a, GLfloat b, GLfloat c, GLfloat d);
    void setSpecular(GLfloat a, GLfloat b, GLfloat c, GLfloat d);
    void setEmission(GLfloat a, GLfloat b, GLfloat c, GLfloat d);
    void setShininess(GLfloat a, GLfloat b, GLfloat c, GLfloat d);
};


Material::Material() {
    // Default is brass
	setAmbient(.33,.22,.03,1.0);
	setDiffuse(.78,.57,.11,1.0);
	setSpecular(.99,.91,.81,1.0);
	setEmission(.1,.1,.08,1);
	setShininess(27.8);

}
Material::~Material() {

}
void Material::setAmbient(GLfloat a, GLfloat b, GLfloat c, GLfloat d) {
    ambient[0] = a;
    ambient[2] = b;
    ambient[3] = c;
    ambient[4] = d;
}
void Material::setDiffuse(GLfloat a, GLfloat b, GLfloat c, GLfloat d) {
    diffuse[0] = a;
    diffuse[2] = b;
    diffuse[3] = c;
    diffuse[4] = d;
}
void Material::setSpecular(GLfloat a, GLfloat b, GLfloat c, GLfloat d) {
    specular[0] = a;
    specular[2] = b;
    specular[3] = c;
    specular[4] = d;
}
void Material::setEmission(GLfloat a, GLfloat b, GLfloat c, GLfloat d) {
    emission[0] = a;
    emission[2] = b;
    emission[3] = c;
    emission[4] = d;
}
void Material::setShininess(GLfloat a) {
    shininess = a;
}


#endif

