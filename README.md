# ssh-bridge
bridge between ssh client and server

## Usage
ssh <--> client.sh(XOR) <- Internet -> server.sh(XOR) <--> sshd <br>
server.sh监听22222端口，与sshd同一主机; <br>
client.sh监听11111端口，与ssh client同一主机; <br>
```bash
server $ server.sh
client $ client.sh $server_ip
client $ ssh -p 11111 $user@127.0.0.1
```

Just for fun.

耍一耍**socat**.
