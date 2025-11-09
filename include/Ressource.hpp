#pragma once //Permet d'empecher les ré-inclusions multiples du fichier lors de la compilation donc évite les erreurs
#include <string>

class Ressource {
    static int compteur;
    int id; //identifiant unique de la ressource
    std::string section;      //VIP,STANDARD...
    std::string rangee; //A,B,C...
    int siege; //Numéro de siège
    double prix;   //Prix de la plce
    bool disponible; //état de la place

public:
    //Constructeur de la classe Ressource
    Ressource(
        const std::string& section,
        const std::string& rangee,
        int siege,
        double prix, 
        bool disponible = true);

    //Accesseurs
    int getId() const;
    std::string getSection() const;
    std::string getRangee() const;
    int getSiege() const;
    double getPrix() const;
    bool estDisponible() const;

    //Mutateurs
    void setId(int nouveauId);
    void setDisponible(bool etat);
    void setPrix(double nouveauPrix);
    void setSection(const std::string& s);
    void setRangee(const std::string& r);
    void setSiege(int s);
};
