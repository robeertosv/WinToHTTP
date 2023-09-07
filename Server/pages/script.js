import query from './handler.js'

const h1 = document.querySelector('h1'); //Tomar el texto h1
const btn = document.querySelector('button'); //Tomar el botón

//Cuando se pulse el botón pedir el nomrbre con la contraseña 1234 como token de acceso al recurso. Escribe el nombre en la web
btn.addEventListener('click', async () => {
    let res = await query('http://localhost:3000/name', 'POST', {"pass": 1234});
    res = await res.text();
    
    h1.innerText = `Tu nombre es ${res}`
}) 