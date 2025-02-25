https://vimsheet.com/

**Check the Most Frequently Used Keys:**

**Cursor Movement (Normal/Visual Mode)**

- `h`, `j`, `k`, `l` - Move left, down, up, right
- `w` / `b` - Move to the next/previous word
- `0` / `$` - Move to the start/end of the current line

**Editing Text**

- `i` / `a` - Start insert mode at/after the cursor
- `o` / `O` - Add a blank line below/above the current line
- `d` / `dd` - Delete/delete the current line
- `c` / `cc` - Change/start insert mode after deleting

**Operators and Marking Text**

- `v` - Start visual mode (to highlight text)
- `y` - Yank (copy) the highlighted text
- `yy` - Yank (copy) the whole line at once
- `control+c = "+y // ``sudo apt-get install vim-gtk3`
- `control+v = "+p // ``sudo apt-get install vim-gtk3`
- `p` - Paste after the cursor
- `>` / `<` - Indent/unindent code blocks

### General Search/Replace and File Manipulation

Here are some useful Vim commands for search-and-replace and working with multiple files, which you may find helpful when working on C++ projects that require creating many headers and classes.

1. **Copying and Renaming Files**
    
    To copy and rename files in a project:
    
    ```bash
    cp old_file.cpp new_file.cpp
    cp old_file.hpp new_file.hp
    ```
    
    For directories, use:
    
    ```bash
    cp folder00/ -r folder01/
    ```
    
2. **Search and Replace in the Whole File**
    
    Replace all instances of a word or string throughout a file:
    
    ```
    :%s/old_word/new_word/g
    ```
    
3. **Autocomplete**
    
    While coding in Vim, you can use **Ctrl+n** to autocomplete words based on existing content in your file, making coding more efficient.


