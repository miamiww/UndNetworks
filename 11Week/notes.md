### OpenSSL
open ssl req -newkey rsa:2048 -nodes -keyout domain.key -x509 -days 365 -out domain.crt

curl -X POST -d 'name=LOLO' http://localhost:8080/data/ -L -k


curl -X POST -d 'name=LOLO' https://localhost:443/data/ -L -k