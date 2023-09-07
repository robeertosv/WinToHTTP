//Middleware para gestionar los fetch que se requieran 

async function query(url, method, data) {
    let headers = new Headers();
    headers.append('Content-Type', 'application/json')

    let body = JSON.stringify(data);

    let options = {
        headers: headers,
        body: body,
        method: method,
        redirect: 'follow'
    }

    let res = await fetch(url , options)
    return res;
}

export default query