#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "default constructor called for Brain." << std::endl;
}

Brain::Brain(const Brain& copy)
{
    std::cout << "copy constructor called for Brain." << std::endl;
    *this = copy;
}

Brain& Brain::operator=(const Brain& copy)
{
    std::cout << "copy assigment operator called for Brain." << std::endl;
    if(this != &copy)
    {
        for(int i = 0; i < 100; i++)
        {
            this->ideas[i] = copy.getIdeas(i);
        }
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "destructor called for Brain." << std::endl;
}

void Brain::setIdeas(std::string idea, int i)
{
    ideas[i] = idea;
}

std::string Brain::getIdeas(int i) const
{
    if(i >= 0 && i <= 100)
        return ideas[i];
    else
        return(NULL);
}
