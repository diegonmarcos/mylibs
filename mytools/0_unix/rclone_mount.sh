#!/bin/bash

# ... Header ...
# Script Name:  rclone_mount.sh
# Description:  GUI startup commands
# Author:       Diego
# Date:

# --- CONFIGURATION ---
MOUNT_POINT="/home/diego/Documents/Gdrive"
RCLONE_OPTS="--log-level INFO --dir-cache-time 72h --vfs-cache-mode writes --drive-skip-gdocs"

# --- FUNCTIONS ---
show_help() {
    echo "Usage: $0 [option]"
    echo "Options:"
    echo "  (no option)   Mount Google Drive."
    echo "  1             Reset: Unmount and remount Google Drive if it is mounted."
    echo "  help          Show this help message."
}

mount_gdrive() {
    rclone mount Gdrive: "$MOUNT_POINT" $RCLONE_OPTS &
}

# --- BODY ---
case "$1" in
    "")
	if mount | grep -q "$MOUNT_POINT"; then
            echo "Google Drive is mounted."
	else
			echo "Google Drive is not mounted. Mounting..."
			mount_gdrive
	fi
        ;;
    "1")
        if mount | grep -q "$MOUNT_POINT"; then
            echo "Google Drive is mounted. Unmounting and remounting..."
			# Try fusermount (for FUSE mounts) first; fallback to forced umount
			fusermount -u -z "$MOUNT_POINT" 2>/dev/null || umount -l -f "$MOUNT_POINT"
            mount_gdrive
        else
            echo "Google Drive is not mounted. Mounting..."
            mount_gdrive
        fi
        ;;
    "help")
        show_help
        ;;
    *)
        echo "Invalid option: $1"
        show_help
        ;;
esac

mount | grep Gdrive
