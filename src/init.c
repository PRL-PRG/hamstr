#include "hamstr.h"

#include <R_ext/Rdynload.h>
#include <R_ext/Visibility.h>

/* List of functions provided by the package. */
static const R_CallMethodDef CallEntries[] = {
    {"hamstr_increment", (DL_FUNC) &hamstr_increment, 1}, /* Incement function, 1 argumemnt) */
    {NULL, NULL, 0} /* Terminates the function list. Necessary. */
};

void attribute_visible R_init_hamstr(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
    R_forceSymbols(dll, TRUE);
}
