Linked list Indexed 
``` C
struct s_list {
    int content;
    struct s_list *next; 
};

int main() {
    struct s_list node0 = {10, NULL};
    struct s_list node1 = {20, NULL};
    struct s_list node2 = {30, NULL};

    // Create an array of pointers
    struct s_list *nodes[] = {&node0, &node1, &node2}; 

    for (int i = 0; i < 3; i++) {
        printf("The variable is: %d\n", nodes[i]->content);
    }

    return 0;
}
```

Data Structures (with Lookup)
``` c
#include <stdio.h>
#include <string.h>

struct Data {
    int value;
    char name[20];
} data[] = { {10, "var1"}, {20, "var2"} };

int main() {
    char *target_name = "var2";
    int found_value = -1;

    for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
        if (strcmp(data[i].name, target_name) == 0) {
            found_value = data[i].value;
            break;
        }
    }
    if (found_value != -1) {
        printf("Value of %s: %d\n", target_name, found_value);
    }
    return 0;
}
```

``` c
#include <stdio.h>
#include <string.h>

union Data {
    int intValue;
    float floatValue;
    char stringValue[50];
};

struct Variable {
    char name[20];
    union Data value;
};

int main() {
    struct Variable variables[3] = {
        {"var1", {.intValue = 10}},
        {"var2", {.floatValue = 3.14}},
        {"var3", {.stringValue = "hello"}}
    };

    char *target_name = "var2";

    for (int i = 0; i < 3; i++) {
        if (strcmp(variables[i].name, target_name) == 0) {
            // Access the appropriate member of the union based on the variable name
            if (strcmp(target_name, "var1") == 0) {
                printf("Value of %s: %d\n", target_name, variables[i].value.intValue); 
            } else if (strcmp(target_name, "var2") == 0) {
                printf("Value of %s: %f\n", target_name, variables[i].value.floatValue);
            } else if (strcmp(target_name, "var3") == 0) {
                printf("Value of %s: %s\n", target_name, variables[i].value.stringValue);
            }
            break;
        }
    }

    return 0;
}
```

Function pointers 
``` c
#include <stdio.h>

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }

int main() {
    int (*operation)(int, int); // Function pointer
    char *op_name = "add"; 

    if (strcmp(op_name, "add") == 0) {
        operation = add;
    } else if (strcmp(op_name, "subtract") == 0) {
        operation = subtract;
    }

    int result = operation(5, 3); // Call through function pointer
    printf("Result: %d\n", result);
    return 0;
}
```