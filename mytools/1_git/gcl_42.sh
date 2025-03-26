#!/bin/bash

### Clone or pull with preference for local changes
clone_or_pull() {
    local repo=$2
    local url=$3
	local merge_strategy=$1
    
    if [ -d "$repo" ]; then
        echo "Pulling $repo (keeping #"$merge_strategy" version on conflicts)..."
        rm -rf "$repo"
    else
        echo "Cloning $repo..."
        git clone "$url" "$repo"
    fi
}

main() {
    ### Choose your strategy
    local mode=$1							### 'local' or 'remote' or default
	local strategy=$2  						### 'local' or 'remote' or default
    local pull_function="clone_or_pull" 	### Default to remote
    
    if [ "$strategy" == "local" ]; then
        pull_function="clone_or_pull ours"
        echo "Using strategy: Keep local changes"
    else
	    pull_function="clone_or_pull theirs"
        echo "Using strategy: Keep remote changes"
    fi
    
    if [ "$mode" = "0" ]; then
        ### HTTPS URLs
		echo "### HTTPS URLs"

    elif [ "$mode" = "1" ]; then
        ### SSH URLs
        $pull_function "push_swap" "git@vogsphere.42berlin.de:vogsphere/intra-uuid-f25ad856-811e-4840-893f-ac1d10b029ea-6237479-dinepomu"
        $pull_function "pipex" "git@vogsphere.42berlin.de:vogsphere/intra-uuid-f7869e98-d0f7-4269-8e68-7c6664cdf647-6268301-dinepomu"
        $pull_function "fdf" "git@vogsphere.42berlin.de:vogsphere/intra-uuid-3d8fe4fa-2a54-4f63-89bb-88f7e4947348-6237478-dinepomu"

    elif [ "$mode" = "2" ]; then
        ### PUSH (add all; commit; push)
		(cd push_swap; git add . ; git commit -m "push"; git push)
		(cd pipex; git add . ; git commit -m "push"; git push)
		(cd fdf; git add . ; git commit -m "push"; git push)

	else
		echo "### USE"
		echo "  $0 [0 | 1] [local | remote]"
		echo "    1: ssh  : private"
		echo "    2: push"
		echo "    local: Keep local changes"
		echo "    remote: Keep remote changes (default)"

    fi
}

main "$1" "$2"