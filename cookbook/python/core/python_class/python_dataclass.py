from dataclasses import dataclass

@dataclass
class Point:
    x: int
    y: int
    z: int = 0

if __name__ == '__main__':
    
    p = Point(1, y=2)
    assert(p.x == 1)
    assert(p.z == 0)
