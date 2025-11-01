// Check if fail on init works as expected
%module swig_fail_on_init

%include <swig_pygsl_init.h>
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


    FUNC_MESS_END();
    swig_init_test_fail();
%}
