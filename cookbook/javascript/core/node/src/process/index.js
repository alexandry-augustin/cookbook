if(require.main === module)
{
    let argv = process.argv;
    console.log(argv);
    console.log(argv.length);

    argv = argv.slice(2);
    console.log(argv);

    process.exit(0);
}
