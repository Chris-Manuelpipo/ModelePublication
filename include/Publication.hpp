#pragma once //Permet de garantir que le fichier est inclus une seule fois pendant la compilation afin d'éviter les erreurs
#include "Ressource.hpp"
#include <vector> // Vecteur Pour stocker les adresses de plusieurs ressources
#include <string>
 
class Publication {
private:
    std::vector<Ressource> ressources; //Liste de ressources(places publiées)
    bool existe(const Ressource& res) const; // Vérifie doublon
    

public:
    bool publier(const Ressource& res); //Fonction de publication; ajoute la place à la liste de places
    bool retirer(int id); // Supprimer une place par son id
    bool modifier(int id, const Ressource &nouvelle);
    Ressource* rechercher(int id);// Rechercher une ressource et simuler la reservation
    void afficherToutes() const;// Afficher/litser toutes places publiées
    std::vector<Ressource*> chercher(const std::string& section, const std::string& rangee) const;// Méthode pour rechercher une place particulière

    //Sauvegarde dans un fichier texte
    bool sauvegarder(const std::string& fichier) const;
    bool charger(const std::string& fichier);

    const std::vector<Ressource>& getRessources() const { return ressources; }
};
