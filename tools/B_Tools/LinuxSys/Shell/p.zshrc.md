# > vim ~/.zshrc

```bash

# Enable Powerlevel10k instant prompt. Should stay close to the top of ~/.zshrc.
# Initialization code that may require console input (password prompts, [y/n]
# confirmations, etc.) must go above this block; everything else may go below.
typeset -g POWERLEVEL9K_INSTANT_PROMPT=quiet
typeset -g POWERLEVEL9K_INSTANT_PROMPT=off

if [[ -r "${XDG_CACHE_HOME:-$HOME/.cache}/p10k-instant-prompt-${(%):-%n}.zsh" ]]; then
  source "${XDG_CACHE_HOME:-$HOME/.cache}/p10k-instant-prompt-${(%):-%n}.zsh"
fi

# If you come from bash you might have to change your $PATH.
#export PATH=$HOME/bin:$HOME/.local/bin:/usr/local/bin:$PATH
#export PATH=$HOME/bin:$HOME/.local/bin:/usr/local/bin
#export PATH="$PATH:/home/dinepomu/goinfre/rclone-v1.68.1-linux-amd64/rclone"


# Path to your Oh My Zsh installation.
export ZSH="$HOME/.oh-my-zsh"

# Set name of the theme to load --- if set to "random", it will
# load a random theme each time Oh My Zsh is loaded, in which case,
# to know which specific one was loaded, run: echo $RANDOM_THEME
# See https://github.com/ohmyzsh/ohmyzsh/wiki/Themes
ZSH_THEME="powerlevel10k/powerlevel10k"

# Set list of themes to pick from when loading at random
# Setting this variable when ZSH_THEME=random will cause zsh to load
# a theme from this variable instead of looking in $ZSH/themes/
# If set to an empty array, this variable will have no effect.
# ZSH_THEME_RANDOM_CANDIDATES=( "robbyrussell" "agnoster" )

# Uncomment the following line to use case-sensitive completion.
# CASE_SENSITIVE="true"

# Uncomment the following line to use hyphen-insensitive completion.
# Case-sensitive completion must be off. _ and - will be interchangeable.
# HYPHEN_INSENSITIVE="true"

# Uncomment one of the following lines to change the auto-update behavior
# zstyle ':omz:update' mode disabled  # disable automatic updates
# zstyle ':omz:update' mode auto      # update automatically without asking
# zstyle ':omz:update' mode reminder  # just remind me to update when it's time

# Uncomment the following line to change how often to auto-update (in days).
# zstyle ':omz:update' frequency 13

# Uncomment the following line if pasting URLs and other text is messed up.
# DISABLE_MAGIC_FUNCTIONS="true"

# Uncomment the following line to disable colors in ls.
# DISABLE_LS_COLORS="true"

# Uncomment the following line to disable auto-setting terminal title.
# DISABLE_AUTO_TITLE="true"

# Uncomment the following line to enable command auto-correction.
# ENABLE_CORRECTION="true"

# Uncomment the following line to display red dots whilst waiting for completion.
# You can also set it to another string to have that shown instead of the default red dots.
# e.g. COMPLETION_WAITING_DOTS="%F{yellow}waiting...%f"
# Caution: this setting can cause issues with multiline prompts in zsh < 5.7.1 (see #5765)
# COMPLETION_WAITING_DOTS="true"

# Uncomment the following line if you want to disable marking untracked files
# under VCS as dirty. This makes repository status check for large repositories
# much, much faster.
# DISABLE_UNTRACKED_FILES_DIRTY="true"

# Uncomment the following line if you want to change the command execution time
# stamp shown in the history command output.
# You can set one of the optional three formats:
# "mm/dd/yyyy"|"dd.mm.yyyy"|"yyyy-mm-dd"
# or set a custom format using the strftime function format specifications,
# see 'man strftime' for details.
# HIST_STAMPS="mm/dd/yyyy"

# Would you like to use another custom folder than $ZSH/custom?
# ZSH_CUSTOM=/path/to/new-custom-folder

# Which plugins would you like to load?
# Standard plugins can be found in $ZSH/plugins/
# Custom plugins may be added to $ZSH_CUSTOM/plugins/
# Example format: plugins=(rails git textmate ruby lighthouse)
# Add wisely, as too many plugins slow down shell startup.
plugins=(git)

source $ZSH/oh-my-zsh.sh

# User configuration
# AUTOCOMPLETE
autoload -U predict-on
predict-on


# export MANPATH="/usr/local/man:$MANPATH"

# You may need to manually set your language environment
# export LANG=en_US.UTF-8

# Preferred editor for local and remote sessions
# if [[ -n $SSH_CONNECTION ]]; then
#   export EDITOR='vim'
# else
#   export EDITOR='nvim'
# fi

# Compilation flags
# export ARCHFLAGS="-arch $(uname -m)"

# Set personal aliases, overriding those provided by Oh My Zsh libs,
# plugins, and themes. Aliases can be placed here, though Oh My Zsh
# users are encouraged to define aliases within a top-level file in
# the $ZSH_CUSTOM folder, with .zsh extension. Examples:# - $ZSH_CUSTOM/aliases.zsh
# - $ZSH_CUSTOM/macos.zsh
# For a full list of active aliases, run `alias`.
#
# Example aliases
# alias zshconfig="mate ~/.zshrc"
# alias ohmyzsh="mate ~/.oh-my-zsh"

alias gcl='git clone'
alias push='git add . && git commit -m "update" && git push'
alias norm="norminette -R CheckForbiddenSourceHeader CheckDefine"
function ccx {
    cc "$1" -o "$(basename "$1" .c).out" -Wall -Wextra -Werror
    output_file="./$(basename "$1" .c).out"

    # Check if additional arguments are provided ($2, $3, etc.)
    if [[ $# -gt 1 ]]; then  # $# is the number of arguments to the function
        # Use "$@" to expand all arguments from $2 onwards, properly quoted.
        "$output_file" "${@:2}" # "${@:2}" expands to $2 $3 $4 ...
    else
        "$output_file" # Execute with no arguments if none provided
    fi
}
function ccx {
    cc "$1" -o "$(basename "$1" .c).out"
    output_file="./$(basename "$1" .c).out"

    # Check if additional arguments are provided ($2, $3, etc.)
    if [[ $# -gt 1 ]]; then  # $# is the number of arguments to the function
        # Use "$@" to expand all arguments from $2 onwards, properly quoted.
        "$output_file" "${@:2}" # "${@:2}" expands to $2 $3 $4 ...
    else
        "$output_file" # Execute with no arguments if none provided
    fi
}

alias francinette=/home/dinepomu/sgoinfre/francinette-image/run.sh
alias paco=/home/dinepomu/sgoinfre/francinette-image/run.sh

# To customize prompt, run `p10k configure` or edit ~/.p10k.zsh.
[[ ! -f ~/.p10k.zsh ]] || source ~/.p10k.zsh

# Check if the Gdrive is mounted by looking for it in the mount outpu. '-q' is silent no output.
if ! mount | grep -q "/home/dinepomu/MyFiles/Gdrive "; then
 # If not mounted, mount it using rclone
        rclone mount Gdrive: \
            /home/dinepomu/MyFiles/Gdrive/ \
            --log-level INFO \
            --rc \
            --rc-web-gui \
            --dir-cache-time 72h \
            --vfs-cache-mode writes \
            --drive-skip-gdocs \
            &    
fi

#Docker Container load, run and start
if ! docker info | grep 'Running' &> /dev/null; then
		echo "[Francinette] Starting Docker..." &> /dev/null
		sleep 1
		exec "/bin/zsh"
fi

if ! docker image ls | grep 'francinette-image' &> /dev/null; then
		echo "[Francinette] Loading the docker container"
		docker load < /home/dinepomu/sgoinfre/francinette-image/francinette.tar
		exec "/bin/zsh"
fi

if ! docker ps | grep 'francinette-image' &> /dev/null; then
	if docker run -d -i -p 53682:53682 -v /home:/home -v /goinfre:/goinfre -v /sgoinfre:/sgoinfre -v /home/dinepomu/sgoinfre/francinette-image/logs:/francinette/logs-t --name run-paco francinette-image /bin/bash 2>&1 | grep 'already' &> /dev/null; then
		docker start run-paco
	fi
fi

# STARTING SCREEN
clear

# Clear the screen
clear

# Function to fetch and format system info
function get_system_info {
  local os_name=$(uname -s)
  local kernel_version=$(uname -r)
  local hostname=$(hostname)
  local uptime=$(uptime | awk '{print $3, $4}' | sed 's/,//')
  local cpu_model=$(lscpu | grep "Model name:" | awk '{print $3,$4,$5,$6,$7,$8}')
  local memory_usage=$(free -h | awk '/Mem:/ {printf "%.1f GB / %.1f GB", $3/1024/1024, $2/1024/1024}')

  echo -e "\nSystem Information:"
  echo -e "------------------"
  echo -e "OS:\t\t$os_name"
  echo -e "Kernel:\t\t$kernel_version"
  echo -e "Hostname:\t$hostname"
  echo -e "Uptime:\t\t$uptime"
  echo -e "CPU:\t\t$cpu_model"
  echo -e "Memory:\t\t$memory_usage"
}

# Function to fetch and format network info
function get_network_info {
  local ip_address=$(ip addr show eth0 | grep "inet\b" | awk '{print $2}' | cut -d/ -f1)  # Adjust 'eth0' if needed
  local gateway=$(ip route | grep default | awk '{print $3}')

  echo -e "\nNetwork Information:"
  echo -e "-------------------"
  echo -e "IP Address:\t$ip_address"
  echo -e "Gateway:\t$gateway"
}

# Function to fetch and format disk usage
function get_disk_usage {
  local disk_usage=$(df -h / | awk 'NR==2 {printf "%s / %s (%.1f%%)", $3, $2, $5}')

  echo -e "\nDisk Usage:"
  echo -e "-----------"
  echo -e "Root:\t\t$disk_usage"
}

# --- Main screen output ---

# Header
echo -e "\e[1;34mWelcome to your shell, $(whoami)!\e[0m"  # Blue color
date +"%A, %B %d, %Y - %I:%M %p"

# System, Network, and Disk Info
get_system_info
get_network_info
get_disk_usage

# Optional: Add more sections for other data (e.g., weather, calendar, news)

# Footer
echo -e "\n\e[32mHave a productive day!\e[0m"  # Green color

# ... (header and other sections) ...

# ART
echo_with_art() {
  # Print the ASCII art
  cat << 'EOF'

           _               _       
       _  /\ \           /\ \      
      /\_\\ \ \         /  \ \     
     / / / \ \ \       / /\ \ \    
    / / /   \ \ \      \/_/\ \ \   
    \ \ \____\ \ \         / / /   
     \ \________\ \       / / /    
      \/________/\ \     / / /  _  
                \ \ \   / / /_/\_\ 
                 \ \_\ / /_____/ / 
                  \/_/ \________/  
                                   

EOF

  # Print the arguments passed to the function
  echo "$@"
}

# Call the function
echo_with_art 
```
