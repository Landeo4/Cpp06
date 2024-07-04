#include "ScalarConverter.hpp"

int main()
{
    ScalarConverter obj;
    obj.convert("1");
}

/*
je dois:
faire une class qui contient une method static "convert"
qui prend en parametre une string qui represente un character de c++
dans sa forme la plus commune et sors sa valeur dans ces differents type
*char
*int
*float
*double

cette classe doit pas etre instanciable par le user
sauf pour les char, seul les notation decimal sont utilise
'c' 'a'
tous les characters non affichables ne doivent pas etre utilise en input
si la conversion n'est pas affichable ecrit un message d'information

Examples of int literals: 0, -42, 42...
Examples of float literals: 0.0f, -4.2f, 4.2f...
vous devez gerer ces different pseudo literals
-inff, +inff, nanf(not a number)

Examples of double literals: 0.0, -4.2, 4.2...
inf, +inf and nan

premierement je dois detecter le type passer en parametre, le convertir
de la string jusqu'a son type, apres le convertir explicitement vers les
trois autres type, enfin aficher le resultat

si une conversion ne fais pas de sens ou overflow, affiche un message
pour informer l'utilisateur que la conversion est impossible
inclue les en-tete que vous avez besoin pour les limits numerique
et les valeurs specials

*/