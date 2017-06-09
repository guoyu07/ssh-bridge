#!/bin/bash

socat tcp4-listen:22222,fork system:'xor | socat - "tcp4-connect:127.0.0.1:22 | xor"'

