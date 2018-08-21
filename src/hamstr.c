#include<R.h>
#include<Rinternals.h>

// The implementation of the increment function. It takes a vector as an 
// argument, creates a new vector and populates the new vector with the values
// of the old vector increased by one. It only works for REALSXP and INTSXP 
// vectors.
SEXP hamstr_increment(SEXP vector) {
  // Create a new vector of the same type and length as the old vector.
  SEXP result = Rf_allocVector(TYPEOF(vector), XLENGTH(vector));

  // Check type of the old vector.
  switch (TYPEOF(vector)) {
    case INTSXP:
      // Iterate over the vectors.
      for (int i = 0; i < XLENGTH(vector); i++)
        // Retrieve an integer element from the old vector with INTEGER_ELT, 
        // add one to the result, and set it as an element of the new vector 
        // with SET_INTEGER_ELT.
        SET_INTEGER_ELT(result, i, INTEGER_ELT(vector, i) + 1);

      return result;

    case REALSXP:
      // Iterate over the vectors.
      for (int i = 0; i < XLENGTH(vector); i++)
	// Retrieve a double element from the old vector with REAL_ELT, add one
        // to the result, and set it as an element of the new vector with 
        // SET_REAL_ELT.
        SET_REAL_ELT(result, i, REAL_ELT(vector, i) + 1);

      return result;

    default:
      // If the vector was neither an INTSXP nor a REALSXP, return R's null 
      // object.
      return R_NilValue;
  }
}
