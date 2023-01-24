#if defined(DEBUG)
#define MY_ASSERT(condition) \
        if(!(condition))  \
        {fprintf(stderr, "ERROR IN FILE %s, FUNCTION %s, LINE %d\n", __FILE__, __FUNCTION__, __LINE__);abort();}
#else
#define ASSERT(condition);

#endif

