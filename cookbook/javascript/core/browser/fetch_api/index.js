const content = document.getElementById('content');

fetch('https://randomuser.me/api/')
  .then((res) => {
    if(res.ok) {
        console.log('ok');
    }
    else {
        console.log('error');
    }
    return res.json();
  })
  .then((data) => {
        console.log(data['results'][0]);
        content.textContent = data['results'][0].email;
    });

    // fetch(base_url, {
    //     method:'POST', 
    //     headers: {
    //         'Content-Type': 'application/json'
    //     },
    //     body: JSON.stringify({
    //         origin: form.origin.value, 
    //         radius: form.radius.value, 
    //         limit: form.limit.value, 
    //         vendor: vendor.value
    //     })})
    //   .then((res) => {
    //     // console.log(res);
    //     return res.json();
    //   })
    //   .then((data) => {
    //     console.log(data);
    //   });