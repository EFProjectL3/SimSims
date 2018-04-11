#include <vector>
#include <memory>
#include "forme.h"
#include <QOpenGLTexture>

std::vector<std::string> lireIntro(char* fichierDonnees);

std::shared_ptr<forme> creerFormesLecture(char* fichierDonnees, int numeroObjet, std::vector<float> att);

std::vector<QOpenGLTexture *>  lireTextures(char * fichierDonnees);

std::vector<std::string> explode(std::string const & s, char delim);
