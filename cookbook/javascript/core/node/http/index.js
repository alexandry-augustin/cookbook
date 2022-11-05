var http = require('http')
var fs   = require('fs')

function serve_plain_text()
{
    // sending plain text with basic routing

    var server = http.createServer(
            function(request, response)
            {
                console.log('Request: ' + request.url);

                response.writeHead(200, { 'Content-Type': 'text/plain' });
                if(request.url === '/home' || request.url === '/')
                {
                    response.end('Home Page');
                }
                else
                {
                    response.end('404 page no found');
                }
            });
    
    return server
}

function serve_html()
{
    // sending html

    var read_stream  = fs.createReadStream(__dirname + '/index.html', 'utf8'); 
    var server = http.createServer(
            function(request, response)
            {
                console.log('Request: ' + request.url);

                response.writeHead(200, { 'Content-Type': 'text/html' });

                read_stream.pipe(response);
            });

    return server
}

function serve_json()
{
    // sending json object

    var json_obj = {
        id: 4,
        url: 'www.google.com'
    };

    var server = http.createServer(
            function(request, response)
            {
                console.log('Request: ' + request.url);

                response.writeHead(200, { 'Content-Type': 'application/json' });
                response.end(JSON.stringify(json_obj));
            });

    return server
}

function run_server(server, port_num)
{
    server.listen(port_num, '127.0.0.1');
    console.log('Server listening on port ' + port_num + '.');
}

if(require.main === module)
{
    server = serve_plain_text();
    //server = serve_html();
    //server = serve_json();

    run_server(server, 3000);
}
