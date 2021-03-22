# pnfaker
Process name faker for linux/BSD/Unix

## Usage
To compile and get the binary:
```
gcc pnfaker.c -o pnfaker
```

To execute it:
```
./pnfaker "/bin/ls -la" /usr/bin/nc -vn 192.168.1.124 443
```
In the example above we open a netcat connection against host 192.168.1.124 port 443, but we disguise it as "ls -la" if somebody lists that machine processes.

![me](https://github.com/defensahacker/pnfaker/raw/main/pnfaker-covert-channel.gif)
