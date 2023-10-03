// https://www.youtube.com/watch?v=DHvZLI7Db8E

if(require.main === module)
{
    {
        // example using callbacks

        let p = function (resolve, reject) {
            let success = true;
            if(success)
                resolve('success');
            else
                reject('failed');
        };

        p((msg) => {
            console.log('success callback:' + msg);
        }, (msg) => {
            console.log('reject callback:' + msg);
        });
    }
    {
        // example using a promise

        let p = new Promise((resolve, reject) => {
            let success = true;
            if(success)
                resolve('success');
            else
                reject('failed');
        });

        p.then((msg) => {
            console.log('then:' + msg);
        }).catch((msg) => {
            console.log('catch:' + msg);
        });
    }
    {
        // promise.all()

        const a = [
            new Promise((resolve, reject) => { resolve('ID 0'); }), 
            new Promise((resolve, reject) => { resolve('ID 1'); }), 
            new Promise((resolve, reject) => { resolve('ID 2'); })
        ];

        Promise.all(a).then((msgs) => {
            console.log(msgs);
        });
    }
    {
        // Promise.race()

        const a = [
            new Promise((resolve, reject) => { resolve('ID 0'); }), 
            new Promise((resolve, reject) => { resolve('ID 1'); }), 
            new Promise((resolve, reject) => { resolve('ID 2'); })
        ];

        Promise.race(a).then((msg) => {
            console.log(msg);
        });
    }
    {
        // https://stackoverflow.com/questions/951021/what-is-the-javascript-version-of-sleep

        function sleep(ms) {
            return new Promise(resolve => setTimeout(resolve, ms));
        }
        
        async function start_timer() {
            for (let i = 1; i < 5; i++) {
                await sleep(i * 1000);
                console.log(`${i} seconds...`);
            }
        }
        
        start_timer();
    }
}
