### curl
* curl -v 'http://www.tigoe.com'
* curl by default does not follow the redirect
* curl -v -L follows redirect
* curl -X POST to make post requests
* -X lets you make any kind of HTTP request
* curl with query string `curl -d 'name=foo@age=23' 'http://128.122.6.128:8080/data' -v`
* nc 128.122.6.228 8080 < request.txt

```
nc 128.122.6.228 8080 
GET / HTTP/1.1
```
 
### HTTP
* HTTP/HTML runs on application layer
* session layer has HTTP metadata, resets, fin, AEK
* then on transport it's TCP/TLS or possibly UDP
* GQUIC is UDP to get rid of the session layer stuff that slows it down


### Express stuff/Posts/Gets
* in Express intro getPost.js, function routes at bottom
* can send query string ?name=Lolo&age=2
* body parser can be JSON, XML, etc

### Ugly Javascript in Express
* anonymous callback functions
* very common in Express
* more efficient for node
* 'pyramid code', callback hell, making Promises more popular