#!/bin/sh

# Help function
show_help() {
    echo "Usage: $0 [option]"
    echo ""
    echo "Options:"
    echo "  kill      - Triggers the OOM killer manually."
    echo "  help      - Displays this help message."
    echo ""
    echo "If no option is provided, the script will display memory usage statistics."
}

# Check for command-line arguments
if [ "$1" = "help" ]; then
    show_help
    exit 0
elif [ "$1" = "kill" ]; then
    echo "Triggering OOM killer..."
    echo f | sudo tee /proc/sysrq-trigger
    exit 0
fi

# Get total and used memory in MiB from `free`
# The `free -m` command provides memory usage in Megabytes.
# We use awk to parse its output.
mem_info=$(free -m | awk '
/^Mem:/ {
    # From the line starting with "Mem:", print the total and used memory.
    print $2, $3
}')
total_mem=$(echo "$mem_info" | cut -d' ' -f1)
used_mem=$(echo "$mem_info" | cut -d' ' -f2)

# Get process information and consolidate memory usage
# We use 'ps -e -o pmem=,args=' to get the memory percentage and full command arguments.
app_data=$(ps -e -o pmem=,args= --no-headers | awk '
{
    usage = $1
    cmd = $0
    # Remove the usage percentage from the beginning of the line to get the command
    sub(/^[0-9.-]+ +/, "", cmd)

    # Determine the application name from the command
    # Default to the base name of the command
    split(cmd, parts, " ")
    app_path = parts[1]
    sub(/.*\\/, "", app_path)
    app_name = app_path

    # Heuristics to group related processes under a common name
    if (cmd ~ /brave/) {
        app_name = "Brave Browser"
    } else if (cmd ~ /code/ || cmd ~ /Code/) {
        app_name = "VS Code"
    } else if (cmd ~ /gemini/) {
        app_name = "Gemini CLI"
    } else if (cmd ~ /plasmashell/) {
        app_name = "KDE Plasma Shell"
    } else if (cmd ~ /node/) {
        app_name = "Node.js"
    }

    # Sum up the memory usage for the application
    app[app_name] += usage
}
END {
    # Print the consolidated data
    for (a in app) {
        print app[a], a
    }
}')

# Calculate the total percentage of memory used by applications
total_app_usage=$(echo "$app_data" | awk '{sum += $1} END {print sum}')

# Calculate the percentage of memory used by the system (kernel, buffers, cache)
total_used_percent=$(awk -v used="$used_mem" -v total="$total_mem" 'BEGIN {printf "%.2f", (used/total)*100}')
system_usage=$(awk -v total_used="$total_used_percent" -v app_used="$total_app_usage" 'BEGIN {printf "%.2f", total_used - app_used}')

# Combine application data with system usage data and sort it
# We add the calculated system usage as a new entry.
combined_data=$( (echo "$app_data"; echo "$system_usage System (Kernel, Buffers, Cache)") | sort -rn)

# Format the final output
echo "$combined_data" | awk \
-v sys_usage="$system_usage" -v app_usage="$total_app_usage" -v total_usage="$total_used_percent" ' 
BEGIN {
    # Print the summary header
    printf "System Usage (%.2f%%) + User Usage (%.2f%%) = Total Usage (%.2f%%)\n\n", sys_usage, app_usage, total_usage
    # Print the table header for our report.
    printf "% -30s | % -10s | %s\n", "Application(service)", "Usage (%)", "Cumulative (%)"
    print "------------------------------------------------------------"
    cumulative = 0
}
{
    usage = $1
    # Reconstruct the application name, as it might contain spaces.
    app_name = $2
    for (i = 3; i <= NF; i++) {
        app_name = app_name " " $i
    }
    # Update the cumulative usage.
    cumulative += usage
    # Print the formatted line with application name, usage, and cumulative usage.
    printf "% -30s | % -10.2f | %.2f\n", app_name, usage, cumulative
}'

echo "\n--- OOM Killer Check ---"
echo "Value of /proc/sys/vm/panic_on_oom:"
cat /proc/sys/vm/panic_on_oom
echo "\n--- systemd-oomd Status ---"
systemctl status systemd-oomd | grep "Active:"