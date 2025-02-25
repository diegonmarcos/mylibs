# Git Push
```sh
#!/bin/bash 

# Get the username from the user 

read -p "Enter username: " user_name 

# Get the groups the user belongs to and sort them 

id -Gn "$user_name" | tr ' ' ',' 

#!/bin/bash 

# Get the message and Root Folder 

#read –p "root folder" f_older 

read -p "Enter message " m_essage 

Git add . 

Git commit –m "update" 

Git push
```
 or
 
```sh
#!/bin/sh

# Get the message and Root Folder

# read -p "root folder" f_older
# read -p "Enter message " m_essage

Git add .
Git commit -m "update"
Git push
```

