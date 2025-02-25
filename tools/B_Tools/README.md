# Documentation

> Use obsidian!  

## 1. Install Obsidian

### For Linux  
``` bash
wget https://github.com/obsidianmd/obsidian-releases/releases/download/v1.4.16/Obsidian-1.4.16.AppImage
    chmod +x Obsidian-1.4.16.AppImage
    ./Obsidian-1.4.16.AppImage
```
### For MacOs
> [https://obsidian.md/download](https://obsidian.md/download)

## 2. Clone repo

``` bash
https://github.com/diegonmarcos/documentation.git
```
## 3. Open new Vault from...

########################################################################################


# Project Index and Landing Page

This page serves as an index and landing page for the various projects and resources within this repository. The projects are organized into categories based on their purpose and complexity. You can navigate through the structure using the collapsible sections below.

## Projects

<details>
  <summary><b>B_Tools</b></summary>

  Tools and resources for general development, 42 School specific tasks, code productivity, and Linux system management.

  <details>
    <summary>0.General</summary>

- General resources and notes.
   - [General.md](B_Tools/0.General/General.md)
   - [index.md](B_Tools/0.General/index.md)
  </details>

  <details>
    <summary>42School</summary>

- Resources related to 42 School curriculum, exams, and the Norminette.
    - [Curricullum.md](B_Tools/42School/Curricullum.md)
    - [Exams.md](B_Tools/42School/Exams.md)
    - [Norminette.md](B_Tools/42School/Norminette.md)
    - [Resources_2.md](B_Tools/42School/Resources_2.md)
    - [Resources.md](B_Tools/42School/Resources.md)
  </details>

  <details>
    <summary>CodeProductivity</summary>

    Tools and resources to enhance code productivity, including cheatsheets, cloud services, IDEs/editors, Jupyter, and unit testers/debuggers.

    <details>
      <summary>Cloud</summary>

	- Information on Git and rclone.

      <details>
        <summary>Git</summary>
          
        - [Commands.md](B_Tools/CodeProductivity/Cloud/Git/Commands.md)
        - [GCL Bash.md](B_Tools/CodeProductivity/Cloud/Git/GCL%20Bash.md)
        - [p.gitignore.md](B_Tools/CodeProductivity/Cloud/Git/p.gitignore.md)
        - [p.gitmodules.md](B_Tools/CodeProductivity/Cloud/Git/p.gitmodules.md)
        - [Resources.md](B_Tools/CodeProductivity/Cloud/Git/Resources.md)
        - [Sources.md](B_Tools/CodeProductivity/Cloud/Git/Sources.md)
      </details>
      
      - [rclone.md](B_Tools/CodeProductivity/Cloud/rclone.md)
    </details>
  
    <details>
      <summary>IDEsEditors</summary>
      
    - Information on various IDEs and editors.
      
      - [readme.md](B_Tools/CodeProductivity/IDEsEditors/readme.md)
      - [VsCode.md](B_Tools/CodeProductivity/IDEsEditors/VsCode.md)
      
      <details>
          <summary>VIM</summary>
          
          - [Install.md](B_Tools/CodeProductivity/IDEsEditors/VIM/Install.md)
          - [p.vimrc_42Header.md](B_Tools/CodeProductivity/IDEsEditors/VIM/p.vimrc_42Header.md)
          - [p.vimrc.md](B_Tools/CodeProductivity/IDEsEditors/VIM/p.vimrc.md)
          - [Vim-Cheat-Sheet.md](B_Tools/CodeProductivity/IDEsEditors/VIM/Vim-Cheat-Sheet.md)
      </details>
    </details>

    <details>
      <summary>Jupyter</summary>
      
    - [Setup.md](B_Tools/CodeProductivity/Jupyter/Setup.md)
    </details>

    <details>
      <summary>UnitTesters_Debuggers</summary>
      
    - Resources for code quality, debugging, and unit testing.
      
      - [CodeQuality.md](B_Tools/CodeProductivity/UnitTesters_Debuggers/CodeQuality.md)
      - [Debugger.md](B_Tools/CodeProductivity/UnitTesters_Debuggers/Debugger.md)
      - [UnitTesters.md](B_Tools/CodeProductivity/UnitTesters_Debuggers/UnitTesters.md)
    </details>
  </details>

  <details>
    <summary>LinuxSys</summary>
    
    Resources for Linux system administration, including Docker, commands, login scripts, shell configurations, and VPNs.
    
    - [Docker](B_Tools/LinuxSys/Docker)
      - [Docker_c.md](B_Tools/LinuxSys/Docker/Docker_c.md)
    - [LINUX_Commands.md](B_Tools/LinuxSys/LINUX_Commands.md)
    - [Linux.md](B_Tools/LinuxSys/Linux.md)
    - [Login.sh.md](B_Tools/LinuxSys/Login.sh.md)
    - [p.zshrc.md](B_Tools/LinuxSys/p.zshrc.md)
    - [Scripts.md](B_Tools/LinuxSys/Scripts.md)
    - [Shell](B_Tools/LinuxSys/Shell)
      - [ohmyzsh.md](B_Tools/LinuxSys/Shell/ohmyzsh.md)
      - [p.zshrc.md](B_Tools/LinuxSys/Shell/p.zshrc.md)
      - [Regex_CheatSheet.md](B_Tools/LinuxSys/Shell/Regex_CheatSheet.md)
    - [VPN](B_Tools/LinuxSys/VPN)
      - [Options.md](B_Tools/LinuxSys/VPN/Options.md)
      - [Proton.md](B_Tools/LinuxSys/VPN/Proton.md)
  </details>

	- [README.md](B_Tools/README.md)
</details>

<details>
  <summary><b>C0_Libft</b></summary>

  The Libft project, a custom C library.

  - [Documentation.md](C0_Libft/Documentation.md)
  - [Roadmap.md](C0_Libft/Roadmap.md)
  <details>
    <summary>Pages</summary>
    
    Detailed documentation for each function in Libft.
    
    <details>
      <summary>0.Include</summary>
      
      - [libftH.md](C0_Libft/Pages/0.Include/libftH.md)
      - [Makefile.md](C0_Libft/Pages/0.Include/Makefile.md)
    </details>

    <details>
      <summary>1.IOPrinters</summary>
      
      - [ft_putchar_fd.md](C0_Libft/Pages/1.IOPrinters/ft_putchar_fd.md)
      - [ft_putendl_fd.md](C0_Libft/Pages/1.IOPrinters/ft_putendl_fd.md)
      - [ft_putnbr_fd.md](C0_Libft/Pages/1.IOPrinters/ft_putnbr_fd.md)
      - [ft_putstr_fd.md](C0_Libft/Pages/1.IOPrinters/ft_putstr_fd.md)
    </details>

    <details>
      <summary>2.StringClassification</summary>
      
      - [ft_isalnum.md](C0_Libft/Pages/2.StringClassification/ft_isalnum.md)
      - [ft_isalpha.md](C0_Libft/Pages/2.StringClassification/ft_isalpha.md)
      - [ft_isascii.md](C0_Libft/Pages/2.StringClassification/ft_isascii.md)
      - [ft_isdigit.md](C0_Libft/Pages/2.StringClassification/ft_isdigit.md)
      - [ft_isprint.md](C0_Libft/Pages/2.StringClassification/ft_isprint.md)
      - [ft_strlen.md](C0_Libft/Pages/2.StringClassification/ft_strlen.md)
    </details>

    <details>
      <summary>3.StringFormatting</summary>
      
      - [ft_atoi.md](C0_Libft/Pages/3.StringFormatting/ft_atoi.md)
      - [ft_bzero.md](C0_Libft/Pages/3.StringFormatting/ft_bzero.md)
      - [ft_itoa.md](C0_Libft/Pages/3.StringFormatting/ft_itoa.md)
      - [ft_striteri.md](C0_Libft/Pages/3.StringFormatting/ft_striteri.md)
      - [ft_strmapi.md](C0_Libft/Pages/3.StringFormatting/ft_strmapi.md)
      - [ft_tolower.md](C0_Libft/Pages/3.StringFormatting/ft_tolower.md)
      - [ft_toupper.md](C0_Libft/Pages/3.StringFormatting/ft_toupper.md)
    </details>

    <details>
      <summary>4.StringSearchCompareSubs</summary>
      
      - [ft_memchr.md](C0_Libft/Pages/4.StringSearchCompareSubs/ft_memchr.md)
      - [ft_memcmp.md](C0_Libft/Pages/4.StringSearchCompareSubs/ft_memcmp.md)
      - [ft_strchr.md](C0_Libft/Pages/4.StringSearchCompareSubs/ft_strchr.md)
      - [ft_strncmp.md](C0_Libft/Pages/4.StringSearchCompareSubs/ft_strncmp.md)
      - [ft_strnstr.md](C0_Libft/Pages/4.StringSearchCompareSubs/ft_strnstr.md)
      - [ft_strrchr.md](C0_Libft/Pages/4.StringSearchCompareSubs/ft_strrchr.md)
      - [ft_substr.md](C0_Libft/Pages/4.StringSearchCompareSubs/ft_substr.md)
    </details>

    <details>
      <summary>5.MemoryCopyMoveSplit</summary>

      - [ft_calloc.md](C0_Libft/Pages/5.MemoryCopyMoveSplit/ft_calloc.md)
      - [ft_memchr.md](C0_Libft/Pages/5.MemoryCopyMoveSplit/ft_memchr.md)
      - [ft_memcmp.md](C0_Libft/Pages/5.MemoryCopyMoveSplit/ft_memcmp.md)
      - [ft_memcpy.md](C0_Libft/Pages/5.MemoryCopyMoveSplit/ft_memcpy.md)
      - [ft_memmove.md](C0_Libft/Pages/5.MemoryCopyMoveSplit/ft_memmove.md)
      - [ft_memset.md](C0_Libft/Pages/5.MemoryCopyMoveSplit/ft_memset.md)
      - [ft_split.md](C0_Libft/Pages/5.MemoryCopyMoveSplit/ft_split.md)
      - [ft_strdup.md](C0_Libft/Pages/5.MemoryCopyMoveSplit/ft_strdup.md)
      - [ft_strjoin.md](C0_Libft/Pages/5.MemoryCopyMoveSplit/ft_strjoin.md)
      - [ft_strlcat.md](C0_Libft/Pages/5.MemoryCopyMoveSplit/ft_strlcat.md)
      - [ft_strlcpy.md](C0_Libft/Pages/5.MemoryCopyMoveSplit/ft_strlcpy.md)
      - [ft_strtrim.md](C0_Libft/Pages/5.MemoryCopyMoveSplit/ft_strtrim.md)
      - [ft_substr.md](C0_Libft/Pages/5.MemoryCopyMoveSplit/ft_substr.md)
      - [Memory functions.md](C0_Libft/Pages/5.MemoryCopyMoveSplit/Memory%20functions.md)
    </details>

    <details>
      <summary>6.StructLinkedLists</summary>
      
      - [ft_lstadd_back.md](C0_Libft/Pages/6.StructLinkedLists/ft_lstadd_back.md)
      - [ft_lstadd_front.md](C0_Libft/Pages/6.StructLinkedLists/ft_lstadd_front.md)
      - [ft_lstclear.md](C0_Libft/Pages/6.StructLinkedLists/ft_lstclear.md)
      - [ft_lstdelone.md](C0_Libft/Pages/6.StructLinkedLists/ft_lstdelone.md)
      - [ft_lstiter.md](C0_Libft/Pages/6.StructLinkedLists/ft_lstiter.md)
      - [ft_lstlast.md](C0_Libft/Pages/6.StructLinkedLists/ft_lstlast.md)
      - [ft_lstmap.md](C0_Libft/Pages/6.StructLinkedLists/ft_lstmap.md)
      - [ft_lstnew.md](C0_Libft/Pages/6.StructLinkedLists/ft_lstnew.md)
      - [ft_lstsize.md](C0_Libft/Pages/6.StructLinkedLists/ft_lstsize.md)
    </details>
  </details>
</details>

<details>
  <summary><b>C1_GnL</b></summary>

  The Get Next Line project, reading lines from a file descriptor.

  - [Documentation.md](C1_GnL/Documentation.md)
  - [RoadMap_Backlog.md](C1_GnL/RoadMap_Backlog.md)
</details>

<details>
  <summary><b>C1_Printf</b></summary>

  The ft_printf project, a custom implementation of the printf function.

  - [Documentation.md](C1_Printf/Documentation.md)
  - [RoadMap_Backlog.md](C1_Printf/RoadMap_Backlog.md)
</details>

<details>
  <summary><b>C2_ExamRank2</b></summary>

  Preparation materials for the second 42 School exam.

  - [examrank02.md](C2_ExamRank2/examrank02.md)
</details>

<details>
  <summary><b>C3_push_swap</b></summary>

  The push_swap project, sorting data on a stack with a limited set of instructions.

  - [Algo.md](C3_push_swap/Algo.md)
  - [Page.md](C3_push_swap/Page.md)
</details>

## Side Projects

<details>
  <summary><b>Side_Projects</b></summary>

  Various side projects, including library extensions, unit testing, data structures, front-end development, and personal setup.
  
  <details>
    <summary>S0_libft_xtend</summary>
    
    - [S0_libft_xtend.md](Side_Projects/S0_libft_xtend/S0_libft_xtend.md)
  </details>

  <details>
    <summary>S0_lib_unit</summary>

    - [S0_UnitTesting.md](Side_Projects/S0_lib_unit/S0_UnitTesting.md)
  </details>

  <details>
    <summary>S1_Data Structures</summary>
    
    - [Augmented Linked List Indexed.md](Side_Projects/S1_Data%20Structures/Augmented%20Linked%20List%20Indexed.md)
    - [CvCs.md](Side_Projects/S1_Data%20Structures/CvCs.md)
    - [Data structure notes.md](Side_Projects/S1_Data%20Structures/Data%20structure%20notes.md)
    - [Undefined Behaviour.md](Side_Projects/S1_Data%20Structures/Undefined%20Behaviour.md)

    <details>
      <summary>Struct implementations</summary>
      
      - [Augmented Linked List Indexed.md](Side_Projects/S1_Data%20Structures/Struct%20implementations/Augmented%20Linked%20List%20Indexed.md)
      - [Struct example with.md](Side_Projects/S1_Data%20Structures/Struct%20implementations/Struct%20example%20with.md)
    </details>
  </details>

  <details>
    <summary>S3_FrontEnd</summary>
    
    - [Infographics.md](Side_Projects/S3_FrontEnd/Infographics.md)
    - [MkDw_JvSc.md](Side_Projects/S3_FrontEnd/MkDw_JvSc.md)
  </details>

  <details>

  # Thank you !
  

``` 
							
   696     696  96969      _=_      9696969  69    696
     9696    969696       (-_-)      696969    6969
        96969696          _) (_          69696969
           96            /__/  \            69
           69          _(<_   / )_          96
          6969        (__\_\_|_/__)        9696


```

------------------------------------------------

``` 


      __                  _                _            __
     >(' )           _  /\ \             /\ \         >(' )
       )/          /\_\\  \ \           /  \ \          )/
      /(          / / / \  \ \         / /\ \ \         /(
     /  `----/   / / /   \  \ \        \/_/\ \ \        \  `----\
jgs  \  ~=- /    \ \ \____\  \ \           / / /         \  ~=- /  
   ~^~^~^~^~^~^~^ \ \________ \ \         / / /     ~^~^~^~^~^~^~^ 
                   \/________/ \ \       / / /  _
                              \ \ \     / / /_/\_\
                               \ \_\   / /_____/ /
                                \/_/   \________/
```
