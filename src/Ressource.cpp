#include "Ressource.hpp"


//Initialisation du compteur à O

int Ressource::compteur = 0;

// Constructeur complet
Ressource::Ressource(const std::string& section,
                     const std::string& rangee,
                     int siege,
                     double prix,
                     bool disponible)
                    :section(section),
                    rangee(rangee),
                    siege(siege),
                    prix(prix),
                    disponible(disponible) {
                        id = ++compteur; //On affecte à l'id l'entier naturel directement supérieur à l'id précédant
                    }

//Getters accesseurs
int Ressource::getId() const { return id; }
std::string Ressource::getSection() const { return section; }
std::string Ressource::getRangee() const { return rangee; }
int Ressource::getSiege() const { return siege; }
double Ressource::getPrix() const { return prix; }
bool Ressource::estDisponible() const { return disponible; }

//mutateurs
void Ressource::setId(int nouveauId) {
    id = nouveauId;
    if (nouveauId > compteur)
        compteur = nouveauId; // pour garder le compteur à jour
}
void Ressource::setDisponible(bool etat) { disponible = etat; }
void Ressource::setPrix(double nouveauPrix) { prix = nouveauPrix; }
void Ressource::setSection(const std::string& s) { section = s; }
void Ressource::setRangee(const std::string& r) { rangee = r; }
void Ressource::setSiege(int s) { siege = s; }

//Méthode d'affichage

    std::string Ressource::toString() const {
    return "ID: " + std::to_string(id) + 
           " | Section: " + section +
           " | Rangée: " + rangee +
           " | Siège: " + std::to_string(siege) +
           " | Prix: " + std::to_string(prix) + " FCFA" +
           " | Disponible: " + (disponible ? "Oui" : "Non");
    }



    //
