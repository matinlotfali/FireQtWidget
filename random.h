#ifndef RANDOM_H
#define RANDOM_H


class Random
{
    unsigned int g_seed;
public:
    inline Random(const unsigned int seed)
        :g_seed(seed) { }

    inline unsigned int nextInt()
    {
        g_seed = (214013*g_seed+2531011);
        return (g_seed>>16)&0x7FFF;
    }

    inline unsigned int nextInt(const unsigned int max)
    {
        return nextInt() % max;
    }
};

#endif // RANDOM_H
