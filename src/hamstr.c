#include<R.h>
#include<Rinternals.h>

SEXP hamstr_increment(SEXP vector) {
  SEXP result = Rf_allocVector(TYPEOF(vector), XLENGTH(vector));

  switch (TYPEOF(vector)) {
    case INTSXP:
      for (int i = 0; i < XLENGTH(vector); i++)
        SET_INTEGER_ELT(result, i, INTEGER_ELT(vector, i) + 1);

      break;

    case REALSXP:
      for (int i = 0; i < XLENGTH(vector); i++)
        SET_REAL_ELT(result, i, REAL_ELT(vector, i) + 1);

      break;

    default:
      return R_NilValue;
  }

  return result;
}
