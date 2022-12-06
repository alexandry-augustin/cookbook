// https://nodejs.org/api/console.html

function log_levels()
{
    console.log('log');
    console.info('info');
    console.warn('warn');
    console.error('error');
}

function log_groups()
{
    console.group("Group heading");
    console.log("First line");
    console.log("Second line");
    console.log("Last line");
    console.groupEnd();
}

function timing()
{
    console.time("Test process");
    // Do some process here
    console.timeLog("Test process");
    console.timeEnd("Test process");
}

if(require.main === module)
{

    log_levels();
    log_groups();
    timing();

    console.assert(1==2, 'Assert Failed');
}
