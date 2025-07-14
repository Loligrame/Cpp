#include "Array.hpp"

template <typename T>
void  printArray(const Array<T> & array){
    for(unsigned int i = 0; i < array.get_size(); ++i)
        std::cout << array[i] << " ";
}

int main(){
     std::cout << "=== TEST 1 : Création et écriture dans un tableau ===\n";
    Array<int> tableau1(5);
    ::printArray(tableau1);
    std::cout << "\nJ'entre : tableau1[3] = 78 " << tableau1[3] << std::endl;
    tableau1[3] = 78;
    std::cout << "Valeur à l’index 3 : " << tableau1[3] << std::endl;
    std::cout << "Valeur à l’index 1 : " << tableau1[1] << std::endl;
    std::cout << "Affichage complet : ";
    ::printArray(tableau1);

    std::cout << "\n\n=== TEST 2 : Création d’un tableau vide ===\n";
    Array<int> tableauVide;
    std::cout << "Taille du tableau : " << tableauVide.get_size() << std::endl;
    try {
        std::cout << "Accès à tableauVide[0] : ";
        std::cout << tableauVide[0] << std::endl; // Devrait lancer une exception
    } catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n\n=== TEST 3 : Accès out-of-range volontaire ===\n";
    Array<int> tableau3(4);
    tableau3[0] = 144;
    tableau3[1] = 16;
    tableau3[2] = 15;
    tableau3[3] = 41;
    try {
        std::cout << std::endl << tableau3[10] << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "Affichage tableau3 : ";
    ::printArray(tableau3);
    std::cout  << std::endl << "Valeur à l’index 1 : " << tableau3[1] << std::endl;

    std::cout << "\n\n=== TEST 4 : Constructeur de copie ===\n";
    Array<int> original(2);
    original[0] = 10;
    original[1] = 20;
    Array<int> copie(original);
    copie[0] = 99;
    std::cout << "Original : ";
    ::printArray(original); // Devrait afficher 10 20
    std::cout  << std::endl << "Copie    : ";
    ::printArray(copie);    // Devrait afficher 99 20

    std::cout << "\n\n=== TEST 5 : Opérateur d’affectation ===\n";
    Array<int> a(3);
    a[0] = 1; a[1] = 2; a[2] = 3;
    Array<int> b(1);
    b = a; // Test de operator=
    std::cout << "b après affectation : ";
    ::printArray(b); // Doit afficher 1 2 3

    std::cout << "\n\n=== TEST 6 : Lecture via un tableau const ===\n";
    const Array<int> tableauConst(a);
    std::cout << "tableauConst[2] : " << tableauConst[2] << std::endl;

    std::cout << "\n\n=== TEST 7 : Template avec std::string ===\n";
    Array<std::string> mots(3);
    mots[0] = "Bonjour";
    mots[1] = "le";
    mots[2] = "monde";
    std::cout << "Tableau de mots : ";
    ::printArray(mots);
}