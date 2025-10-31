// Check if fail on init works as expected
%module swig_fail_on_init

%{
    #include <pygsl/utils.h>
%}

%init %{
    // deliberatley not initalsing pygsl here
    // so setting the debug level artificially
    // intention: make it visible which flag is returned
#if DEBUG == 1
    pygsl_debug_level = 10;
#endif
    FUNC_MESS_BEGIN();

    // some swig version did make the init reply with a different value
    // check that it fullfills this requirements
    PyErr_SetString(PyExc_AssertionError, "this module is failing intentionally on import");


#if SWIG_VERSION >= 0x040400 // SWIG >= 4.4.0
    const int returned_flag = -1;
#else
    const void * returned_flag = NULL;
#endif
    DEBUG_MESS(2, "Swig version %x returning flag %ld ", SWIG_VERSION, (long int) returned_flag);
    FUNC_MESS_END();
    return returned_flag;
%}
