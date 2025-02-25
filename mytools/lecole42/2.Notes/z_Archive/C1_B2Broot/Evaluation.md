# Checks
`head -n 2 /etc/os-release`  
`ss -tunlp`    
`sudo /usr/sbin/ufw status`  

# OS
Debian for user, and Linux is based on Debian.
Rocky for servers  enterprise use
`hostnamectl`


# Security

**Difference between aptitude and apt, and what APPArmor is?:**

* `apt` is the modern command-line package manager. `aptitude` is a full-featured text-based interface package manager. 
* `AppArmor` is a security module that restricts programs' capabilities.
* `aa-status`

# Users

**groups the user belong:*** `groups <username>`
**create a new user:*** `sudo adduser <username>`
**show the files/folders that have the password policies:*** `/etc/pam.d/common-password` and `/etc/login.defs
**create a new group:*** `sudo addgroup <groupname>`
**assign the user to this group:*** `sudo adduser <username> <groupname>`
**Show groups and user** : `getent passwd`
**why the password policies:**
* Password policies enforce strong passwords, prevent unauthorized access, and protect against brute-force attacks.

# Hostname and Partitions

**hostname check:*** `hostnamectl`
**change hostname:*** `sudo hostnamectl set-hostname <new-hostname>`
**reboot machine:*** `sudo reboot`
**display partitions HD:*** `lsblk`

**Explanation of how LVM works and why it's beneficial:**
* LVM (Logical Volume Management) provides a layer of abstraction over physical disks, allowing for flexible management of storage space, including resizing partitions, creating snapshots, and adding disks without downtime.

# Sudo

**Change to sudo**: `su `
**Change back use:** `su <username>`
**Verify Sudo is installed:*** `which sudo`
**Assign new user to sudo:*** `sudo usermod -aG sudo <username>`
**files/folder with sudo policies:*** `sudo -l` , `/etc/sudoers`, `/etc/sudoers.d/`
**verify that the "/var/log/sudo/" directory exists:*** `ls -ld /var/log/sudo/`

**Explain the purpose and operation of sudo:** 
* Sudo allows authorized users to execute commands with root privileges, providing controlled access and accountability.

# UFW

**Verify UFW package is installed:*** `which ufw`
**UFW status:** `sudo ufw status`
**UFW rules list:*** `sudo ufw status numbered`
**UFW add new rule:*** `sudo ufw allow <port>/<protocol>` (e.g., `sudo ufw allow 8080/tcp`)

# SSH

**verify the package is installed:*** `which ssh`
**SSH status:*** `sudo service ssh status`
**SSH Policies:** `vim /etc/ssh/sshd_config`

**What is SSH?:**
* SSH (Secure Shell) is a cryptographic network protocol for secure remote login and command execution.

# Script Monit.

**Folder/File to change cron rules:*** `crontab -e ` // change to root

**What is "cron":**
* Cron is a time-based job scheduler that allows you to automate tasks.
 


---

