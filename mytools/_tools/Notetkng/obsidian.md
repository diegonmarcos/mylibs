# Obsidian Markdown&Snippets
## Snippets
**Functionality & Workflow**
1. **Current Date:** `{{date}}` (or variations for specific formats) - Quickly insert today's date.
2. **Current Time:** `{{time}}` - Insert the current time.
3. **File Name:** `{{title}}` - Insert the current note's title.
4. **Link to Current File:** `[[{{title}}]]` - Create a self-referential link within a note.
5. **Random Number:** `{{random}}` (with optional range) - Generate a random number for various uses.
6. **Clipboard Content:** `{{clipboard}}` - Paste the contents of your clipboard.

**Templates & Note Creation**
7. **Template Insertion:** `/Template Name` - Trigger a specific template from your template folder.
8. **Daily Note:** `/Daily Note` - Quickly create or open today's daily note.
9. **New Note with Link:** `[[new note name]]` - Create a new note and link to it simultaneously.

**Text Manipulation**
10. **Title Case:** `{{title(text)}}` - Transform text to title case (e.g., "hello world" to "Hello World").
11. **Uppercase:** `{{upper(text)}}` - Convert text to uppercase.
12. **Lowercase:** `{{lower(text)}}` - Convert text to lowercase.

**Dates & Time**
13. **Date Arithmetic:** `{{date+1d}}` (or similar) - Calculate dates relative to today or a specified date.
14. **Day of the Week:** `{{date:dddd}}` - Get the day of the week for a given date.

**Advanced Snippets**
15. **Conditional Statements:** `{{#if condition}} text {{else}} other text {{/if}}` - Display text based on a condition.
16. **Iteration:** `{{#each list}} item {{/each}}` - Loop through a list and perform actions.
17. **Javascript Code Execution:** `{{js: code }}` - Execute JavaScript code within a snippet.

## Markdown
1. **Headers:**    
    # This is a level 1 heading
    ## This is a level 2 heading
    ### This is a level 3 heading
    
2. **Emphasis:**
    *This text will be italic*
    _This will also be italic_
    
    **This text will be bold**
    __This will also be bold__
    
3. **Lists:**    ```
    - Item 1
    - Item 2
      - Subitem 2.1
      - Subitem 2.2
    - Item 3
    1. Numbered item 1
    2. Numbered item 2

4. **Links:**
    [Link text](https://www.example.com)

5. **Images:**
    ![Alt text](image.jpg)
6. **Code:**
    `This is inline code`
    ```python
    def my_function():
        print("Hello, world!")
    ````
    
7. **Blockquotes:**
    > This is a blockquote. 
    
8. **Horizontal Rule:**
---

9. **Tables:**

| Header 1 | Header 2 |
| -------- | -------- |
| Cell 1   | Cell 2   |
| Cell 3   | Cell 4   |

10. **Escaping Characters:**

\*This text will not be italic\* *This text will be italic*

11. **Nested Lists:**
    - Item 1
      - Subitem 1.1
        - Sub-subitem 1.1.1
      - Subitem 1.2
    - Item 2

12. **Task Lists:**
    - [x] Task 1 (completed)
    - [ ] Task 2 (incomplete)

13. **Definition Lists:**
    Term 1
    : Definition 1
    Term 2
    : Definition 2a
    : Definition 2b

14. **Footnotes:**
    This is some text with a footnote.[^1]
    [^1]: This is the footnote.
    
15. **Strikethrough:**

    ~~This text will be struck through.~~
    
16. **Highlight:**
    <mark>This text will be highlighted.</mark>
    
17. **Superscript:**
    This is a superscript^2^
    
18. **Subscript:**
    This is a subscript~2~
    
19. **HTML:**
    <p>This is a paragraph of HTML.</p>
    
20. **Line Breaks:**
    This is the first line.  
    This is the second line.
    (Note the two spaces at the end of the first line)
 
## Admotion
**1. Notes and Tips:**
> [!note] 
> This is a note about an important concept. You can use it to emphasize key takeaways or definitions.

**2. Warnings and Cautions:**

> [!warning] 
> Be careful when implementing this code. It could lead to unexpected consequences if not handled correctly.

**3. Important Information:**
> [!important]
>  Don't forget to back up your data regularly!

**4. Examples and Illustrations:**
> [!example]
> This is how you would format a code block:
> ```python
> print("Hello, world!")
> ```

**5. Questions and FAQs:**
> [!question]
> What is the best way to learn Markdown?
> 
> Practice and experimentation are key!

  