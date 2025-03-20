### ------------------ #
### INSTALL ZSH
### ------------------ #
### Instal zsh and set as default shell
#zsh_install nosudo
#ohmyzsh_install
#dependencies_install

function zsh_install {

	if (command -v zsh >/dev/null 2>&1); then
		echo "Zsh is already installed. Skipping..."
		return
	elif [["$1" == "nosudo"]]; then
		# Create a directory for the installation
		mkdir -p ~/local/zsh

		# Download and extract Zsh source code
		cd /tmp
		wget https://sourceforge.net/projects/zsh/files/latest/download -O zsh.tar.gz
		tar -xzf zsh.tar.gz
		cd zsh-*

		# Configure, compile, and install to your home directory
		./configure --prefix=$HOME/local/zsh
		make
		make install

		# Add to PATH in your current .bashrc or similar
		echo 'export PATH=$HOME/local/zsh/bin:$PATH' >> ~/.bashrc
		source ~/.bashrc

		# Make it your login shell if possible (may require admin assistance)
		# If your admin allows chsh without sudo:
		chsh -s $HOME/local/zsh/bin/zsh
	elif [["$1" == "sudo"]]; then
		sudo apt update
		sudo apt install zsh -y
		chsh -s $(which zsh)
	fi
}

function ohmyzsh_install {
	# Install Oh My Zsh
	sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"
	# For Powerlevel10k
	git clone --depth=1 https://github.com/romkatv/powerlevel10k.git ${ZSH_CUSTOM:-$HOME/.oh-my-zsh/custom}/themes/powerlevel10k
}

funtion dependencies_install {
	# Install dependencies
	sudo apt update
	sudo apt install -y git curl wget
	sudo apt install -y build-essential
	sudo apt install -y libncurses5-dev
	sudo apt install -y libncursesw5-dev
	sudo apt install -y libssl-dev
	sudo apt install -y libreadline-dev
	sudo apt install -y libgdbm-dev
	sudo apt install -y libsqlite3-dev
	sudo apt install -y libbz2-dev
	sudo apt install -y liblzma-dev
	sudo apt install -y zlib1g-dev
	sudo apt install -y uuid-dev
	sudo apt install -y libffi-dev
	sudo apt install -y libdb-dev
	sudo apt install -y libexpat1-dev
	sudo apt install -y libmpdec-dev
}