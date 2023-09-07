# WinToHTTP
Example of a C++ application using the Windows API to send data to a Node.js server over HTTP

# Como usarla

1º Abrir Server/server.js y elegir el puerto deseado, por defecto viene el 3000

2º Arrancar el servidor (Vease Server/README.md)

3º Poner en el navegador http://localhost:3000 (Por defecto el server se ejecuta en el puerto 3000)

4º Ejecutar la APP de escritorio (Desktop/x64/Debug/Desktop.exe)

Escribir el nombre en la App y pulsar el botón

Pulsar el botón en la web

# Errores

Si al pulsar el botón en la web pone que nuestro nombre es FORBIDDEN el token de acceso es incorrecto (La contraseña es 1234) asegurate que en Server/pages/script.js la contraseña sea 1234

```js
 let res = await query('http://localhost:3000/name', 'POST', {"pass": 1234});
```

Puedes cambiar la contraseña válida en Server/server.js

````js
if(req.body.pass == 1234) {
        res.send(name)
    }else{
        res.status(403).send('FORBIDDEN');
    }
```
