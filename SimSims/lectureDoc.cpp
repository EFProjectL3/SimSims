#include "lectureDoc.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <memory>

/**
 * @brief lireIntro
 * @param fichierDonnees
 * @return
 *
 * Lis le début du fichier, retourne le nombre de formes dans ce fichier, et créer un tableau static
 * avec le nom detoutes les formes du fichier
 */

std::vector<std::string> lireIntro(char* fichierDonnees)
{
    int nombreDeFormes;
    std::string tmp; //Pour passer les lignes non utiles
    std::ifstream fichier(fichierDonnees, std::ios::in);  // on ouvre le fichier en lecture

    if(fichier)  // si l'ouverture a réussi
    {
        fichier >> tmp;     //"NOMBREFORME"
        fichier >> nombreDeFormes;
        std::vector<std::string> NOM_FORMES;
        fichier >> tmp;     //'NOMFORME"

        for (int i(0); i<nombreDeFormes; i++)
        {
            fichier >> tmp;
            NOM_FORMES.push_back(tmp);
        }

        fichier.close();
        return NOM_FORMES;
    }
    else
    {
        std::cout << "Ouverture du fichier impossible" << std::endl;
        exit(1);
    }
}

int nombreAttributForme(char* fichierDonnees, int indice)
{
    int idForme = 0;
    std::ifstream fichier(fichierDonnees, std::ios::in);  // on ouvre le fichier en lecture

    if(fichier)  // si l'ouverture a réussi
    {
        bool trouve = false;
        std::string ligneEnCours;
        while(getline(fichier, ligneEnCours))  // tant que l'on peut mettre la ligne dans "contenu"
        {
            if (ligneEnCours == "//NOUVELLEFORME")
            {
                idForme++;
            }
            if (idForme == indice)
            {
                if (trouve)
                {
                    int val;
                    std::stringstream stream(ligneEnCours);
                    stream >> val;
                    return val;
                }

                if (ligneEnCours == "/-NOMBREATTRIBUTS")
                    trouve = true;
            }
        }

        fichier.close();
    }
    else
    {
        std::cout << "Ouverture du fichier impossible" << std::endl;
        exit(1);
    }
}



/* FONCTIONS PROVENANT DE STACK OVERFLOW */
/**
 * @brief ReplaceAll
 * @param str
 * @param from
 * @param to
 * @return
 *
 * Remplace toutes les occurences de from dans la chaine str par la chaine to
 */
std::string ReplaceAll(std::string str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return str;
}
/**
 * @brief explode
 * @param s
 * @param delim
 * @return
 *
 * Fonction eclatant une chaine par rapport à son délimiteur
 */
std::vector<std::string> explode(std::string const & s, char delim)
{
    std::vector<std::string> result;
    std::istringstream iss(s);

    for (std::string token; std::getline(iss, token, delim); )
    {
        result.push_back(std::move(token));
    }

    return result;
}
/***************************************/

/**
 * @brief calcul_normale
 * @param s0x
 * @param s0y
 * @param s0z
 * @param s1x
 * @param s1y
 * @param s1z
 * @param s2x
 * @param s2y
 * @param s2z
 * @param normale
 *
 * Calcul les normales aux faces
 */
void calcul_normale(float s0x, float s0y, float s0z, float s1x, float s1y, float s1z, float s2x, float s2y, float s2z, struct normale * normale) {
    float v0x = s2x - s1x;
    float v0y = s2y - s1y;
    float v0z = s2z - s1z;
    float v1x = s0x - s1x;
    float v1y = s0y - s1y;
    float v1z = s0z - s1z;
    normale->x = (v0y * v1z) - (v0z *v1y);
    normale->y = (v0z * v1x) - (v0x *v1z);
    normale->z = (v0x * v1y) - (v0y *v1x);
    float norme = sqrtf(normale->x * normale->x + normale->y * normale->y + normale->z * normale->z);
    normale->x = normale->x / norme;
    normale->y = normale->y / norme;
    normale->z = normale->z / norme;
}


/**
 * @brief creerFormesLecture
 * @param fichierDonnees
 * @param numeroObjet
 * @param att
 * @return
 *
 * Créer la forme correspondant à numéroObjet, et la retourne sous la forme d'un pointeur
 */
std::shared_ptr<forme> creerFormesLecture(char* fichierDonnees, int numeroObjet, std::vector<float> att)
{
    int nombreDeFormes = 0;
    int etape=0;

    bool coeffAttribut = true;  //vrai si on est sur le coeff de l'attribut, faut si on est sur l'attribut lui même
    float valeurCoeff;
    std::string tmp; //Pour passer les lignes non utiles
    std::ifstream fichier(fichierDonnees, std::ios::in);  // on ouvre le fichier en lecture
    std::string ligneEnCours;
    std::string lignePrecedente;

    if(fichier)  // si l'ouverture a réussi
    {
        fichier >> tmp;     //"NOMBREFORME"
        fichier >> nombreDeFormes;
        fichier >> tmp;     //'NOMFORME"
        for (int i(0); i<nombreDeFormes; i++)
        {
            fichier >> tmp;
        }

        //ARRIVE ICI, ON EST RENDU A LA PREMIERE //NOUVELLE FORME

        int idTmp = 0;
        int nbFacTmp;
        int nbSomTmp;
        int nbFacMax;
        int nbAttTmp;

        int ** facesTabTmp = new int*[100];  //correspond au tableau de construction des faces
        for(int i(0); i < 100; i++)
        { facesTabTmp[i] = new int[3]; }

        for (int i(0); i<100; i++)          //toutes les valeurs à 0 pour éviter d'avoir des valeurs aléatoires en fin de tableau
        {
            for (int j(0); j<3; j++)
                facesTabTmp[i][j] = 0;
        }

        int ** somTabTmp = new int*[100];   //correspond au tableau de construction des sommets
        for(int i(0); i < 100; i++)
        { somTabTmp[i] = new int[3]; }
        sommet * somTmp = new sommet [50];         //tableau de sommets
        face * facTmp = new face [50];     //tableau de faces
        std::map<std::string,float> attTmp;                  //map d'attributs

        int iFacesCons = 0; //Indice dans le tableau de construction des faces
        int iSommetCons = 0;    //Indice dans le tableau de construction des sommets
        int iAtt = 0;   //Indice dans le tableau des attributs
        int xyz = 0;    //0 pour x, 1 pour y, 2 pour z
        int sommetsTraites = 0;
        int facesTraitees = 0;
        int iFaces = 0; //Indice pour le tableau de sommets
        int iSommet = 0;    //Indice pour le tableau de faces

        int numeroface = 0;
        int valeurSommet = 0;
        bool passerFin = false;

        sommet sommetTemporaire;
        face faceTemporaire;

        getline(fichier, ligneEnCours);
        while(getline(fichier, ligneEnCours))  // tant que l'on peut mettre la ligne dans "contenu"
        {
            /* Pour debug. Affichage de ce qui est lu */
            //nbLigne++;
            //std::cout << "Lignes lues: " << nbLigne << std::endl;
            //std::cout << "Etape : " << etape << std::endl;
            //std::cout << ligneEnCours << std::endl;
            /******************************************/
            if (ligneEnCours == "//NOUVELLEFORME")
            {
                idTmp++;
                etape = 0;
            }
            if (idTmp == numeroObjet)   //on est au niveau de l'objet que l'on veut créer
            {

                if (ligneEnCours == "/-TABFACES")
                    etape = 1;
                if (ligneEnCours == "/-TABSOMMETS")
                    etape = 2;
                if (ligneEnCours == "/-ATTRIBUTS")
                    etape = 3;
                if (ligneEnCours == "/-FONCTIONCREATIONFORME")
                    etape = 4;
                if (ligneEnCours == "/-FONCTIONAFFICHAGEFORME")
                    etape = 5;

                if (lignePrecedente == "/-NOMBREFACE")
                {nbFacTmp = atoi(ligneEnCours.c_str());}
                if (lignePrecedente == "/-FACEMAX")
                {nbFacMax = atoi(ligneEnCours.c_str());}
                if (lignePrecedente == "/-NOMBRESOMMETS")
                {nbSomTmp = atoi(ligneEnCours.c_str());}
                if (lignePrecedente == "/-NOMBREATTRIBUTS")
                {nbAttTmp = atoi(ligneEnCours.c_str());}

                if (etape == 1 && ligneEnCours != "/-TABFACES") //Lecture du tableau de création de faces
                {
                    int j = 0;
                    std::vector<std::string> res = explode(ligneEnCours, ' ');
                    while (j<nbFacMax)
                    {
                        std::string chaine = res[j];
                        int val = std::stoi(chaine);
                        facesTabTmp[iFacesCons][j] = val;
                        j++;
                    }

                    iFacesCons++;
                }

                if (etape == 2 && ligneEnCours != "/-TABSOMMETS")   //Lecture du tableau de création de sommets
                {
                    int j = 0;
                    std::vector<std::string> res = explode(ligneEnCours, ' ');
                    while (j<3)
                    {
                        std::string chaine = res[j];
                        int val = std::stoi(chaine);
                        somTabTmp[iSommetCons][j] = val;
                        j++;
                    }
                    iSommetCons++;
                }

                if (etape == 3 && ligneEnCours != "/-ATTRIBUTS") //Lecture des attributs, et on les relie à leur valeur
                {
                    if (coeffAttribut)
                    {
                        std::stringstream stream(ligneEnCours);
                        stream >> valeurCoeff;
                    }
                    else
                    {
                        attTmp.insert(std::make_pair(ligneEnCours,att[iAtt]*valeurCoeff));
                        iAtt++;
                    }
                }
                if (coeffAttribut)
                    coeffAttribut = false;
                else
                    coeffAttribut = true;

                if (etape==4 && ligneEnCours != "/-FONCTIONCREATIONFORME" && ligneEnCours != "//")  //Position des sommets et centre des faces
                {
                    std::string chaine = ligneEnCours;
                    //Conversion valeur en float du map en chaine
                    for (std::map<std::string,float>::const_iterator it = attTmp.begin(); it!=attTmp.end();++it)
                    {
                        float valeur = it->second;
                        std::stringstream ss;
                        ss << valeur;
                        std::string valTxt = ss.str();
                        //On remplace toutes les occurences dans la ligne en cours
                        chaine = ReplaceAll(chaine,it->first,valTxt);
                    }
                    //EN ARRIVANT ICI, ON A UNE CHAINE DE CARACTERE AVEC LES VALEURS QUI ONT REMPLACE LES ATTRIBUTS

                    if (sommetsTraites < nbSomTmp)  //On est encore dans la partie sommet
                    {
                        if (passerFin)
                            passerFin = false;
                        if (xyz == 2)   //coordonnées Z
                        {
                            float val;
                            std::stringstream stream(chaine);
                            stream >> val;
                            sommetTemporaire.coordonnees.z = val;
                            somTmp[iSommet]=sommetTemporaire;
                            iSommet++;
                            xyz = 0;
                            sommetsTraites++;
                            valeurSommet++;
                            passerFin = true;
                        }
                        if (!passerFin)
                        {
                            if (xyz == 1)   //coordonnées Y
                            {
                                float val;
                                std::stringstream stream(chaine);
                                stream >> val;
                                sommetTemporaire.coordonnees.y = val;
                                xyz++;
                            }
                            if (xyz == 0)   //coordonnées X
                            {
                                float val;
                                std::stringstream stream(chaine);
                                stream >> val;
                                sommetTemporaire.coordonnees.x = val;
                                xyz++;
                            }
                        }
                    }   //Fin du remplissage des sommets
                    else //Remplissage des centres de face
                    {
                        if (facesTraitees < nbFacTmp)
                        {
                            if (passerFin)
                                passerFin = false;
                            if (xyz == 2)   //coordonnées Z
                            {
                                float val;
                                std::stringstream stream(chaine);
                                stream >> val;
                                faceTemporaire.centre.z = val;
                                facTmp[iFaces]=faceTemporaire;
                                iFaces++;
                                xyz = 0;
                                facesTraitees++;
                                numeroface++;
                                passerFin = true;
                            }
                            if (!passerFin)
                            {
                                if (xyz == 1)   //coordonnées Y
                                {
                                    float val;
                                    std::stringstream stream(chaine);
                                    stream >> val;
                                    faceTemporaire.centre.y = val;
                                    xyz++;
                                }
                                if (xyz == 0)   //coordonnées X
                                {
                                    float val;
                                    std::stringstream stream(chaine);
                                    stream >> val;
                                    faceTemporaire.centre.x = val;
                                    xyz++;
                                }
                            }
                        }
                    }
                }   //Fin etape 4

                if (ligneEnCours == "/---CREATIONFORME")
                {
                    etape = 0;
                }   //Fin creation forme

                lignePrecedente = ligneEnCours;
            }
        }   //Fin de lecture du fichier
        fichier.close();

        for (int j(0);j<nbFacTmp;j++)
        {
            calcul_normale(
                        somTmp[facesTabTmp[j][0]].coordonnees.x,
                    somTmp[facesTabTmp[j][0]].coordonnees.y,
                    somTmp[facesTabTmp[j][0]].coordonnees.z,
                    somTmp[facesTabTmp[j][1]].coordonnees.x,
                    somTmp[facesTabTmp[j][1]].coordonnees.y,
                    somTmp[facesTabTmp[j][1]].coordonnees.z,
                    somTmp[facesTabTmp[j][2]].coordonnees.x,
                    somTmp[facesTabTmp[j][2]].coordonnees.y,
                    somTmp[facesTabTmp[j][2]].coordonnees.z,
                    &(facTmp[j].norm));
        }

        auto formePtr = std::make_shared<forme>(idTmp, nbFacTmp, nbSomTmp, nbAttTmp, nbFacMax, facesTabTmp, somTmp, facTmp, attTmp);
        //formePtr->infoForme();

        return formePtr;
    }   //Fichier fermé
    else  // Sinon
    {
        std::cout << "Impossible d'ouvrir le fichier !" << std::endl;
        exit(1);
    }
}

/**
 * @brief lireTextures
 * @param fichierDonnees
 *
 * Stock les noms de textures dans un vecteur
 */
std::vector<std::string> lireAdresseTextures(char * fichierDonnees)
{
    bool textureTrouve = false;
    std::vector<std::string> tabAdresseTextures;
    std::ifstream fichier(fichierDonnees, std::ios::in);  // on ouvre le fichier en lecture
    std::string ligneEnCours;
    if(fichier)  // si l'ouverture a réussi
    {
        while(getline(fichier, ligneEnCours))  // tant que l'on peut mettre la ligne dans "contenu"
        {
            if (ligneEnCours == "/---TEXTURES")
                textureTrouve = true;
            if (textureTrouve && ligneEnCours != "/---TEXTURES")
            {
                std::string chaine = ligneEnCours;
                tabAdresseTextures.push_back(chaine);
            }
        }
        return tabAdresseTextures;
    }
    else
    {
        std::cout << "Impossible d'ouvrir le fichier !" << std::endl;
        exit(1);
    }
}

void chargerTextures()
{
}
