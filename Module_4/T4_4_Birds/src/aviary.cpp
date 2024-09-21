#include "aviary.hpp"
Aviary::Aviary():birds_(){}

void Aviary::Add(Bird* bird)
{
    if (bird == NULL)
    {
        throw std::logic_error("NULL ptr");
    }
    birds_.push_back(bird);
    return;
}
void Aviary::SpeakAll(std::ostream& os) const
{
    for(auto& b : birds_)
    {
        b->Speak(os);
    }
    return;
}
size_t Aviary::Size() const
{
    return birds_.size();
}
Bird* Aviary::operator[](size_t idx)
{
    if (idx >= Size())
    {
        throw std::out_of_range("Out of range");
    }
    return birds_[idx];
}
Bird* Aviary::operator[](size_t idx) const
{
    if (idx >= Size())
    {
        throw std::out_of_range("Out of range");
    }
    return birds_[idx];
}
Aviary::~Aviary()
{
    for(auto& b : birds_)
    {
        delete b;
    }
    return;
}