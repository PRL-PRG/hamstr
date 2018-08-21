# hamstr
Experiments with parallel R.

## Installation

```bash
> R CMD INSTALL $PATH_TO_REPO --preclean
* installing to library ‘/home/kondziu/R/installed/vanilla’
* installing *source* package ‘hamstr’ ...
** libs
gcc -I"/home/kondziu/Workspace/R-3.5.1/include" -DNDEBUG   -g3 -O0 -ggdb   -fpic  -g3 -O0 -ggdb  -c hamstr.c -o hamstr.o
gcc -I"/home/kondziu/Workspace/R-3.5.1/include" -DNDEBUG   -g3 -O0 -ggdb   -fpic  -g3 -O0 -ggdb  -c init.c -o init.o
gcc -shared -L/usr/local/lib -o hamstr.so hamstr.o init.o
installing to /home/kondziu/R/installed/vanilla/hamstr/libs
** R
** byte-compile and prepare package for lazy loading
** help
*** installing help indices
** building package indices
** testing if installed package can be loaded
* DONE (hamstr)
```

## Getting started

Load the library:

```R
> library(hamstr)
```

Run `increment` on a `numeric` vector.

```R
> increment(c(1,2,3,4))
[1] 2 3 4 5
```

Run `increment` on an integer vector.

```R
> increment(as.integer(c(1,2,3,4)))
[1] 2 3 4 5
```

Run `increment` on a string vector.

```R
> increment("a")
Error in increment("a") : 
  Vector is of typecharacter, must be either integer or double.
```

What happens to `NA` values?

```R
> increment(c(1,2,3,4,NA))
[1] 2 3 4 5 NA
```
