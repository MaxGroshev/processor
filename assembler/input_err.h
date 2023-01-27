#define INPUT_ERR(token, ...)                                                                                                                \
        {                                                                                                                               \
            fprintf (stderr,"Error of input of commands: \033[91m %s  \033[0m\n", token);                                               \
            fprintf (stderr,"Plese check FILE: %s, number of command %d\n", NAME_OF_PROG, (cur_elem + 1));                              \
        }                                                                                                                               \
;
