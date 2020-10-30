# Printf  

The goal of this project is pretty straightforward. Recode libc’s printf so you have a better understanding of how it works.
Besides that it's a good way to learn how to use variadic arguments in C.

This versions manages the following conversions: cspdiuxX%#+'_'. Besides that it
manages any combination of the following flags: ’-0.*’ and minimum field width.

When 'make' is ran, a static lib is created (libftprintf.a) that can be used in any C project. 