ifconfig -a | grep 'ether ' | sed 's/.ether.//' | tr -d " "
