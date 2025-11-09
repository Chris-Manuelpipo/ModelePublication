#pragma once
#include "Ressource.hpp"
#include <vector> //Vecteur Pour stocker les adresses de plusieurs ressources
#include <string>
 
class Publication {
private:
    std::vector<Ressource>ressources; //Liste de ressources
    bool existe(const Ressource& res) const; //Vérifie les doublons
    
public:
    bool publier(const Ressource& res); //Fonction de publication correspondante au modèle mathématique
    Ressource* rechercher(int id);//Rechercher une ressource
    void afficherToutes() const;//Afficher toutes les places en console
    std::vector<Ressource*> chercher(const std::string& section, const std::string& rangee) const;//Méthode pour rechercher une place particulière
    bool sauvegarder(const std::string& fichier) const;//Sauvegarde dans un fichier texte
    bool charger(const std::string& fichier);//Charger depuis le fichier texte
    const std::vector<Ressource>& getRessources() const { return ressources; }//Récupérer toutes les ressources
};
