#ifndef QRNG_MODULE_DEFINES_H
#define QRNG_MODULE_DEFINES_H 1
#define QRNG_INIT  "Reinitialize the generator Q to its starting point"
#define QRNG_GET   "This function returns the next point X from the sequence generator Q.\n"\
                   "The point X will lie in the range 0 < x_i < 1 for each x_i. If you\n"\
                   "supply an additional integer i, the generator will be sampled i times\n"\
                   " internally."
#define QRNG_NAME  "Returns the name of the generator"
#define QRNG_CLONE "Returns a copy of the generator."
#endif /* QRNG_MODULE_DEFINES_H */
