#!/bin/bash

vscode_backup(){
	# Create a backup directory
	mkdir -p vscode-backup

	# Copy user settings
	cp ~/.config/Code/User/settings.json vscode-backup/
	cp ~/.config/Code/User/keybindings.json vscode-backup/
	cp -r ~/.config/Code/User/snippets vscode-backup/

	# Copy workspace settings
	cp -r ~/Documents/Git/.vscode vscode-backup/workspace-vscode

	# Export extension list
	code --list-extensions > vscode-backup/extensions.txt

	# Remove sensitive data
	sed 's/"wakatime.apiKey":.*"/"wakatime.apiKey": ""/g' -i vscode-backup/settings.json
}

vscode_restore(){
	# Copy user settings
	mkdir -p ~/.config/Code/User/
	cp vscode-backup/settings.json ~/.config/Code/User/
	cp vscode-backup/keybindings.json ~/.config/Code/User/
	cp -r vscode-backup/snippets ~/.config/Code/User/

	# Copy workspace settings
	#cp -r vscode-backup/workspace-vscode /path/to/new/workspace/.vscode

	# Install extensions
	cat vscode-backup/extensions.txt | xargs -L 1 code --install-extension
}

main(){
	if [ $1 = "backup" ]; then
		vscode_backup
	elif [ $1 = "restore" ]; then
		vscode_restore
	else
		echo "Invalid argument. Please use 'backup' or 'restore'."
	fi
}

main $1