
# USAGE
## Generate File config and Render
```
doxygen -g
doxygen Doxyfile
```
## GUI
```
doxywizard
```

## Clean.sh
``` sh
#!/bin/bash
rm -rf html
rm -rf latex
rm -f doxygen_warnings.log
```

## Template
``` C
/** @brief 
 *
 * 	@details
 * 	@par Details:
 * 	- 
 * 	- 
 * 	- 
 * 	- 
 * 	-  
 * 
 * 	@par Usage:
 * 	- @b [parm1] is
 * 	- @b [parm2] is
 * 	- @b [parm3] is
 * 	- @b return is
 */
 ``` 

``` C
/**
 * @brief 
 * 
 */
 *
 * @details
 * Detailed description of the function's operation.
 * This can span multiple lines and contain detailed explanations.
 *
 * @param param1 Description of first parameter
 * @param param2 Description of second parameter
 * @param param3 Description of third parameter
 *
 * @return Description of the return value
 *
 * @note Any additional notes about usage
 * @see Related functions
 * @example example_usage.c
 */
 ```

# TAGS
Basic Tags  
- @brief - Provides a brief description.
- @param - Describes a function parameter.
- @return - Describes the return value of a function.
- @details - Provides a detailed description.
- @note - Adds a note to the documentation.
- @warning - Adds a warning to the documentation.
- @see - References related functions, classes, or files.
- @code and @endcode - Includes code snippets in the documentation.  

Class and Struct Tags
- @class - Documents a class.
- @struct - Documents a struct.
- @public, @protected, @private - Documents the access level of class members.

File and Group Tags
- @file - Documents a file.
- @ingroup - Adds the element to a specific group.
- @defgroup - Defines a group of related elements.

Miscellaneous Tags
- @todo - Marks something that needs to be done.
- @bug - Documents a known bug.
- @deprecated - Marks a function, class, or method as deprecated.
- @example - Includes an example in the documentation.
- @author - Documents the author of the code.
- @version - Documents the version of the code.
- @date - Documents the date of the code.
- @copyright - Documents the copyright information.





# INSTALL
``` bash
sudo apt-get install doxygen
sudo apt-get install doxygen-gui
sudo apt-get install texlive
```
