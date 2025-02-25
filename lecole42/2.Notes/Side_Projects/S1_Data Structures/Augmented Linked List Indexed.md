# Brief:
Create a Linked list that instead of head and tail, it will have a int array that will store addresses of each node.

# Functions:
- ft_ls_CreateNode(* void content)
- ft_ls_AddNodeMiddle(front, middle, back, address)
- ft_ls_DeleteNode/List(node or list, address)

- ft_ReallocArray
You will need a function to realloc size of the int array every time it gets full. Starts with a size and then double it for not needing to resize each node addition.

- ft_Addmiddle(front/back)
You will check if a realoc is needed,
You will need a function that memmove data to allocate the new data in the middle of the array.

# Array structure:
- A[0]= size of the array;
- A[1]=head;
- ...
- A[A[0]]=tail.


# Output:
- Then this is a linked list with a array indexing functionality.
- If the search is by the name, then implement hash struc for searching.