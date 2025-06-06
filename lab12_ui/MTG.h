#ifndef MTG_H
#define MTG_H

#include <random>

class BaseGenerator{
public:
    virtual ~BaseGenerator() = default;
    virtual float generate() = 0;
};

class ImitationGenerator : public BaseGenerator{
public:
    virtual ~ImitationGenerator() = default;
protected:
    ImitationGenerator(unsigned int sd) : seed(sd) {};
    unsigned int seed, prevNum;
};

class MTG : public ImitationGenerator{
public:
    MTG(unsigned int sd) :
        ImitationGenerator(sd)
    {prevNum = seed;
        mt.seed(prevNum);}
    ~MTG() = default;
    float generate() override;
private:
    std::mt19937 mt;
};




#endif // MTG_H
