#!/bin/bash

script_a(){
if [ -f /etc/os-release ]; then
. /etc/os-release
echo "OS Name: $NAME"
echo "OS Version: $VERSION"
fi
echo "Kernel Version: $(uname -r)"
echo ""
}

script_b(){
echo "Top 10 Processes (CPU Usage):"

ps -eo pid,ppid,cmd,%cpu --sort=-%cpu | head -n 11
echo ""
}

script_c(){
echo "Top 10 Processes (Memory Usage):"

ps -eo pid,ppid,cmd,%mem --sort=-%mem | head -n 11
echo ""
}

script_d(){
echo "User Information:"
echo "Current logged in user: $(whoami)"
echo "Logged Name of the user: $LOGNAME"
echo ""
}

script_e(){
echo "Environment & Shell information"
echo "Current shell: $SHELL"
echo "Home directory: $HOME"
echo "Current path : $PATH"
echo "Current working directory: $(pwd)"
echo "OS type: $(uname -o)"
}

echo "=========================================="
echo "            OPERATING SYSTEMS             "
echo "=========================================="

PS3="Enter your choice (1-6): "

select choice in "OS & Kernel Information"\
                "Top 10 Processes (By CPU usage)"\
                "Top 10 Processes (By memory usage)"\
                "User information"\
                "Environment & Shell Information"\
                "Exit" 
do 
case $choice in
        "OS & Kernel Information")
        script_a
        ;;
        "Top 10 Processes (By CPU usage)")
        script_b
        ;;
        "Top 10 Processes (By memory usage)")
        script_c
        ;;
        "User Information")
        script_d
        ;;
        "Environment & Shell Information")
        script_e
        ;;
        "Exit")
        echo "Exiting. Goodbye :)"
        break
        ;;
        *)
        echo "Invalid input. Please choose (1-6)"
        ;;
esac
done
