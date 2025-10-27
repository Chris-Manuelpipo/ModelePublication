
//CLASSE RESSOURCE: Une ressource (place au stade) est caractérisée par son nom, sa description, et son état(disponible ou non)


#pragma once // Permet d'empecher les ré-inclusions multiples du fichier lors de la compilation donc évite les erreurs
#include <string>

class Ressource {
    static int compteur;
    int id; //identifiant unique de la ressource
    std::string section;      // VIP, standard, presidentielle
    std::string rangee; 
    int siege;                // Numéro de siège 
    double prix;   // Prix de la plce
    bool disponible; // état de la place

public:
    //Constructeur de la classe ressource
    Ressource(
        const std::string& section,
        const std::string& rangee,
        int siege,
        double prix, 
        bool disponible = true);

    // Accesseurs qui permettent  d'accéder aux attributs caractérisant une place
    int getId() const;
    std::string getSection() const;
    std::string getRangee() const;
    int getSiege() const;
    double getPrix() const;
    bool estDisponible() const;

    // Mutateur pour modifier les attributs
    void setId(int nouveauId);
    void setDisponible(bool etat);
    void setPrix(double nouveauPrix);
    void setSection(const std::string& s);
    void setRangee(const std::string& r);
    void setSiege(int s);

    //Affichage
    std::string toString() const; 
};
