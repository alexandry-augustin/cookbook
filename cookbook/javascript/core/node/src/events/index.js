var events = require('events');

if(require.main === module)
{
    var my_emitter = new events.EventEmitter();

    my_emitter.on('my_event', 
            function(msg)
            {
                console.log(msg);
            });

    my_emitter.emit('my_event', 'event emitted');
}
