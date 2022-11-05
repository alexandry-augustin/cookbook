setTimeout(
        function()
        {
            console.log('timeout');
        }, 2000);

var n = 0;
var timer = setInterval(
        function()
        {
            console.log(n);
            n += 1;
            
            if(n > 3)
            {
                clearInterval(timer);
            }
        }, 2000);

