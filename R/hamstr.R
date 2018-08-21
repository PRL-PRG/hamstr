# Hello, world!
#
# This is an example function named 'hello'
# which prints 'Hello, world!'.
#
# You can learn more about package authoring with RStudio at:
#
#   http://r-pkgs.had.co.nz/
#
# Some useful keyboard shortcuts for package authoring:
#
#   Build and Reload Package:  'Ctrl + Shift + B'
#   Check Package:             'Ctrl + Shift + E'
#   Test Package:              'Ctrl + Shift + T'

increment <- function(vector) {
  if (typeof(vector) != "double" && typeof(vector) != "integer")
    stop(paste0("Vector is of type", typeof(vector),
                ", must be either integer or double."))

  .Call(hamstr_increment, vector)
}
