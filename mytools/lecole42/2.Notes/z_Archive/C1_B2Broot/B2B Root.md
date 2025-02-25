# Configuration
- Disk 2 partitions wiht LVM Encryption
	- partition 1
	- partition 2 \home
- A SSH service will be running on the mandatory 
	- port 4242 in your virtual machine.
	- it must not be possible to connect using SSH as root.
- Firewall
	- UFW (or firewalld for Rocky)
	- only port 4242 open in your virtual machine



# 
# Commands


## Tests
`head -n 2 /etc/os-release`
`ss -tunlp`
`sudo /usr/sbin/ufw status`


## Users and SUDO
`apt install sudo`

`sudo adduser <name>`
`sudo addgroup <group>
`getent group <groupname>`
`cat /etc/group`
`sudo adduser <user> <groupname>`
## Psw Policies and login policies
`mkdir /var/log/sudo`
`vim /etc/sudoers.d/sudo_config`
`vim etc/login.defs
`sudo apt install libpam-pwquality`
`vim /etc/pam.d/common-password`
## Passwords
Root Pass :`Admin42berlin` 
User: `dinepomu`
User Pass: `User42berlin`
	Gorups: user42 and sudo groups.
Encryption Pass: `Disk42berlin`

## SSH
#### Install
`sudo apt update`
`sudo apt install openssh-server`
#### Config
`sudo service ssh status`
`vim /etc/ssh/sshd_config`
- port 4242
- no root ssh
`vim /etc/ssh/sshh_config`
- port4242

../sshd.conf = `AddressFamily any`

Port Fowarding VirtualBox
Host Port:4243
Guest Port: 4242

#### Usage
`sudo service ssh status`
`sudo service ssh restart`

`ip -c a` ||  `ip addr show`  
`ssh dinepomu@172.17.0.1 -p 4243`
`ssh dinepomu@localhost -p 4242`


## Firewall UFW
`sudo apt install ufw`


`sudo ufw status numbered`
`sudo ufw delete <rule_number>`

`sudo ufw enable`
`sudo ufw allow 4242`
`sudo ufw status`



## Monitoring and Crontab
`/usr/local/bin/`
`sudo crontab -u root -e
`*/10 * * * * sh /ruta del script`
## Hasfile Signature.txt
`shasum b2bRoot_Debian1280.vdi`

 ~/s/M/b/V/b2bRoot_Debian1280  shasum b2bRoot_Debian1280.vdi    ✔ │ 13:32:39 
0de12b2330db38d6e917385d678445d8c40ee452  b2bRoot_Debian1280.vdi






# 

# Takeways
## Debian Flavours
**1. Aptitude vs. apt:**

- **apt:** This is the core command-line package manager for Debian (and Debian-based systems like Ubuntu). It's what you'll use most often for installing, removing, and updating software. Think of it as the modern, streamlined way to interact with Debian packages.  
    
- **aptitude:** A more full-featured package manager with a text-based interface (ncurses). It provides more advanced options for searching, filtering, and resolving package dependencies. It can be handy for complex situations or if you prefer a menu-driven approach.  
    

**Key Differences:**

- **Interface:** `apt` is primarily command-line driven, while `aptitude` has an interactive text-based interface.
- **Dependency Handling:** `aptitude` often provides more detailed information and options for resolving complex dependency issues.
- **Search and Filtering:** `aptitude` offers more powerful search and filtering capabilities for finding packages.

**In most cases, `apt` is sufficient for everyday package management tasks.**

## Debian Sandbox Sercurity System
**2. SELinux vs. AppArmor:**

Both SELinux (Security-Enhanced Linux) and AppArmor are **Mandatory Access Control (MAC)** systems that enhance the security of your Debian system. They limit what applications can do and access, even if those applications are compromised by a security vulnerability.  

- **SELinux:**
    - More complex and powerful.
    - Uses labels to define access controls.  
        
    - Can be more difficult to configure.
    - Often used in server environments.
- **AppArmor:**
    - Simpler to understand and manage.
    - Uses profiles to restrict application behavior.
    - Easier to learn and implement.
    - Common on desktop systems.

**Debian 12 defaults to AppArmor.** If you haven't specifically enabled SELinux, it's likely that AppArmor is the MAC system active on your installation.

## Debian File Structure
**3. Other Important Debian Concepts:**

- **`/etc/apt/sources.list`:** This file defines the repositories where Debian retrieves software packages. Understanding how to add or modify repositories can be essential.  
    
- **Debian package formats:** `.deb` is the standard package format. You might encounter `.tar.gz` or `.tar.bz2` archives for source code.
- **Init system:** Debian 12 uses **systemd** as its init system. This is responsible for starting and managing services during the boot process.
- **Important directories:**
    - `/etc/`: System-wide configuration files.
    - `/var/`: Variable data (logs, caches, etc.).
    - `/home/`: User home directories.
    - `/usr/`: Contains most user binaries and libraries.

**Take aways:**

- **Be familiar with basic Debian commands:** `apt update`, `apt install`, `apt remove`, `dpkg -i`, `systemctl status`, etc.
- **Understand the Debian filesystem hierarchy.**
- **Be prepared to explain why you chose Debian 12.** Highlight its stability, security, and the large package repository.
- **If you've customized your system (e.g., installed specific software or configured services), be ready to discuss those changes.**


## GRUB Boat loader
- What is?
## SUDO package
 - what is?