#ifndef RANDOM_H
#define RANDOM_H


class Random
{
private:
    unsigned int g_seed;
public:
    Random(unsigned int seed);
    unsigned int nextInt();
    unsigned int nextInt(unsigned int max);
};

#endif // RANDOM_H
