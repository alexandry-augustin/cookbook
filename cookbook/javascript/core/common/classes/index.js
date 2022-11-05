class Point
{
    constructor(x, y)
    {
      this.x = x;
      this.y = y;
    }
    static name = "my_point";
    static n = 0;
    get sum()
    {
        return this.calc_sum();
    }
    calc_sum()
    {
        return this.x + this.y;
    }
}
  
if(require.main === module)
{
    console.log(Point.name);

    let point = new Point(1, 2);
    let sum = point.sum;
    console.log(sum);

    for(i = 0; i < 5; i++)
    {
        Point.n++;
    }
    console.log(Point.n);
}