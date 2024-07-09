#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
    srand((unsigned)time(0));
    int pc = rand() % 100;
    std::cout << "voici les chance " << pc << std::endl;
    if (pc <= 33)
    {
        A *obj = new A;
        return obj;
    }
    else if (pc <= 66)
    {
        B *obj = new B;
        return obj;
    }
    C *obj = new C;
    return obj;
}

// cree au hazard A B ou C et retourne l'instance en pointeur BAse
// le hasard doit etre fait comme on veut
void identify(Base* p)
{
    A *a = dynamic_cast<A*>(p);
    if (a != NULL)
    {
        std::cout << "Voici le type du cast: A" << std::endl;
        return ;
    }
    B *b = dynamic_cast<B*>(p);
    if (b != NULL)
    {
        std::cout << "Voici le type du cast: B" << std::endl;
        return ;
    }
    C *c = dynamic_cast<C*>(p);
    if (c != NULL)
    {
        std::cout << "Voici le type du cast: C" << std::endl;
        return ;
    }
    std::cout << "no type detected" << std::endl;
}
// print le type actuel de l'objet pointer

void identify(Base& p)
{
    try
    {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "Voici le type du cast: A" << std::endl;
        return ;
    }
    catch(std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        B &b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "Voici le type du cast: B" << std::endl;
        return ;
    }
    catch(std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        C &c = dynamic_cast<C&>(c);
        (void)c;
        std::cout << "Voici le type du cast: C" << std::endl;
        return ;
    }
    catch(std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "no type detected" << std::endl;
}

// print le type de l'objet pointer
// utiliser un pointeur dans cette fonction est interdit

int main()
{
    Base *sa = NULL;
    sa = generate();
    identify(sa);
    Base *sq;
    sq = generate();
    identify(sq);
    delete sa;
    delete sq;
}
