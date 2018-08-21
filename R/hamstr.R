# This is the R code for the hamstr package.
#
# Some useful keyboard shortcuts for package authoring in Rstudio:
#
#   Build and Reload Package:  'Ctrl + Shift + B'
#   Check Package:             'Ctrl + Shift + E'
#   Test Package:              'Ctrl + Shift + T'

# Increment function checks validity of the arguments and calls a C function 
# via .Call.
increment <- function(vector) {
  # Check if argument is a real or integer vector and throw exception if that
  # is not the case.
  if (typeof(vector) != "double" && typeof(vector) != "integer")
    stop(paste0("Vector is of type", typeof(vector),
                ", must be either integer or double."))

  # Call C function registered as "hamster_increment" and pass vector as 1st 
  # argument.
  .Call(hamstr_increment, vector)
}
