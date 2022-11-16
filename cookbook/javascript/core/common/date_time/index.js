// https://javascript.info/date

function create()
{
    let now;
    let date;

    now = new Date();
    
    // current timestamp
    now = Date.now(); 
    now = new Date().getTime();

    let milliseconds = 100;
    date = new Date(milliseconds); // milliseconds passed after Jan 1st of 1970 UTC+0
    
    date = new Date("2017-01-26");
    
    let year = 2017;
    let month = 0; // 0 (Jan), 11 (Dec)
    let day = 26;
    let hours = 12;
    let minutes = 1;
    let seconds = 0;
    let ms = 0;
    date = new Date(year, month, day, hours, minutes, seconds, ms);
    // if hours/minutes/seconds/ms is absent, they are assumed to be equal 0.
    date = new Date(year, month, day);
    
    epoc = Date.parse('2012-01-26T13:51:50.417-07:00'); // parses the string in the given format and returns the timestamp
    date = new Date(epoc)
}

function getters(date)
{
    // All the methods above return the components relative to the local time zone.
    // Get the day of week, from 0 (Sunday) to 6 (Saturday). The first day is always Sunday, in some countries that’s not so, but can’t be changed. 
    console.log(date.getFullYear(), 
                date.getMonth(), 
                date.getDate(),
                date.getHours(), 
                date.getMinutes(), 
                date.getSeconds(), 
                date.getMilliseconds(), 
                date.getDay());
                
    // UTC-counterparts
    console.log(date.getUTCFullYear(), 
                date.getUTCMonth(), 
                date.getUTCHours(), 
                date.getUTCDay());

    // timestamp for the date – a number of milliseconds passed from the January 1st of 1970 UTC+0.                
    console.log(date.getTime());
    
    // difference between UTC and the local time zone, in minutes:
    console.log(date.getTimezoneOffset());
}

function setters(date)
{
    // date.setFullYear(year, [month], [date])
    // date.setMonth(month, [date])
    // date.setDate(date)
    // date.setHours(hour, [min], [sec], [ms])
    // date.setMinutes(min, [sec], [ms])
    // date.setSeconds(sec, [ms])
    // date.setMilliseconds(ms)
    // date.setTime(milliseconds) //  sets the whole date by milliseconds since 01.01.1970 UTC
}

function to_string(date)
{
    console.log(date);

    console.log(date.toLocaleDateString("en-UK"));
    console.log(date.toLocaleString());

    //var options = { weekday: 'long', year: 'numeric', month: 'long', day: 'numeric' };
    var options = { day: 'numeric', month: 'long', year: 'numeric' };
    console.log(date.toLocaleDateString("en-UK", options));
    console.log(date.toLocaleDateString("es-CL", options));
    
    date = new Date("30 July 2010 15:05 UTC");
    console.log(date.toISOString());
}

if(require.main === module)
{
    create();
    getters(new Date());
    setters(new Date());
    to_string(new Date());
}
