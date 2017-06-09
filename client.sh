#!/bin/bash

ip=""

arg0=`basename $0`
if [[ $arg0 =~ "client-ip-" ]]; then
	ip=${arg0#client-ip-}
fi

if [ -z "$ip" ]; then
	ip="$1"
fi

echo "Server: $ip"

socat tcp4-listen:11111,fork system:"xor | socat - \"tcp4-connect:${ip}:22222\" | xor"

