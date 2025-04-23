#!/system/bin/sh
if [ "$(id -u)" -ne 0 ] && [ "$(id -u)" -ne 2000 ]; then
	printf "[ Eror |@Yeye_nat(Yeye)]\n"
	exit 1
fi

shell() {
	source_msg="$1"
	cmd notification post -I /sdcard/Fidle/prop.png -S bigtext -t '♨️ Priority idle' 'Tag' "$source_msg" >/dev/null 2>&1
}

   echo
    echo "     ☆================================☆"
    echo
    echo "       ~ Description. SpeedsterX........."
    echo
    echo "       - Author                 :  @UnixeID"
    echo "       - Point                    :  Ramex Priority "
    echo "       - Release               :  23 - April - 2025"
    echo "       - Name Shell         :  SpeedsterX "
    echo
    echo "    |_______________________________________|"
    echo "    \______________________________________/"
    echo
    echo "   Priority SpeedsterX Mode Custem. "
    echo 
    sleep 2
     rm -rf /data/local/tmp/*
     cp /sdcard/src/std /data/local/tmp 
     chmod +x /data/local/tmp/std
     if [ "$1" = "-d" ]; then
          shell "Applying Idle priority Low profile. Please wait 1-6 seconds..."
          /data/local/tmp/std -d
     elif [ "$1" = "-L" ]; then
          shell "Applying priority High profile. Please wait 1-4 seconds..."
          /data/local/tmp/std -L
      elif [ "$1" = "-R" ]; then
           shell "Applying Reset system shell idle profile. Please wait 1-3 seconds..."
           /data/local/tmp/std -R
     elif [ "$1" = "-h" ] || [ "$1" = "--help" ]; then
           /data/local/tmp/std --help
        else
          printf "Failed to apply requested profile. Unknown option: %s\n" "$1"
         fi