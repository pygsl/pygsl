#ifndef PYGSL_UTIL_H
#define PYGSL_UTIL_H

/* I want to enforce the asserts in the code now */

#ifdef DEBUG
#define FUNC_MESS(mess) fprintf(stderr,                            \
                                "%s %s In File %s at line %d\n",   \
                                mess,                              \
                                __FUNCTION__, __FILE__, __LINE__)

#define DEBUG_MESS(level, mess, ...)                                 \
if(DEBUG > level) {                                                  \
fprintf(stderr,                                                      \
	"In Function %s from File %s at line %d "  mess      "\n" ,  \
        __FUNCTION__, __FILE__, __LINE__, __VA_ARGS__);              \
}                                                                   
#else
#define FUNC_MESS(mess)
#define DEBUG_MESS(level, mess,  ...)
#endif

#define FUNC_MESS_BEGIN() FUNC_MESS("BEGIN")
#define FUNC_MESS_END()   FUNC_MESS("END  ")
#ifndef DEBUG
#define DEBUG 0
#endif


#endif /* PYGSL_UTIL_H */
