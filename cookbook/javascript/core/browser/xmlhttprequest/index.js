function send_http_request(method, url, is_async) {

    const xhr = new XMLHttpRequest();

    xhr.onload = () => {
        console.log(xhr.response);
        const resp = xhr.reponse;
        console.log(resp);
        if(resp) {        
            const data = JSON.parse(u);
            console.log(data);
        }
    }
    // xhr.onreadystatechange = (ev) => {
    //     // console.log(xhr.readyState);
    //     if(xhr.readyState === 4) {
    //         const data = JSON.parse(xhr.response);
    //         console.log(data);
    //     }
    // }
    // xhr.onerror = (err) => {
    //     console.warn(err);
    // }

    xhr.open(method, url, is_async);
    xhr.send();
}

send_http_request('GET', 'http://127.0.0.1:8080/data.json', false);
