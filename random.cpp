#include "random.h"

Random::Random(unsigned int seed)
{
    g_seed = seed;
}

unsigned int Random::nextInt()
{
    g_seed = (214013*g_seed+2531011);
    return (g_seed>>16)&0x7FFF;
}

unsigned int Random::nextInt(unsigned int max)
{
    return nextInt() % max;
}
