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
            for (int i = 0; i < XLENGTH(vector); i++) {
                // Retrieve an integer element at index i from the old vector.
                int element = INTEGER_ELT(vector, i);

                // Check if the element is NA.
                if (element == NA_INTEGER) 
                    // If the element is NA, just copy it to the result.
                    SET_INTEGER_ELT(result, i, element);
                else
                    // Otherwise add one to the element, and set it as an 
                    // element of the new vector.
                    SET_INTEGER_ELT(result, i, element + 1);
            }

            return result;

         case REALSXP:
            // Iterate over the vectors.
            for (int i = 0; i < XLENGTH(vector); i++) {
                // Retrieve a double/real element at index i from the old 
                // vector.
                double element = REAL_ELT(vector, i);

                // Check if the element is NA.
                if (element == NA_REAL) 
                    // If the element is NA, just copy it to the result.
                    SET_REAL_ELT(result, i, element);
                else
                    // Otherwise add one to the element, and set it as an 
                    // element of the new vector.
                    SET_REAL_ELT(result, i, element + 1);
            }

            return result;

        default:
            // If the vector was neither an INTSXP nor a REALSXP, return R's 
            // null object.
            return R_NilValue;
    }
}
