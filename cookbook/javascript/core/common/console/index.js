// https://nodejs.org/api/console.html

if(require.main === module)
{
    console.log('log');
    console.error('error');
    console.warn('warn');
    console.assert(1==2, 'Assert Failed');
}
