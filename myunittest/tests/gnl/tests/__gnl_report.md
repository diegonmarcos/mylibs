# GNL - TEST REPORT
 > Test of [16] files  

### Tests:
- ✔ [0] 41_no_nl: **Ok**  
- ✔ [1] 41_with_nl: **Ok**  
- ✔ [2] 42_no_nl: **Ok**  
- ✔ [3] 42_with_nl: **Ok**  
- ✔ [4] 43_no_nl: **Ok**  
- ✔ [5] 43_with_nl: **Ok**  
- ✔ [6] alternate_line_nl_no_nl: **Ok**  
- ✔ [7] alternate_line_nl_with_nl: **Ok**  
- ✔ [8] big_line_no_nl: **Ok**  
- ✔ [9] big_line_with_nl: **Ok**  
- ✔ [10] empty: **Ok**  
- ✔ [11] multiple_line_no_nl: **Ok**  
- ✔ [12] multiple_line_with_nl: **Ok**  
- ✔ [13] multiple_nlx5: **Ok**  
- ✔ [14] nl: **Ok**  
- ✔ [15] variable_nls: **Ok**  


### Valgrind:
- ✔ [0] 41_no_nl: **Ok**  
- ✔ [1] 41_with_nl: **Ok**  
- ✔ [2] 42_no_nl: **Ok**  
- ✔ [3] 42_with_nl: **Ok**  
- ❗ [4] 43_no_nl: `NoK : 35584`  
==34642== Invalid read of size 1
==34642== Process terminating with default action of signal 11 (SIGSEGV)
==34642== All heap blocks were freed -- no leaks are possible
==34642== Invalid read of size 1
- ❗ [5] 43_with_nl: `NoK : 35584`  
==34673== Invalid read of size 1
==34673== Process terminating with default action of signal 11 (SIGSEGV)
==34673== All heap blocks were freed -- no leaks are possible
==34673== Invalid read of size 1
- ✔ [6] alternate_line_nl_no_nl: **Ok**  
- ✔ [7] alternate_line_nl_with_nl: **Ok**  
- ❗ [8] big_line_no_nl: `NoK : 35584`  
==34725== Invalid read of size 1
==34725== Process terminating with default action of signal 11 (SIGSEGV)
==34725== All heap blocks were freed -- no leaks are possible
==34725== Invalid read of size 1
- ❗ [9] big_line_with_nl: `NoK : 35584`  
==34768== Invalid read of size 1
==34768== Process terminating with default action of signal 11 (SIGSEGV)
==34768== All heap blocks were freed -- no leaks are possible
==34768== Invalid read of size 1
- ✔ [10] empty: **Ok**  
- ✔ [11] multiple_line_no_nl: **Ok**  
- ✔ [12] multiple_line_with_nl: **Ok**  
- ✔ [13] multiple_nlx5: **Ok**  
- ✔ [14] nl: **Ok**  
- ✔ [15] variable_nls: **Ok**  
