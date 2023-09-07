const express = require('express');
const app = express();
const server = require('http').createServer(app);
const port = 3000;

app.use(express.static('./pages'));
app.use(express.json());

let name; //Guardar el nombre

//Al acceder a localhost:(port) enviar el archivo index.html
app.get('/', (req, res) => {
    res.send('./pages')
})

//Cuando se acceda a localhost:(port)/api escribir el nombre en la variable name
app.post('/api', (req, res) => {
    let n = req.body.name;
    name = n;
    console.log(n)
    res.status(200).send('OK')
})

//Cuando se acceda a localhost:(port)/name y la contraseña sea 1234 enviar el nombre
app.post('/name', (req, res) => {
    if(req.body.pass == 1234) {
        res.send(name)
    }else{
        res.status(403).send('FORBIDDEN');
    }
})
server.listen(port, () => console.log(`http://localhost:${port}`));