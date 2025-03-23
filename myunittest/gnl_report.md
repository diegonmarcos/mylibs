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
==463049== Invalid read of size 1
==463049== Process terminating with default action of signal 11 (SIGSEGV)
==463049== All heap blocks were freed -- no leaks are possible
==463049== Invalid read of size 1
- ❗ [5] 43_with_nl: `NoK : 35584`  
==463071== Invalid read of size 1
==463071== Process terminating with default action of signal 11 (SIGSEGV)
==463071== All heap blocks were freed -- no leaks are possible
==463071== Invalid read of size 1
- ✔ [6] alternate_line_nl_no_nl: **Ok**  
- ✔ [7] alternate_line_nl_with_nl: **Ok**  
- ❗ [8] big_line_no_nl: `NoK : 35584`  
==463123== Invalid read of size 1
==463123== Process terminating with default action of signal 11 (SIGSEGV)
==463123== All heap blocks were freed -- no leaks are possible
==463123== Invalid read of size 1
- ❗ [9] big_line_with_nl: `NoK : 35584`  
==463174== Invalid read of size 1
==463174== Process terminating with default action of signal 11 (SIGSEGV)
==463174== All heap blocks were freed -- no leaks are possible
==463174== Invalid read of size 1
- ✔ [10] empty: **Ok**  
- ✔ [11] multiple_line_no_nl: **Ok**  
- ✔ [12] multiple_line_with_nl: **Ok**  
- ✔ [13] multiple_nlx5: **Ok**  
- ✔ [14] nl: **Ok**  
- ✔ [15] variable_nls: **Ok**  
