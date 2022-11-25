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
    {
        // static members

        console.assert(Point.name == "my_point");

        console.assert(Point.n == 0);
        for(i = 0; i < 5; i++)
        {
            Point.n++;
        }
        console.assert(Point.n == 5);
    }
    {
        let point = new Point(1, 2);

        console.assert(point.sum == 3);
    }
}
