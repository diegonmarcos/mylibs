# Installation
```sudo apt update
sudo apt install rclone
```

``` 
rclone config 
```

```
rclone rcd --rc-web-gui --rc-addr :53682 &`
```

# Usage

## Initialization
``` bash
rclone mount Gdrive: \                # Mount your Google Drive at the specified mount point
    /home/diego/Documents/Gdrive/ \   # Mount point (local directory)
    --log-file rclone.log \           # Write logs to a file named "rclone.log"
    --log-level INFO \                # Set the logging level to INFO
    --rc \                            # Enable the remote control interface
    --rc-web-gui \                    # Start the rclone web GUI 
    --dir-cache-time 72h \            # Cache directory listings for 72 hours
    --vfs-cache-mode writes \         # Only download files when written to
    --drive-skip-gdocs \              # Skip Google Docs files
    &                                 # Run in the background

```

## Forcing an update (cloud as source)
- Just umount and mount again
```
umount Gdrive
```

- run command refresh
``` bash
rclone rc vfs/refresh directory="path/to/directory"
```
	This command tells rclone to refresh the directory listing and file information for the specified path.

## Forcing an update (local as source):**

- **Usually not necessary:** As mentioned, local changes are typically synced quickly.
``` Bash
rclone rc vfs/sync directory="path/to/directory"
```
	If you're absolutely sure a change hasn't synced and want to force it, you can use thi 